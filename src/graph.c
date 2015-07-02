#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <cassert.h>

static struct vertex** create_vertex_array(int num_verticies)
{
    struct vertex **array = malloc(sizeof(struct vertex*) * num_verticies);
    if(array == NULL)
    {
        return NULL;
    }

    for(int i = 0; i < num_verticies; i++)
    {
        array[i] = NULL;
    }

    return array;
}

struct graph* create_graph(int num_verticies)
{
    struct graph *graph = malloc(sizeof(struct graph));
    if(graph == NULL)
    {
        return NULL;
    }

    graph->vertex_count = 0;
    graph->vertex_limit = num_verticies;
    graph->adj_list = create_vertex_array(num_verticies);
}
