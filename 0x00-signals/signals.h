#ifndef SIGNALS_H
#define SIGNALS_H

#include <signal.h>
#include <stdio.h>

int handle_signal(void);
void handle_sigint(int sig);

#endif
