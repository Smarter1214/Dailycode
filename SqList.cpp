#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50 //静态分配，定义线性表最大长度
#define InitSize 100 //动态分配线性表初始化长度

//静态分配
typedef struct {
	int data[MaxSize];//顺序表的元素
	int length;//顺序表的当前长度
}SqList;//顺序表的类型定义

//动态分配
typedef struct {
	int *data;//指向动态分配数组的指针
	int MaxSize_SeqList;//顺序表最大容量
	int length;//顺序表的当前长度
}SeqList;//动态分配顺序表的类型定义

//L.data = (int*)malloc(sizeof(int) * InitSize);//动态分配语句


/*
	以下以静态分配顺序表SqList为例
*/

/*
* 初始化静态分配的线性表
*/
void InitList(SqList& L) {
	L.length = 0;
}

/*
	求表长
*/

int Length(SqList L) {
	return L.length;
}

/*
	按值查找
*/
int LocateElem(SqList L,int e) {
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e)
			return i+1;//注意数组和线表的映射
	}
	return 0;
}

/*
	按位查找
*/
int GetElem(SqList L, int i) {
	if (i<1 || i>L.length)
		return 0;
	else
		return L.data[i - 1];//注意映射
}

/*
	插入操作
*/
bool ListInsert(SqList& L, int i, int e) {//i为位置，e为值
	if (i<1 || i>L.length + 1)//i是否有效
		return false;
	if (L.length >= MaxSize)//内存是否已满
		return false;
	for (int j = L.length; j >= i; j--) {//将原第i个元素及以后元素推后一位
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//插入i值
	L.length++;
	return true;
}

/*
	删除操作
*/
bool ListDelete(SqList& L, int i, int& e) {
	if (i<1 || i>L.length)//判断i是否有效
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++) {//i位置之后的前移
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

/*
	输出操作，按照前后顺序输出L的所有元素值
*/

void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d\n", L.data[i]);
	}
}
/*
判断是否为空
*/
bool Empty(SqList L) {
	if (L.length == 0) {
		return true;
	}
	return false;
}
/*
摧毁释放L空间——动态分配才有的操作
*/
//void DestroyList(SqList &L) {//注意*的添加
//	free(L);
//}

int main() {
	SqList L;
	InitList(L);
	//赋值
	for (int i = 0; i < 5; i++)
	{
		/* code */
		L.data[i] = i;
		L.length++;
	}
	int e;
	PrintList(L);
	ListDelete(L, 4, e);
	PrintList(L);
	printf("删除的数字为%d", e);
	//DestroyList(L);
	return 0;
}
