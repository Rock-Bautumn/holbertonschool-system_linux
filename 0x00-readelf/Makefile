# -*- MakeFile -*-

all: 0-hreadelf 1-hreadelf 2-hreadelf

0-hreadelf: task0.c
	gcc task0.c -Wall -pedantic -Wextra -Werror -std=c90 -g -o 0-hreadelf

1-hreadelf: testfile1.c
	gcc testfile1.c -Wall -pedantic -Wextra -Werror -std=c90 -g -o 1-hreadelf

2-hreadelf: task2.c
	gcc task2.c -Wall -pedantic -Wextra -Werror -std=c90 -g -o 2-hreadelf

clean:
	rm 0-hreadelf 1-hreadelf 2-hreadelf
