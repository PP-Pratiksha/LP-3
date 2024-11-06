#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int iterativeFibonacci(int n)
{
    if (n <= 1)
        return n;

    int a1 = 0, a2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int a3 = a2 + a1;
        a1 = a2;
        a2 = a3;
    }

    return a2;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Recursive nth Fibonacci number: " << fibonacci(n) << endl;
    cout << "Iterative nth Fibonacci number: " << iterativeFibonacci(n) << endl;

    return 0;
}
