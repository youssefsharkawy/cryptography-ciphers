#include <bits/stdc++.h>

using namespace std;

string caesar(string plaintext , int key,bool encrypt){
    string s = "";
    for(char c : plaintext){
        if(isalpha(c))
        {
            char isUpperOrLower = isupper(c) ? 'A' : 'a';
            int val =  c - isUpperOrLower;
            if(encrypt)
            {
                val = (val + key) % 26;
            }else{
                val = (val - key + 26) % 26;

            }

            char c2 = isUpperOrLower + val;
            s+=c2;
        }
        else{
            s+= c;
        }


    }
    return s;
}

string caesarEncrypt(string plaintext,int key){
    return caesar(plaintext, key, true);
}

string caesarDecrypt(string plaintext,int key){
    return caesar(plaintext, key, false);
}

int main() {
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
                cout << "Enter Encryption KEY: \n";
                int encryptKey;
                while (!(cin >> encryptKey)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid integer key.\n";
                }
                cout << "Encrypted MSG: " << caesarEncrypt(myStr, encryptKey)<<endl;
                break;
            case 2:
                cout << "Enter Encrypted MSG: \n";
                cin.ignore();
                getline(cin, myStr);
                cout << "Enter Decryption KEY: \n";
                int decryptKey;
                while (!(cin >> decryptKey)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid integer key.\n";
                }
                cout << "PlainText MSG: " << caesarDecrypt(myStr, decryptKey) << endl;
                break;
            default:
                cout << "Invalid choice. Please enter 1 for Encryption or 2 for Decryption. \n";
                break;
        }
    }
}
