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
//void arrange(char(* str)[13], int L)
//{
//	//已有二维字符数组
//	//1.每一行
//	//2.每一行字符改变从中间向两端递进
//	//3.达到最大值后，从两端向中间递减
//	//4.打印字符数组
//	
//	//先用普通算法。
//	int line = (L - 1) / 2;//6 mid
//	//先换上面，后换下面。
//	int i = 0;
//	for (i = 0; i <= line; i++)
//	{
//		int j = 0;
//		for (j = 0; j < L ; j++)
//		{
//			if ((L - (2 * i + 1)) / 2 - 1 < j && j < (L - 1) / 2 + i + 1)
//			{
//				str[i][j] = '*';
//			}
//			else
//			{
//				str[i][j] = ' ';
//			}
//
//		}
//	}
//	for (i = 7; line < i && i < L; i++)
//	{
//		int j = 0;
//		for (j = 0; j < L; j++)
//		{
//			if (i % ((L + 1) / 2) < j && j < L - (i - line))
//			{
//				str[i][j] = '*';
//			}
//			else
//			{
//				str[i][j] = ' ';
//			}
//
//		}
//	}
//}
//
//void print(char(*pri)[13],int L)
//{
//	int i = 0;
//	for (i = 0; i < L; i++)
//	{
//		int j = 0;
//		for (j = 0; j < L; j++)
//		{
//			printf("%c", pri[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	char arr[13][13] = { 0 };
//	int line = sizeof(arr) / sizeof(arr[0]);
//	arrange(arr,line);
//	print(arr,line);
//	return 0;
//}

//void print(int(* pri)[3])
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", pri[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	print(arr);
//	return 0;
//}

//喝汽水问题，1元一瓶，两个瓶盖可以换一瓶汽水，20元可以喝多少瓶。

//int test(int x, int y)
//{
//	//1.先全部购买为汽水，相当于开局有20个瓶子。
//	//2.除2，每次得到的商累加加上余数，再除2，直到商小于1，不能兑换。
//	//3.每次被除数相加就是喝到的瓶数。
//	int sum = 0;
//	do
//	{
//		int n = x / y;
//		y = 2;
//		int loss = x % y;
//		x = n + loss;
//		sum += n;
//		if (x <= 1)
//		{
//			y = 0;
//		}
//
//	} while (y);
//	return sum;
//}
//
//int main()
//{
//	int i = 20;
//	int s = 1;
//	int n = test(i, s);
//	printf("可以喝%d瓶汽水。", n);
//	return 0;
//}

//写一个程序让数组中的奇数靠前，偶数靠后。

//void move(int* str, int n)
//{
//	//建立思维,怎么去调整？
//	//1.我们可以使用从两端向中间扫描的办法来进行交换
//	//2.如果交换，左边下标往右移动一位，否则不移动。
//	//3.界定范围，左>=右
//	int reight = n - 1;
//	int left = 0;
//	for (; reight > 1; reight--)
//	{
//		if (1 == str[reight] % 2)
//		{
//			for (left = 0; left <= reight; left++)
//			{
//				if (0 == str[left] % 2)
//				{
//					int tmp = str[left];
//					str[left] = str[reight];
//					str[reight] = tmp;
//				}
//			}
//		}
//	}
//	return 0;
//}
//
//void print(int* pri, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", pri[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr,sz);
//	return 0;
//}

//int main()
//{
//	int i = 2;
//	int j = 0;
//	if (i % 2 == 0)
//		printf("是偶数。");
//	else
//		printf("是奇数。");
//	return 0;
//}


//5名运动员进行百米冲刺比赛，5名运动员各说了一句话，里面有一半正确。
//a.b第2，我第3
//b.e第4，我第2
//c.d第2，我第1
//d.c第5，我第3
//e.a第1，我第4

//用程序判断真正的名次

//int main()
//{
//	//穷举法
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a < 6; a++)
//	{
//		for (b = 1; b < 6; b++)
//		{
//			for (c = 1; c < 6; c++)
//			{
//				for (d = 1; d < 6; d++)
//				{
//					for (e = 1; e < 6; e++)
//					{
//						if ((b == 2) + (a == 3) == 1 &&
//							(e == 4) + (b == 2) == 1 &&
//							(d == 2) + (c == 1) == 1 &&
//							(c == 5) + (d == 3) == 1 &&
//							(a == 1) + (e == 4) == 1 )
//						{
//							if (a * b * c * d * e == 120)
//								printf("a排第%d b排第%d c排第%d d排第%d e排第%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	//a.b第2，我第3
//    //b.e第4，我第2
//    //c.d第2，我第1
//    //d.c第5，我第3
//    //e.a第1，我第4
//    int a, b, c, d, e;
//    
//    for (a = 1; a < 6; a++)
//	{
//		for (b = 1; b < 6; b++)
//		{
//			for (c = 1; c < 6; c++)
//			{
//				for (d = 1; d < 6; d++)
//				{
//					for (e = 1; e < 6; e++)
//					{
//						if (((a == 3) || (b == 2) == 1) &&
//							((e == 4) || (b == 2) == 1) &&
//							((c == 1) || (d == 2) == 1) &&
//							((d == 3) || (c == 5) == 1) &&//应该是可以用||这个逻辑，但是确实结果有问题。
//							((e == 4) || (a == 1) == 1) &&//老师这里两个逻辑用相加判断是否等于1(是否为真)。
//							((a != b) && (b != c) && (c!= d) && (d != e)))//这里用5个数的积为120来判断。
//							printf("a排第%d b排第%d c排第%d d排第%d e排第%d\n", a, b, c, d, e);
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//写一个函数来判断一个字符串是否为另一个字符串旋转后所得到的

int my_cmp(char* x, char* y, int line)
{
	int n = 0;
	int i = 0;
	int j = line - 1;
	for (i = 0, j; i < j; i++, j--)
	{
		char tmp = x[i];
		x[i] = x[j];
		x[j] = tmp;
	}
	if (strcmp(x, y) == 0)
	{
		return 1;
	}
	else
		return 0;
}
int main()
{
	char a[] = "aabbccd";
	char b[] = "dccbbaa";
	int line1 = strlen(a);
	int line2 = strlen(b);
	//1.先判断两个字符串长度是否相等。相等可以比较，不相等比较无意义。
	//2.我们可以直接将一个字符串颠倒，然后使用strcmp函数对两个字符串进行对比。
	//3.返回1，字符串不相同，那么判定不是。如果返回值为0，那么字符串相同。  
	if (line1 != line2)
	{
		printf("字符串长度不同，对比无意义。");

	}
	else
	{
		int end = my_cmp(a, b, line1);
		if (end == 1)
		{
			printf("a和b是相互旋转后得到的字符串。\n");
		}
		else
		{
			printf("a和b不是相互旋转后得到的字符串。\n");
		}
	}
	return 0;
}