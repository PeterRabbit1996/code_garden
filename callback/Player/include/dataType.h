#pragma once

class ActionCallback
{
public:
	virtual void onShoot() = 0;
	virtual void onPass() = 0;
};