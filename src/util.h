#pragma once
#include <arrayfire.h>

typedef struct device_info {
	char* name;
	char* platform;
	char* toolkit;
	char* compute;
} device_info;

af_err list_devices(device_info* devices, int count);