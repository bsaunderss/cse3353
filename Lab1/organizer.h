//
//  usercatalog.hpp
//  Lab1
//
//  Created by Blair Saunders on 8/29/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef usercatalog_h
#define usercatalog_h

#include <stdio.h>
#include <string>
#include "algorithm.h"
#include "sortAlgo.h"

using namespace std;
class organizer
{
public:
    organizer();
    void addFilePaths (vector<string>&);//chooses the data sets to sort
    void addAlgoNames (vector<string>&);//chooses the algorithms to use
};


#endif /* usercatalog_h */
