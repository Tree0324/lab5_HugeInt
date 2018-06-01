#include "HugeInt.h"

using namespace std;

int main(){
    cout << "enter a postive number x u want to do a HugeInt calculate for x+y and z-x \n where y=28825252 z=31415926535897932846 \n "; 
    HugeInt x;
    HugeInt y(28825252);
    HugeInt z("314159265358979323846");
    HugeInt result;

    cin >> x;
    result = x + y;
    cout << x << " + " << y << " = " << result<< endl;

    result = z - x;
    cout << result;

    return 0; 
}