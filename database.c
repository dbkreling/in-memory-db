# include <stdio.h>
# include <stdlib.h>
# include <string.h>

t_member * t_member_alloc(char * name, int value){
	t_member * new_member = (t_member *)malloc (sizeof(t_member));
	if(new_member != NULL){
		strcpy(new_member->name,name);
		new_member->value = value;
		new_member->next = NULL;
	}
	return new_member;
}

// declare function get that returns the member value

int * get_member_value(char * name, t_member * list){
	t_member * current;
	int * ret = (int *) malloc (sizeof(int));
	current = list;
	while (current != NULL){
		if (!strcmp(name,current->name)){
			printf ("==Found Member==\nName: %s\nValue: %d\n", current->name, current->value);
			* ret = current->value; //copies the value of current->value
			return ret;
		}
		current = current->next;
	}
	printf("There is no %s in the list.Try another name.\n", name);
	return NULL;
}

int remove_member(char * name, t_member * list){
	t_member * current = list; // this is the first member of the list
	t_member * previous = NULL;
	while (current != NULL){
		if(!strcmp(current->name, name)){
			if(previous == NULL)
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
	while(current->next != NULL){
		current = current->next;
	}
	new_member->value = current->value + 1;
	current->next = new_member;
	new_member->next = NULL;
	printf ("++Added++\nName: %s\nValue: %d\n", new_member->name, new_member->value);
	return 0;
}
