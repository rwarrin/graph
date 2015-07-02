#include "graph.h"

#include <stdio.h>

int main(void)
{
    /**
     * This is the graph structure we're going to attempt to build
     * 0-2-3
     * |
     * 1-4
     */

    const int MAX_VERTICIES = 5;

    // create the graph
    struct graph *graph = create_graph(MAX_VERTICIES);
    if(graph == NULL)
    {
        fprintf(stderr, "Failed to create graph\n");
        return 1;
    }

    // add 5 verticies to the graph
    for(int i = 0; i < MAX_VERTICIES; i++)
    {
        struct vertex *vertex = graph_add_vertex(graph, i);
        if(vertex == NULL)
        {
            fprintf(stderr, "Failed to add vertex to graph: %d\n", i);
            return 2;
        }
    }

    // add the edges to the graph
    graph_add_edge(graph, 0, 1, 0);
    graph_add_edge(graph, 0, 2, 0);

    graph_add_edge(graph, 1, 0, 0);
    graph_add_edge(graph, 1, 4, 0);

    graph_add_edge(graph, 2, 0, 0);
    graph_add_edge(graph, 2, 3, 0);

    graph_add_edge(graph, 3, 2, 0);

    graph_add_edge(graph, 4, 1, 0);

    // print the graph
    graph_print(graph);

    // free memory allocated by the graph
    destroy_graph(graph);

    return 0;
}
