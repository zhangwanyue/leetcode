//
// Created by vera on 19-9-20.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout.setf(ios::fixed);
    double d = 0.123456789;
    cout<<setprecision(6)<<d;
}