#include "laps.h"

/**
 * free_racers - Deallocates all of the racers from memory
 * @racer_head: The head node of the racer linked list
 * Return: void
*/

void free_racers(racer *racer_head)
{

	racer *thisRacer = racer_head;
	racer *freeRacer;

	while (thisRacer)
	{
		freeRacer = thisRacer;
		thisRacer = thisRacer->next;
		free(freeRacer);
	}

}

/**
 * print_race_state - prints the status of the race to console
 * @racer_head: The head node of the racer linked list
 * Return: void
*/

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

/**
 * check_racer_id - checks if the ID exists in the racer linked list
 * @racer_head: The head node of the racer linked list
 * @id: the ID of the car
 * Return: void
*/

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

/**
 * new_car - creates a new racer linked list node
 * @id: the ID of the car
 * Return: the address of a the new car node
*/

racer *new_car(int id)
{
	racer *newRacer;

	newRacer = malloc(sizeof(racer));
	if (newRacer == NULL)
		return (NULL);

	newRacer->next = NULL;
	newRacer->laps = 0;
	newRacer->id = id;
	printf("Car %d joined the race\n", newRacer->id);

	return (newRacer);

}

/**
 * race_state - updates and prints out the race state, updating
 * the number of laps for each id included in the array
 * @id: an array of car IDs
 * @size: the size of the array of IDs
 * Return: void
*/

void race_state(int *id, size_t size)
{
	static racer *racer_head;
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

