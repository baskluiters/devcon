#include <iostream>

void generateFibonacci(int n) {
    int a = 0, b = 1, next;

    std::cout << "Fibonacci Series: " << a << ", " << b;

    for (int i = 2; i < n; ++i) {
        next = a + b;
        a = b;
        b = next;
        std::cout << ", " << next;
    }
    std::cout << std::endl;
}

int main() {
    int n = 10;
    
    generateFibonacci(n);

    return 0;
}