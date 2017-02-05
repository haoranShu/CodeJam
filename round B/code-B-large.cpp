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
const ll N = 1e9 + 7;
/*
ll forOneSentence(std::vector<std::string> strings, std::string sentence){
    ll num = 0;
    int length = (int)sentence.length();
    for (i = 0; i < length; i++){
        for (auto& s:strings){
            if (charInString(sentence[]))
        }
    }
    num = num%N;
    return num;
}

int main(){
    //read in the input
    std::ifstream fin("A-large.in");

    ll numCases;
    ll V, S;
    
    fin >> numCases;
    
    for (ll k = 1; k <= numCases; k++){
        std::vector<std::string> strings;
        fin >> V;
        fin >> S;
        for (int i = 0; i < V; i++){
            std::string tmp;
            std::getline(fin, tmp);
            strings.push_back(tmp);
        }
        std::cout << "Case #" << k << ": ";
        for (int j = 1; j <= S; j++){
            std::string sentence;
            std::getline(fin, sentence);
            std::cout << forOneSentence(strings, sentence) << " ";
        }
        std::cout << std::endl;
    }
 
    return 0;
}
 */

int main(){
    //read in the input
    std::ifstream fin("B-small-attempt3.in");
    
    ll numCases;
    ll R, C;

    fin >> numCases;
    for (ll k = 1; k <= numCases; k++){
        fin >> R;
        fin >> C;
        
        if (R < C){
            ll tmp = R;
            R = C;
            C = tmp;
        }
        
        ll row1 = 2*(R/3) + R%3;
        ll row2 = 2*((R+1)/3) + (R+1)%3 - 1;
        ll row3 = 2*((R+2)/3) + (R+2)%3 - 2;
        ll col1 = C/3;
        ll col2 = C%3;
        ll total;
        if (C == 2){
            total = 2*row1;
        }
        else{
            total = col1 * (row1 + row2 + row3);
            if (col2 >= 1){
                total += row1;
                if (col2 >= 2){
                    total += row2;
                }
            }
        }
        
        std::cout << "Case #" << k << ": " << total << std::endl;
    }
    return 0;
}
