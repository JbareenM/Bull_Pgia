#pragma once
#include <iostream>
#include <string>

namespace bullpgia {
	class Chooser {
    public:
        uint length;
        virtual std::string choose(uint length)=0;
	};
}
