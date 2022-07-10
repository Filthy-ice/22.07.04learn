#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>

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