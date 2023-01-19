#include <stdio.h>


void prime_factorization(int n) {
    int i;
    for (i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
}

int main() {
    int n = 1021020;
    prime_factorization(n);
    return 0;
}
