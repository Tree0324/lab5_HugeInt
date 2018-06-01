#include "HugeInt.h"

using namespace std;


HugeInt::HugeInt(int a ){
    number.resize(100);
    setInt(a);

}
HugeInt::HugeInt(string str){                           //convert to str and write into my vector
    number.resize(100);
    for (int i=0;i<number.size();i++){
        if (str.size() != 0){                           //assign for the number
            number[i] = ( str.back() - '0');
            str.pop_back();
        }
    }
}

void HugeInt::setInt(int aa){                            // conver to int and write into vector
    int i = 0; 
    while(aa){
        number[i] = aa%10;
        aa/=10;
        i++;
    }
    

    if (aa<0){
        cout << "only postive int is valid !! ";
        exit(0);
    }
}


HugeInt::~HugeInt(){
}

bool HugeInt::bigone(const HugeInt& a1,const HugeInt& a2){  //Apply to minus case which one is bigger
    int i = number.size()-1;
    while (i>=0){
        if ( a1.number[i] !=0  ||  a2.number[i] != 0 ){
            if (a1.number[i] > a2.number[i])
                return true;
            else
                return false;
        }
        i--;
    }
}

HugeInt HugeInt::operator+(const HugeInt& a1){              //logic design
    int carry = 0;
    HugeInt res = *this;
    for (int i=0;i<number.size();i++){
        if ( (a1.number[i] + res.number[i])  >= 10 ){
            res.number[i] = (a1.number[i] + res.number[i])%10+carry;
            carry = 1;
        }
        else{
            res.number[i] = (a1.number[i] + res.number[i]) + carry;
            carry = 0;
        }
    }
    if ( ( a1.number[99] + res.number[99] )  > 10 )
        cout << "the number is too big!! out of range.\n";
    return res;     
}

HugeInt HugeInt::operator-(const HugeInt& a1){
    int carry = 0;
    HugeInt res = *this;
    if (bigone(res,a1)){                                                    //discuss 2 cases
        for (int i=0;i<number.size();i++){
            if ( (res.number[i] - carry - a1.number[i])  < 0  ){
                res.number[i] = (res.number[i] - carry + 10 - a1.number[i]);
                carry = 1;
            }
            else{
                res.number[i]=(res.number[i] - carry - a1.number[i]) ;
                carry = 0;
            }
        }
        return res;
    }
    else{
         for (int i=0;i<number.size();i++){
            if ( (a1.number[i] - carry - res.number[i])  < 0  ){
                res.number[i] = (a1.number[i] - carry + 10 - res.number[i]);
                carry = 1;
            }
            else{
                res.number[i] = (a1.number[i] - carry - res.number[i]) ;
                carry = 0;
            }
         }
         cout << "  (it's a minus term.)"<<" -";
         return res;
    }
}

HugeInt& HugeInt::operator=(const HugeInt& right){
    if (&right != this){                                                    //if the same and don't need to do
        for (int i=0;i<number.size();i++){
        this -> number[i] = right.number[i];  
        }
    }
    return *this;
}

istream& operator>>(istream& in ,HugeInt& a ){
    string input_buffer;
    in >> input_buffer;
    a = HugeInt(input_buffer);
    return in;
}

ostream& operator << (ostream& out ,HugeInt& a){
    int i = 0;
    for ( i=a.number.size()-1;i>=1;i--)                             //note:only end at idx=1 since 0 still need to print while all the literal is zero
        if (a.number[i] != 0 )
            break;
    for (int k=i;k>=0;k--)                                          //print the literal step by step
        out <<  a.number[k];
    return out;
}
