/*
** EPITECH PROJECT, 2020
** scenario backrith
** File description:
** rpg
*/

#include "rpg.h"

void backrith_fst_part(scene_s *sc, pnj_quest_t *pq, int *ret)
{
    if (pq->quest_nb >= 15 && pq->quest_nb <= 21) {
        sfSound_play(sc->sound_music->sound[1]->sound);
        pq->in_speak = 1;
        pq->quest_nb += 1;
        *ret = 1;
    }
}

void backrith_scd_part(scene_s *sc, pnj_quest_t *pq, int *ret)
{
    if (pq->quest_nb >= 22 && pq->quest_nb < 25 && *ret == 0) {
        pq->in_speak = 1;
        if (pq->quest_nb == 24) {
            pq->quest_nb = 22;
            pq->in_speak = 0;
        } else if (pq->quest_nb == 23 && sc->gutlet->gutlets[0] >= 18) {
            sc->gutlet->gutlets[0] -= 18;
            sfText_setString(sc->gutlet->text[0],
            int_to_str(sc->gutlet->gutlets[0]));
            sfSound_play(sc->sound_music->sound[4]->sound);
            pq->quest_nb = 25;
            *ret = 1;
        } else {
            sfSound_play(sc->sound_music->sound[1]->sound);
            pq->quest_nb += 1;
        }
    }
    if (pq->quest_nb == 22 && pq->in_speak == 1)
        pq->in_speak = 0;
}

void backrith_trd_part(scene_s *sc, pnj_quest_t *pq, int *ret)
{
    if (pq->quest_nb >= 26 && pq->quest_nb < 29) {
        pq->in_speak = 1;
        if (pq->quest_nb == 28) {
            pq->quest_nb = 26;
            pq->in_speak = 0;
        } else if (pq->quest_nb == 27 && sc->gutlet->gutlets[1] >= 16) {
            sc->gutlet->gutlets[1] -= 16;
            sfText_setString(sc->gutlet->text[1],
            int_to_str(sc->gutlet->gutlets[1]));
            sfSound_play(sc->sound_music->sound[4]->sound);
            pq->quest_nb = 29;
            *ret = 1;
        } else {
            sfSound_play(sc->sound_music->sound[1]->sound);
            pq->quest_nb += 1;
        }
    }
    if (pq->quest_nb == 25 && *ret == 0) {
        pq->quest_nb += 1;
        pq->in_speak = 0;
    }
}

void backrith_four_part(scene_s *sc, pnj_quest_t *pq)
{
    if (pq->quest_nb == 38)
        pq->in_speak = 0;
    if (pq->quest_nb >= 30 && pq->quest_nb < 38) {
        pq->in_speak = 1;
        if (pq->quest_nb == 32) {
            pq->quest_nb = 30;
            pq->in_speak = 0;
        } else if (pq->quest_nb == 31 && sc->gutlet->gutlets[2] >= 24) {
            sc->gutlet->gutlets[2] -= 24;
            sfText_setString(sc->gutlet->text[2],
            int_to_str(sc->gutlet->gutlets[2]));
            sfSound_play(sc->sound_music->sound[4]->sound);
            pq->quest_nb = 33;
        } else {
            sfSound_play(sc->sound_music->sound[1]->sound);
            pq->quest_nb += 1;
        }
    }
}

void backrith_five_part(pnj_quest_t *pq, int *ret)
{
    if (pq->quest_nb == 29 && *ret == 0) {
        pq->quest_nb += 1;
        pq->in_speak = 0;
    }
}