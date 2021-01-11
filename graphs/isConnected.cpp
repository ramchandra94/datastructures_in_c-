#include<iostream>
using namespace std;

void isConnectedHelper(bool **edges, int numVertices, int startNode, bool *visited){
    visited[startNode] = true;
    for(int i=0; i < numVertices; i++){
        if(edges[startNode][i] && !visited[i]){
            isConnectedHelper(edges, numVertices, i, visited);
        }
    }
}

bool isConnected(bool **edges, int numVertices){
    bool *visited = new bool[numVertices];
    isConnectedHelper(edges, numVertices, 0, visited);
    
    for(int i=0; i < numVertices; i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    
    bool **edgeMatrix = new bool*[numVertices];
    for(int i=0; i < numVertices; i++){
    	edgeMatrix[i] = new bool[numVertices];
        for(int j=0; j < numVertices; j++){
            edgeMatrix[i][j] = false;
        }
    }
    
    for(int i=0; i < numEdges; i++){
        int sv, ev;
        cin >> sv >> ev;
        edgeMatrix[sv][ev] = true;
        edgeMatrix[ev][sv] = true;
    }
    
    int sv, ev;
    cin >> sv >> ev;
    

    cout << (isConnected(edgeMatrix, numVertices) ? "true" : "false") << endl;
    
    for(int i=0; i < numVertices; i++){
        delete[] edgeMatrix[i];
    }
    
    delete[] edgeMatrix;
    return 0;
}