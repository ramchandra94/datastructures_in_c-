#include <iostream>
using namespace std;

void countIslandsHelper(bool **edges, int numVertices, int startNode,bool *visited){
    visited[startNode] = true;
    for(int i=0; i < numVertices; i++){
        if(edges[startNode][i] && !visited[i]){
            countIslandsHelper(edges, numVertices, i, visited);
        }
    }
}

int countIslands(bool **edges, int numVertices){
    bool *visited = new bool[numVertices];
    int count = 0;
    for(int i=0; i < numVertices; i++){
        if(!visited[i]){
            count++;
            countIslandsHelper(edges, numVertices, i, visited);
        }
    }
    return count;
}
int main() {
    // Write your code here
    int n;
    int e;
    
    cin >> n >> e;
    
    
    bool **edges = new bool*[n];
    for(int i=0; i < n; i++){
        edges[i] = new bool[n];
        for(int j=0; j < n; j++){
            edges[i][j] = false;
        }
    }
    
    for(int i=0; i < e; i++){
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = true;
        edges[ev][sv] = true;
    }
    cout << countIslands(edges, n) << endl;
}