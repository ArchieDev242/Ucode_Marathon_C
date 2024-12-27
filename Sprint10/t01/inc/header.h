#pragma once

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int mx_strlen(const char *s);
void mx_printerr(const char *s);

