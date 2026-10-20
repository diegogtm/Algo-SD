#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Exercice 1
int is_sorted_increasing(int A[], int n) {
    for (int i=1; i<n; i++) {
        if (A[i]<=A[i-1]) return 0;
    }
    return 1;
}

int linear_search(int A[], int n, int target) {
    for (int i=0; i<n; i++) {
        if (A[i] == target) return i;
    }
    return -1;
}       // worst-case time complexity O(n)

int jump_search(int A[], int n, int target) {
    if (is_sorted_increasing(A, n) == 0) return -1;
    int jump = (int)sqrt(n);
    int i = 0;
    while (i < n && target >= A[i]) {
        if (A[i] == target) return i;
        else {
            i += jump;
        }
    }
    if (i >= n) {
        i = n;
    }
    for (int j = 1; j <= jump && i - j >= 0; j++) {
        if (A[i - j] == target) return i - j;
    }
    return -1;
}      // worst-case time complexity O(sqrt(n))

int binary_search(int A[], int n, int target) {
    if (is_sorted_increasing(A, n) == 0) return -1;
    int low = 0; int high = n-1;
    while (low<=high) {
        int mid = (low+high)/2;
        if (A[mid] == target) return mid;
        else
            if (target<A[mid]) high = mid-1;
            else
                low = mid+1;
    }
    return -1;
}       // worst-case time complexity O(log(n))

void performance_comparison() {
    int n = 100000000; int *A = (int*)malloc(n * sizeof(int));
    for (int i=0; i<n; i++) A[i] = i;

    clock_t ti = clock();
    linear_search(A,n, n-1);
    clock_t t2 = clock();
    jump_search(A,n,n-1);
    clock_t t3 = clock();
    binary_search(A, n, n-1);
    clock_t tf = clock();

    

    double lt = 1000.0 * (t2 - ti) / CLOCKS_PER_SEC;
    double jt = 1000.0 * (t3 - t2) / CLOCKS_PER_SEC;
    double bt = 1000.0 * (tf - t3) / CLOCKS_PER_SEC;
    
    printf("Linear Search : %.4f ms\n", lt);
    printf("Jump Search : %.4f ms\n", jt);
    printf("Binary Search : %.4f ms\n", bt);
}

int main() {
    performance_comparison();
    return 0;
}