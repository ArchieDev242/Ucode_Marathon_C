#include "only_smiths.h"

int agent_smith(t_agent *agent, int strength) 
{
	if(mx_strcmp(agent -> name, "Smith") == 0 && agent -> strength < strength) 
	{
		return 1;
	}

	return 0;
}

t_agent **mx_only_smiths(t_agent **agents, int strength) 
{
	int number = 0;

	if(agents == NULL) 
	{
		return NULL;
	}

	for(int i = 0; agents[i] != NULL; i++) 
	{
		if(agent_smith(agents[i], strength) == 1) 
		{
			number += 1;
		}
	}

	t_agent **new_smith = malloc(sizeof(t_agent*) * (number + 1));

	int k = 0;
	for(int i = 0; agents[i] != NULL; i++) 
	{
		if(agent_smith(agents[i], strength) == 1) 
		{
			new_smith[k] = mx_create_agent(agents[i] -> name, agents[i] -> power, agents[i] -> strength);
			k += 1;
		}
	}
	new_smith[k] = NULL;
	mx_exterminate_agents(&agents);

	return new_smith;
}

