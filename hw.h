static volatile unsigned char * const UART0_PTR = (unsigned char*) 0x0101f1000;

void uart_putc(const char ch);
int uart_puts(const char *string);
