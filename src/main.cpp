#include <iostream>
#include "fun.h"

int main() {

    const char* str1 = "qwe4  gftt e 555gr rrgr  grhh ";
    const char* str2 = "  qwe4 ";

    const char* str3 = "Hello, world!";
    const char* str4 = "Hello world!";

    const char* str5 = " bad dog ";
    const char* str6 = " six monkeys";


    std::cout << "FA1: " << faStr1(str1) << std::endl;
    std::cout << "FA1: " << faStr1(str2) << std::endl;

    std::cout << "FA2: " << faStr2(str3) << std::endl;
    std::cout << "FA2: " << faStr2(str4) << std::endl;

    std::cout << "FA3: " << faStr3(str5) << std::endl;
    std::cout << "FA3: " << faStr3(str6) << std::endl;

    return 0;
}
