#include "hw.h"

void uart_putc(const char ch){
	*UART0_PTR = ch;
}

int uart_puts(const char *string){
	while(*string != '\0'){
		uart_putc(*string);
		string ++;
	}
	return 0;
}

