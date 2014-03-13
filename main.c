/*
 * main.cpp, entry point of the program
 *
 * weizhenwei <weizhenwei1988@gmail.com>
 * Date: 2014.03.12
 *
 * vim settings: set ts=4, set expandtab
 * replace tab with space: %retab!
 */

#include <locale.h>

#include "wsocket.h"


int main(int argc, char *argv[])
{
    // set locale according current environment;
    setlocale(LC_ALL, "");

    mainLoop();

    return 0;
}
