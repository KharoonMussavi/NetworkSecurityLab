//Euler's Totient Function 12
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

int phi(int n) {
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (gcd(i, n) == 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;

    cout << "Enter number: ";
    cin >> n;

    cout << "Euler Totient phi(" << n << ") = " << phi(n) << endl;

    return 0;
}
