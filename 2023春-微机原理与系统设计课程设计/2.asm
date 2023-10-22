_stack segment stack
	       db 128 dup(0)
_stack ends

data segment
	begin  db 'input number:',0ah,0dh,'$'
	string db 0ah,0dh,'number: $'
	input  db 20h
	       db 100 dup('$')
	res    db 'result: $'
	error  db '[error] please input number again:',0ah,0dh,'$'
data ends

code segment
	           assume cs:code,ds:data,ss:_stack
	start:     
	           mov    ax,_stack
	           mov    ss,ax

	           mov    ax,data
	           mov    ds,ax
 
	           mov    dx,offset begin
 
	           mov    ah,09h
	           int    21h
	           mov    bx,0
	read:      
	           mov    dx,offset string
	           mov    ah,09h
	           int    21h

	           mov    dx,offset input
	           mov    ah,0ah
	           mov    al,00h
	           int    21h

	           mov    bx,offset input+1
	           mov    cx,[bx]
	           mov    ch,0

	           mov    dx,offset input+2
	           mov    al,[bx+1]

	           cmp    al,'q'
	           je     exit
	           cmp    al,'q'
	           je     exit
 
	           call   newline
	           call   atoi
	           push   ax

	           mov    dx,offset res
	           mov    ah,09h
	           int    21h

	           pop    ax
	           call   dispbin
	           jmp    read
 
	exit:      
	           mov    ah,4ch
	           int    21h

atoi proc
	           push   bx
	           push   si
	           push   cx
	           push   dx
		
	           mov    bx,0
	           mov    si,dx
	           mov    ah,0
	           mov    al,[si]
 
	           sub    ax,30h
	           cmp    ax,9
	           ja     overflow

	           cmp    cx,1h
		
	           je     binaryproc
	           mov    dx,10
	           dec    cx

	binary:    
	           inc    si
	           mov    dx,10
	           mul    dx
	           mov    bl,[si]
	           sub    bl,30h
	           cmp    bl,9
	           ja     overflow
	           add    ax,bx
	           loop   binary
	           jmp    binaryproc

	overflow:  
	           pop    dx
	           pop    cx
	           push   cx
	           push   dx

	           mov    dx,offset error
	           mov    ah,09h
	           int    21h

	           pop    dx
	           pop    cx
	           pop    si
	           pop    bx
	           jmp    read

	binaryproc:
	           pop    dx
	           pop    cx
	           pop    si
	           pop    bx
	           ret
 
atoi endp

	
dispbin proc
	           push   ax
	           push   bx
	           push   cx
	           push   dx
	           mov    bx, ax
	           mov    cx, 16
	l1:        
	           push   cx
	           mov    cl, 1
	           rol    bx, cl
	           mov    dl, bl
	           and    dl, 01h
	           add    dl, 30h
	           cmp    dl, 39h
	           jbe    deal
	           add    dl, 7
	deal:      
	           mov    ah, 02h
	           int    21h
	           pop    cx
	           loop   l1
	           pop    dx
	           pop    cx
	           pop    bx
	           pop    ax
dispbin endp
	
newline proc
	           push   ax
	           push   dx
 
	           mov    ah,02h
	           mov    dl,0ah
	           int    21h

	           mov    dl,0dh
	           int    21h

	           pop    dx
	           pop    ax
	           ret
newline endp

 
code ends
end start





