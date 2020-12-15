#include "libft.h"
#include <stdio.h>
#include <string.h>

#define VERSION_NUMBER 2.0
#define TEST_MODULE "libft"

void	test_ft_memset()
{
	char TEST_NAME[] = "ft_memset test 1.0";
	int diff = 0;

	char memset_test0[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	char memset_test1[] = "XX\nXX\bXX\vX";
	char memset_test2[] = "XXXXX\0XXXX";
	char memset_control0[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	char memset_control1[] = "XX\nXX\bXX\vX";
	char memset_control2[] = "XXXXX\0XXXX";

	char *ctrl0 = memset(memset_control0,89,30);//standard check, nothing special
	//Memset throws a compiler warning on a empty string check so it's missing.
	char *ctrl1 = memset(memset_control1,89,10);//special char check
	char *ctrl2 = memset(memset_control2,89,10);//NULL char check
	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (memset)\n");
	printf("test0: %s \n",ctrl0);
	printf("test1: %s \n",ctrl1);
	printf("test2: %s \n\n",ctrl2);
	printf("ACTUAL RESULT   (ft_memset)\n");
	char *ctrl3 = ft_memset(memset_test0,89,30);//standard check, nothing special
	char *ctrl4 = ft_memset(memset_test1,89,10);//special char check
	char *ctrl5 = ft_memset(memset_test2,89,10);//NULL char check
	printf("test0: %s \n",ctrl3);
	printf("test1: %s \n",ctrl4);
	printf("test2: %s \n",ctrl5);

	if(strcmp(ctrl0,ctrl3) != 0){
		printf("issue detected on test 0 (\"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\",89,30):standard check, nothing special\n");
		diff = 1;}
	if(strcmp(ctrl1,ctrl4) != 0){
		printf("issue detected on test 1 (\"XX\\nXX\\bXX\\vX\",89,10): special char check\n");
		diff = 1;}
	if(strcmp(ctrl2,ctrl5) != 0){
		printf("issue detected on test 2 (\"XXXXX\\0XXXX\",89,10): NULL char check\n");
		diff = 1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}
void	test_ft_bzero()
{
	char TEST_NAME[] = "ft_bzero test 1.0";
	int diff = 0;

	char bzero_test0[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXOK";//standard check, nothing special
	char bzero_test1[] = "XX\nXX\bXX\vXOK";//special char check
	char bzero_test2[] = "XXXXX\0XXXXOK";//NULL char check
	char bzero_test3[] = "OK";//empty string check
	char bzero_control0[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXOK";//standard check, nothing special
	char bzero_control1[] = "XX\nXX\bXX\vXOK";//special char check
	char bzero_control2[] = "XXXXX\0XXXXOK";//NULL char check
	char bzero_control3[] = "OK";//empty string check

	int i = 0;
	//using memset with 0 as second param since bzero is a legacy function and
	//my compiler wont let me use it :(
	memset(bzero_control0,0,30);//standard check, nothing special
	memset(bzero_control1,0,10);//special char check
	memset(bzero_control2,0,10);//terminating char check
	memset(bzero_control3,0,0);//empty string check

	ft_bzero(bzero_test0,30);//standard check, nothing special
	ft_bzero(bzero_test1,10);//special char check
	ft_bzero(bzero_test2,10);//terminating char check
	ft_bzero(bzero_test3,0);//empty string check

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (bzero)\n");
	i=0;
	while(bzero_control0[i] == 0)
		i++;
	printf("test0: %c%c\n",bzero_control0[i],bzero_control0[i+1]);
	i=0;
	while(bzero_control1[i] == 0)
		i++;
	printf("test1: %c%c\n",bzero_control1[i],bzero_control1[i+1]);
	i=0;
	while(bzero_control2[i] == 0)
		i++;
	printf("test2: %c%c\n",bzero_control2[i],bzero_control2[i+1]);
	i=0;
	while(bzero_control3[i] == 0)
		i++;
	printf("test3: %c%c\n\n",bzero_control3[i],bzero_control3[i+1]);
	printf("ACTUAL RESULT   (ft_bzero)\n");
	i=0;
	while(bzero_test0[i] == 0)
		i++;
	printf("test0: %c%c\n",bzero_test0[i],bzero_test0[i+1]);
	i=0;
	while(bzero_test1[i] == 0)
		i++;
	printf("test1: %c%c\n",bzero_test1[i],bzero_test1[i+1]);
	i=0;
	while(bzero_test2[i] == 0)
		i++;
	printf("test2: %c%c\n",bzero_test2[i],bzero_test2[i+1]);
	i=0;
	while(bzero_test3[i] == 0)
		i++;
	printf("test3: %c%c\n",bzero_test3[i],bzero_test3[i+1]);

	if(strcmp(bzero_control0,bzero_test0) != 0){
		printf("issue detected on test 0 (\"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXOK\",30): standard check, nothing special\n");
		diff=1;}
	if(strcmp(bzero_control1,bzero_test1) != 0){
		printf("issue detected on test 1 (\"XX\\nXX\\bXX\\vXOK\",10): special char check\n");
		diff=1;}
	if(strcmp(bzero_control2,bzero_test2) != 0){
		printf("issue detected on test 2 (\"XXXXX\\0XXXXOK\",10): terminating char check\n");
		diff=1;}
	if(strcmp(bzero_control3,bzero_test3) == 0){
		printf("issue detected on test 2 (\"OK\",0): empty string check\n");
		diff=1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}
void	test_ft_memcpy()
{
	char TEST_NAME[] = "ft_memcpy test 1.0";
	int diff = 0;

	char memcpy_test0[] = "Just a regular old string here";//standard check
	char memcpy_test1[] = "Sp\necc\bia\vl";//special char check
	char memcpy_test2[] = "Termi\0nate";//NULL char check
	char memcpy_test3[] = "";//empty string check
	char memcpy_test_dest0[50] = {"                                                  "};
	char memcpy_test_dest1[50] = {"                                                  "};
	char memcpy_test_dest2[50] = {"                                                  "};
	char memcpy_test_dest3[50] = {"                                                  "};
	char memcpy_control0[] = "Just a regular old string here";
	char memcpy_control1[] = "Sp\necc\bia\vl";
	char memcpy_control2[] = "Termi\0nate";
	char memcpy_control3[] = "";
	char memcpy_control_dest0[50] = {"                                                  "};
	char memcpy_control_dest1[50] = {"                                                  "};
	char memcpy_control_dest2[50] = {"                                                  "};
	char memcpy_control_dest3[50] = {"                                                  "};

	memcpy(memcpy_control_dest0,memcpy_control0,31);
	memcpy(memcpy_control_dest1,memcpy_control1,12);
	memcpy(memcpy_control_dest2,memcpy_control2,11);
	memcpy(memcpy_control_dest3,memcpy_control3,1);

	ft_memcpy(memcpy_test_dest0,memcpy_test0,31);
	ft_memcpy(memcpy_test_dest1,memcpy_test1,12);
	ft_memcpy(memcpy_test_dest2,memcpy_test2,11);
	ft_memcpy(memcpy_test_dest3,memcpy_test3,1);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (memcpy)\n");
	printf("test0: %s \n",memcpy_control_dest0);
	printf("test1: %s \n",memcpy_control_dest1);
	printf("test2: %s%c%c%c%c%c \n",memcpy_control_dest2,memcpy_control_dest2[5],memcpy_control_dest2[6],memcpy_control_dest2[7],memcpy_control_dest2[8],memcpy_control_dest2[9]);
	printf("test3: %s\n\n",memcpy_control_dest3);
	printf("ACTUAL RESULT   (ft_memcpy)\n");
	printf("test0: %s \n",memcpy_test_dest0);
	printf("test1: %s \n",memcpy_test_dest1);
	printf("test2: %s%c%c%c%c%c \n",memcpy_test_dest2,memcpy_test_dest2[5],memcpy_test_dest2[6],memcpy_test_dest2[7],memcpy_test_dest2[8],memcpy_test_dest2[9]);
	printf("test3: %s \n",memcpy_test_dest3);

	if(strcmp(memcpy_control_dest0,memcpy_test_dest0) != 0){
		printf("issue detected on test 0 (dest,\"Just a regular old string here\",31): standard check, nothing special\n");
		diff=1;}
	if(strcmp(memcpy_control_dest1,memcpy_test_dest1) != 0){
		printf("issue detected on test 1 (dest,\"Sp\\necc\\bia\\vl\",11): special char check\n");
		diff=1;}
	if(strcmp(memcpy_control_dest2,memcpy_test_dest2) != 0){
		printf("issue detected on test 2 (dest,\"Termi\\0nate\",11): NULL char check\n");
		diff=1;}
	if(strcmp(memcpy_control_dest3,memcpy_test_dest3) != 0){
		printf("issue detected on test 3 (dest,\"\",1): empty string check\n");
		diff=1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}
void	test_ft_strlen()
{
	char TEST_NAME[] = "ft_strlen test 1.0";
	int diff = 0;

	char strlen_test0[] = "13 chr string";//standard check, nothing special
	char strlen_test1[] = "This\tstring\vis\rfull\aof\bspecial\echaracters\n";//special char check
	char strlen_test2[] = "";//empty string check

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strlen)\n");
	printf("test0: %d , ",(int)strlen(strlen_test0));
	printf("test1: %d , ",(int)strlen(strlen_test1));
	printf("test2: %d \n\n",(int)strlen(strlen_test2));

	printf("ACTUAL RESULT   (ft_strlen)\n");
	printf("test0: %d , ",(int)ft_strlen(strlen_test0));
	printf("test1: %d , ",(int)ft_strlen(strlen_test1));
	printf("test2: %d \n",(int)ft_strlen(strlen_test2));

	if((int)strlen(strlen_test0) != (int)ft_strlen(strlen_test0)){
		printf("issue detected on test 0 (\"13 chr string\"): base test, nothing special\n");
		diff=1;}
	if((int)strlen(strlen_test1) != (int)ft_strlen(strlen_test1)){
		printf("issue detected on test 1 (\"This\\tstring\\vis\\rfull\\aof\\bspecial\\echaracters\\n\"): check if there are issues on special characters\n");
		diff=1;}
	if((int)strlen(strlen_test2) != (int)ft_strlen(strlen_test2)){
		printf("issue detected on test 2 (\"\"): empty string check\n");
		diff=1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}
void	test_ft_strcpy()
{
	char TEST_NAME[] = "ft_strcpy test 1.0";
	int diff = 0;

	char strcpy_test0[] = "13 chr string";//standard check, nothing special
	char strcpy_test1[] = "This\tstring\vis\rfull of\bspecial\echaracters\n";//special char check
	char strcpy_test2[] = "";//empty string check

	char strcpy_dest0[60];
	char strcpy_dest1[60];
	char strcpy_dest2[60];

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strcpy)\n");
	printf("test0: %s \n",strcpy(strcpy_dest0,strcpy_test0));
	printf("test1: %s \n",strcpy(strcpy_dest1,strcpy_test1));
	printf("test2: %s \n\n",strcpy(strcpy_dest2,strcpy_test2));

	char strcpy_dest3[60];
	char strcpy_dest4[60];
	char strcpy_dest5[60];
	printf("ACTUAL RESULT   (ft_strcpy)\n");
	printf("test0: %s \n",strcpy(strcpy_dest3,strcpy_test0));
	printf("test1: %s \n",strcpy(strcpy_dest4,strcpy_test1));
	printf("test2: %s \n",strcpy(strcpy_dest5,strcpy_test2));

	if(strcmp(strcpy_dest0,strcpy_dest3) != 0){
		printf("issue detected on test 0 (\"13 chr string\"): base test, nothing special\n");
		diff=1;}
	if(strcmp(strcpy_dest1,strcpy_dest4) != 0){
		printf("issue detected on test 1 (\"This\\tstring\\vis\\rfull of\\bspecial\\echaracters\\n\"): check if there are issues on special characters\n");
		diff=1;}
	if(strcmp(strcpy_dest2,strcpy_dest5) != 0){
		printf("issue detected on test 2 (\"\"): empty string check\n");
		diff=1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (strcmp(av[1], "strlen") == 0 || strcmp(av[1], "ft_strlen") == 0)
			test_ft_strlen();
		else if (strcmp(av[1], "strcpy") == 0 || strcmp(av[1], "ft_strcpy") == 0)
			test_ft_strcpy();
		else if (strcmp(av[1], "memset") == 0 || strcmp(av[1], "ft_memset") == 0)
			test_ft_memset();
		else if (strcmp(av[1], "bzero") == 0 || strcmp(av[1], "ft_bzero") == 0)
			test_ft_bzero();
		else if (strcmp(av[1], "memcpy") == 0 || strcmp(av[1], "ft_memcpy") == 0)
			test_ft_memcpy();
	}
	return (0);
}
