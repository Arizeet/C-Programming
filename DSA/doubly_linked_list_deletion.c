#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
int count=0;
struct node *head, *tail;
void create(){
    struct node *newnode;
    int choice=1;
    while(choice){
        newnode = (struct node *)malloc(sizeof(struct node));
        count++;
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        if(head==0){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("Continue..? ");
        scanf("%d",&choice);
    }
}
void display(){
    struct node *temp;
    int ch;
    printf("\n1. From Head\t2. From Tail\n");
    scanf("%d",&ch);
    if(ch==1){
        temp=head;
        while(temp!=0){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
    else if(ch==2){
        temp=tail;
        while(temp!=0){
            printf("%d\t",temp->data);
            temp=temp->prev;
        }
    }
    else{
        printf("\nInvalid choice...");
    }
}
void deleteB(){
    struct node *temp;
    temp=head;
    head=head->next;
    head->prev=0;
    free(temp);
    count--;
}
void deleteE(){
    struct node *temp;
    temp=tail;
    tail=tail->prev;
    tail->next=0;
    free(temp);
    count--;
}
void deleteSP(){
    struct node *temp;
    int pos,i=1;
    printf("Enter pos: ");
    scanf("%d",&pos);
    if(pos<1||pos>count){
        printf("Invalid position...");
    }
    else if(pos==1){
        deleteB();
    }
    else if(pos==count){
        deleteE();
    }
    else{
        temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        count--;
    }
}
int main(){
    int ch=1,choice;
    create();
    printf("LL created: %d nodes in the list",count);
    while(ch){
        printf("\n1. DeleteB\t2. DeleteE\t3. DeleteSP\t4. Display\t5. No. of nodes\t6. EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: deleteB();  break;
            case 2: deleteE();  break;
            case 3: deleteSP(); break;
            case 4: display();  break;
            case 5: printf("%d nodes in LL",count); break;
            case 6: exit(1);
            default:    printf("Invalid i/p...\n");
        }
    }
    return 0;
}