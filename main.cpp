#include <iostream>
#include <chrono>
using namespace std;

unsigned int fibonacci(unsigned int n);

int main()
{
    for (unsigned int i = 0; i < 51; ++i)
    {
        auto start = chrono::high_resolution_clock::now();
        cout << "f(" << i << ") = " << fibonacci(i);
        auto stop = chrono::high_resolution_clock::now();
        auto durationMilli= chrono::duration_cast<chrono::milliseconds>(stop - start);
        auto durationMicro = chrono::duration_cast<chrono::microseconds>(stop - start);
        auto durationNano = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        cout << " | Milli: " << durationMilli.count()
             << " | Micro: " << durationMicro.count()
             << " | Nano : " << durationNano.count() << endl;
    }
    return 0;
}

unsigned int fibonacci(unsigned int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
