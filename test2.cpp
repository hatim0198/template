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
template <size_t n> struct fib {
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


int main()
{
    
  // PrintStuff call with variant of paramtypes and or params ...
  wrapper(1,2,3, 4,5);
  
  wrapper('a', 'b', 'c');
  
  const double PI_LIKE = 3141516171819e-12;
  wrapper("asd", 1, 2, PI_LIKE);

  /*
  // PrintStuff call with variant of paramtypes and or params ...
  printStuff(1,2,3);
  //printStuff(12, 4, 17.80001, "text message...");
  */

  /*
  // Example of Template Recursion Output:
  std::cout << "fib<5>::value: " << fib<5>::value << "\n"
            << "fib<4>::value: " << fib<4>::value << "\n"
            << "fib<3>::value: " << fib<3>::value << "\n"
            << "fib<2>::value: " << fib<2>::value << "\n"
            << "fib<1>::value: " << fib<1>::value << "\n";
  */
  
  /*
  //system generated...
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";
  */
    
}
