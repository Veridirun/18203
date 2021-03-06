#include <stdio.h>

const int MAX_NUMBER_LENGTH = 10;

int readStrAndAmount(char* s, int* amount);
int isGoodInput(char* s, int numberLength);
void showNextPermutations(char* s, int stringLength, int amount);
int postfixLength(char* s, int stringLength);
void permutate(char* s, int postfixLength);
void swap(char* a, char* b);
void writeString(char* s, int amountOfSymbols);
void invertStr(char* s, int length);

int main() {
	char s[MAX_NUMBER_LENGTH] = "";
	int amount;
	int numberLength = readStrAndAmount(s, &amount);
	if (!numberLength) {
		printf_s("bad input");
		return -1;
	}

	if (isGoodInput(s, numberLength)) {
		showNextPermutations(s, numberLength, amount);
	}
	else
		printf_s("bad input");

	return 0;
}

int readStrAndAmount(char* s, int* amount) {
	int length;
	for (length = 0; length != MAX_NUMBER_LENGTH; length++) {
		scanf_s("%c", s + length);
		if (s[length] == '\n') break;
		s[length] -= '0';
	}
	invertStr(s, length);
	scanf_s("%d", amount);
	return length;
}

int isGoodInput(char* s, int numberLength) {
	int numbersExist[MAX_NUMBER_LENGTH];
	for (int i = 0; i != MAX_NUMBER_LENGTH; i++)
		numbersExist[i] = 0;
	for (int i = 0; i != numberLength; i++) {
		if (s[i] < 0 || s[i]>9) {
			return 0;
		}else
			numbersExist[s[i]]++;
	}
	for (int i = 0; i != MAX_NUMBER_LENGTH; i++)
		if (numbersExist[i] > 1) return 0;

	return 1;
}

void showNextPermutations(char* s, int stringLength, int amount) {
	int currentPostfixLength;
	for (int i = 0; i != amount; i++) {
		currentPostfixLength = postfixLength(s, stringLength);
		if (currentPostfixLength == stringLength) break;
		permutate(s, currentPostfixLength);
		writeString(s, stringLength);
	}
}

int postfixLength(char* s, int stringLength) {
	int length = stringLength;
	for (int i = 1; i != stringLength; i++)
		if (s[i] < s[i - 1]) {
			length = i;
			break;
		}
	return length;
}

void permutate(char* s, int postfixLength) {
	for (int i = 0; i != postfixLength; i++)
		if (s[i] > s[postfixLength]) {
			swap(&s[i], &s[postfixLength]);
			break;
		}
	for (int i = 0; i != postfixLength / 2; i++)
		swap(&s[i], &s[postfixLength - i - 1]);
}

void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void writeString(char* s, int amountOfSymbols) {
	for (int i = 0; i != amountOfSymbols; i++)
		printf_s("%d",s[amountOfSymbols - i - 1]);
	printf_s("\n");
}

void invertStr(char* s, int length) {
	for (int i = 0; i != length / 2; i++)
		swap(s + i, s + length - 1 - i);
}