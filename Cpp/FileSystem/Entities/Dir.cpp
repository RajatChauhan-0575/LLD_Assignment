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

        bool setName(const string& name)
        {
            this->name.assign(name);
            return true;
        }

        string getName() const
        {
            return name;
        }

        Type getType() const 
        {
            return Type::DIRECTORY;
        }
    
        bool addEntry(Entry* entry)
        {
            if (entry && childEntry.find(entry->getName()) == childEntry.end())
            {
                childEntry[entry->getName()] = entry;
                return true;
            }
            else
            {
                return false;
            }
        }

        bool deleteEntry(const string& name)
        {
            auto itr = childEntry.find(name);

            if (itr != childEntry.end())
            {
                childEntry.erase(itr);
                return true;
            }
            else
            {
                return false;
            }
        }

        vector<string> listEntity()
        {
            vector<string> res;

            for (auto itr : childEntry)
            {
                res.push_back(itr.first);
            }

            return res;
        }

        Entry* find(string name)
        {
            auto itr = childEntry.find(name);

            if (itr != childEntry.end())
            {
                return itr->second;
            }
            else
            {
                return nullptr;
            }
        }

    private:
        string name;
        unordered_map<string, Entry*> childEntry;
};