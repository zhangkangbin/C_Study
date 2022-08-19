#include <stdio.h>
#include <iostream>
using namespace std;

class Node
{

public:
    string dataNode;
    Node *datanext;
};

class SingleLinkList
{

private:
    string data;
    Node *head = NULL;
    Node *mLastNext;

public:
    string getData();
    bool addData(string data);
    void printAllData();
};

void SingleLinkList::printAllData()
{

    Node *tempNext = head;
    while (tempNext != NULL)
    {

        cout << "data:" << tempNext->dataNode << "\n";

        tempNext = tempNext->datanext;
    }
}

bool SingleLinkList::addData(string value)
{

    Node *tempNode = new Node();
    tempNode->dataNode = value;
    if (head == NULL)
    {
        head = tempNode;
       // mLastNext = head;
    }
    else
    {

        mLastNext->datanext = tempNode;
    
    }
    mLastNext = tempNode;
    return true;
}
string SingleLinkList::getData()
{

    return "1222";
}

int main()
{

    SingleLinkList list;

    list.addData("1");
    list.addData("22");
    list.addData("333");
    list.addData("4444");
    list.printAllData();

    return 0;
}