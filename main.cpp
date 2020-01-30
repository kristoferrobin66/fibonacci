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
        auto durationNano = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        cout << " | Seg: " << float(durationNano.count()) / 1000000000
             << " | Mili: " << float(durationNano.count()) / 1000000
             << " | Micro: " << float(durationNano.count()) / 1000
             << " | Nano: " << float(durationNano.count()) << endl;
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
