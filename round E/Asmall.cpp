//
//  main.cpp
//  roundE
//
//  Created by 舒 浩然 on 16/11/6.
//  Copyright © 2016年 舒 浩然. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

typedef long long ll;

int whichInPattern(ll I, int length){
    int rest = I%length;
    if (rest == 0){
        rest = length;
    }
    return rest;
}

int main() {
    std::ifstream fin("A-small-attempt0.in");
    
    ll numCases;
    
    fin >> numCases;
    
    for (ll k = 1; k <= numCases; k++){
        ll I, J;
        int length;
        std::string pattern;
        std::getline(fin, pattern);
        std::getline(fin, pattern);
        fin >> I;
        fin >> J;
        length = (int)pattern.length();
        //std::cout << length << std::endl;
        
        int blueInEach = 0;
        for (int i = 0; i < length; i++){
            if (pattern[i] == 'B'){
                blueInEach++;
            }
        }
        //std::cout << blueInEach << std::endl;
        
        int iLoc, jLoc;
        iLoc = whichInPattern(I, length);
        jLoc = whichInPattern(J, length);
        //std::cout << iLoc << " " << jLoc << std::endl;
        
        int Iright = 0, Jleft = 0;
        for (int i = 0; i < length; i++){
            if (pattern[i] == 'B'){
                if (i+1 <= jLoc){
                    Jleft++;
                }
                if (i+1 >= iLoc){
                    Iright++;
                }
            }
        }
        //std::cout << Iright << " " << Jleft << std::endl;
        ll num;
        
        if (I/length == J/length){
            num = Iright+Jleft-blueInEach;
        }
        else {
            ll Inew, Jnew;
            Inew = I+(length-iLoc+1);
            Jnew = J-jLoc;
            ll count = Jnew - Inew + 1;
            count = count/length;
            num = count*blueInEach;
            num += Iright;
            num += Jleft;
        }
        std::cout << "Case #" << k << ": " << num << std::endl;
    }
    return 0;
}
