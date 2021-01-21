bool checksequenece(char large[] , char*small) {
	if(small[0] == '\0'){
        return true;
    }else{
        if(large[0] == '\0'){
            return false;
        }
    }
    
    int i = 0;
    while(large[i] != '\0' && large[i] != small[0]){
        i++;
    }
    if(large[i] == '\0'){
        return false;
    }
    
    bool smallOutput = checksequenece(large+i+1, small+1);
    return smallOutput;
}
