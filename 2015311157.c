#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:4996)

// ���� ����Ʈ ��� ����ü
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ���� ����Ʈ ���� ���� �Լ�
Node* insertionSort(Node* head) {
    printf("���������Լ�����\n"); //�Լ� ���� Ȯ��
    if (head == NULL || head->next == NULL) {
        printf("not node or 1\n");//���� Ȯ��
        return head;
    }
        

    Node* sortedList = NULL;
    Node* current = head;

    while (current != NULL) {
        printf("current node: %d\n", current->data);//���� ��� Ȯ��
        Node* next = current->next;
        Node* temp = sortedList;
        Node* prev = NULL;

        // ���� ��ġ ã��
        while (temp != NULL && temp->data < current->data) {
            prev = temp;
            temp = temp->next;
        }

        // ��� ����
        if (prev == NULL) {
            current->next = sortedList;
            sortedList = current;
            printf("�� �� ����: %d\n", current->data);//���� ��ġ Ȯ��
        }
        else {
            current->next = temp;
            prev->next = current;
            printf("�߰� �Ǵ� �� ����: %d\n", current->data);//���� ��ġ Ȯ��
        }

        printf("���ĵ� ����Ʈ ����:");//�߰����� Ȯ��
        current = next;
    }
    printf("���������Լ�����\n");//�Լ� ���� Ȯ��
    return sortedList;
}

// ���� ����Ʈ ��� �Լ�
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// �޸� ���� �Լ�
void freeLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    printf("���α׷� ����\n");//����Ȯ��
    Node* head = NULL;
    Node* tail = NULL;
    int num;

    // �Է� ó��
    printf("������ �Է��ϼ��� (�����Ϸ��� Ctrl + Z �Ǵ� Ctrl + D):\n");
    while (scanf("%d", &num) == 1) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        printf("��� �߰���: %d\n", num);
    }

    // ���� ���� ����
    printf("���� �Լ� ȣ�� ��\n");//�Լ� ȣ�� ��
    Node* sortedList = insertionSort(head);
    printf("���� �Լ� ȣ�� ��\n");//�Լ� ȣ�� ��

    // ���ĵ� ���� ����Ʈ ���
    printLinkedList(sortedList);

    // �޸� ����
    freeLinkedList(sortedList);

    return 0;
}