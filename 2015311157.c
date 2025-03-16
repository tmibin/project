#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:4996)

// 연결 리스트 노드 구조체
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 연결 리스트 삽입 정렬 함수
Node* insertionSort(Node* head) {
    printf("삽입정렬함수시작\n"); //함수 시작 확인
    if (head == NULL || head->next == NULL) {
        printf("not node or 1\n");//예외 확인
        return head;
    }
        

    Node* sortedList = NULL;
    Node* current = head;

    while (current != NULL) {
        printf("current node: %d\n", current->data);//현재 노드 확인
        Node* next = current->next;
        Node* temp = sortedList;
        Node* prev = NULL;

        // 삽입 위치 찾기
        while (temp != NULL && temp->data < current->data) {
            prev = temp;
            temp = temp->next;
        }

        // 노드 삽입
        if (prev == NULL) {
            current->next = sortedList;
            sortedList = current;
            printf("맨 앞 삽입: %d\n", current->data);//삽입 위치 확인
        }
        else {
            current->next = temp;
            prev->next = current;
            printf("중간 또는 끝 삽입: %d\n", current->data);//삽입 위치 확인
        }

        printf("정렬된 리스트 상태:");//중간상태 확인
        current = next;
    }
    printf("삽입정렬함수종료\n");//함수 종료 확인
    return sortedList;
}

// 연결 리스트 출력 함수
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 메모리 해제 함수
void freeLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    printf("프로그램 시작\n");//시작확인
    Node* head = NULL;
    Node* tail = NULL;
    int num;

    // 입력 처리
    printf("정수를 입력하세요 (종료하려면 Ctrl + Z 또는 Ctrl + D):\n");
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
        printf("노드 추가됨: %d\n", num);
    }

    // 삽입 정렬 수행
    printf("정렬 함수 호출 전\n");//함수 호출 전
    Node* sortedList = insertionSort(head);
    printf("정렬 함수 호출 후\n");//함수 호출 후

    // 정렬된 연결 리스트 출력
    printLinkedList(sortedList);

    // 메모리 해제
    freeLinkedList(sortedList);

    return 0;
}