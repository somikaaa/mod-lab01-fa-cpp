#include <iostream>
#include "fun.h"

int main() {

    const char* str1 = "Hello W0rld 123";
    const char* str2 = "Apple Banana tasty Cherry";
    const char* str3 = "This is a test string";

    std::cout << "Слова без цифр: " << faStr1(str1) << std::endl;
    std::cout << "Слова, начинающиеся на заглавную латинскую букву, а среди других символов этих слов только латинские строчные буквы: " << faStr2(str2) << std::endl;
    std::cout << "Средняя длина слов в строке: " << faStr3(str3) << std::endl;

    return 0;
}
