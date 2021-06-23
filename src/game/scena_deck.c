/*
** EPITECH PROJECT, 2020
** scena deckard
** File description:
** rpg
*/

#include "rpg.h"

void deckard_fst_part(scene_s *sc, pnj_quest_t *pq)
{
    if (pq->quest_nb >= 0 && pq->quest_nb <= 14) {
        sfSound_play(sc->sound_music->sound[1]->sound);
        pq->in_speak = 1;
        pq->quest_nb += 1;
    }
    if (pq->quest_nb == 15 && pq->in_speak == 1) {
        pq->in_speak = 0;
    }
}

void deckard_scd_part(scene_s *sc, pnj_quest_t *pq)
{
    if (pq->quest_nb >= 38 && pq->quest_nb < 46) {
        pq->in_speak = 1;
        if (pq->quest_nb == 40) {
            pq->quest_nb = 38;
            pq->in_speak = 0;
        } else if (pq->quest_nb == 39 && sc->totem == 1) {
            sfSound_play(sc->sound_music->sound[4]->sound);
            sc->totem = 0;
            pq->quest_nb = 41;
        } else {
            sfSound_play(sc->sound_music->sound[1]->sound);
            pq->quest_nb += 1;
        }
    }
    if (pq->quest_nb == 46) {
        pq->in_speak = 0;
    }
}