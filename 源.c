#define _CRT_SECURE_NO_WARNINGS 0
//struct s
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct s arr[50];//50个struct s 类型的数据
//	//30 - 浪费空间
//	//60 - 不够空间
//	//一部分编译器都不支持变长数组的c99标准
//
//
//	//所以存在动态内存分配   在堆上申请空间    
//	return 0;
//}

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<errno.h>
#include<windows.h>
//int main()
//{
//	//向内存申请10个整型空间
//	//int* p = (int*)malloc(10 * sizeof(int));   //把申请的这块地址交给指针p来进行维护'
//	int* p = malloc(10 * sizeof(int));//动态内存开辟    开辟失败会返回空指针
//	//int* p = malloc(INT_MAX);//开辟一个最大的整型空间   不能开辟0字节的空间，这样的标准是未定义的，取决于编译器
//	if (p == NULL)     //malloc和free是成对使用的，谁开辟，谁释放
//	{
//		//打印错误的原因的一个方式
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++) 
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//当动态申请的空间不再使用的时候
//	//就应该还给操作系统
//	free(p);// 另外一个函数free，专门是用来做动态内存的释放和回收的
//	p = NULL;//
//	return 0;
//}

//calloc
//int main()
//{
//	//malloc(10*sizeof(int))  开辟一块空间 不初始化  为随机数
//	int* p = calloc(10, sizeof(int));//开辟一块内存空间  每个字节初始化为0
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));   //这样写发现打印出来的都是十个0
//		}
//	}
//	//释放空间
//	//free函数是用来释放动态开辟的空间的
//	free(p);
//	p = NULL;
//	return 0;
//}

//realloc  调整动态开辟内存的大小
/*int main()
{
	int* p = (int*)malloc(20);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i) = i;
		}
		//只是在使用malloc开辟的空间
		//假设这里，20个字节不能满足我们的使用要求
		//希望我们能有40个字节的空间 
		//这里就可以使用realloc来调整动态开辟的内存
		//
		//realloc使用时的注意事项
		//1.如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
		//2.如果p指向的空间之后没有足够的内存空间可以追加，则realloc函数会重新找一块新的内存区域
		//开辟一块满足需求的空间，并把原来内存中的数据拷贝过来，释放旧的内存空间，最后返回新开辟的内存空间的地址
		//3.得用一个新的变量来接收realloc函数的返回值
		int* p2 = realloc(p, 40);
		if (p2 != NULL)
		{
			p = p2;
			for (i = 5; i < 10; i++)
			{
				*(p + i) = i;
			}
			for (i = 0; i < 10; i++)
			{
				printf("%d ", *(p + i));
			}
		}
		 
	}
	//释放内存
	free(p);
	p = NULL;
	return 0;
}*/
//int main()
//{
//	int* p = realloc(NULL, 40);//这里的用法和malloc一样
//	return 0;
//}
//注意事项
/*1.对动态申请内存空间需要判断是否为空指针
2.避免越界访问
3.对非动态开辟内存的free*/
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//ok?
//	p = NULL;
//	return 0;
//}
//4.使用free释放动态开辟内存的一部分
//
//int main()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//p不再指向动态内存的起始位置  必须指向起始位置才能释放
//	return 0;
//}
//5.对同一块动态内存的多次释放    
//void test() 
//{
//	int* p = (int*)malloc(100);
//	free(p);
//  p = NULL;  要想避免这个问题就得把p置为空指针
//	free(p);//重复释放
//}
//6.对动态内存开辟忘记释放（内存泄漏）
//int main()
//{
//	while (1)
//	{
//		malloc(10);//不断的向内存申请空间
//		malloc(10);
//		malloc(10);
//		malloc(10);
//		malloc(10);
//	}
//	return 0;
//}