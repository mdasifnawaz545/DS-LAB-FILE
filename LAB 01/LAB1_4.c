#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct complex addition(struct complex c1, struct complex c2);
struct complex multiplication(struct complex *, struct complex *);
struct complex
{
    int real;
    int imaginary;
};
int main()

{
    int i, r, a, b;
    struct complex c1;
    struct complex c2;
    struct complex r1;
    struct complex r2;
    printf("Enter the Complex number 1: ");
    scanf("%d %d", &c1.real, &c1.imaginary);
    printf("Enter the Complex number 2: ");
    scanf("%d %d", &c2.real, &c2.imaginary);
    printf("MENU\n");
    printf("1.Addition\n");
    printf("2.Multiplication\n");
    printf("Enter your choice : ");
    scanf("%d", &a);
    if (a == 1)
    {
        r1 = addition(c1, c2);
        printf("Sum is : %d + %di\n", r1.real, r1.imaginary);
    }
    else if (a == 2)
    {
        r2 = multiplication(&c1, &c2);
        printf("Multiplication is : %d + %di", r2.real, r2.imaginary);
    }
    return 0;
}
struct complex addition(struct complex c1, struct complex c2)
{
    struct complex r1;
    int real, imaginary;
    r1.real = c1.real + c2.real;
    r1.imaginary = c1.imaginary + c2.imaginary;
    return r1;
}
struct complex multiplication(struct complex *c1, struct complex *c2)
{
    struct complex r2;
    int f1, f2, f3, f4;

    f1 = c1->real * c2->real;
    f2 = c1->real * c2->imaginary;
    f3 = c1->imaginary * c2->real;
    f4 = c1->imaginary * c2->imaginary;
    r2.real = f1 - f4;
    r2.imaginary = f2 + f3;

    return r2;
}