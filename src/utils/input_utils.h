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
    } else {
      cout << "Invalid input. Please enter a non-empty string." << endl;
    }
  }

  return;
}

inline void parse_bool(const string &question, bool &input) {
  string raw;
  cout << question << "(y/n)" << endl;

  while (true) {
    getline(cin, raw);
    transform(raw.begin(), raw.end(), raw.begin(),
              [](unsigned char symbol) { return tolower(symbol); });

    if (raw == "y") {
      input = true;
      return;
    } else if (raw == "n") {
      input = false;
      return;
    } else {
      cout << "Invalid input. Please enter 'y' or 'n'." << endl;
    }
  }

  return;
}

inline void parse_int(const string &question, int &input) {
  string raw;
  cout << question << endl;

  while (true) {
    getline(cin, raw);

    try {
      input = stoi(raw);
      return;
    } catch (invalid_argument &e) {
      cout << "Invalid input. Please enter a valid integer." << endl;
    }
  }

  return;
}
