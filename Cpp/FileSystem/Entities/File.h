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

        bool setName(const string& name);
        string getName() const;
        Type getType() const;
        bool addEntry(Entry* entry);
        bool deleteEntry(const string& name);
        vector<string> listEntity();
        Entry* find(string name);

    private:
        string name;
};