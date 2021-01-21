bool splitHelper(int input[], int l_sum, int r_sum, int size){
    if(size==0){
        return l_sum == r_sum;
    }
    
    if(input[0] % 5 == 0){
        l_sum += input[0];
    } 
    else if(input[0] % 3 == 0){
        r_sum += input[0];
    } 
    else{
        return splitHelper(input + 1, l_sum + input[0], r_sum, size-1) || splitHelper(input + 1, l_sum, r_sum + input[0], size-1);
    }
    
    return splitHelper(input + 1, l_sum, r_sum, size-1);
}
    
bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    splitHelper(input, 0, 0, size);
    
}
