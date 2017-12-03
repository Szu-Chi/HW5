#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int dice1,dice2;
	int point[6][6] = {0};
	int t[13] = {0};
	srand(time(NULL));
	for( int i = 0; i < 36000; i ++){
		dice1 = rand() % 6;
		dice2 = rand() % 6;
		point[dice1][dice2]++;
		t[dice1 + dice2]++; 
	}
	printf("  ");
	for( int i = 0; i < 6; i++)
		printf("   %4d",i + 1);
	printf("\n");

	for (int i = 0; i < 6; i++) {
		printf(" %d",i + 1);
		for (int j = 0; j < 6; j++) {
			printf("   %4d", point[i][j]);
		}
		printf("\n");
	}
	printf("¦¸¼Æ:\n");
	for (int i = 0; i < 11; i++)
		printf("%2d: %4d\n",i + 2,t[i]);
	
	printf("\n");
	system("pause");
	return 0;
}