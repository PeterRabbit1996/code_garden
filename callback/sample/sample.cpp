#include <string>
#include <thread>
#include <unistd.h>
#include "sample.h"
#include "sdk.h"
#include "callback.h"

void onLM10Shoot()
{
	printf("LM10 shoot...\n");
	return;
}

void onLM10Pass()
{
	printf("LM10 pass...\n");
	return;
}

void onCR7Shoot()
{
	printf("CR7 shoot...\n");
	return;
}

void onCR7Pass()
{
	printf("CR7 pass...\n");
	return;
}

int main()
{
	SDKActionCallback LM10AC;
	LM10AC.onShoot = onLM10Shoot;
	LM10AC.onPass = onLM10Pass;

	SDKActionCallback CR7AC;
	CR7AC.onShoot = onCR7Shoot;
	CR7AC.onPass = onCR7Pass;

	listPlayer();
	SDKRegisterActionCallback(0, &LM10AC);
	SDKRegisterActionCallback(1, &CR7AC);

	SDKStartPlay(0);
	SDKStartPlay(1);

	while (true)
	{

	}

	return 0;
}