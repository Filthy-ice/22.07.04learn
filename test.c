#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<math.h>

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
//void reverse(char* arr)
//{
//	assert(arr);
//	int len = strlen(arr);
//	char* left = arr;
//	char* reight = arr + len - 1;
//	while (left < reight)
//	{
//		char tmp = *left;
//		*left = *reight;
//		*reight = tmp;
//		left++;
//		reight--;
//	}
//	return 0;
//}
//
//int main()
//{
//	char arr[256];
//	scanf("%s", arr);
//	reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//��Sn=a+aa+aaa+aaaa+aaaaa,��һ������ǰ����֮�͡�
//int main()
//{
//	int a = 0;
//	int n = 0;
//	int i = 0;
//	int sum = 0;
//	int ret = 0;
//	scanf("%d%d", &a, &n);
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//��0~10000֮���ˮ�ɻ������磺153=1^3+5^3+3^3,
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100000; i++)
//	{
//		//1.��δ֪��λ��n��
//		int n = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp /= 10)//tmpԽ��ԽС��ֱ��whileѭ�����ֵС��10��
//		{
//			n++;
//		}
//        //2.����i��ÿһλn�η�֮�͡�
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//        //3.�Ա��Ƿ����i==sum��
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//дһ�������ӡ�����Ų���*��

//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//*************
// ***********
//  *********
//   *******
//    *****
//     ***
//      *

//������ʦ���õĴ���ӡ������д
//int main()
//{
//	//��ӡ�ϰ벿��
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		int j = 0;
//		//��ӡ�ո�
//		for (j = 0; j < line-1-i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2*i+1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//��ӡ�°벿��
//
//	for (i = 0; i < line; i++)
//	{
//		int j = 0;
//		//��ӡ�ո�
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * ( line-1-i )-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//�ö�ά�����д��
void arrange(char* str)
{
	//���ж�ά�ַ�����
	//1.ÿһ��
	//2.ÿһ���ַ��ı���м������˵ݽ�
	//3.�ﵽ���ֵ�󣬴��������м�ݼ�
	//4.��ӡ�ַ�����
	
}

int main()
{
	char arr[13][13] = { 0 };
	arrange(arr);
	return 0;
}