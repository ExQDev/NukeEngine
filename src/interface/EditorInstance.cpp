#include "interface/EditorInstance.h"

EditorInstance::EditorInstance() {
	
}
EditorInstance::~EditorInstance() {}



bool EditorInstance::isEditor() { return true; }

//void EditorInstance::PushWindow(string &key, boost::function<void()> fWindow) {
//	for (auto tup : *editorWindows) {
//		if (tup.first.compare(key) == 0)
//			throw std::runtime_error("Window key must be unique!");
//	}
//	cout << "Pushing window \"" << key << "\"" << endl;
//	//editorWindows->insert(bc::pair<string, bst::function<void()>>(key, fWindow));// make_pair(key, fWindow));
//}
