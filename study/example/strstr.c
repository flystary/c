#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *m_strstr(const char *s, const char *t)
{
    char *s1 = s;
    char *t1 = t;

    while(*s && *t)
    {
        if(*s++ != *t++)
        {
            t = t1;
            s = ++s1;
        }
    }

    if(*t == '\0')
        return s1;
    else
        return NULL;
}

char *m_strstr1(const char s[], const char t[])//K&R书上找的
{
    int i, j, k;
 
    for(i = 0; s[i] != '\0'; i++)
    {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            return s[i];
    }
 
    return NULL;
}


int main()
{
    const char haystack[20] = "HELLOIOT";
    const char needle[10] = "LLO";
    
    const char h[] = "HELLO";
    const char n[] = "EL";

    char *ret;
    char *ret1;
    char *ret2;

    ret = strstr(haystack, needle);
    printf("子字符串是: %s\n", ret);

    ret1 = m_strstr(haystack, needle);
    printf("子字符串是: %s\n", ret1);

    ret2 = m_strstr1(h, n);
    printf("子字符串是: %s\n", ret2);

    return 0;
}
