#include <iostream>
#include <chrono>
#include <math.h>
using namespace std;

unsigned int fibonacci(unsigned int n);
unsigned int fib(unsigned int n);
unsigned int fibonacciPol(double n);

int main()
{
    //cout << fibonacciPol(3) << endl;
    cout << fibonacci(50) << endl;
    return 0;
}

unsigned int fibonacciPol(double n)
{
    return ( pow((1 + sqrt(5)) / 2, n)
        - pow(((1 - sqrt(5)) / 2), n) ) / sqrt(5);
}

unsigned int fibonacci(unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i)
    {
        auto start = chrono::high_resolution_clock::now();
        cout << "f(" << i << ") = " << fib(i);
        auto stop = chrono::high_resolution_clock::now();
        auto durationNano = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        cout << " | Seg: " << float(durationNano.count()) / 1000000000
             << " | Mili: " << float(durationNano.count()) / 1000000
             << " | Micro: " << float(durationNano.count()) / 1000
             << " | Nano: " << float(durationNano.count()) << endl;
    }
}

unsigned int fib(unsigned int n)
{
    if (n <= 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}
