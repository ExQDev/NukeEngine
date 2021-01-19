#include "render/universal/nukebgfx.h"
#include <lodepng/lodepng.h>


GLFWimage decodeOneStep(const char* filename) {
	unsigned error;
	GLFWimage image;

	error = lodepng_decode32_file(&(image.pixels), (unsigned int*)&(image.width), (unsigned int*)&(image.height), filename);
	if (error) printf("error %u: %s\n", error, lodepng_error_text(error));

	return image;
}

NukeBGFX* NukeBGFX::_main;

NukeBGFX::NukeBGFX() {
	if (_main)
		_instance = _main;
	else
	{
		_main = this;
		_instance = _main;
	}
}
NukeBGFX::~NukeBGFX() {}

int NukeBGFX::init(int w = 1280, int h = 720) {
	cout << "[NukeBGFX]\t\t" << "Called init of render(" << w << ", " << h << ")" << endl;
	glfwSetErrorCallback(glfw_errorCallback);
	if (!glfwInit())
		return 1;
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	window = glfwCreateWindow(w, h, "NukeEngine Editor", nullptr, nullptr);
	if (!window)
		return 1;
	
	glfwSetKeyCallback(window, glfw_keyCallback);
	glfwSetMouseButtonCallback(window, glfw_mouse_button_callback);

	GLFWimage images[2];
	images[0] = decodeOneStep("res/logo.png");
	images[1] = decodeOneStep("res/logo.png");
	glfwSetWindowIcon(window, 2, images);

	// Most graphics APIs must be used on the same thread that created the window.
	bgfx::renderFrame();
	// Initialize bgfx using the native window handle and window resolution.
	bgfx::Init init;
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	init.platformData.ndt = glfwGetX11Display();
	init.platformData.nwh = (void*)(uintptr_t)glfwGetX11Window(window);
#elif BX_PLATFORM_OSX
	init.platformData.nwh = glfwGetCocoaWindow(window);
#elif BX_PLATFORM_WINDOWS
	init.platformData.nwh = glfwGetWin32Window(window);
#endif
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	init.resolution.width = (uint32_t)width;
	init.resolution.height = (uint32_t)height;
	init.resolution.reset = BGFX_RESET_VSYNC;
	if (!bgfx::init(init))
		return 1;


	bgfx::setViewClear(kClearView, BGFX_CLEAR_COLOR);
	bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);

	if (_UIinit) {
		cout << "[NukeBGFX]\t\t" << "Init UI" << endl;
		_UIinit();
	}

//        this->renderThread = new bst::thread(b::bind(&NukeBGFX::loop, this));
}

int NukeBGFX::render() {
	glfwPollEvents();
	// Handle window resize.
	int oldWidth = width, oldHeight = height;
	glfwGetWindowSize(window, &width, &height);
	if (width != oldWidth || height != oldHeight) {
		bgfx::reset((uint32_t)width, (uint32_t)height, BGFX_RESET_VSYNC);
		bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);
	}
	// This dummy draw call is here to make sure that view 0 is cleared if no other draw calls are submitted to view 0.
	bgfx::touch(kClearView);
	// Use debug font to print information about this example.
	//bgfx::dbgTextClear();

	if (_onGUI.size() > 0)
		for (auto _rn : _onGUI) {
			_rn();
		}

	//bgfx::dbgTextImage(bx::max<uint16_t>(uint16_t(width / 2 / 8), 20) - 20, bx::max<uint16_t>(uint16_t(height / 2 / 16), 6) - 6, 40, 12, s_logo, 160);
	if (_debug) {
		bgfx::dbgTextPrintf(0, 0, 0x0f, "Press F1 to toggle stats.");
		bgfx::dbgTextPrintf(0, 1, 0x0f, "Color can be changed with ANSI \x1b[9;me\x1b[10;ms\x1b[11;mc\x1b[12;ma\x1b[13;mp\x1b[14;me\x1b[0m code too.");
		bgfx::dbgTextPrintf(80, 1, 0x0f, "\x1b[;0m    \x1b[;1m    \x1b[; 2m    \x1b[; 3m    \x1b[; 4m    \x1b[; 5m    \x1b[; 6m    \x1b[; 7m    \x1b[0m");
		bgfx::dbgTextPrintf(80, 2, 0x0f, "\x1b[;8m    \x1b[;9m    \x1b[;10m    \x1b[;11m    \x1b[;12m    \x1b[;13m    \x1b[;14m    \x1b[;15m    \x1b[0m");
		const bgfx::Stats* stats = bgfx::getStats();
		bgfx::dbgTextPrintf(0, 2, 0x0f, "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters.", stats->width, stats->height, stats->textWidth, stats->textHeight);
		// Enable stats or debug text.
		bgfx::setDebug(s_showStats ? BGFX_DEBUG_STATS : BGFX_DEBUG_TEXT);
		// Advance to next frame. Process submitted rendering primitives.
	}
	bgfx::frame();
	return 1;
}

void NukeBGFX::renderObject(Mesh* mesh, Material* mat, Transform* transform) {

}

void NukeBGFX::loop() {
	while (!glfwWindowShouldClose(this->window)) {
		this->render();
	}
}

void NukeBGFX::deinit() {
	bgfx::shutdown();
	glfwTerminate();
}

void NukeBGFX::update() {

}

char* NukeBGFX::getEngine() {
	return  (char*)"BGFX - ";
}

char* NukeBGFX::getVersion() {
	return (char*)"1.0.0.0";
}

void NukeBGFX::setOnClose(b::function<void()> cb) {
	_onClose.push_back(cb);
}

void NukeBGFX::setOnGUI(b::function<void(void)> cb) {
	_onGUI.push_back(cb);
	//        cout << cb << " -- onGUI[" << this << "]" << endl;
}

void NukeBGFX::setOnRender(b::function<void(void)> cb) {
	_onRender.push_back(cb);
	//        cout << cb << " -- onRender" << endl;
}

void NukeBGFX::close()
{
	if (_onClose.size() > 0)
		for (auto cb : _onClose)
			cb();
}

void NukeBGFX::timer() {
	if (_physTrigger)
		_physTrigger();
}

void NukeBGFX::keyboard(int key, int scancode, int action, int mods) {
	switch (action)
	{
	case GLFW_PRESS:
		KeyBoard::getSingleton()->key(key, 0, 0);
		break;
	case GLFW_RELEASE:
		KeyBoard::getSingleton()->keyup((unsigned char)glfwGetKeyName(key, 0), 0, 0);
		break;
	case GLFW_REPEAT:
		KeyBoard::getSingleton()->key((unsigned char)glfwGetKeyName(key, 0), 0, 0);
		break;
	default:
		break;
	}
}

void NukeBGFX::mouseMove(double xpos, double ypos)
{
}

void NukeBGFX::mouseClick(int button, int action, int mods)
{
	switch (action)
	{
	case GLFW_PRESS:
	case GLFW_RELEASE:
		Mouse::getSingleton()->key(button, action, mods);
		break;
	default:
		break;
	}
}

void NukeBGFX::setCursorMode(int mode)
{
}

void NukeBGFX::rawMouse(double xpos, double ypos)
{
}

void NukeBGFX::mouseEnterLeave(int entered)
{
}

void mouseMove(double xpos, double ypos) {

}
void setCursorMode(int mode) {

}
void rawMouse(double xpos, double ypos) {

}
void mouseEnterLeave(int entered) {

}


void glfw_errorCallback(int error, const char* description)
{
	fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

void glfw_keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	NukeBGFX::getSingleton()->keyboard(key, scancode, action, mods);
	if (key == GLFW_KEY_F1 && action == GLFW_RELEASE)
	{
		((NukeBGFX*)NukeBGFX::getSingleton())->_debug = ((NukeBGFX*)!NukeBGFX::getSingleton())->_debug;
		s_showStats = !s_showStats;
	}
}

void glfw_mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	NukeBGFX::getSingleton()->mouseClick(button, action, mods);
}