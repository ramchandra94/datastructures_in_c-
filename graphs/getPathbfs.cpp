#include <iostream>
#include<vector>
using namespace std;

bool printDFSPathHelper(bool **edgeMatrix, 
                        int numVertices, 
                        int startNode, 
                        int endNode, 
                        bool *visited, 
                        vector<int> &path)
{
    if(startNode == endNode){
        path.push_back(endNode);
        return true;
    }
    visited[startNode] = true;
    for(int i=0; i < numVertices; i++){
        if(edgeMatrix[startNode][i] && !visited[i]){
            if(printDFSPathHelper(edgeMatrix, numVertices, i, endNode, visited, path)){
                path.push_back(startNode);
                return true;
            }
        }
    }
    return false;
}

void printDFSPath(bool **edgeMatrix, int numVertices, int startNode, int endNode){
    bool *visited = new bool[numVertices];
    vector<int> path;
    printDFSPathHelper(edgeMatrix, numVertices, startNode, endNode, visited, path);
    
    for(int i=0; i < path.size(); i++){
        cout << path[i] << " ";
    }
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
    
    int sv, ev;
    cin >> sv >> ev;
    printDFSPath(edgeMatrix, numVertices, sv, ev);
    
    for(int i=0; i < numVertices; i++){
        delete[] edgeMatrix[i];
    }
    
    delete[] edgeMatrix;
    return 0;
}