#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <map>

using namespace std;

class Test {

  public:
    Test();
    ~Test();
    void run(string name, bool(*function)());
    void end();

  private:
    int tests;
    int passed;

};

#endif
