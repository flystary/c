#include <stdio.h>
#include <stdlib.h>

int mcalloc()
{
	int i, n;
	int *a;

	printf("要输入的元素个数：");
	scanf("%d", &n);

	a = (int *)calloc(n, sizeof(int));
	printf("输入 %d 个数字：\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("输入的数字为：");
	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}

	free(a); // 释放内存

	return 0;
}

int mfree()
{
	char *str;

	str = (char *)malloc(15);
	strcpy(str, "baidu");

	printf("String = %s,  Address = %p\n", str, str);

	/* 重新分配内存 */
	str = (char *)realloc(str, 25);
	strcat(str, ".com");
	printf("String = %s,  Address = %p\n", str, str);

	/* 释放已分配的内存 */
	free(str);

	return 0;
}

int mrealloc()
{
	char *str;

	/* 最初的内存分配 */
	str = (char *)malloc(15);
	strcpy(str, "runoob");
	printf("String = %s,  Address = %p\n", str, str);

	/* 重新分配内存 */
	str = (char *)realloc(str, 25);
	strcat(str, ".com");
	printf("String = %s,  Address = %p\n", str, str);

	free(str);

	return 0;
}

int main()
{
	// mcalloc();
	// mfree();
	mrealloc();
	return 0;
}
