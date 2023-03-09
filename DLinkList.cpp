#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// 定义双向链表
struct DLinkList {
    struct Node* head;
    struct Node* tail;
};

// 初始化双向链表
void initList(struct DLinkList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// 在链表头部插入元素
void insertAtHead(struct DLinkList* list, int data) {
    // 创建新节点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;

    // 将新节点插入到链表头部
    if (list->head == NULL) {
        newNode->next = NULL;
        list->tail = newNode;
    }
    else {
        newNode->next = list->head;
        list->head->prev = newNode;
    }
    list->head = newNode;
}

// 在链表尾部插入元素
void insertAtTail(struct DLinkList* list, int data) {
    // 创建新节点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // 将新节点插入到链表尾部
    if (list->tail == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
    }
    else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
    }
    list->tail = newNode;
}

// 获取链表长度
int getLength(struct DLinkList* list) {
    int length = 0;
    struct Node* currentNode = list->head;

    while (currentNode != NULL) {
        length++;
        currentNode = currentNode->next;
    }

    return length;
}

// 获取链表中第index个节点的值
int getValue(struct DLinkList* list, int index) {
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
void deleteNode(struct DLinkList* list, int index) {
    // 判断index是否超出链表长度
    if (index < 0 || index >= getLength(list)) {
        printf("Invalid index!\n");
        return;
    }

    // 删除第index个节点
    struct Node* currentNode = list->head;
    if (index == 0) {
        list->head = currentNode->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
        else {
            list->head->prev = NULL;
        }
        free(currentNode);
        return;
    }
    for (int i = 0; i < index - 1; i++) {
        currentNode = currentNode->next;
    }
    struct Node* deletedNode = currentNode->next;
    currentNode->next = deletedNode->next;
    if (deletedNode == list->tail) {
        list->tail = currentNode;
    }
    else {
        deletedNode->next->prev = currentNode;
    }
    free(deletedNode);
}

// 打印链表中所有元素
void printList(struct DLinkList* list) {
    struct Node* currentNode = list->head;
    printf("DLinkList: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}
    // 清空链表
    void clearList(struct DLinkList* list) {
        struct Node* currentNode = list->head;
        while (currentNode != NULL) {
            struct Node* tempNode = currentNode;
            currentNode = currentNode->next;
            free(tempNode);
        }

        list->head = NULL;
        list->tail = NULL;
    }
    int main() {
        // 初始化双向链表
        struct DLinkList list;
        initList(&list);
        // 在链表头部插入元素
        insertAtHead(&list, 1);
        insertAtHead(&list, 2);
        insertAtHead(&list, 3);
        printf("After inserting at head:\n");
        printList(&list);

        // 在链表尾部插入元素
        insertAtTail(&list, 4);
        insertAtTail(&list, 5);
        insertAtTail(&list, 6);
        printf("After inserting at tail:\n");
        printList(&list);

        // 获取链表长度和元素值
        printf("Length of list: %d\n", getLength(&list));
        printf("Value at index 2: %d\n", getValue(&list, 2));

        // 删除链表中元素
        deleteNode(&list, 3);
        printf("After deleting node at index 3:\n");
        printList(&list);

        // 清空链表
        clearList(&list);
        printf("After clearing the list:\n");
        printList(&list);

        return 0;
    }
