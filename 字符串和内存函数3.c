#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//���������Ƶ��ַ����������� strncpy strncat strncmp


//strncpy
//char*strncpy(char* strDest , const char* strSource , size_t count);
//����num���ֽڴ�Դ�ַ������ռ�
//���Դ�ַ����ĳ���С��num,�򿽱���Դ�ַ���֮��,��Ŀ����׷��0,ֱ��num��

int main()
{
	char arr1[5] = "abc";
	char arr2[] = "hello bit";
	strncpy(arr1, arr2, 4); //size_t count��λ���ֽ�
	//ֻ����4���ֽ�,��hell(�����࿽��'\0')
	printf("%s\n", arr1);

	char arr3[10] = "abcdefg";
	char arr4[] = "sin";
	strncpy(arr3, arr4, 6); //��ʹsource��ַû��6���ַ�,��Ȼ���Կ���,ʣ�����'\0'����
	printf("%s\n", arr3);
	return 0;
}


//strncat(ָ������׷��)
//char* strncat(char* destination , const char* source , size_t num);

int main()
{
	char arr1[30] = "hello";
	char arr2[] = "world";
	strncat(arr1, arr2, 8);
	//��Ŀ�ĵص�ַ��'\0'��ʼ׷��
	//׷����֮�������������׷��һ��'\0'
	//����ӡ�Ľ��Ϊ"hellowor\0"
	//��ʹ��׷�ӵ��ֽ�Ϊ8���ֽ�,��source��ֻ��5���ֽ�,ֻ������׷�ӵ�һ��'\0',û��8���ֽ�Ҳ����׷��'\0'
	printf("%s\n", arr1);
	return 0;
}


//strncmp(ָ���ַ������ȱȽ�)
//int strncmp(const char* string1,const char* string2,size_t count);

int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "abcqwer";
	int ret = strcmp(p1, p2, 3);
	printf("%d\n", ret);
	return 0;
}