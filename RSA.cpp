//RSA Algorithm 10
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;

    while (exp > 0) {
        result = (result * base) % mod;
        exp--;
    }

    return result;
}

int main() {
    int p, q, e, d = 0;
    int message;

    cout << "Enter prime number p: ";
    cin >> p;

    cout << "Enter prime number q: ";
    cin >> q;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    cout << "Enter public key e: ";
    cin >> e;

    if (gcd(e, phi) != 1) {
        cout << "Invalid e. gcd(e, phi) must be 1." << endl;
        return 0;
    }

    for (int i = 1; i < phi; i++) {
        if ((i * e) % phi == 1) {
            d = i;
            break;
        }
    }

    cout << "Enter message as number: ";
    cin >> message;

    long long encrypted = powerMod(message, e, n);
    long long decrypted = powerMod(encrypted, d, n);

    cout << "n = " << n << endl;
    cout << "phi = " << phi << endl;
    cout << "Public Key: (" << e << ", " << n << ")" << endl;
    cout << "Private Key: (" << d << ", " << n << ")" << endl;
    cout << "Encrypted Message: " << encrypted << endl;
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}
