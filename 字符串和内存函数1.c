#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

//字符函数和字符串函数
//重点
//1.求字符串长度 strlen
//2.长度不受限制的字符串函数 strcpy strcat strcmp
//3.长度受限制的字符串函数介绍 strncpy strncat strncmp
//4.字符串查找 strstr strtok
//5.错误信息报告 strerror
//6.字符操作
//7.内存操作函数 memcpy memmove memset memcmp

//函数介绍 - strlen
//size_t strlen(const char*str);
//字符串以'\0'作为结束标志,strlen函数返回的是在字符串中'\0'前面出现的字符个数(不包含'\0')
//参数指向的字符串必须要以'\0'结束
//注意函数的返回值为size_t,是无符号的(易错)

//1.计数器的方法
//2.递归的方法
//3.指针 - 指针
int my_strlen(const char* str) //重要,
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
	int len = my_strlen("abcdef");  //输出的结果为6
	//char arr[] = { 'a','b','c','d','e','f' };
	//int len = strlen(arr); //输出的方式没变,但是此时的\0位置不固定
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
	//打印的结果为xixi
	//直接调用库函数中的strlen,它的返回值类型为size_t(size_t的定义类型为unsigned int)
	//而上面自己定义的my_strlen函数返回值类型为int
	return 0;
}