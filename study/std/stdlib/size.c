#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int s_mblen()
{
	int len;
   	char *pmbnull  = NULL;
   	char *pmb = (char *)malloc( MB_CUR_MAX );
   	wchar_t *pwc = L"Hi";
   	wchar_t *pwcs = (wchar_t *)malloc( sizeof( wchar_t ));

	printf("转换为多字节字符串\n");
   	len = wcstombs( pmb, pwc, MB_CUR_MAX);
   	printf("被转换的字符 %d\n", len);
   	printf("第一个多字节字符的十六进制值：%#.4x\n", pmb);
   
   	len = mblen( pmb, MB_CUR_MAX );
   	printf( "多字节字符 %x 的字节长度：%u\n", pmb, len );

   	pmb = NULL;
   
   	len = mblen( pmb, MB_CUR_MAX );
   	printf( "多字节字符 %x 的字节长度：%u\n", pmb, len );
   
   	return(0);
}


int s_mbstowcs() {
	int len;
	
	char *pmbnull  = NULL;
   	char *pmb = (char *)malloc( MB_CUR_MAX );
   	wchar_t *pwc = L"Hi";
   	wchar_t *pwcs = (wchar_t *)malloc( sizeof( wchar_t ));
 

	printf("转换为多字节字符串\n");
   	len = wcstombs( pmb, pwc, MB_CUR_MAX);
   	printf("被转换的字符 %d\n", len);
   	printf("第一个多字节字符的十六进制值：%#.4x\n", pmb);

   	printf("转换回宽字符字符串\n");
   	len = mbstowcs( pwcs, pmb, MB_CUR_MAX);
   	printf("被转换的字符 %d\n", len);
   	printf("第一个宽字符的十六进制值：%#.4x\n\n", pwcs);
   
   	return(0);

}


int s_mbtowc() {
	char *str = "这里是 runoob.com";
	wchar_t mb[100];
	int len;

	len = mblen(NULL, MB_CUR_MAX);

	mbtowc(mb, str, len*strlen(str));

	wprintf(L"%ls \n", mb);

	return 0;
}


#define BUFFER_SIZE 50

int s_wcstombs()
{
   size_t ret;
   char *MB = (char *)malloc( BUFFER_SIZE );
   wchar_t *WC = L"http://www.w3cschool.cc";

   /* 转换宽字符字符串 */
   ret = wcstombs(MB, WC, BUFFER_SIZE);
   
   printf("要转换的字符数 = %u\n", ret);
   printf("多字节字符 = %s\n\n", MB);
   
   return(0);
}


int s_wctomb()
{
   int i;
   wchar_t wc = L'a';
   char *pmbnull = NULL;
   char *pmb = (char *)malloc(sizeof( char ));

   printf("要转换的宽字符：\n");
   i = wctomb( pmb, wc );
   printf("被转换的字符：%u\n", i);
   printf("多字节字符：%.1s\n", pmb);

   printf("当要转换的字符为 NULL 时尝试转换：\n");
   i = wctomb( pmbnull, wc );
   printf("被转换的字符：%u\n", i);
   /* 不会输出任何值 */
   printf("多字节字符：%.1s\n", pmbnull);
   
   return(0);
}

int main()
{
	// s_mblen();
	// s_mbstowcs();
	// s_mbtowc();
	s_wcstombs();
	s_wctomb();
	return 0;
}
