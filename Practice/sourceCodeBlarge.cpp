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
    i = i%K;
    
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

int main() {
    //read the input
    std::ifstream fin("B-large-practice.in");
    int numCase;
    fin >> numCase;
    
    const long long l = pow(10,9)+7;
    
    for (int n = 1; n <= numCase; n++){
        long long A, B, N, K;
        fin >> A;
        fin >> B;
        fin >> N;
        fin >> K;
        
        long long result = 0;
        long long Same = 0;
        long long SameTail = 0;
        
        long long loop, tail;
        loop = N/K;
        tail = N%K;
        
        long long iter = std::min(N, K);
        typedef long long ll;
        std::vector<ll> statA, statB, statAtail, statBtail;
        
        for (long long i = 1; i <= K; i++){
            statA.push_back(0);
            statB.push_back(0);
            statAtail.push_back(0);
            statBtail.push_back(0);
        }
        
        for (long long i = 1; i <= iter; i++){
            long long ri = getModulo(i, K, A);
            long long rj = getModulo(i, K, B);
            if ((ri + rj)%K == 0){
                Same++;
            }
            statA[ri]++;
            statB[rj]++;
            if (i <= tail){
                statAtail[ri]++;
                statBtail[rj]++;
            }
            if (i == tail){
                SameTail = Same;
            }
        }
 
        //std::cout << "StatA is ";
        //for (int i = 0; i < K; i++){
        //    std::cout << statA[i];
        //}
        //std::cout << std::endl;
        
        //std::cout << "StatB is ";
        //for (int i = 0; i < K; i++){
        //    std::cout << statB[i];
        //}
        //std::cout << std::endl;
        
        loop = loop%l;i
        long long loop2 = getModulo(loop, l, 2);
        result += (statA[0]*statB[0]*loop2)%l;
        result += (statAtail[0]*statB[0]*loop)%l;
        result += (statA[0]*statBtail[0]*loop)%l;
        result += (statAtail[0]*statBtail[0])%l;
        result = result%l;
        for (int i = 1; i < K; i++){
            result += (statA[i]*statB[K-i]*loop2)%l;
            result += (statA[i]*statBtail[K-i]*loop)%l;
            result += (statAtail[i]*statB[K-i]*loop)%l;
            result += (statAtail[i]*statBtail[K-i])%l;
            result = result%l;
        }
        //std::cout << result << std::endl;
        //std::cout << loop << " " << tail << " " << Same << " " << SameTail << std::endl;
        result = ((result - Same*loop - SameTail)%l + l)%l;
        
        std::cout << "Case #" << n << ": " << result << std::endl;
    }
    
    return 0;
}
