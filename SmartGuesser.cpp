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

using namespace std;

string SmartGuesser::guess() {
    int rnd = rand() % vec.size();
    auto i = vec.begin();
    advance(i, rnd);
    _lastGuess = *i;
    cout<<_lastGuess<<endl;
    return _lastGuess;
}

void SmartGuesser::learn(bullpgia::Latest_Guess s) {
    string str1=to_string(s._Bulls)+","+to_string(s._Pgia);
    for(auto i=vec.begin(); i!= vec.end();) {
        bullpgia::Latest_Guess ans = bullpgia::calculateBullAndPgia(_lastGuess, *i);
        string str=to_string(ans._Bulls)+","+to_string(ans._Pgia);
        if(str1 != str)
            i = vec.erase(i);
        else
            i++;
    }
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
        vec.insert(Convert_Guess(i));
    }
    Convert_Guess(length);
}
