#include <sys/types.h>
#include <signal.h>

/**
 * pid_exist - Checks if a process ID exists
 * @pid: the process ID to check
 * Return: Greater than 0 if process found
*/
int pid_exist(pid_t pid)
{
	return (!kill(pid, 0));
}
