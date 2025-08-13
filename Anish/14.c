#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF 9999

int graph[MAX][MAX], n;

// Function to take graph input
void inputGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF; // no edge
            }
        }
    }
}

// Dijkstra's Algorithm for shortest path
void dijkstra(int start) {
    int cost[MAX][MAX], dist[MAX], visited[MAX], pred[MAX];
    int count, mindist, nextnode, i, j;

    // Prepare cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cost[i][j] = graph[i][j];

    // Initialize
    for (i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;
    count = 1;

    // Main loop
    while (count < n - 1) {
        mindist = INF;
        for (i = 0; i < n; i++)
            if (dist[i] < mindist && !visited[i]) {
                mindist = dist[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindist + cost[nextnode][i] < dist[i]) {
                    dist[i] = mindist + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    // Print results
    printf("\nShortest paths from vertex %d:\n", start);
    for (i = 0; i < n; i++) {
        if (i != start) {
            printf("To %d: Distance = %d, Path = %d", i, dist[i], i);
            j = i;
            while (j != start) {
                j = pred[j];
                printf(" <- %d", j);
            }
            printf("\n");
        }
    }
}

// Prim's Algorithm for MST
void prim() {
    int selected[MAX], no_of_edges = 0;
    int x, y; // row, col
    int total_cost = 0;

    for (int i = 0; i < n; i++)
        selected[i] = 0;

    selected[0] = 1;

    printf("\nEdges in the Minimum Spanning Tree:\n");
    while (no_of_edges < n - 1) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, graph[x][y]);
        total_cost += graph[x][y];
        selected[y] = 1;
        no_of_edges++;
    }
    printf("Total cost of MST: %d\n", total_cost);
}

// Main function
int main() {
    int start;
    inputGraph();

    printf("\n--- Shortest Path (Dijkstra) ---\n");
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    dijkstra(start);

    printf("\n--- Minimum Spanning Tree (Prim) ---\n");
    prim();

    return 0;
}
