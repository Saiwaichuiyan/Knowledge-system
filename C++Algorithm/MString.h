#pragma once
#include <iostream>
#include <vector>
#include <string>
using std::vector;
class MString
{
public:

    void reverseString(vector<char>& s) {
        int i = 0;
        while (i < s.size() / 2) {
            std::swap(s[i], s[s.size() - 1 - i]);
            i++;
        }
    }
    void reverserStringChar(vector<char>& s) {
        char r = s.size();
        int i = 0;
        while (i < s.size() / 2) {
            s[i] += s[r - 1 - i];
            s[r - 1 - i] = s[i] - s[r - 1 - i];
            s[i] = s[i] - s[r - 1 - i];
            i++;
        }
    }
    std::string reverseStr(std::string s, int k) {

        if (s.size() < k) {
            s.reserve(s.size());
            return s;

        }
        std::string str;

        for (int i = 0; i < s.size() / 2 * k; i += 2 * k) {
            for (int j = i + k; j > i; j--) {
                str += s[j];
            }
            for (int j = i + k + 1; j < 2 * k; j++) {
                str += s[j];
            }
        }
        if (s.size() % (2 * k) < k){
            
        }

        return std::string(str.data(),s.size());
    }
    /*
    ��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
    ʾ�� 1��
        ���룺s = "We are happy."
        �����"We%20are%20happy."
    */
    std::string replaceSpace(std::string s) {
        //ͳ�ƿո����
        
        int first = s.size() - 1;
        int index = 0;
        for (auto itor : s) {
            if (itor == ' ') index++;
        }
        s.resize(s.size() + 2 * index);
        int sencond = s.size() - 1;
        for (; first >= 0; --first, --sencond) {
            if (s[first] == ' ') {
                s[sencond--] = '0';
                s[sencond--] = '2';
                s[sencond] = '%';
                
            }
            else {
                s[sencond] = s[first];
            }
        }
        return s;
    }

    /*����һ���ַ��� s �������ת�ַ����е����� ���� ��

        ���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����

        ���㷵��һ����ת s �е���˳���õ����ո��������ַ�����

        ˵����

        �����ַ��� s ������ǰ�桢������ߵ��ʼ��������Ŀո�
        ��ת�󵥴ʼ�Ӧ������һ���ո�ָ���
        ��ת����ַ����в�Ӧ��������Ŀո�*/
    std::string reverseWords(std::string s) {
        std::string str;
        int index = s.size() - 1;
        int first, second;
        while (index >= 0) {

            while (index >= 0 && s[index] == ' ') index--;//����β
            first = index; // ������
            while (index >= 0 && s[index] != ' ') index--;//����ͷ
            second = index + 1;//ǰ����
            if (second <= first) {
                str.append(&s[second], &s[first+1]);
                str += ' ';
            }
        }

        if (str.back() == ' ') str.pop_back();
        return str;
    }
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() == 0) return 0;
        int first = 0, second = 0;
        int index = 0;
        while (index < haystack.size()) {
            if (haystack[index] == needle[0]) {
                while (first < needle.size()) {
                    if (haystack[index] == needle[first]) {
                        index++;
                        first++;
                    }
                    else {
                        break;
                    }  
                }
                if (first == needle.size()) return index - needle.size();
            }
        }
        return -1;
    }
    bool get() {
        std::string str = "aacaaaaaaaa";
        //˫ָ�뷨
        int first = 0, second = 0;
        std::string temp{str[0]};
        if (str.size() <= 1) return false;
        for ( ; ; ) {
            
           
        }
    }
};

class MStringTest {
public:
    void strStrTest() {
        std::string str = "hello",str1 = "ll";
        MString s;
       // int result = s.strStr(str, str1);
       // std::cout << result << std::endl;
        std::cout << s.get()<<std::endl;
    }
    void recerseWordsTest() {
        std::string str = "     hello world  ";
        MString s;
        std::string result = s.reverseWords(str);
        std::cout <<"\""<< result<<"\"" << std::endl;
    }
    void replaceSpaceTest() {
        std::string str = "   ";
        
        MString s;
        auto result = s.replaceSpace(str);
        std::cout << result << std::endl;
    }
    void recerserStringTest() {
        vector<char> str{ 'a','b','c','d','e','f','g' };
        std::string sc = "abcdefg";
        MString s;
        auto ss = s.reverseStr(sc,3);
        for (auto itor : ss) {
            std::cout << itor <<" ";
        }
        std::cout << std::endl;
    }
    void run() {
        strStrTest();
        //recerseWordsTest();
        //replaceSpaceTest();
        //recerserStringTest();
    }
};