#include<stdio.h>
#define INF 9999
#define V 4

void printsolution(int dist[V][V]){
    printf("The following matrix shows the shortest distances between every pair of vertices \n");

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j] == INF){
                printf("%7s","INF");
            }else{
                printf("%7d",dist[i][j]);
            }
        }
        printf("\n");

    }



}

void floydWarshall(int dist[V][V]){
    int i,j,k;

    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
        
            }
        
        }
    }

    printsolution(dist);
}

int main()
{
    
    int graph[V][V] = { { 0, 9, -4, INF },
                        { 6, 0, INF, 2 },
                        { INF, 5, 0, INF },
                        { INF, INF, 1, 0 } };

    // Function call
    floydWarshall(graph);
    return 0;
}
