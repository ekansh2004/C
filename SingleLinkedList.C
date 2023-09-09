#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
}*newnode,*first = NULL, *last = NULL;

void enter() {
    printf("\n\nPress Enter to continue\n");
    fflush(stdin);
    getchar();
    system("cls");
}

void ins_start() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data = ");
    scanf("%d", &newnode->data);
    //printf("%d",newnode->data);
    newnode->link = NULL;
    if (first == NULL) {
        first = newnode;
        last = newnode;
    } else {
        newnode->link = first;
        first = newnode;
    }
    //printf("first = %d",first->data);
    //printf("last = %d",last->data);
    printf("%d Entered Successfully",newnode->data);

    enter();
}

void display(){
    struct node *temp = first;

    printf("\nLinked List is = ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    enter();
}

int main() {
/*
    printf("Hello");

    ins_start();
    ins_start();
    display();
*/
    bool exit = false;
    int ch;

    while(exit == false) {
        printf("\nPress 1 to Add to beginning of Linked List");
        printf("\nPress 2 to Display Linked List");
        printf("\nPress 3 to exit");
        printf("\nEnter your choice = ");
        scanf("%d",&ch);

        system("cls");

        switch(ch) {
            case 1: {
                ins_start();
                break;
            }
            case 2: {
                display();
                break;
            }
            case 3: {
                exit = true;
                break;
            }
            default: {
                printf("\n Enter a valid input");
            }
        }
    }
    return 0;
}
