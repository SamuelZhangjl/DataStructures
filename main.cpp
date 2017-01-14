/*
 * main.cpp
 *
 *  Created on: 14 Jan 2017
 *      Author: Samuel
 */
#include<iostream>
using namespace std;

struct Link{
	struct Link *next;
	struct Link *prev;
	char* data;
};

struct List{
	struct Link *head;
};

typedef struct Link LinkT;
typedef struct List StrLLT;

List Cons(void){
	struct List list;
	list.head = NULL;
	return list;
}

void Add(StrLLT& list, char* d){
	LinkT *newlink = new LinkT;
	newlink -> next = NULL;
	newlink -> prev = NULL;
	newlink -> data = d;

	if(list.head == NULL){
		list.head = newlink;

	}
	else
	{
		newlink->next = list.head;
		list.head->prev = newlink;
		list.head = newlink;
	}
}

void PrintList(StrLLT list){
	Link* temp;
	temp = list.head;

	while(temp != NULL){
		cout << temp->data<<endl;
		temp = temp->next;
	}
}
void Dest(StrLLT& list)
{
	Link* temp;
	if(list.head == NULL)
		return;
	else
	{
		temp = list.head;
		while(temp->next != NULL){
			temp = temp->next;
			delete temp->prev;
		}
		delete temp;
	}
}

int main(){
	StrLLT list;
	list = Cons();
	Add(list,"Fluff");
	Add(list,"Badger");
	Add(list,"Raspeberry Pi");
	PrintList(list);
	Dest(list);
}
