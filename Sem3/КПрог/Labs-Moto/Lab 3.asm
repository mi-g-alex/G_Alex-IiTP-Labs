org $8000
 ldx #$8200
 ldaa #$03
 staa $8233
 ldaa #$07
 staa $8243
 ldaa #$40
 staa $82f0
 ldy #0
 jmp p1 
check:
 ldab 0,x
 aby
 cpx #$82ff
 beq checkx
 inx
p1:
 ldaa 0,x
 cmpa #0
 bgt check
 cpx #$82ff
 beq checkx
 inx
 jmp p1
checkx:
 bra *
