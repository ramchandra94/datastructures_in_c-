#include <iostream>
#include<climits>
using namespace std;

int findMinVertex(int *distances, bool* visited, int n){
    int minVertex = -1;
    for(int i=0; i < n; i++){
        if(!visited[i] && (minVertex == -1 || distances[i] < distances[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void dijktras(int **edges, int n){
    bool *visited = new bool[n];
    int *distances = new int[n];
    
    for(int i=0; i < n; i++){
        visited[i] = false;
        distances[i] = INT_MAX;
    }
    distances[0] = 0;
    for(int i=1; i < n; i++){
        int minVertex = findMinVertex(distances, visited, n);
        visited[minVertex] = true;
        for(int j=0; j < n; j++){
            if(edges[minVertex][j] != 0 && !visited[j])
            {
                int c_dist = edges[minVertex][j] + distances[minVertex];
                if(c_dist < distances[j]){
                    distances[j] = c_dist;
                }
            }
        }
    }
    
    for(int i=0; i < n; i++){
        cout << i << " " << distances[i] << endl;
    }
}

int main() {
    // Write your code here
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    
    int **edgeMatrix = new int*[numVertices];
    for(int i=0; i < numVertices; i++){
        edgeMatrix[i] = new int[numVertices];
        for(int j=0; j < numVertices; j++){
            edgeMatrix[i][j] = 0;
        }
    }
    
    for(int i=0; i < numEdges; i++){
        int sv, ev, weight;
        cin >> sv >> ev >> weight;
        edgeMatrix[sv][ev] = weight;
        edgeMatrix[ev][sv] = weight;
    }
    
    dijktras(edgeMatrix, numVertices);
    
    for(int i=0; i < numVertices; i++){
        delete[] edgeMatrix[i];
    }
    
    delete[] edgeMatrix;
    return 0;
}