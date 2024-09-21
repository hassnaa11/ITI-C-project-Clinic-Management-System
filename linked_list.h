#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct patient{
	u8 age;
	u32 id;
	u8 gender[10];
	u8 name[50];
}patient;

typedef struct node{
	patient info;
	struct node* next;
}node;

void inserAtFirst(patient);
void free_linked_list(void);
node* search_by_id(u8 id);
void print_linked_list(void);

#endif