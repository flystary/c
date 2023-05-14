#include<stdio.h>

int main()
{
	char  input[10];
	scanf("%s", &input);

	switch (*input) {
	case 'G':
	case 'g':
		printf("G\n");
		break;
	case 'A':
	case 'a':
		printf("A\n");
		break;
	default:
		break;
	}

	return 0;
}
