mystack segment stack
	        db 256 dup(?)
mystack ends

data segment
	hello  db  'Hello world!$'
	lhello equ $ - hello
	endl   db  0dh, 0ah, '$'
	no     db  'Number: 20009200998$'
	nm     db  'Name: Wang Junjian$'
	info   db  'Input chars: (q or Q to quit)$'
	tip    db  '>>> $'
	char   db  '[char]: $'
	ascii  db  '[ASCII]: $'
	endd   db  'program ends.$'
data ends

code segment
	       assume cs:code, ds:data
	start: 
	       mov    ax, data
	       mov    ds, ax
	
	;------------------------------
	; task1: show hello and ascii
	;   out: Hello world!
	;        [ASCII]: xxx\n
	;------------------------------

	       mov    dx, offset hello
	       mov    ah, 9           	; display str
	       int    21h
	       mov    dx, offset endl 	; \n
	       mov    ah, 9
	       int    21h
	       mov    dx, offset ascii
	       mov    ah, 9
	       int    21h

	; convert hello into ascii
	       mov    cx, lhello
	       lea    si, hello       	; si point to hello
	cnvt0: 
	       mov    bl, [si]        	; low 4
	       mov    bh, [si]        	; high 4
	       inc    si
	       push   cx

	; high 4
	       and    bh, 0f0h
	       mov    cl, 4
	       shr    bh, cl
	       cmp    bh, 9           	; if bh > 9(1001) then the output is characters nut nums!
	       jbe    no1
	       add    bh, 7h          	; h4 > 9
	no1:                          	; h4 <= 9
	       add    bh, '0'
	; disp in ascii
	       mov    dl, bh
	       mov    ah, 2
	       int    21h
	
	; low 4
	       and    bl, 0fh
	       cmp    bl, 9
	       jbe    no2
	       add    bl, 7h          	; l4 > 9
	no2:                          	; l4 <= 9
	       add    bl, '0'
	; disp in ascii
	       mov    dl, bl
	       mov    ah, 2
	       int    21h
	
	; end of one turn
	       mov    dl, 32          	; (space)
	       mov    ah, 2
	       int    21h
	       pop    cx
	       loop   cnvt0

	; end of task1
	       mov    dx, offset endl
	       mov    ah, 9
	       int    21h

	;----------------------------------
	; task2: output number & name
	;   out: Number: xxx\tName: xxx\n
	;----------------------------------

	       mov    dx, offset no
	       mov    ah, 9
	       int    21h
	       mov    dl, 9
	       mov    ah, 2
	       int    21h
	       mov    dx, offset nm
	       mov    ah, 9
	       int    21h
	       mov    dx, offset endl
	       mov    ah, 9
	       int    21h
	
	;-----------------------------------
	; task3: input & test
	;   out: >>> x
	;        [char]: xxx\t[ASCII]: xxx\n
	;-----------------------------------

	       mov    dx, offset info
	       mov    ah, 9
	       int    21h
	       mov    dx, offset endl
	       mov    ah, 9
	       int    21h
	cnvt:  
	       mov    dx, offset tip
	       mov    ah, 9
	       int    21h
	       mov    ah, 1           	; input into al and disp
	       int    21h
		
	; q or Q to quit
	       cmp    al, 'q'
	       je     ending
	       cmp    al, 'Q'
	       je     ending
	
	; store to bh/bl
	       mov    bl, al          	; low 4
	       mov    bh, al          	; high 4
	
	       mov    dx, offset endl
	       mov    ah, 9
	       int    21h
	
	; disp [char]: x\t[ASCII]:
	       mov    dx, offset char
	       mov    ah, 9
	       int    21h
	       mov    dl, bl
	       mov    ah, 2
	       int    21h
	       mov    dl, 9
	       mov    ah, 2
	       int    21h
	       mov    dx, offset ascii
	       mov    ah, 9
	       int    21h
	
	; high 4
	       and    bh, 0f0h
	       mov    cl, 4
	       shr    bh, cl
	       cmp    bh, 9
	       jbe    noh
	       add    bh, 7h
	noh:   
	       add    bh, '0'
	       mov    dl, bh
	       mov    ah, 2
	       int    21h
	
	; low 4
	       and    bl, 0fh
	       cmp    bl, 9
	       jbe    nol
	       add    bl, 7h
	nol:   
	       add    bl, '0'
	       mov    dl, bl
	       mov    ah, 2
	       int    21h
	
	;end of one turn
	       mov    dx, offset endl
	       mov    ah, 9
	       int    21h
	       jmp    cnvt
	
	;-------
	; END
	;-------
	ending:
	       mov    dx, offset endl
	       mov    ah, 9
	       int    21h
	       mov    dx, offset endd
	       mov    ah, 9
	       int    21h
	       mov    ah, 4ch
	       int    21h

code ends
end start
