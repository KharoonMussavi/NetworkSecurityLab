//Diffie-Hellman Key Exchange 11
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

int main() {
    long long p, g, a, b;

    cout << "Enter prime number p: ";
    cin >> p;

    cout << "Enter primitive root g: ";
    cin >> g;

    cout << "Enter Alice private key a: ";
    cin >> a;

    cout << "Enter Bob private key b: ";
    cin >> b;

    long long A = powerMod(g, a, p);
    long long B = powerMod(g, b, p);

    long long keyAlice = powerMod(B, a, p);
    long long keyBob = powerMod(A, b, p);

    cout << "Alice Public Key: " << A << endl;
    cout << "Bob Public Key: " << B << endl;

    cout << "Secret Key calculated by Alice: " << keyAlice << endl;
    cout << "Secret Key calculated by Bob: " << keyBob << endl;

    return 0;
}
