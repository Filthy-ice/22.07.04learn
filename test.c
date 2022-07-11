#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<math.h>

//第一题
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
//
////假设p的值为0x100000。如下表达式的值分别为多少？
////已知，结构体类型Test大小为20个字节。
//
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);//0x100014
//	printf("%p\n", (unsigned long)p + 0x1);//0x100008 错 0x100001,因为此时p已经相当于被赋值了，0x100000转化成10进制，然后加1，那就是值+1。
//	printf("%p\n", (unsigned int*)p + 0x1);//0x100004
//	return 0;
//}

//第二题
//int main()
//{
//	//使用内存的小端存储解决这两个问题。
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);//此时相当于ptr1是从a的地址向后移动整体a地址的大小。
//	int* ptr2 = (int*)((int)a + 1);//需要写出小端存储的内存排列。
//	//01 00 00 00    02 00 00 00   03 00 00 00   04 00 00 00
//	//(int)a+1是将a的元素首地址强制转化为整形(a原本的元素大小也是整形)，那么(int)a=1，+1=2，然后强制转化为地址。
//	//例如0x10000001向后移动一位及0x100000002而ptr2是指针，那么从内存第二存储点开始，及打印的是 00 00 00 02
//	//但该表示方式仍为小端存储方式，那么本身应该是0x02000000，转化为10进制，非常大。33554432
//	printf("%x %x", ptr1[-1], ptr2);//输出4,2000000(HEX)
//	return 0;
//}

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//
//	printf("%s\n", **++cpp);
//	printf("%s\n", *--*++cpp+3);//用画内存来具体观察。“ER”
//	printf("%s\n", *cpp[-2]+3);//ST
//	printf("%s\n", cpp[-1][-1]+1);//EW
//	return 0;
//}



//写一个逆序函数让数组中的内容逆序排列。
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

//如Sn=a+aa+aaa+aaaa+aaaaa,求一个数的前五项之和。
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

//求0~10000之间的水仙花数。如：153=1^3+5^3+3^3,
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100000; i++)
//	{
//		//1.求未知的位数n。
//		int n = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp /= 10)//tmp越变越小，直至while循环里的值小于10。
//		{
//			n++;
//		}
//        //2.计算i的每一位n次方之和。
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//        //3.对比是否符合i==sum。
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//写一个程序打印菱形排布的*。

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

//先用老师所用的纯打印方法编写
//int main()
//{
//	//打印上半部分
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		int j = 0;
//		//打印空格
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
//	//打印下半部分
//
//	for (i = 0; i < line; i++)
//	{
//		int j = 0;
//		//打印空格
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

//用二维数组编写。
void arrange(char* str)
{
	//已有二维字符数组
	//1.每一行
	//2.每一行字符改变从中间向两端递进
	//3.达到最大值后，从两端向中间递减
	//4.打印字符数组
	
}

int main()
{
	char arr[13][13] = { 0 };
	arrange(arr);
	return 0;
}