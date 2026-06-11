//RC4 09
#include <iostream>
#include <vector>
using namespace std;

vector<int> KSA(string key) {
    vector<int> S(256);

    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }

    int j = 0;

    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % key.length()]) % 256;
        swap(S[i], S[j]);
    }

    return S;
}

string RC4(string text, string key) {
    vector<int> S = KSA(key);
    int i = 0, j = 0;
    string output = "";

    for (char ch : text) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;

        swap(S[i], S[j]);

        int k = S[(S[i] + S[j]) % 256];

        output += ch ^ k;
    }

    return output;
}

int main() {
    string plaintext, key;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter key: ";
    getline(cin, key);

    string encrypted = RC4(plaintext, key);
    string decrypted = RC4(encrypted, key);

    cout << "Encrypted Text in ASCII values: ";
    for (char ch : encrypted) {
        cout << int(ch) << " ";
    }

    cout << "\nDecrypted Text: " << decrypted << endl;

    return 0;
}
