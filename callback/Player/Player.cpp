#include <mutex>
#include <unistd.h>
#include "Player.h"

int Player::startPlay()
{
	m_thread = std::thread(&Player::threadPlay, this);
	return 0;
}

int Player::stopPlay()
{
	m_thread.join();
	return 0;
}

int Player::registerActionCallback(ActionCallback *actionCallback)
{
	m_mutex.lock();
	m_actionCallback = actionCallback;
	m_mutex.unlock();

	return 0;
}

int Player::unregisterActionCallback()
{
	m_mutex.lock();
	m_actionCallback = nullptr;
	m_mutex.unlock();

	return 0;
}

void Player::threadPlay()
{
	while (true)
	{
		m_mutex.lock();
		if (m_actionCallback != nullptr)
		{
			m_actionCallback->onPass();
			sleep(1);

			m_actionCallback->onShoot();
			sleep(1);
		}
		m_mutex.unlock();
	}

	return;
}
