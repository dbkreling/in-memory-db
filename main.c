# include "./database.h"
# include <stdlib.h>

int main(int argc, char *argv[]){
	t_member * list = NULL;
	list = t_member_alloc("ana", 1);
	get_member_value("ana",list);
	add_member("bruna", 2, list);
	//remove_member("mauro",list);
	get_member_value("bruna", list);
	add_member("carla", 3, list);
	get_member_value("carla", list);
	return 0;
} 


