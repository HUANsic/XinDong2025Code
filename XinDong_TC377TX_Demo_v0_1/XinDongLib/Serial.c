#include "Serial.h"
#include "IfxAsclin_Asc.h"

IfxAsclin_Asc uartHandle_serial;

void Serial_Tx_ISR(void) {
	IfxAsclin_Asc_isrTransmit(&uartHandle_serial);
}

void Serial_Rx_ISR(void) {
	uint8 buff;
	sint16 count = 1;
	IfxAsclin_Asc_isrReceive(&uartHandle_serial);
	IfxAsclin_Asc_read(&uartHandle_serial, &buff, &count, 100);
	Serial_Received(buff);
}

void Serial_Err_ISR(void) {
	IfxAsclin_Asc_isrError(&uartHandle_serial);
}

__weak__ void Serial_Received(uint8 buff) {
	(void) buff;
}
