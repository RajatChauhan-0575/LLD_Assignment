#pragma once
// #include"Entry.h"
#include"Types.h"
#include"File.cpp"
#include"Dir.cpp"

using namespace std;

class EntryFactory
{
    public: 
        EntryFactory()
        {

        }

        Entry* createEntry(string& name, Type type)
        {
            if (type == Type::FILE)
            {
                return new File(name);
            }
            else if (type == Type::DIRECTORY)
            {
                return new Dir(name);
            }
            else
            {
                return nullptr;
            }
        }
};