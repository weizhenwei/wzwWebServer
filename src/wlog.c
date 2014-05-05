/*
 * wlog.cpp, definitions of log apis
 *
 * weizhenwei <weizhenwei1988@gmail.com>
 * Date: 2014.05.05
 *
 * vim settings: set ts=4, set expandtab
 * replace tab with space: %retab!
 */

#include "wlog.h"

void syslog_open()
{
    openlog("wzwWebServer", LOG_PID, LOG_USER);
}

void syslog_write(int priority, const char *format, ...)
{
    // TODO
}

void syslog_close()
{
    closelog();
}
