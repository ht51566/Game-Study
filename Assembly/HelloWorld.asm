%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; 쉬프트(shift) 연산, 논리(logical) 연산
    
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    shl eax, 8
    PRINT_HEX 4, eax
    NEWLINE
    shr eax, 8
    PRINT_HEX 4, eax
    NEWLINE
    ; 곱셈/나눗셈
    ; 게임서버에서 ObjectID를 만들어줄 때
    
    ; not and or xor
    
    ; 조건A : 잘생겼다
    ; 조건B : 키가 크다
    
    ; not A : 잘생겼다의 반대 -> (0이면 1, 1이면 0)
    ; A and B : 잘생겼고 and 키도 크고 -> 둘다 1이면 1, 아니면 0
    ; A or B : 잘생겼거나 or 키가 크거나 -> 둘중 하나라도 1이면, 아니면 0
    ; A xor B : 잘생기고 작거나 or 못생기고 크거나 -> 둘다 1이거나 둘다 0이면 0, 아니면 1
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    ; 0b00010100 = 0x14
    and al, bl ; al = al and bl
    PRINT_HEX 1, al
    NEWLINE
    
    ; 0b11101011 = 0xeb
    not al
    PRINT_HEX 1, al
    NEWLINE
    
    ; 응용 사례 : bitflag
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    NEWLINE
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    ; 동일한 값으로 xor 두번하면 자기 자신으로 되돌아오는 특성
    ; 암호학에서 유용하다! (value xor key)
    
    ; mov al, 0
    xor al, al
    PRINT_HEX 1, al
    
    ;GET_DEC 1, al
    ;GET_DEC 1, num
    
    ;PRINT_DEC 1, al
    ;NEWLINE
    ;PRINT_DEC 1, num
    
    ; 더하기 연산
    ; add a, b (a = a + b)
    ; a는 레지스터 or 메모리
    ; b는 레지스터 or 메모리 or 상수
    ; - 단! a, b 모두 메모리는 X
    
    ; 빼기 연산
    ; sub a, b (a = a - b)
    
    ;add al, 1 ; 레지스터 + 상수
    ;PRINT_DEC 1, al ; 1+1=2
    ;NEWLINE
     
    ;add al, [num] ; 레지스터 + 메모리
    ;PRINT_DEC 1, al ; 2+2=4
    ;NEWLINE
    
    ;mov bl, 3
    ;add al, bl
    ;PRINT_DEC 1, al ; 4+3=7
    ;NEWLINE
    
    ;add [num], byte 1 ; 메모리 + 상수
    ;PRINT_DEC 1, [num] ; 2+1=3
    ;NEWLINE
    
    ;add [num], al ; 메모리 + 레지스터
    ;PRINT_DEC 1, [num] ; 3+7=10
    ;NEWLINE
    
    ; 곱하기 연산
    ; mul reg
    ; - mul bl => al * bl
    ; -- 연산 결과를 ax에 저장
    ; - mul bx => ax * bx
    ; -- 연산 결과는 dx(상위16비트) ax(하위16비트)에 저장
    
    ; ex) 5 * 8 은?
    ;mov ax, 0
    ;mov al, 5
    ;mov bl, 8
    ;mul bl
    ;PRINT_DEC 2, ax
    ;NEWLINE
    
    ; 나누기 연산
    ; div reg
    ; - div bl => ax / bl
    ; -- 연산 결과는 al(몫) ah(나머지)
    
    ; ex) 100 / 3은 ?
    ;mov ax, 100
    ;mov bl, 3
    ;div bl
    ;PRINT_DEC 1, al ; 100 /3 = 33 * 3 + 1
    ;NEWLINE  
    ;mov al, ah
    ;PRINT_DEC 1, al
      
    ; 메모를 남길 수 있는 기능 = 주석
    
    ; 10진수(0 1 2 3 4 5 6 7 8 9)
    ; 10 11 12 13 ... 19 20
    
    ; 2진수(0 1)
    ; 0 1 10
    ; 0b0 0b1 0b10 0b11 0b100
    
    ; 16진수(0 1 2 3 4 5 6 7 8 9 A B C D E F)
    ; 0 1 2 3 4 5 6 7 8 9 A B C D E F 10
    ; 0x00
    
    ; 0b10010101 = 0x95
    
    ; 8 bit = 1 byte
    ; 16 bit = 2 byte = 1 word
    ; 32 bit = 4 byte = 2 word = 1 dword (double-word)
    ; 64 bit = 8 byte = 4 word = 1 qword (quad-word)
    
       
    ;PRINT_STRING msg
   
    
    ;mov eax, 0x1234
    ;mov rbx, 0x12345678
    ;mov cl, 0xff
    
    ;mov al, 0x00
    
    ; 메모리 <-> 레지스터
    ; mov rax, a ; a 라는 주소값을 rax 에 복사
    ; mov rax, [a] ; a 라는 바구니 안에 있는 값을 rax 에다 복사
    ;mov al, [a]
    
    ;mov [a], byte 0x55
    ;mov [a], word 0x6666
    ;mov [a], cl
      
    xor rax, rax
    ret
    
    ; 변수의 선언 및 사용
    ; 변수는 그냥 데이터를 저장하는 바구니 [ ]
    ; - 처음에 바구니 사용하겠다 선언 (이름과 크기 지정)
    
    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] db(1) dw(2) dd(4) dq(8)
;section .data
    ;msg db 0x48,0x65,0x6c,0x6c,0x6f,0x20,0x57,0x6f,0x72,0x6c,0x64,0x0
    
    ;a db 0x11, 0x11, 0x11, 0x11   ; [0x11]
    
    ;b dd 0x12345678
    ; 장단점이 교차한다
    ; - 빅 엔디언 : 숫자 비교에 유리
    ; - 리틀 엔디언 : 캐스팅에 유리하다
    
    ;b dw 0x2222
    ;c dd 0x33333333
    ;d dq 0x4444444444444444
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 1