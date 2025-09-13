
#include <iostream>
#include <iomanip>

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head) {
    //q1 will be p1's next
    //q3 is p3's next->next->next

    Node* p1 = head;
    Node* p2 = head->next;
    Node* p3 = head->next->next;
    Node* p4 = head->next->next->next;


    while(p4->next && p4->next->next && p4->next->next->next && p4->next->next->next->next){
        p1 = p1->next;
        p2 = p2->next->next;
        p3 = p3->next->next->next;
        p4 = p4->next->next->next->next;

    }

    if (p4->next == nullptr){
        //1 2 3 4 5 6 7 8

        long long int q3 = ((long long) p3->next->value + p3->value);
        long long int q1 = ((long long) p1->next->value + p1->value);

        return q3/2.0 - q1/2.0;
    } else if(p4->next && p4->next->next == nullptr){
        //1 2 3 4 5 6 7 8 9

        long long int q3 = ((long long) p3->next->next->value + p3->next->value);
        long long int q1 = ((long long) p1->next->value + p1->value);

        return (q3)/2.0 - (q1)/2.0;
    } else if(p4->next && p4->next->next && p4->next->next->next == nullptr){
        // 1 2 3 4 5 6 7 8 9 10

        long long int q3 = ((long long) p3->next->next->value);
        long long int q1 = ((long long) p1->next->value);

        return q3 - q1;
    }

    long long int q3 = ((long long) p3->next->next->next->value);
    long long int q1 = ((long long) p1->next->value);
    return q3 - q1;
}