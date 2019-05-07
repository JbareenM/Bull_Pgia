//
//  Pgia
//
//  Created by Jeme Jbareen on 4/28/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#ifndef SmartGuesser_hpp
#define SmartGuesser_hpp

#include "Guesser.hpp"
#include "calculate.hpp"
#include <vector>
#include <string>
class SmartGuesser: public bullpgia::Guesser {
private:
    std::string _lastGuess="";
    std::vector<std::string> vec;
    std::string Convert_Guess(int);
public:
    std::string guess() override;
    void startNewGame(uint len) override;
    void learn(bullpgia::Latest_Guess res) override;
};


#endif

