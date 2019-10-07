#include "interface/EditorInstance.h"

EditorInstance::EditorInstance() {
	if (!menuStrip)
		menuStrip = new MenuStrip();
}
EditorInstance::~EditorInstance() {}

bool EditorInstance::isEditor() { return true; }

void EditorInstance::PushWindow(string key, boost::function<void()> fWindow) {
	for (auto tup : GetSingleton()->editorWindows) {
		if (tup.first.compare(key) == 0)
			throw std::runtime_error("Window key must be unique!");
	}
	cout << "Pushing window \"" << key << "\"" << endl;
	editorWindows.insert(make_pair(key, fWindow));
}

void EditorInstance::PopWindow(string key) {
	editorWindows.erase(key);
}