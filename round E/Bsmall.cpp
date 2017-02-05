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

bool appropriate(ll N, ll d){
    while (N%d == 1){
        N = N/d;
    }
    if (N == 0)
        return true;
    return false;
}

int main() {
    std::ifstream fin("testB.txt");
    
    ll numCases;
    
    fin >> numCases;
    
    for (ll k = 1; k <= numCases; k++){
        ll N;
        fin >> N;
        
        ll base;
        for (ll d = 1; d <= N; d++){
            if (appropriate(N, d)){
                base = d;
                break;
            }
        }
        std::cout << "Case #" << k << ": " << base << std::endl;
    }
    return 0;
}
