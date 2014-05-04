/*
 * main.cpp, entry point of the program
 *
 * weizhenwei <weizhenwei1988@gmail.com>
 * Date: 2014.05.02
 *
 * vim settings: set ts=4, set expandtab
 * replace tab with space: %retab!
 */
#include "wsignal.h"

void signal_init()
{

    signal(SIGPIPE, SIG_IGN);
    signal(SIGHUP, SIG_DFL);
    signal(SIGTERM, SIG_DFL);
    signal(SIGINT, SIG_DFL);
}

void signal_register(int sig, void (*sighandler)(int))
{
    //TODO
    signal(sig, sighandler);
}
