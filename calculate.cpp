#include "calculate.hpp"
#include <string>
#include <iostream>
using namespace std;

//const bullpgia::Latest_Guess bullpgia::calculateBullAndPgia(string choose, string guess)
//{
//    int Bulls = 0;
//    int Pgia = 0;
//    string Choice = "";
//    string Guess = "";
//    for (int i = 0; i < choose.length(); i++){
//        if (choose[i] == guess[i])
//            Bulls++;
//        else{
//            Choice+=choose[i];
//            Guess += guess[i];
//        }
//    }
//    for (int i = 0; i < Guess.length(); i++){
//        int place = Choice.find(Guess[i]);
//        if (place != -1){
//            Pgia++;
//            Choice.erase(Choice.begin()+place);
//        }
//    }
//    bullpgia::Latest_Guess a;
//    a._Bulls=Bulls;
//    a._Pgia=Pgia;
//    return a;
//}
bool bullpgia::Latest_Guess::operator==(const bullpgia::Latest_Guess res){
    return (_Bulls==res._Bulls && _Pgia==res._Pgia);
}
std::ostream& bullpgia::operator <<(std::ostream& out, const bullpgia::Latest_Guess& res){
    return out << std::to_string(res._Bulls) << "," + std::to_string(res._Pgia);
}

bullpgia::Latest_Guess calculateBullAndPgia(string the_choice,string the_guess){
    int pgia_numbers = 0;
    int bull_numbers = 0;
    int num[10] = {0};
    for(int i=0; i<the_choice.length(); i++)
    {
        if(the_guess[i]==the_choice[i])
        {
            bull_numbers++;
        }
        else
        {
            if(num[the_guess[i] - '0']++ < 0)
            {
                pgia_numbers++;
            }
            if(num[the_choice[i] - '0']-- > 0)
            {
                pgia_numbers++;
            }
        }
    }
    bullpgia::Latest_Guess l;
    l._Bulls=bull_numbers;
    l._Pgia=pgia_numbers;
    return l;
}

