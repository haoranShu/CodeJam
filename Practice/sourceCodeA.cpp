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

int maxBa(int R, int L){
    int minP;
    minP = std::min(R, L);
    return (minP+1)*minP/2;
}

int main() {
    //read the input
    std::ifstream fin("A-small-attempt0.in");
    int numCase;
    fin >> numCase;
    
    int result;
    for (int i = 1; i <= numCase; i++){
        int L, R;
        fin >> L;
        fin >> R;
        result = maxBa(R, L);
        std::cout << "Case #" << i << ": " << result << std::endl;
    }
    
    return 0;
}
