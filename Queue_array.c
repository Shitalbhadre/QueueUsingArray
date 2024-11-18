#include <stdio.h>
#define MAX 5

int queue[MAX];
int F = -1;
int R = -1;

void enqueue() {
    int item;
    char ch;

    do {
        printf("Enter the data: ");
        scanf("%d", &item);
        
        if (R == MAX - 1) {
            printf("Queue overflow\n");
        }
        else if (F == -1 && R == -1) {
                F = R = 0;
            } else {
                R++;
            }
            queue[R] = item;
           
        printf("Press y to continue: ");
        getchar(); 
        scanf("%c", &ch);
    } while (ch == 'y');
}

void dequeue() {
    if (F == -1) {
        printf("Queue underflow\n");
    } else {
        printf("Removed %d from the queue\n", queue[F]);
        if (F == R) {
            F = R = -1;
        } else {
            F++;
        }
    }
}

void display() {
    if (F == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = F; i <= R; i++) {
            printf("%d", queue[i]);
        }

        
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}





