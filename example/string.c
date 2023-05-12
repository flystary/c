#include<stdio.h>
#include<string.h>

int echo_a1()
{
    char a1[] = {'a', 'b', 'c', 'd'};

    char a2[] = { "abcd" };

    
    printf("%lu\n", sizeof(a1));

    // printf("%lu\n", strlen(a1)); // error
    // printf("%s\n", a1);          // error


    for(int i = 0; i<4; i++)
    {
        printf("%c\n", a1[i]);
    }
    
    return 0;
}


int echo_a2()
{
    char a2[] = { "abcd" };

    printf("%lu\n", sizeof(a2));
    printf("%lu\n", strlen(a2));

    for( int i = 0; i < 4; i++ )
    {
        printf("%c\n", a2[i]);
    }

    return 0;
}


int echo_a3()
{
    int a[]={4,5,6,7,8};

    int *p = a;

    *p++=100;

    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);  

    printf("\n");
    printf("*p: %d\n", *p);

    printf("*(++p): %d\n", *(++p));
    
    return 0;
}

int main()
{
    echo_a1();

    printf("\n");

    echo_a2();
    
    printf("\n");

    echo_a3();

    return 0;
}
