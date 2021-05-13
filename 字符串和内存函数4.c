#define _CRT_SECURE_NO_WARNINGS
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>

//�ַ������� strstr strtok


//strstr(�����ַ���)
//char* strstr(const char*string,const char* strCharSet);

char* my_strstr(const char*string, const char* strCharSet)
{
	assert(string && strCharSet);
	char* s1 = NULL; //֮����Ҫ�ٴ���һ��ָ��,��Ϊ�˲��ƶ�string��strCharSetָ��,��Ϊ��˼�¼λ��,��������ʹ��
	char* s2 = NULL;
	char* cur = string;
	if (*strCharSet == '\0') //if(!*strCharSet)
		return  (char*)string;
	while (*cur)
	{
		s1 = cur;
		s2 = (char* )strCharSet;
		while((*s1 != '\0') && (*s2!= '\0') && (*s1 == *s2)) //while(*s1 && *s2 && !(*s1 - *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0') //if(!*s2)
		{
			return cur;
		}
		cur++;
	}
	return NULL;//�Ҳ����Ӵ�
}
//����һ��KMP�㷨���Բο�

int main()
{
	char* p1 = "abcdedef";
	char* p2 = "def";
	//char* p3 ="abcdefabcdef";  //����p3�в����ַ���,��ӡ�Ľ��Ϊ"defabcdef",�ӵ�һ��'d'�ĵ�ַ��ʼ����ӡ
    char* ret = my_strstr(p1, p2); //���յķ���ֵΪ'd'�ĵ�ַ
	if (ret == NULL)
		printf("�Ӵ�������\n");
	else
		printf("%s\n", ret); 
	return 0;
}


//strtok
//char* strtok(char*str , const char* sep); sep�����Ǹ��ַ���,�����������ָ������ַ�����
//��һ������ָ��һ���ַ���,��������0��������sep�ַ�����һ�����߶���ָ����ָ�ı��
//strtok�����ҵ�str�е���һ�����,��������\0��β,����һ��ָ�������ǵ�ָ��
//(ע:strtok������ı䱻�������ַ���,������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸�)
//strtok�����ĵ�һ��������ΪNULL,�������ҵ�str�е�һ�����,strtok���������������ַ����е�λ��
//strtok�����ĵ�һ������ΪNULL,��������ͬһ���ַ����б������λ�ÿ�ʼ,������һ�����
//����ַ����в����ڸ���ı��,�򷵻�NULLָ��

int main()
{
	//192.168.31.121
	//192 168 31 121 - strtok
	//ip��ַ�ı�ʾ��ʽΪ���ʮ���Ƶı�ʾ��ʽ
	char arr[] = "syy@bitedu.tech";
	char* p = "@.";
	//strtok(arr, p);

	char buf[1024] = { 0 };
	strcpy(buf, arr);

	//�и�buf�е��ַ���
	char*ret =  strtok(arr, p); //�и����һ��֮��strtok�������Լ���ס�Ķ���\0��λ��
	printf("%s\n", ret); //��ʱ��ӡ�Ľ��Ϊsyy
	ret = strtok(NULL, p);
	printf("%s\n", ret); //��ӡ�Ľ��Ϊbitedu
	ret = strtok(NULL, p);
	printf("%s\n", ret); //��ӡ�Ľ��Ϊtech

	//���õ��и�buf�е��ַ���
	char* ret = NULL;
	for (ret = strtok(arr, p); ret != NULL;ret = strtok(NULL,p))
	{
		printf("%s\n", ret);
	}
	return 0;
}


//������Ϣ����  strerror
//char* strerror(int errnum);
//���ش���������Ӧ�Ĵ�����Ϣ

int main()
{
	//char* str = strerror(0);
	char* str = strerror(errno);
	//errno��һ��ȫ�ֵĴ�����ı���
	//��C���ԵĿ⺯����ִ�еĹ����з����˴���,�ͻ�Ѷ�Ӧ�Ĵ����븳ֵ��erron��
	printf("%s\n", str); 

	//int numΪ������ - �����Ϊ������Ϣ
	//0 - No error
	//1 - Operation not permitted
	//2 - No such file or directory
	//...
	return 0;
}

int main()
{
	//���ļ�
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s/n", strerror(errno));
	}
	else
	{
		printf("open file success\n");
	}
	return 0;
}

//�ַ�����
//����һ�ֺ������ַ����ຯ��,�����Լ���������
//�ַ�ת������tolower(��д��ĸתСд),toupper(Сд��ĸת��д)��
#include<ctype.h>
int main()
{
	//char ch = tolower('Q');
	//putchar(ch);

	char arr[] = "I Am a Student";
	int i = 0;
	while (arr[i])
	{
		if (isupper(arr[i]));
		{
			arr[i] = tolower(arr[i]);
		}
		i++;
	}
	printf("%s\n", arr);
	return 0;
}