#include <vector>
#include "sdk.h"
#include "Team.h"
#include "callback.h"

static Team s_team;
static std::vector<SDKActionCallback *> s_sdkACList;
static std::vector<ActionCallback *> s_acList;

int listPlayer()
{
	int playerCnt = 2;
	for (size_t playerID = 0; playerID < playerCnt; playerID++)
	{
		s_team.addPlayer(new Player());

		SDKActionCallback *sdkAC = (SDKActionCallback *)malloc(sizeof(SDKActionCallback));
		s_sdkACList.__emplace_back(sdkAC);

		ActionCallback *ac;
		s_acList.__emplace_back(ac);
	}

	return 0;
}

int SDKStartPlay(size_t playerID)
{
	if (s_team.startPlay(playerID) != 0)
		return -1;
	return 0;
}

int SDKStopPlay(size_t playerID)
{
	if (s_team.stopPlay(playerID) != 0)
		return -1;
	return 0;
}

/* ==================================================================================== */

class SDKAC : public ActionCallback
{
public:
	SDKAC(size_t playerID)
	{
		m_playerID = playerID;
	}
	void onShoot()
	{
		if (s_sdkACList[m_playerID] == NULL ||
		    s_sdkACList[m_playerID]->onShoot == NULL)
			return;

		s_sdkACList[m_playerID]->onShoot();
		return;
	}

	void onPass()
	{
		if (s_sdkACList[m_playerID] == NULL ||
		    s_sdkACList[m_playerID]->onPass == NULL)
			return;

		s_sdkACList[m_playerID]->onPass();
		return;
	}

private:
	size_t m_playerID = -1;
};

int SDKRegisterActionCallback(size_t playerID, SDKActionCallback *sdkActionCallback)
{
	if (sdkActionCallback == nullptr)
		return -1;

	s_sdkACList[playerID] = sdkActionCallback;

	s_acList[playerID] = new SDKAC(playerID);
	s_team.registerActionCallback(playerID, s_acList[playerID]);

	return 0;
}

void SDKUnregisterActionCallback(size_t playerID, SDKActionCallback *sdkActionCallback)
{
	s_team.unregisterActionCallback(playerID);
	delete s_acList[playerID];
	s_acList[playerID] = nullptr;

	return;
}