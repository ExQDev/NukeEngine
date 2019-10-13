#include "interface/EditorInstance.h"

EditorInstance::EditorInstance(): AppInstance() {
	if (!menuStrip)
		menuStrip = new MenuStrip();
	if (!editorWindows)
		editorWindows = new bc::map<string, b::function<void()>>();
	cout << "[EditorInstance]\t" << "Current scene is: " << currentScene << ", Hierarchy is: " << currentScene->hierarchy << endl;
}
EditorInstance::~EditorInstance() {}

bool EditorInstance::isEditor() { return true; }

//void EditorInstance::PushWindow(string &key, boost::function<void()> fWindow) {
//	for (auto tup : *editorWindows) {
//		if (tup.first.compare(key) == 0)
//			throw std::runtime_error("Window key must be unique!");
//	}
//	cout << "Pushing window \"" << key << "\"" << endl;
//	//editorWindows->insert(bc::pair<string, b::function<void()>>(key, fWindow));// make_pair(key, fWindow));
//}

void EditorInstance::PushWindow(const char* key, boost::function<void()> fWindow) {
	for (auto tup : *editorWindows) {
		if (tup.first.compare(key) == 0)
			throw std::runtime_error("Window key must be unique!");
	}
	cout << "Pushing window \"" << key << "\"" << endl;
	editorWindows->insert(make_pair(string(key), fWindow));
}
void EditorInstance::PopWindow(string key) {
	editorWindows->erase(key);
}