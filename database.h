# ifndef DATABASE_H
# define DATABASE_H

typedef struct member{
    char name[32];
    int value;
    struct member * next;
} t_member;

t_member * t_member_alloc(char * name, int value);
int * get_member_value(char * name, t_member * list);
int remove_member(char * name, t_member * list);
int add_member(char * name, int value, t_member * list);

# endif
