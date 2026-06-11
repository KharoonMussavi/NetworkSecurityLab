
//Chinese Remainder Theorem 13
#include <iostream>
using namespace std;

int findCRT(int rem[], int mod[], int n) {
    int x = 1;

    while (true) {
        bool found = true;

        for (int i = 0; i < n; i++) {
            if (x % mod[i] != rem[i]) {
                found = false;
                break;
            }
        }

        if (found) {
            return x;
        }

        x++;
    }
}

int main() {
    int n;

    cout << "Enter number of equations: ";
    cin >> n;

    int rem[20], mod[20];

    for (int i = 0; i < n; i++) {
        cout << "Enter remainder " << i + 1 << ": ";
        cin >> rem[i];

        cout << "Enter modulus " << i + 1 << ": ";
        cin >> mod[i];
    }

    int result = findCRT(rem, mod, n);

    cout << "Smallest value of x = " << result << endl;

    return 0;
}
