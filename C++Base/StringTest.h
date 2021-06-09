#pragma once
#include <iostream>
#include <string>
using std::string;

class StringTest
{
public:
    void test() {
        string str1 = "hello", str2 = "base.bat", str3 = "extern.", str4 = "tmpname.tmp";
        string::size_type idx = str1.find('.');
        const char * temp = "123456";
        if (idx == string::npos) {//string::npos表示为size_type的最大值，用来表示不存在的量
            str1 += ".tmp\0";
            std::cout << str1 << std::endl;
            std::cout << str1.size() << std::endl;
            auto str = str1.append(temp);
            str.clear();
            std::cout << &str1 << " " << &str << " " << str1<< " " << str << std::endl;
        }
    }
};

