#pragma once

#include <string>
#include <iostream>
#include <chrono>
#include <sstream>
#include <fstream>

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define	H_API __declspec(dllexport)
	#else 
		#define H_API __declspec(dllimport)
	#endif
#endif

