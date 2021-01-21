/**********
 
Following is the main function we are using internally.
Refer this for completing the ComplexNumbers class.
 
 
int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}
 
 ************/


class ComplexNumbers {
    // Complete this class
    private:
    int real;
    int imaginary;
    public:
    ComplexNumbers(const int real, const int imaginary){
        this -> real = real;
        this -> imaginary = imaginary;
    }
    
    void plus(ComplexNumbers const &num){
        this -> real = this -> real + num.real;
        this -> imaginary = this -> imaginary + num.imaginary;
    }
    
    void multiply(ComplexNumbers const & num){
        int newReal = (this -> real * num.real) - (this -> imaginary * num.imaginary);
        int newImaginary = (this -> real * num.imaginary) + (this->imaginary * num.real);
        this -> real = newReal;
        this -> imaginary = newImaginary;
    }
    
    void print(){
        std::cout << real;
        if(imaginary < 0){
            std::cout << " - i" << imaginary*-1 << std::endl;
        }else{
            std::cout << " + i" << imaginary << std::endl;
        }
    }
};