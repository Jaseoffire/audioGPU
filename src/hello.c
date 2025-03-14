#include <arrayfire.h>
#include "miniaudio.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	af_err err;
	device_info* devices;
	int count;
	err = af_get_device_count(&count);
	if (err != AF_SUCCESS) {
		return -1;
	}
	printf("you have %i devices\n",count);
	devices = malloc(sizeof(device_info)*count);
	err = list_devices(devices, count);
	if (err != AF_SUCCESS) {
		return -1;
	}
	for (int i=0;i<count;i++) {
		printf("%i %s\n",i,devices[i].name);
	}
	ma_result result;
	ma_engine engine;
	result = ma_engine_init(NULL, &engine);
	if (result != MA_SUCCESS) {
		return -1;
	}
	ma_engine_play_sound(&engine, "sound.wav", NULL);
	printf("Press Enter to quit...");
	getchar();
	ma_engine_uninit(&engine);
	return 0;
}
