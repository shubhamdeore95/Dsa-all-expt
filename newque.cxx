#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int alert_type) {
    if (rear == MAX - 1) {
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = alert_type;
    
    if (alert_type == 1) {
        printf("Yellow Alert Issued!\n");
    } else if (alert_type == 2) {
        printf("Orange Alert Issued!\n");
    } else if (alert_type == 3) {
        printf("Red Alert Issued!\n");
    }
}

void dequeueAll() {
    if (front == -1 || front > rear) {
        printf("No active alerts to remove.\n");
        return;
    }
    while (front <= rear) {
        int removed = queue[front];
        front++;
        if (removed == 1) {
            printf("Removed: Yellow Alert\n");
        } else if (removed == 2) {
            printf("Removed: Orange Alert\n");
        } else if (removed == 3) {
            printf("Removed: Red Alert\n");
        }
    }
    front = -1;
    rear = -1;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. No active alerts.\n");
        return;
    }
    printf("Active alerts in queue (Front to Rear): ");
    for (int i = front; i <= rear; i++) {
        if (queue[i] == 1) printf("[Yellow Alert] ");
        else if (queue[i] == 2) printf("[Orange Alert] ");
        else if (queue[i] == 3) printf("[Red Alert] ");
    }
    printf("\n");
}

int main() {
    int choice;
    float temp;

    while (1) {
        printf("\n--- Heatwave Prediction System ---\n");
        printf("1. Enter Temperature\n");
        printf("2. Display Active Alerts\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter current temperature in Celsius: ");
                scanf("%f", &temp);
                if (temp >= 45.0) {
                    enqueue(3);
                } else if (temp >= 43.0) {
                    enqueue(2);
                } else if (temp >= 40.0) {
                    enqueue(1);
                } else {
                    printf("Temperature < 40 deg. Clearing active alerts...\n");
                    dequeueAll();
                }
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
