#include "Interrupts.h"

// encoder overflow

IFX_INTERRUPT(_ENCODER_OVERFLOW_ISR, 0, ENCODER_OVERFLOW_PRIORITY) {
	Encoder_Overflow_ISR();
}

__attribute__((weak))void Encoder_Overflow_ISR(void) {
	;
}
