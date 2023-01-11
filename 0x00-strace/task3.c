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
 * print_params - print the syscall parameters
 * @user_regs: The registers in the user space
 * Return: void 
*/
/* sysc  0   1   2   3  4  5 */
/* RAX RDI RSI RDX R10 R8 R9 */
void print_params(struct user_regs_struct *user_regs)
{
	size_t param_qty = syscalls_64_g[user_regs->orig_rax].nb_params;
	size_t this_param = 0;

	if (syscalls_64_g[user_regs->orig_rax].params[0] == VOID)
		return;
	while (this_param < param_qty)
	{
		switch (this_param)
		{
		case 0:
			printf("%s%lx",  user_regs->rdi == 0 ? "" : "0x", (size_t) user_regs->rdi);
			break;
		case 1:
			printf("%s%lx",  user_regs->rsi == 0 ? "" : "0x", (size_t) user_regs->rsi);
			break;
		case 2:
			if (syscalls_64_g[user_regs->orig_rax].params[2] == VARARGS)
			{
				printf("...");
				break;
			}
			printf("%s%lx",  user_regs->rdx == 0 ? "" : "0x", (size_t) user_regs->rdx);
			break;
		case 3:
			printf("%s%lx",  user_regs->r10 == 0 ? "" : "0x", (size_t) user_regs->r10);
			break;
		case 4:
			printf("%s%lx",  user_regs->r8 == 0 ? "" : "0x", (size_t) user_regs->r8);
			break;
		case 5:
			printf("%s%lx",  user_regs->r9 == 0 ? "" : "0x", (size_t) user_regs->r9);
			break;
		default:
			break;
		}
		this_param++;
		if (this_param < param_qty)
			printf(", ");
	}
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
		printf("execve(0, 0, 0");
		while (!WIFEXITED(child_status))
		{
			alternator++;
			ptrace(PTRACE_SYSCALL, pid, 0, 0);
			wait(&child_status);
if (ptrace(PTRACE_GETREGS, pid, 0, &user_regs) == 0 && alternator % 2 == 0)
			{
				printf("%s(", syscalls_64_g[user_regs.orig_rax].name);
				print_params(&user_regs);
				/* if (user_regs.orig_rax != 1)
					printf("()\n");
				*/
			}
			if (alternator % 2 == 1 && !WIFEXITED(child_status))
				printf(") = %s%lx\n", user_regs.rax == 0 ? "" : "0x", (size_t) user_regs.rax);
			/*
			if (user_regs.orig_rax == 1 && alternator % 2 == 1)
				printf("[]\n");
			*/
			fflush(stdout);
		}
		printf(") = ?\n");
		ptrace(PTRACE_DETACH, pid, NULL, NULL);
	}
	else if (pid == 0)
	{
		ptrace(PTRACE_TRACEME, pid, 0, 0);
		execve(argv[1], &argv[1], environ);
	}

	return (EXIT_SUCCESS);
}
