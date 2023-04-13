# -*- MakeFile -*-

options = -Wall -Wextra -Werror -pedantic -g

src = helpers_src/*.c

all: todo_api_0 todo_api_1 todo_api_2
# todo_api_2 todo_api_3 todo_api_4

todo_api_0: 4-server.c
	gcc $(options) $(src) 4-server.c -o todo_api_0

todo_api_1: 5-server.c
	gcc $(options) $(src) 5-server.c -o todo_api_1

todo_api_2: 6-server.c
	gcc $(options) $(src) 6-server.c -o todo_api_2

# todo_api_3: 7-server.c
# 	gcc $(options) $(src) 7-server.c -o todo_api_3

# todo_api_4: 8-server.c
# 	gcc $(options) $(src) 8-server.c -o todo_api_4
