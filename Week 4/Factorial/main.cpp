#include <iostream>
using namespace std;

long long Factorial(long long n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n*Factorial(n-1);
    }
}

int main() {
    long long number;
    cin >> number;

    cout << Factorial(number);

    return 0;
}
