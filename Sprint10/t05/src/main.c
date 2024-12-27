#include "../inc/header.h"

int main(int argc, char *argv[]) 
{ 
    if(argc != 3) 
    {
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        exit(0);
    }

    if(mx_strcmp(argv[1], "-p") != 0 && mx_strcmp(argv[1], "-s") != 0 && mx_strcmp(argv[1], "-n") != 0) 
    {
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        exit(0);
    }

    int count_array = 0;
    char buffer, helper;
    int count_of_agents = 0;
    bool issp = false;
    int file = open(argv[2], O_RDONLY);

    if(file < 0) 
    {
        mx_printerr("error\n");
        exit(0);
    }

    while(read(file, &buffer, 1)) if (buffer == '{') count_of_agents++;

    if(close(file) < 0) 
    {
        mx_printerr("error\n");
        exit(0);
    }

    t_agent **agents = (t_agent**)malloc(16 * count_of_agents);
    for(int i = 0; i < count_of_agents; i++)
        agents[i] = (t_agent*)malloc(16);
    char *temp = mx_strnew(100);
    int indicator = 0;

    file = open(argv[2], O_RDONLY);

    if(file < 0) 
    {
        mx_printerr("error\n");
        exit(0);
    }

    while(read(file, &buffer, 1)) 
    {
        if(issp && buffer != '\n') 
        {
            temp[indicator++] = buffer;          
        }

        if(issp && buffer == '\n') 
        {
            issp = false;
            temp[indicator++] = ' ';
        }
        if(buffer == ' ' && helper == ':')issp = true;
        helper = buffer;
    }

    if(close(file) < 0) 
    {
        mx_printerr("error\n");
        exit(0);
    }

    char **arr = mx_strsplit(temp, ' ');

    while(*arr) 
    {
        count_array++;
        arr++;
    }

    arr -= count_array;

    int o = 0;

    for(int i = 0; i < count_of_agents; i++) 
    {
        agents[i] -> name = arr[o++];
        agents[i] -> power = mx_atoi(arr[o++]);
        agents[i] -> strength = mx_atoi(arr[o++]);
    }

    if(mx_strcmp(argv[1], "-p") == 0) 
    {
        for(int i = 0; i < count_of_agents; i++) 
        {
            for(int j = 0; j < count_of_agents - 1; j++) 
            {
                if (agents[j] -> power > agents[j + 1] -> power) 
                {
                    t_agent temp_agent = *agents[j];
                    *agents[j] = *agents[j + 1];
                    *agents[j + 1] = temp_agent;
                }
            }
        }
            mx_print_agents(agents, count_of_agents);
    } else if(mx_strcmp(argv[1], "-s") == 0) 
    {
        for(int i = 0; i < count_of_agents; i++) 
        {
            for(int j = 0; j < count_of_agents - 1; j++) 
            {
                if(agents[j] -> strength > agents[j + 1] -> strength) 
                {
                    t_agent temp_agent = *agents[j];
                    *agents[j] = *agents[j + 1];
                    *agents[j + 1] = temp_agent;
                }
            }
        }
            mx_print_agents(agents, count_of_agents);
    } else if(mx_strcmp(argv[1], "-n") == 0) 
    {
        for(int i = 0; i < count_of_agents; i++) 
        {
            for(int j = 0; j < count_of_agents - 1; j++) 
            {
                if(mx_strcmp(agents[j] -> name, agents[j + 1] -> name) > 0) 
                {
                    t_agent temp_agent = *agents[j];
                    *agents[j] = *agents[j + 1];
                    *agents[j + 1] = temp_agent;
                }
            }
        }
            mx_print_agents(agents, count_of_agents);
    }

    for(int i = 0; i < count_of_agents; i++) 
    {
        free(agents[i]);
        agents[i] = NULL;
    }

    free(agents);
    agents = NULL;
    count_array = 0;

    while(arr[count_array] != NULL) 
    {
        free(arr[count_array++]);
        arr[count_array++] = NULL;
    }

    free(arr);
    arr = NULL;
    free(arr);
    arr = NULL;
    free(temp);
    temp = NULL;

    return 0;
}

