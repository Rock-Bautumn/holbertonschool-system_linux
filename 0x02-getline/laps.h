#ifndef LAPS_H
#define LAPS_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void check_racer_id(int id);
void free_racers(void);
void print_race_state(void);
void race_state(int *id, size_t size);

typedef struct racer_node {
	int id;
	int laps;
	struct racer_node *next;
} racer;



#endif
