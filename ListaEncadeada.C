#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para cada nó da lista encadeada
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Função para criar um novo nó
Node *createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um elemento no início da lista encadeada
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = (*head);
    (*head) = newNode;
}

// Função para inserir um elemento no final da lista encadeada
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    Node *lastNode = (*head);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Função para remover um elemento da lista encadeada
void removeNode(Node **head, int data) {
    Node *temp = *head, *prev;
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Função para exibir os elementos da lista encadeada
void displayList(Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    displayList(head);
    removeNode(&head, 2);
    displayList(head);
    return 0;
}
