#define _CRT_SECURE_NO_WARNINGS
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>

//字符串查找 strstr strtok


//strstr(查找字符串)
//char* strstr(const char*string,const char* strCharSet);

char* my_strstr(const char*string, const char* strCharSet)
{
	assert(string && strCharSet);
	char* s1 = NULL; //之所以要再创建一个指针,是为了不移动string和strCharSet指针,作为标杆记录位置,方便后面的使用
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
	return NULL;//找不到子串
}
//还有一种KMP算法可以参考

int main()
{
	char* p1 = "abcdedef";
	char* p2 = "def";
	//char* p3 ="abcdefabcdef";  //若从p3中查找字符串,打印的结果为"defabcdef",从第一个'd'的地址开始向后打印
    char* ret = my_strstr(p1, p2); //接收的返回值为'd'的地址
	if (ret == NULL)
		printf("子串不存在\n");
	else
		printf("%s\n", ret); 
	return 0;
}


//strtok
//char* strtok(char*str , const char* sep); sep参数是个字符串,定义了用作分隔符的字符集合
//第一个参数指定一个字符串,它包含了0个或多个由sep字符串中一个或者多个分隔符分割的标记
//strtok函数找到str中的下一个标记,并将其用\0结尾,返回一个指向这个标记的指针
//(注:strtok函数会改变被操作的字符串,所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改)
//strtok函数的第一个参数不为NULL,函数将找到str中第一个标记,strtok函数将保存它再字符串中的位置
//strtok函数的第一个参数为NULL,函数将在同一个字符串中被保存的位置开始,查找下一个标记
//如果字符串中不存在更多的标记,则返回NULL指针

int main()
{
	//192.168.31.121
	//192 168 31 121 - strtok
	//ip地址的表示方式为点分十进制的表示方式
	char arr[] = "syy@bitedu.tech";
	char* p = "@.";
	//strtok(arr, p);

	char buf[1024] = { 0 };
	strcpy(buf, arr);

	//切割buf中的字符串
	char*ret =  strtok(arr, p); //切割完第一段之后strtok函数会自己记住改动的\0的位置
	printf("%s\n", ret); //此时打印的结果为syy
	ret = strtok(NULL, p);
	printf("%s\n", ret); //打印的结果为bitedu
	ret = strtok(NULL, p);
	printf("%s\n", ret); //打印的结果为tech

	//更好的切割buf中的字符串
	char* ret = NULL;
	for (ret = strtok(arr, p); ret != NULL;ret = strtok(NULL,p))
	{
		printf("%s\n", ret);
	}
	return 0;
}


//错误信息报告  strerror
//char* strerror(int errnum);
//返回错误码所对应的错误信息

int main()
{
	//char* str = strerror(0);
	char* str = strerror(errno);
	//errno是一个全局的错误码的变量
	//当C语言的库函数在执行的过程中发生了错误,就会把对应的错误码赋值到erron中
	printf("%s\n", str); 

	//int num为错误码 - 后面的为错误信息
	//0 - No error
	//1 - Operation not permitted
	//2 - No such file or directory
	//...
	return 0;
}

int main()
{
	//打开文件
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

//字符操作
//还有一种函数叫字符分类函数,可以自己查找资料
//字符转换函数tolower(大写字母转小写),toupper(小写字母转大写)等
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