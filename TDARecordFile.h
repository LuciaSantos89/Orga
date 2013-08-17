#ifndef TDARECORDFILE
#define TDARECORDFILE value

#include "Campo.h"
#include "TDAFile.h"
#include <string>



class TDARecordFile:public TDAFile
{
public:
	TDARecordFile();
	~TDARecordFile();

	bool addRecord(Campo*, string*);
	string* searchRecord();
	bool deleteRecord(int);
	string* listRecord();
	/* data */
};
#endif
