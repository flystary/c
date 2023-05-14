#include <string.h>

int mchr()
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

int mcmp()
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

int mcpy()
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

int mmove()
{
	const char dst[] = "oldstring";
	const char src[] = "newstring";

	printf("Before memmove dest = %s, src = %s\n", dst, src);
	memmove(dst, src, 9);
	printf("After memmove dest = %s, src = %s\n", dst, src);

	return (0);
}

int mset()
{
	char str[50];
	strcpy(str, "This is String.h library funtion");
	puts(str);

	memset(str, '@', 7);
	puts(str);

	return (0);
}

int scat()
{
	char src[50], dst[50];
	strcpy(src, "This is source");
	strcpy(dst, "This is destination");

	strcat(dst, src);
	printf("最终的目标字符串： |%s|\n", dst);

	return 0;
}

int sncat()
{
	char src[50], dest[50];

	strcpy(src, "This is source SRC");
	strcpy(dest, "This is destination");

	strncat(dest, src, 17);

	printf("最终的目标字符串： |%s|\n", dest);

	return (0);
}

int schr()
{
	const char str[] = "https://www.baidu.com";
	const char ch = 'i';
	char *ptr;

	ptr = strchr(str, ch);
	if (ptr != NULL)
	{
		printf("字符 'i' 出现的位置为 %ld。\n", ptr - str + 1);
		printf("|%c| 之后的字符串是 - |%s|\n", ch, ptr);
	}
	else
	{
		printf("没有找到字符 'o' 。\n");
	}

	char *find;
	find = strchr(ptr, '\n'); // 查找换行符
	if (find)				  // 如果地址不是NULL
		*find = '\0';		  // 在此处放置一个空字符
	else
		while (getchar() != '\n')
			continue;

	return (0);
}

int scmp()
{
	char str1[15];
	char str2[15];
	int ret;

	strcpy(str1, "abcdef");
	strcpy(str2, "ABCDEF");

	ret = strcmp(str1, str2);

	if (ret < 0)
	{
		printf("str1 小于 str2");
	}
	else if (ret > 0)
	{
		printf("str1 大于 str2");
	}
	else
	{
		printf("str1 等于 str2");
	}

	return (0);
}
int sncmp()
{
	char str1[15];
	char str2[15];
	int ret;

	strcpy(str1, "abcdef");
	strcpy(str2, "ABCDEF");

	ret = strncmp(str1, str2, 4);

	if (ret < 0)
	{
		printf("str1 小于 str2");
	}
	else if (ret > 0)
	{
		printf("str2 小于 str1");
	}
	else
	{
		printf("str1 等于 str2");
	}

	return (0);
}

int scoll()
{
	char str1[15];
	char str2[15];
	int ret;

	strcpy(str1, "abc");
	strcpy(str2, "ABC");

	ret = strcoll(str1, str2);

	if (ret > 0)
	{
		printf("str1 大于 str2\n");
	}
	else if (ret < 0)
	{
		printf("str2 小于 str1\n");
	}
	else
	{
		printf("str1 等于 str2\n");
	}
	return (0);
}

int scpy()
{
	char src[40];
	char dest[100];

	memset(dest, '\0', sizeof(dest));
	strcpy(src, "This is runoob.com");
	strcpy(dest, src);

	printf("最终的目标字符串： %s\n", dest);

	char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	strcpy(str2, str1);
	strcpy(str3, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);

	return (0);
}

int sncpy()
{
	char src[40];
	char dest[12];

	memset(dest, '\0', sizeof(dest));
	strcpy(src, "This is runoob.com");
	strncpy(dest, src, 10);

	printf("最终的目标字符串： %s\n", dest);

	return (0);
}

int scspn()
{
	int len;
	const char str1[] = "ABCDEF4 3 0960910";
	const char str2[] = "013";

	len = strcspn(str1, str2);

	printf("第一个匹配的字符是在 %d\n", len + 1);

	return (0);
}
#include <stdio.h>
#include <errno.h>

int serror()
{
	FILE *fp;

	fp = fopen("file.txt", "r");
	if (fp == NULL)
	{
		printf("Error: %s\n", strerror(errno));
	}

	return (0);
}

int slen()
{
	char str[50];
	int len;

	strcpy(str, "This is baidu.com");
	len = strlen(str);

	printf("|%s|的长度是|%d|\n", str, len);

	return (0);
}

int spbrk()
{
	const char str1[] = "abcde2fghi3jk4l";
	const char str2[] = "34";
	char *ret;

	ret = strpbrk(str1, str2);
	if (ret)
	{
		printf("第一个匹配的字符是： %c\n", *ret);
	}
	else
	{
		printf("未找到字符");
	}

	return (0);
}

int srchr()
{
	int len;
	const char str[] = "https://www.runoob.com";
	const char ch = '.';
	char *ret;

	ret = strrchr(str, ch);

	printf("|%c| 之后的字符串是 - |%s|\n", ch, ret);

	return (0);
}

int sspn()
{
	int len;
	const char str1[] = "ABCDEFG019874ABCD";
	const char str2[] = "ABCD";

	len = strspn(str1, str2);

	printf("初始段匹配长度 %d\n", len);

	return (0);
}

int sstr()
{
	const char haystack[20] = "RUNOOB";
	const char needle[10] = "NOOB";
	char *ret;

	ret = strstr(haystack, needle);

	printf("子字符串是： %s\n", ret);

	return (0);
}

int stok()
{
	char str[80] = "This is - www.runoob.com - website";
	const char s[2] = "-";
	char *token;

	/* 获取第一个子字符串 */
	token = strtok(str, s);

	/* 继续获取其他的子字符串 */
	while (token != NULL)
	{
		printf("%s\n", token);

		token = strtok(NULL, s);
	}

	return (0);
}

int sxfrm()
{
	char dest[20];
	char src[20];
	int len;

	strcpy(src, "W3C School");
	len = strxfrm(dest, src, 20);

	printf("\n字符串 |%s| 的长度是： |%d|\n", dest, len);

	return (0);
}

int main()
{
	// mchr();
	// mcmp();
	// mcpy();
	// mmove();
	// mset();
	// scat();
	// sncat();
	// schr();
	// scmp();
	// sncmp();
	// scoll();
	// scpy();
	// sncpy();
	// scspn();
	// serror();
	// slen();
	// spbrk();
	// srchr();
	// sspn();
	// sstr();
	stok();
	sxfrm();

	return (0);
}
