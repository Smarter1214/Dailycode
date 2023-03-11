#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    int data[MAX_STACK_SIZE];
} Stack;

// 初始化栈
void initStack(Stack* s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 判断栈是否已满
int isFull(Stack* s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// 入栈
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++(s->top)] = value;
}

// 出栈
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

// 获取栈顶元素
int top(Stack* s) {
    if (isEmpty(s)) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top];
}

// 打印栈中元素
void printStack(Stack* s) {
    int i;
    printf("Stack: ");
    for (i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printStack(&s);
    printf("Top element: %d\n", top(&s));
    pop(&s);
    printStack(&s);
    printf("Top element: %d\n", top(&s));
    return 0;
}
