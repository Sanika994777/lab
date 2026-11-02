#include <iostream>
using namespace std;

// Non-recursive (iterative) Fibonacci - Time: O(n), Space: O(1)
int fibonacciIterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;  
        b = c;
    }
    return b;
}

// Recursive Fibonacci - Time: O(2^n), Space: O(n) due to call stack
int fibonacciRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    
    cout << "Enter the position of Fibonacci number: ";
    cin >> n;
    
    if (n < 0) {    
        cout << "Please enter a non-negative number." << endl;
        return 0;
    }
    
    // Calculate using iterative method
    cout << "\nFibonacci number at position " << n << ":" << endl;
    cout << "Iterative: " << fibonacciIterative(n) << endl;
    
    // Calculate using recursive method
    cout << "Recursive: " << fibonacciRecursive(n) << endl;
    
    // Complexity Analysis
    cout << "\nComplexity Analysis:" << endl;
    cout << "Iterative - Time: O(n), Space: O(1)" << endl;
    cout << "Recursive - Time: O(2^n), Space: O(n)" << endl;
    
    return 0;
}
    