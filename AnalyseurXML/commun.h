#ifndef COMMUN_H
#define COMMUN_H

using namespace std;
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>

typedef map<string,string> AttList;
typedef pair<string,string> ElementName;

#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif

#endif
