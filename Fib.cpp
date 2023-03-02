#include<stdio.h>

int Fib(int n) {//递归算法求解Fib

	if (n == 0) { return 0; }
	else if (n == 1) { return 1; }
	else{
		return Fib(n - 1) + Fib(n - 2);
	}
	return 0;
}

int Fib1(int n) {//非递归算法
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
	printf("请输入Fib(n)的自变量n值：");
	scanf_s("%d", &n);
	if (n > 0 ) { 
		res1 = Fib(n);//递归算法
		res2 = Fib1(n);//非递归算法
	}
	else{
		printf("输入不合法数字，请重新输入\n"); return 0;
	}
	printf("递归Fib(%d)为%d\n", n, res1);
	printf("非递归Fib1(%d)为%d\n", n, res2);
	return 0;

}