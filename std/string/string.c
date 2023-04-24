#include <string.h>

int chr()
{
	const char str[] = "http://www.baidu.com";
	const char ch1 = '.';
	const char ch2 = 'd';
	const char ch3 = 'c';

	char *ret1;
	char *ret2;
	char *ret3;

	ret1 = (char *)memchr(str, ch1, strlen(str));
	ret2 = (char *)memchr(str, ch2, strlen(str));
	ret3 = (char *)memchr(str, ch3, strlen(str));
	printf("|%c| 之后的字符串是 - |%s|\n", ch1, ret1);
	printf("|%c| 之后的字符串是 - |%s|\n", ch2, ret2);
	printf("|%c| 之后的字符串是 - |%s|\n", ch3, ret3);
	return (0);
}

int cmp()
{
	char str1[15];
	char str2[15];
	int ret;

	memcpy(str1, "abcdef", 6);
	memcpy(str2, "ABCDEF", 6);

	ret = memcmp(str1, str2, 5);
	if (ret > 0)
	{
		printf("str1 > str2\n");
	}
	else if (ret < 0)
	{
		printf("str1 < str2\n");
	}
	else
	{
		printf("str1==str2\n");
	}

	return (0);
}

int cpy()
{
	const char src[50] = "http://www.baidu.com/ or http://www.shifen.com/";
	char dest[50];

	memcpy(dest, src, strlen(src) + 1);
	printf("len(src) = %d\n", strlen(src));
	printf("dest = %s \n", dest);

	char *s = "http://www.qq.com";
	char d[20];
	// memcpy(d, s+11, 6);
	memcpy(d, s + 11 * sizeof(char), 6 * sizeof(char));
	d[6] = '\0';
	printf("%s\n", d);

	char src1[] = "***";
	char dest1[] = "abcdefg";
	printf("使用 memcpy 前: %s\n", dest1);
	memcpy(dest1, src1, strlen(src1));
	printf("使用 memcpy 后: %s\n", dest1);

	return (0);
}

int move()
{
	const char dst[] = "oldstring";
	const char src[] = "newstring";

	printf("Before memmove dest = %s, src = %s\n", dst, src);
	memmove(dst, src, 9);
	printf("After memmove dest = %s, src = %s\n", dst, src);

	return (0);
}

int set()
{
	char str[50];
	strcpy(str, "This is String.h library funtion");
	puts(str);

	memset(str, '@', 7);
	puts(str);

	return(0);
}
int main()
{
	// chr();
	// cmp();
	// cpy();
	// move();
	set();
	return (0);
}
