
// Task 1

#include <iostream>

long pow_a(long a, int exponent) {
    long result = 1;
    _asm {
        mov ecx, exponent
        dec ecx
        mov eax, a
    loop_start:
        test ecx, ecx
        jz loop_end
        mov ebx, a
        mul ebx
        dec ecx
        jmp loop_start
    loop_end:
        mov result, eax
    }
    return result;
}

int main() {
    long a;
    std::cout << "a = ";
    std::cin >> a;

    long result = pow_a(a, 12) + pow_a(a, 8) + a;

    std::cout << "a^12 + a^8 + a = " << result << std::endl;
    return 0;
}



// Task 2

#include <iostream>

int main() {

    const int size = 50;
    int solutions[size]{0};
    int count = 0;

    _asm {
        mov esi, 0
        mov edi, 0
        
        loop_x:
        cmp esi, 25
        jg end_loop_x

        mov ebx, 0

        loop_y:
        cmp ebx, 16
        jg end_loop_y

            mov ecx, 2
            mov eax, esi
            mul ecx

            add eax, ebx
            add eax, ebx
            add eax, ebx

            cmp eax, 50
            jne not_equal

            mov solutions[edi], esi
            mov solutions[edi + 4], ebx
            add edi, 8
            add count, 1

            not_equal:
            inc ebx
            jmp loop_y

            end_loop_y :
            inc esi
            jmp loop_x;

            end_loop_x :
    }

    std::cout << "Number of solutions: " << count << std::endl;

    for (int i = 0; i < size && solutions[i] != 0 && solutions[i + 1] != 0; i += 2) {
        std::cout << "2*" << solutions[i] << " + 3*" << solutions[i + 1] << " = 50" << std::endl;
    }

    return 0;
}



// Task 3
 
#include <iostream>

int main() {
    const int MaxNumbers = 100;
    int fibonacci[MaxNumbers]{0};
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    std::cout << fibonacci[0] << ", " << fibonacci[1];

    _asm {
        mov eax, 0
        mov ebx, 1
        mov ecx, 8

        fibonacci_loop:
            add eax, ebx
            
            mov edx, eax
            
            mov eax, ebx
            mov ebx, edx

            mov esi, ecx
            mov fibonacci[esi], eax
            jo end_loop
            add ecx, 4

            jmp fibonacci_loop

            end_loop :
    }

    for (int i = 2; i < MaxNumbers && fibonacci[i] != 0; i++) {
        std::cout << ", " << fibonacci[i];
    }

    return 0;
}



// Task 4

#include <iostream>

int main()
{
    int numerator, denominator;
    std::cout << "numerator: ";
    std::cin >> numerator;
    std::cout << "denominator: ";
    std::cin >> denominator;
    if (numerator == 0) {
        std::cout << "result: " << numerator << std::endl;
        return 0;
    }

    int nod = 1;
    _asm
    {
        mov eax, numerator
        mov ebx, denominator

        cmp eax, 0
        jge divide
        neg eax

        divide:
        gcd_loop :
        cmp ebx, 0
        je gcd_end
        mov edx, 0
        idiv ebx
        mov eax, ebx
        mov ebx, edx
        jmp gcd_loop
            
        gcd_end :
        mov nod, eax
        


            mov eax, numerator
            xor edx, edx
            cmp eax, 0
            jge sokr

            cmp eax, 0
            jl minus
            jmp done

            sokr :
            div nod
            mov numerator, eax
            jmp denom

            minus :
            neg eax
            idiv nod
            neg eax
            mov numerator, eax
            done2 :


        denom:
        mov eax, denominator
        mov edx, 0
        idiv nod
        mov denominator, eax
        done3:
        done:
    }

    std::cout << "result: " << numerator << "/" << denominator << std::endl;

    return 0;
}
