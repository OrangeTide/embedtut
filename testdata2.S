.section .rodata
.global binary_testdata2_start
binary_testdata2_start:
.incbin "testdata2.dat"
/* calculate length as a symbol */
.equ binary_testdata2_len, . - binary_testdata2_start
.byte 0 /* add a null terminator */
.align 4
/* put length into a variable. */
.globl binary_testdata2_size
binary_testdata2_size:
	.int binary_testdata2_len
