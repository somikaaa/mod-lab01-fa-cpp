#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>
#include "fun.h" 


bool isLatinLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Функция для определения, является ли символ цифрой
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Функция для подсчета слов, не содержащих цифр
unsigned int faStr1(const char* str) {
    unsigned int count = 0;
    bool inWord = false;

    while (*str) {
        if (isLatinLetter(*str)) {
            if (!inWord) {
                inWord = true;
            }
        }
        else if (isDigit(*str)) {
            inWord = false;
        }
        str++;
    }

    if (inWord) {
        count++;
    }

    return count;
}

// Функция для подсчета слов, начинающихся на заглавную латинскую букву и содержащих только строчные буквы
unsigned int faStr2(const char* str) {
    unsigned int count = 0;
    bool inWord = false;
    bool isCapital = false;

    while (*str) {
        if (isLatinLetter(*str)) {
            if (!inWord) {
                inWord = true;
                isCapital = (*str >= 'A' && *str <= 'Z');
            }
            else if (!isCapital && isLatinLetter(*str)) {
                isCapital = false;
            }
        }
        else {
            inWord = false;
        }
        str++;
    }

    if (inWord && isCapital) {
        count++;
    }

    return count;
}

// Функция для подсчета средней длины слова в строке, округляя до ближайшего целого числа
unsigned int faStr3(const char* str) {
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;

    while (*str) {
        if (isLatinLetter(*str)) {
            if (!wordCount) {
                wordCount++;
            }
            totalLength++;
        }
        else {
            wordCount = 0;
        }
        str++;
    }

    if (wordCount) {
        return totalLength / wordCount;
    }
    else {
        return 0;
    }
}
