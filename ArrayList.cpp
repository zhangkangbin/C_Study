#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//字符数组，最大，
#define MaxSize 4
class ArrayList
{
private:
    // int length = 0;
    int index = 0; //数组下标
    string data[MaxSize];

public:
    bool addData(string data);
    string getData(int dext);
    string findData(string value);
    int getLength() const;
    bool deleteData(string data);
};
bool ArrayList::addData(string elem)
{

    if (index >= MaxSize)
    {
        cout << "​The capacity of the list is full.";
        return false;
    }
    data[index] = elem;
    index++;

    return true;
}
string ArrayList::getData(int i)
{

    if ((index - 1) < i)
    {
        // cout << "下標不合法";
        return "index不合法";
    }

    return data[i];
}

string ArrayList::findData(string value)
{

    for (int i = 0; i < index; i++)
    {
        string temp = data[i];
        cout << "\n\n";
        if (temp.compare(value) == 0)
        {
         cout << "\n Data found \n";
            return temp;
        }
    }
    cout << "\n not found value \n";
    return "not found";
}

int ArrayList::getLength() const
{

    return index;
}

int main()
{
    ArrayList list;
    list.addData("kang");
    list.addData("1tong");
    list.addData("xue");
    list.addData("xue2");

    list.findData("xue");

    // int length=list.getLength();

    // << list.getData(1) << "\n\n";
    cout << "\n\n"
         << list.getData(2).length() << "\n\n";
    return 0;
}
