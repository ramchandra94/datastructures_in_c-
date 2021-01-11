#include <iostream>
using namespace std;

int print3Cycle(bool **edges, int numVertices){
    int count = 0;
    for(int i=0; i < numVertices; i++){
        for(int j=0; j < numVertices; j++){
            if(edges[i][j]){
                for(int k=0; k < numVertices; k++){
                    if(edges[j][k]){
                        if(edges[i][k]){
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count/6;
}
int main() {
    // Write your code here
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
    cout << print3Cycle(edgeMatrix, numVertices) << endl;
    return 0;
}