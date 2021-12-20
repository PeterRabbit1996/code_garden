#pragma once

#include <unistd.h>
#include "callback.h"

int listPlayer();

int SDKStartPlay(size_t playerID);
int SDKStopPlay(size_t playerID);

int SDKRegisterActionCallback(size_t playerID, SDKActionCallback *sdkActionCallback);
void SDKUnregisterActionCallback(size_t playerID, SDKActionCallback *sdkActionCallback);


