#include <stdio.h>

int gcd(int, int);

int main(){
    int a, b;

    printf("Enter a:");
    scanf("%d", &a);

    printf("Enter b:");
    scanf("%d", &b);

    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    return 0;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
