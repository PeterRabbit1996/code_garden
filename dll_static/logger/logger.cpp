#include <mutex>
#include "logger.h"

static std::mutex s_mutex;
static LogCallback s_logCallback;

int registerLogCallback(LogCallback callback)
{
	s_mutex.lock();
	memcpy(&s_logCallback, &callback, sizeof(LogCallback));
	s_mutex.unlock();

	return 0;
}

int unregisterLogCallback()
{
	s_mutex.lock();
	memset(&s_logCallback, 0, sizeof(LogCallback));
	s_mutex.unlock();

	return 0;
}

void writeLog(const char *logmsg, const size_t logSize)
{
	s_mutex.lock();
	if (s_logCallback.onLogCallback != NULL)
	{
		s_logCallback.onLogCallback(logmsg, logSize);
	}
	s_mutex.unlock();

	return;
}