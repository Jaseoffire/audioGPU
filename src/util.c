#include "util.h"
#include <stdlib.h>

af_err list_devices(device_info* devices, int count){
	af_err err;
	for (int i=0;i<count;i++) {
		err = af_set_device(i);
		if (err != AF_SUCCESS) {
			return err;
		}
		devices[i].name = malloc(sizeof(char)*1024);
		devices[i].platform = malloc(sizeof(char)*1024);
		devices[i].toolkit = malloc(sizeof(char)*1024);
		devices[i].compute = malloc(sizeof(char)*1024);
		err = af_device_info(devices[i].name, devices[i].platform, devices[i].toolkit, devices[i].compute);
		if (err != AF_SUCCESS) {
			return err;
		}
	}
	return AF_SUCCESS;
}