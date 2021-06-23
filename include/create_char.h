/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** rpg
*/

#ifndef cre
#define cre

#include <SFML/System.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

typedef struct game_object {
    sfVector2f position;
    sfVector2f scale;
    sfSprite* sprite;
    sfTexture* texture;
    sfIntRect rect;
    sfClock* clock;
    float speed;
    int disp;
    int drawable;
    sfMusic* sound;
} game_object;

typedef struct skillpoints {
    int skillpoints;
    int strength;
    int vitality;
    int stamina;
    int chance;
    int accuracy;
    int intelligence;
    int type_char;
    int reset;
} skill_s;

typedef struct button_s {
    sfRectangleShape *rect;
    struct button_s *next;
    game_object *plus;
    int (*callback)(skill_s *);
} button_s;

typedef struct scene_s {
    sfEvent *event;
    sfRenderWindow *window;
    game_object **bg;
    game_object *character[3];
    game_object *keys[3];
    button_s *buttons;
    sfClock* textclock;
    sfVector2f textscale;
    sfText* *texts;
    sfMusic* up_sound;
    sfMusic* error_sound;
    game_object *banner;
    game_object *ping;
    float volume;
    int switch_volume;
    sfRectangleShape* disp_v[3];
    int nb;
    float error_disp;
    int leave;
    char *name;
} scene_s;

typedef struct return_values {
    char *name;
    sfEvent *event;
    sfRenderWindow *window;
    skill_s *skillpoint;
} ret_s;

void draw_sprites(scene_s *sc, skill_s *);
int init_character(scene_s *scene);
game_object *create_object(const char *, sfVector2f, sfIntRect, float);
game_object **init_parallax(void);
void move_parallax(scene_s *sc);
int init_texts(scene_s *scene);
void draw_texts(scene_s *sc, skill_s *);
void draw_parallax(scene_s *sc);
char *get_str(char *buffer);
int get_size_str(char *buffer, int nb);
char *get_font(char *buffer);
sfColor get_color(char *buffer);
sfVector2f get_origin(char *buffer);
sfVector2f get_pos(char *buffer);
int get_nb_number(char *buffer, int nb);
sfText* *get_texts(void);
int get_size(char *buffer);
void get_res(char *buffer, int idx, int *res);
void init_skill_point(skill_s *skillpoint, int bool, char *name);
char *my_nbr(int nb);
void set_skill_text(sfText* *texts, skill_s *skillpoint);
char *get_skill(int idx, skill_s *skillpt);
button_s *init_buttons(void);
int add_strength(skill_s *skillpt);
int add_intelligence(skill_s *skillpt);
int add_stamina(skill_s *skillpt);
int add_accuracy(skill_s *skillpt);
int add_chance(skill_s *skillpt);
int add_vitality(skill_s *skillpt);
int reset(skill_s *skillpt);
void key_managing(sfRenderWindow *, sfEvent, scene_s *, skill_s *);
void manage_mouse_click(sfMouseButtonEvent m, scene_s *, skill_s *);
void draw_buttons(scene_s *sc, button_s *button);
sfVector2f get_pos_button(char *buffer);
sfVector2f get_size_button(char *buffer);
int get_callback(char *buffer);
void draw_icons(scene_s *scene, skill_s *);
void draw_ping(scene_s *sc);
void draw_volume(scene_s *sc);
int init_volume_display(scene_s *sc);
void set_volume(sfMusic* music, scene_s *sc);
void switch_volume(scene_s *sc);
int volume_setting(skill_s *skillpt);
void destroy_music(scene_s *scene);
int start_game(ret_s *values);
void parsed_stats(char *name, skill_s *skill);
int init_scene(scene_s *scene, char *name);
int loop_init_parallax(game_object **layer, float speed, int i, char *);
ret_s *return_create_char(scene_s *sc, skill_s *sk);

#endif /* !cre */