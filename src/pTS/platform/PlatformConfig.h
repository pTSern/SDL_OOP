#pragma once

#define pTS_UNKOWN_PLATFORM             0

#define pTS_WIN32_PLATFORM              1
#define pTS_MAC_PLATFORM                2

#define pTS_ANDROID_PLATFORM            3
#define pTS_IOS_PLATFORM                4
#define pTS_LINUX_PLATFORM              5

#define pTS_TARGET_PLATFORM             pTS_UNKOWN_PLATFORM

#ifdef __ANDROID__
  #undef pTS_TARGET_PLATFORM
  #define pTS_TARGET_PLATFORM           pTS_ANDROID_PLATFORM
#elif _WIN32 || _WIN64
  #undef pTS_TARGET_PLATFORM
  #define pTS_TARGET_PLATFORM           pTS_WIN32_PLATFORM
#elif __APPLE__
#elif __linux__
  #undef pTS_TARGET_PLATFORM
  #define pTS_TARGET_PLATFORM           pTS_LINUX_PLATFORM
#endif

