#include <stdio.h>
#define test(a, b) a##b //token concatenation

int main() {
    printf("%d\n", test(34, 45));

    char* s =  "B\x4b"; // \x hexadecimal 4b is 75
    printf("%s", s); // -> BK

    int i = 6;
    printf("\n%d %d %d %d %d\n", !i, ++i, i+3, i--, i++);

    //switch case
    i = 3;
    switch (i)
    {
        default:
            printf("yooo\n");
        case 1:
            printf("case 1\n");
        case 3:
            printf("case 3\n"); //no break so fall through from here
        case 2:
            printf("case 2\n");
        case 5:
            printf("case 5\n"); 
    }

    //unsigned conversion
    unsigned int ar = 6;
    int b = -20;  // unsigned conversion makes b -> 2^32 - 20

    (ar+b > 6) ? puts("> 6\n") : puts("<= 6\n");

    
    //pointer indirection
    // int *****************p; //compiler should be able to do atleast 12
    

    int a[] = {1,2,4,6,8};
    int* p[] = {a, a+1, a+2, a+3, a+4};
    int **p1 = p;
    int *p2 = *(p + 2);
    printf("%u %u %u\n", *++p2,++*p2++,*++*++p1);
}