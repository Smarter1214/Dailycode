#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// ����˫������
struct DLinkList {
    struct Node* head;
    struct Node* tail;
};

// ��ʼ��˫������
void initList(struct DLinkList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// ������ͷ������Ԫ��
void insertAtHead(struct DLinkList* list, int data) {
    // �����½ڵ�
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;

    // ���½ڵ���뵽����ͷ��
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

// ������β������Ԫ��
void insertAtTail(struct DLinkList* list, int data) {
    // �����½ڵ�
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // ���½ڵ���뵽����β��
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

// ��ȡ������
int getLength(struct DLinkList* list) {
    int length = 0;
    struct Node* currentNode = list->head;

    while (currentNode != NULL) {
        length++;
        currentNode = currentNode->next;
    }

    return length;
}

// ��ȡ�����е�index���ڵ��ֵ
int getValue(struct DLinkList* list, int index) {
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
void deleteNode(struct DLinkList* list, int index) {
    // �ж�index�Ƿ񳬳�������
    if (index < 0 || index >= getLength(list)) {
        printf("Invalid index!\n");
        return;
    }

    // ɾ����index���ڵ�
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

// ��ӡ����������Ԫ��
void printList(struct DLinkList* list) {
    struct Node* currentNode = list->head;
    printf("DLinkList: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}
    // �������
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
        // ��ʼ��˫������
        struct DLinkList list;
        initList(&list);
        // ������ͷ������Ԫ��
        insertAtHead(&list, 1);
        insertAtHead(&list, 2);
        insertAtHead(&list, 3);
        printf("After inserting at head:\n");
        printList(&list);

        // ������β������Ԫ��
        insertAtTail(&list, 4);
        insertAtTail(&list, 5);
        insertAtTail(&list, 6);
        printf("After inserting at tail:\n");
        printList(&list);

        // ��ȡ�����Ⱥ�Ԫ��ֵ
        printf("Length of list: %d\n", getLength(&list));
        printf("Value at index 2: %d\n", getValue(&list, 2));

        // ɾ��������Ԫ��
        deleteNode(&list, 3);
        printf("After deleting node at index 3:\n");
        printList(&list);

        // �������
        clearList(&list);
        printf("After clearing the list:\n");
        printList(&list);

        return 0;
    }
