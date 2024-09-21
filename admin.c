#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "initializations.h"
#include "00-LIB/LSTD_types.h"
#include "linked_list.c"
#include "linked_list.h"

extern void show_admin_options();
extern void show_user_options();

u8 *slots[] = {"2pm", "2:30pm", "3pm", "3:30pm", "4pm", "4:30pm", "5pm"};
u8 *reserved_slots[7];
u8 ids_slots[7] = {0};

void add_new_patient(void){
	u8 check_int;
	patient newPatient;
	printf("Enter Patient ID: ");
	check_int = scanf("%d", &(newPatient.id));
	node* exist_node = search_by_id(newPatient.id);
	if(exist_node != NULL){
		printf("ID already exists ! \n");
	}else{
	printf("Enter Patient name: ");
	scanf("%s", newPatient.name);
	printf("Enter Patient age: ");
	scanf("%d", &(newPatient.age));
	printf("Enter Patient gender: ");
	scanf("%s", newPatient.gender);
	inserAtFirst(newPatient);
	printf("Patient added successfully !\n");
	}
	show_admin_options();
}

void edit_record(void){
	u32 id;
	printf("Enter Patient ID: ");
	scanf("%d", &id);
	
	node* exist_node = search_by_id(id);
	if(exist_node == NULL){
		printf("ID doesn\'t exist ! \n\n");
	}else{
		printf("Enter new patient name: ");
		scanf("%s", exist_node->info.name);
		printf("Enter new Patient age: ");
		scanf("%d", &(exist_node->info.age));
		printf("Enter new Patient gender: ");
		scanf("%s", exist_node->info.gender);
		printf("Record information edited successfully !\n");
	}
	show_admin_options();
}

void reserve(void){
	u32 id;
	u8 desired_slot[20];
	u32 length =(sizeof(slots) / sizeof(slots[0]));
	for(u8 i = 0; i < length; i++){
		if(slots[i] == NULL){
			continue;
		}
		printf("%d. %s\n", i+1, slots[i]);
	}
	
	printf("Enter Patient ID: ");
	scanf("%d", &id);
	node* exist_node = search_by_id(id);
	if(exist_node == NULL){
		printf("ID doesn\'t exist ! \n\n");
	}else{
		printf("Enter the desired slot: ");
		scanf("%s", desired_slot);
		for(u8 i = 0; i < length; i++){
			if(slots[i] != NULL && strcmp(desired_slot, slots[i]) == 0){
				reserved_slots[i] = slots[i];
				slots[i] = NULL;
				ids_slots[i] = id;
				printf("Slot reserved successfully.\n");
				break;
			}
			if(i == (length - 1)){
				printf("Not an available slot !\n");
				break;
			}
		}	
	}
	show_admin_options();	
}

void cancel_reservation(void){
	u32 id;
	u8 canceled_slot[40];
	u32 length =(sizeof(slots) / sizeof(slots[0]));
	printf("Enter Patient ID: ");
	scanf("%d", &id);
	node* exist_node = search_by_id(id);
	if(exist_node == NULL){
		printf("ID doesn\'t exist ! \n\n");
	}else{
		printf("Enter the desired slot: ");
		scanf("%s", canceled_slot);
		for(u8 i = 0; i < length; i++){
			if((slots[i] == NULL) && (strcmp((char*)canceled_slot, (char*)(reserved_slots[i])) == 0)){
				if(ids_slots[i] == id){
					switch(i){
						case 0:
							slots[0] = "2pm";
							break;
						case 1:
							slots[1] = "2:30pm";
							break;
						case 2:
							slots[2] = "3pm";
							break;
						case 3:
							slots[3] = "3:30pm";
							break;
						case 4:
							slots[4] = "4pm";
							break;
						case 5:
							slots[5] = "4:30pm";
							break;
						case 6:
							slots[6] = "5pm";
							break;						
					}
					ids_slots[i] = 0;
					printf("Reservation canceled successfully.\n");
					break;
				}
			}
			if(i == (length - 1)){
				printf("Not a reserved slot !\n");
				break;
			}
		}	
	}
	show_admin_options();
}


void view_patient_record(void){
	u32 id;
	printf("Enter Patient ID: ");
	scanf("%d", &id);
	
	node* exist_node = search_by_id(id);
	if(exist_node != NULL){
        printf("ID: %d, Name: %s, Age: %d, Gender: %s\n", exist_node->info.id, exist_node->info.name, exist_node->info.age, exist_node->info.gender);
	}else{
		printf("ID doesn\'t exist ! \n\n");
	}
	show_user_options();
}

void view_reservations(void){
	u8 *reserved_slots[7], flag = 0; 
	u32 length =(sizeof(slots) / sizeof(slots[0]));
	for(u8 i = 0; i < length; i++){
		if(slots[i] == NULL && ids_slots[i] != 0){
			flag = 1;
			switch(i){
					case 0:
						reserved_slots[0] = "2pm";
						break;
					case 1:
						reserved_slots[1] = "2:30pm";
						break;
					case 2:
						reserved_slots[2] = "3pm";
						break;
					case 3:
						reserved_slots[3] = "3:30pm";
						break;
					case 4:
						reserved_slots[4] = "4pm";
						break;
					case 5:
						reserved_slots[5] = "4:30pm";
						break;
					case 6:
						reserved_slots[6] = "5pm";
						break;						
				}
			printf("slot time: %s & patient id: %d\n", reserved_slots[i], ids_slots[i]);
		}
	}
	if(flag == 0){
		printf("There\'s no reservations yet.\n");
	}
	show_user_options();
}