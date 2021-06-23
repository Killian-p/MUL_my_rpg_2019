/*
** EPITECH PROJECT, 2020
** launcher
** File description:
** my
*/

#include "struct.h"
#include <stdio.h>
#define TRUE (1)
#define FALSE (-1)

typedef struct skillpoints {
    int skillpoints;
    int strength;
    int vitality;
    int stamina;
    int chance;
    int accuracy;
    int intelligence;
    int type_char;
} skill_s;

typedef struct return_values {
    char *name;
    sfEvent *event;
    sfRenderWindow *window;
    skill_s *skillpoint;
} ret_s;

#ifndef MY_H_
#define MY_H_
void check_register_position(control_t *ctl, sfVector2i mouse);
void register_set_and_disp(control_t *ctl, sfEvent event);
void keyboard_manage(control_t *ctl, sfEvent event);
void password_set(control_t *ctl, sfEvent event);
void username_set(control_t *ctl, sfEvent event);
void login_set(control_t *ctl, sfEvent event);
void delete(control_t *ctl, sfEvent event);
int check_equals(char *str, char *compare);
ret_s *create_game(char *name, int bool);
sfRenderWindow *window_create(void);
void draw_launcher(control_t *ctl);
char *str_cat(char *buff, char c);
void check_field(control_t *ctl);
char *remove_char(char *buffer);
char *remove_char(char *buffer);
int start_launcher(void);
char *create_path(char *buffer);
int start_game(ret_s *values);
void parsed_stats(char *name);

/*-------------------LIBBBB---------*/
int *my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *s1, char *s2);
int my_strlen(char const *str);
int my_putstr(char *str);

#endif /* !MY_H_ */
