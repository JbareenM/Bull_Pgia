//
//  Pgia
//
//  Created by Jeme Jbareen on 4/28/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#ifndef CHOOSER_hpp
#define CHOOSER_hpp

#include <iostream>
#include <string>

namespace bullpgia {
	class Chooser {
    public:
        uint length;
        virtual std::string choose(uint length)=0;
	};
}
#endif
