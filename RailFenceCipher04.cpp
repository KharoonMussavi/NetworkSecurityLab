//Rail Fence Cipher 04
#include <iostream>
#include <vector>
using namespace std;

string encryptRailFence(string text, int key) {
    vector<string> rail(key);
    int row = 0;
    bool down = true;

    for (char ch : text) {
        rail[row] += ch;

        if (row == 0) down = true;
        else if (row == key - 1) down = false;

        row += down ? 1 : -1;
    }

    string result = "";
    for (string r : rail) {
        result += r;
    }

    return result;
}

int main() {
    string text;
    int key;

    cout << "Enter plaintext: ";
    getline(cin, text);

    cout << "Enter number of rails: ";
    cin >> key;

    string encrypted = encryptRailFence(text, key);

    cout << "Encrypted Text: " << encrypted << endl;

    return 0;
}
