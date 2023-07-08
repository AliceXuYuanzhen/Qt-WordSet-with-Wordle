#ifndef MYFILE_H
#define MYFILE_H

#include "cardset.h"

class MyFile
{
public:
    MyFile();
    // 存储
    static void WriteFile(CardSet * cs);
    // 读取
    static CardSet * ReadFile();
    //文件的路径
    static QString filePath;
};

#endif // MYFILE_H
