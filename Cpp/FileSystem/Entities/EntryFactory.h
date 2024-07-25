#pragma once
#include"Types.h"
#include"File.h"
#include"Dir.h"

using namespace std;

class EntryFactory
{
    public:

        EntryFactory()
        {

        }

        Entry* createEntry(string& name, Type type);
};