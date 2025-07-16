#include<bits/stdc++.h>

using namespace std;
int q;
struct node{
	int data;
	node *next;
};

node *makeNode(int x){
	node *newNode = new node();
	
	newNode->data = x;
	newNode->next = NULL;
	
	return newNode;
}

void pushBack(node **head, int x){
	node *temp = *head;
	node *newNode = makeNode(x);
	
	if(*head == NULL){
		*head = newNode;
		return;
	}
	
	while(temp->next != NULL){
		temp = temp->next;
		
	}
	temp->next = newNode;
}
void duyet(node *head){
	while(head != NULL){
		if(head->data != q){
			cout << head->data << " ";
		}
		head = head->next;
	}
}
int main(){
	int n;
	cin >> n;
	node *head = NULL;
	for(int i = 0;i < n;i++){
		int x;
		cin >> x;
		pushBack(&head, x);
	}
	
	cin >> q;
	
	duyet(head);
	
}