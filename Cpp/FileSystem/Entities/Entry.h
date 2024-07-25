#pragma once
#include <string>
#include <vector>
#include "Types.h"

using namespace std;

class Entry
{
    public:
        virtual bool setName(const string&) = 0;
        virtual string getName() const = 0;
        virtual Type getType() const = 0;
    
        virtual bool addEntry(Entry*) = 0;
        virtual bool deleteEntry(const string& ) = 0;
        virtual vector<string> listEntity() = 0;
        virtual Entry* find(string name) = 0;
};