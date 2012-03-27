#ifndef DTD_SERVICES_H
#define DTD_SERVICES_H

#include "../includes/common.h"
#include "model/Doctype.h"

extern FILE* dtdin;
extern int dtdparse(Document **ddoc);
extern void dtdFlushBuffer();

class DtdParser
{
	public:
		static Doctype* parseStream(FILE *fd);
};

#endif
