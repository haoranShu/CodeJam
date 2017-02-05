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


long long getModulo(long long i, long long K, long long A){
    if (K == 1){
        return 0;
    }
    
    long long result = 1;
    
    while (A != 0){
        if (A%2 == 1)
            result = (result*i)%K;
        A = A/2;
        i = (i*i)%K;
    }

    return result;
}

bool isPair (long long i, long long j, long long K, long long A, long long B){
    if (i == j){
        return false;
    }
    long long iresult = getModulo(i, K, A);
    long long jresult = getModulo(j, K, B);
    if ((iresult+jresult)%K == 0){
        return true;
    }
    else
        return false;
}

int main() {
    //read the input
    std::ifstream fin("B-small-attempt7.in");
    int numCase;
    fin >> numCase;
    
    const long long l = pow(10,9)+7;
    
    //std::cout << getModulo(3, 9, 4) << std::endl;
    
    
    for (int n = 1; n <= numCase; n++){
        long long A, B, N, K;
        fin >> A;
        fin >> B;
        fin >> N;
        fin >> K;
        
        long long result = 0;
        
        for (long long i = 1; i <= N; i++){
            for (long long j = 1; j <= N; j++){
                if (isPair(i, j, K, A, B)){
                    //std::cout <<i << " " << j<< std::endl;
                    result ++;
                    result = result % l;
                }
            }
        }
        
        result = result % l;
        std::cout << "Case #" << n << ": " << result << std::endl;
    }
    
    return 0;
}