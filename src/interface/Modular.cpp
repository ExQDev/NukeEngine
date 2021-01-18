#include "interface/Modular.h"

void InitModules(AppInstance* instance)
{
	if (!bfs::exists(bfs::path(bfs::current_path().concat("/modules"))))
	{
		bfs::create_directory(bfs::current_path().concat("/modules"));
		cout << "directory created!" << endl;
	}

	for (auto& p : boost::filesystem::directory_iterator(bfs::current_path().concat("/modules")))
	{
		if (!bfs::is_directory(p.path()))
		{
			//cout << p.path().extension().concat("\n").generic_string().c_str() << endl;
			if (p.path().extension() == ".so")
			{
				cout << p.path().filename().concat("\n").generic_string().c_str() << endl;
				boost::shared_ptr<NUKEModule> plugin;
				std::string s = "";
				plugin = dll::import<NUKEModule>("modules/" + p.path().filename().generic_string(), "plugin");
				cout << plugin << endl;
				plugin.get()->modulePath = p.path().generic_string();
				modules.push_back(plugin);
				boost::thread(boost::bind(&NUKEModule::Run, plugin.get(), instance));
			}
		}
	}
}
void UnloadModules()
{
	for (auto i : modules)
	{
		if (i) {
			i.get()->Shutdown();
		}
	}
	modules.clear();
}