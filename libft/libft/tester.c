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
	char TEST_NAME[] = "ft_memcpy test 1.1";
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

	char *return_test0 = ft_memcpy(memcpy_test_dest0,memcpy_test0,31);
	char *return_test1 = ft_memcpy(memcpy_test_dest1,memcpy_test1,12);
	char *return_test2 = ft_memcpy(memcpy_test_dest2,memcpy_test2,11);
	char *return_test3 = ft_memcpy(memcpy_test_dest3,memcpy_test3,1);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (memcpy)\n");
	printf("test0: %s \n",memcpy_control_dest0);
	printf("test1: %s \n",memcpy_control_dest1);
	printf("test2: %s%c%c%c%c%c \n",memcpy_control_dest2,memcpy_control_dest2[5],memcpy_control_dest2[6],memcpy_control_dest2[7],memcpy_control_dest2[8],memcpy_control_dest2[9]);
	printf("test3: %s\n\n",memcpy_control_dest3);
	printf("ACTUAL RESULT   (ft_memcpy)\n");
	printf("test0: %s \n",return_test0);
	printf("test1: %s \n",return_test1);
	printf("test2: %s%c%c%c%c%c \n",return_test2,return_test2[5],return_test2[6],return_test2[7],return_test2[8],return_test2[9]);
	printf("test3: %s \n",return_test3);

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
void	test_ft_memmove()
{
	char TEST_NAME[] = "ft_memmove test 1.0";
	int diff = 0;

	char memmove_test0[] = "Just a regular old string here";//standard check
	char memmove_test1[] = "Sp\necc\bia\vl";//special char check
	char memmove_test2[] = "Termi\0nate";//NULL char check
	char memmove_test3[] = "";//empty string check
	char memmove_test4[] = "0,1,2,3,4,5,6,7,8,9";//overlapping memory check
	char memmove_test_dest0[50] = {"                                                  "};
	char memmove_test_dest1[50] = {"                                                  "};
	char memmove_test_dest2[50] = {"                                                  "};
	char memmove_test_dest3[50] = {"                                                  "};
	char *memmove_test_dest4 = &memmove_test4[10];
	char memmove_control0[] = "Just a regular old string here";
	char memmove_control1[] = "Sp\necc\bia\vl";
	char memmove_control2[] = "Termi\0nate";
	char memmove_control3[] = "";
	char memmove_control4[] = "0,1,2,3,4,5,6,7,8,9";
	char memmove_control_dest0[50] = {"                                                  "};
	char memmove_control_dest1[50] = {"                                                  "};
	char memmove_control_dest2[50] = {"                                                  "};
	char memmove_control_dest3[50] = {"                                                  "};
	char *memmove_control_dest4 = &memmove_control4[10];

	memmove(memmove_control_dest0,memmove_control0,31);
	memmove(memmove_control_dest1,memmove_control1,12);
	memmove(memmove_control_dest2,memmove_control2,11);
	memmove(memmove_control_dest3,memmove_control3,1);
	memmove(memmove_control_dest4,memmove_control4,10);

	char *return_test0 = ft_memmove(memmove_test_dest0,memmove_test0,31);
	char *return_test1 = ft_memmove(memmove_test_dest1,memmove_test1,12);
	char *return_test2 = ft_memmove(memmove_test_dest2,memmove_test2,11);
	char *return_test3 = ft_memmove(memmove_test_dest3,memmove_test3,1);
	char *return_test4 = ft_memmove(memmove_test_dest4,memmove_test4,10);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (memmove)\n");
	printf("test0: %s \n",memmove_control_dest0);
	printf("test1: %s \n",memmove_control_dest1);
	printf("test2: %s%c%c%c%c%c \n",memmove_control_dest2,memmove_control_dest2[5],memmove_control_dest2[6],memmove_control_dest2[7],memmove_control_dest2[8],memmove_control_dest2[9]);
	printf("test3: %s \n",memmove_control_dest3);
	printf("test4: %s\n\n",memmove_control_dest4);
	printf("ACTUAL RESULT   (ft_memmove)\n");
	printf("test0: %s \n",return_test0);
	printf("test1: %s \n",return_test1);
	printf("test2: %s%c%c%c%c%c \n",return_test2,return_test2[5],return_test2[6],return_test2[7],return_test2[8],return_test2[9]);
	printf("test3: %s \n",return_test3);
	printf("test4: %s \n",memmove_test_dest4);

	if(strcmp(memmove_control_dest0,memmove_test_dest0) != 0){
		printf("issue detected on test 0 (dest,\"Just a regular old string here\",31): standard check, nothing special\n");
		diff=1;}
	if(strcmp(memmove_control_dest1,memmove_test_dest1) != 0){
		printf("issue detected on test 1 (dest,\"Sp\\necc\\bia\\vl\",11): special char check\n");
		diff=1;}
	if(strcmp(memmove_control_dest2,memmove_test_dest2) != 0){
		printf("issue detected on test 2 (dest,\"Termi\\0nate\",11): NULL char check\n");
		diff=1;}
	if(strcmp(memmove_control_dest3,memmove_test_dest3) != 0){
		printf("issue detected on test 3 (dest,\"\",1): empty string check\n");
		diff=1;}
	if(strcmp(memmove_control_dest4,memmove_test_dest4) != 0){
		printf("issue detected on test 4 (dest,\"\",1): overlapping memory check\n");
		diff=1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}
void	test_ft_memccpy()
{
	char TEST_NAME[] = "ft_memccpy test 1.1";
	int diff = 0;

	char memccpy_test0[] = "Just a regular old string here";//standard check
	char memccpy_test1[] = "Just a regular old string hereXKO";//standard check with stop
	char memccpy_test2[] = "Sp\necc\bia\vlXKO";//special char check
	char memccpy_test3[] = "Termi\0nateXKO";//NULL char check
	char memccpy_test4[] = "XKO";//sudden stop check
	char memccpy_test5[] = "";//empty string check
	char memccpy_test_dest0[50] = {"                                                  "};
	char memccpy_test_dest1[51] = {"                               \0                   "};
	char memccpy_test_dest2[50] = {"            \0                                     "};
	char memccpy_test_dest3[50] = {"           \0                                      "};
	char memccpy_test_dest4[50] = {" \0                                                "};
	char memccpy_test_dest5[50] = {" \0                                                "};
	char memccpy_control0[] = "Just a regular old string here";
	char memccpy_control1[] = "Just a regular old string hereXKO";
	char memccpy_control2[] = "Sp\necc\bia\vlXKO";
	char memccpy_control3[] = "Termi\0nateXKO";
	char memccpy_control4[] = "XKO";
	char memccpy_control5[] = "";
	char memccpy_control_dest0[50] = {"                                                  "};
	char memccpy_control_dest1[51] = {"                               \0                   "};
	char memccpy_control_dest2[50] = {"            \0                                     "};
	char memccpy_control_dest3[50] = {"           \0                                      "};
	char memccpy_control_dest4[50] = {" \0                                                "};
	char memccpy_control_dest5[50] = {" \0                                                "};

	char *return_control0 = memccpy(memccpy_control_dest0,memccpy_control0,88,31);
	char *return_control1 = memccpy(memccpy_control_dest1,memccpy_control1,88,34);
	char *return_control2 = memccpy(memccpy_control_dest2,memccpy_control2,88,15);
	char *return_control3 = memccpy(memccpy_control_dest3,memccpy_control3,88,14);
	char *return_control4 = memccpy(memccpy_control_dest4,memccpy_control4,88,4);
	char *return_control5 = memccpy(memccpy_control_dest5,memccpy_control5,88,1);

	char *return_test0 = ft_memccpy(memccpy_test_dest0,memccpy_test0,88,31);
	char *return_test1 = ft_memccpy(memccpy_test_dest1,memccpy_test1,88,34);
	char *return_test2 = ft_memccpy(memccpy_test_dest2,memccpy_test2,88,15);
	char *return_test3 = ft_memccpy(memccpy_test_dest3,memccpy_test3,88,14);
	char *return_test4 = ft_memccpy(memccpy_test_dest4,memccpy_test4,88,4);
	char *return_test5 = ft_memccpy(memccpy_test_dest5,memccpy_test5,88,1);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (memccpy)\n");
	printf("test0: %s    return value: %s\n",memccpy_control_dest0,return_control0);
	printf("test1: %s   return value: %d\n",memccpy_control_dest1,*return_control1);
	printf("test2: %s                                  return value: %d\n",memccpy_control_dest2,*return_control2);
	printf("test3: %s%c%c%c%c%c                        return value: %d\n",memccpy_control_dest3,memccpy_control_dest3[5],memccpy_control_dest3[6],memccpy_control_dest3[7],memccpy_control_dest3[8],memccpy_control_dest3[9],*return_control3);
	printf("test4: %s                                 return value: %d\n",memccpy_control_dest4,*return_control4);
	printf("test5: %s                                  return value: %s\n\n",memccpy_control_dest5,return_control5);
	printf("ACTUAL RESULT   (ft_memccpy)\n");
	printf("test0: %s    return value: %s\n",memccpy_test_dest0,return_test0);
	printf("test1: %s   return value: %d\n",memccpy_test_dest1,*return_test1);
	printf("test2: %s                                  return value: %d\n",memccpy_test_dest2,*return_test2);
	printf("test3: %s%c%c%c%c%c                        return value: %d\n",memccpy_test_dest3,memccpy_test_dest3[5],memccpy_test_dest3[6],memccpy_test_dest3[7],memccpy_test_dest3[8],memccpy_test_dest3[9],*return_test3);
	printf("test4: %s                                 return value: %d\n",memccpy_test_dest4,*return_test4);
	printf("test5: %s                                  return value: %s\n",memccpy_test_dest5,return_test5);

	if(strcmp(memccpy_control_dest0,memccpy_test_dest0) != 0 || return_control0 != return_test0){
		printf("issue detected on test 0 (dest,\"Just a regular old string here\",88,31): standard check, nothing special\n");
		diff=1;}
	if(strcmp(memccpy_control_dest1,memccpy_test_dest1) != 0 || *return_control1 != *return_test1){
		printf("issue detected on test 1 (dest,\"Just a regular old string hereX KO\",88,35): standard check with stop\n");
		diff=1;}
	if(strcmp(memccpy_control_dest2,memccpy_test_dest2) != 0 || *return_control2 != *return_test2){
		printf("issue detected on test 2 (dest,\"Sp\\necc\\bia\\vlX KO\",88,16): special char check\n");
		diff=1;}
	if(strcmp(memccpy_control_dest3,memccpy_test_dest3) != 0 || *return_control3 != *return_test3){
		printf("issue detected on test 3 (dest,\"Termi\\0nateX KO\",88,15): NULL char check\n");
		diff=1;}
	if(strcmp(memccpy_control_dest4,memccpy_test_dest4) != 0 || *return_control4 != *return_test4){
		printf("issue detected on test 4 (dest,\"X KO\",88,5): sudden stop check\n");
		diff=1;}
	if(strcmp(memccpy_control_dest5,memccpy_test_dest5) != 0 || return_control5 != return_test5){
		printf("issue detected on test 5 (dest,\"\",88,1): empty string check\n");
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
	printf("test0: %s \n",ft_strcpy(strcpy_dest3,strcpy_test0));
	printf("test1: %s \n",ft_strcpy(strcpy_dest4,strcpy_test1));
	printf("test2: %s \n",ft_strcpy(strcpy_dest5,strcpy_test2));

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
		if (strcmp(av[1], "memset") == 0 || strcmp(av[1], "ft_memset") == 0)
			test_ft_memset();
		else if (strcmp(av[1], "bzero") == 0 || strcmp(av[1], "ft_bzero") == 0)
			test_ft_bzero();
		else if (strcmp(av[1], "memcpy") == 0 || strcmp(av[1], "ft_memcpy") == 0)
			test_ft_memcpy();
		else if (strcmp(av[1], "memccpy") == 0 || strcmp(av[1], "ft_memccpy") == 0)
			test_ft_memccpy();
		else if (strcmp(av[1], "memmove") == 0 || strcmp(av[1], "ft_memmove") == 0)
			test_ft_memmove();
		else if (strcmp(av[1], "strlen") == 0 || strcmp(av[1], "ft_strlen") == 0)
			test_ft_strlen();
		else if (strcmp(av[1], "strcpy") == 0 || strcmp(av[1], "ft_strcpy") == 0)
			test_ft_strcpy();
	}
	return (0);
}
