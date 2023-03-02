#include<stdio.h>

int Fib(int n) {//�ݹ��㷨���Fib

	if (n == 0) { return 0; }
	else if (n == 1) { return 1; }
	else{
		return Fib(n - 1) + Fib(n - 2);
	}
	return 0;
}

int Fib1(int n) {//�ǵݹ��㷨
	int result = 0;
	int fib1 = 0, fib2 = 1;

	if (n == 0) { return 0; }
	else if (n == 1) { return 1; }
	else {
		for (int i = 1; i < n; i++) {
			result = fib1 + fib2;
			fib1 = fib2;
			fib2 = result;
		}
	}
	return result;
}

int main() {
	int n, res1 = 0, res2 = 0;
	printf("������Fib(n)���Ա���nֵ��");
	scanf_s("%d", &n);
	if (n > 0 ) { 
		res1 = Fib(n);//�ݹ��㷨
		res2 = Fib1(n);//�ǵݹ��㷨
	}
	else{
		printf("���벻�Ϸ����֣�����������\n"); return 0;
	}
	printf("�ݹ�Fib(%d)Ϊ%d\n", n, res1);
	printf("�ǵݹ�Fib1(%d)Ϊ%d\n", n, res2);
	return 0;

}