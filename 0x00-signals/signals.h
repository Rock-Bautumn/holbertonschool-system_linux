#ifndef SIGNALS_H
#define SIGNALS_H

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* task 0 */
int handle_signal(void);
void handle_sigint(int sig);

/* task 1 */
void print_hello(int);
void set_print_hello(void);
void (*current_handler_signal(void))(int);

/* task 2 */
int handle_sigaction(void);

/* task 3 */
void (*current_handler_sigaction(void))(int);

/* task 4 */
int trace_signal_sender(void);

/* task 5 */


/* task 6 */


/* task 7 */


/* task 8 */


/* task 9 */


/* task 10 */
int pid_exist(pid_t pid);

#endif
