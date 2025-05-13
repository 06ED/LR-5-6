#include "cruise/Cruise.hpp"
#include <iostream>

using namespace std;

int main() {
  Cruise cruise("sd");
  cout << cruise.getPackageId() << endl;
  cout << "Hello, Uwu!" << endl;

  return 0;
}
