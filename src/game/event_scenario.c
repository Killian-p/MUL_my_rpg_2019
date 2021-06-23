/*
** EPITECH PROJECT, 2020
** display dialogue
** File description:
** rpg
*/

#include "rpg.h"

sfVector2f get_ul_pnj(pnj_t *pnj)
{
    sfVector2f pos = sfSprite_getPosition(pnj->pnj_s);
    sfVector2f ul = {0, 0};

    ul.x = pos.x - 100;
    ul.y = pos.y - 100;
    return (ul);
}

sfVector2f get_br_pnj(pnj_t *pnj)
{
    sfFloatRect lb = sfSprite_getLocalBounds(pnj->pnj_s);
    sfVector2f pos = sfSprite_getPosition(pnj->pnj_s);
    sfVector2f br = {0, 0};

    br.x = pos.x + (lb.width * pnj->scale.x) + 120;
    br.y = pos.y + (lb.height * pnj->scale.y) + 120;
    return (br);
}

int enter_is_near_pnj(game_object *p, pnj_t *pnj, sfVector2f *pos_pnj)
{
    sfVector2f p_mid = {p->p.x + ((p->rect.width * p->scale.x) / 2),
    p->p.y + ((p->rect.height * p->scale.y) / 2)};
    sfVector2f ul = {0, 0};
    sfVector2f br = {0, 0};

    while (pnj) {
        ul = get_ul_pnj(pnj);
        br = get_br_pnj(pnj);
        if (p_mid.x > ul.x && p_mid.x < br.x
        && p_mid.y > ul.y && p_mid.y < br.y) {
            *pos_pnj = sfSprite_getPosition(pnj->pnj_s);
            return (pnj->nb);
        }
        pnj = pnj->next;
    }
    return (-1);
}

void scenario(scene_s *sc, pnj_quest_t *pq)
{
    sfVector2f pos_pnj = {0, 0};
    int pnj = 0;
    int ret = 0;

    if ((pnj = enter_is_near_pnj(sc->player, pq->pnj, &pos_pnj)) == -1)
        return;
    if (pnj == 0) {
        deckard_fst_part(sc, pq);
        deckard_scd_part(sc, pq);
    }
    if (pnj == 1) {
        backrith_fst_part(sc, pq, &ret);
        backrith_scd_part(sc, pq, &ret);
        backrith_trd_part(sc, pq, &ret);
        backrith_four_part(sc, pq);
        backrith_five_part(pq, &ret);
    }
    if (pq->quest_nb < 46)
        sfText_setPosition(pq->quest[pq->quest_nb],
        (sfVector2f){pos_pnj.x - 100, pos_pnj.y - 100});
}