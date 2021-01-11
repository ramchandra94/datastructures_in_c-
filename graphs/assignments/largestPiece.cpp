bool isValid(int i, int j, int n){
    return (i >= 0 && i < n && j >= 0 && j < n);
}
int cakeDFS(vector<vector<int>> &cake, int i, int j, int n, bool **visited){
    if(!isValid(i, j, n) || visited[i][j]){
        return 0;
    }
    
    if(cake[i][j] == 0){
        return 0;
    }
    
    int count = 1;
    visited[i][j] = true;
    
    count += cakeDFS(cake, i, j+1, n, visited);
    count += cakeDFS(cake, i+1, j, n, visited);
    count += cakeDFS(cake, i, j-1, n, visited);
    count += cakeDFS(cake, i-1, j, n, visited);
    
    return count;
}
int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    int max = 0;
    bool **visited = new bool*[n];
    for(int i=0; i < n; i++){
        visited[i] = new bool[n];
        for(int j=0; j < n; j++){
            visited[i][j] = false;
        }
    }
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
   			int ans = cakeDFS(cake, i, j, n, visited);
            if(ans > max){
                max = ans;
            }
        }
    }
    return max;
}