#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct TemperatureStack {
    int arr[MAX];
    int top;
};

void initStack(struct TemperatureStack *s) {
    s->top = -1;
}

int isFull(struct TemperatureStack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct TemperatureStack *s) {
    return s->top == -1;
}

void push(struct TemperatureStack *s, int temp) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->top++;
    s->arr[s->top] = temp;
}

int pop(struct TemperatureStack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    int poppedValue = s->arr[s->top];
    s->top--;
    return poppedValue;
}

void processTemperature(struct TemperatureStack *s, int temp) {
    if (temp >= 45) {
        push(s, temp);
        printf("Red Alert\n");
    } 
    else if (temp >= 43) {
        push(s, temp);
        printf("Orange Alert\n");
    } 
    else if (temp >= 40) {
        push(s, temp);
        printf("Yellow Alert\n");
    } 
    else {
        while (!isEmpty(s)) {
            pop(s);
        }
        printf("Pop.\n");
    }
}

int main() {
    struct TemperatureStack alertStack;
    initStack(&alertStack);
    
    int choice, temp;
    
    while(1) {
        printf("\n1. Enter Temperature\n2. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }
        
        if (choice == 1) {
            printf("Enter temperature: ");
            scanf("%d", &temp);
            processTemperature(&alertStack, temp);
        } 
        else if (choice == 2) {
            break;
        } 
        else {
            printf("Invalid choice.\n");
        }
    }
    
    return 0;
}