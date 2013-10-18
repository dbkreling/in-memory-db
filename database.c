# include <stdio.h>
# include <stdlib.h>

typedef struct member{
    char name[32];
    int value;
    struct member * next;
} t_member;


int main(int argc, char *argv[]){
	t_member *var = NULL;
	var = (t_member *) malloc(sizeof(t_member));
	var->value = 10;
	printf ("%d\n", var->value);
	return 0;
} 


