class ComplexNumbers{
    private:
        int real;
        int img;
    public:
        ComplexNumbers(int real,int img){
            this->real = real;
            this->img = img;
        }    
        void plus(ComplexNumbers const &c2){
            real += c2.real;
            img += c2.img;
        }
        void multiply(ComplexNumbers const &c2){
            real = real*c2.real - img*c2.img;
            img = img*c2.real + real*c2.img;
        }
        void print(){
            cout<<real<<" "<<img<<"i"<<endl;
        }
};