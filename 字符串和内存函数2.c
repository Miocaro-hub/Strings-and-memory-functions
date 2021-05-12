#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>

//长度不受限制的字符串函数 strcpy strcat strcmp

//strcpy(字符串拷贝)
//char* strcpy(char*destination,const char*soure)
//源字符串必须以'\0'结束
//会将源字符串的'\0'拷贝到目标空间
//目标空间必须足够大,以确保能存放源字符串
//目标空间必须可变

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
	*dest = *src; //拷贝'\0'
	return ret;
}


//还可以写的更巧妙
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	//assert(dest && src)
	char* ret = dest;
	whlie(*dest++ = *src++); //拷贝src指向的字符串到dest指向的空间(包含'\0')
	{
		;
	}
	return ret; //返回目的空间的起始地址
}
int main()
{
	char arr1[] = { "abcdefghi" };
	char arr2[] = { "bit" };
	//char arr2[] = {'b','i','t'}; err,没有定义'\0'的位置
	//char arr1[] = {'a'}; err,arr1的空间不够大,无法将arr2全部拷贝进去
	//char* p = {"abcdefgh"}; err,p指向的事常量字符串,无法更改

	//strcpy(arr1,arr2);
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}



//strcat(字符串追加)
//char* strcat(char*destination , const char*source);
//源字符串必须以'\0'结束
//会将源字符串的'\0'拷贝到目标空间
//目标空间必须足够大,以确保能存放源字符串
//字符串自己给自己追加(会出问题的,追加是从源字符串的'\0'开始追加,但一旦覆盖了'\0',源字符串也做目的字符串,'\0'也消失了)

char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src);
	char* ret = dest;
	//assert(dest && src);

	//第一步,找到目的字符串的'\0'
	while (*dest != '\0');
	{
		dest++;
	}
	//第二步再追加(本质就是从'\0'开始拷贝)
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
	//strcat(arr1, arr2);虽然追加成功过,但会导致程序崩溃,原因是因为arr1中的空间不够,导致越界访问
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}



//strcmp(字符串比较)
//int strcmp(const char* str1 , const char* str2)
//标准规定:
//第一个字符串大于第二个字符串,则返回大于0的数字
//第一个字符串等于第二个字符串,则返回0
//第一个字符串小于第二个字符串,则返回小于0的数字

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);

	whlie(*str1 == *str2); //比较
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
	//return (*str1 - *str2); 用于不止返回1或-1,而是返回大于0或是小于0
}
int main()
{
	char* p1 = "abcdef";
	char* p2 = "abqwer";
	int ret = my_strcmp(p1, p2); //两个字符串比较并不是比较长度,而是比较字符
	//在比较时,设置一个计数器,从零开始,一直循环到最短的那个字符结束,一位一位进行比较
    //如果 字符串1的第n位的ASCII码值 等于 字符串2的第n位的ASCII码值则 继续比较下一位
	//如果 字符串1的第n位的ASCII码值 大于 字符串2的第n位的ASCII码值则 输出结果:1,表示字符串1 > 字符串2
	//如果 字符串1的第n位的ASCII码值 小于 字符串2的第n位的ASCII码值则 输出结果:-1 表示字符串1 < 字符串2
	//如果 每一位的ASCII码值都相等,而且长度相同,则 输出结果:0 表示字符串1 == 字符串2
	//不同的电脑系统,不同编译器比较完的返回值不一定都是1,0,-1,切忌不能通过返回值1,0,-1来输出值
	printf("%d\n", ret);
	return 0;
}

//这三个函数长度都不受限制,如果字符的空间不符合条件,导致程序挂掉,但依然可以让结果执行出来,不安全