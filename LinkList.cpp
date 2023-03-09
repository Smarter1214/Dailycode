#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
struct Node {
    int data;
    struct Node* next;
};

// 定义单链表
struct LinkList {
    struct Node* head;
};

// 初始化单链表
void initList(struct LinkList* list) {
    list->head = NULL;
}

// 在链表头部插入元素
void insertAtHead(struct LinkList* list, int data) {
    // 创建新节点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // 将新节点插入到链表头部
    newNode->next = list->head;
    list->head = newNode;
}

// 在链表尾部插入元素
void insertAtTail(struct LinkList* list, int data) {
    // 创建新节点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // 如果链表为空，则将新节点插入到头部
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    // 找到链表尾部节点并插入新节点
    struct Node* currentNode = list->head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

// 获取链表长度
int getLength(struct LinkList* list) {
    int length = 0;
    struct Node* currentNode = list->head;

    while (currentNode != NULL) {
        length++;
        currentNode = currentNode->next;
    }

    return length;
}

// 获取链表中第index个节点的值
int getValue(struct LinkList* list, int index) {
    // 判断index是否超出链表长度
    if (index < 0 || index >= getLength(list)) {
        printf("Invalid index!\n");
        return -1;
    }

    // 找到第index个节点并返回其值
    struct Node* currentNode = list->head;
    for (int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

// 删除链表中第index个节点
void deleteNode(struct LinkList* list, int index) {
    // 判断index是否超出链表长度
    if (index < 0 || index >= getLength(list)) {
        printf("Invalid index!\n");
        return;
    }

    // 删除第index个节点
    struct Node* currentNode = list->head;
    if (index == 0) {
        list->head = currentNode->next;
        free(currentNode);
        return;
    }
    for (int i = 0; i < index - 1; i++) {
        currentNode = currentNode->next;
    }
    struct Node* deletedNode = currentNode->next;
    currentNode->next = deletedNode->next;
    free(deletedNode);
}

// 打印链表
void printList(struct LinkList* list) {
    struct Node* currentNode = list->head;

    printf("List: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

//
