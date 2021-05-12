#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//长度受限制的字符串函数介绍 strncpy strncat strncmp


//strncpy
//char*strncpy(char* strDest , const char* strSource , size_t count);
//拷贝num个字节从源字符串到空间
//如果源字符串的长度小于num,则拷贝完源字符串之后,在目标后边追加0,直到num个

int main()
{
	char arr1[5] = "abc";
	char arr2[] = "hello bit";
	strncpy(arr1, arr2, 4); //size_t count单位是字节
	//只拷贝4个字节,即hell(不多余拷贝'\0')
	printf("%s\n", arr1);

	char arr3[10] = "abcdefg";
	char arr4[] = "sin";
	strncpy(arr3, arr4, 6); //即使source地址没有6个字符,依然可以拷贝,剩余的用'\0'补充
	printf("%s\n", arr3);
	return 0;
}


//strncat(指定长度追加)
//char* strncat(char* destination , const char* source , size_t num);

int main()
{
	char arr1[30] = "hello";
	char arr2[] = "world";
	strncat(arr1, arr2, 8);
	//从目的地地址的'\0'开始追加
	//追加完之后后面主动的再追加一个'\0'
	//即打印的结果为"hellowor\0"
	//即使让追加的字节为8个字节,但source中只有5个字节,只有主动追加的一个'\0',没有8个字节也不多追加'\0'
	printf("%s\n", arr1);
	return 0;
}


//strncmp(指定字符串长度比较)
//int strncmp(const char* string1,const char* string2,size_t count);

int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "abcqwer";
	int ret = strcmp(p1, p2, 3);
	printf("%d\n", ret);
	return 0;
}