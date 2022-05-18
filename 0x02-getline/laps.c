#include "laps.h"

void free_racers(racer *racer_head)
{

	racer *thisRacer = racer_head;
	racer *freeRacer;

	while (thisRacer)
	{
		printf("Freeing car %d\n", thisRacer->id);
		freeRacer = thisRacer;
		thisRacer = thisRacer->next;
		free(freeRacer);
	}

}

void print_race_state(racer **racer_head)
{

	racer *thisRacer = *racer_head;

	printf("Race state:\n");
	while (thisRacer)
	{
		printf("Car %d [%d laps]\n", thisRacer->id, thisRacer->laps);
		thisRacer = thisRacer->next;
	}
}

void check_racer_id(racer **racer_head, int id)
{
	racer *thisRacer = *racer_head;
	racer *prevRacer = NULL;
	racer *tempRacer = NULL;

	if (*racer_head == NULL)
	{
		*racer_head = new_car(id);
		return;
	}

	while (thisRacer)
	{
		if (thisRacer->id == id)
		{
			thisRacer->laps++;
			return;
		}

		if (thisRacer->id > id)
		{
			tempRacer = new_car(id);
			if (prevRacer)
				prevRacer->next = tempRacer;
			else
				*racer_head = tempRacer;
			tempRacer->next = thisRacer;
			return;
		}
		prevRacer = thisRacer;
		thisRacer = thisRacer->next;

	}

	prevRacer->next = new_car(id);
}

racer *new_car(int id)
{
	racer *newRacer;

	newRacer = malloc(sizeof(racer));
	if (newRacer == NULL)
		return NULL;
	
	newRacer->next = NULL;
	newRacer->laps = 0;
	newRacer->id = id;
	printf("Car %d joined the race\n", newRacer->id);

	return newRacer;

}

void race_state(int *id, size_t size)
{
	static racer *racer_head = NULL;
	unsigned int i = 0;

	
	(void) racer_head;
	if (size == 0)
	{
		free_racers(racer_head);
		return;
	}

	for (i = 0; i < size; i++)
	{
		check_racer_id(&racer_head, id[i]);
	}

	print_race_state(&racer_head);
}

