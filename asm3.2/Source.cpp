#include <iostream>

int main() {
    int A[25], B[25], k = 0, x = 1, y = 1;

    _asm {
        mov edx, 0
        lea esi, A
        lea edi, B

        loop1 :
        mov eax, x

            loop2 :
        mov ebx, y
            imul eax, 2
            imul ebx, 3
            add eax, ebx
            cmp eax, 50
            je found
            jg incx
            inc y
            mov eax, x
            jmp loop2

            incx :
        inc x
            mov y, 0
            jmp loop1

            found :
        mov ecx, x
            mov[esi][edx * 4], ecx
            mov ecx, y
            mov[edi][edx * 4], ecx
            inc edx
            cmp x, 25
            je end
            jmp incx
            end :
        mov k, edx
    }

    std::cout <<  k << std::endl;
    for (int i = 0; i < k; ++i) {
        std::cout << "2*" << A[i] << " + 3*" << B[i] << " = 50" << std::endl;
    }

    return 0;
}
