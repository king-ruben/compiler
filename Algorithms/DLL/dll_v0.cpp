/**
 * 
*/
#include <iostream>

struct Node* createNode(int x);
void inserAtTail(int x);
void inserAtHead(int x);

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* head;

int main(int argc, char** argv)
{
 

    return 0;
}

struct Node* createNode(int x)
{
    struct Node* newNode = new struct Node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void inserAtHead(int x)
{
    

}

void inserAtTail(int x)
{

}

