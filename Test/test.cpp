#include "test.h"

Test::Test() {
  tests = 0; passed = 0;
}

Test::~Test() {
}

void Test::run(string name, bool(*function)()) {
  tests++;
  cout << "[test] " << name << " ";
  if (!function()) {
    cout << "FAIL";
  } else {
    cout << "OK";
    passed++;
  }
  cout << endl;
}

void Test::end() {
  cout << passed << "/" << tests << " tests passed" << endl;
  tests = 0; passed = 0;
}
