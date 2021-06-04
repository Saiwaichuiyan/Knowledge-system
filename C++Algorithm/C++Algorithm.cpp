#include <iostream>
#include "Array.h"
#include "List.h"
#include "Hash.h"
#include "MString.h"

void TestList() {
    ListTest test;
    test.run();
}
void TestHash() {
    HashTest test;
    test.run();
}

void TestMyString(){
    MStringTest test;
    test.run();
}
void TestAll() {
    //TestList();
    //TestHash();
    TestMyString();
}
int main()
{
    TestAll();
}
