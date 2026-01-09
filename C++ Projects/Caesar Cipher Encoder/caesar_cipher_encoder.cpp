#include <iostream>
// Cipher program to shift characters by a specified number
int main() {

// Variables to hold user input
    char input_text[100] = "";
    int increase_by;

// Get user input
    std::cout << "Enter text to cipher: ";
    std::cin.getline(input_text, sizeof(input_text));

// Get shift value
    std::cout << "Enter the number to increase by: ";
    std::cin >> increase_by;

// Process each character in the input text
    for (int i=0; input_text[i] != '\0'; ++i) {
        if (input_text[i] >= 'a' && input_text[i] <= 'z') {
            input_text[i] = input_text[i] + increase_by;
            // Wrap around if it goes past 'z'
            if (input_text[i] > 'z') {
                input_text[i] = input_text[i] - 26;
            }

        } 
        else if (input_text[i] >= 'A' && input_text[i] <= 'Z') {
            if (input_text[i] >= 'A' && input_text[i] <= 'Z') {
            input_text[i] = input_text[i] + increase_by;}
            // Wrap around if it goes past 'z'
            if (input_text[i] > 'Z') {
                input_text[i] = input_text[i] - 26;
            }
        }

    }

    std::cout << "Ciphered text: " << input_text << std::endl;
    return 0;
}
