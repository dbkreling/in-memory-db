# include "./database.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int main(int argc, char *argv[]){
	t_member * list = NULL;
	char name[32];
	int value;
	while(1){
		printf("Enter a name to start the list: \n");
		scanf("%s",name);
		if(!strcmp(name,"exit"))
			break;
//		strcpy(list->name,name);
		printf("Enter a value for this entry: \n");
		scanf("%i",&value);
//		list->value = value;
		add_member(name,value, list);
		//list = t_member_alloc("ana", 1);
		//get_member_value("ana",list);
		//add_member("bruna", 6, list);
		//remove_member("mauro",list);
		//get_member_value("bruna", list);
		//add_member("carla", 3, list);
		//get_member_value("carla", list);
		//update_member("aline",list,9);
		print_list(list);
	}
	return 0; 
}

