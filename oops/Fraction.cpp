class Fraction{
    private:
    int numerator;
    int denominator;

    public:

    // if we create our own constructor, then compiler will not create a default
    // constructor
    Fraction(int numerator, int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    int setNumerator(int n){
        this->numerator = n;
    }

    int setDenominator(int d){
        this->denominator = d;
    }

    // this function will be called on an object itself.
    // this method will be called by obj.print() so no need to pass any arguments.
    void print() const{
        cout << this->numerator << "/" << this->denominator << endl;
    }

    void simplify(){
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for(int i=1; i <= j; i++){
            if(this->numerator % i == 0 && this->denominator % i == 0){
                gcd = i;
            }
        }

        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }
    // say we want to add a fraction to the fraction object.
    // lets create a function add that adds a fraction that's passed as input.
    // and lets update in the current object itself.
    // instad of passing the object copy we can directly pass the reference and a constant reference.
    Fraction add(const Fraction &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = x*numerator + y*f2.numerator;
        Fraction f_new(num, lcm);
        f_new.simplify();
        return f_new;
    }

    // if we do f1 + f2, f1 is passed in this and f2 
    // is passed as an argument.
    Fraction operator+(const Fraction &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = x*numerator + y*f2.numerator;
        
        Fraction f_new = Fraction(num, lcm);
        f_new.simplify();
        return f_new;
    }

    void multiply(const Fraction &f2){
        this->numerator = this->numerator*f2.numerator;
        this->denominator = this->denominator*f2.denominator;
        simplify();
    }

    Fraction operator*(const Fraction f2){
        int n = numerator*f2.numerator;
        int d = denominator*f2.denominator;

        Fraction f_new(n, d);
        f_new.simplify();
        return f_new;
    }

    bool operator==(const Fraction f2){
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    // preincrement operator
    // if we dont use this reference then we wont be able to 
    // perform chained pre-increment operators.
    Fraction& operator++(){
        numerator = numerator + denominator;
        simplify();
        return *this ;
    }

    // Post Increment
    Fraction operator++(int){
        Fraction f_new(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        f_new.simplify();
        return f_new;
    }

    //
    Fraction& operator+=(const Fraction &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = x*numerator + y*f2.numerator;
        numerator = num;
        denominator = lcm;
        simplify();
        return *this;
    }
};