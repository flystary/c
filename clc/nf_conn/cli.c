#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char *argv[])
{

    char *addr = "";
    char *port = "";
    char *direction = "";

    if (argc == 2)
    {
        if (strcmp(argv[1], "--ip") == 0)
        {
            addr = argv[2];
        }
        else if (strcmp(argv[1], "--port") == 0)
        {
            port = argv[2];
        }
        else if (strcmp(argv[1], "--direction") == 0)
        {
            direction = argv[2];
        }
        else
        {
            printf("[]\n");
            return 0;
        }
    }
    else
    {
        printf("[]\n");
        return 0;
    }

    printf("%s %s %s \n", addr, port, direction);

    return 0;
}