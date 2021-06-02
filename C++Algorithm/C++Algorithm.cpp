#include <iostream>
#include "Array.h"
#include "List.h"
#include "Hash.h"


void TestList() {
    ListTest test;
    test.run();
}
void TestHash() {
    HashTest test;
    test.run();
}
void TestAll() {
    //TestList();
    TestHash();
}
int main()
{
    TestAll();
}
