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

bool isPermutation(std::string str1, std::string str2){
    std::string str1c = str1;
    std::string str2c = str2;
    std::sort(str1c.begin(), str1c.begin());
    std::sort(str2c.begin(), str2c.begin());
    //std::cout << str1c << " " << str2c << std::endl;
    if (str1c.compare(str2c) == 0){
        return true;
    }
    else{
        //std::cout << "not" << std::endl;
        return false;
    }
}

ll forOneSentence(std::vector<std::string> strings, std::string sentence){
    ll num = 0;
    int l = (int)strings.size();
    int sentencel = (int)sentence.length();
    for (int i = 0; i < l; i++){
        std::cout << i << std::endl;
        int ll = (int)strings[i].length();
        if (ll == sentencel){
            std::string first = sentence.substr(0,ll);
            std::cout << first << " " << strings[i] << std::endl;
            if (isPermutation(first, strings[i])){
                num = 1;
                return num;
            }
        }
        else if (ll < sentencel){
            std::string first = sentence.substr(0,ll);
            std::cout << first << " " << strings[i] << std::endl;
            if (isPermutation(first, strings[i])){
                std::string subsentence = sentence.substr(ll,sentencel-ll);
                num += forOneSentence(strings, subsentence);
                }
            }
        }
    num = num%N;
    //std::cout << num << std::endl;
    return num;
}

int main(){
    //read in the input
    std::ifstream fin("TestC.txt");

    ll numCases;
    ll V, S;
    
    fin >> numCases;
    
    for (ll k = 1; k <= numCases; k++){
        std::vector<std::string> strings;
        fin >> V;
        fin >> S;
        std::string tmp;
        std::getline(fin, tmp);
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
