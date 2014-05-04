/*
 * main.cpp, entry point of the program
 *
 * weizhenwei <weizhenwei1988@gmail.com>
 * Date: 2014.05.02
 *
 * vim settings: set ts=4, set expandtab
 * replace tab with space: %retab!
 */

#ifndef WSIGNAL_H
#define WSIGNAL_H

#include <signal.h>
#include <bits/signum.h>

void signal_init();

void signal_register(int sig, void (*sighandler)(int));




#endif
