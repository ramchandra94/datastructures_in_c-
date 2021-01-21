#include <iostream>
#include<climits>
using namespace std;

int findMinVertex(int *weights, bool *visited, int n){
    int minVertex = -1;
    for(int i=0; i < n; i++){
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])){
         	minVertex = i;   
        }
    }
    return minVertex;
}

void primPrint(int ** edges, int n){
    bool *visited = new bool[n];
    int *parents = new int[n];
    int *weights = new int[n];
    for(int i=0; i < n; i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    parents[0] = -1;
    weights[0] = 0;
    
    for(int i=0; i < n; i++){
        int minVertex = findMinVertex(weights, visited, n);
        visited[minVertex] = true;
        for(int j=0; j < n; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j] < weights[j]){
                    weights[j] = edges[minVertex][j];
                    parents[j] = minVertex;
                }
            }
        }
    }
    for(int i=1; i < n; i++){
        if(parents[i] < i){
            cout << parents[i] << " " << i << " " << weights[i] << endl;
        }else{
            cout << i << " " << parents[i] << " " << weights[i] << endl;
        }
    }
}

int main() {
    // Write your code here
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    
    int ** edgeMatrix = new int*[numVertices];
    for(int i=0; i < numVertices;i++){
        edgeMatrix[i] = new int[numVertices];
        for(int j=0; j < numVertices;j++){
            edgeMatrix[i][j] = 0;
        }
    }
    
    
    
    for(int i=0; i < numEdges; i++){
        int sv, ev, weight;
        cin >> sv >> ev >> weight;
        edgeMatrix[sv][ev] = weight;
        edgeMatrix[ev][sv] = weight;
    }
    
    primPrint(edgeMatrix, numVertices);
    for(int i=0; i < numVertices; i++){
        delete[] edgeMatrix[i];
    }
    delete[] edgeMatrix;
    
    return 0;
}