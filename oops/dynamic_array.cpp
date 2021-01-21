class DynamicArray {
    int *data;
    int nextIndex;
    int capacity;

    public:
    DynamicArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    DynamicArray(const DynamicArray &d){

        // Internal shallow copy will do this
        /*
        this->data = d.data;
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity
        */

        this->data = new int[d.capacity];
        for(int i=0; i < d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void operator=(const DynamicArray &d){
        this->data = new int[d.capacity];
        for(int i=0; i < d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void add(int element){
        if(nextIndex == capacity){
            int *newData = new int[2*capacity];
            for(int i=0; i < capacity; i++){
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int get(int i){
        if(i >= nextIndex){
            return -1;
        }
        return data[i];
    }

    void add(int i, int element){
        if(i < nextIndex){
            data[i] = element;
        }else if(i == nextIndex){
            add(element);
        }else{
            return;
        }
    }

    void print(){
        for(int i=0; i < nextIndex; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};