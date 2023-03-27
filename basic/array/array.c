#include<stdio.h>

//
/* type arrayName [ arraySize ]; */
/*
double balance[10];

double balance[5] = {100.0, 2.0, 3.4, 7.0, 50.0};

double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};

balance[4] = 50.0;

double salary = balance[9];
*/

void array1()
{
    int n [ 10 ];
    int i, j;

    for( i = 0; i < 10; i++)
    {
        n[i] = i + 100;
    }

    for (j = 0; j < 10; j++)
    {
        printf("Element[%d] = %d\n", j, n[j]);
    }

}

int main()
{
    array1();
    return 0;
}