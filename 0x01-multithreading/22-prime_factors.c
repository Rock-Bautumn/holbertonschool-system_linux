#include "multithreading.h"
#include "list.h"

/**
 * create_task - Generates a task item to be executed later
 * @entry: The function that the task performs
 * @param: The parameters passed to the entry function
 * Return: 
 */

task_t *create_task(task_entry_t entry, void *param)
{
	task_t *this_task;

	this_task = malloc(sizeof(task_t));

	this_task->entry = entry;
	this_task->param = param;
	this_task->status = 0;

	pthread_mutex_init(&this_task->lock, NULL);

	return (this_task);
}

/**
 * destroy_task - Removes the task
 * @task: The task to destroy
 * Return: void
 */
void destroy_task(task_t *task)
{
	if (task->result)
	{
		list_destroy((list_t *) task->result, free);
		free((list_t *) task->result);
	}

	free(task);
}

/**
 * exec_tasks - Executes a list of tasks
 * @tasks: The list of tasks
 * Return: NULL
 */
void *exec_tasks(list_t const *tasks)
{
	node_t *this_node;
	task_t *this_task = NULL;
	int id = 0;

	if (tasks == NULL)
		pthread_exit(NULL);

	this_node = tasks->head;

	while (this_node != NULL)
	{
		this_task = this_node->content;
		if (pthread_mutex_trylock(&this_task->lock) == 0)
		{
			this_node = this_node->next;
			id++;
			continue;
		}

		if (this_task->status == PENDING)
		{
			this_task->status = STARTED;
			this_task->result = this_task->entry(this_task->param);

			tprintf("[%02d] Started\n", id);

			if (this_task->result == NULL)
				this_task->status = FAILURE;
			else
				this_task->status = SUCCESS;

			tprintf("[%02d] %s\n", id), (this_task->result == SUCCESS) ? "Success" : "Failure";
		}
		id++;
		this_node = this_node->next;
	}

	return (NULL);
}
