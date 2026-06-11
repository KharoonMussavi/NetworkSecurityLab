//Playfair Cipher 02
#include <iostream>
#include <vector>
#include <set>
using namespace std;

char matrix[5][5];

void generateMatrix(string key) {
    set<char> used;
    string finalKey = "";

    for (char ch : key) {
        ch = toupper(ch);
        if (ch == 'J') ch = 'I';

        if (isalpha(ch) && used.find(ch) == used.end()) {
            finalKey += ch;
            used.insert(ch);
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;

        if (used.find(ch) == used.end()) {
            finalKey += ch;
            used.insert(ch);
        }
    }

    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = finalKey[index++];
        }
    }
}

void findPosition(char ch, int &row, int &col) {
    if (ch == 'J') ch = 'I';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string prepareText(string text) {
    string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            if (ch == 'J') ch = 'I';
            result += ch;
        }
    }

    string prepared = "";

    for (int i = 0; i < result.length(); i++) {
        prepared += result[i];

        if (i + 1 < result.length() && result[i] == result[i + 1]) {
            prepared += 'X';
        }
    }

    if (prepared.length() % 2 != 0) {
        prepared += 'X';
    }

    return prepared;
}

string encryptPlayfair(string text) {
    string encrypted = "";

    for (int i = 0; i < text.length(); i += 2) {
        char a = text[i];
        char b = text[i + 1];

        int r1, c1, r2, c2;
        findPosition(a, r1, c1);
        findPosition(b, r2, c2);

        if (r1 == r2) {
            encrypted += matrix[r1][(c1 + 1) % 5];
            encrypted += matrix[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            encrypted += matrix[(r1 + 1) % 5][c1];
            encrypted += matrix[(r2 + 1) % 5][c2];
        } else {
            encrypted += matrix[r1][c2];
            encrypted += matrix[r2][c1];
        }
    }

    return encrypted;
}

int main() {
    string key, plaintext;

    cout << "Enter key: ";
    getline(cin, key);

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    generateMatrix(key);

    cout << "\nPlayfair Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    string prepared = prepareText(plaintext);
    string encrypted = encryptPlayfair(prepared);

    cout << "\nPrepared Text: " << prepared << endl;
    cout << "Encrypted Text: " << encrypted << endl;

    return 0;
}
