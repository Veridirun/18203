// HeapSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <cstdlib>

void hsort(int* a, int length);
void buildTree(int* a, int rootIndex, int length);
void swap(int* a, int* b);
int makeMaxFirst(int* a, int index1, int index2);
int makeMaxFirst(int* a, int index1, int index2, int index3);

int main() {
	int length;
	scanf_s("%d /n", &length);
	int* a = (int*)malloc(4 * length);
	if (a) {
		for (int i = 0; i != length; i++) { scanf_s("%d", &a[i]); }

		if (length > 0) hsort(&a[0], length);

		for (int i = 0; i != length; i++) {
			printf_s("%d %c", a[i], ' ');
		}

		free(a);
		return(0);
	}
	else return -1;
}

void hsort(int* a, int length) {
	for (int i = length / 2 - 1; i != -1; i--) {		//первое построение дерева
		buildTree(a, i, length);
	}
	int itemp;
	for (int i = length - 1; i != 0; i--) {				// собст. сортировка
		swap(a, a + i);			//перемещение самого большого эл-та в конец массива
		buildTree(a, 0, i);		//корректировка дерева
	}
}

void buildTree(int* a, int rootIndex, int length) {	//построение дерева (для случая ,когда условие элемента
	if (2 * rootIndex + 1 < length) {				// дерева не выполняется только для коренного элемента)
		int changedIndex;

		if (2 * rootIndex + 2 < length) { changedIndex = makeMaxFirst(a, rootIndex, 2 * rootIndex + 1, 2 * rootIndex + 2); }
		else { changedIndex = makeMaxFirst(a, rootIndex, 2 * rootIndex + 1); }

		if (changedIndex) buildTree(a, changedIndex, length);		//рекурсивное построение изменённого выше "поддерева"
	}
}

void swap(int* a, int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int makeMaxFirst(int* a, int index1, int index2) {
	int changedIndex = 0;
	if (*(a + index1) < *(a + index2)) {
		swap(a + index1, a + index2);
		changedIndex = index2;
	}
	return changedIndex;
}

int makeMaxFirst(int* a, int index1, int index2, int index3) {
	int changedIndex = 0;
	if (*(a + index2) > *(a + index3)) {
		changedIndex = makeMaxFirst(a, index1, index2);
	}
	else {
		changedIndex = makeMaxFirst(a, index1, index3);
	}
	return changedIndex;
}
