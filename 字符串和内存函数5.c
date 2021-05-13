#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

//�ڴ�������� memcpy memmove memset memcmp
//ǰ����ַ���������Ե����Ͷ�Ϊ�ַ�������,����,������,�ṹ���͵Ȳ�����

//memcpy
//void* memcpy(void*destination , const void*source , size_t num); size_t num�ĵ�λ���ֽ�
//void* - ͨ������ָ�� - ������ָ��(�����Խ��н����ò���)
//����memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ��
//�������������'\0'��ʱ�򲢲���ͣ����
//���source��destination���κε��ص�,���ƵĽ������δ�����

void* my_memcpy(void*dest, const void*src, size_t num)
{
	void* ret = dest;
	assert(dest && src);
	while (num--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest; //++dest�޷�ʵ��,ָ��dest�ķ���������void*,�޷�ִ��++��--����
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

	struct S arr3[] = { {"����",20},{"����",18},{"����",30} };
	struct S arr4[] = { 0 };
	my_memcpy(arr4, arr3, sizeof(arr3));
	printf("%s,%d\n", arr4);

	return 0;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	//�����arr�����е�1,2,3,4,5����my_memcpy����������arr�����е�3,4,5,6,7
	//Ҳ����3,4,5,6,7��dest����,1,2,3,4,5��src����
	my_memcpy(arr+2,arr,20);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]); //��ʵ�ʴ�ӡ���Ľ��Ϊ1 2 1 2 1 2 1 8 9 10
	//�ɼ����destination�����source���ص�����˵���й���,�������������
	return 0;
}


//���Ծ����������һ���ڴ溯��,ר�����������ڴ��ص������
//memmove
//void* memmove(void*destination , const void*source , size_t count);  size_t count�ĵ�λ���ֽ�

void* my_memmove(void*dest, const void*src, size_t count)
{
	//������ڴ��ص������,������п��ܴ�ǰ��󿽱�,�п��ܴӺ���ǰ����
	//ԭ��������ص��Ĳ����ȿ���
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	//�����arr�����е�4,5,6,7,8����my_memmove����������arr�����е�1,2,3,4,5
	//Ҳ����1,2,3,4,5��dest����,4,5,6,7,8��src����
	my_memmove(arr + 2, arr, 20);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	//��ʱ��ӡ���Ľ����Ϊ4 5 6 7 8 6 7 8 9 10
	return 0;
}