#include "libft.h"
#include <stdio.h>
#include <string.h>

#define VERSION_NUMBER 2.0
#define TEST_MODULE "libft"

void test_ft_strlen()
{
	char TEST_NAME[] = "ft_strlen test 1.0";
	char strlen_test0[] = "13 chr string";//base test, nothing special
	char strlen_test1[] = "This\tstring\vis\rfull\aof\bspecial\echaracters\n";//check if there are issues on special characters
	char strlen_test2[] = "";//empty string check

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strlen)\n");
	printf("%d , ",(int)strlen(strlen_test0));
	printf("%d , ",(int)strlen(strlen_test1));
	printf("%d \n\n",(int)strlen(strlen_test2));

	printf("ACTUAL RESULT   (ft_strlen)\n");
	printf("%d , ",(int)ft_strlen(strlen_test0));
	printf("%d , ",(int)ft_strlen(strlen_test1));
	printf("%d \n",(int)ft_strlen(strlen_test2));

	if((int)strlen(strlen_test0) != (int)ft_strlen(strlen_test0))
		printf("issue detected on test 0 (\"13 chr string\"): base test, nothing special\n");
	if((int)strlen(strlen_test1) != (int)ft_strlen(strlen_test1))
		printf("issue detected on test 1 (\"This\\tstring\\vis\\rfull\\aof\\bspecial\\echaracters\\n\"): check if there are issues on special characters\n");
	if((int)strlen(strlen_test2) != (int)ft_strlen(strlen_test2))
		printf("issue detected on test 2 (\"\"): empty string check\n");

}
void test_ft_strcpy()
{
	char TEST_NAME[] = "ft_strcpy test 1.0";
	char strcpy_test0[] = "13 chr string";//base test, nothing special
	char strcpy_test1[] = "This\tstring\vis\rfull of\bspecial\echaracters\n";//check if there are issues on special characters
	char strcpy_test2[] = "";//empty string check

	char strcpy_dest0[60];
	char strcpy_dest1[60];
	char strcpy_dest2[60];

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strcpy)\n");
	printf("%s \n",strcpy(strcpy_dest0,strcpy_test0));
	printf("%s \n",strcpy(strcpy_dest1,strcpy_test1));
	printf("%s \n\n",strcpy(strcpy_dest2,strcpy_test2));

	char strcpy_dest3[60];
	char strcpy_dest4[60];
	char strcpy_dest5[60];
	printf("ACTUAL RESULT   (ft_strcpy)\n");
	printf("%s \n",strcpy(strcpy_dest3,strcpy_test0));
	printf("%s \n",strcpy(strcpy_dest4,strcpy_test1));
	printf("%s \n",strcpy(strcpy_dest5,strcpy_test2));

	if(strcmp(strcpy_dest0,strcpy_dest3) != 0)
		printf("issue detected on test 0 (\"13 chr string\"): base test, nothing special\n");
	if(strcmp(strcpy_dest1,strcpy_dest4) != 0)
		printf("issue detected on test 1 (\"This\\tstring\\vis\\rfull of\\bspecial\\echaracters\\n\"): check if there are issues on special characters\n");
	if(strcmp(strcpy_dest2,strcpy_dest5) != 0)
		printf("issue detected on test 2 (\"\"): empty string check\n");
}
void test_ft_memset()
{
	char TEST_NAME[] = "ft_memset test 1.0";
	char memset_test0[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	char memset_test1[] = "XX\nXX\bXX\vX";
	char memset_test2[] = "XXXXX\0XXXX";
	char memset_control0[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	char memset_control1[] = "XX\nXX\bXX\vX";
	char memset_control2[] = "XXXXX\0XXXX";

	char *ctrl0 = memset(memset_control0,89,30);//normal test, nothing special
	//Memset throws a compiler warning on a empty string check so it's missing.
	char *ctrl1 = memset(memset_control1,89,10);//empty string check
	char *ctrl2 = memset(memset_control2,89,10);//terminating char check
	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (memset)\n");
	printf("%s \n",ctrl0);
	printf("%s \n",ctrl1);
	printf("%s \n\n",ctrl2);
	printf("ACTUAL RESULT   (ft_memset)\n");
	char *ctrl3 = ft_memset(memset_test0,89,30);//normal test, nothing special
	char *ctrl4 = ft_memset(memset_test1,89,10);//empty string check
	char *ctrl5 = ft_memset(memset_test2,89,10);//terminating char check
	printf("%s \n",ctrl3);
	printf("%s \n",ctrl4);
	printf("%s \n",ctrl5);

	if(strcmp(ctrl0,ctrl3) != 0)
		printf("issue detected on test 0 (\"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\"): base test, nothing special\n");
	if(strcmp(ctrl1,ctrl4) != 0)
		printf("issue detected on test 1 (\"XX\\nXX\\bXX\\vX\"): standard special chars test\n");
	if(strcmp(ctrl2,ctrl5) != 0)
		printf("issue detected on test 2 (\"XXXXX\\0XXXX\"): check if there are issues on special characters\n");
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (strcmp(av[1], "strlen") == 0 || strcmp(av[1], "ft_strlen") == 0)
			test_ft_strlen();
		else if (strcmp(av[1], "strcpy") == 0 || strcmp(av[1], "ft_strcpy") == 0)
			test_ft_strcpy();
		else if (strcmp(av[1], "memset") == 0 || strcmp(av[1], "ft_memset") == 0)
			test_ft_memset();
	}
	return (0);
}
