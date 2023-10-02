#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *kReverse(Node *head, int k)
{
    // base call
    if (head == NULL)
    {
        return NULL;
    }

    // step1: reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step2: Recursion dekhlega aage ka
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }

    // step3: return head of reversed list
    return prev;
}

int main(){

Node*node1=new Node(10);

Node*head=node1;

insertAtHead(head,23);
insertAtHead(head, 2);
insertAtHead(head, 5);
insertAtHead(head, 7);
insertAtHead(head, 8);

print(head);


head=kReverse(head,2);
print(head);


return 0;
}