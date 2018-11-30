#ifndef usercatalog_hpp
#define usercatalog_hpp

#include <stdio.h>
#include <string>
//#include "algorithm.h"
//#include "sortAlgo.h"
//#include "tspAlgo.h"

using namespace std;
class organizer
{
public:
    organizer();
    void addFilePaths (vector<string>&);//chooses the data sets to sort
    void addAlgoNames (vector<string>&);//chooses the algorithms to use
    
};
#endif /* usercatalog_hpp */
