#pragma once
#pragma optimize("", off)
#include "FileSystem.h"

using namespace std;

vector<string> FileSystem::getNextWord(string& path)
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

void FileSystem::mk(string path, Type type)
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

void FileSystem::rm(string path)
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

vector<string> FileSystem::ls(string path)
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

bool FileSystem::mv(string src, string dest)
{
    vector<string> pathTok = getNextWord(src);
    Entry* sitr = m_rootEntry;
    int sz = pathTok.size();

    for (int i = 0; i < sz - 1; i++)
    {
        Entry* next = sitr->find(pathTok[i]);

        if (next == nullptr)
        {
            return false;
        }

        sitr = next;
    }

    vector<string> pathTokd = getNextWord(dest);
    Entry* ditr = m_rootEntry;
    int sz1 = pathTokd.size();

    for (int i = 0; i < sz1; i++)
    {
        Entry* next = sitr->find(pathTokd[i]);

        if (next == nullptr)
        {
            return false;
        }

        ditr = next;
    }

    ditr->addEntry(sitr);
    sitr = nullptr;

    return true;
}