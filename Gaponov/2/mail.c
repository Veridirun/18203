#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 11
void Swap(char*, int, int);
int Permutation(char*, int);
void checkInput(char*);

int main()
{
	int permAmount;
	char Input[MAX_LENGTH];
	scanf("%s%d", Input, &permAmount);
	checkInput(Input);

	while (Permutation(Input, strlen(Input)) && permAmount--)
		printf("%s\n", Input);

	return 0;
}

void Swap(char* x, int i, int a) {
	int t = x[i];
	x[i] = x[a];
	x[a] = t;
}

void checkInput(char* Input) {
	int a[10] = { 0 };
	for (int i = 0; Input[i] != '\0'; ++i) {
		int num = Input[i] - '0';
		if (num > 9 || num < 0 || a[num]) {
			printf("bad input");
			exit;
		}
		++(a[num]);
	}
}

int Permutation(char* Input, int strlen) {
	int i = strlen - 1;
	for (;i > 0 && Input[i - 1] >= Input[i];i--)
		;
	if (!i)
		return 0;
	int j = strlen - 1;
	while (Input[j] <= Input[i - 1])
		j--;
	Swap(Input, i - 1, j);
	j = strlen - 1;
	while (i++ < j--)
		Swap(Input, i, j);
	return 1;
}
