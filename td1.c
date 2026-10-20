#include <stdio.h>
#include <time.h>

int fibonacci(int n){
    if (n == 0 || n == 1){
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int DPFib[1] = {-1};

int dynamic_fibonacci(int n, int* DPFib){
    if (n <= 1){
        return n;
    }
    else if (DPFib[n] != -1){
        return DPFib[n];
    }
    DPFib[n] = dynamic_fibonacci(n-1, DPFib) + dynamic_fibonacci(n-2, DPFib);
    return DPFib[n];
}

int prime_numbers(int n) {
    if (n <= 2) return 0;
    int count = 0;
    for (int i = 2; i < n; i++) {
        int is_prime = 1;
        for (int j = 2; j * j <= i && is_prime == 1; j++) {
            if (i % j == 0) {
                is_prime = 0;
            }
        }
        if (is_prime == 1) {
            count++;
        }
    }
    return count;
}

void main() {
    int n = 40;
    int DPFib[41] = {-1};

    clock_t start = clock();
    fibonacci(n);
    clock_t end = clock();
    float t_naif = end-start;
    printf("Temps naif : %f secondes\n", t_naif / CLOCKS_PER_SEC);

    start = clock();
    dynamic_fibonacci(n, DPFib);
    end = clock();
    float t_dyn = end-start;
    printf("Temps dynamique : %f secondes\n", t_dyn / CLOCKS_PER_SEC);

    int a = prime_numbers(45);
    printf("%i",a);
}