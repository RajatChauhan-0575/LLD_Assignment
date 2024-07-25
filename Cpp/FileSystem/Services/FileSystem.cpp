#pragma once
#include "../Entities/Types.h"
// #include "../Entities/Entry.h"
#include "../Entities/EntryFactory.cpp"

using namespace std;

class FileSystem
{

    public:
        FileSystem(string& root): m_root(root)
        {
            m_rootEntry = factory.createEntry(m_root, Type::DIRECTORY);
        }

        vector<string> getNextWord(string& path)
        {
            int len = path.length();
            size_t pos = 0;
            vector<string> res;
    
            while(pos < len)
            {
                size_t tpos = path.find("/", pos + 1);

                if (tpos != string::npos)
                {
                    int tlen = tpos - pos - 1;
                    string tmp = path.substr(pos + 1, tlen);
                    res.emplace_back(tmp);

                    pos = tpos;
                }
                else
                {
                    int tlen = len - pos - 1;
                    string tmp = path.substr(pos + 1, tlen);
                    res.emplace_back(tmp);

                    pos = len;
                }
            }

            return res;
        }

        void mk(string path, Type type)
        {
            vector<string> pathTok = getNextWord(path);
            Entry* itr = m_rootEntry;
            int sz = pathTok.size();

            for (int i = 0; i < sz; i++)
            {
                Entry* next = itr->find(pathTok[i]);

                if (next == nullptr)
                {
                    if (type == Type::DIRECTORY)
                    {
                        Dir* dir = new Dir(pathTok[i]);
                        itr->addEntry(dir);

                        next = dir;
                    }
                    else if (type == Type::FILE)
                    {
                        File* file = new File(pathTok[i]);
                        itr->addEntry(file);

                        next = file;  
                    }
                }

                itr = next;
            }
        }

        void rm(string path)
        {
            vector<string> pathTok = getNextWord(path);
            Entry* itr = m_rootEntry;
            int sz = pathTok.size();

            for (int i = 0; i < sz - 1; i++)
            {
                Entry* next = itr->find(pathTok[i]);

                if (next == nullptr)
                {
                    return;
                }

                itr = next;
            }

            itr->deleteEntry(pathTok[sz-1]);
        }

        vector<string> ls(string path)
        {
            vector<string> res;
            vector<string> pathTok = getNextWord(path);
            Entry* itr = m_rootEntry;
            int sz = pathTok.size();

            for (int i = 0; i < sz; i++)
            {
                Entry* next = itr->find(pathTok[i]);

                if (next == nullptr)
                {
                    return res;
                }

                itr = next;
            }

            return itr->listEntity();
        }

        bool mv(string src, string dest)
        {
            return true;
        }
    
    private:
        EntryFactory factory;
        string m_root = "/";
        Entry* m_rootEntry = nullptr;
};