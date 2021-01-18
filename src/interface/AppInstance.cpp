#include "interface/AppInstance.h"

AppInstance::AppInstance()
{
	//currentScene = new Scene();
	keyboard = KeyBoard::getSingleton();
	mouse = Mouse::getSingleton();
	//render = iRender::getSingleton();
	config = Config::getSingleton();
	
	if (!menuStrip)
		menuStrip = new MenuStrip();
	if (!editorWindows)
		editorWindows = new bc::map<string, b::function<void()>>();
	cout << "[EditorInstance]\t" << "Current scene is: " << currentScene << "(" << currentScene->name << ")" << ", Hierarchy is: " << &currentScene->GetHierarchy() << endl;
}
AppInstance::~AppInstance() {}

bool AppInstance::isEditor() { 
	return _isEditor;
}

void AppInstance::setEditor(bool editor) {
	_isEditor = editor;
}

void AppInstance::UpdateThread()
{
	while (true)
	{
		try
		{
			currentScene->Update();
			boost::this_thread::sleep(boost::posix_time::milliseconds(40));
		}
		catch (const std::exception&)
		{

		}
	}

}

void AppInstance::StartUpdateThread()
{
	boost::thread updt(boost::bind(&AppInstance::UpdateThread, this));
}

void AppInstance::PushWindow(const char* key, boost::function<void()> fWindow) {
	for (auto tup : *editorWindows) {
		if (tup.first.compare(key) == 0)
			throw std::runtime_error("Window key must be unique!");
	}
	cout << "[EditorInstance]\t" << "Pushing window \"" << key << "\"" << endl;
	editorWindows->insert(make_pair(string(key), fWindow));
}
void AppInstance::PopWindow(string key) {
	editorWindows->erase(key);
}
