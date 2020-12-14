#include "libft.h"
#include <stdio.h>
#include <string.h>

void test_ft_strlen()
{
	char strlentest0[] = "13 chr string";//base test, nothing special
	char strlentest1[] = "This\tstring\vis\rfull\aof\bspecial\echaracters\n";//check if there are issues on special characters
	char strlentest2[] = "";//empty string check

	printf("EXPECTED RESULT (strlen)\n");
	printf("%d , ",(int)strlen(strlentest0));
	printf("%d , ",(int)strlen(strlentest1));
	printf("%d \n",(int)strlen(strlentest2));

	printf("ACTUAL RESULT   (ft_strlen)\n");
	printf("%d , ",(int)ft_strlen(strlentest0));
	printf("%d , ",(int)ft_strlen(strlentest1));
	printf("%d \n",(int)ft_strlen(strlentest2));

	if((int)strlen(strlentest0) != (int)ft_strlen(strlentest0))
		printf("issue detected on test 0 (\"13 chr string\"): base test, nothing special\n");
	if((int)strlen(strlentest1) != (int)ft_strlen(strlentest1))
		printf("issue detected on test 1 (\"This\\tstring\\vis\\rfull\\aof\\bspecial\\echaracters\\n\"): check if there are issues on special characters\n");
	if((int)strlen(strlentest2) != (int)ft_strlen(strlentest2))
		printf("issue detected on test 2 (\"\"): empty string check\n");

}

void test_ft_strcpy()
{
	char strcpytest0[] = "13 chr string";//base test, nothing special
	char strcpytest1[] = "This\tstring\vis\rfull of\bspecial\echaracters\n";//check if there are issues on special characters
	char strcpytest2[] = "";//empty string check

	char strcpydest0[60];
	char strcpydest1[60];
	char strcpydest2[60];

	printf("EXPECTED RESULT (strcpy)\n");
	printf("%s \n",strcpy(strcpydest0,strcpytest0));
	printf("%s \n",strcpy(strcpydest1,strcpytest1));
	printf("%s \n",strcpy(strcpydest2,strcpytest2));

	char strcpydest3[60];
	char strcpydest4[60];
	char strcpydest5[60];
	printf("ACTUAL RESULT   (ft_strcpy)\n");
	printf("%s \n",strcpy(strcpydest3,strcpytest0));
	printf("%s \n",strcpy(strcpydest4,strcpytest1));
	printf("%s \n",strcpy(strcpydest5,strcpytest2));

	if(strcmp(strcpydest0,strcpydest3) != 0)
		printf("issue detected on test 0 (\"13 chr string\"): base test, nothing special\n");
	if(strcmp(strcpydest1,strcpydest4) != 0)
		printf("issue detected on test 1 (\"This\\tstring\\vis\\rfull of\\bspecial\\echaracters\\n\"): check if there are issues on special characters\n");
	if(strcmp(strcpydest2,strcpydest5) != 0)
		printf("issue detected on test 2 (\"\"): empty string check\n");
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (strcmp(av[1], "strlen") == 0 || strcmp(av[1], "ft_strlen") == 0)
			test_ft_strlen();
		else if (strcmp(av[1], "strcpy") == 0 || strcmp(av[1], "ft_strcpy") == 0)
			test_ft_strcpy();
	}
	return (0);
}
