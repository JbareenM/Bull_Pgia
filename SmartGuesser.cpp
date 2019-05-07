//
//  Pgia
//
//  Created by Jeme Jbareen on 4/28/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#include "SmartGuesser.hpp"
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

string SmartGuesser::guess(){
    if(vec.size()==0)
        Convert_Guess(length);
    else
        _lastGuess=vec[0];
    return _lastGuess;
}
void SmartGuesser::learn(bullpgia::Latest_Guess s){
    vector<string> _BullsVec;
    string str1=to_string(s._Bulls)+","+to_string(s._Pgia);
    for (int i = 0; i < vec.size(); i++){
        bullpgia::Latest_Guess res = bullpgia::calculateBullAndPgia(_lastGuess, vec[i]);
        string str=to_string(res._Bulls)+","+to_string(res._Pgia);
        if (str==str1)
            _BullsVec.push_back(vec[i]);
    }
    vec.clear();
    vec = _BullsVec;
    _lastGuess = _BullsVec[0];
    _BullsVec.clear();
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
