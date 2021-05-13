#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

//内存操作函数 memcpy memmove memset memcmp
//前面的字符串函数针对的类型都为字符串类型,整型,浮点型,结构体型等不适用

//memcpy
//void* memcpy(void*destination , const void*source , size_t num); size_t num的单位是字节
//void* - 通用类型指针 - 无类型指针(不可以进行解引用操作)
//函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置
//这个函数在遇到'\0'的时候并不会停下来
//如果source和destination有任何的重叠,复制的结果都是未定义的

void* my_memcpy(void*dest, const void*src, size_t num)
{
	void* ret = dest;
	assert(dest && src);
	while (num--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest; //++dest无法实现,指针dest的返回类型是void*,无法执行++或--操作
		++(char*)src;
	}
	return ret;
}

struct S
{
	char name[20];
	int age;
};
int main()
{
	//int arr1[] = { 1,2,3,4,5 };
	//int arr2[5] = { 0 };
	//memcpy(arr2, arr1, sizeof(arr1));

	struct S arr3[] = { {"张三",20},{"李四",18},{"王五",30} };
	struct S arr4[] = { 0 };
	my_memcpy(arr4, arr3, sizeof(arr3));
	printf("%s,%d\n", arr4);

	return 0;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	//我想把arr数组中的1,2,3,4,5利用my_memcpy函数拷贝到arr数组中的3,4,5,6,7
	//也就是3,4,5,6,7做dest数组,1,2,3,4,5做src数组
	my_memcpy(arr+2,arr,20);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]); //但实际打印出的结果为1 2 1 2 1 2 1 8 9 10
	//可见如果destination数组和source有重叠或者说是有关联,则结果是有问题的
	return 0;
}


//所以就延伸出了另一个内存函数,专门用来处理内存重叠的情况
//memmove
//void* memmove(void*destination , const void*source , size_t count);  size_t count的单位是字节

void* my_memmove(void*dest, const void*src, size_t count)
{
	//如果有内存重叠的情况,视情况有可能从前向后拷贝,有可能从后向前拷贝
	//原则就是有重叠的部分先拷贝
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	//我想把arr数组中的4,5,6,7,8利用my_memmove函数拷贝到arr数组中的1,2,3,4,5
	//也就是1,2,3,4,5做dest数组,4,5,6,7,8做src数组
	my_memmove(arr + 2, arr, 20);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	//这时打印出的结果就为4 5 6 7 8 6 7 8 9 10
	return 0;
}