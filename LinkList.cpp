#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�
struct Node {
    int data;
    struct Node* next;
};

// ���嵥����
struct LinkList {
    struct Node* head;
};

// ��ʼ��������
void initList(struct LinkList* list) {
    list->head = NULL;
}

// ������ͷ������Ԫ��
void insertAtHead(struct LinkList* list, int data) {
    // �����½ڵ�
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // ���½ڵ���뵽����ͷ��
    newNode->next = list->head;
    list->head = newNode;
}

// ������β������Ԫ��
void insertAtTail(struct LinkList* list, int data) {
    // �����½ڵ�
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // �������Ϊ�գ����½ڵ���뵽ͷ��
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    // �ҵ�����β���ڵ㲢�����½ڵ�
    struct Node* currentNode = list->head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

// ��ȡ������
int getLength(struct LinkList* list) {
    int length = 0;
    struct Node* currentNode = list->head;

    while (currentNode != NULL) {
        length++;
        currentNode = currentNode->next;
    }

    return length;
}

// ��ȡ�����е�index���ڵ��ֵ
int getValue(struct LinkList* list, int index) {
    // �ж�index�Ƿ񳬳�������
    if (index < 0 || index >= getLength(list)) {
        printf("Invalid index!\n");
        return -1;
    }

    // �ҵ���index���ڵ㲢������ֵ
    struct Node* currentNode = list->head;
    for (int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

// ɾ�������е�index���ڵ�
void deleteNode(struct LinkList* list, int index) {
    // �ж�index�Ƿ񳬳�������
    if (index < 0 || index >= getLength(list)) {
        printf("Invalid index!\n");
        return;
    }

    // ɾ����index���ڵ�
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

// ��ӡ����
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
