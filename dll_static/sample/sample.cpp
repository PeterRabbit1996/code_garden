#include <string>
#include <thread>
#include <unistd.h>
#include "sample.h"
#include "sdk.h"
#include "logger.h"

void onSDKLogCallback(const void *log_msg, const size_t log_size)
{
	printf("%s", (char *)log_msg);

	return;
}

void thread_func()
{
	while (true)
	{
		char c = getchar();
		if (c == '\n')
			continue;
		else
		{
			std::string str = "get input " + std::to_string(c) + '\n';
			SDKWriteLog(str.c_str(), strlen(str.c_str()));
		}
	}
}

int main()
{
	SDKLogCallback sdkLogCallback;
	sdkLogCallback.onSDKLogCallback = onSDKLogCallback;
	registerSDKLogCallback(sdkLogCallback);

	std::thread thread_cmd(thread_func);
	while (true)
	{
		writeLog("sleep...\n", 1);
		sleep(1);
	}

	return 0;
}