#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

inline void parse_string(const string &question, string &input) {
    string raw;
    cout << question << endl;

    while (true) {
        getline(cin, raw);

        if (!raw.empty()) {
            input = raw;
            return;
        }

        cout << "Invalid input. Please enter a non-empty string." << endl;
    }
}

inline void parse_bool(const string &question, bool &input) {
    string raw;
    cout << question << "(y/n)" << endl;

    while (true) {
        getline(cin, raw);
        ranges::transform(raw, raw.begin(),
                          [](unsigned char symbol) { return tolower(symbol); });

        if (raw == "y") {
            input = true;
            return;
        }

        if (raw == "n") {
            input = false;
            return;
        }

        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
    }
}

inline void parse_int(const string &question, int &input) {
    string raw;
    cout << question << endl;

    while (true) {
        getline(cin, raw);

        try {
            input = stoi(raw);
            return;
        } catch (invalid_argument &) {
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
    }
}

#endif // INPUT_UTILS_H
