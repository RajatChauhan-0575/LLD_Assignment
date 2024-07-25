#include "Entry.h"

class File: public Entry
{
    public:
        File(string& name)
        {
            this->name = name;
        }

        ~File()
        {

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
            return Type::FILE;
        }
    
        bool addEntry(Entry* entry)
        {
            return false;
        }

        bool deleteEntry(const string& name)
        {
            return false;
        }

        vector<string> listEntity()
        {
            vector<string> res;

            return res;
        }

        Entry* find(string name)
        {
            return nullptr;
        }

    private:
        string name;
};