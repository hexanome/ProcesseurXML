#ifndef COMMUN_H
#define COMMUN_H

using namespace std;
#include <vector>
#include <utility>
#include <string>

typedef pair<string,string> Attribute;
typedef vector<Attribute> AttList;
typedef pair<string,string> ElementName;

#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif


#endif
