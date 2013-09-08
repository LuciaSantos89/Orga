#ifndef TDARECORDFILE
#define TDARECORDFILE value

#include "Campo.h"
#include "TDAFile.h"
#include <string>
#include <vector>



class TDARecordFile:public TDAFile
{
public:
	TDARecordFile();
	~TDARecordFile();

    bool addRecord(vector <Campo*>,vector<string>);
	string* searchRecord();
	bool deleteRecord(int);
	string* listRecord();
	/* data */
};
#endif
