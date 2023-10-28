.section .init
.global _start
@------------------
@SETUP VALUES
@------------------
.equ BASE,  0x3f200000 @Base address
.equ GPFSEL0, 0x00			@FSEL0 register offset 
.equ GPFSEL1, 0x04			@FSEL1 register offset 
.equ GPFSEL2, 0x08			@FSEL2 register offset 
.equ GPSET0,  0x1c			@GPSET0 register offset
.equ GPCLR0,0x28			@GPCLR0 register offset
.equ GPLEV0,0x34
.equ walk_time, 0x27F0000
.equ blink_delay, 0x1F0000
.equ blink_counter, 0x5
@=============================
.equ BIT_17,  0x20000 @ button
.equ BIT_19,  0x80000	@ red street
.equ BIT_27,  0x8000000	@ yello street
.equ BIT_21,  0x200000  @ green street
@=============================
.equ BIT_26,  0x4000000 @ green walk
.equ BIT_25,  0x2000000 @ red walk
@=============================
@ GPIO 17 input, 19, 21, 25, 26, 27 output
.equ SEL_one,   0xCF1FFFFF  
.equ SEL_two,   0x248008
@------------------
@Start label
@------------------
_start:
@------------------
@load register with BASE
@------------------
ldr r0,=BASE
@set pin 17 input and 19 to output
ldr r1,=SEL_one
str r1,[r0,#GPFSEL1] 
@set pin 21, 25, 26, 27 to output
ldr r1,=SEL_two
str r1,[r0,#GPFSEL2] 
@------------------
b walk_red

walk_red:
	ldr r1,=BIT_21
	str r1,[r0,#GPSET0] @ set pin 21
	ldr r1,=BIT_25
	str r1,[r0,#GPSET0] @ set pin 25
	mov r4, #17
	mov r3, #1
	b wait_for_input

wait_for_input:
	mov r3,#1
	lsl r3,r4		@create mask based on argument	
	ldr r1,=GPLEV0		@GPLEV holds pin states
	ldr r5,[r0,r1]		@access GPLEV0
	tst r5,r3
	bne walk_green
	beq wait_for_input

walk_green:
	ldr r1,=BIT_21
	str r1,[r0,#GPCLR0] @ CLR pin 21 
	ldr r1,=BIT_25
	str r1,[r0,#GPCLR0] @ CLR pin 25 
	ldr r1,=BIT_19
	str r1,[r0,#GPSET0] @ SET pin 19 
	ldr r1,=BIT_26
	str r1,[r0,#GPSET0] @ SET pin 26
	ldr r2,=walk_time
	mov r10,#0
	delay:
		add r10,r10,#1
		cmp r10,r2	
		bne delay
	mov r9,#0
	b notify_blink

notify_blink:
	add r9,r9,#1
	ldr r1,=BIT_26
	str r1,[r0,#GPSET0] @ SET pin 26BIT_26
	ldr r1,=BIT_27
	str r1,[r0,#GPSET0] @ SET pin 27
	ldr r2,=blink_delay
	mov r10,#0
	delay1:
		add r10,r10,#1
		cmp r10,r2	
		bne delay1
	ldr r1,=BIT_26
	str r1,[r0,#GPCLR0] @ CLR pin 26
	ldr r1,=BIT_27
	str r1,[r0,#GPCLR0] @ CLR pin 27
	ldr r2,=blink_delay
	mov r10,#0
	delay2:
		add r10,r10,#1
		cmp r10,r2	
		bne delay2
	ldr r2,=blink_counter
	cmp r9,r2
	bne notify_blink
	ldr r1,=BIT_19
	str r1,[r0,#GPCLR0] @ SET pin 19
	beq walk_red
	
	






