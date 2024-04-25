#include <stdio.h>

#include <limits.h>

#include <stdbool.h>

#include <string.h>

#define V 6

int edmonds_karp(int graph[V][V], int source, int sink);

bool bfs(int rGraph[V][V], int source, int sink, int parent[]);

int min(int a, int b) {

return (a < b) ? a : b;

}

int main() {

int graph[V][V] = {

{0, 16, 13, 0, 0, 0},

{0, 0, 10, 12, 0, 0},

{0, 4, 0, 0, 14, 0},

{0, 0, 9, 0, 0, 20},

{0, 0, 0, 7, 0, 4},{0, 0, 0, 0, 0, 0}

};

int source = 0;

int sink = 5;

printf("The maximum possible flow is %d\n", edmonds_karp(graph, source, sink));

return 0;

}

int edmonds_karp(int graph[V][V], int source, int sink) {

int u, v;

int rGraph[V][V];

for (u = 0; u < V; u++)

for (v = 0; v < V; v++)

rGraph[u][v] = graph[u][v];

int parent[V];

int max_flow = 0;

while (bfs(rGraph, source, sink, parent)) {

int path_flow = INT_MAX;

for (v = sink; v != source; v = parent[v]) {

u = parent[v];

path_flow = min(path_flow, rGraph[u][v]);

}

for (v = sink; v != source; v = parent[v]) {u = parent[v];

rGraph[u][v] -= path_flow;

rGraph[v][u] += path_flow;

}

max_flow += path_flow;

}

return max_flow;

}

bool bfs(int rGraph[V][V], int source, int sink, int parent[]) {

bool visited[V];

memset(visited, 0, sizeof(visited));

int queue[V];

int front = 0, rear = 0;

queue[rear++] = source;

visited[source] = true;

parent[source] = -1;

while (front < rear) {

int u = queue[front++];

for (int v = 0; v < V; v++) {

if (visited[v] == false && rGraph[u][v] > 0) {

queue[rear++] = v;

parent[v] = u;

visited[v] = true;

}

}}

return (visited[sink] == true);

}