//
//  usercatalog.h
//  Lab1
//
//  Created by Blair Saunders on 8/29/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef usercatalog_hpp
#define usercatalog_hpp

#include <stdio.h>
#include <string>
#include "algorithm.h"
#include "sortAlgo.h"
#include "searchAlgo.h"

using namespace std;
class organizer
{
public:
    organizer();
    void addFilePaths (vector<string>&);//chooses the data sets to sort
    void addAlgoNames (vector<string>&);//chooses the algorithms to use
    void addStructures(vector<string>&);
};


#endif /* usercatalog_hpp */
