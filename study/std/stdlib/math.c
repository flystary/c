#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int m_abs()
{
	int a, b;
	a = abs(5);
	printf("a = %d\n", a);

	b = abs(-10);
	printf("b = %d\n", b);

	return 0;
}


int m_div()
{
	div_t output;
	output = div(27, 4);
	printf("(27/4)的商 = %d\n", output.quot);
	printf("(27/4)的余 = %d\n", output.rem);

	output = div(27, 3);
	printf("(27/ 3) 的商 = %d\n", output.quot);
   	printf("(27/3) 的余数 = %d\n", output.rem);
	
	return 0;
}

int m_labs()
{
	long int a, b;
	a = labs(65987L);
	printf("a = %ld\n", a);

	b = labs(-1005090L);
	printf("b = %ld\n", b);

	return 0;
}

int m_ldiv()
{
	long int numer = 11;
	long int denom 	= 3;

	ldiv_t result = ldiv(numer, denom);

	printf("商 = %ld\n", result.quot);
    printf("余数 = %ld\n", result.rem);

    return 0;
}


int m_rand()
{
	int i, n, r;
	time_t t;

	n = 5;
	
	srand((unsigned) time(&t));

	for(i = 0; i < n; i++ ) {
		// r = rand();
		printf("%d\n", rand() % 50);
		// printf("%d\n", r % 50);
	}

	return 0;
}

int m_rand1()
{
   int i, n;
   time_t t;
   
   n = 5;
   
   /* 初始化随机数发生器 */
   srand((unsigned) time(&t));
 
   /* 输出 0 到 49 之间的 5 个随机数 */
   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50);
   }
   
  return(0);
}

int m_srand()
{
   int i, n;
   time_t t;
   
   n = 5;
   
   /* 初始化随机数发生器 */
   srand((unsigned) time(&t));
 
   /* 输出 0 到 50 之间的 5 个随机数 */
   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50);
   }
   return(0);
}

int main()
{
//	m_abs();
//	m_div();
//	m_labs();
//	m_ldiv();
//	m_rand();
//	printf("\n");
//	m_rand1();
//
	m_srand();
	return 0;
}
