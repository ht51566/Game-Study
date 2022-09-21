%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; 스택 메모리, 스택 프레임
    
    ; 레지스터는 다양한 용도로 사용
    ; - a b c d 범용 레지스터
    ; - 포인터 레지스터 (포인터 = 위치를 가리키는~)
    ; -- ip (Instruction Pointer) : 다음 수행 명령어의 위치
    ; -- sp (Stack Pointer) : 현재 스택 top 위치 (일종의 cursor)
    ; -- bp (Base Pointer) : 스택 상대주소 계산용
    
    push 1
    push 2
    push 3
    
    pop rax
    pop rbx
    pop rcx
    
    ; 함수 (프로시저 procedure 서브루틴 subroutine)
    
    ;call PRINT_MSG
    
    ;mov eax, 10
    ;mov ebx, 15
    ;call MAX
    ;PRINT_DEC 4, ecx
    ;NEWLINE
    
    ; 배열과 주소
    
    ; 배열 : 동일한 타입의 데이터 묶음
    ; - 배열을 구성하는 각 값을 배열 요쇼(element)라고 함
    ; - 배열의 위치리르 가리키는 숫자를 인덱스(index)라고 함
    
    ; 주소
    ; [시작 주소 + 인덱스 * 크기]
    
    ;mov rax, a
    
    ; 연습문제 : a배열의 모든 데이터 출력해보기
    ;PRINT_HEX 1, [a]
    ;NEWLINE
    ;PRINT_HEX 1, [a+1]
    ;NEWLINE
    ;PRINT_HEX 1, [a+2]
    ;NEWLINE
    
    ;xor ecx, ecx
;LABEL_PRINT_A:
    ;PRINT_HEX 1, [a+ecx]
    ;NEWLINE
    ;inc ecx ;add ecx, 1
    ;cmp ecx, 5
    ;jne LABEL_PRINT_A
    
    ;xor ecx, ecx
    
;LABEL_PRINT_B:
    ;PRINT_HEX 2, [b+ecx*2]
    ;NEWLINE
    ;inc ecx
    ;cmp ecx, 5
    ;jne LABEL_PRINT_B
    
    ; 반복문 (while for)
    ; 특정 조건을 만족할때까지 반복해서 실행~
    
    ; ex) Hello World를 10번 출력해야 한다면?
    
    ;mov ecx, 10
    
;LABEL_LOOP:
    ;PRINT_STRING msg
    ;NEWLINE
    ;dec ecx ; sub ecx, 1과 동일
    ;cmp ecx, 0
    ;jne LABEL_LOOP
    
    ; 연습 문제) 1에서 100까지의 합을 구하는 프로그램 1+2+3+4....+100 = ?
    ;mov eax, 100 ; 최종 목적지
    ;xor ebx, ebx ; mov ebx, 0 ebx: 결과물
    ;xor ecx, ecx
    
;LABEL_SUM:
    ;;inc ecx ; add ecx, 1과 동일
    ;;add ebx, ecx ; ebx = ebx + ecx
    ;add ebx, eax
    ;dec eax
    ;;cmp ecx, eax
    ;cmp eax, 0
    ;jne LABEL_SUM
    
    ;PRINT_DEC 4, ebx
    ;NEWLINE
    
    ; loop [라벨]
    ; - ecx에 반복 횟수
    ; - loop 할때마다 ecx 1 감소 0이면 빠져나감. 아니면 라벨로 이동
    
    ;mov ecx, 100
    ;xor ebx, ebx ; mov ebx, 0 ebx: 결과물
;LABEL_LOOP_SUM:
    ;add ebx, ecx
    ;loop LABEL_LOOP_SUM
    
    ;PRINT_DEC 4, ebx
    ;NEWLINE
    
    ; 분기문 (if)
    ; 특정 조건에 따라서 코드 흐름을 제어하는 것
    ; ex) 스킬 버튼 눌렀는가? YES -> 스킬 사용
    ; ex) 제한 시간 내에 던전 입장 수락 버튼을 눌렀는가?
    
    ; 조건 -> 흐름
    
    ; CMP dst, src (dst가 기준)
    ; 비교를 한 결과물은 Flag Register 저장
    
    ; JMP [label] 시리즈
    ; JMP : 무조건 jump
    ; JE : JumpEquals 같으면 jump
    ; JNE : JumpNotEquals 다르면 jump
    ; JG : JumpGreater 크면 jump
    ; JGE : JumpGreaterEquals 크거나 같으면 jump
    ; JL
    ; JLE
    
    ; 두 숫자가 같으면 1, 아니면 0을 출력하는 프로그램
    
    ;mov rax, 10
    ;mov rbx, 10
    
    ;cmp rax, rbx
    
    ;je LABEL_EQUAL
    
    ; je 에 의해 점프를 안했다면, 같지 않다는 의미
    ;mov rcx, 0
    ;jmp LABEL_EQUAL_END
    
;LABEL_EQUAL:
    ;mov rcx, 1
;LABEL_EQUAL_END:
    
    ;PRINT_HEX 1, rcx
    ;NEWLINE
    
    ; 연습 문제: 어떤 숫자(1~100)가 짝수면 1, 홀수면 0을 출력하는 프로그램
    ;mov ax, 91
    
    ; 나누기 연산
    ; div reg
    ; - div b1 => ax / bl (al몫 ah나머지)
    
    ;mov bl, 2
    ;div bl
    ;cmp ah, 0
    ;je L1
    ;mov rcx, 0
    ;jmp L2
    
;L1:
    ;mov rcx, 1
;L2:
    ;PRINT_HEX 1, rcx
    ;NEWLINE
    
    ; 쉬프트(shift) 연산, 논리(logical) 연산
    
    ;mov eax, 0x12345678
    ;PRINT_HEX 4, eax
    ;NEWLINE
    ;shl eax, 8
    ;PRINT_HEX 4, eax
    ;NEWLINE
    ;shr eax, 8
    ;PRINT_HEX 4, eax
    ;NEWLINE
    ; 곱셈/나눗셈
    ; 게임서버에서 ObjectID를 만들어줄 때
    
    ; not and or xor
    
    ; 조건A : 잘생겼다
    ; 조건B : 키가 크다
    
    ; not A : 잘생겼다의 반대 -> (0이면 1, 1이면 0)
    ; A and B : 잘생겼고 and 키도 크고 -> 둘다 1이면 1, 아니면 0
    ; A or B : 잘생겼거나 or 키가 크거나 -> 둘중 하나라도 1이면, 아니면 0
    ; A xor B : 잘생기고 작거나 or 못생기고 크거나 -> 둘다 1이거나 둘다 0이면 0, 아니면 1
    
    ;mov al, 0b10010101
    ;mov bl, 0b01111100
    
    ; 0b00010100 = 0x14
    ;and al, bl ; al = al and bl
    ;PRINT_HEX 1, al
    ;NEWLINE
    
    ; 0b11101011 = 0xeb
    ;not al
    ;PRINT_HEX 1, al
    ;NEWLINE
    
    ; 응용 사례 : bitflag
    
    ;mov al, 0b10010101
    ;mov bl, 0b01111100
    
    ;NEWLINE
    ;PRINT_HEX 1, al
    ;NEWLINE
    ;xor al, bl
    ;PRINT_HEX 1, al
    ;NEWLINE
    ;xor al, bl
    ;PRINT_HEX 1, al
    ;NEWLINE
    ; 동일한 값으로 xor 두번하면 자기 자신으로 되돌아오는 특성
    ; 암호학에서 유용하다! (value xor key)
    
    ; mov al, 0
    ;xor al, al
    ;PRINT_HEX 1, al
    
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
    
;PRINT_MSG:
    ;PRINT_STRING msg
    ;NEWLINE
    ;ret
    
; ex) 두 값중 더 큰 값을 반환하는 max
; 근데 2값을 어떻게 남겨받지? 반환 어떻게?
; eax와 ebx 입력값을 ecx에 반환
;MAX:
    ;call PRINT_MSG
    
    ;cmp eax, ebx
    ;jg L1
    ;mov ecx, ebx
    ;jmp L2
    
;L1:
    ;mov ecx, eax
    
;L2:
    ;ret

    ; 그런데 인자가 10개라면 어떻게 할까? a b c d
    ; eax, ebx에 이미 중요한 값이 있으면 어떻게 할까?
    ; [!] .data .bss 사용하면?
    ; 인자를 도대체 몇개를 할당해야 하지?
    
    ; 다른 메모리 구조가 필요하다
    ; - 꿈이 유효한 동안에는 그 꿈을 유지시켜야 함 (유효 범위의 개념이 있다)
    ; - 꿈이 끝나면 그 꿈을 부셔버려도 됨 (정리의 개념이 있다)
    ; - 꿈에서도 또 꿈을 꿀 수 있다는 것을 고려해야 함 (유동적으로 유효 범위가 확장 가능)
    
    ; [!] 스택(stack)이라는 메모리 영역을 사용
    ; 함수가 사용하는 일종의 메모장
    ; - 매개 변수 전달
    ; - 돌아갈 주소 관리

    ; 변수의 선언 및 사용
    ; 변수는 그냥 데이터를 저장하는 바구니 [ ]
    ; - 처음에 바구니 사용하겠다 선언 (이름과 크기 지정)
    
    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] db(1) dw(2) dd(4) dq(8)
section .data
    msg db 0x48,0x65,0x6c,0x6c,0x6f,0x20,0x57,0x6f,0x72,0x6c,0x64,0x0
    
    ;a db 0x01, 0x02, 0x03, 0x04, 0x05 ; 5 * 1 = 5바이트

    ; 0x0001
    ;b times 5 dw 1 ; 5 * 2 = 10바이트
    
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
    num resb 10