#include <stdio.h>

void print(int A[], int num);

int main() {
int A[] = { 1,2,3,4}, B[] = {5,6,7,8,9}
print(A, 4);
}

void print(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d", arr[i]);
    }
}
