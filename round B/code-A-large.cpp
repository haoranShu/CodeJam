//
//  main.cpp
//  CodeJam
//
//  Created by 舒 浩然 on 16/8/28.
//  Copyright © 2016年 舒 浩然. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>

typedef long long ll;

int main(){
    //read in the input
    std::ifstream fin("A-small-attempt0.in");
    
    ll numCases;
    ll M, N;
    //ll Mold, Nold;
    
    fin >> numCases;
    //std::vector<std::vector<double>> table;
    
    for (ll k = 1; k <= numCases; k++){
        fin >> N;
        fin >> M;
        std::vector<std::vector<double>> table;
        std::vector<double> tmp;
        tmp.push_back(0);
        table.push_back(tmp);
        for (ll i = 1; i <= N; i++){
            std::vector<double> tmp;
            tmp.push_back(1.0);
            table.push_back(tmp);
        }
        for (ll j = 1; j <= M; j++){
            if (j <= N){
                table[j].push_back(0);
            }
            for (ll i = j+1; i <= N; i++){
                table[i].push_back((table[i][j-1]*j+table[i-1][j]*i)/(double)(i+j));
            }
        }
        std::cout << "Case #" << k << ": " << table[N][M] << std::endl;
    }
    
    return 0;
}
