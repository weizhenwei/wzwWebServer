/*
 * wlog.h, definitions of log apis
 *
 * weizhenwei <weizhenwei1988@gmail.com>
 * Date: 2014.05.05
 *
 * vim settings: set ts=4, set expandtab
 * replace tab with space: %retab!
 */

#ifndef  WLOG_H
#define WLOG_H

#include <syslog.h>

void syslog_open();
void syslog_write(int priority, const char *format, ...);
void syslog_close();

#endif
