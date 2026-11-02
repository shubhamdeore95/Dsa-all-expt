#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WeatherNode {
    char timestamp[10];
    char location[50];
    float temperature;
    struct WeatherNode* next;
};

struct WeatherNode* createNode(char* timestamp, char* location, float temp) {
    struct WeatherNode* newNode = (struct WeatherNode*)malloc(sizeof(struct WeatherNode));
    strcpy(newNode->timestamp, timestamp);
    strcpy(newNode->location, location);
    newNode->temperature = temp;
    newNode->next = NULL;
    return newNode;
}

void insertObservation(struct WeatherNode** head, char* timestamp, char* location, float temp) {
    struct WeatherNode* newNode = createNode(timestamp, location, temp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct WeatherNode* tempNode = *head;
    while (tempNode->next != NULL) {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
}

void deleteObservation(struct WeatherNode** head, char* timestamp) {
    struct WeatherNode* temp = *head;
    struct WeatherNode* prev = NULL;

    if (temp != NULL && strcmp(temp->timestamp, timestamp) == 0) {
        *head = temp->next;
        free(temp);
        printf("Record at %s deleted successfully.\n", timestamp);
        return;
    }

    while (temp != NULL && strcmp(temp->timestamp, timestamp) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Record at timestamp %s not found for deletion.\n", timestamp);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Record at %s deleted successfully.\n", timestamp);
}

void displayObservations(struct WeatherNode* head) {
    struct WeatherNode* temp = head;
    if (temp == NULL) {
        printf("No climate records available.\n");
        return;
    }
    printf("\n--- KJS-CES-01 Climate Intelligence Monitor ---\n");
    while (temp != NULL) {
        printf("[%s | %s | %.1f°C]", temp->timestamp, temp->location, temp->temperature);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n\n");
}

void searchObservation(struct WeatherNode* head, char* timestamp) {
    struct WeatherNode* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->timestamp, timestamp) == 0) {
            printf("Record Found: [%s | %s | %.1f°C]\n", temp->timestamp, temp->location, temp->temperature);
            return;
        }
        temp = temp->next;
    }
    printf("No records found for timestamp: %s\n", timestamp);
}

void updateObservation(struct WeatherNode* head, char* timestamp, float newTemp) {
    struct WeatherNode* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->timestamp, timestamp) == 0) {
            temp->temperature = newTemp;
            printf("Successfully updated %s temperature to %.1f°C\n", timestamp, newTemp);
            return;
        }
        temp = temp->next;
    }
    printf("Timestamp %s not found. Update failed.\n", timestamp);
}

int main() {
    struct WeatherNode* head = NULL;

    insertObservation(&head, "10:00", "Mumbai", 36.0);
    insertObservation(&head, "11:00", "Mumbai", 38.0);
    insertObservation(&head, "12:00", "Mumbai", 40.0);
    insertObservation(&head, "13:00", "Mumbai", 42.0);

    printf("Initial sequential meteorological observations:");
    displayObservations(head);

    printf("Inserting new real-time AWS observation (13:30, Mumbai, 43.0°C):\n");
    insertObservation(&head, "13:30", "Mumbai", 43.0);
    displayObservations(head);

    printf("Searching for 12:00 log:\n");
    searchObservation(head, "12:00");

    printf("\nUpdating corrected sensor data for 11:00 log:\n");
    updateObservation(head, "11:00", 39.5);
    displayObservations(head);

    printf("Deleting obsolete log at 10:00:\n");
    deleteObservation(&head, "10:00");
    displayObservations(head);

    struct WeatherNode* current = head;
    struct WeatherNode* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
