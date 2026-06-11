//ceaser cipher 01
#include <iostream>
using namespace std;

string encryptCaesar(string text, int key) {
    string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            result += char((ch - base + key) % 26 + base);
        } else {
            result += ch;
        }
    }

    return result;
}

string decryptCaesar(string text, int key) {
    string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            result += char((ch - base - key + 26) % 26 + base);
        } else {
            result += ch;
        }
    }

    return result;
}

int main() {
    string text;
    int key;

    cout << "Enter plaintext: ";
    getline(cin, text);

    cout << "Enter key: ";
    cin >> key;

    string encrypted = encryptCaesar(text, key);
    string decrypted = decryptCaesar(encrypted, key);

    cout << "Encrypted Text: " << encrypted << endl;
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
