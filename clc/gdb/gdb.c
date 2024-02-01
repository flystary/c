#include <stdio.h>
#include <stdlib.h>


struct st
{
    int    a;
    int    b;
};

void print_array(char* array, int len)
{
    int i = 0;
    for(i=0; i < len; i++)
    {
        printf("array[%d]: %c\n", i, array[i]);
    }
}


int main(int argc, char* argv[])
{
    struct st st_temp;
    int i =0;
    char array[5];

    st_temp.a = 10;
    st_temp.b = 11;

    for(i = 0; i < 5; i++)
    {
        array[i] = i + '0';
    }
    print_array(array, 5);

    for(i = 0; i < argc; i++)
    {
        printf("hello...argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}
