COM_ADD		EQU	0273H	
PA_ADD		EQU	0270H	
PB_ADD		EQU	0271H	
PC_ADD		EQU	0272H	

_stack segment	stack
	       dw 100 dup(?)
_stack ends
			
_data segment	word public 'data'
	led_data db 10111110b	;东西绿灯，南北红灯
	         db 10111111b	;东西绿灯闪烁，南北红灯
	         db 10111101b	;东西黄灯亮，南北红灯
	         db 11101011b	;东西红灯，南北绿灯
	         db 11111011b	;东西红灯，南北绿灯闪烁
	         db 11011011b	;东西红灯，南北黄灯亮
_data ends
			
code segment
start proc	near
	         assume cs:code, ds:_data, ss:_stack
	         mov    ax,_data
	         mov    ds,ax
	         nop
	         mov    dx,COM_ADD
	         mov    al,80h                      	;pa、pb、pc为基本输出模式
	         out    dx,al
	         mov    dx,PA_ADD                   	;灯全熄灭
	         mov    al,0ffh
	         out    dx,al
	         lea    bx,led_data
	start1:  mov    al,0
	         xlat
	         out    dx,al                       	;东西绿灯，南北红灯
	         call   dl5s
	         mov    cx,6
	start2:  mov    al,1
	         xlat
	         out    dx,al                       	;东西绿灯闪烁，南北红灯
	         call   dl500ms
	         mov    al,0
	         xlat
	         out    dx,al
	         call   dl500ms
	         loop   start2
	         mov    al,2                        	;东西黄灯亮，南北红灯
	         xlat
	         out    dx,al
	         call   dl3s
	         mov    al,3                        	;东西红灯，南北绿灯
	         xlat
	         out    dx,al
	         call   dl5s
	         mov    cx,6
	start3:  mov    al,4                        	;东西红灯，南北绿灯闪烁
	         xlat
	         out    dx,al
	         call   dl500ms
	         mov    al,3
	         xlat
	         out    dx,al
	         call   dl500ms
	         loop   start3
	         mov    al,5                        	;东西红灯，南北黄灯亮
	         xlat
	         out    dx,al
	         call   dl3s
	         jmp    start1


dl500ms proc	near
	         push   cx
	         mov    cx,60000
	dl500ms1:loop   dl500ms1
	         pop    cx
	         ret
dl500ms endp

dl3s proc	near
	         push   cx
	         mov    cx,6
	dl3s1:   call   dl500ms
	         loop   dl3s1
	         pop    cx
	         ret
	         endp
			
dl5s proc	near
	         push   cx
	         mov    cx,10
	dl5s1:   call   dl500ms
	         loop   dl5s1
	         pop    cx
	         ret
	         endp

start endp
code ends
	 	end	start
