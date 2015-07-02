#ifndef GRAPH_H
#define GRAPH_H

struct vertex
{
    int id;
    struct edge *edges;
};

struct edge
{
    double weight;
    struct vertex *vertex;
    struct edge *next_edge;
};

struct graph
{
    int vertex_count;
    int vertex_limit;
    struct vertex **adj_list;
};

struct graph* create_graph(int num_verticies);

#endif  // GRAPH_H
