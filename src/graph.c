#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

static void destroy_vertex_array(struct vertex **array, int num_verticies)
{
    if(array == NULL)
    {
        return;
    }

    for(int i = 0; i < num_verticies; i++)
    {
        if(array[i] != NULL)
        {
            free(array[i]);
        }
    }
    free(array);
}

static struct edge* create_edge_for_vertex(struct vertex *vertex)
{
    if(vertex == NULL)
    {
        return NULL;
    }

    struct edge *edge = malloc(sizeof(struct edge));
    if(edge == NULL)
    {
        return NULL;
    }

    edge->weight = 0;
    edge->vertex = NULL;
    edge->next_edge = NULL;

    if(vertex->edges == NULL)
    {
        vertex->edges = edge;
    }
    else
    {
        struct edge *walker = vertex->edges;
        while(walker->next_edge != NULL)
        {
            walker = walker->next_edge;
        }

        walker->next_edge = edge;
    }

    return edge;
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

    return graph;
}

static void delete_edge_list_for_vertex(struct vertex *vertex)
{
    if(vertex == NULL)
    {
        return;
    }

    struct edge *walker = vertex->edges;
    while(walker != NULL)
    {
        vertex->edges = vertex->edges->next_edge;
        free(walker);
        walker = vertex->edges;
    }
}

void destroy_graph(struct graph *graph)
{
    if(graph == NULL)
    {
        return;
    }

    for(int i = 0; i < graph->vertex_limit; i++)
    {
        delete_edge_list_for_vertex(graph->adj_list[i]);
    }

    destroy_vertex_array(graph->adj_list, graph->vertex_limit);
    free(graph);
}

struct vertex* graph_add_vertex(struct graph *graph, int id)
{
    if(graph == NULL)
    {
        return NULL;
    }
    
    if(graph->adj_list[id] != NULL)
    {
        return NULL;
    }

    struct vertex *vertex = malloc(sizeof(struct vertex));
    if(vertex == NULL)
    {
        return NULL;
    }

    vertex->id = id;
    vertex->edges = NULL;

    graph->adj_list[id] = vertex;
    
    return vertex;
}

struct edge* graph_add_edge(struct graph *graph, int from_vertex_id, int to_vertex_id, int weight)
{
    if(graph == NULL)
    {
        return NULL;
    }

    if(graph->adj_list[from_vertex_id] == NULL)
    {
        return NULL;
    }

    if(graph->adj_list[to_vertex_id] == NULL)
    {
        return NULL;
    }

    struct vertex *from_vertex = graph->adj_list[from_vertex_id];
    struct vertex *to_vertex = graph->adj_list[to_vertex_id];

    struct edge *edge = create_edge_for_vertex(from_vertex);
    if(edge == NULL)
    {
        return NULL;
    }

    edge->weight = weight;
    edge->vertex = to_vertex;
    return edge;
}

void graph_print(struct graph *graph)
{
    if(graph == NULL)
    {
        return;
    }

    struct edge *walker = NULL;
    for(int i = 0; i < graph->vertex_limit; i++)
    {
        printf("[%3d] => ", i);
        if(graph->adj_list[i] == NULL)
        {
            printf("DOES NOT EXIST");
        }
        else
        {
            walker = graph->adj_list[i]->edges;
            while(walker != NULL)
            {
                printf("%3d(%3.2f), ", walker->vertex->id, walker->weight);
                walker = walker->next_edge;
            }
        }
        printf("\n");
    }
}
