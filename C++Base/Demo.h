#pragma once
#include <iostream>
class Demo
{
public:
    void print(std::initializer_list<int> values) {
        for (const auto& itor : values){
            std::cout << (itor) << std::endl;
        }
        for (auto p = values.begin(); p != values.end(); ++p) {
            std::cout << (*p) << std::endl;
        }
    }
    void run() {
        print({ 1,2,3,5,3,4,5 });
        auto s = L"ÄãºÃ";
        std::cout <<s<<std::endl;
        for (auto itor : { 1,2,3,4,5,6 }) {
            std::cout << [](int it) { return it * it; }(itor) << std::endl;
        }
        short i = std::numeric_limits<short>::min();
        std::cout << i << std::endl;
    }

};

