#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool mx_isalpa(int c);
bool mx_isdigit(int c);
bool mx_islower(int c);
bool mx_isupper(int c);

unsigned long mx_hex_to_nbr(const char *hex);

