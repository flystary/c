#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void e_env()
{
	printf("PATH : %s\n", getenv("PATH"));
   	printf("HOME : %s\n", getenv("HOME"));
   	printf("ROOT : %s\n", getenv("ROOT"));
}

void e_system() {
	char command[50];

	strcpy(command, "ls -l");
	system( command );

}

int values[] = { 5, 20, 29, 32, 63 };

int cmpfunc(const void *a, const void * b)
{
	return (*(int*)a - *(int*)b );
}

void e_bsearch() {
	int *item;
	int key = 32;

	item = (int*) bsearch ( &key, values, 5, sizeof(int), cmpfunc);

	if (item != NULL)
	{
		printf("Fond item = %d\n", *item);
	}
	else
	{
		printf("Item = %d could not be found\n", *item);
	}
}


int values1[] = { 88, 56, 100, 2, 25 };

int cmpfunc1 (const void *a , const void * b)
{
	return (*(int*)a - *(int*)b );
}

int e_qsort()
{
	int n;
	printf("Not Sort: \n");

	for(n = 0; n < 5; n++) {
		printf("%d ", values1[n]);
	}

	qsort(values, 5, sizeof(int), cmpfunc1);

	printf("\nSort : \n");

	for(n = 0; n < 5; n++) {
		printf("%d ", values1[n]);
	}
	printf("\n");

	return 0;
}



int main() {
	// e_env();
	// printf("\n");
	// e_system();
	// e_bsearch();

	e_qsort();
	return 0;
}
