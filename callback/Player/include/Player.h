#pragma once

#include <thread>
#include <mutex>
#include "dataType.h"

class Player
{
public:
	int startPlay();
	int stopPlay();

	int registerActionCallback(ActionCallback *callback);
	int unregisterActionCallback();

private:
	std::mutex m_mutex;
	ActionCallback *m_actionCallback;

	std::thread m_thread;

	void threadPlay();
};