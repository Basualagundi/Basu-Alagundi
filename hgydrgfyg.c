#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int moisture;
    struct Node* next;
} Node;

// Function to create a new node with the given moisture level
Node* createNode(int moisture) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->moisture = moisture;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
Node* insertNode(Node* head, int moisture) {
    Node* newNode = createNode(moisture);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to increase the moisture level of trees from index 'start' to 'end'
void increaseMoisture(Node* head, int start, int end) {
    Node* temp = head;
    int i = 1;
    while (temp != NULL) {
        if (i >= start && i <= end) {
            temp->moisture++;
        }
        temp = temp->next;
        i++;
    }
}

// Function to decrease the moisture level of trees from index 'start' to 'end'
void decreaseMoisture(Node* head, int start, int end) {
    Node* temp = head;
    int i = 1;
    while (temp != NULL) {
        if (i >= start && i <= end) {
            temp->moisture--;
        }
        temp = temp->next;
        i++;
    }
}

// Function to print the moisture levels of all trees
void printMoistureLevels(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->moisture);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeLinkedList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int N, K;
    printf("Enter the number of trees: ");
    scanf("%d", &N);
    printf("Enter the number of days to hydrate: ");
    scanf("%d", &K);

    // Create the linked list representing the moisture levels of trees
    Node* head = NULL;
    for (int i = 1; i <= N; i++) {
        head = insertNode(head, 1);  // Initialize all trees with moisture level 1
    }

    // Perform hydration for K days
    for (int day = 1; day <= K; day++) {
        int position;
        printf("Enter the position to increase moisture: ");
        scanf("%d", &position);

        // Increase moisture for trees before position and decrease moisture for trees after position
        increaseMoisture(head, 1, position - 1);
        decreaseMoisture(head, position, N);

        printf("Moisture levels after day %d: ", day);
        printMoistureLevels(head);
    }

    // Free the memory allocated for the linked list
    freeLinkedList(head);

    return 0;
}
