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
void destroy_graph(struct graph *graph);

struct vertex* graph_add_vertex(struct graph *graph, int id);
struct edge* graph_add_edge(struct graph *graph, int from_vertex_id, int to_vertex_id, int weight);
void graph_print(struct graph *graph);

#endif  // GRAPH_H
