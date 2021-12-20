#include "Team.h"

int Team::addPlayer(Player *player)
{
	if (player == nullptr)
		return -1;

	m_playerList.__emplace_back(player);

	return 0;
}

int Team::startPlay(size_t playerID)
{
	if (m_playerList[playerID]->startPlay() != 0)
		return -1;

	return 0;
}

int Team::stopPlay(size_t playerID)
{
	if (m_playerList[playerID]->stopPlay() != 0)
		return -1;

	return 0;
}

int Team::registerActionCallback(size_t playerID, ActionCallback *actionCallback)
{
	if (actionCallback == nullptr)
		return -1;

	if (m_playerList[playerID]->registerActionCallback(actionCallback) != 0)
		return -1;

	return 0;
}

void Team::unregisterActionCallback(size_t playerID)
{
	m_playerList[playerID]->unregisterActionCallback();

	return;
}
