/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** rpg
*/

#ifndef rpg
#define rpg

#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>

typedef struct loading {
    int total_load;
    int total_to_load;
    sfRectangleShape *yellow;
    sfRectangleShape *back;
    sfRectangleShape *top;
    sfText *load;
} loading_t;

typedef struct game_object {
    sfVector2f p;
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

typedef struct items {
    game_object *obj;
    int *effect;
    float bonus[10];
    int id[2];
    float disp_effect;
    char *path;
    struct items *next;
} items_s;

typedef struct text {
    sfFont *font;
    sfText *text;
} text_t;

typedef struct player {
    float life;
    float physical_armor;
    float magical_armor;
    float physical_attack;
    float magical_attack;
    float magic;
    float crit_rate;
    float crit_dmg;
    float miss_chance;
    float stamina;
    float exp;
    float lvl;
} player_t;

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

typedef struct map_s {
    game_object *tile;
    struct map_s *next;
} map_s;

typedef struct moving_kit_s {
    int has_reach;
    sfVector2f target;
    float speedx;
    float speedy;
    float memx;
    float memy;
    float a;
    float b;
    float v;
    float d;
} move_s;

typedef struct stats_s {
    float stamina;
    float life;
    float magic;
    sfRectangleShape *green;
    sfRectangleShape *red;
    sfRectangleShape *blue;
    sfRectangleShape *exp;
    sfRectangleShape *bg1;
    sfRectangleShape *bg2;
    sfRectangleShape *bg3;
    sfRectangleShape *bg4;
} stats_s;

typedef struct ennemies {
    game_object *obj;
    sfTexture *move;
    sfTexture *atk;
    sfTexture *death;
    sfTexture *idle;
    sfVector2f trigger;
    sfClock *atk_rate;
    int max;
    int anim_death;
    int type;
    int tuto;
    float health;
    float life;
    float damage;
    int type_dmg;
    float p_armor;
    float m_armor;
    float exp;
    int drop_chance;
    int spawn_number;
    int offset;
    int focus;
    int has_reach;
    int disp_speed;
    move_s *mv_kit;
    struct ennemies *next;
} enn_s;

typedef struct bat {
    sfTexture *bat_t;
    sfSprite *bat_s;
    struct bat *next;
} bat_t;

typedef struct pnj {
    text_t *name;
    sfTexture *pnj_t;
    sfSprite *pnj_s;
    sfClock *clock;
    sfIntRect rect;
    sfVector2f scale;
    int nb;
    struct pnj *next;
} pnj_t;

typedef struct pnj_quest {
    pnj_t *pnj;
    sfText **quest;
    int quest_nb;
    int in_speak;
} pnj_quest_t;

typedef struct spawn_point {
    sfVector2f pos;
    sfVector2f size;
    int nb_enn;
    int type;
    struct spawn_point *next;
} spawn_s;

typedef struct gutlet {
    int *gutlets;
    sfText **text;
    game_object *red;
    game_object *green;
    game_object *blue;
} gutlet_s;

typedef struct button {
    sfSprite *sprite;
    sfTexture *texture;
} button_t;

typedef struct button_s {
    sfRectangleShape *rect;
    struct button_s *next;
    game_object *plus;
    int (*callback)(skill_s *);
} button_s;

typedef struct pause {
    button_t **button;
    text_t **text;
    int in_pause;
    int htop;
    sfTexture *back_t;
    sfTexture *htop_t;
    sfSprite *htop_s;
    sfSprite *back_s;
} pause_t;

typedef struct sound {
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

typedef struct music {
    sfMusic *music;
} music_t;

typedef struct sound_music {
    game_object *icon;
    sound_t **sound;
    music_t **music;
    int play;
} sound_music_t;

typedef struct magic_kit {
    int cast;
    int anim;
    game_object *spell_area;
    game_object *spell;
} spell_s;

typedef struct scene_s {
    spell_s *spell;
    sound_music_t *sound_music;
    pause_t *pause;
    bat_t *bat;
    button_s *buttons;
    sfEvent event;
    sfRenderWindow *window;
    player_t *stats;
    stats_s *disp;
    skill_s *skills;
    game_object *bg;
    game_object *head;
    game_object *player;
    game_object *interface;
    game_object *banner;
    sfText* *tuto;
    sfText* *skills_text;
    map_s *map;
    sfRectangleShape* cam;
    sfText* *texts;
    sfView* view;
    move_s *mv_kit;
    sfClock* clock2;
    sfClock* regen;
    sfClock* atk_rate;
    sfClock* spawn_rate;
    spawn_s *spawner;
    enn_s *enn;
    items_s *items;
    items_s *player_items;
    sfRectangleShape* disp_v[3];
    float volume;
    int switch_volume;
    float error_disp;
    int leave;
    int run;
    int nb_char;
    int atk;
    char *name;
    int focus;
    char **save;
    int get_item;
    int totem;
    int death;
    gutlet_s *gutlet;
} scene_s;

typedef struct return_values {
    char *name;
    sfEvent *event;
    sfRenderWindow *window;
    skill_s *skillpoint;
} ret_s;

#define size_map_x 60
#define size_map_y 140

void start(void);
sfRenderWindow *create_window(void);
ret_s *create_game(char *name);
game_object *create_obj(const char *, sfVector2f, sfIntRect, float);
text_t *create_text(char *, int, sfVector2f, sfColor);
scene_s *init_game_scene(ret_s *);
int anim_offset(game_object *obj, int max, int offset);
void gkey_managing(scene_s *scene, sfEvent, pnj_quest_t *);
void draw_head(scene_s *sc);
map_s *create_map(scene_s *);
void draw_map(map_s **map, scene_s *sc);
int put_gravel(map_s **map);
int add_tile(map_s **map, int idx, int idy, int nb);
int check_for_gravel(sfVector2f p, map_s **map, int x, int y);
void manage_game_click(sfMouseButtonEvent, scene_s *sc);
void move_player(scene_s *sc);
void change_to_idle(scene_s *sc);
void set_coor(float *x, float *y, scene_s *sc, sfMouseButtonEvent m);
void set_interfacex(scene_s *scene, sfVector2f move);
void set_interfacey(scene_s *scene, sfVector2f move);
void target_managing(scene_s *sc, float x, float y);
sfTexture *get_texture(scene_s *sc);
sfTexture *get_idle(scene_s *sc);
char *int_to_str(int score);
void display_loading(loading_t *load, scene_s *scene);
loading_t *create_load(void);
int my_strlen(char *);
int set_stats(scene_s *sc);
int set_disp_stats(scene_s *sc);
float get_coeff(float total_load, float total_to_load);
void draw_stats(scene_s *sc);
void set_stats_posx(scene_s *sc);
void set_stats_posy(scene_s *sc);
int create_an_ennemy(scene_s *sc);
void draw_ennemies(scene_s *sc, enn_s **);
sfTexture *get_slash(scene_s *sc);
void draw_atk(scene_s *sc);
int in_range(enn_s *tmp, game_object *player);
void take_damage(enn_s *tmp, scene_s *sc, int type);
int enn_offset(game_object *obj, int max, int offset);
void anim_atk(scene_s *sc, int t);
void regen(scene_s *sc);
void draw_text(scene_s *sc);
sfText **load_tuto(void);
sfText **get_texts(void);
sfText *get_text(char *buffer);
void set_texts(scene_s *sc, sfVector2f);
char **my_realloc_array(char **map, char *buffer);
bat_t *init_bat(scene_s *);
char *get_next_line(int fd);
void display_bat(scene_s *sc, bat_t *bat);
int click_is_in_house(bat_t *bat, sfMouseButtonEvent m, sfVector2f p);
int click_on_ennemy(scene_s *sc, float x, float y);
void set_path(scene_s *sc);
void change_to_attack(scene_s *sc);
void draw_attack(scene_s *sc, int t);
void deal_damage(scene_s *sc);
void change_action(scene_s *sc);
sfTexture *get_attack(scene_s *sc);
sfTexture *get_death_mob(void);
void draw_items(scene_s *sc, items_s **);
void drop_items(enn_s *tmp, scene_s *sc);
pnj_t *init_pnj(char **map);
void display_pnj(scene_s *sc, pnj_t *pnj);
pnj_quest_t *init_pnj_quest(scene_s *stats, ret_s *value);
void save_player_stats(scene_s *value, pnj_quest_t *pq, ret_s *save);
int init_spawner(scene_s *sc);
void spawning(scene_s *sc);
int set_stat_enn(enn_s *enn, int type, spawn_s *tmp);
int init_exp_bar(scene_s *sc);
void scenario(scene_s *sc, pnj_quest_t *pq);
int my_atoi(char *str);
int keep_on_init(scene_s *sc);
void draw_gutlets(scene_s *sc);
void set_pos_gutlety(scene_s *sc);
void set_pos_gutletx(scene_s *sc);
void trigger_enn(scene_s *sc, enn_s **);
int move_enn(enn_s *tmp, int has_reach);
sfTexture *get_atk_enn(void);
sfTexture *get_move_enn(void);
void take_damage_enn(scene_s *sc, enn_s *tmp);
char *my_strcat(char *s1, char *s2);
sfTexture *get_idle_enn(void);
void parsed_stats(char *name, skill_s *skill);
int parsed_quest(char *name);
void collision_enn(enn_s **ref, enn_s *enn, scene_s *sc, int);
int in_cam_enn(enn_s *tmp, scene_s *sc);
sfTexture *get_idle_boss(void);
sfTexture *get_move_boss(void);
sfTexture *get_atk_boss(void);
sfTexture *get_death_boss(enn_s *);
void set_anim_stat(enn_s *tmp, int max, int type);
int create_boss(scene_s *sc);
int set_graphics_totem(items_s *dag, enn_s *tmp, char *path);
int set_graphics_item(items_s *dag, enn_s *tmp, char *path);
void drop_random(scene_s *sc, enn_s *tmp);
void add_item(items_s *item, items_s **sc);
pause_t *init_pause(void);
void reaching_action(scene_s *sc, int has_reach);
void move_item(scene_s *sc, items_s **items, items_s **player);
void set_path_to_item(scene_s *sc);
int clic_item(scene_s *sc, sfMouseButtonEvent m, items_s **ref);
void event_pause_menu(scene_s *sc, sfEvent event, int *);
void game_loop(scene_s *scene, pnj_quest_t *pq, int *);
void display_pause(scene_s *sc);
void draw_player_items(scene_s *sc, items_s **items);
char *get_file_id(items_s *item);
int set_stats_item(items_s *item, char *path);
float atoi_for_items(char *str);
void print_stat(scene_s *sc);
void regen_stats(scene_s *sc);
int death_player(scene_s *sc);
sound_music_t *init_sound_music(void);
int add_strength(skill_s *skillpt);
int add_intelligence(skill_s *skillpt);
int add_stamina(skill_s *skillpt);
int add_accuracy(skill_s *skillpt);
int add_chance(skill_s *skillpt);
int add_vitality(skill_s *skillpt);
int reset(skill_s *skillpt);
button_s *get_buttons_skill(void);
void add_button(button_s **, sfRectangleShape *, int , game_object *);
void set_callback(int (**callback)(skill_s *skillpt), int c);
void draw_skill_tree(scene_s *sc, button_s **refb);
int check_place(int x, int y, button_s *temp);
int check_skill_tree(sfMouseButtonEvent m, scene_s *scene, skill_s *skillpt);
sfText* *get_skills_text(void);
void set_skill_text(sfText* *texts, skill_s *skillpoint);
sfVector2f get_pos_button(char *buffer);
sfVector2f get_size_button(char *buffer);
int get_callback(char *buffer);
char *my_nbr(int nb);
int start_launcher(void);
void destroy_all(ret_s *values, pnj_quest_t *pq, scene_s *sc);
void backrith_fst_part(scene_s *sc, pnj_quest_t *pq, int *ret);
void backrith_scd_part(scene_s *sc, pnj_quest_t *pq, int *ret);
void backrith_trd_part(scene_s *sc, pnj_quest_t *pq, int *ret);
void backrith_four_part(scene_s *sc, pnj_quest_t *pq);
void backrith_five_part(pnj_quest_t *pq, int *ret);
void deckard_fst_part(scene_s *sc, pnj_quest_t *pq);
void deckard_scd_part(scene_s *sc, pnj_quest_t *pq);
void destroy_pnj(pnj_t *all);
void destroy_texts(sfText **text);
void destroy_game_obj(game_object *all);
void destroy_music_sound(sound_music_t *sm);
void destroy_pause(pause_t *pause);
void destroy_enemy(enn_s *all);
void destroy_map(map_s *all);
void destroy_stat(stats_s *stat);
void destroy_bat(bat_t *all);
void destroy_spawn(spawn_s *spawn);
void reinit_pause_text(scene_s *sc, pause_t *pause);
void reinit_pause_button(scene_s *sc, pause_t *pause);
void check_drop_item(scene_s *sc, sfMouseButtonEvent m);
void put_on_map(items_s *item, items_s **ref, scene_s *sc);
int error_drop(int idx, items_s **ref);
void cast_spell(scene_s *sc, sfMouseButtonEvent m);
void draw_spell(scene_s *sc);
void draw_spell_anim(scene_s *sc);
int init_game_volume_display(scene_s *sc);
void draw_volume_pause(scene_s *sc);
void check_volume_click(scene_s *sc, float, float);
void set_volume_game(scene_s *sc);
int create_map_loop(int *idx, int *idy);
button_t *create_button(char *path, sfVector2f pos);
text_t *create_texts(char *texts, int size_text,
            sfVector2f pos, sfColor color);

#endif /* !rpg */