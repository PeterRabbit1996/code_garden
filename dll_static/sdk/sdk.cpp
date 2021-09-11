#include <mutex>
#include "sdk.h"
#include "logger.h"

static std::mutex s_mutex;
static SDKLogCallback s_SDKLogCallback;
static LogCallback s_logCallback;

void onLogCallback(const void *log_msg, const size_t log_size)
{
	s_SDKLogCallback.onSDKLogCallback(log_msg, log_size);

	return;
}

int registerSDKLogCallback(SDKLogCallback callback)
{
	s_mutex.lock();
	memcpy(&s_SDKLogCallback, &callback, sizeof(SDKLogCallback));

	s_logCallback.onLogCallback = onLogCallback;
	registerLogCallback(s_logCallback);
	s_mutex.unlock();

	return 0;
}

int unregisterSDKLogCallback()
{
	s_mutex.lock();
	memset(&s_SDKLogCallback, 0, sizeof(SDKLogCallback));

	unregisterLogCallback();
	s_mutex.unlock();

	return 0;
}

void SDKWriteLog(const char *logMsg, const size_t logSize)
{
	writeLog(logMsg, logSize);
	return;
}