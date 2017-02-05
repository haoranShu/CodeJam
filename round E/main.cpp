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
#include <set>
#include <vector>
#include <algorithm>

typedef long long ll;

int calculateK(std::vector<int> A){
    int K;
    int l = (int)A.size();
    
    //1 in first
    std::set<int> needing;
    needing.insert(1);
    int pointer = 0;
    int max = 1;
    while (!needing.empty()){
        if (A[pointer] > max){
            for (int k = max+1; k < A[pointer]; k++){
                needing.insert(k);
            }
            max = A[pointer];
        }
        else {
            needing.erase(A[pointer]);
        }
        pointer++;
    }
    std::cout << pointer << " " << max << std::endl;
    
    //N in last
    std::set<int> needing2;
    needing2.insert(l);
    int pointer2 = l-1;
    int min = l;
    while (!needing.empty()){
        if (A[pointer2] < min){
            for (int k = min-1; k > A[pointer2]; k--){
                needing.insert(k);
            }
            min = A[pointer2];
        }
        else {
            needing.erase(A[pointer2]);
        }
        pointer2--;
    }
    std::cout << pointer2 << " " << min << std::endl;
    
    if (pointer > pointer2){
        
    }
    else if (pointer == pointer2) {
        K = 3;
    }
    else {
        std::vector<int> B;
        for (int k = pointer2; k >= pointer; k--){
            B.push_back(A[k]);
        }
        K = calculateK(B)+2;
    }
    
    if (s == 1){
        
    }
    
    return K;
}



int main() {
    std::ifstream fin("testB.txt");
    
    ll numCases;
    
    fin >> numCases;
    
    for (ll k = 1; k <= numCases; k++){
        int N, P;
        fin >> N;
        fin >> P;
        std::vector<int> A;
        
        for (int i = 0; i < N; i++){
            int tmp;
            fin >> tmp;
            A.push_back(tmp);
        }
        
        int K;
        K = calculateK(A);
        std::cout << "Case #" << k << ": " << K << std::endl;
    }
    return 0;
}