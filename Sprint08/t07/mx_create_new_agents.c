#include <stdlib.h>
#include <stddef.h>
#include "agent.h"


t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count)
{
	if(name == NULL || power == NULL || strength == NULL)
	{
			return NULL;
	}

	t_agent **agents = (t_agent**)malloc(16 * (count + 1));;

	for(int i = 0; i < count; i++)
		agents[i] = mx_create_agent(name[i], power[i], strength[i]);
	agents[count] = NULL;
	return agents;
}
