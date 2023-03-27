#include<stdio.h>

//内存管理
/*
void *calloc(int num, int size);
在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。所以它的结果是分配了 num*size 个字节长度的内存空间，并且每个字节的值都是 0。
void free(void *address);
该函数释放 address 所指向的内存块,释放的是动态分配的内存空间。
void *malloc(int num);
在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。
void *realloc(void *address, int newsize);
该函数重新分配内存，把内存扩展到 newsize。
*/

// char name[100]
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mem()
{
    char name[100];
    char *description;

    strcpy(name, "ZAra Ali");
    description = (char *)malloc(200*sizeof(char));


    if (description == NULL)
    {
        fprintf(stderr, "Error - unable to allocate\n");
    }
    else
    {
        strcpy(description, "Zara ali a DPS student in class 10th");
    }
    printf("Name = %s\n", name);
    printf("Description: %s\n", description);

    return 0;
}


int mem1()
{
    char name[100];
    char *description;

    strcpy(name, "Zara Ali");

    /* 动态分配内存 */
    description = (char *)malloc( 30 * sizeof(char) );
    if( description == NULL )
    {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else
    {
        strcpy( description, "Zara ali a DPS student.");
    }
    description = (char *) realloc(description, 100 *sizeof(char));
    if( description == NULL )
    {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else
    {
        strcat( description, "She is in class 10th");
    }

    printf("Name = %s\n", name );
    printf("Description: %s\n", description );

    free(description);
}

/*
常用的内存管理函数和运算符
malloc() 函数：用于动态分配内存。它接受一个参数，即需要分配的内存大小（以字节为单位），并返回一个指向分配内存的指针。

free() 函数：用于释放先前分配的内存。它接受一个指向要释放内存的指针作为参数，并将该内存标记为未使用状态。

calloc() 函数：用于动态分配内存，并将其初始化为零。它接受两个参数，即需要分配的内存块数和每个内存块的大小（以字节为单位），并返回一个指向分配内存的指针。

realloc() 函数：用于重新分配内存。它接受两个参数，即一个先前分配的指针和一个新的内存大小，然后尝试重新调整先前分配的内存块的大小。如果调整成功，它将返回一个指向重新分配内存的指针，否则返回一个空指针。

sizeof 运算符：用于获取数据类型或变量的大小（以字节为单位）。

指针运算符：用于获取指针所指向的内存地址或变量的值。

& 运算符：用于获取变量的内存地址。

* 运算符：用于获取指针所指向的变量的值。

-> 运算符：用于指针访问结构体成员，语法为 pointer->member，等价于 (*pointer).member。

memcpy() 函数：用于从源内存区域复制数据到目标内存区域。它接受三个参数，即目标内存区域的指针、源内存区域的指针和要复制的数据大小（以字节为单位）。

memmove() 函数：类似于 memcpy() 函数，但它可以处理重叠的内存区域。它接受三个参数，即目标内存区域的指针、源内存区域的指针和要复制的数据大小（以字节为单位）。
*/
int main()
{
    mem();
    mem1();

    return 0;
}