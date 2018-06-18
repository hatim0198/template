// Example program
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template<typename T>
class Less_than {
    const T val;
    // value to compare against
public:
    Less_than(const T& v) :val(v) { }
    bool operator()(const T& x) const { return x<val; } // call operator
};


template<typename T>
class In_between {
    const T val_min;
    const T val_max;
    // value to compare against
public:
    In_between(const T& min, const T& max) :val_min(min), val_max(max) { }
    bool operator()(const T& x) const { return val_min < x && x < val_max; } // call operator
};


template<typename C, typename P>
int count(const C& c, P less_than)
{
    int cnt = 0;
    for (const auto& x : c)
        if (less_than(x))
            ++cnt;
    return cnt;
}


void f(const vector<int>& vec, const list<string>& lst, int _x, const string& s)
{
    cout << "number of values less than " << _x
         << ": " << count(vec,[&_x](int a){ return a < _x; }) << '\n';

    cout << "number of values less than " << s
         << ": " << count(lst,Less_than<string>{s}) << '\n';
    cout << "\n\n";
}

void f2(const vector<int>& vec, const list<string>& lst, int _x, int _y, const string& s)
{
    cout << "number of values less than " << _x
         << ": " << count(vec,[&_x](int a){ return a < _x; }) << '\n';

    cout << "number of values less than " << s
         << ": " << count(lst,Less_than<string>{s}) << '\n';

    cout << "\n\n";
    
    cout << "number of values in between " << _x << " and " << _y
         << ": " << count(vec, In_between<int>{_x, _y} ) << '\n';

    cout << "number of values in between " << _x << " and " << _y
         << ": " << count(vec, [&_x, &_y](int a){ return _x < a && a < _y;}) << '\n';
    
}



int main()
{
    vector<int> vec{10, 20, 30};
    list<string> lst{"aaaa", "cccc", "eeee"};
    
    f(vec, lst, 12, "asdf");
    f2(vec, lst, 12, 22, "asdf");
}
