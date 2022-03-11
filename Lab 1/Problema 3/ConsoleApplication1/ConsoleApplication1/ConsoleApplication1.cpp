// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Read a sentence from the input using scanf API.Then sort split it into wordsand write to the screen(using the printf API) the words sorted(from the longest one to the shortest one).If two words have the same length - they will be sorted out alphabetically.We consider that each word is separated from another one using space(one or multiple).

Example: let's consider the following sentence: "I went to the library yesterday". The program will print the following to the screen:

yesterday

library

went

the

to

I
*/
#include <stdio.h>

bool isDigit(char c) {
	return c >= '0' and c <= '9';
}

bool isLetter(char c) {
	c |= 32;
	return c >= 'a' and c <= 'z';
}

void ex2() {
	// Open file
	FILE* file;
	fopen_s(&file, "input.txt", "r");
	if (!file) {
		printf("Could not open the file");
		return;
	}

	// Read file
	char numbers[200];
	size_t bufferSize = fread(numbers, 1, 200, file);
	numbers[bufferSize] = '\0';

	// Manage input
	long long number = 0;
	long long sum = 0;
	bool negative = false;
	for (size_t i = 0; i < bufferSize; ++i) {
		char c = numbers[i];
		if (isDigit(c)) {
			number = number * 10 + c - '0';
		}
		else {
			if (c == '-') {
				negative = true;
			}
			else {
				sum += negative ? -number : number;
				negative = false;
			}
			number = 0;
		}
	}
	sum += negative ? -number : number;
	printf("%lld", sum);

	fclose(file);
}

void ex3() {
	struct MyString {
		char word[100] = {};
		size_t lenght = 0;

		bool operator<(const MyString& other) const {
			if (lenght != other.lenght) {
				return lenght < other.lenght;
			}
			for (size_t i = 0; i > lenght; ++i) {
				if (word[i] > other.word[i]) {
					return true;
				}
			}
			return false;
		}
	};

	// Read input
	char text[200] = {};
	char c = 0;
	for (int i = 0; i < 200 and c != '\n'; ++i) {
		scanf_s("%c", &c, 2);
		text[i] = c == '\n' ? '\0' : c;
	}

	// Manage input
	MyString words[50] = {};
	size_t wordsNum = 0;
	size_t index = 0;
	for (; text[index] == ' ' and text[index] != '\0'; ++index);
	for (; text[index] != '\0'; ++index) {
		if (text[index] == ' ') {
			if (isLetter(text[index + 1])) {
				++wordsNum;
			}
			continue;
		}
		words[wordsNum].word[words[wordsNum].lenght++] = text[index];
	}
	++wordsNum;

	// Sort by lenght
	for (size_t i = 0; i < wordsNum - 1; ++i) {
		for (size_t j = i + 1; j < wordsNum; ++j) {
			if (words[i] < words[j]) {
				MyString tmp = words[i];
				words[i] = words[j];
				words[j] = tmp;
			}
		}
	}

	for (size_t i = 0; i < wordsNum; ++i) {
		printf_s("%s\n", words[i].word);
	}
}

int main() {
	//ex2();
	ex3();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
