#include "calculate.hpp"
#include <string>
#include <iostream>
using std::string;


const bullpgia::Latest_Guess bullpgia::calculateBullAndPgia(const string choose, const string guess){
    int Bulls=0, Pgia=0;
    for (int i=0; i<choose.length(); ++i) {
        if (choose[i] == guess[i])
            Bulls++;
        else
            Pgia++;
    }
    Latest_Guess last_Result;
    last_Result._Bulls= Bulls;
    last_Result._Pgia =Pgia;
    return last_Result;
}
bool bullpgia::Latest_Guess::operator==(const bullpgia::Latest_Guess res){
    return (_Bulls==res._Bulls && _Pgia==res._Pgia);
}
std::ostream& bullpgia::operator <<(std::ostream& out, const bullpgia::Latest_Guess& res){
    return out << std::to_string(res._Bulls) << "," + std::to_string(res._Pgia);
}
