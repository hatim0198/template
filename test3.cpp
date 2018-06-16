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
    std::cout << std::boolalpha;

    Less_than<int> lt_10(10);      //ctor
    Less_than<int> lt_50{50};     //ctor

    std::cout << "lt_10(24) : " << lt_10(24) << "\n";
    std::cout << "lt_50(24) : " << lt_50(24) << "\n";
    std::cout << std::endl;


    Less_than<char> lt_a('a');
    Less_than<char> lt_c('c');

    std::cout << "lt_a('b') : " << lt_a('b') << "\n";
    std::cout << "lt_c('b') : " << lt_c('b') << "\n";

    return 0;
}
