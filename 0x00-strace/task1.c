#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <unistd.h>
#include "syscalls.h"

/**
 * fatal_error - ends the process while printing an error
 * @error_text: the message to print when exiting
 * Return: void
*/

void fatal_error(char *error_text)
{
	fprintf(stderr, "ERROR: %s\n", error_text);
	exit(EXIT_FAILURE);
}

/**
 * main - Forks a child process that is ptraced
 * @argc: The number of args
 * @argv: The filepath of the executable to possess our child
 * @environ: the environment of our process
 * Return: void
 */

int main(int argc, char **argv, char **environ)
{
	pid_t pid;
	struct user_regs_struct user_regs;
	int child_status = EXIT_FAILURE;
	size_t alternator = 0;

	if (argc < 2)
		fatal_error("No program provided");
	pid = fork();
	if (pid == -1)
		fatal_error("Fork failed");
	else if (pid > 0)
	{
		puts("execve");
		while (!WIFEXITED(child_status))
		{
			alternator++;
			ptrace(PTRACE_SYSCALL, pid, 0, 0);
			wait(&child_status);
if (ptrace(PTRACE_GETREGS, pid, 0, &user_regs) == 0 && alternator % 2 == 0)
				printf("%s\n", syscalls_64_g[user_regs.orig_rax].name);
			fflush(stdout);
		}
		ptrace(PTRACE_DETACH, pid, NULL, NULL);
	}
	else if (pid == 0)
	{
		ptrace(PTRACE_TRACEME, pid, 0, 0);
		execve(argv[1], &argv[1], environ);
	}

	return (EXIT_SUCCESS);
}
