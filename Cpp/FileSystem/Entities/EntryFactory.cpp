#pragma once
#include "EntryFactory.h"

using namespace std;

Entry* EntryFactory::createEntry(string& name, Type type)
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
