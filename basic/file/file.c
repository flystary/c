#include<stdio.h>

// 文件读写

// fopen( ) 函数来创建一个新的文件或者打开一个已有的文件

// FILE *fopen( const char *filename, const char *mode );

// 访问模式 mode 的值
/*
r	打开一个已有的文本文件，允许读取文件。
w	打开一个文本文件，允许写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会从文件的开头写入内容。如果文件存在，则该会被截断为零长度，重新写入。
a	打开一个文本文件，以追加模式写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会在已有的文件内容中追加内容。
r+	打开一个文本文件，允许读写文件。
w+	打开一个文本文件，允许读写文件。如果文件已存在，则文件会被截断为零长度，如果文件不存在，则会创建一个新文件。
a+	打开一个文本文件，允许读写文件。如果文件不存在，则会创建一个新文件。读取会从文件的开头开始，写入则只能是追加模式。
*/

// 二进制文件
// "rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"

// 关闭文件

//  int fclose( FILE *fp );

//  如果成功关闭文件，fclose( ) 函数返回零，如果关闭文件时发生错误，函数返回 EOF。

// 写入文件

// int fputc( int c, FILE *fp );

// 函数 fputc() 把参数 c 的字符值写入到 fp 所指向的输出流中。如果写入成功，它会返回写入的字符，如果发生错误，则会返回 EOF。

// int fputs( const char *s, FILE *fp );

// 函数 fputs() 把字符串 s 写入到 fp 所指向的输出流中。如果写入成功，它会返回一个非负值，如果发生错误，则会返回 EOF。


int write()
{
    FILE *fp = NULL;

    fp = fopen("/tmp/test.txt", "w+");
    fprintf(fp, "This is testing for fprintf...\n");

    fputs("This is testing for fputs...\n", fp);
    fclose(fp);
}


// 读取文件
/*
int fgetc( FILE * fp );

fgetc() 从 fp 所指向的输入文件中读取一个字符。返回值是读取的字符，如果发生错误则返回 EOF。下面的函数允许您从流中读取一个字符串：

char *fgets( char *buf, int n, FILE *fp );
fgets() 从 fp 所指向的输入流中读取 n - 1 个字符。它会把读取的字符串复制到缓冲区 buf，并在最后追加一个 null 字符来终止字符串。
*/


int read()
{
    FILE *fp = NULL;
    char buff[255];

    fp = fopen("/tmp/test.txt", "r");
    fscanf(fp, "%s", buff);
    printf("1: %s\n", buff);

    fgets(buff, 255, (FILE*)fp);
    printf("2: %s\n", buff);

    fgets(buff, 255, (FILE*)fp);
    printf("3: %s\n", buff);

    fclose(fp);
}
// fscanf() 方法只读取了 This，因为它在后边遇到了一个空格。其次，调用 fgets() 读取剩余的部分，直到行尾。最后，调用 fgets() 完整地读取第二行。


// 二进制I/O
ize_t fread(void *ptr, size_t size_of_elements,
             size_t number_of_elements, FILE *a_file);

size_t fwrite(const void *ptr, size_t size_of_elements,
             size_t number_of_elements, FILE *a_file);

//都是用于存储块的读写 - 通常是数组或结构体


int main()
{
    write();

    read();
}