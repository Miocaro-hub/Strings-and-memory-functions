#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

//�ַ��������ַ�������
//�ص�
//1.���ַ������� strlen
//2.���Ȳ������Ƶ��ַ������� strcpy strcat strcmp
//3.���������Ƶ��ַ����������� strncpy strncat strncmp
//4.�ַ������� strstr strtok
//5.������Ϣ���� strerror
//6.�ַ�����
//7.�ڴ�������� memcpy memmove memset memcmp

//�������� - strlen
//size_t strlen(const char*str);
//�ַ�����'\0'��Ϊ������־,strlen�������ص������ַ�����'\0'ǰ����ֵ��ַ�����(������'\0')
//����ָ����ַ�������Ҫ��'\0'����
//ע�⺯���ķ���ֵΪsize_t,���޷��ŵ�(�״�)

//1.�������ķ���
//2.�ݹ�ķ���
//3.ָ�� - ָ��
int my_strlen(const char* str) //��Ҫ,
{
	int count = 0;
	assert(str != NULL);
	while (*str != '\0')//while(*str)
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	int len = my_strlen("abcdef");  //����Ľ��Ϊ6
	//char arr[] = { 'a','b','c','d','e','f' };
	//int len = strlen(arr); //����ķ�ʽû��,���Ǵ�ʱ��\0λ�ò��̶�
	printf("%d\n", len);
	return 0;
}

int main()
{
	if (strlen("abc") - strlen("abcdef") > 0)
	{
		printf("xixi\n");
	}
	else
	{
		printf("haha\n");
	}
	//��ӡ�Ľ��Ϊxixi
	//ֱ�ӵ��ÿ⺯���е�strlen,���ķ���ֵ����Ϊsize_t(size_t�Ķ�������Ϊunsigned int)
	//�������Լ������my_strlen��������ֵ����Ϊint
	return 0;
}