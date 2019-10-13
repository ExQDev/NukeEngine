#include "interface/AppInstance.h"

AppInstance::AppInstance()
{
	currentScene = new Scene();
	keyboard = KeyBoard::getSingleton();
	mouse = Mouse::getSingleton();
	render = iRender::getSingleton();
	config = Config::getSingleton();
}
AppInstance::~AppInstance() {}

bool AppInstance::isEditor() { return false; }

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