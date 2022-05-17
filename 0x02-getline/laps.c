#include "laps.h"

void free_racers(void)
{
	static racer *racer_head;

	racer *thisRacer = racer_head;
	racer *freeRacer;

	while (thisRacer->next != NULL)
	{
		printf("Freeing car %d\n", thisRacer->id);
		freeRacer = thisRacer;
		thisRacer = thisRacer->next;
		free(freeRacer);
	}

}

void print_race_state(void)
{
	static racer **racer_head;

	racer *thisRacer = *racer_head;

	while (thisRacer->next != NULL)
	{
		printf("Car %d [%d laps]\n", thisRacer->id, thisRacer->laps);
		thisRacer = thisRacer->next;
	}
}

void check_racer_id(int id)
{
	
	static racer **racer_head;

	racer *thisRacer = racer_head;
	int match = 0;
	racer *newRacer;

	while (thisRacer->next != NULL)
	{
		if (thisRacer->id == id)
		{
			thisRacer->laps++;
			match = 1;
		}
		thisRacer = thisRacer->next;

	}
	if (match == 1)
		return;
	
	newRacer = malloc(sizeof(racer));
	if (newRacer == NULL)
		return;
	
	if (thisRacer == *racer_head)
		*racer_head = newRacer;
	else
		thisRacer->next = newRacer;

	newRacer->next = NULL;
	newRacer->laps = 0;
	newRacer->id = id;
	printf("Car %d joined the race\n", newRacer->id);

}

void race_state(int *id, size_t size)
{
	static racer *racer_head = NULL;
	unsigned int i = 0;

	
	(void) racer_head;
	if (size == 0)
	{
		free_racers();
		return;
	}

	for (i = 0; i < size; i++)
	{
		check_racer_id(*id);
	}

	print_race_state();
}

