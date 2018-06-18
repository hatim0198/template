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


template<typename T>
class More_than 
{
    public:
        More_than(const T& v) :val(v) { }
        bool operator()(const T& x) const { return x > val; } // call operator
        
    private:
        const T val;
        // value to compare against
};


//bool theF(int x, Less_than<int> lt_24)
template<typename T>
bool isMinor(int alter, T minor, bool debug_mode = false)
{
    if(debug_mode)
    {
        std::cout << "minor(17) : " << minor(17) << "\n";
        std::cout << "minor(19) : " << minor(19) << "\n";
    }

    bool ret = true;
    if(minor(alter) == true)
    {
        ret = true;
    }
    else
    {
        ret = false;
    }
    return ret;
}

int main()
{
    std::cout << std::boolalpha;


    //std::cout << "isMinor(17) : " << isMinor(6, [&](int x){ return x < 18;})<< "\n";
    
    Less_than<int> lt_10(10);      //functor ctor
    Less_than<int> lt_50{50};      //functor ctor

    std::cout << "lt_10(24) : " << lt_10(24) << "\n"; // functor operator() call
    std::cout << "lt_10.operator()(24) : " << lt_10.operator()(24) << "\n"; // functor operator() call
    std::cout << "lt_50(24) : " << lt_50(24) << "\n";
    std::cout << "lt_50(24) : " << lt_50(24) << "\n";
    std::cout << std::endl;


    Less_than<char> lt_a('a');
    Less_than<char> lt_c('c');

    std::cout << "lt_a('b') : " << lt_a('b') << "\n";
    std::cout << "lt_c('b') : " << lt_c('b') << "\n";

    return 0;
}
