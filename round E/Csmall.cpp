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

long num2Divide(int y, int N){
    int rest = N%y;
    int m = N/y;
    if (m < rest){
        return 0;
    }
    return (m-rest)/(y+1)+1;
}

long numDivide(int x, int N){
    long num = 0;
    if (x > N){
        return 0;
    }
    if (x == N){
        return 1;
    }
    int n = N/x;
    for(int k = 1; k <= n; k++){
        num += num2Divide(x+1, N-k*x);
    }
    return num;
}

int main() {
    std::ifstream fin("C-small-attempt0.in");
    
    int numCases;
    
    fin >> numCases;
    
    for (int k = 1; k <= numCases; k++){
        int D, N;
        fin >> N;
        fin >> D;
        long num = 0;
        for (int bound = D; bound <= N; bound += D){
            num += numDivide(bound, N);
        }
        std::cout << "Case #" << k << ": " << num << std::endl;
    }
    return 0;
}