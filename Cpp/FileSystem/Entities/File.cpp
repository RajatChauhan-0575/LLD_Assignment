#include "File.h"

bool File::setName(const string& name)
{
    this->name.assign(name);
    return true;
}

string File::getName() const
{
    return name;
}

Type File::getType() const 
{
    return Type::FILE;
}
    
bool File::addEntry(Entry* entry)
{
    return false;
}

bool File::deleteEntry(const string& name)
{
    return false;
}

vector<string> File::listEntity()
{
    vector<string> res;

    return res;
}

Entry* File::find(string name)
{
    return nullptr;
}