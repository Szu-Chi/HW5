#include <stdio.h>
#include <stdlib.h>

int maximumInArray(int *array,int size,int index) {
	static int max = 0;
	if (array[max] < array[index]) max = index;
	if (index < size)
		return maximumInArray(array, size, index + 1);
	else
		return max;
}

int main(void) {
	unsigned int size;
	int *array;
	srand(time(NULL));
	scanf_s("%d",&size);
	array = calloc(size,sizeof(int));
	for (unsigned int i = 0; i < size; i++) {
		if (!(i % 5)) printf("\n");
		array[i] = rand() % 500;
		printf("array[%3d] = %3d\t", i, array[i]);
	}
	
	printf("\nMaximum in array is array[%d]\n",maximumInArray(array, size, 0));
	system("pause");
	return 0;
}