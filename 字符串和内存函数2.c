#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>

//���Ȳ������Ƶ��ַ������� strcpy strcat strcmp

//strcpy(�ַ�������)
//char* strcpy(char*destination,const char*soure)
//Դ�ַ���������'\0'����
//�ὫԴ�ַ�����'\0'������Ŀ��ռ�
//Ŀ��ռ�����㹻��,��ȷ���ܴ��Դ�ַ���
//Ŀ��ռ����ɱ�

char* my_strcpy(char*dest, const char*src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	whlie(*src != '\0'); //whlie(*src)
	{
		//*dest = *src;
		//dest++;
		//src++;
		*dest++ = *src++;
	}
	*dest = *src; //����'\0'
	return ret;
}


//������д�ĸ�����
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	//assert(dest && src)
	char* ret = dest;
	whlie(*dest++ = *src++); //����srcָ����ַ�����destָ��Ŀռ�(����'\0')
	{
		;
	}
	return ret; //����Ŀ�Ŀռ����ʼ��ַ
}
int main()
{
	char arr1[] = { "abcdefghi" };
	char arr2[] = { "bit" };
	//char arr2[] = {'b','i','t'}; err,û�ж���'\0'��λ��
	//char arr1[] = {'a'}; err,arr1�Ŀռ䲻����,�޷���arr2ȫ��������ȥ
	//char* p = {"abcdefgh"}; err,pָ����³����ַ���,�޷�����

	//strcpy(arr1,arr2);
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}



//strcat(�ַ���׷��)
//char* strcat(char*destination , const char*source);
//Դ�ַ���������'\0'����
//�ὫԴ�ַ�����'\0'������Ŀ��ռ�
//Ŀ��ռ�����㹻��,��ȷ���ܴ��Դ�ַ���
//�ַ����Լ����Լ�׷��(��������,׷���Ǵ�Դ�ַ�����'\0'��ʼ׷��,��һ��������'\0',Դ�ַ���Ҳ��Ŀ���ַ���,'\0'Ҳ��ʧ��)

char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src);
	char* ret = dest;
	//assert(dest && src);

	//��һ��,�ҵ�Ŀ���ַ�����'\0'
	while (*dest != '\0');
	{
		dest++;
	}
	//�ڶ�����׷��(���ʾ��Ǵ�'\0'��ʼ����)
	whlie(*dest++ = *src++);
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[20] = "hello";
	char arr2[] = "world";
	//strcat(arr1, arr2);��Ȼ׷�ӳɹ���,���ᵼ�³������,ԭ������Ϊarr1�еĿռ䲻��,����Խ�����
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}



//strcmp(�ַ����Ƚ�)
//int strcmp(const char* str1 , const char* str2)
//��׼�涨:
//��һ���ַ������ڵڶ����ַ���,�򷵻ش���0������
//��һ���ַ������ڵڶ����ַ���,�򷵻�0
//��һ���ַ���С�ڵڶ����ַ���,�򷵻�С��0������

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);

	whlie(*str1 == *str2); //�Ƚ�
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	//return (*str1 - *str2); ���ڲ�ֹ����1��-1,���Ƿ��ش���0����С��0
}
int main()
{
	char* p1 = "abcdef";
	char* p2 = "abqwer";
	int ret = my_strcmp(p1, p2); //�����ַ����Ƚϲ����ǱȽϳ���,���ǱȽ��ַ�
	//�ڱȽ�ʱ,����һ��������,���㿪ʼ,һֱѭ������̵��Ǹ��ַ�����,һλһλ���бȽ�
    //��� �ַ���1�ĵ�nλ��ASCII��ֵ ���� �ַ���2�ĵ�nλ��ASCII��ֵ�� �����Ƚ���һλ
	//��� �ַ���1�ĵ�nλ��ASCII��ֵ ���� �ַ���2�ĵ�nλ��ASCII��ֵ�� ������:1,��ʾ�ַ���1 > �ַ���2
	//��� �ַ���1�ĵ�nλ��ASCII��ֵ С�� �ַ���2�ĵ�nλ��ASCII��ֵ�� ������:-1 ��ʾ�ַ���1 < �ַ���2
	//��� ÿһλ��ASCII��ֵ�����,���ҳ�����ͬ,�� ������:0 ��ʾ�ַ���1 == �ַ���2
	//��ͬ�ĵ���ϵͳ,��ͬ�������Ƚ���ķ���ֵ��һ������1,0,-1,�мɲ���ͨ������ֵ1,0,-1�����ֵ
	printf("%d\n", ret);
	return 0;
}

//�������������ȶ���������,����ַ��Ŀռ䲻��������,���³���ҵ�,����Ȼ�����ý��ִ�г���,����ȫ