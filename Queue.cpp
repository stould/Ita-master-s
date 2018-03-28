#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node *next;
};

struct Queue{
    Node *head;
    int size;
    Queue(){
        head = NULL;
        size = 0;
    }

    Node* makeNode(int val){
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->val = val;
        newNode->next = NULL;
        return newNode;
    }

    int getFront(){
        if(head == NULL){
            printf("Erro - queue is NULL\n");
            return -1;
        }else{
            return head->val;
        }
    }

    void push(int val){
        Node *newNode = makeNode(val);
        if(head == NULL){
            head = newNode;
        }else{
            Node* tmp = head, *last = head;
            while(tmp != NULL){
                last = tmp;
                tmp = tmp->next;
            }
            last->next = newNode;
        }
        size++;
    }

    void pop(){
        if(head == NULL){
            printf("Erro - Pilha vazia\n");
        }else{
            Node *tmp = head;
            head = head->next;
            free(tmp);
        }
    }

    int getSize(){
        return size;
    }
};

int main(){
    Queue st;
    st.push(10);
    printf("%d\n", st.getFront());
    st.push(5);
    printf("%d\n", st.getFront());
    st.pop();
    st.push(15);
    printf("%d\n", st.getFront());
    st.push(7);
    printf("%d\n", st.getFront());
    st.pop();
    printf("%d\n", st.getFront());
    st.pop();
    printf("%d\n", st.getFront());
    st.pop();
    printf("%d\n", st.getFront());
    return 0;
}
