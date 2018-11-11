#pragma once


#ifdef PIS_PLATFORM_WINDOWS	
	#ifdef PIS_BUILD_DLL
		#define PIS_API __declspec(dllexport)
	#else
		#define PIS_API __declspec(dllimport)
	#endif
#else
	#error PIS_DOESN'T_SUPORT_THIS
#endif