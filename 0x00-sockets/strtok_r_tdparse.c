
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

int
main(int argc, char *argv[])
{
	char *str1, *str2, *token, *subtoken;
	char *saveptr1, *saveptr2, *key = NULL, *value = NULL, *key2, *value2;
	int j, k;
	ll_tdnode *head = NULL, *t_n;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (j = 1, str1 = argv[1]; ; j++, str1 = NULL) {
		token = strtok_r(str1, "&", &saveptr1);
		if (token == NULL)
			break;
		printf("%d: %s\n", j, token);

		for (k = 1, str2 = token; ; k++, str2 = NULL) {
			subtoken = strtok_r(str2, "=", &saveptr2);
			printf("subtoken = %s\n", subtoken);
			if (subtoken == NULL)
				break;
			if (j == 1)
			{
				if (k == 1)
					key = subtoken;
				else if (k == 2)
					value = subtoken;
			}
			else if (j == 2)
			{
				if (k == 1)
					key2 = subtoken;
				else if (k == 2)
					value2 = subtoken;
			}
		}
	}
	appendTDNode(&head, key, value, key2, value2);
			printf(" --> (%d, %d) %s\n", j, k, subtoken);
	t_n = head;

	for (; t_n; t_n = t_n->next)
	{
		printf("node contains: %s = %s & %s = %s\n", key, value, key2, value2);
	}

	exit(EXIT_SUCCESS);
}

