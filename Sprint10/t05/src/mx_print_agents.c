#include "../inc/header.h"

void mx_print_agents(t_agent **agents, int count_of_agents) 
{
    for(int i = 0; i < count_of_agents; i++) 
    {
        mx_printstr("agent: ");
        mx_printstr(agents[i] -> name);          
        mx_printstr(", power: ");
        mx_printint(agents[i] -> power);
        mx_printstr(", strength: ");
        mx_printint(agents[i] -> strength);
        mx_printchar('\n');
    }
}

