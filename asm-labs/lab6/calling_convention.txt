# System V AMD64 ABI
|Целые аргументы|rdi,rsi,rdx,rcx,r8,r9|
|Аргументы с плавающей точкой|xmm0 - xmm7|
|Изменяемые регистры|rax,rcx,rdx,rsi,rdi,r8-r11,st(0)-st(7),xmm/ymm/zmm|
|Неизменяемые регистры|rbx,rbp,r12-r15|
|Возвращаемое значение|rax,rdx:rax,xmm0|
|Выравнивание rsp| 16 байт|
