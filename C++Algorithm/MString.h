#pragma once
#include <iostream>
#include <vector>
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
};

class MStringTest {
public:
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
        recerserStringTest();
    }
};