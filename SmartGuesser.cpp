//
//  Pgia
//
//  Created by Jeme Jbareen on 4/28/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#include "SmartGuesser.hpp"
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using std::string,std::to_string,std::vector;
string SmartGuesser::guess() {
    int r = rand() % vec.size();
    _lastGuess = vec[r];
    return _lastGuess;
}

void SmartGuesser::learn(bullpgia::Latest_Guess s) {
    vector<string> _BullsVec;
    string str1=to_string(s._Bulls)+","+to_string(s._Pgia);
    for(int i=0; i!= vec.size();i++) {
        bullpgia::Latest_Guess ans = bullpgia::calculateBullAndPgia(_lastGuess, vec[i]);
        string str=to_string(ans._Bulls)+","+to_string(ans._Pgia);
        if(str1 == str)
            _BullsVec.push_back(vec[i]);
    }
    vec.clear();
    vec=_BullsVec;
    _lastGuess=vec[0];
}
string SmartGuesser::Convert_Guess(int num){
    string str = to_string(num);
    int size = length - str.length();
    for (int i=0; i<size; ++i){
        str = "0" + str;
    }
    return str;
}
void SmartGuesser::startNewGame(uint len){
    _lastGuess = "";
    vec.clear();
    length = len;
    for (int i=0; i<pow(10.0,len); ++i){
        vec.push_back(Convert_Guess(i));
    }
    Convert_Guess(length);
}
