	.arch msp430g2553
	.p2align 1,0
	.text
	
	.extern	buzzer_set_period() ;
	.data


S:
	.word 0			;
JT:	
	.word case0
	.word case1		;
	.word case2		;
	.word case3		;
	.word case4		;
	.word case5		;
	.word case6		;
	.word case7		;
	.word case8		;
	.word case9		;
	.word case10		;
	.word case11		;
	.word case12		;
	.word case13		;
	.word case14		;
	.word case15		;
	
	.text
.global switchAs
switchAs:	
	Mov &S, r12
	cmp #16,r12		;
	jc case15		;
	add r12,r12,#1		;
	mov JT(r12),r0
case0:
	mov #7124, r12
	call #buzzer_set_period ;
	jmp switchDone
case1:
	mov #7124, r12
	call #buzzer_set_period;
	jmp switchDone
case2:
	mov #4992,r12
	call #buzzer_set_period	;
	jmp switchDone
case3:
	mov #4992,r12
	call #buzzer_set_period ;
	jmp switchDone
case4:
	mov #4545,r12
	call #buzzer_set_period	;
	jmp switchDone
case5:
	mov #4545,r12
	call #buzzer_set_period;
	jmp switchDone
case6:
	mov #4992,r12
	call #buzzer_set_period ;
	jmp switchDone
case7:
	mov #5714,r12
	call #buzzer_set_period ;
	jmp switchDone
case8:
	mov #5714,r12
	call #buzzer_set_period	;
	jmp switchDone
case9:
	mov #5664,r12
	call #buzzer_set_period ;
	jmp switchDone
case10:
	mov #5664,r12
	call #buzzer_set_period ;
	jmp switchDone
case11:
	mov #6660,r12
	call #buzzer_set_period	;
	jmp switchDone
case12:
	mov #6660,r12
	call #buzzer_set_period ;
	jmp switchDone
case13:
	mov #7126,r12
	call #buzzer_set_period	;
	jmp switchDone
case14:
	mov #7126,r12
	call #buzzer_set_period	;
	jmp switchDone
case15:
	mov #0,r12		;
	jmp switchDone
switchDone:
	Pop r0			;
	
		

