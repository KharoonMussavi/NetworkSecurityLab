//Fermat's Theorem 14 
#include <iostream>
using namespace std;

long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;

    while (exp > 0) {
        result = (result * base) % mod;
        exp--;
    }

    return result;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int a, p;

    cout << "Enter value of a: ";
    cin >> a;

    cout << "Enter prime number p: ";
    cin >> p;

    if (!isPrime(p)) {
        cout << "p is not prime. Fermat theorem cannot be applied." << endl;
        return 0;
    }

    if (a % p == 0) {
        cout << "a is divisible by p. Fermat theorem cannot be applied." << endl;
        return 0;
    }

    long long result = powerMod(a, p - 1, p);

    cout << a << "^" << p - 1 << " mod " << p << " = " << result << endl;

    if (result == 1) {
        cout << "Fermat's Theorem is verified." << endl;
    } else {
        cout << "Fermat's Theorem is not verified." << endl;
    }

    return 0;
}
