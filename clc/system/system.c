#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getOsInfo() {
    FILE *fp = fopen("/proc/version", "r");
    if (NULL == fp)
        printf("failed to open version\n");

    char szTest[1000] = {0};
    while(!feof(fp))
    {
        memset(szTest, 0, sizeof(szTest));
        fgets(szTest, sizeof(szTest) -1, fp);
        printf("%s", szTest);
    }
    fclose(fp);
}


void getMemInfo()
{
    FILE *fp = fopen("/proc/meminfo", "r");
    if (NULL == fp)
        printf("failed to open meminfo\n");
    
    char szTest[1000] = {0};
    while(!feof(fp))
    {
        memset(szTest, 0, sizeof(szTest));
        fgets(szTest, sizeof(szTest) - 1, fp);
        printf("%s", szTest);
    }
    fclose(fp);
}

int main()
{
    getOsInfo();
    getMemInfo();

    return 0;
}
