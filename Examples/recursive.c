#include <stdio.h>

int factorial(int n) {

    if (n == 1)
        return 1;

    return n * factorial(n-1);

}

int main() {

    int n = 5;
    int output = factorial(n);

    printf("%d! = %d\n",n,output);

    return 0;
}