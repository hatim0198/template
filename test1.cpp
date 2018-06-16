// Example program
#include <iostream>
#include <string>

/// 1: Begin
// Incomplete Definition
template<size_t n> struct fib;

// Base Cases
template<> struct fib<0> {const static auto value = 1; };
template<> struct fib<1> {const static auto value = 1; };

// Recursive Definition
template<size_t n> struct fib {
    const static auto value = fib<n-1>::value + fib<n-2>::value;
};

// Assertion
static_assert(fib<3>::value == 3, "Fib Math Error...");


/// 2: Begin
// Base case when "rest..." is empty

void printStuff()
{
    //std::cout << std::endl;    
}


//Recursive Definition
template <typename Tfirst, typename... Trest>
void printStuff(Tfirst first, Trest... rest)
{
    std::cout << ", " << first;
    printStuff(rest...);    
}

//Wrapper
template <typename Tfirst, typename... Trest>
void wrapper(Tfirst first, Trest... rest)
{
    std::cout <<  "{ " << first;
    printStuff(rest...);
    std::cout << " }" << std::endl;
}

// Assertion
// how could that go ??

template<typename T>
T fact_f(T value)
{
    if(value == 0)
        return 1;
    return value * fact_f(value -1); 
}

template<int theArg> struct fact_s;
// Base Case
template<> struct fact_s<0> {
    //for static_cast test switch the comments in the following lines:
    const static auto value  = 1;
    //const static auto erg = 221;
};
//recursive Call  
template<int theArg> struct fact_s {
    const static auto value  = theArg * fact_s<theArg - 1>::value;
};

static_assert(fact_s<3>::value == 6, "Error: struct \"fact_s\" is not implemented properly...");

int main()
{
    std::cout << "fact_s<3>::value : " << fact_s<3>::value << std::endl << std::endl;
    std::cout << "fact_f(3)        : " << fact_f(3) << std::endl << std::endl;
    // PrintStuff call with variant of paramtypes and or params ...
    wrapper(1,2,3, 4,5);
    std::cout << std::endl;

    wrapper('a', 'b', 'c');
    std::cout << std::endl;

    const double PI_LIKE = 3141516171819e-12;
    wrapper("asd", 1, 2, PI_LIKE);

    std::cout << "fib<5>::value: " << fib<5>::value << "\n"
              << "fib<4>::value: " << fib<4>::value << "\n"
              << "fib<3>::value: " << fib<3>::value << "\n"
              << "fib<2>::value: " << fib<2>::value << "\n"
              << "fib<1>::value: " << fib<1>::value << "\n";

    /* ***
    //system generated...
    std::string name;
    std::cout << "What is your name? ";
    getline (std::cin, name);
    std::cout << "Hello, " << name << "!\n";
    */
}

