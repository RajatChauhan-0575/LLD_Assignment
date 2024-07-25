#pragma once
#include "Entry.h"
#include <unordered_map>
#include "Dir.h"

bool Dir::setName(const string& name)
{
    this->name.assign(name);
    return true;
}

string Dir::getName() const
{
    return name;
}

Type Dir::getType() const 
{
    return Type::DIRECTORY;
}
    
bool Dir::addEntry(Entry* entry)
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

bool Dir::deleteEntry(const string& name)
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

vector<string> Dir::listEntity()
{
    vector<string> res;

    for (auto itr : childEntry)
    {
        res.push_back(itr.first);
    }

    return res;
}

Entry* Dir::find(string name)
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