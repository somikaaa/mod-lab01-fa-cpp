// Copyright 2022 UNN UNN-IASR
#include "fun.h"
#include <sstream>
#include <cctype>
#include <string>

unsigned int faStr1(const char* str) {
    unsigned int wordCount = 0;
    bool isWord = false;

    // Перемещаемся к началу строки, чтобы начать обход с первого символа
    const char* currentChar = str;

    while (*currentChar) {
        // Если текущий символ не является 
        //цифрой и не пробелом, начинаем новое слово
        if (!std::isdigit(*currentChar) && !std::isspace(*currentChar)) {
            isWord = true;
        }
        // Если текущий символ является пробелом
        //и мы находимся внутри слова, увеличиваем счетчик слов
        else if (std::isspace(*currentChar) && isWord) {
            wordCount++;
            isWord = false;
        }
        // Если текущий символ является цифрой, сбрасываем флаг 
        //isWord и пропускаем все цифры до следующего пробела или конца строки
        else if (std::isdigit(*currentChar)) {
            isWord = false;
            while (*currentChar && !std::isspace(*currentChar)) {
                currentChar++;
            }
        }

        currentChar++;
    }

    // Увеличиваем счетчик слов, если последнее слово не было учтено
    if (isWord) {
        wordCount++;
    }

    return wordCount;
}

unsigned int faStr2(const char* str) {
    unsigned int count = 0;
    std::istringstream iss(str);
    std::string word;

    while (iss >> word) {
        if (!word.empty() && isupper(word[0])) {
            bool valid = true;
            for (size_t i = 1; i < word.length(); i++) {
                if (!islower(word[i]) && !isspace(word[i])) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                count++;
            }
        }
    }

    return count;
}

unsigned int faStr3(const char* str) {
    unsigned int wordCount = 0;
    unsigned int totalLength = 0;
    std::istringstream iss(str);
    std::string word;

    while (iss >> word) {
        wordCount++;
        totalLength += word.length();
    }

    return wordCount == 0 ? 0 : totalLength / wordCount;
}
