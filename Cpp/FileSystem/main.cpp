#include "Services/FileSystem.cpp"
#include <iostream>

using namespace std;

void printVec(vector<string>& vec)
{
    for (auto val : vec)
    {
        cout << val << endl;
    }
}

int main()
{
    // Init
    string root = "/";
    FileSystem fs(root);

    // T1
    cout << "T1 : " << endl;
    fs.mk("/home", Type::DIRECTORY);
    fs.mk("/home/rajat", Type::DIRECTORY);
    fs.mk("/home/ayush", Type::DIRECTORY);
    fs.mk("/home/rc", Type::DIRECTORY);
    fs.mk("/home/rajat/demo", Type::FILE);

    auto res = fs.ls("/home");
    printVec(res);

    //T2
    cout << "T2 : " << endl;
    auto res2 = fs.ls("/home/rajat");
    printVec(res2);
    
    //T3 - Add more directories/files
    cout << "T3 : " << endl;
    fs.mk("/home/ayush/f1", Type::FILE);
    fs.mk("/home/ayush/f2", Type::FILE);
    fs.mk("/home/ayush/f4", Type::FILE);

    auto res3 = fs.ls("/home/ayush");
    printVec(res3);

    //T3 - Delete directory
    cout << "T4 : " << endl;
    fs.rm("/home/ayush");
    auto res4 = fs.ls("/home/ayush");
    printVec(res4);
    return 0;
}