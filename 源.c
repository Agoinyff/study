#define _CRT_SECURE_NO_WARNINGS 0
//struct s
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct s arr[50];//50��struct s ���͵�����
//	//30 - �˷ѿռ�
//	//60 - �����ռ�
//	//һ���ֱ���������֧�ֱ䳤�����c99��׼
//
//
//	//���Դ��ڶ�̬�ڴ����   �ڶ�������ռ�    
//	return 0;
//}

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<errno.h>
#include<windows.h>
//int main()
//{
//	//���ڴ�����10�����Ϳռ�
//	//int* p = (int*)malloc(10 * sizeof(int));   //�����������ַ����ָ��p������ά��'
//	int* p = malloc(10 * sizeof(int));//��̬�ڴ濪��    ����ʧ�ܻ᷵�ؿ�ָ��
//	//int* p = malloc(INT_MAX);//����һ���������Ϳռ�   ���ܿ���0�ֽڵĿռ䣬�����ı�׼��δ����ģ�ȡ���ڱ�����
//	if (p == NULL)     //malloc��free�ǳɶ�ʹ�õģ�˭���٣�˭�ͷ�
//	{
//		//��ӡ�����ԭ���һ����ʽ
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//����ʹ�ÿռ�
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
//	//����̬����Ŀռ䲻��ʹ�õ�ʱ��
//	//��Ӧ�û�������ϵͳ
//	free(p);// ����һ������free��ר������������̬�ڴ���ͷźͻ��յ�
//	p = NULL;//
//	return 0;
//}

//calloc
//int main()
//{
//	//malloc(10*sizeof(int))  ����һ��ռ� ����ʼ��  Ϊ�����
//	int* p = calloc(10, sizeof(int));//����һ���ڴ�ռ�  ÿ���ֽڳ�ʼ��Ϊ0
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));   //����д���ִ�ӡ�����Ķ���ʮ��0
//		}
//	}
//	//�ͷſռ�
//	//free�����������ͷŶ�̬���ٵĿռ��
//	free(p);
//	p = NULL;
//	return 0;
//}

//realloc  ������̬�����ڴ�Ĵ�С
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
		//ֻ����ʹ��malloc���ٵĿռ�
		//�������20���ֽڲ����������ǵ�ʹ��Ҫ��
		//ϣ����������40���ֽڵĿռ� 
		//����Ϳ���ʹ��realloc��������̬���ٵ��ڴ�
		//
		//reallocʹ��ʱ��ע������
		//1.���pָ��Ŀռ�֮�����㹻���ڴ�ռ����׷�ӣ���ֱ��׷�ӣ��󷵻�p
		//2.���pָ��Ŀռ�֮��û���㹻���ڴ�ռ����׷�ӣ���realloc������������һ���µ��ڴ�����
		//����һ����������Ŀռ䣬����ԭ���ڴ��е����ݿ����������ͷžɵ��ڴ�ռ䣬��󷵻��¿��ٵ��ڴ�ռ�ĵ�ַ
		//3.����һ���µı���������realloc�����ķ���ֵ
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
	//�ͷ��ڴ�
	free(p);
	p = NULL;
	return 0;
}*/
//int main()
//{
//	int* p = realloc(NULL, 40);//������÷���mallocһ��
//	return 0;
//}
//ע������
/*1.�Զ�̬�����ڴ�ռ���Ҫ�ж��Ƿ�Ϊ��ָ��
2.����Խ�����
3.�ԷǶ�̬�����ڴ��free*/
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//ok?
//	p = NULL;
//	return 0;
//}
//4.ʹ��free�ͷŶ�̬�����ڴ��һ����
//
//int main()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//p����ָ��̬�ڴ����ʼλ��  ����ָ����ʼλ�ò����ͷ�
//	return 0;
//}
//5.��ͬһ�鶯̬�ڴ�Ķ���ͷ�    
//void test() 
//{
//	int* p = (int*)malloc(100);
//	free(p);
//  p = NULL;  Ҫ������������͵ð�p��Ϊ��ָ��
//	free(p);//�ظ��ͷ�
//}
//6.�Զ�̬�ڴ濪�������ͷţ��ڴ�й©��
//int main()
//{
//	while (1)
//	{
//		malloc(10);//���ϵ����ڴ�����ռ�
//		malloc(10);
//		malloc(10);
//		malloc(10);
//		malloc(10);
//	}
//	return 0;
//}