.global _start
_start:
LDR sp, = sp_top
BL main
B .
