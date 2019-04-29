#pragma once
#include "Guesser.hpp"
using std::string;


class ConstantGuesser: public bullpgia::Guesser {
		string myConstantString;
	public:
		ConstantGuesser(const string& constantString) { myConstantString = constantString; }
		string guess() override {
			return myConstantString;
		}
};

class RandomGuesser: public bullpgia::Guesser {
	string guess() override;

};
