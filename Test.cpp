/**
 * A demo program for bull-pgia.
 *
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {
    
    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
        
        // BASIC TESTS - DO NOT CHANGE
        ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
        ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};
        
        testcase.setname("Calculate bull and pgia")
        .CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
        .CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
        
        .CHECK_OUTPUT(calculateBullAndPgia("1234","5678"), "0,0")
        .CHECK_OUTPUT(calculateBullAndPgia("1234","3214"), "2,2")
        .CHECK_OUTPUT(calculateBullAndPgia("5037","4321"), "0,1")
        .CHECK_OUTPUT(calculateBullAndPgia("121323123323","32331313326"), "5,4")
        .CHECK_OUTPUT(calculateBullAndPgia("5037","5073"), "2,2")
        .CHECK_OUTPUT(calculateBullAndPgia("8526", "8511"), "2,0")
        .CHECK_OUTPUT(calculateBullAndPgia("1111", "2222"), "0,0")
        .CHECK_OUTPUT(calculateBullAndPgia("9797","9000"), "1,0")
        .CHECK_OUTPUT(calculateBullAndPgia("5037","2345"), "0,2")
        .CHECK_OUTPUT(calculateBullAndPgia("655765765765765","62531623561323"), "3,2")
        .CHECK_OUTPUT(calculateBullAndPgia("7777","4444"), "0,0")
        .CHECK_OUTPUT(calculateBullAndPgia("5037","5370"), "1,3")
        .CHECK_OUTPUT(calculateBullAndPgia("42415","54432"), "1,3")
        .CHECK_OUTPUT(calculateBullAndPgia("42415","54342"), "0,4")
        .CHECK_OUTPUT(calculateBullAndPgia("11111","11111"), "5,0")
        .CHECK_OUTPUT(calculateBullAndPgia("22","22"), "2,0")
        .CHECK_OUTPUT(calculateBullAndPgia("4567","7654"), "0,4")
        .CHECK_OUTPUT(calculateBullAndPgia("8000","2000"), "3,0")
        .CHECK_OUTPUT(calculateBullAndPgia("7878","1818"), "2,0")
        .CHECK_OUTPUT(calculateBullAndPgia("22","12"), "1,0")
        .CHECK_OUTPUT(calculateBullAndPgia("12","10"), "1,0")
        .CHECK_OUTPUT(calculateBullAndPgia("4","4"), "1,0")
        .CHECK_OUTPUT(calculateBullAndPgia("1322","1437"), "1,1")
        .CHECK_OUTPUT(calculateBullAndPgia("4","3"), "0,0")
        ;
        
        testcase.setname("Play with dummy choosers and guessers")
        .CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
        .CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns
        .CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
        .CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
        ;
        
        testcase.setname("Play with smart guesser");
        RandomChooser randy;
        SmartGuesser smarty;
        for (uint i=0; i<100; ++i) {
            testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
        }
        testcase.setname("play with Random chooser with smart guesser");
        for (uint i=0; i<100; ++i) {
            testcase.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true);  // smarty should always win in at most 10 turns!
        }
        testcase.setname("Random chooser with smart guesser")
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
        .CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true);
        
        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: "  << grade << endl;
    return 0;
}
