bool isValid(int i, int j, int n, int m){
    return (i >= 0 && j >= 0 && i < n && j < m);
}

bool isPath(vector<vector<char>> &board, 
            int startX, int startY, 
            int endX, int endY, 
            int n, int m, 
            bool **visited){
    if(startX == endX && startY == endY){
        return true;
    }
    char colour = board[startX][startY];
    bool result = false;
    visited[startX][startY] = true;
    if(isValid(startX, startY+1, n, m) && !visited[startX][startY+1] && board[startX][startY+1] == colour){
        result = result | isPath(board, startX, startY+1, endX, endY, n, m, visited);
    }
    if(isValid(startX+1, startY, n, m) && !visited[startX+1][startY] && board[startX+1][startY] == colour){
        result = result | isPath(board, startX+1, startY, endX, endY, n, m, visited);
    }
    if(isValid(startX, startY-1, n, m) && !visited[startX][startY-1] && board[startX][startY-1] == colour){
        result = result | isPath(board, startX, startY-1, endX, endY, n, m, visited);
    }
    if(isValid(startX-1, startY, n, m) && !visited[startX-1][startY] && board[startX-1][startY] == colour){
        result = result | isPath(board, startX-1, startY, endX, endY, n, m, visited);
    }
    
    visited[startX][startY] = false;
    return result;
}
bool checkCycle(vector<vector<char>> &board, int n, int m, int i, int j, bool **visited){
    char colour = board[i][j];
    bool result = false;
    visited[i][j] = true;
	if(isValid(i, j+1, n, m) && isValid(i+1, j, n, m) && board[i][j+1] == colour && board[i+1][j] == colour){
        result = result | isPath(board, i, j+1, i+1, j, n, m, visited);
    }
    
    if(isValid(i+1, j, n, m) && isValid(i, j-1, n, m) && board[i+1][j] == colour && board[i][j-1] == colour){
        result = result | isPath(board, i+1, j, i, j-1, n, m, visited);
    }
    
    if(isValid(i, j-1, n, m) && isValid(i-1, j, n, m) && board[i][j-1] == colour && board[i-1][j] == colour){
        result = result | isPath(board, i, j-1, i-1, j, n, m, visited);
    }
    
    if(isValid(i-1, j, n, m) && isValid(i, j+1, n, m) && board[i-1][j] == colour && board[i][j+1] == colour){
        result = result | isPath(board, i-1, j, i, j+1, n, m, visited);
    }
    return result;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    bool result = false;
    
    bool **visited = new bool*[n];
    for(int i=0; i < n; i++){
        visited[i] = new bool[m];
        for(int j=0; j < m; j++){
            visited[i][j] = false;
        }
    }
    
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            bool temp = checkCycle(board, n, m, i, j, visited);
            result = result | temp;
            if(result) break;
        }
        if(result) break;
    }
    
    return result;
}