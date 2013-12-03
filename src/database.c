# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "database.h"

//receives a new member name and  allocs memory space for it as a t_member struct 
t_member * t_member_alloc(char * name, int value){
	t_member * new_member = (t_member *)malloc (sizeof(t_member));
	if(new_member != NULL){
		strcpy(new_member->name,name);
		new_member->value = value;
		new_member->next = NULL;
	}
	return new_member;
}

void print_list(t_member * list){
	printf("Passei aqui");
	t_member * current = list;
	while (current != NULL){
		get_member_value(current->name, list);
		current = current->next;
	}
}

// declare function get that returns the member value
int * get_member_value(char * name, t_member * list){
	t_member * current;
	int * ret = (int *) malloc (sizeof(int));
	current = list;
	while (current != NULL){
		if (!strcmp(name,current->name)){
			printf ("\nMember Name: %s\nValue: %d\n", current->name, current->value);
			* ret = current->value; //copies the value of current->value
			return ret;
		}
		current = current->next;
	}
	printf("There is no %s in the list.Try another name.\n", name);
	return NULL;
}

int update_member(char * name, t_member * list, int new_value){
	t_member * current = list;
	while (current != NULL){
		if(!strcmp(name,current->name)){
			printf("Updating member %s...\nOld value: %i\n",current->name,current->value);
			current->value=new_value;
			printf("New value: %i\n",current->value);
			return 0;
		}
		current = current->next;
	}
	printf("%s not found in database...\n",name);
	return 1;
}


int remove_member(char * name, t_member * list){
	t_member * current = list; // this is the first member of the list
	t_member * previous = NULL;
	while (current != NULL){
		if(!strcmp(current->name, name)){
			if(previous == NULL) //in case this is the first member
				list = current->next;
			else 
				previous->next = current->next;
			printf("%s removed successfully!", name);
			free(current);
			return 0;
		}
		previous = current;
		current = current->next;
	}
	return -1;
}

int add_member(char * name, int value, t_member * list){
	t_member * new_member = t_member_alloc(name, value);
	t_member * current = list;
	if(current == NULL){
		strcpy(new_member->name,name);
		new_member->value = value;
		new_member->next = NULL;
		list = new_member;
	} else {
		while(current->next != NULL){
			current = current->next;
		}
		strcpy(new_member->name,name);
		new_member->value = value;
		current->next = new_member;
		new_member->next = NULL;
	}
	print_list(list);
	printf ("\nMember Added >> Name: %s \tValue: %d\n", new_member->name, new_member->value);
	return 0;
}
