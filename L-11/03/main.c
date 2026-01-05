#include <stdio.h>
#include <math.h>

int getLength(long long value) {
    int counter = 0;
    if (value == 0) return 1;
    while (value != 0) {
        counter++;
        value /= 10;
    }
    return counter;
}

long long power(int base, int exp) {
    long long res = 1;
    while (exp > 0) {
        res *= base;
        exp--;
    }
    return res;
}

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10) {
        return x * y;
    }

    int n = fmax(getLength(x), getLength(y));
    int m = n / 2;

    long long multiplier = power(10, m);

    long long x1 = x / multiplier;
    long long x0 = x % multiplier;

    long long y1 = y / multiplier;
    long long y0 = y % multiplier;

    long long z0 = karatsuba(x0, y0);

    long long z2 = karatsuba(x1, y1);

    long long z1_temp = karatsuba(x1 + x0, y1 + y0);
    long long z1 = z1_temp - z2 - z0;

    return z2 * power(10, 2 * m) + z1 * power(10, m) + z0;
}

int main() {
    printf("Inmultire Karatsuba");
    long long x = 1234;
    long long y = 5678;

    printf("Numere: %lld, %lld\n", x, y);
    printf("Rezultat Karatsuba: %lld\n", karatsuba(x, y));
    printf("Rezultat clasic:    %lld\n", x * y);

    return 0;
}
