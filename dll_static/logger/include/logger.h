#pragma once

typedef struct
{
	void (*onLogCallback)(const void *log_msg, const size_t log_size);
} LogCallback;

int registerLogCallback(LogCallback callback);
int unregisterLogCallback();
void writeLog(const char *logmsg, const size_t logSize);
