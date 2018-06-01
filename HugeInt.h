#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

class HugeInt{

    friend ostream & operator<<(ostream&,HugeInt&); //declare outside the class since ostream do not belongs to the HugeInt class 
    friend istream & operator>>(istream&,HugeInt&); //same above

    public:
        HugeInt(int a = 87);
        HugeInt(string);
        ~HugeInt();
        void setInt(int);

        bool bigone(const HugeInt&,const HugeInt&); // for - operator and check which one is big
        HugeInt  operator+(const HugeInt& );        // return by value <- can be l Rvalue and lvalue(not ensure all the case)
        HugeInt  operator-(const HugeInt& );        //same above
        HugeInt &operator=(const HugeInt&);

    private:

        vector<int> number;
};



