#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>
#include "fun.h" 


//ф-я подсчета слов без цифр
unsigned int faStr1(const char* str){
	unsigned int counter = 0;

	bool inWord = false;//в слове
	bool hasDigit = false;//является цифрой

	for (int i = 0; str[i] != '\0'; i++) {
		//проверка, является ли текущий символ пробелом
		if (std::isspace(str[i])) {
			//если находимся внутри слова и не обнаружили цифры, увеличиваем counter
			if (inWord && !hasDigit)
			{
				counter++;
			}
			inWord = false;
			hasDigit = false;
		} else {
			if (std::isdigit(str[i])) {
				hasDigit = true;
			}
			inWord = true;
		}
		
	}
	// Проверяем последнее слово, если оно не содержит цифр
	if (inWord && !hasDigit) {
		counter++;
	}

	return counter;
}

/*int main() {
    const char* input = "Пример строки с 123 цифрами и словами без цифр";
    unsigned int count = faStr1(input);
    std::cout << "Количество слов без цифр: " << count << std::endl;

    return 0;
}*/



// Функция для подсчета слов, начинающихся на заглавную латинскую букву и содержащих только латинские строчные буквы
unsigned int faStr2(const char* str) {
	unsigned int count = 0;
	bool inWord = false;
	bool startsWithCapital = false;
	bool hasNonLowercase = false;

	for (int i = 0; str[i] != '\0'; ++i) {
		// Проверяем, является ли текущий символ пробелом
		if (std::isspace(str[i])) {
			// Если мы находимся внутри слова и оно начинается с заглавной буквы и содержит только строчные буквы
			if (inWord && startsWithCapital && !hasNonLowercase) {
				count++;
			}
			inWord = false;
			startsWithCapital = false;
			hasNonLowercase = false;
		}
		else {
			// Проверяем, является ли текущий символ заглавной буквой
			if (std::isupper(str[i])) {
				startsWithCapital = true;
			}
			else if (std::islower(str[i])) {
				// Проверяем, является ли текущий символ строчной буквой
				// Если нет, устанавливаем флаг на наличие не строчных букв
				if (!startsWithCapital) {
					hasNonLowercase = true;
				}
			}
			else {
				// Если символ не буква, сбрасываем флаги
				startsWithCapital = false;
				hasNonLowercase = false;
			}
			inWord = true;
		}
	}

	// Проверяем последнее слово, если оно соответствует условиям
	if (inWord && startsWithCapital && !hasNonLowercase) {
		count++;
	}

	return count;
}
/*int main() {
    const char* input = "Пример строки с Word и word, но не с Word1 или word1";
    unsigned int count = faStr2(input);
    std::cout << "Количество слов, соответствующих условиям: " << count << std::endl;

    return 0;
}*/



// Функция для подсчета средней длины слова в строке
unsigned int faStr3(const char* str) {
	unsigned int totalLength = 0;
	unsigned int wordCount = 0;
	bool inWord = false;

	for (int i = 0; str[i] != '\0'; ++i) {
		// Проверяем, является ли текущий символ пробелом
		if (std::isspace(str[i])) {
			inWord = false;
		}
		else {
			if (!inWord) {
				inWord = true;
				wordCount++;
			}
			totalLength++;
		}
	}

	// Проверяем последнее слово, если оно не закончилось пробелом
	if (inWord) {
		wordCount++;
	}

	// Если слов нет, возвращаем 0
	if (wordCount == 0) {
		return 0;
	}

	// Вычисляем среднюю длину слова, округляя до целого значения
	unsigned int averageLength = static_cast<unsigned int>(totalLength / wordCount);
	return averageLength;
}
 /*int main() {
    const char* input = "Пример строки с разными длинами слов";
    unsigned int averageLength = faStr3(input);
    std::cout << "Средняя длина слова: " << averageLength << std::endl;

    return 0;
}*/
