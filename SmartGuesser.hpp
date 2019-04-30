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

class SmartGuesser: public bullpgia::Guesser {
    public:
        std::string guess() override;
        void startNewGame(uint len) override;
        void learn(bullpgia::Latest_Guess res) override;
};

void Convert_Guess(std::string,int);
#endif

