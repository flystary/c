#include<stdio.h>

/*
union [union tag]
{
   member definition;
   member definition;
   ...
   member definition;
} [one or more union variables];
*/

union Date
{
    int     i;
    float   f;
    char    str[20];
} data;

union Data
{
    int     i;
    float   f;
    char    str[20];
};


void echo()
{
    union Data data;
    printf("Memory size occupied by data : %d\n", sizeof(data));
}

#include<string.h>

union Data1
{
    int    i;
    float   f;
    char    str[20];
};

void echo1()
{
    union Data1 data;

    data.i = 10;
    data.f = 220.5;
    strcpy( data.str, "C Programming");

    printf("data.i : %d\n", data.i);
    printf("data.f : %f\n", data.f);
    printf("data.str : %s\n", data.str);
}


union Data2
{
    int     i;
    float   f;
    char    str[20];
};

void echo2()
{
    union Data2 data;
    data.i = 10;
    printf( "data.i : %d\n", data.i);

    data.f = 220.5;
    printf( "data.f : %f\n", data.f);

    strcpy( data.str, "C Programming");
    printf( "data.str : %s\n", data.str);

}
int main()
{
    echo();
    echo1();
    echo2();

    return 0;
}