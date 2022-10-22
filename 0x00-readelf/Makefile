# -*- MakeFile -*-

all: 0-hreadelf 1-hreadelf 2-hreadelf

0-hreadelf: task0.c task_0a.c task_0b.c task_0c.c
	gcc task0.c task_0a.c task_0b.c task_0c.c -Wall -pedantic -Wextra -Werror -std=c90 -g -o 0-hreadelf

1-hreadelf: task1.c task_1a.c task_1b.c
	gcc task1.c task_1a.c task_1b.c -Wall -pedantic -Wextra -Werror -std=c90 -g -o 1-hreadelf

2-hreadelf: task2.c task_2a.c task_2b.c
	gcc task2.c task_2a.c task_2b.c -Wall -pedantic -Wextra -Werror -std=c90 -g -o 2-hreadelf

clean:
	rm -f 0-hreadelf 1-hreadelf 2-hreadelf
