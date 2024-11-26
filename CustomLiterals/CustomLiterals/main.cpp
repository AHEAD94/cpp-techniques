//
//  main.cpp
//  CustomLiterals
//
//  Created by Ryu Dae-ha on 11/26/24.
//

#include <iostream>

using namespace std;

const long double km_per_mile = 1.609344L;

long double operator"" _km(long double val) {
    return val;
}

long double operator"" _mi(long double val) {
    return val * km_per_mile; // convert mile to km
}

int main(void) {
    long double dist_1 = 1.0_km;
    long double dist_2 = 1.0_mi;
    
    cout << "Sum of dist: " << dist_1 + dist_2 << " km" << endl;
    
    return 0;
}
