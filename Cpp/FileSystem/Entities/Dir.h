#pragma once
#include "Entry.h"
#include <unordered_map>

class Dir: public Entry
{
    public:
        Dir(const string& name)
        {
            this->name = name;
        }

        ~Dir()
        {
            for (auto itr : childEntry)
            {
                delete itr.second;
            }

            childEntry.clear();
        }

        bool setName(const string& name);
        string getName() const;
        Type getType() const;
        bool addEntry(Entry* entry);
        bool deleteEntry(const string& name);
        vector<string> listEntity();
        Entry* find(string name);

    private:
        string name;
        unordered_map<string, Entry*> childEntry;
};