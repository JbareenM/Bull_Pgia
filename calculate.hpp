//
//  Pgia
//
//  Created by Jeme Jbareen on 4/28/19.
//  Copyright © 2019 Jeme Jbareen. All rights reserved.
//

#ifndef calculate_hpp
#define calculate_hpp

#include <string>

namespace bullpgia {

	struct Latest_Guess{
		int _Bulls;
        int _Pgia;
        bool operator==(const Latest_Guess res);
		friend std::ostream& operator <<(std::ostream& a, const bullpgia::Latest_Guess& b);
	};
	const Latest_Guess calculateBullAndPgia(const std::string choose, const std::string guess);
}
#endif

