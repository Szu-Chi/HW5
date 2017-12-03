#include <stdio.h>
#include <stdlib.h>

void printArray(int *array) {
	int n = 0;
	while (array[n] != NULL) n++;
	for (int i = 0; i < n; i++) {
		if (!(i % 5)) printf("\n");
		printf("array[%2d] = %3d \t", i, array[i]);
	}
	printf("\n");
}

int cmpfunc(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

int BinarySearch(int value, int *array, int start, int end) {
	int index = (start + end) / 2;
	if (start == end)return (value == array[index]) ? index : -1;
	printf("BinarySearch �� index = %d\n", index);
	if (value == array[index]) return index;
	else if (value > array[index]) return BinarySearch(value, array, index + 1, end);
	else if (value < array[index]) return BinarySearch(value, array, start, (index > 0)?index - 1:index);
}

int main() {
	int *array, size;
	srand(time(NULL));
	printf("��J�}�C�j�p: ");
	scanf_s("%d",&size);
	array = calloc(size,sizeof(int));
	*(array + size) = NULL;
	for (int i = 0; i < size; i++)
		array[i] = rand() % 500;
	printf("\n�}�C��(��l)");
	printArray(array);

	qsort( array, size, sizeof(int), cmpfunc );

	printf("\n�}�C��(�H�Ƨ�)");
	printArray(array);

	printf("�n��M����: ");
	int value, index;
	scanf_s("%d",&value);
	index = BinarySearch(value, array, 0, size);
	printf("\n\nindex = %d\n", index);
	if (index == -1)
		printf("�L�k�b�}�C����� %d\n", value);
	else
		printf("array[%d] = %d\n", index, value);
	system("pause");
	return 0;
}