// https://www.digitalocean.com/community/tutorials/prototype-design-pattern-in-java
// In short - Prototype Design Pattern = expose clone method on object in case of expensive creation

#include <iostream>

using namespace std;

class Test {
    public:
        Test(int i): d_i(i) {};
        Test *clone() {
            return new Test(*this);
        }
        int d_i;
        
    private:
        void operator=(Test other);
        Test(const Test& other) = default;
};

int main()
{
    Test t(1);
    
    // Test t2 = t; // Compile error! Private operator= means we can't accidentally pass by value
    Test *t2 = t.clone();
    
    t2->d_i = 5;
    
    std::cout << "t: " << t.d_i << " t2: " << t2->d_i <<std::endl;
    
    return 0;
}
