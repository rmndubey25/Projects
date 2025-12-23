#include <iostream>
#include <string>
#include <cctype> // for islower, isupper, isdigit

using namespace std;

int main() {
    string pass;

    while (true) { // keep asking until valid
        cout << "Enter the password: ";
        cin >> pass;

        bool valid = true; // assume password is valid

        //Check length
        if (pass.length() < 8) {
            cout << "Password must be at least 8 characters long.\n";
            valid = false;
        }

        //Check special character
        if (pass.find_first_of("!@#$%^&*()-_+=[]{}|\\:;\"'<>,.?") == string::npos) {
            cout << "Enter at least one special character.\n";
            valid = false;
        }

        //Check lowercase, uppercase, and digit in one loop
        bool hasLower = false, hasUpper = false, hasDigit = false;

        for (char c : pass) {
            if (islower(c)) hasLower = true;
            if (isupper(c)) hasUpper = true;
            if (isdigit(c)) hasDigit = true;
        }

        if (!hasLower) {
            cout << "Needs at least one lowercase.\n";
            valid = false;
        }

        if (!hasUpper) {
            cout << "Needs at least one uppercase.\n";
            valid = false;
        }

        if (!hasDigit) {
            cout << "Needs at least one digit.\n";
            valid = false;
        }

        //If everything is valid, exit loop
        if (valid) {
            cout << "Password accepted!\n";
            break;
        }

        cout << "Please try again.\n\n"; // prompt again
    }

    return 0;
}
