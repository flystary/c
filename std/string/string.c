#include<string.h>

int chr()
{
	const char str[] = "http://www.baidu.com";
    const char ch1 = '.';
    const char ch2 = 'd';
    const char ch3 = 'c';

	char *ret1;
	char *ret2;
	char *ret3;

	ret1 = (char*)memchr(str, ch1, strlen(str));
	ret2 = (char*)memchr(str, ch2, strlen(str));
	ret3 = (char*)memchr(str, ch3, strlen(str));
    printf("|%c| 之后的字符串是 - |%s|\n", ch1, ret1);
    printf("|%c| 之后的字符串是 - |%s|\n", ch2, ret2);
    printf("|%c| 之后的字符串是 - |%s|\n", ch3, ret3);
	return(0);
}


int main()
{
	chr();
    return(0);
}
