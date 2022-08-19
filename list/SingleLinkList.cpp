#include <stdio.h>
#include <iostream>
using namespace std;

class Node
{

public:
    string dataNode;
    Node *dataPre;//双链表
    Node *datanext;
};

class SingleLinkList
{

private:
    string data;
    Node *head = NULL;
    Node *mLastNext;

public:
    string getData(string value);
    bool addData(string data);
    bool deleteData(string data);
    void printAllData();
};

void SingleLinkList::printAllData()
{

    Node *tempNext = head;
    while (tempNext != NULL)
    {
        if (tempNext->dataPre != NULL)
        {
            cout << "" << tempNext->dataPre->dataNode;
        }

        cout << "_:" << tempNext->dataNode;

        if (tempNext->datanext != NULL)
        {
            cout << "_" << tempNext->datanext->dataNode << "\n";
        }

        tempNext = tempNext->datanext;
    }
}

bool SingleLinkList::addData(string value)
{

    Node *tempNode = new Node();

    tempNode->dataNode = value;
    if (head == NULL)
    {
        tempNode->dataPre = NULL;
        head = tempNode;
        // mLastNext = head;
    }
    else
    {
        tempNode->dataPre = mLastNext;
        mLastNext->datanext = tempNode;
    }
    mLastNext = tempNode;
    return true;
}
string SingleLinkList::getData(string value)
{

    Node *tempData = head;

    while (tempData != NULL)
    {

        if (tempData->dataNode.compare(value) == 0)
        {

            return tempData->dataNode;
        }

        tempData = tempData->datanext;
    }

    return "";
}

bool SingleLinkList::deleteData(string value)
{

    Node *tempData = head;

    while (tempData != NULL)
    {

        if (tempData->dataNode.compare(value) == 0)
        {
            //等于空是父节点。
            if (tempData->dataPre != NULL)
            {
                //把父节点的next改成
                tempData->dataPre->datanext = tempData->datanext;
            }
            else
            {
                //把头节点给下个。
                head = tempData->datanext;
            }
            if (tempData->datanext != NULL)
            {

                tempData->datanext->dataPre = tempData->dataPre;
            }

            tempData = NULL; //删除节点.
            free(tempData);
            cout << "\ndelete success!\n";
            return true;
        }

        tempData = tempData->datanext;
    }
    cout << "\ndelete fail!\n";
    return false;
}

int main()
{

    SingleLinkList list;

    list.addData("1");
    list.addData("2");
    list.addData("3");
    list.addData("4");
    list.deleteData("1");

    list.printAllData();

    return 0;
}