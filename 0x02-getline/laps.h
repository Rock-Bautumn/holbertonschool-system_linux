#ifndef LAPS_H
#define LAPS_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

/**
 * struct racer_node - A singly linked list node that holds racer data
 * @id: the ID of the car
 * @laps: the number of laps completed
 * @next: the next node
*/

typedef struct racer_node
{
	int id;
	int laps;
	struct racer_node *next;
} racer;


void check_racer_id(racer **racer_head, int id);
void free_racers(racer *racer_head);
void print_race_state(racer **racer_head);
void race_state(int *id, size_t size);

racer *new_car(int id);



#endif
