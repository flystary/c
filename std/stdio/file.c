#include<stdio.h>
#include<string.h>


int f_close()
{
    FILE *fp;
	fp = fopen("file.txt","w");

    fprintf(fp, "%s\n", "www.baidu.com");
    fclose(fp);


    return 0;
}


int f_clearerr()
{
    FILE *fp;
    char c;
    
    fp = fopen("file.txt", "w");

    c = fgetc(fp);
    if(ferror(fp));
    {
        printf("读取文件：file.txt 时发生错误\n");
    }
    
    clearerr(fp);
    if( ferror(fp) )
    {
        printf("读取文件：file.txt 时发生错误\n");
    }    
    fclose(fp);

    return 0;
}

int f_feof()
{
    FILE *fp;
    int c;
    

    fp = fopen("file.txt", "r");

    if(fp == NULL) {
        perror("open this file error");
        return -1;
    }
    while(1) {
        c = fgetc(fp);
        if (feof(fp)) {
            break;
        }
        printf("%c", c);
    }

    fclose(fp);

    return 0;
}


int f_ferror()
{
    FILE *fp;
    char c;

    fp = fopen("file.txt", "w");

    c = fgetc(fp);
    if( ferror(fp) )
    {
        printf("读取文件：file.txt 时发生错误\n");
    }
    clearerr(fp);
    if( ferror(fp) )
    {
        printf("读取文件：file.txt 时发生错误\n");
    }
    fclose(fp);


    return 0;
}


int f_fflush()
{
    char buff[1024];

    memset(buff, '\0', sizeof(buff));

    fprintf(stdout, "启用全缓冲\n");
    setvbuf(stdout, buff, _IOFBF, 1024);
 
    fprintf(stdout, "这里是 www.baidu.com\n");
    fprintf(stdout, "该输出将保存到 buff\n");
    fflush( stdout );
 
    fprintf(stdout, "这将在编程时出现\n");
    fprintf(stdout, "最后休眠五秒钟\n");
 
    sleep(5);

    return 0;
}

int f_fgetpos()
{
    FILE *fp;
    fpos_t position;

    fp = fopen("file.txt", "w+");
    fgetpos(fp, &position);
    fputs("Hello World!", fp);


    fsetpos(fp, &position);
    fputs("这将覆盖之前的内容", fp);

    fclose(fp);
    
    return 0;
}

/*
 *
 * "r"  打开一个用于读取的文件。该文件必须存在。
 * "w"  创建一个用于写入的空文件。如果文件名称与已存在的文件相同，则会删除已有文件的内容，文件被视为一个新的空文件。
 * "a"  追加到一个文件。写操作向文件末尾追加数据。如果文件不存在，则创建文件。
 * "r+" 打开一个用于更新的文件，可读取也可写入。该文件必须存在。
 * "w+" 创建一个用于读写的空文件。
 * "a+" 打开一个用于读取和追加的文件
 */

int f_fopen()
{
    FILE *fp;
    fp = fopen("file.txt", "w+");

    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2023);

    fclose(fp);

    return 0;
}

void print()
{
    FILE *fp;
    int c;
    int n = 0;

    fp = fopen("file.txt","r");
    while(1)
    {
        c = fgetc(fp);
        if( feof(fp) )
        {
            break ;
        }
        printf("%c", c);
    }

    fclose(fp);
}


int f_fread()
{
    FILE    *fp;
    char    c[] = "This is baidu";
    char    buffer[20];

    fp = fopen("file.txt", "w+");
    fwrite(c, strlen(c) + 1, 1, fp);
    fseek(fp, 0, SEEK_SET);

    fread(buffer, strlen(c)+1, 1, fp);

    printf("%s\n", buffer);

    fclose(fp);

    return 0;

}

int main()
{
    // f_close();
    // f_clearerr();
    // f_feof();
    // f_ferror();
    // f_fflush();
    // f_fgetpos();
    // f_fopen();
    f_fread();

    // print();
    return 0;
}
