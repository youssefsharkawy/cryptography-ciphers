#include <bits/stdc++.h>

using namespace std;

pair<string, string> generateMapping() {
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string shuffled = alphabet;
    random_shuffle(shuffled.begin(), shuffled.end());
    return make_pair(alphabet, shuffled);
}

string substitution(string plaintext, string from, string to){
    string s = "";
    for(char c : plaintext){
        size_t pos = from.find(c);
        if(pos != string::npos){
            s += to[pos];
        } else {
            s += c;
        }
    }
    return s;
}

string substitutionEncrypt(string plaintext, string from, string to){
    return substitution(plaintext, from, to);
}

string substitutionDecrypt(string ciphertext, string from, string to){
    return substitution(ciphertext, to, from);
}

int main() {
    pair<string, string> mapping = generateMapping();

    while (true) {
        cout << "1. Encryption" << endl;
        cout << "2. Decryption" << endl;
        cout << "0. Exit" << endl;

        int choice;
        cout << "Enter your choice: \n";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting." << endl;
            break;
        }

        string myStr = "";

        switch (choice) {
            case 1:
                cout << "Enter PlainText MSG: \n";
                cin.ignore();
                getline(cin, myStr);
                cout << "Encrypted MSG: " << substitutionEncrypt(myStr, mapping.first, mapping.second) << endl;
                break;
            case 2:
                cout << "Enter Encrypted MSG: \n";
                cin.ignore();
                getline(cin, myStr);
                cout << "PlainText MSG: " << substitutionDecrypt(myStr, mapping.first, mapping.second) << endl;
                break;
            default:
                cout << "Invalid choice. Please enter 1 for Encryption or 2 for Decryption. \n";
                break;
        }
    }
}