#include<stdio.h>
#include<string.h>
#include<getopt.h>
//argc 是指传入参数的个数，argv[] 是一个指针数组，指向传递给程序的每个参数。


int args(int argc, char *argv[])
{
    if( argc == 2)
    {
        printf("%s\n", argv[1]);
    }
    else if (argc > 2 )
    {
        printf("Too many arguments supplied.\n");
    }
    else
    {
        printf("One argument expected.\n");
    }
}


int args1( int argc, char *argv[] )
{
   printf("Program name %s\n", argv[0]);

   if( argc == 2 )
   {
      printf("The argument supplied is %s\n", argv[1]);
   }
   else if( argc > 2 )
   {
      printf("Too many arguments supplied.\n");
   }
   else
   {
      printf("One argument expected.\n");
   }

   return 0;
}


// int main(int test_argc,  char *test_argv[])

int main(int argc, char *argv[]){
    char *optstr = "p:n:m:c:";
    struct option opts[] = {
        {"path", 1, NULL, 'p'},
        {"name", 1, NULL, 'n'},
        {"mtime", 1, NULL, 'm'},
        {"ctime", 1, NULL, 'c'},
        {0, 0, 0, 0},
    };
    int opt;
    while((opt = getopt_long(argc, argv, optstr, opts, NULL)) != -1){
        switch(opt) {
            case 'p':
                strcpy(path, optarg);
                break;
            case 'n':
                strcpy(targetname, optarg);
                break;
            case 'm':
                modifiedtime = atoi(optarg);
                break;
            case 'c':
                changetime = atoi(optarg);
                break;
            case '?':
                if(strchr(optstr, optopt) == NULL){
                    fprintf(stderr, "unknown option '-%c'\n", optopt);
                }else{
                    fprintf(stderr, "option requires an argument '-%c'\n", optopt);
                }
                return 1;
        }
    }
    findInDir(path);
    return 0;
}