	;;  Define printf as an external function

	extern	buzzer_set_period() ;
	.data
	.word 1
jp:	
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
global switchAs
switchAs:	
	Mov &s, r12
	cmp #18,r2		;
	jnc case15		;
	add r12,r12		;
	mov JT(r12),r0
case0:
	call #buzzer_set_period(7124) ;
	jmp switchDone
case1:
	call #buzzer_set_period(7124) ;
	jmp switchDone
case2:
	call #buzzer_set_period(4992)	;
	jmp switchDone
case3:
	call #buzzer_set_period(4992) ;
	jmp switchDone
case4:
	call #buzzer_set_period(4545)	;
	jmp switchDone
case5:
	call #buzzer_set_period(4545) ;
	jmp switchDone
case6:
	call #buzzer_set_period(4992) ;
	jmp switchDone
case7:
	call #buzzer_set_period(5714) ;
	jmp switchDone
case8:
	call #buzzer_set_period(5714)	;
	jmp switchDone
case9:
	call #buzzer_set_period(5664) ;
	jmp switchDone
case10:
	call #buzzer_set_period(5664) ;
	jmp switchDone
case11:
	call #buzzer_set_period(6660)	;
	jmp switchDone
case12:
	call #buzzer_set_period(6660) ;
	jmp switchDone
case13:
	call #buzzer_set_period(7126)	;
	jmp switchDone
case14:
	call #buzzer_set_period(7126) ;
	jmp switchDone
case15:
	mov #0,
switchDone:
	Pop r0
	
		

