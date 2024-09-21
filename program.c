#include <stdio.h>
#include "initializations.h"
#include "00-LIB/LSTD_types.h"
#include "admin.c"

void start(void){
	u8 mode, res;
	printf("\n****************************\n\nWelcome back !\nPlease enter:\n1. for admin mode\nor\n2. for user mode\n");
	do{
		scanf("%d", &mode);
		if(mode != 1 && mode != 2){
			printf("icorrect mode number !\n\nPlease enter:\n1. for admin mode\nor\n2. for user mode\n");
		}
		else{
			break;
		}
	}while(1);
	
	if(mode == 1){
		res = enter_admin_pass();
		if(res == 1){
			show_admin_options();
		}
	}else{
		show_user_options();
	}
}

u8 enter_admin_pass(){
	u8 i = 0;
	u32 password;
	printf("Please enter the password: ");
	do{
		scanf("%d", &password);
		if(password == 1234){
			printf("\nLogin Successfuly!\n");
			return 1;
		}
		else if(i != 2){
			printf("Incorrect password! Try again.\n");
		}
		i++;
		if(i == 3){
			printf("Sorry, You entered an incorrect password for 3 consecutive times. Try again later.\n");
			return 0;
		}
	}while(i < 3); 
}

void show_admin_options(void){
	u8 option;
	printf("\n----------------------\nPlease choose option:\n\n");
	printf("1. Add new patient record\n");
	printf("2. Edit patient record\n");
	printf("3. Reserve a slot\n");
	printf("4. Cancel reservation\n");
	printf("5. Exit\n");
	
	do{
		scanf("%d", &option);
		if((option < 1 || option > 5) && option != '\0'){
			printf("Incorect option! please choose from 1 to 4.\n");
		}else{
			switch(option){
				case 1:
					add_new_patient();
					break;
				case 2:
					edit_record();
					break;
				case 3:
					reserve();
					break;
				case 4:
					cancel_reservation();
					break;		
				case 5:
					start();
					break;					
			}
		}
	}while(1);
}

void show_user_options(void){
	u8 option;
	printf("\n----------------------\nPlease choose option:\n\n");
	printf("1. View patient record\n");
	printf("2. View today\'s reservations\n");
	printf("3. Exit\n");
	do{
		scanf("%d", &option);
		if(option != 1 && option != 2 && option != 3){
			printf("Incorect option! please choose 1 or 2.\n");
		}else{
			switch(option){
				case 1:
					view_patient_record();
					break;
				case 2:
					view_reservations();
					break;
				case 3:
					start();
					break;					
			}
		}
	}while(1);
}