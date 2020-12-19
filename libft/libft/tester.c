#include "libft.h"
#include <stdio.h>
#include <ctype.h>

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
	printf("test4: %s \n",return_test4);

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
void	test_ft_memchr()
{
	char TEST_NAME[] = "ft_memchr test 1.0";
	int diff = 0;

	char memchr_test0[] = "Just a regular old string here";//standard check
	char memchr_test1[] = "Sp\necc\bia\vl";//special char check
	char memchr_test2[] = "Termi\0nate";//NULL char check
	char memchr_test3[] = "asdfghjkl";//missing char check

	char memchr_control0[] = "Just a regular old string here";
	char memchr_control1[] = "Sp\necc\bia\vl";
	char memchr_control2[] = "Termi\0nate";
	char memchr_control3[] = "asdfghjkl";

	char *return_control0 = memchr(memchr_control0,'h',31);
	char *return_control1 = memchr(memchr_control1,'l',12);
	char *return_control2 = memchr(memchr_control2,'n',11);
	char *return_control3 = memchr(memchr_control3,'q',10);

	char *return_test0 = ft_memchr(memchr_test0,'h',31);
	char *return_test1 = ft_memchr(memchr_test1,'l',12);
	char *return_test2 = ft_memchr(memchr_test2,'n',11);
	char *return_test3 = ft_memchr(memchr_test3,'q',10);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (memchr)\n");
	printf("test0: %s \n",return_control0);
	printf("test1: %s \n",return_control1);
	printf("test2: %s \n",return_control2);
	printf("test3: %s \n",return_control3);
	printf("ACTUAL RESULT   (ft_memchr)\n");
	printf("test0: %s \n",return_test0);
	printf("test1: %s \n",return_test1);
	printf("test2: %s \n",return_test2);
	printf("test3: %s \n",return_test3);

	if(strcmp(return_control0,return_test0) != 0){
		printf("issue detected on test 0 (dest,\"Just a regular old string here\",31): standard check, nothing special\n");
		diff=1;}
	if(strcmp(return_control1,return_test1) != 0){
		printf("issue detected on test 1 (dest,\"Sp\\necc\\bia\\vl\",11): special char check\n");
		diff=1;}
	if(strcmp(return_control2,return_test2) != 0){
		printf("issue detected on test 2 (dest,\"Termi\\0nate\",11): NULL char check\n");
		diff=1;}
	if(return_control3 != return_test3){
		printf("issue detected on test 3 (dest,\"asdfghjkl\",11): missing char check\n");
		diff=1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}
void	test_ft_memcmp()
{
	char TEST_NAME[] = "ft_memcmp test 1.0";
	int diff = 0;

	char memcmp_test0[] = "Just a regular old string here";//standard check
	char memcmp_test1[] = "Sp\necc\bia\vl";//special char check
	char memcmp_test2[] = "Termi\0nate";//NULL char check
	char memcmp_test3[] = "";//empty check

	char memcmp_control0[] = "Just a regular old string here";
	char memcmp_control1[] = "Sp\necc\bia\vl";
	char memcmp_control2[] = "Termi\0nate";
	char memcmp_control3[] = "";

	int	return_control0 = memcmp(memcmp_control0,memcmp_test0,31);//standard check
	int	return_control1 = memcmp(memcmp_control1,memcmp_test1,12);//special char check
	int	return_control2 = memcmp(memcmp_control2,memcmp_test2,11);//NULL char check
	int	return_control3 = memcmp(memcmp_control3,memcmp_test3,0);//empty check
	int	return_control4 = memcmp(memcmp_control0,memcmp_test2,11);//diff check 0
	int	return_control5 = memcmp(memcmp_control1,memcmp_test0,12);//diff check 1
	int	return_control6 = memcmp(memcmp_control2,memcmp_test3,1);//diff check 2
	int	return_control7 = memcmp(memcmp_control3,memcmp_test1,1);//diff check 3

	int	return_test0 = ft_memcmp(memcmp_control0,memcmp_test0,31);
	int	return_test1 = ft_memcmp(memcmp_control1,memcmp_test1,12);
	int	return_test2 = ft_memcmp(memcmp_control2,memcmp_test2,11);
	int	return_test3 = ft_memcmp(memcmp_control3,memcmp_test3,0);
	int	return_test4 = ft_memcmp(memcmp_control0,memcmp_test2,11);
	int	return_test5 = ft_memcmp(memcmp_control1,memcmp_test0,12);
	int	return_test6 = ft_memcmp(memcmp_control2,memcmp_test3,1);
	int	return_test7 = ft_memcmp(memcmp_control3,memcmp_test1,1);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (memcmp)\n");
	printf("test0: %d \n",return_control0);
	printf("test1: %d \n",return_control1);
	printf("test2: %d \n",return_control2);
	printf("test3: %d \n",return_control3);
	printf("test4: %d   (or any negative value)\n",return_control4);
	printf("test5: %d    (or any positive value)\n",return_control5);
	printf("test6: %d   (or any positive value)\n",return_control6);
	printf("test7: %d  (or any negative value)\n",return_control7);
	printf("ACTUAL RESULT   (ft_memcmp)\n");
	printf("test0: %d \n",return_test0);
	printf("test1: %d \n",return_test1);
	printf("test2: %d \n",return_test2);
	printf("test3: %d \n",return_test3);
	printf("test4: %d  (any negative value)\n",return_test4);
	printf("test5: %d    (any positive value)\n",return_test5);
	printf("test6: %d   (any positive value)\n",return_test6);
	printf("test7: %d  (any negative value)\n",return_test7);

	if(return_control0 != return_test0){
		printf("issue detected on test 0 (\"Just a regular old string here\",\"Just a regular old string here\",31): standard check, nothing special\n");
		diff=1;}
	if(return_control1 != return_test1){
		printf("issue detected on test 1 (\"Sp\\necc\\bia\\vl\",\"Sp\\necc\\bia\\vl\",12): special char check\n");
		diff=1;}
	if(return_control2 != return_test2){
		printf("issue detected on test 2 (\"Termi\\0nate\",\"Termi\\0nate\",11): NULL char check\n");
		diff=1;}
	if(return_control3 != return_test3){
		printf("issue detected on test 3 (\"\",\"\",0): empty check\n");
		diff=1;}
	if(0 < return_test4){
		printf("issue detected on test 4 (\"Just a regular old string here\",\"Termi\\0nate\",11): diff check\n");
		diff=1;}
	if(0 > return_test5){
		printf("issue detected on test 5 (\"Sp\\necc\\bia\\vl\",\"Just a regular old string here\",12): diff check\n");
		diff=1;}
	if(0 > return_test6){
		printf("issue detected on test 6 (\"Termi\\0nate\",\"\",1): diff check\n");
		diff=1;}
	if(0 <  return_test7){
		printf("issue detected on test 7 (\"\",\"Sp\\necc\\bia\\vl\",1): diff check\n");
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
void	test_ft_strdup()
{
	char TEST_NAME[] = "ft_strdup test 1.0";
	int diff = 0;

	char strdup_test0[] = "13 chr string";//standard check, nothing special
	char strdup_test1[] = "This\tstring\vis\"full\fof\bspecial\echaracters\n";//special char check
	char strdup_test2[] = "Termi\0nate";//NULL char check
	char strdup_test3[] = "";//empty string check

	char *return_control0 = strdup(strdup_test0);
	char *return_control1 = strdup(strdup_test1);
	char *return_control2 = strdup(strdup_test2);
	char *return_control3 = strdup(strdup_test3);

	char *return_test0 = ft_strdup(strdup_test0);
	char *return_test1 = ft_strdup(strdup_test1);
	char *return_test2 = ft_strdup(strdup_test2);
	char *return_test3 = ft_strdup(strdup_test3);


	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strdup)\n");
	printf("test0: %s \n",return_control0);
	printf("test1: %s",return_control1);
	printf("test2: %s \n",return_control2);
	printf("test3: %s \n\n",return_control3);

	printf("ACTUAL RESULT   (ft_strdup)\n");
	printf("test0: %s \n",return_test0);
	printf("test1: %s",return_test1);
	printf("test2: %s \n",return_test2);
	printf("test3: %s \n",return_test3);

	if(strcmp(return_control0,return_test0) != 0){
		printf("issue detected on test 0 (\"13 chr string\"): base test, nothing special\n");
		diff=1;}
	if(strcmp(return_control1,return_test1) != 0){
		printf("issue detected on test 1 (\"This\\tstring\\vis\\rfull\\aof\\bspecial\\echaracters\\n\"): check if there are issues on special characters\n");
		diff=1;}
	if(strcmp(return_control2,return_test2) != 0){
		printf("issue detected on test 2 (\"Termi\\0nate\"): NULL char check\n");
		diff=1;}
	if(strcmp(return_control3,return_test3) != 0){
		printf("issue detected on test 3 (\"\"): empty string check\n");
		diff=1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}
void	test_ft_strcpy()
{
	char TEST_NAME[] = "ft_strcpy test 1.0";
	int diff = 0;

	char strcpy_test0[] = "13 chr string";//standard check, nothing special
	char strcpy_test1[] = "This\tstring\vis\ffull of\bspecial\echaracters\n";//special char check
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
		printf("issue detected on test 1 (\"This\\tstring\\vis\\ffull of\\bspecial\\echaracters\\n\"): check if there are issues on special characters\n");
		diff=1;}
	if(strcmp(strcpy_dest2,strcpy_dest5) != 0){
		printf("issue detected on test 2 (\"\"): empty string check\n");
		diff=1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}
void	test_ft_strncpy()
{
	char TEST_NAME[] = "ft_strncpy test 1.0";
	int diff = 0;

	char strncpy_test0[] = "13 chr string";//standard check, nothing special
	char strncpy_test1[] = "This\tstring\vis\ffull of\bspecial\echaracters\n";//special char check
	char strncpy_test2[] = "";//empty string check
	char strncpy_test3[] = "This string is too long and will be truncated";//string too long check

	char strncpy_dest0[60];
	char strncpy_dest1[60];
	char strncpy_dest2[60];
	char strncpy_dest3[60] = "This string is too long\0                    ";

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strncpy)\n");
	printf("test0: %s \n",strncpy(strncpy_dest0,strncpy_test0,14));
	printf("test1: %s",strncpy(strncpy_dest1,strncpy_test1,43));
	printf("test2: %s \n",strncpy(strncpy_dest2,strncpy_test2,1));
	printf("test3: This string is too long \n\n");//have to hard code the result to avoid compiler warning
												  //(it will warn you about the truncation)

	char strncpy_dest4[60];
	char strncpy_dest5[60];
	char strncpy_dest6[60];
	char strncpy_dest7[60] = "                       \0                    ";
	printf("ACTUAL RESULT   (ft_strncpy)\n");
	printf("test0: %s \n",ft_strncpy(strncpy_dest4,strncpy_test0,14));
	printf("test1: %s",ft_strncpy(strncpy_dest5,strncpy_test1,43));
	printf("test2: %s \n",ft_strncpy(strncpy_dest6,strncpy_test2,1));
	printf("test3: %s \n\n",ft_strncpy(strncpy_dest7,strncpy_test3,23));

	if(strcmp(strncpy_dest0,strncpy_dest4) != 0){
		printf("issue detected on test 0 (dest,\"13 chr string\",14): base test, nothing special\n");
		diff=1;}
	if(strcmp(strncpy_dest1,strncpy_dest5) != 0){
		printf("issue detected on test 1 (dest,\"This\\tstring\\vis\\ffull of\\bspecial\\echaracters\\n\",43): check if there are issues on special characters\n");
		diff=1;}
	if(strcmp(strncpy_dest2,strncpy_dest6) != 0){
		printf("issue detected on test 2 (dest,\"\",1): empty string check\n");
		diff=1;}
	if(strcmp(strncpy_dest3,strncpy_dest7) != 0){
		printf("issue detected on test 3 (dest,\"This string is too long and will be truncated\",23): truncation check\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_strcat()
{
	char TEST_NAME[] = "ft_strcat test 1.0";
	int diff = 0;

	char strcat_test0[] = "13 chr string";//standard check, nothing special
	char strcat_test1[] = "This\tstring\vis\ffull of\bspecial\echaracters\n";//special char check
	char strcat_test2[] = "";//empty string check

	char strcat_dest0[60] = {"Destination. "};
	char strcat_dest1[60] = {"Destination. "};
	char strcat_dest2[60] = {"Destination. "};

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strcat)\n");
	printf("test0: %s \n",strcat(strcat_dest0,strcat_test0));
	printf("test1: %s",strcat(strcat_dest1,strcat_test1));
	printf("test2: %s \n\n",strcat(strcat_dest2,strcat_test2));

	char strcat_dest4[60] = {"Destination. "};
	char strcat_dest5[60] = {"Destination. "};
	char strcat_dest6[60] = {"Destination. "};

	printf("ACTUAL RESULT   (ft_strcat)\n");
	printf("test0: %s \n",ft_strcat(strcat_dest4,strcat_test0));
	printf("test1: %s",ft_strcat(strcat_dest5,strcat_test1));
	printf("test2: %s \n\n",ft_strcat(strcat_dest6,strcat_test2));

	if(strcmp(strcat_dest0,strcat_dest4) != 0){
		printf("issue detected on test 0 (dest,\"13 chr string\"): base test, nothing special\n");
		diff=1;}
	if(strcmp(strcat_dest1,strcat_dest5) != 0){
		printf("issue detected on test 1 (dest,\"This\\tstring\\vis\\ffull of\\bspecial\\echaracters\\n\"): check if there are issues on special characters\n");
		diff=1;}
	if(strcmp(strcat_dest2,strcat_dest6) != 0){
		printf("issue detected on test 2 (dest,\"\",1): empty string check\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_strncat()
{
	char TEST_NAME[] = "ft_strncat test 1.0";
	int diff = 0;

	char strncat_test0[] = "13 chr string";//standard check, nothing special
	char strncat_test1[] = "This\tstring\vis\ffull of\bspecial\echaracters\n";//special char check
	char strncat_test2[] = "";//empty string check
	char strncat_test3[] = "Truncation";//Truncation check

	char strncat_dest0[60] = {"Destination. "};
	char strncat_dest1[60] = {"Destination. "};
	char strncat_dest2[60] = {"Destination. "};
	char strncat_dest3[60] = {"Destination. Trunc"};

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strncat)\n");
	printf("test0: %s \n",strncat(strncat_dest0,strncat_test0,14));
	printf("test1: %s",strncat(strncat_dest1,strncat_test1,43));
	printf("test2: %s \n",strncat(strncat_dest2,strncat_test2,1));
	printf("test3: Destination. Trunc \n\n");//hard coded to avoid compiler warning.

	char strncat_dest4[60] = {"Destination. "};
	char strncat_dest5[60] = {"Destination. "};
	char strncat_dest6[60] = {"Destination. "};
	char strncat_dest7[60] = {"Destination. "};

	printf("ACTUAL RESULT   (ft_strncat)\n");
	printf("test0: %s \n",ft_strncat(strncat_dest4,strncat_test0,14));
	printf("test1: %s",ft_strncat(strncat_dest5,strncat_test1,43));
	printf("test2: %s \n",ft_strncat(strncat_dest6,strncat_test2,1));
	printf("test3: %s \n\n",ft_strncat(strncat_dest7,strncat_test3,5));

	if(strcmp(strncat_dest0,strncat_dest4) != 0){
		printf("issue detected on test 0 (dest,\"13 chr string\",14): base test, nothing special\n");
		diff=1;}
	if(strcmp(strncat_dest1,strncat_dest5) != 0){
		printf("issue detected on test 1 (dest,\"This\\tstring\\vis\\ffull of\\bspecial\\echaracters\\n\",43): check if there are issues on special characters\n");
		diff=1;}
	if(strcmp(strncat_dest2,strncat_dest6) != 0){
		printf("issue detected on test 2 (dest,\"\",1): empty string check\n");
		diff=1;}
	if(strcmp(strncat_dest3,strncat_dest7) != 0){
		printf("issue detected on test 2 (dest,\"Truncation\",5): Truncation check\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_strlcat()
{
	char TEST_NAME[] = "ft_strlcat test 1.0";
	int diff = 0;

	char strlcat_test0[] = "13 chr string";//standard check, nothing special
	char strlcat_test1[] = "This\tstring\vis\ffull of\bspecial\echaracters\n";//special char check
	char strlcat_test2[] = "";//empty string check
	char strlcat_test3[] = "Truncation";//Truncation check

	char strlcat_dest0[60] = {"Destination. 13 chr string"};
	char strlcat_dest1[60] = {"Destination. This\tstring\vis\ffull of\bspecial\echaracters\n"};
	char strlcat_dest2[60] = {"Destination. "};
	char strlcat_dest3[60] = {"Destination. Trunc"};

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strlcat)\n");
	printf("test0: return: 39, Destination. 13 chr string\n");
	printf("test1: return: 97, Destination. This\tstring\vis\ffull of\bspecial\echaracters\n");
	printf("test2: return: 13, Destination. \n");
	printf("test3: return: 28, Destination. Trunc\n\n");//all hardcoded cause my windows version does not have strlcat

	char strlcat_dest4[60] = {"Destination. "};
	char strlcat_dest5[60] = {"Destination. "};
	char strlcat_dest6[60] = {"Destination. "};
	char strlcat_dest7[60] = {"Destination. "};

	size_t return_test0 = ft_strlcat(strlcat_dest4,strlcat_test0,28);
	size_t return_test1 = ft_strlcat(strlcat_dest5,strlcat_test1,57);
	size_t return_test2 = ft_strlcat(strlcat_dest6,strlcat_test2,14);
	size_t return_test3 = ft_strlcat(strlcat_dest7,strlcat_test3,20);

	printf("ACTUAL RESULT   (ft_strlcat)\n");
	printf("test0: return: %I64u, %s\n",return_test0,strlcat_dest4);
	printf("test1: return: %I64u, %s",return_test1,strlcat_dest5);
	printf("test2: return: %I64u, %s\n",return_test2,strlcat_dest6);
	printf("test3: return: %I64u, %s\n\n",return_test3,strlcat_dest7);

	if(strcmp(strlcat_dest0,strlcat_dest4) != 0){
		printf("issue detected on test 0 (dest,\"13 chr string\",14): base test, nothing special\n");
		diff=1;}
	if(strcmp(strlcat_dest1,strlcat_dest5) != 0){
		printf("issue detected on test 1 (dest,\"This\\tstring\\vis\\ffull of\\bspecial\\echaracters\\n\",43): check if there are issues on special characters\n");
		diff=1;}
	if(strcmp(strlcat_dest2,strlcat_dest6) != 0){
		printf("issue detected on test 2 (dest,\"\",1): empty string check\n");
		diff=1;}
	if(strcmp(strlcat_dest3,strlcat_dest7) != 0){
		printf("issue detected on test 2 (dest,\"Truncation\",5): Truncation check\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_strchr()
{
	char TEST_NAME[] = "ft_strchr test 1.0";
	int diff = 0;

	char strchr_test0[] = "13 chr string";//standard check, nothing special
	char strchr_test1[] = "This\tstring\vis\ffull of\bspecial\eCharacters\n";//special char check
	char strchr_test2[] = "";//empty string check
	char strchr_test3[] = "This are not the characters you are looking for";//nothing to find check

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strchr)\n");
	printf("test0: %s\n",strchr(strchr_test0,'s'));
	printf("test1: %s",strchr(strchr_test1,'C'));
	printf("test2: %s\n",strchr(strchr_test2,'s'));
	printf("test3: %s\n\n",strchr(strchr_test3,'z'));

	printf("ACTUAL RESULT   (ft_strchr)\n");
	printf("test0: %s\n",ft_strchr(strchr_test0,'s'));
	printf("test1: %s",ft_strchr(strchr_test1,'C'));
	printf("test2: %s\n",ft_strchr(strchr_test2,'s'));
	printf("test3: %s\n\n",ft_strchr(strchr_test3,'z'));

	if(*strchr(strchr_test0,'s') != *ft_strchr(strchr_test0,'s')){
		printf("issue detected on test 0 (\"13 chr string\",'s'): base test, nothing special\n");
		diff=1;}
	if(*strchr(strchr_test1,'h') != *ft_strchr(strchr_test1,'h')){
		printf("issue detected on test 1 (\"This\\tstring\\vis\\ffull of\\bspecial\\eCharacters\\n\",'C'): check if there are issues on special characters\n");
		diff=1;}
	if(strchr(strchr_test2,'s') != ft_strchr(strchr_test2,'s')){
		printf("issue detected on test 2 (\"\",'s'): empty string check\n");
		diff=1;}
	if(strchr(strchr_test3,'z') != ft_strchr(strchr_test3,'z')){
		printf("issue detected on test 3 (\"This are not the characters you are looking for\",'z'): nothing to find check\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_strrchr()
{
	char TEST_NAME[] = "ft_strrchr test 1.0";
	int diff = 0;

	char strrchr_test0[] = "13 chr string";//standard check, nothing special
	char strrchr_test1[] = "This\tstring\vis\ffull of\bspecial\echaracters\n";//special char check
	char strrchr_test2[] = "";//empty string check
	char strrchr_test3[] = "This are not the characters you are looking for";//nothing to find check

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strrchr)\n");
	printf("test0: %s\n",strrchr(strrchr_test0,'r'));
	printf("test1: %s",strrchr(strrchr_test1,'c'));
	printf("test2: %s\n",strrchr(strrchr_test2,'s'));
	printf("test3: %s\n\n",strrchr(strrchr_test3,'z'));

	printf("ACTUAL RESULT   (ft_strrchr)\n");
	printf("test0: %s\n",ft_strrchr(strrchr_test0,'r'));
	printf("test1: %s",ft_strrchr(strrchr_test1,'c'));
	printf("test2: %s\n",ft_strrchr(strrchr_test2,'s'));
	printf("test3: %s\n\n",ft_strrchr(strrchr_test3,'z'));

	if(*strrchr(strrchr_test0,'r') != *ft_strrchr(strrchr_test0,'r')){
		printf("issue detected on test 0 (\"13 chr string\",'r'): base test, nothing special\n");
		diff=1;}
	if(*strrchr(strrchr_test1,'c') != *ft_strrchr(strrchr_test1,'c')){
		printf("issue detected on test 1 (\"This\\tstring\\vis\\ffull of\\bspecial\\eCharacters\\n\",'c'): check if there are issues on special characters\n");
		diff=1;}
	if(strrchr(strrchr_test2,'s') != ft_strrchr(strrchr_test2,'s')){
		printf("issue detected on test 2 (\"\",'s'): empty string check\n");
		diff=1;}
	if(strrchr(strrchr_test3,'z') != ft_strrchr(strrchr_test3,'z')){
		printf("issue detected on test 3 (\"This are not the characters you are looking for\",'z'): nothing to find check\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_strstr()
{
	char TEST_NAME[] = "ft_strstr test 1.0";
	int diff = 0;

	char strstr_test0[] = "13 chr string";//standard check, nothing special
	char strstr_test1[] = "This\tstring\vis\ffull of\bspecial\echaracters\n";//special char check
	char strstr_test2[] = "";//empty string check
	char strstr_test3[] = "This are not the characters you are looking for";//nothing to find check
	char strstr_test4[] = "Haystack";//no input check

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strstr)\n");
	printf("test0: %s\n",strstr(strstr_test0,"str"));
	printf("test1:  %s",strstr(strstr_test1,"\bspecial\ech"));
	printf("test2: %s\n",strstr(strstr_test2,"something"));
	printf("test3: %s\n",strstr(strstr_test3,"droids"));
	printf("test4: %s\n\n",strstr(strstr_test4,""));

	printf("ACTUAL RESULT   (ft_strstr)\n");
	printf("test0: %s\n",ft_strstr(strstr_test0,"str"));
	printf("test1:  %s",ft_strstr(strstr_test1,"\bspecial\ech"));
	printf("test2: %s\n",ft_strstr(strstr_test2,"something"));
	printf("test3: %s\n",ft_strstr(strstr_test3,"droids"));
	printf("test4: %s\n\n",ft_strstr(strstr_test4,""));

	if(*strstr(strstr_test0,"str") != *ft_strstr(strstr_test0,"str")){
		printf("issue detected on test 0 (\"13 chr string\",\"str\"): base test, nothing special\n");
		diff=1;}
	if(*strstr(strstr_test1,"\bspecial\ech") != *ft_strstr(strstr_test1,"\bspecial\ech")){
		printf("issue detected on test 1 (\"This\\tstring\\vis\\ffull of\\bspecial\\eCharacters\\n\",\"\\bspecial\\ech\"): check if there are issues on special characters\n");
		diff=1;}
	if(strstr(strstr_test2,"something") != ft_strstr(strstr_test2,"something")){
		printf("issue detected on test 2 (\"\",\"something\"): empty string check\n");
		diff=1;}
	if(strstr(strstr_test3,"droids") != ft_strstr(strstr_test3,"droids")){
		printf("issue detected on test 3 (\"This are not the characters you are looking for\",\"droids\"): nothing to find check\n");
		diff=1;}
	if(strstr(strstr_test4,"") != ft_strstr(strstr_test4,"")){
		printf("issue detected on test 4 (\"Haystack\",\"\"): no input check\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_strnstr()
{
	char TEST_NAME[] = "ft_strnstr test 1.0";
	int diff = 0;

	char strnstr_test0[] = "13 chr string";//standard check, nothing special
	char strnstr_test1[] = "This\tstring\vis\ffull of\bspecial\echaracters\n";//special char check
	char strnstr_test2[] = "";//empty string check
	char strnstr_test3[] = "This are not the characters you are looking for";//nothing to find check
	char strnstr_test4[] = "Haystack";//empty needle check
	char strnstr_test5[] = "This string is too long needle";//not in range check
	char strnstr_test6[] = "n is zero";//n = 0 check

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strnstr)\n");
	printf("test0: string\n");
	printf("test1:  \bspecial\echaracters\n");
	printf("test2: (null)\n");
	printf("test3: (null)\n");
	printf("test4: Haystack\n");
	printf("test5: (null)\n");
	printf("test6: (null)\n\n");//all hardcoded because my windows version does not have strnstr

	printf("ACTUAL RESULT   (ft_strnstr)\n");
	printf("test0: %s\n",ft_strnstr(strnstr_test0,"str",13));
	printf("test1:  %s",ft_strnstr(strnstr_test1,"\bspecial\ech",50));
	printf("test2: %s\n",ft_strnstr(strnstr_test2,"something",15));
	printf("test3: %s\n",ft_strnstr(strnstr_test3,"droids",50));
	printf("test4: %s\n",ft_strnstr(strnstr_test4,"",15));
	printf("test5: %s\n",ft_strnstr(strnstr_test5,"needle",29));
	printf("test6: %s\n\n",ft_strnstr(strnstr_test6,"zero",0));

	if('s' != *ft_strnstr(strnstr_test0,"str",13)){
		printf("issue detected on test 0 (\"13 chr string\",\"str\",13): base test, nothing special\n");
		diff=1;}
	if('\b' != *ft_strnstr(strnstr_test1,"\bspecial\ech",50)){
		printf("issue detected on test 1 (\"This\\tstring\\vis\\ffull of\\bspecial\\eCharacters\\n\",\"\\bspecial\\ech\",50): check if there are issues on special characters\n");
		diff=1;}
	if(NULL != ft_strnstr(strnstr_test2,"something",15)){
		printf("issue detected on test 2 (\"\",\"something\",15): empty string check\n");
		diff=1;}
	if(NULL != ft_strnstr(strnstr_test3,"droids",50)){
		printf("issue detected on test 3 (\"This are not the characters you are looking for\",\"droids\",50): nothing to find check\n");
		diff=1;}
	if('H' != *ft_strnstr(strnstr_test4,"",15)){
		printf("issue detected on test 4 (\"Haystack\",\"\",15): no input check\n");
		diff=1;}
	if(NULL != ft_strnstr(strnstr_test4,"needle",29)){
		printf("issue detected on test 5 (\"This string is too long needle\",\"needle\",29): no input check\n");
		diff=1;}
	if(NULL != ft_strnstr(strnstr_test4,"zero",0)){
		printf("issue detected on test 6 (\"n is zero\",\"zero\",0): no input check\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_strcmp()
{
	char TEST_NAME[] = "ft_strcmp test 1.0";
	int diff = 0;

	char strcmp_test0[] = "Just a regular old string here";//standard check
	char strcmp_test1[] = "Sp\necc\bia\vl";//special char check
	char strcmp_test2[] = "Termi\0nate";//NULL char check
	char strcmp_test3[] = "";//empty check

	char strcmp_control0[] = "Just a regular old string here";
	char strcmp_control1[] = "Sp\necc\bia\vl";
	char strcmp_control2[] = "Termi\0nate";
	char strcmp_control3[] = "";

	int	return_control0 = strcmp(strcmp_control0,strcmp_test0);//standard check
	int	return_control1 = strcmp(strcmp_control1,strcmp_test1);//special char check
	int	return_control2 = strcmp(strcmp_control2,strcmp_test2);//NULL char check
	int	return_control3 = strcmp(strcmp_control3,strcmp_test3);//empty check
	int	return_control4 = strcmp(strcmp_control0,strcmp_test2);//diff check 0
	int	return_control5 = strcmp(strcmp_control1,strcmp_test0);//diff check 1
	int	return_control6 = strcmp(strcmp_control2,strcmp_test3);//diff check 2
	int	return_control7 = strcmp(strcmp_control3,strcmp_test1);//diff check 3

	int	return_test0 = ft_strcmp(strcmp_control0,strcmp_test0);
	int	return_test1 = ft_strcmp(strcmp_control1,strcmp_test1);
	int	return_test2 = ft_strcmp(strcmp_control2,strcmp_test2);
	int	return_test3 = ft_strcmp(strcmp_control3,strcmp_test3);
	int	return_test4 = ft_strcmp(strcmp_control0,strcmp_test2);
	int	return_test5 = ft_strcmp(strcmp_control1,strcmp_test0);
	int	return_test6 = ft_strcmp(strcmp_control2,strcmp_test3);
	int	return_test7 = ft_strcmp(strcmp_control3,strcmp_test1);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strcmp)\n");
	printf("test0: %d \n",return_control0);
	printf("test1: %d \n",return_control1);
	printf("test2: %d \n",return_control2);
	printf("test3: %d \n",return_control3);
	printf("test4: %d   (or any negative value)\n",return_control4);
	printf("test5: %d    (or any positive value)\n",return_control5);
	printf("test6: %d   (or any positive value)\n",return_control6);
	printf("test7: %d  (or any negative value)\n",return_control7);
	printf("ACTUAL RESULT   (ft_strcmp)\n");
	printf("test0: %d \n",return_test0);
	printf("test1: %d \n",return_test1);
	printf("test2: %d \n",return_test2);
	printf("test3: %d \n",return_test3);
	printf("test4: %d  (any negative value)\n",return_test4);
	printf("test5: %d    (any positive value)\n",return_test5);
	printf("test6: %d   (any positive value)\n",return_test6);
	printf("test7: %d  (any negative value)\n",return_test7);

	if(return_control0 != return_test0){
		printf("issue detected on test 0 (\"Just a regular old string here\",\"Just a regular old string here\"): standard check, nothing special\n");
		diff=1;}
	if(return_control1 != return_test1){
		printf("issue detected on test 1 (\"Sp\\necc\\bia\\vl\",\"Sp\\necc\\bia\\vl\"): special char check\n");
		diff=1;}
	if(return_control2 != return_test2){
		printf("issue detected on test 2 (\"Termi\\0nate\",\"Termi\\0nate\"): NULL char check\n");
		diff=1;}
	if(return_control3 != return_test3){
		printf("issue detected on test 3 (\"\",\"\"): empty check\n");
		diff=1;}
	if(0 < return_test4){
		printf("issue detected on test 4 (\"Just a regular old string here\",\"Termi\\0nate\"): diff check\n");
		diff=1;}
	if(0 > return_test5){
		printf("issue detected on test 5 (\"Sp\\necc\\bia\\vl\",\"Just a regular old string here\"): diff check\n");
		diff=1;}
	if(0 > return_test6){
		printf("issue detected on test 6 (\"Termi\\0nate\",\"\"): diff check\n");
		diff=1;}
	if(0 <  return_test7){
		printf("issue detected on test 7 (\"\",\"Sp\\necc\\bia\\vl\"): diff check\n");
		diff=1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}
void	test_ft_strncmp()
{
	char TEST_NAME[] = "ft_strncmp test 1.0";
	int diff = 0;

	char strncmp_test0[] = "Just a regular old string here";//standard check
	char strncmp_test1[] = "Sp\necc\bia\vl";//special char check
	char strncmp_test2[] = "Termi\0nate";//NULL char check
	char strncmp_test3[] = "";//empty check

	char strncmp_control0[] = "Just a regular old string here";
	char strncmp_control1[] = "Sp\necc\bia\vl";
	char strncmp_control2[] = "Termi\0nate";
	char strncmp_control3[] = "";

	int	return_control0 = strncmp(strncmp_control0,strncmp_test0,31);//standard check
	int	return_control1 = strncmp(strncmp_control1,strncmp_test1,12);//special char check
	int	return_control2 = strncmp(strncmp_control2,strncmp_test2,11);//NULL char check
	int	return_control3 = strncmp(strncmp_control3,strncmp_test3,0);//empty check
	int	return_control4 = strncmp(strncmp_control0,strncmp_test2,11);//diff check 0
	int	return_control5 = strncmp(strncmp_control1,strncmp_test0,12);//diff check 1
	int	return_control6 = strncmp(strncmp_control2,strncmp_test3,1);//diff check 2
	int	return_control7 = strncmp(strncmp_control3,strncmp_test1,1);//diff check 3

	int	return_test0 = ft_strncmp(strncmp_control0,strncmp_test0,31);
	int	return_test1 = ft_strncmp(strncmp_control1,strncmp_test1,12);
	int	return_test2 = ft_strncmp(strncmp_control2,strncmp_test2,11);
	int	return_test3 = ft_strncmp(strncmp_control3,strncmp_test3,0);
	int	return_test4 = ft_strncmp(strncmp_control0,strncmp_test2,11);
	int	return_test5 = ft_strncmp(strncmp_control1,strncmp_test0,12);
	int	return_test6 = ft_strncmp(strncmp_control2,strncmp_test3,1);
	int	return_test7 = ft_strncmp(strncmp_control3,strncmp_test1,1);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strncmp)\n");
	printf("test0: %d \n",return_control0);
	printf("test1: %d \n",return_control1);
	printf("test2: %d \n",return_control2);
	printf("test3: %d \n",return_control3);
	printf("test4: %d   (or any negative value)\n",return_control4);
	printf("test5: %d    (or any positive value)\n",return_control5);
	printf("test6: %d   (or any positive value)\n",return_control6);
	printf("test7: %d  (or any negative value)\n",return_control7);
	printf("ACTUAL RESULT   (ft_strncmp)\n");
	printf("test0: %d \n",return_test0);
	printf("test1: %d \n",return_test1);
	printf("test2: %d \n",return_test2);
	printf("test3: %d \n",return_test3);
	printf("test4: %d  (any negative value)\n",return_test4);
	printf("test5: %d    (any positive value)\n",return_test5);
	printf("test6: %d   (any positive value)\n",return_test6);
	printf("test7: %d  (any negative value)\n",return_test7);

	if(return_control0 != return_test0){
		printf("issue detected on test 0 (\"Just a regular old string here\",\"Just a regular old string here\",31): standard check, nothing special\n");
		diff=1;}
	if(return_control1 != return_test1){
		printf("issue detected on test 1 (\"Sp\\necc\\bia\\vl\",\"Sp\\necc\\bia\\vl\",12): special char check\n");
		diff=1;}
	if(return_control2 != return_test2){
		printf("issue detected on test 2 (\"Termi\\0nate\",\"Termi\\0nate\",11): NULL char check\n");
		diff=1;}
	if(return_control3 != return_test3){
		printf("issue detected on test 3 (\"\",\"\",0): empty check\n");
		diff=1;}
	if(0 < return_test4){
		printf("issue detected on test 4 (\"Just a regular old string here\",\"Termi\\0nate\",11): diff check\n");
		diff=1;}
	if(0 > return_test5){
		printf("issue detected on test 5 (\"Sp\\necc\\bia\\vl\",\"Just a regular old string here\",12): diff check\n");
		diff=1;}
	if(0 > return_test6){
		printf("issue detected on test 6 (\"Termi\\0nate\",\"\",1): diff check\n");
		diff=1;}
	if(0 <  return_test7){
		printf("issue detected on test 7 (\"\",\"Sp\\necc\\bia\\vl\",1): diff check\n");
		diff=1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}
void	test_ft_atoi()
{
	char TEST_NAME[] = "ft_atoi test 1.0";
	int diff = 0;

	char atoi_test0[] = "   -178asd";//standard check
	char atoi_test1[] = " \n\t\v\f\r+42";//special char check
	char atoi_test2[] = "   +-+90";//invalid input check
	char atoi_test3[] = "";//empty check
	char atoi_test4[] = "     -2,147,483,648";//min integer check
	char atoi_test5[] = "    +2,147,483,647";//max integer check
	char atoi_test6[] = "   69";//signless check
	char atoi_test7[] = "-10";//spaceless check
	char atoi_test8[] = "  46  ";//spaces at end check
	char atoi_test9[] = "  -asd132";//no number check

	int	return_control0 = atoi(atoi_test0);//standard check
	int	return_control1 = atoi(atoi_test1);//special char check
	int	return_control2 = atoi(atoi_test2);//invalid input check
	int	return_control3 = atoi(atoi_test3);//empty check
	int	return_control4 = atoi(atoi_test4);//min integer check
	int	return_control5 = atoi(atoi_test5);//max integer check
	int	return_control6 = atoi(atoi_test6);//signless check
	int	return_control7 = atoi(atoi_test7);//spaceless check
	int	return_control8 = atoi(atoi_test8);//spaces at end check
	int	return_control9 = atoi(atoi_test9);//no number check


	int	return_test0 = ft_atoi(atoi_test0);
	int	return_test1 = ft_atoi(atoi_test1);
	int	return_test2 = ft_atoi(atoi_test2);
	int	return_test3 = ft_atoi(atoi_test3);
	int	return_test4 = ft_atoi(atoi_test4);
	int	return_test5 = ft_atoi(atoi_test5);
	int	return_test6 = ft_atoi(atoi_test6);
	int	return_test7 = ft_atoi(atoi_test7);
	int	return_test8 = ft_atoi(atoi_test8);
	int	return_test9 = ft_atoi(atoi_test9);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (atoi)\n");
	printf("test0: %d \n",return_control0);
	printf("test1: %d \n",return_control1);
	printf("test2: %d \n",return_control2);
	printf("test3: %d \n",return_control3);
	printf("test4: %d \n",return_control4);
	printf("test5: %d \n",return_control5);
	printf("test6: %d \n",return_control6);
	printf("test7: %d \n",return_control7);
	printf("test8: %d \n",return_control8);
	printf("test9: %d \n\n",return_control9);
	printf("ACTUAL RESULT   (ft_atoi)\n");
	printf("test0: %d \n",return_test0);
	printf("test1: %d \n",return_test1);
	printf("test2: %d \n",return_test2);
	printf("test3: %d \n",return_test3);
	printf("test4: %d \n",return_test4);
	printf("test5: %d \n",return_test5);
	printf("test6: %d \n",return_test6);
	printf("test7: %d \n",return_test7);
	printf("test8: %d \n",return_test8);
	printf("test9: %d \n\n",return_test9);

	if(return_control0 != return_test0){
		printf("issue detected on test 0 (\"   -178asd\"): standard check, nothing special\n");
		diff=1;}
	if(return_control1 != return_test1){
		printf("issue detected on test 1 (\" \\n\\t\\v\\f\\r+42\"): special char check\n");
		diff=1;}
	if(return_control2 != return_test2){
		printf("issue detected on test 2 (\"   +-+90\"): invalid input check\n");
		diff=1;}
	if(return_control3 != return_test3){
		printf("issue detected on test 3 (\"\"): empty check\n");
		diff=1;}
	if(return_control4 != return_test4){
		printf("issue detected on test 4 (\"     -2,147,483,648\"): min integer check\n");
		diff=1;}
	if(return_control5 != return_test5){
		printf("issue detected on test 5 (\"    +2,147,483,647\"): max integer check\n");
		diff=1;}
	if(return_control6 != return_test6){
		printf("issue detected on test 6 (\"   69\"): signless check\n");
		diff=1;}
	if(return_control7 != return_test7){
		printf("issue detected on test 7 (\"-10\"): no spaces check\n");
		diff=1;}
	if(return_control8 != return_test8){
		printf("issue detected on test 8 (\"  46  \"): spaces after number check\n");
		diff=1;}
	if(return_control9 != return_test9){
		printf("issue detected on test 9 (\"  -asd132\"): no number check\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_isalpha()
{
	char TEST_NAME[] = "ft_isalpha test 1.0";
	int diff = 0;

	int isalpha_test0 = (int)'5';
	int isalpha_test1 = (int)'@';
	int isalpha_test2 = (int)'A';
	int isalpha_test3 = (int)'Z';
	int isalpha_test4 = (int)'[';
	int isalpha_test5 = (int)'`';
	int isalpha_test6 = (int)'a';
	int isalpha_test7 = (int)'z';
	int isalpha_test8 = (int)'{';
	int isalpha_test9 = (int)'!';

	int	return_control0 = isalpha(isalpha_test0);
	int	return_control1 = isalpha(isalpha_test1);
	int	return_control2 = isalpha(isalpha_test2);
	int	return_control3 = isalpha(isalpha_test3);
	int	return_control4 = isalpha(isalpha_test4);
	int	return_control5 = isalpha(isalpha_test5);
	int	return_control6 = isalpha(isalpha_test6);
	int	return_control7 = isalpha(isalpha_test7);
	int	return_control8 = isalpha(isalpha_test8);
	int	return_control9 = isalpha(isalpha_test9);


	int	return_test0 = ft_isalpha(isalpha_test0);
	int	return_test1 = ft_isalpha(isalpha_test1);
	int	return_test2 = ft_isalpha(isalpha_test2);
	int	return_test3 = ft_isalpha(isalpha_test3);
	int	return_test4 = ft_isalpha(isalpha_test4);
	int	return_test5 = ft_isalpha(isalpha_test5);
	int	return_test6 = ft_isalpha(isalpha_test6);
	int	return_test7 = ft_isalpha(isalpha_test7);
	int	return_test8 = ft_isalpha(isalpha_test8);
	int	return_test9 = ft_isalpha(isalpha_test9);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (isalpha)\n");
	printf("test0: %d \n",return_control0);
	printf("test1: %d \n",return_control1);
	printf("test2: %d (any positive number)\n",return_control2);
	printf("test3: %d (any positive number)\n",return_control3);
	printf("test4: %d \n",return_control4);
	printf("test5: %d \n",return_control5);
	printf("test6: %d (any positive number)\n",return_control6);
	printf("test7: %d (any positive number)\n",return_control7);
	printf("test8: %d \n",return_control8);
	printf("test9: %d \n\n",return_control9);
	printf("ACTUAL RESULT   (ft_isalpha)\n");
	printf("test0: %d \n",return_test0);
	printf("test1: %d \n",return_test1);
	printf("test2: %d (any positive number)\n",return_test2);
	printf("test3: %d (any positive number)\n",return_test3);
	printf("test4: %d \n",return_test4);
	printf("test5: %d \n",return_test5);
	printf("test6: %d (any positive number)\n",return_test6);
	printf("test7: %d (any positive number)\n",return_test7);
	printf("test8: %d \n",return_test8);
	printf("test9: %d \n\n",return_test9);

	if(return_control0 != return_test0){
		printf("issue detected on test 0 (\"5\")\n");
		diff=1;}
	if(return_control1 != return_test1){
		printf("issue detected on test 1 (\"@\")\n");
		diff=1;}
	if(return_test2 < 1){
		printf("issue detected on test 2 (\"A\")\n");
		diff=1;}
	if(return_test3 < 1){
		printf("issue detected on test 3 (\"Z\")\n");
		diff=1;}
	if(return_control4 != return_test4){
		printf("issue detected on test 4 (\"[\")\n");
		diff=1;}
	if(return_control5 != return_test5){
		printf("issue detected on test 5 (\"`\")\n");
		diff=1;}
	if(return_test6 < 1){
		printf("issue detected on test 6 (\"a\")\n");
		diff=1;}
	if(return_test7 < 1){
		printf("issue detected on test 7 (\"z\")\n");
		diff=1;}
	if(return_control8 != return_test8){
		printf("issue detected on test 8 (\"{\")\n");
		diff=1;}
	if(return_control9 != return_test9){
		printf("issue detected on test 9 (\"!\")\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_isdigit()
{
	char TEST_NAME[] = "ft_isdigit test 1.0";
	int diff = 0;

	int isdigit_test0 = (int)'|';
	int isdigit_test1 = (int)'/';
	int isdigit_test2 = (int)'0';
	int isdigit_test3 = (int)'9';
	int isdigit_test4 = (int)':';
	int isdigit_test5 = (int)'A';
	int isdigit_test6 = (int)'a';
	int isdigit_test7 = (int)'Z';
	int isdigit_test8 = (int)'z';
	int isdigit_test9 = (int)'!';

	int	return_control0 = isdigit(isdigit_test0);
	int	return_control1 = isdigit(isdigit_test1);
	int	return_control2 = isdigit(isdigit_test2);
	int	return_control3 = isdigit(isdigit_test3);
	int	return_control4 = isdigit(isdigit_test4);
	int	return_control5 = isdigit(isdigit_test5);
	int	return_control6 = isdigit(isdigit_test6);
	int	return_control7 = isdigit(isdigit_test7);
	int	return_control8 = isdigit(isdigit_test8);
	int	return_control9 = isdigit(isdigit_test9);


	int	return_test0 = ft_isdigit(isdigit_test0);
	int	return_test1 = ft_isdigit(isdigit_test1);
	int	return_test2 = ft_isdigit(isdigit_test2);
	int	return_test3 = ft_isdigit(isdigit_test3);
	int	return_test4 = ft_isdigit(isdigit_test4);
	int	return_test5 = ft_isdigit(isdigit_test5);
	int	return_test6 = ft_isdigit(isdigit_test6);
	int	return_test7 = ft_isdigit(isdigit_test7);
	int	return_test8 = ft_isdigit(isdigit_test8);
	int	return_test9 = ft_isdigit(isdigit_test9);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (isdigit)\n");
	printf("test0: %d \n",return_control0);
	printf("test1: %d \n",return_control1);
	printf("test2: %d (any positive number)\n",return_control2);
	printf("test3: %d (any positive number)\n",return_control3);
	printf("test4: %d \n",return_control4);
	printf("test5: %d \n",return_control5);
	printf("test6: %d \n",return_control6);
	printf("test7: %d \n",return_control7);
	printf("test8: %d \n",return_control8);
	printf("test9: %d \n\n",return_control9);
	printf("ACTUAL RESULT   (ft_isdigit)\n");
	printf("test0: %d \n",return_test0);
	printf("test1: %d \n",return_test1);
	printf("test2: %d (any positive number)\n",return_test2);
	printf("test3: %d (any positive number)\n",return_test3);
	printf("test4: %d \n",return_test4);
	printf("test5: %d \n",return_test5);
	printf("test6: %d \n",return_test6);
	printf("test7: %d \n",return_test7);
	printf("test8: %d \n",return_test8);
	printf("test9: %d \n\n",return_test9);

	if(return_control0 != return_test0){
		printf("issue detected on test 0 (\"|\")\n");
		diff=1;}
	if(return_control1 != return_test1){
		printf("issue detected on test 1 (\"/\")\n");
		diff=1;}
	if(return_test2 < 1){
		printf("issue detected on test 2 (\"0\")\n");
		diff=1;}
	if(return_test3 < 1){
		printf("issue detected on test 3 (\"9\")\n");
		diff=1;}
	if(return_control4 != return_test4){
		printf("issue detected on test 4 (\":\")\n");
		diff=1;}
	if(return_control5 != return_test5){
		printf("issue detected on test 5 (\"A\")\n");
		diff=1;}
	if(return_test6 != 0){
		printf("issue detected on test 6 (\"a\")\n");
		diff=1;}
	if(return_test7 != 0){
		printf("issue detected on test 7 (\"Z\")\n");
		diff=1;}
	if(return_control8 != return_test8){
		printf("issue detected on test 8 (\"z\")\n");
		diff=1;}
	if(return_control9 != return_test9){
		printf("issue detected on test 9 (\"!\")\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_isalnum()
{
	char TEST_NAME[] = "ft_isalnum test 1.0";
	int diff = 0;

	int isalnum_test0 = (int)'/';
	int isalnum_test1 = (int)'0';
	int isalnum_test2 = (int)'9';
	int isalnum_test3 = (int)':';
	int isalnum_test4 = (int)'`';
	int isalnum_test5 = (int)'a';
	int isalnum_test6 = (int)'z';
	int isalnum_test7 = (int)'{';
	int isalnum_test8 = (int)'@';
	int isalnum_test9 = (int)'A';
	int isalnum_test10 = (int)'Z';
	int isalnum_test11 = (int)'[';

	int	return_control0 = isalnum(isalnum_test0);
	int	return_control1 = isalnum(isalnum_test1);
	int	return_control2 = isalnum(isalnum_test2);
	int	return_control3 = isalnum(isalnum_test3);
	int	return_control4 = isalnum(isalnum_test4);
	int	return_control5 = isalnum(isalnum_test5);
	int	return_control6 = isalnum(isalnum_test6);
	int	return_control7 = isalnum(isalnum_test7);
	int	return_control8 = isalnum(isalnum_test8);
	int	return_control9 = isalnum(isalnum_test9);
	int	return_control10 = isalnum(isalnum_test10);
	int	return_control11 = isalnum(isalnum_test11);


	int	return_test0 = ft_isalnum(isalnum_test0);
	int	return_test1 = ft_isalnum(isalnum_test1);
	int	return_test2 = ft_isalnum(isalnum_test2);
	int	return_test3 = ft_isalnum(isalnum_test3);
	int	return_test4 = ft_isalnum(isalnum_test4);
	int	return_test5 = ft_isalnum(isalnum_test5);
	int	return_test6 = ft_isalnum(isalnum_test6);
	int	return_test7 = ft_isalnum(isalnum_test7);
	int	return_test8 = ft_isalnum(isalnum_test8);
	int	return_test9 = ft_isalnum(isalnum_test9);
	int	return_test10 = ft_isalnum(isalnum_test10);
	int	return_test11 = ft_isalnum(isalnum_test11);


	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (isalnum)\n");
	printf("test0: %d \n",return_control0);
	printf("test1: %d (any positive number)\n",return_control1);
	printf("test2: %d (any positive number)\n",return_control2);
	printf("test3: %d \n",return_control3);
	printf("test4: %d \n",return_control4);
	printf("test5: %d (any positive number)\n",return_control5);
	printf("test6: %d (any positive number)\n",return_control6);
	printf("test7: %d \n",return_control7);
	printf("test8: %d \n",return_control8);
	printf("test9: %d (any positive number)\n",return_control9);
	printf("test10: %d (any positive number)\n",return_control10);
	printf("test11: %d \n\n",return_control11);
	printf("ACTUAL RESULT   (ft_isalnum)\n");
	printf("test0: %d \n",return_test0);
	printf("test1: %d (any positive number)\n",return_test1);
	printf("test2: %d (any positive number)\n",return_test2);
	printf("test3: %d \n",return_test3);
	printf("test4: %d \n",return_test4);
	printf("test5: %d (any positive number)\n",return_test5);
	printf("test6: %d (any positive number)\n",return_test6);
	printf("test7: %d \n",return_test7);
	printf("test8: %d \n",return_test8);
	printf("test9: %d (any positive number)\n",return_test9);
	printf("test10: %d (any positive number)\n",return_test10);
	printf("test11: %d \n\n",return_test11);

	if(return_test0 != 0){
		printf("issue detected on test 0 (\"/\")\n");
		diff=1;}
	if(return_test1 < 1){
		printf("issue detected on test 1 (\"0\")\n");
		diff=1;}
	if(return_test2 < 1){
		printf("issue detected on test 2 (\"9\")\n");
		diff=1;}
	if(return_test3 != 0){
		printf("issue detected on test 3 (\":\")\n");
		diff=1;}
	if(return_test4 != 0){
		printf("issue detected on test 4 (\"`\")\n");
		diff=1;}
	if(return_test5 < 1){
		printf("issue detected on test 5 (\"a\")\n");
		diff=1;}
	if(return_test6 < 1){
		printf("issue detected on test 6 (\"z\")\n");
		diff=1;}
	if(return_test7 != 0){
		printf("issue detected on test 7 (\"{\")\n");
		diff=1;}
	if(return_test8 != 0){
		printf("issue detected on test 8 (\"@\")\n");
		diff=1;}
	if(return_test9 < 1){
		printf("issue detected on test 9 (\"A\")\n");
		diff=1;}
	if(return_test10 < 1){
		printf("issue detected on test 10 (\"Z\")\n");
		diff=1;}
	if(return_test11 != 0){
		printf("issue detected on test 11 (\"[\")\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_isascii()
{
	char TEST_NAME[] = "ft_isascii test 1.0";
	int diff = 0;

	int isascii_test0 = 0;
	int isascii_test1 = 42;
	int isascii_test2 = 127;
	int isascii_test3 = 128;
	int isascii_test4 = -1;
	int isascii_test5 = -69;

	int	return_control0 = isascii(isascii_test0);
	int	return_control1 = isascii(isascii_test1);
	int	return_control2 = isascii(isascii_test2);
	int	return_control3 = isascii(isascii_test3);
	int	return_control4 = isascii(isascii_test4);
	int	return_control5 = isascii(isascii_test5);

	int	return_test0 = ft_isascii(isascii_test0);
	int	return_test1 = ft_isascii(isascii_test1);
	int	return_test2 = ft_isascii(isascii_test2);
	int	return_test3 = ft_isascii(isascii_test3);
	int	return_test4 = ft_isascii(isascii_test4);
	int	return_test5 = ft_isascii(isascii_test5);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (isascii)\n");
	printf("test0: %d (any positive number)\n",return_control0);
	printf("test1: %d (any positive number)\n",return_control1);
	printf("test2: %d (any positive number)\n",return_control2);
	printf("test3: %d \n",return_control3);
	printf("test4: %d \n",return_control4);
	printf("test5: %d \n\n",return_control5);

	printf("ACTUAL RESULT   (ft_isascii)\n");
	printf("test0: %d (any positive number)\n",return_test0);
	printf("test1: %d (any positive number)\n",return_test1);
	printf("test2: %d (any positive number)\n",return_test2);
	printf("test3: %d \n",return_test3);
	printf("test4: %d \n",return_test4);
	printf("test5: %d \n\n",return_test5);

	if(return_test0 < 1){
		printf("issue detected on test 0 (\"0\")\n");
		diff=1;}
	if(return_test1 < 1){
		printf("issue detected on test 1 (\"42\")\n");
		diff=1;}
	if(return_test2 < 1){
		printf("issue detected on test 2 (\"127\")\n");
		diff=1;}
	if(return_test3 != 0){
		printf("issue detected on test 3 (\"128\")\n");
		diff=1;}
	if(return_test4 != 0){
		printf("issue detected on test 4 (\"-1\")\n");
		diff=1;}
	if(return_test5 != 0){
		printf("issue detected on test 5 (\"-69\")\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_isprint()
{
	char TEST_NAME[] = "ft_isprint test 1.0";
	int diff = 0;

	int isprint_test0 = 31;
	int isprint_test1 = 32;
	int isprint_test2 = 126;
	int isprint_test3 = 127;
	int isprint_test4 = -1;
	int isprint_test5 = 128;

	int	return_control0 = isprint(isprint_test0);
	int	return_control1 = isprint(isprint_test1);
	int	return_control2 = isprint(isprint_test2);
	int	return_control3 = isprint(isprint_test3);
	int	return_control4 = isprint(isprint_test4);
	int	return_control5 = isprint(isprint_test5);

	int	return_test0 = ft_isprint(isprint_test0);
	int	return_test1 = ft_isprint(isprint_test1);
	int	return_test2 = ft_isprint(isprint_test2);
	int	return_test3 = ft_isprint(isprint_test3);
	int	return_test4 = ft_isprint(isprint_test4);
	int	return_test5 = ft_isprint(isprint_test5);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (isprint)\n");
	printf("test0: %d \n",return_control0);
	printf("test1: %d (any positive number)\n",return_control1);
	printf("test2: %d (any positive number)\n",return_control2);
	printf("test3: %d \n",return_control3);
	printf("test4: %d \n",return_control4);
	printf("test5: %d \n\n",return_control5);

	printf("ACTUAL RESULT   (ft_isprint)\n");
	printf("test0: %d \n",return_test0);
	printf("test1: %d (any positive number)\n",return_test1);
	printf("test2: %d (any positive number)\n",return_test2);
	printf("test3: %d \n",return_test3);
	printf("test4: %d \n",return_test4);
	printf("test5: %d \n\n",return_test5);

	if(return_test0 != 0){
		printf("issue detected on test 0 (\"31\")\n");
		diff=1;}
	if(return_test1 < 1){
		printf("issue detected on test 1 (\"32\")\n");
		diff=1;}
	if(return_test2 < 1){
		printf("issue detected on test 2 (\"126\")\n");
		diff=1;}
	if(return_test3 != 0){
		printf("issue detected on test 3 (\"127\")\n");
		diff=1;}
	if(return_test4 != 0){
		printf("issue detected on test 4 (\"-1\")\n");
		diff=1;}
	if(return_test5 != 0){
		printf("issue detected on test 5 (\"128\")\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_toupper()
{
	char TEST_NAME[] = "ft_toupper test 1.0";
	int diff = 0;

	int toupper_test0 = 96;//'`'
	int toupper_test1 = 97;//'a'
	int toupper_test2 = 122;//'z'
	int toupper_test3 = 123;//'{'
	int toupper_test4 = -1;
	int toupper_test5 = 128;

	int	return_control0 = toupper(toupper_test0);
	int	return_control1 = toupper(toupper_test1);
	int	return_control2 = toupper(toupper_test2);
	int	return_control3 = toupper(toupper_test3);
	int	return_control4 = toupper(toupper_test4);
	int	return_control5 = toupper(toupper_test5);

	int	return_test0 = ft_toupper(toupper_test0);
	int	return_test1 = ft_toupper(toupper_test1);
	int	return_test2 = ft_toupper(toupper_test2);
	int	return_test3 = ft_toupper(toupper_test3);
	int	return_test4 = ft_toupper(toupper_test4);
	int	return_test5 = ft_toupper(toupper_test5);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (toupper)\n");
	printf("test0: %c \n",return_control0);
	printf("test1: %c \n",return_control1);
	printf("test2: %c \n",return_control2);
	printf("test3: %c \n",return_control3);
	printf("test4: %c \n",return_control4);
	printf("test5: %c \n\n",return_control5);

	printf("ACTUAL RESULT   (ft_toupper)\n");
	printf("test0: %c \n",return_test0);
	printf("test1: %c \n",return_test1);
	printf("test2: %c \n",return_test2);
	printf("test3: %c \n",return_test3);
	printf("test4: %c \n",return_test4);
	printf("test5: %c \n\n",return_test5);

	if(return_test0 != return_control0){
		printf("issue detected on test 0 (\"`\")\n");
		diff=1;}
	if(return_test1 != return_control1){
		printf("issue detected on test 1 (\"a\")\n");
		diff=1;}
	if(return_test2 != return_control2){
		printf("issue detected on test 2 (\"z\")\n");
		diff=1;}
	if(return_test3 != return_control3){
		printf("issue detected on test 3 (\"{\")\n");
		diff=1;}
	if(return_test4 != return_control4){
		printf("issue detected on test 4 (\"-1\")\n");
		diff=1;}
	if(return_test5 != return_control5){
		printf("issue detected on test 5 (\"128\")\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_tolower()
{
	char TEST_NAME[] = "ft_tolower test 1.0";
	int diff = 0;

	int tolower_test0 = 64;//'@'
	int tolower_test1 = 65;//'A'
	int tolower_test2 = 90;//'A'
	int tolower_test3 = 91;//'['
	int tolower_test4 = -1;
	int tolower_test5 = 128;

	int	return_control0 = tolower(tolower_test0);
	int	return_control1 = tolower(tolower_test1);
	int	return_control2 = tolower(tolower_test2);
	int	return_control3 = tolower(tolower_test3);
	int	return_control4 = tolower(tolower_test4);
	int	return_control5 = tolower(tolower_test5);

	int	return_test0 = ft_tolower(tolower_test0);
	int	return_test1 = ft_tolower(tolower_test1);
	int	return_test2 = ft_tolower(tolower_test2);
	int	return_test3 = ft_tolower(tolower_test3);
	int	return_test4 = ft_tolower(tolower_test4);
	int	return_test5 = ft_tolower(tolower_test5);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (tolower)\n");
	printf("test0: %c \n",return_control0);
	printf("test1: %c \n",return_control1);
	printf("test2: %c \n",return_control2);
	printf("test3: %c \n",return_control3);
	printf("test4: %c \n",return_control4);
	printf("test5: %c \n\n",return_control5);

	printf("ACTUAL RESULT   (ft_tolower)\n");
	printf("test0: %c \n",return_test0);
	printf("test1: %c \n",return_test1);
	printf("test2: %c \n",return_test2);
	printf("test3: %c \n",return_test3);
	printf("test4: %c \n",return_test4);
	printf("test5: %c \n\n",return_test5);

	if(return_test0 != return_control0){
		printf("issue detected on test 0 (\"`\")\n");
		diff=1;}
	if(return_test1 != return_control1){
		printf("issue detected on test 1 (\"a\")\n");
		diff=1;}
	if(return_test2 != return_control2){
		printf("issue detected on test 2 (\"z\")\n");
		diff=1;}
	if(return_test3 != return_control3){
		printf("issue detected on test 3 (\"{\")\n");
		diff=1;}
	if(return_test4 != return_control4){
		printf("issue detected on test 4 (\"-1\")\n");
		diff=1;}
	if(return_test5 != return_control5){
		printf("issue detected on test 5 (\"128\")\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_memalloc()//honestly i have no clue if this test is any good
{
	char TEST_NAME[] = "ft_memalloc test 1.0";
	int diff = 0;

	char	*memalloc_test0;
	char	*memalloc_test1;
	int		*memalloc_test2;
	int		*memalloc_test3;
	long	*memalloc_test4;
	long	*memalloc_test5;
	char	*memalloc_control0;
	char	*memalloc_control1;
	int		*memalloc_control2;
	int		*memalloc_control3;
	long	*memalloc_control4;
	long	*memalloc_control5;

	memalloc_test0 = (char *)ft_memalloc(sizeof(char));//one char check
	memalloc_test1 = (char *)ft_memalloc(sizeof(char) * 10);//ten char check
	memalloc_test2 = (int *)ft_memalloc(sizeof(int));//one int check
	memalloc_test3 = (int *)ft_memalloc(sizeof(int) * 10);//ten int check
	memalloc_test4 = (long *)ft_memalloc(sizeof(long));//one long check
	memalloc_test5 = (long *)ft_memalloc(sizeof(long) * 10);//ten long check

	memalloc_control0 = (char *)malloc(sizeof(char));//one char check
	memalloc_control1 = (char *)malloc(sizeof(char) * 10);//ten char check
	memalloc_control2 = (int *)malloc(sizeof(int));//one int check
	memalloc_control3 = (int *)malloc(sizeof(int) * 10);//ten int check
	memalloc_control4 = (long *)malloc(sizeof(long));//one long check
	memalloc_control5 = (long *)malloc(sizeof(long) * 10);//ten long check

	memset(memalloc_control0,0,sizeof(char));
	memset(memalloc_control1,0,sizeof(char) * 10);
	memset(memalloc_control2,0,sizeof(int));
	memset(memalloc_control3,0,sizeof(int) * 10);
	memset(memalloc_control4,0,sizeof(long));
	memset(memalloc_control5,0,sizeof(long) * 10);
	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (memalloc)\n");
	printf("test 0: 0\n");
	printf("test 1: 0\n");
	printf("test 2: 0\n");
	printf("test 3: 0\n");
	printf("test 4: 0\n");
	printf("test 5: 0\n\n");
	printf("ACTUAL RESULT   (ft_memalloc)\n");
	printf("test 0: %d\n",memcmp(memalloc_test0,memalloc_control0,sizeof(char)));
	printf("test 1: %d\n",memcmp(memalloc_test1,memalloc_control1,(sizeof(char)*10)));
	printf("test 2: %d\n",memcmp(memalloc_test2,memalloc_control2,sizeof(int)));
	printf("test 3: %d\n",memcmp(memalloc_test3,memalloc_control3,(sizeof(int)*10)));
	printf("test 4: %d\n",memcmp(memalloc_test4,memalloc_control4,sizeof(long)));
	printf("test 5: %d\n\n",memcmp(memalloc_test5,memalloc_control5,(sizeof(long)*10)));

	if(memcmp(memalloc_test0,memalloc_control0,sizeof(char)) != 0){
		printf("issue detected on test 0 : (char *)ft_memalloc(sizeof(char)) one char check\n");
		diff = 1;}
	if(memcmp(memalloc_test1,memalloc_control1,sizeof(char) * 10) != 0){
		printf("issue detected on test 1 : (char *)ft_memalloc(sizeof(char) * 10) ten char check\n");
		diff = 1;}
	if(memcmp(memalloc_test2,memalloc_control2,sizeof(int)) != 0){
		printf("issue detected on test 2 : (int *)ft_memalloc(sizeof(int)) one int check\n");
		diff = 1;}
	if(memcmp(memalloc_test3,memalloc_control3,(sizeof(int)*10)) != 0){
		printf("issue detected on test 3 : (int *)ft_memalloc(sizeof(int) * 10) ten int check\n");
		diff = 1;}
	if(memcmp(memalloc_test4,memalloc_control4,sizeof(long)) != 0){
		printf("issue detected on test 4 : (long *)malloc(sizeof(long)) one long check\n");
		diff = 1;}
	if(memcmp(memalloc_test5,memalloc_control5,(sizeof(long)*10)) != 0){
		printf("issue detected on test 5 : (long *)ft_memalloc(sizeof(long) * 10) ten long check\n");
		diff = 1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_memdel()
{
	char TEST_NAME[] = "ft_memdel test 1.0";
	int diff = 0;

	char	*memdel_test0 = (char *)malloc(sizeof(char)*10);
	int		*memdel_test1 = (int *)malloc(sizeof(int)*10);
	long	*memdel_test2 = (long *)malloc(sizeof(long)*10);
	char	*memdel_control0 = (char *)malloc(sizeof(char)*10);
	int		*memdel_control1 = (int *)malloc(sizeof(int)*10);
	long	*memdel_control2 = (long *)malloc(sizeof(long)*10);

	char	**test0ptr = &memdel_test0;
	int		**test1ptr = &memdel_test1;
	long	**test2ptr = &memdel_test2;

	free(memdel_control0);
	free(memdel_control1);
	free(memdel_control2);
	memdel_control0 = NULL;
	memdel_control1 = NULL;//yes, i could have skipped the malloc and free
	memdel_control2 = NULL;//and just set it to NULL from the start.

	ft_memdel((void **)test0ptr);
	ft_memdel((void **)test1ptr);
	ft_memdel((void **)test2ptr);//testXptr needs to become a pointer to a NULL pointer

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (memdel)\n");
	printf("test 0: %p\n",memdel_control0);
	printf("test 1: %p\n",memdel_control1);
	printf("test 2: %p\n\n",memdel_control2);
	printf("ACTUAL RESULT   (ft_memdel)\n");
	printf("test 0: %p\n",memdel_test0);
	printf("test 1: %p\n",memdel_test1);
	printf("test 2: %p\n\n",memdel_test2);

	if(memdel_test0 != 0){
		printf("issue detected on test 0 : ft_memdel((void **)test0ptr)  pointer not correctly set to 0\n");
		diff = 1;}
	if(memdel_test1 != 0){
		printf("issue detected on test 1 : ft_memdel((void **)test1ptr)  pointer not correctly set to 0\n");
		diff = 1;}
	if(memdel_test2 != 0){
		printf("issue detected on test 2 : ft_memdel((void **)test2ptr)  pointer not correctly set to 0\n");
		diff = 1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_strnew()
{
	char TEST_NAME[] = "ft_strnew test 1.0";
	int diff = 0;

	char *strnew_test0;
	char *strnew_test1;
	char *strnew_test2;

	strnew_test0 = ft_strnew(0);
	strnew_test1 = ft_strnew(1);
	strnew_test2 = ft_strnew(42);

	char *return_control0 = (char *)malloc(0);
	char *return_control1 = (char *)malloc(1);
	char return_control2[] = "testtest";

	return_control0[0] = 0;
	return_control1[0] = 0;
	strnew_test2[0] = 't';
	strnew_test2[4] = 't';
	strnew_test2[1] = 'e';
	strnew_test2[5] = 'e';
	strnew_test2[2] = 's';
	strnew_test2[6] = 's';
	strnew_test2[3] = 't';
	strnew_test2[7] = 't';

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strnew)\n");
	printf("test0: %d \n",*return_control0);
	printf("test1: %d \n",*return_control1);
	printf("test2: %s \n",return_control2);

	printf("ACTUAL RESULT   (ft_strnew)\n");
	printf("test0: %d \n",*strnew_test0);
	printf("test1: %d \n",*strnew_test1);
	printf("test2: %s \n",strnew_test2);

	if(strcmp(strnew_test0,return_control0) != 0){
		printf("issue detected on test 0 (\"13 chr string\"): base test, nothing special\n");
		diff=1;}
	if(strcmp(strnew_test1,return_control1) != 0){
		printf("issue detected on test 1 (\"This\\tstring\\vis\\rfull\\aof\\bspecial\\echaracters\\n\"): check if there are issues on special characters\n");
		diff=1;}
	if(strcmp(strnew_test2,return_control2) != 0){
		printf("issue detected on test 2 (\"Termi\\0nate\"): NULL char check\n");
		diff=1;}
	if(diff==0)
		printf("\nNo issue detected, Good Job!\n");
}
void	test_ft_strdel()
{
	char TEST_NAME[] = "ft_strdel test 1.0";
	int diff = 0;

	char	*strdel_test0 = (char *)malloc(0);
	char	*strdel_test1 = (char *)malloc(sizeof(char));
	char	*strdel_test2 = (char *)malloc(sizeof(char)*10);
	char	*strdel_control0 = (char *)malloc(0);
	char	*strdel_control1 = (char *)malloc(sizeof(char));
	char	*strdel_control2 = (char *)malloc(sizeof(char)*10);

	char	**test0ptr = &strdel_test0;
	char	**test1ptr = &strdel_test1;
	char	**test2ptr = &strdel_test2;

	free(strdel_control0);
	free(strdel_control1);
	free(strdel_control2);
	strdel_control0 = NULL;
	strdel_control1 = NULL;//yes, i could have skipped the malloc and free
	strdel_control2 = NULL;//and just set it to NULL from the start.

	ft_strdel(test0ptr);
	ft_strdel(test1ptr);
	ft_strdel(test2ptr);//testXptr needs to become a pointer to a NULL pointer

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strdel)\n");
	printf("test 0: %p\n",strdel_control0);
	printf("test 1: %p\n",strdel_control1);
	printf("test 2: %p\n\n",strdel_control2);
	printf("ACTUAL RESULT   (ft_strdel)\n");
	printf("test 0: %p\n",strdel_test0);
	printf("test 1: %p\n",strdel_test1);
	printf("test 2: %p\n\n",strdel_test2);

	if(strdel_test0 != 0){
		printf("issue detected on test 0 : ft_strdel((void **)test0ptr)  pointer not correctly set to 0\n");
		diff = 1;}
	if(strdel_test1 != 0){
		printf("issue detected on test 1 : ft_strdel((void **)test1ptr)  pointer not correctly set to 0\n");
		diff = 1;}
	if(strdel_test2 != 0){
		printf("issue detected on test 2 : ft_strdel((void **)test2ptr)  pointer not correctly set to 0\n");
		diff = 1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}
void	test_ft_strclr()
{
	char TEST_NAME[] = "ft_strclr test 1.0";
	int diff = 0;

	char strclr_test0[] = "Just a regular old string here";//standard check
	char strclr_test1[] = "Sp\necc\bia\vl";//special char check
	char strclr_test2[] = "Termi\0nate";//NULL char check
	char strclr_test3[] = "";//empty check

	char strclr_control0[] = "Just a regular old string here";
	char strclr_control1[] = "Sp\necc\bia\vl";
	char strclr_control2[] = "Termi\0nate";
	char strclr_control3[] = "";

	memset(strclr_control0,0,strlen(strclr_control0));
	memset(strclr_control1,0,strlen(strclr_control1));
	memset(strclr_control2,0,strlen(strclr_control2));
	memset(strclr_control3,0,strlen(strclr_control3));
	ft_strclr(strclr_test2);
	ft_strclr(strclr_test0);
	ft_strclr(strclr_test3);
	ft_strclr(strclr_test1);

	printf("HACS %.1f, %s, %s\n\n",VERSION_NUMBER,TEST_MODULE,TEST_NAME);
	printf("EXPECTED RESULT (strclr)\n");
	printf("test0: %d \n",strclr_control0[0]);
	printf("test1: %d \n",strclr_control1[0]);
	printf("test2: %d \n",strclr_control2[0]);
	printf("test3: %d \n\n",strclr_control3[0]);
	printf("ACTUAL RESULT   (ft_strclr)\n");
	printf("test0: %d \n",strclr_test0[0]);
	printf("test1: %d \n",strclr_test1[0]);
	printf("test2: %d \n",strclr_test2[0]);
	printf("test3: %d \n\n",strclr_test3[0]);

	if(strclr_test0[0] != 0){
		printf("issue detected on test 0: string not properly set to 0\n");
		diff=1;}
	if(strclr_test1[0] != 0){
		printf("issue detected on test 1: string not properly set to 0\n");
		diff=1;}
	if(strclr_test2[0] != 0){
		printf("issue detected on test 2: string not properly set to 0\n");
		diff=1;}
	if(strclr_test3[0] != 0){
		printf("issue detected on test 3: string not properly set to 0\n");
		diff=1;}
	if(diff==0)
		printf("No issue detected, Good Job!\n");
}

int		main(int ac, char **av)
{
	if (ac == 2)// this whole thing is probably gonna get removed or greatly reworked
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
		else if (strcmp(av[1], "memchr") == 0 || strcmp(av[1], "ft_memchr") == 0)
			test_ft_memchr();
		else if (strcmp(av[1], "memcmp") == 0 || strcmp(av[1], "ft_memcmp") == 0)
			test_ft_memcmp();
		else if (strcmp(av[1], "strlen") == 0 || strcmp(av[1], "ft_strlen") == 0)
			test_ft_strlen();
		else if (strcmp(av[1], "strdup") == 0 || strcmp(av[1], "ft_strdup") == 0)
			test_ft_strdup();
		else if (strcmp(av[1], "strcpy") == 0 || strcmp(av[1], "ft_strcpy") == 0)
			test_ft_strcpy();
		else if (strcmp(av[1], "strncpy") == 0 || strcmp(av[1], "ft_strncpy") == 0)
			test_ft_strncpy();
		else if (strcmp(av[1], "strcat") == 0 || strcmp(av[1], "ft_strcat") == 0)
			test_ft_strcat();
		else if (strcmp(av[1], "strncat") == 0 || strcmp(av[1], "ft_strncat") == 0)
			test_ft_strncat();
		else if (strcmp(av[1], "strlcat") == 0 || strcmp(av[1], "ft_strlcat") == 0)
			test_ft_strlcat();
		else if (strcmp(av[1], "strchr") == 0 || strcmp(av[1], "ft_strchr") == 0)
			test_ft_strchr();
		else if (strcmp(av[1], "strrchr") == 0 || strcmp(av[1], "ft_strrchr") == 0)
			test_ft_strrchr();
		else if (strcmp(av[1], "strstr") == 0 || strcmp(av[1], "ft_strstr") == 0)
			test_ft_strstr();
		else if (strcmp(av[1], "strnstr") == 0 || strcmp(av[1], "ft_strnstr") == 0)
			test_ft_strnstr();
		else if (strcmp(av[1], "strcmp") == 0 || strcmp(av[1], "ft_strcmp") == 0)
			test_ft_strcmp();
		else if (strcmp(av[1], "strncmp") == 0 || strcmp(av[1], "ft_strncmp") == 0)
			test_ft_strncmp();
		else if (strcmp(av[1], "atoi") == 0 || strcmp(av[1], "ft_atoi") == 0)
			test_ft_atoi();
		else if (strcmp(av[1], "isalpha") == 0 || strcmp(av[1], "ft_isalpha") == 0)
			test_ft_isalpha();
		else if (strcmp(av[1], "isdigit") == 0 || strcmp(av[1], "ft_isdigit") == 0)
			test_ft_isdigit();
		else if (strcmp(av[1], "isalnum") == 0 || strcmp(av[1], "ft_isalnum") == 0)
			test_ft_isalnum();
		else if (strcmp(av[1], "isascii") == 0 || strcmp(av[1], "ft_isascii") == 0)
			test_ft_isascii();
		else if (strcmp(av[1], "isprint") == 0 || strcmp(av[1], "ft_isprint") == 0)
			test_ft_isprint();
		else if (strcmp(av[1], "toupper") == 0 || strcmp(av[1], "ft_toupper") == 0)
			test_ft_toupper();
		else if (strcmp(av[1], "tolower") == 0 || strcmp(av[1], "ft_tolower") == 0)
			test_ft_tolower();
		else if (strcmp(av[1], "memalloc") == 0 || strcmp(av[1], "ft_memalloc") == 0)
			test_ft_memalloc();
		else if (strcmp(av[1], "memdel") == 0 || strcmp(av[1], "ft_memdel") == 0)
			test_ft_memdel();
		else if (strcmp(av[1], "strnew") == 0 || strcmp(av[1], "ft_strnew") == 0)
			test_ft_strnew();
		else if (strcmp(av[1], "strdel") == 0 || strcmp(av[1], "ft_strdel") == 0)
			test_ft_strdel();
		else if (strcmp(av[1], "strclr") == 0 || strcmp(av[1], "ft_strclr") == 0)
			test_ft_strclr();
		//else if (strcmp(av[1], "striter") == 0 || strcmp(av[1], "ft_striter") == 0)
		//	test_ft_striter();
		//else if (strcmp(av[1], "striteri") == 0 || strcmp(av[1], "ft_striteri") == 0)
		//	test_ft_striteri();
		//else if (strcmp(av[1], "strmap") == 0 || strcmp(av[1], "ft_strmap") == 0)
		//	test_ft_strmap();
		//else if (strcmp(av[1], "strmapi") == 0 || strcmp(av[1], "ft_strmapi") == 0)
		//	test_ft_strmapi();
		//else if (strcmp(av[1], "strequ") == 0 || strcmp(av[1], "ft_strequ") == 0)
		//	test_ft_strequ();
		//else if (strcmp(av[1], "strnequ") == 0 || strcmp(av[1], "ft_strnequ") == 0)
		//	test_ft_strnequ();
		//else if (strcmp(av[1], "strsub") == 0 || strcmp(av[1], "ft_strsub") == 0)
		//	test_ft_strsub();
		//else if (strcmp(av[1], "strjoin") == 0 || strcmp(av[1], "ft_strjoin") == 0)
		//	test_ft_strjoin();
		//else if (strcmp(av[1], "strtrim") == 0 || strcmp(av[1], "ft_strtrim") == 0)
		//	test_ft_strtrim();
		//else if (strcmp(av[1], "strsplit") == 0 || strcmp(av[1], "ft_strsplit") == 0)
		//	test_ft_strsplit();
		//else if (strcmp(av[1], "itoa") == 0 || strcmp(av[1], "ft_itoa") == 0)
		//	test_ft_itoa();
		//else if (strcmp(av[1], "putchar") == 0 || strcmp(av[1], "ft_putchar") == 0)
		//	test_ft_putchar();
		//else if (strcmp(av[1], "putstr") == 0 || strcmp(av[1], "ft_putstr") == 0)
		//	test_ft_putstr();
		//else if (strcmp(av[1], "putendl") == 0 || strcmp(av[1], "ft_putendl") == 0)
		//	test_ft_putendl();
		//else if (strcmp(av[1], "putnbr") == 0 || strcmp(av[1], "ft_putnbr") == 0)
		//	test_ft_putnbr();
		//else if (strcmp(av[1], "putchar_fd") == 0 || strcmp(av[1], "ft_putchar_fd") == 0)
		//	test_ft_putchar_fd();
		//else if (strcmp(av[1], "putstr_fd") == 0 || strcmp(av[1], "ft_putstr_fd") == 0)
		//	test_ft_putstr_fd();
		//else if (strcmp(av[1], "putendl_fd") == 0 || strcmp(av[1], "ft_putendl_fd") == 0)
		//	test_ft_putendl_fd();
		//else if (strcmp(av[1], "putnbr_fd") == 0 || strcmp(av[1], "ft_putnbr_fd") == 0)
		//	test_ft_putnbr_fd();
		//else if (strcmp(av[1], "lstnew") == 0 || strcmp(av[1], "ft_lstnew") == 0)
		//	test_ft_lstnew();
		//else if (strcmp(av[1], "lstdelone") == 0 || strcmp(av[1], "ft_lstdelone") == 0)
		//	test_ft_lstdelone();
		//else if (strcmp(av[1], "lstdel") == 0 || strcmp(av[1], "ft_lstdel") == 0)
		//	test_ft_lstdel();
		//else if (strcmp(av[1], "lstadd") == 0 || strcmp(av[1], "ft_lstadd") == 0)
		//	test_ft_lstadd();
		//else if (strcmp(av[1], "lstiter") == 0 || strcmp(av[1], "ft_lstiter") == 0)
		//	test_ft_lstiter();
		//else if (strcmp(av[1], "lstmap") == 0 || strcmp(av[1], "ft_lstmap") == 0)
		//	test_ft_lstmap();
	}
	return (0);
}
