# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct member{
    char name[32];
    int value;
    struct member * next;
} t_member;

// declare function get that returns the member value
int get_member_number(char * name, t_member * list){
	t_member * current;
	current = list;
	while (current != NULL){
		if (!strcmp(name,current->name)){
			printf ("The value is %d\n", current->value);
			return 0;
		}
		current = current->next;
	}
	printf("There is no %s in the list\n", name);
	return 0;
}

int main(int argc, char *argv[]){
	t_member * list = NULL;
	list = (t_member *) malloc(sizeof(t_member));
	list->value = 1;
	strcpy(list->name,"ana");
	get_member_number("ana",list);
	return 0;
} 


