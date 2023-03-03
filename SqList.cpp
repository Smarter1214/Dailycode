#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50 //��̬���䣬�������Ա���󳤶�
#define InitSize 100 //��̬�������Ա��ʼ������

//��̬����
typedef struct {
	int data[MaxSize];//˳����Ԫ��
	int length;//˳���ĵ�ǰ����
}SqList;//˳�������Ͷ���

//��̬����
typedef struct {
	int *data;//ָ��̬���������ָ��
	int MaxSize_SeqList;//˳����������
	int length;//˳���ĵ�ǰ����
}SeqList;//��̬����˳�������Ͷ���

//L.data = (int*)malloc(sizeof(int) * InitSize);//��̬�������


/*
	�����Ծ�̬����˳���SqListΪ��
*/

/*
* ��ʼ����̬��������Ա�
*/
void InitList(SqList& L) {
	L.length = 0;
}

/*
	���
*/

int Length(SqList L) {
	return L.length;
}

/*
	��ֵ����
*/
int LocateElem(SqList L,int e) {
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e)
			return i+1;//ע��������߱��ӳ��
	}
	return 0;
}

/*
	��λ����
*/
int GetElem(SqList L, int i) {
	if (i<1 || i>L.length)
		return 0;
	else
		return L.data[i - 1];//ע��ӳ��
}

/*
	�������
*/
bool ListInsert(SqList& L, int i, int e) {//iΪλ�ã�eΪֵ
	if (i<1 || i>L.length + 1)//i�Ƿ���Ч
		return false;
	if (L.length >= MaxSize)//�ڴ��Ƿ�����
		return false;
	for (int j = L.length; j >= i; j--) {//��ԭ��i��Ԫ�ؼ��Ժ�Ԫ���ƺ�һλ
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//����iֵ
	L.length++;
	return true;
}

/*
	ɾ������
*/
bool ListDelete(SqList& L, int i, int& e) {
	if (i<1 || i>L.length)//�ж�i�Ƿ���Ч
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++) {//iλ��֮���ǰ��
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

/*
	�������������ǰ��˳�����L������Ԫ��ֵ
*/

void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d\n", L.data[i]);
	}
}
/*
�ж��Ƿ�Ϊ��
*/
bool Empty(SqList L) {
	if (L.length == 0) {
		return true;
	}
	return false;
}
/*
�ݻ��ͷ�L�ռ䡪����̬������еĲ���
*/
//void DestroyList(SqList &L) {//ע��*�����
//	free(L);
//}

int main() {
	SqList L;
	InitList(L);
	//��ֵ
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
	printf("ɾ��������Ϊ%d", e);
	//DestroyList(L);
	return 0;
}
