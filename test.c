#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>

//��һ��
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
//
////����p��ֵΪ0x100000�����±��ʽ��ֵ�ֱ�Ϊ���٣�
////��֪���ṹ������Test��СΪ20���ֽڡ�
//
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);//0x100014
//	printf("%p\n", (unsigned long)p + 0x1);//0x100008 �� 0x100001,��Ϊ��ʱp�Ѿ��൱�ڱ���ֵ�ˣ�0x100000ת����10���ƣ�Ȼ���1���Ǿ���ֵ+1��
//	printf("%p\n", (unsigned int*)p + 0x1);//0x100004
//	return 0;
//}

//�ڶ���
//int main()
//{
//	//ʹ���ڴ��С�˴洢������������⡣
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);//��ʱ�൱��ptr1�Ǵ�a�ĵ�ַ����ƶ�����a��ַ�Ĵ�С��
//	int* ptr2 = (int*)((int)a + 1);//��Ҫд��С�˴洢���ڴ����С�
//	//01 00 00 00    02 00 00 00   03 00 00 00   04 00 00 00
//	//(int)a+1�ǽ�a��Ԫ���׵�ַǿ��ת��Ϊ����(aԭ����Ԫ�ش�СҲ������)����ô(int)a=1��+1=2��Ȼ��ǿ��ת��Ϊ��ַ��
//	//����0x10000001����ƶ�һλ��0x100000002��ptr2��ָ�룬��ô���ڴ�ڶ��洢�㿪ʼ������ӡ���� 00 00 00 02
//	//���ñ�ʾ��ʽ��ΪС�˴洢��ʽ����ô����Ӧ����0x02000000��ת��Ϊ10���ƣ��ǳ���33554432
//	printf("%x %x", ptr1[-1], ptr2);//���4,2000000(HEX)
//	return 0;
//}

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//
//	printf("%s\n", **++cpp);
//	printf("%s\n", *--*++cpp+3);//�û��ڴ�������۲졣��ER��
//	printf("%s\n", *cpp[-2]+3);//ST
//	printf("%s\n", cpp[-1][-1]+1);//EW
//	return 0;
//}



//дһ���������������е������������С�
void reverse(char* arr)
{
	assert(arr);
	int len = strlen(arr);
	char* left = arr;
	char* reight = arr + len - 1;
	while (left < reight)
	{
		char tmp = *left;
		*left = *reight;
		*reight = tmp;
		left++;
		reight--;
	}
	return 0;
}

int main()
{
	char arr[256];
	scanf("%s", arr);
	reverse(arr);
	printf("%s\n", arr);
	return 0;
}