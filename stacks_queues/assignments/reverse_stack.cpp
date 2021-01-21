void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    
    while(input.size() != 0){
        extra.push(input.top());
        input.pop();
    }
    
    input = extra;
}