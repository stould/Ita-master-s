#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node *next;
};

struct Stack{
    Node *head;
    int size;
    Stack(){
        head = NULL;
        size = 0;
    }

    Node* makeNode(int val){
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->val = val;
        newNode->next = NULL;
        return newNode;
    }

    int getTop(){
        if(head == NULL){
            printf("Erro - stack is NULL\n");
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
            newNode->next = head;
            head = newNode;
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
            size--;
        }
    }

    int getSize(){
        return size;
    }
};

int main(){
    Stack st;
    st.push(1);
    printf("%d\n", st.getTop());
    st.push(2);
    printf("%d\n", st.getTop());
    st.push(3);
    printf("%d\n", st.getTop());
    st.pop();
    printf("%d\n", st.getTop());
    st.push(4);
    printf("%d\n", st.getTop());
    st.push(5);
    printf("%d\n", st.getTop());
    st.pop();
    printf("%d\n", st.getTop());
    st.pop();
    printf("%d\n", st.getTop());
    st.pop();
    printf("%d\n", st.getTop());
    st.pop();
    st.push(7);
    printf("%d\n", st.getTop());
    st.push(4);
    printf("%d\n", st.getTop());
    st.pop();
    printf("%d\n", st.getTop());
    st.pop();
    printf("%d\n", st.getTop());
    return 0;
}
