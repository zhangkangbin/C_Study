#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//字符数组，最大，
#define MaxSize 3
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
    void printAllData();
};
bool ArrayList::addData(string elem)
{

    if (index >= MaxSize)
    {
        cout << "\n​The capacity of the list is full.\n";
        return false;
    }
    data[index] = elem;
    index++;

    return true;
}
string ArrayList::getData(int i)
{

    if (index <= i)
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
bool ArrayList::deleteData(string value)
{

    bool isFind = false;

    for (int i = 0; i < index; i++)
    {
        string temp = data[i];
        if (!isFind && temp.compare(value) == 0)
        {

            isFind = true;
            index--;
        }

        //判断下标防止越界。
        if (isFind && (i + 1) < MaxSize)
        {
            //数组下标后移
            data[i] = data[i + 1];
        }
    }
    if (isFind)
    {
        cout << "\n Data found ,deleted success\n";
    }
    else
    {
        cout << "\n not found value \n";
    }

    return isFind;
}

void ArrayList::printAllData()
{
    for (int i = 0; i < index; i++)
    {
        string temp = data[i];
        cout << "\n"
             << temp;
    }
}
int main()
{
    ArrayList list;
    list.addData("xue0");
    list.addData("xue1");
    list.addData("xue2");
    list.addData("xue3");

    list.findData("xue");

    // int length=list.getLength();

    // << list.getData(1) << "\n\n";
    cout << "\n"
         << list.getData(1);
    list.deleteData("xue");
    list.printAllData();
    //  cout << "\n"<< list.getData(2).length() << "\n";
    return 0;
}
