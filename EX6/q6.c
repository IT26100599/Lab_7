#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void simplify_fraction(int *numerator, int *denominator)
{
    int divisor = gcd(*numerator, *denominator);

    if (divisor != 0)
    {
        *numerator = *numerator / divisor;
        *denominator = *denominator / divisor;
    }
}

int main()
{
    int numerator, denominator;

    printf("Enter numerator: ");
    scanf("%d", &numerator);

    printf("Enter denominator: ");
    scanf("%d", &denominator);

    if (denominator == 0)
    {
        printf("Denominator cannot be zero.\n");
        return 1;
    }

    simplify_fraction(&numerator, &denominator);

    printf("Simplified Fraction: %d/%d\n",
           numerator, denominator);

    return 0;
}
