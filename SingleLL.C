#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
}*newnode, *first = NULL, *last = NULL;

int count = 0;

void enter(){
    printf("\n\nPress Enter to continue\n");
    fflush(stdin);
    getchar();
    system("cls");
}

void insStart(){
    newnode = (struct node *)malloc(sizeof(struct node));
    count++;
    printf("\nEnter the Data = ");
    scanf(" %d",&newnode->data);

    if(first == NULL){
        newnode->link = NULL;
        first = newnode;
        last = newnode;
    }else{
        newnode->link = first;
        first = newnode;
    }

    enter();
}

void display(){
    struct node * temp;
    temp = first;
    if(first == NULL){
        printf("\nEmpty Linked List");
    }else{
        printf("\nLinked list =");
        while(temp != NULL){
            printf(" %d",temp->data);
            temp = temp->link;
        }
    }
    enter();
}

void insLast(){
    newnode = (struct node *)malloc(sizeof(struct node));
    count++;
    printf("\nEnter the Data = ");
    scanf(" %d",&newnode->data);

    if(first == NULL){
        newnode->link = NULL;
        first = newnode;
        last = newnode;
    }else{
        newnode->link = NULL;
        last->link = newnode;
        last = newnode;
    }
    enter();
}

void insMid(){
    int pos,i;
    struct node * temp;

    printf("\nEnter position = ");
    scanf("%d",&pos);
    if(pos == 1){
        insStart();
    }else if(pos == count+1){
        insLast();
    }else if((pos > count+1)||(pos < 1)){
        printf("\nEnter a valid position");
        enter();
    }else{
        newnode = (struct node *)malloc(sizeof(struct node));
        count++;
        printf("\nEnter the Data = ");
        scanf(" %d",&newnode->data);

        temp = first;
        i = 1;
        while(i < pos-1){
            temp = temp->link;
            i++;
        }
        newnode->link = temp->link;
        temp->link = newnode;
        enter();
    }

}

void delFirst(){
    struct node * temp = first;

    if(first == NULL){
        printf("\nEmpty Linked List");
    }else{
        printf("\nDeleting node %d",first->data);
        if(first == last){
            first = NULL;
            last = NULL;
        }else{
            first = first->link;
            free(temp);
            count--;
        }
    }
    enter();
}

void delMid(){
    int pos,i;
    struct node *temp, *temp1;

    printf("\nEnter Position = ");
    scanf("%d",&pos);

    if(pos == 1){
        delFirst();
    }else if((pos >= count + 1)||(pos < 1)){
        printf("\nInvalid Position");
        enter();
    }else{
        temp = first;
        i = 1;
        while(i < pos-1){
            temp = temp->link;
            i++;
        }
        temp1 = temp->link;
        temp->link = temp1->link;
        printf("\nDeleted %d data",temp1->data);
        free(temp1);
        count--;

        enter();
    }

}

void search(){
    int sch,i = 1;
    struct node * temp = first;
    bool flag = false;

    printf("\nEnter the value to be searched = ");
    scanf("%d",&sch);

    while(temp != NULL){
        if(temp->data == sch){
            flag = true;
            break;
        }
        temp = temp->link;
        i++;
    }

    if((i > count) && (flag == false)){
        printf("\nNot Found");
    }else{
        printf("\nFound");
    }
    enter();
}

int main(){
    bool exit = false;
    int ch;

    while(exit == false) {
        printf("\nPress 1 to Insert at Start");
        printf("\nPress 2 to Insert in the Middle");
        printf("\nPress 3 to Insert at End");
        printf("\nPress 4 to Delete the First Node");
        printf("\nPress 5 to Delete a Node from the Middle");
        printf("\nPress 6 to Display Linked List");
        printf("\nPress 7 to Search in Linked List");
        printf("\nPress 8 to Exit");
        printf("\nEnter your choice = ");
        scanf("%d",&ch);

        system("cls");

        switch(ch) {
            case 1: {
                //printf("\ninsStart");
                insStart();
                break;
            }
            case 2: {
                //printf("\ninsMid");
                insMid();
                break;
            }
            case 3: {
                //printf("\ninsLast");
                insLast();
                break;
            }
            case 4: {
                //printf("\ndelFirst");
                delFirst();
                break;
            }
            case 5: {
                //printf("\ndelMid");
                delMid();
                break;
            }
            case 6: {
                //printf("\nDisplay");
                display();
                break;
            }
            case 7: {
                //printf("\nSearch");
                search();
                break;
            }
            case 8: {
                exit = true;
                break;
            }
            default: {
                printf("\nEnter a valid input");
            }
        }
    }

    return 0;
}
