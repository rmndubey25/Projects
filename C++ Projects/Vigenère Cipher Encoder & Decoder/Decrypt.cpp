#include <iostream>
#include <string>

int main() {
    std::string ciphertext;
    std::string keyword;

    std::cout << "Enter ciphertext to decode:\n";
    std::getline(std::cin, ciphertext);

    std::cout << "Enter secret keyword:\n";
    std::cin >> keyword;

    std::string fullKey = "";
    int j = 0; 
    for (int i = 0; i < ciphertext.length(); i++) {
        fullKey += keyword[j];
        j++;
        if (j >= keyword.length()) {
            j = 0; 
        }
    }

    std::string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        char cipherChar = ciphertext[i];
        char keyChar = fullKey[i];

        if (cipherChar >= 'a' && cipherChar <= 'z') {
            int cipherValue = cipherChar - 'a';
            int keyValue = keyChar - 'a';
            int ptValue = cipherValue - keyValue;
            if (ptValue < 0) {
                ptValue = ptValue + 26;
            }
            char ptChar = ptValue + 'a';
            plaintext += ptChar;
        }
        else {
            plaintext += cipherChar;
        }
    }

    std::cout << "\nDecrypted Plaintext: " << plaintext << std::endl;

    return 0;
}
