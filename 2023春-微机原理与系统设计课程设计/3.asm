io244	equ	0230h	;74ls244 addr
io273	equ	0230h	;74ls273 addr

mystack segment	stack
	        dw 100	dup(?)
mystack ends

data segment word	 public 'data'
data ends

code segment
	       assume cs:code, ds:data, ss:mystack

start proc	 near
	       mov    ax, data
	       mov    ds, ax
	input: 
	       mov    dx, io244
	       in     ax, dx
	       cmp    ax, 0ffffh                  	; switch all low
	       jz     q1                          	; light <<
	       cmp    ax, 0                       	; all high
	       jz     q2                          	; light >>
	       mov    dx, io273
	       not    ax                          	; light
	       out    dx, ax
	       jmp    input
	q1:    
	       mov    ax, 7fffh
	       mov    dx, io273
	r2l:   
	       call   delay
	       out    dx, ax
	       rol    ax, 1
	       cmp    ax, 7fffh
	       jne    r2l                         	; equal -> finish one turn
	       jmp    input
		
	q2:    
	       mov    ax, 0fffeh
	       mov    dx, io273
	l2r:   
	       call   delay
	       out    dx, ax
	       ror    ax, 1
	       cmp    ax, 0fffeh
	       jne    l2r                         	; equal -> finish one turn
	       jmp    input                       	; read switch

delay proc near
	delay1:
	       xor    cx,cx                       	; clear
	       loop   $
	       ret

delay endp
start endp
code ends
end		start
