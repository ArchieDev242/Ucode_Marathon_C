#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "agent.h"

    
t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count);    
t_agent *mx_create_agent(char *name, int power, int strength);
char *mx_strnew(const int size);
char* mx_strcpy(char* dst, const char* src);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);