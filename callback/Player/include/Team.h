#pragma once

#include <vector>
#include "Player.h"

class Team
{
public:
	int addPlayer(Player *player);

	int startPlay(size_t playerID);
	int stopPlay(size_t playerID);

	int registerActionCallback(size_t playerID, ActionCallback *actionCallback);
	void unregisterActionCallback(size_t playerID);

private:
	std::vector<Player *> m_playerList;
};
