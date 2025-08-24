#include "Intercore.h"

uint8 cpu0_ready = 0, cpu1_ready = 0, cpu2_ready = 0;
uint8 initAllowed = 0;

void Intercore_CPU0_Ready(void){
	cpu0_ready = 1;
}

void Intercore_CPU1_Ready(void){
	cpu1_ready = 1;
}

void Intercore_CPU2_Ready(void){
	cpu2_ready = 1;
}

uint8 Intercore_InitAllowed(void){
	return initAllowed;
}

void Intercore_AllowInitialize(void){
	initAllowed = 1;
}

uint8 Intercore_ReadyToGo(void){
	return (cpu0_ready && cpu1_ready && cpu2_ready);
}
