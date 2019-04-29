//
//  Pgia
//
//  Created by Jeme Jbareen on 4/28/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#ifndef Guesser_hpp
#define Guesser_hpp

#include <iostream>
#include <string>
#include "calculate.hpp"


namespace bullpgia {
	class Guesser {
    public:
        uint length;
        virtual std::string guess()=0;
        virtual void startNewGame(uint length) {this->length = length;}
        virtual void learn(Latest_Guess res){}
 	};
}
#endif
