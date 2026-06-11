//Hill cipher 03
#include <iostream>
using namespace std;

int main() {
    int key[2][2];
    string text;

    cout << "Enter 2x2 key matrix:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> key[i][j];
        }
    }

    cout << "Enter plaintext: ";
    cin >> text;

    if (text.length() % 2 != 0) {
        text += 'X';
    }

    string encrypted = "";

    for (int i = 0; i < text.length(); i += 2) {
        int p1 = toupper(text[i]) - 'A';
        int p2 = toupper(text[i + 1]) - 'A';

        int c1 = (key[0][0] * p1 + key[0][1] * p2) % 26;
        int c2 = (key[1][0] * p1 + key[1][1] * p2) % 26;

        encrypted += char(c1 + 'A');
        encrypted += char(c2 + 'A');
    }

    cout << "Encrypted Text: " << encrypted << endl;

    return 0;
}
