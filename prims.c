#include <stdio.h>
#include <limits.h>

#define V 100 

int minKey(int key[], int mstSet[], int numNodes) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < numNodes; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int printMST(int parent[], int numNodes, int graph[V][V]) {
    printf("Edge   Weight\n");
    for (int i = 1; i < numNodes; i++) {
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V], int numNodes) {
    int parent[V], key[V], mstSet[V];

    for (int i = 0; i < numNodes; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numNodes - 1; count++) {
        int u = minKey(key, mstSet, numNodes);
        mstSet[u] = 1;

        for (int v = 0; v < numNodes; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, numNodes, graph);
}

int main() {
    int numNodes, numEdges;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    int graph[V][V] = {0};
    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, numNodes);

    return 0;
   }
}


