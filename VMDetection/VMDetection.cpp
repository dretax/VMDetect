// VMDetection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int IsVMRunning()
{
#if _WIN64 
	UINT64 time1 = rdtsc();
	UINT64 time2 = rdtsc();
	if (time2 - time1 > 500) {
		return 1;
	}
	return 0;
#else 
	unsigned int time1 = 0;
	unsigned int time2 = 0;
	__asm
	{
		RDTSC
		MOV time1, EAX
		RDTSC
		MOV time2, EAX

	}
	if (time2 - time1 > 500) {
		return 1;
	}
	return 0;
#endif
}

int main()
{
	int vm = IsVMRunning();
	if (vm == 1)
	{
		printf("VM Detected");
		return 0;
	}
	printf("Not a VM system.");
	return 0;
}