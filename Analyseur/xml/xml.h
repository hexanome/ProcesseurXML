#ifndef XML_SERVICES_H
#define XML_SERVICES_H

#include "../includes/common.h"
#include "model/document.h"

extern FILE* xmlin;
extern int xmlparse(char ** content);

public:
	Document* parseStream(iostream inStream);

#endif