#include "hw.h"

#define UARTDR (volatile int*)(0x101f1000)
#define UARTFR (volatile int*)(0x101f1018)

void print_int_char(int b){
	char a[3];
	a[0] = b + '0';
	a[1] = 0;
	uart_puts(a);
}

void print_int(int b){
	int keta = 0;
	int c = b;
	int ch[10];
	do{
		ch[keta] = c % 10;
		keta++;
	}while((c = c/10) && keta < 9);

	for(int i = keta-1; i >= 0; i--){
		print_int_char(ch[i]);
	}
}

void print_n(){
	char a[3];
	a[0] = '\n';
	a[1] = 0;
	uart_puts(a);
}

int main() {
	while(1){
		while(*UARTFR == 192){
			uart_putc(*UARTDR);
		}
	}
	uart_puts("Hello, world!\n");
	return 0;
}
