//DES 07
#include <iostream>
using namespace std;

string encryptDESDemo(string text, string key) {
    string encrypted = "";

    for (int i = 0; i < text.length(); i++) {
        encrypted += text[i] ^ key[i % key.length()];
    }

    return encrypted;
}

string decryptDESDemo(string encrypted, string key) {
    string decrypted = "";

    for (int i = 0; i < encrypted.length(); i++) {
        decrypted += encrypted[i] ^ key[i % key.length()];
    }

    return decrypted;
}

int main() {
    string plaintext, key;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter key: ";
    getline(cin, key);

    string encrypted = encryptDESDemo(plaintext, key);
    string decrypted = decryptDESDemo(encrypted, key);

    cout << "Encrypted Text in ASCII values: ";
    for (char ch : encrypted) {
        cout << int(ch) << " ";
    }

    cout << "\nDecrypted Text: " << decrypted << endl;

    return 0;
}
