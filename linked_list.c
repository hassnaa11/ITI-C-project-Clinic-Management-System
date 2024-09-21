#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "./linked_list.h"
#include "./00-LIB/LSTD_types.h"

static node* head = NULL;

void inserAtFirst(patient newPatient){
	node *newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
	newNode->info.id = newPatient.id; 
	newNode->info.age = newPatient.age; 
	strcpy((char *)newNode->info.gender, (char *)newPatient.gender); 
    strcpy((char *)newNode->info.name, (char *)newPatient.name);
	newNode->next = head;
	head = newNode;
}

void free_linked_list(){
	node* currNode = head;
	node* nextNode;
	while(currNode != NULL){
		nextNode = currNode->next;
		free(currNode);
		currNode = nextNode;
	}
	head = NULL;
}

node* search_by_id(u8 id){
	node *currNode = head;
    if (currNode == NULL) {
        return currNode;
    }

    while (currNode != NULL && currNode->info.id != id) {
        currNode = currNode->next;
    }
	return currNode;
}

void print_linked_list() {
    node *currNode = head;
    if (currNode == NULL) {
        printf("List is empty\n");
        return;
    }

    while (currNode != NULL) {
        printf("ID: %d, Age: %d, Gender: %s, Name: %s\n", currNode->info.id, currNode->info.age, currNode->info.gender, currNode->info.name);
        currNode = currNode->next;
    }
}