#include "create_new_agents.h"

t_agent *mx_create_agent(char *name, int power, int strength) 
{
    if (name == NULL || power == 0 || strength == 0) 
    {
        return NULL;
    }

    t_agent *agent = (t_agent*)malloc(16);
    agent -> name = mx_strdup(name);
    agent -> power = power;
    agent -> strength = strength;

    return agent;
}

