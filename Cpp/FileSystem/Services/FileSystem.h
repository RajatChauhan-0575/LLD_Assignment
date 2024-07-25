#pragma once
#include "../Entities/Types.h"
#include "../Entities/EntryFactory.h"

using namespace std;

class FileSystem
{

    public:
        FileSystem(string& root): m_root(root)
        {
            m_rootEntry = factory.createEntry(m_root, Type::DIRECTORY);
        }

        vector<string> getNextWord(string& path);
        void mk(string path, Type type);
        void rm(string path);
        vector<string> ls(string path);
        bool mv(string src, string dest);
    
    private:
        EntryFactory factory;
        string m_root = "/";
        Entry* m_rootEntry = nullptr;
};