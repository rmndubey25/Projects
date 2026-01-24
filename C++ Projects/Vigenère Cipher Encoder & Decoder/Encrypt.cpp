#include <iostream>
#include <string>

int main() {
    std::string plaintext;
    std::string keyword;

    std::cout << "Enter plaintext to encode:\n";
    std::getline(std::cin, plaintext);

    std::cout << "Enter secret keyword:\n";
    std::cin >> keyword;

    for (int i = 0; i < plaintext.length(); i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            plaintext[i] = plaintext[i] - 'A' + 'a';
    }

    for (int i = 0; i < keyword.length(); i++) {
        if (keyword[i] >= 'A' && keyword[i] <= 'Z')
            keyword[i] = keyword[i] - 'A' + 'a';
    }

    std::string fullKey = keyword;
    for (int i = 0; fullKey.length() < plaintext.length(); i++) {
        fullKey += keyword[i % keyword.length()];
    }

    std::string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            int ptValue = plaintext[i] - 'a';
            int keyValue = fullKey[i] - 'a';
            int cipherValue = (ptValue + keyValue) % 26;
            ciphertext += (cipherValue + 'a');
        }
        else {
            ciphertext += plaintext[i];
        }
    }

    std::cout << "\nCiphertext: " << ciphertext << std::endl;

    return 0;
}
