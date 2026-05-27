#include <iostream>
#include <climits>
using namespace std;

int main() {
    int V;
    cin >> V;

    int graph[100][100];

    // Input adjacency matrix
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cin >> source;

    int dist[100];
    bool visited[100];

    // Initialize
    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    // Dijkstra Algorithm
    for(int count = 0; count < V - 1; count++) {

        int u = -1;
        int mini = INT_MAX;

        // Find minimum distance vertex
        for(int i = 0; i < V; i++) {
            if(!visited[i] && dist[i] < mini) {
                mini = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        // Update distances
        for(int v = 0; v < V; v++) {

            if(graph[u][v] != 0 &&
               !visited[v] &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output
    cout << "Vertex Distance from Source" << endl;

    for(int i = 0; i < V; i++) {
        cout << i << "->" << dist[i] << endl;
    }

    return 0;
}
