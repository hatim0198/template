#include <iostream>

template<typename T>
class Less_than 
{
    public:
        Less_than(const T& v) :val(v) { }
        bool operator()(const T& x) const { return x < val; } // call operator
        
    private:
        const T val;
        // value to compare against
};

int main()
{
    Less_than<int> lt1(3);      //ctor
    Less_than<int> lt2{33};     //ctor
    std::cout << lt1(24) << "\n";
    std::cout << lt2(24) << "\n";


    Less_than<char> lt_a('a');
    Less_than<char> lt_c('c');

    std::cout << "lt_a('b') : " << lt_a('b') << "\n";
    std::cout << "lt_c('b') : " << lt_c('b') << "\n";

    std::cout << "true : " << true << "\n";
    return 0;
}
