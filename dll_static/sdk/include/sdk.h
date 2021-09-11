#pragma once

typedef struct
{
	void (*onSDKLogCallback)(const void *log_msg, const size_t log_size);
} SDKLogCallback;

void onLogCallback(void *log_msg, const size_t log_size);

int registerSDKLogCallback(SDKLogCallback callback);
int unregisterSDKLogCallback();
void SDKWriteLog(const char *logmsg, const size_t logSize);
