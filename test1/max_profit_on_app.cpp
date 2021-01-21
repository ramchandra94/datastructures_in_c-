void mergeSort(int input[], int low, int high){
    if(low >= high){
        return;
    }
    
    int mid = low + (high-low)/2;
    mergeSort(input, low, mid);
    mergeSort(input, mid+1, high);
    int i = low;
    int j = mid+1;
    int k =0;
    int len = high-low+1;
    int temp[len];
    while(i <= mid && j <= high){
        if(input[i] <= input[j]){
            temp[k] = input[i];
            i++;
        }
        else{
            temp[k] = input[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        temp[k] = input[i];
        i++;
        k++;
    }
    while(j <= high){
        temp[k] = input[j];
        j++;
        k++;
    }
    
    for(int t=0; t < len; t++){
        input[low+t] = temp[t];
    }
}

int maximumProfit(int budget[], int n) {
    // Write your code here
	mergeSort(budget, 0, n-1);
    
    int max = budget[0]*n;
    
    for(int i=1; i < n; i++){
        int new_max = budget[i]*(n-i);
        if(new_max > max){
            max = new_max;
        }
    }
    return max;
}
