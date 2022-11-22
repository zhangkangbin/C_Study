/*
 * @Author: zhangkangbin
 * @Date: 2022-09-22 14:25:44
 * @LastEditors: zhangkangbin
 * @LastEditTime: 2022-11-21 15:23:10
 * @FilePath: \C_Study\chapter9_file\FileOperate.cpp
 * 文件操作相关的类
 */
#include <fstream>
#include <stdio.h>
#include <iostream>
using namespace std;
#include <string>

/**
数据类型	描述
ofstream	该数据类型表示输出文件流，用于创建文件并向文件写入信息。
ifstream	该数据类型表示输入文件流，用于从文件读取信息。
fstream	    该数据类型通常表示文件流，且同时具有 ofstream 和 ifstream 两种功能，
            这意味着它可以创建文件，向文件写入信息，从文件读取信息。
 * 
 */

/**
 *
模式标志	 描述
ios::app	追加模式。所有写入都追加到文件末尾。
ios::ate	文件打开后定位到文件末尾。
ios::in	    打开文件用于读取。
ios::out	打开文件用于写入。
ios::trunc	如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。
 *
 */
void writeData()
{
    // 以写模式打开文件
    ofstream outfile;

    //ios::app	追加模式。所有写入都追加到文件末尾。
    //如果文件不存在，会自动新建一个文件。
    outfile.open("test2.txt", ios::app);

    // string data = "i am data:"+to_string(number);
    string data = "在结尾写入一条数据";

    outfile << data << endl;
    // 关闭打开的文件
    outfile.close();
}

/**
 * @brief 读出所有数据。
 *
 */
void readAllData()
{

    // 以读模式打开文件
    ifstream infile;
    infile.open("test.txt");

    string numberStr = "test";
    infile >> numberStr;
    int number = atoi(numberStr.c_str());
    number++;

    cout << "-------------" << number << endl;
    char buf[1024] = {0};
    while (infile.getline(buf, sizeof(buf)))
    {
        cout << buf << endl;
    }

    // cout << "读出数据:" << readData << endl;
    infile.close();
}
int main()
{
   writeData();
   // openFile();
    /* code */
    return 0;
}
