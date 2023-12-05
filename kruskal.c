#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int numNodes, numEdges;
    struct Edge edge[MAX_EDGES];
};

struct Subset {
    int parent;
    int rank;
};

struct Graph* createGraph(int numNodes, int numEdges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph != NULL) {
        graph->numNodes = numNodes;
        graph->numEdges = numEdges;
    }
    return graph;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST(struct Graph* graph) {
    int numNodes = graph->numNodes;
    struct Edge result[numNodes];
    int e = 0; // Index variable for result[]
    int i = 0; // Index variable for sorted edges array

    qsort(graph->edge, graph->numEdges, sizeof(graph->edge[0]), compare);

    struct Subset* subsets = (struct Subset*)malloc(numNodes * sizeof(struct Subset));

    for (int v = 0; v < numNodes; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < numNodes - 1 && i < graph->numEdges) {
        struct Edge nextEdge = graph->edge[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int j = 0; j < e; ++j) {
        printf("%d - %d  Weight: %d\n", result[j].src, result[j].dest, result[j].weight);
    }

    free(subsets);
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &numNodes, &numEdges);

    struct Graph* graph = createGraph(numNodes, numEdges);

    printf("Enter edges and their weights (source destination weight):\n");
    for (int i = 0; i < numEdges; ++i) {
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    kruskalMST(graph);
    
    free(graph);

    return 0;
}


