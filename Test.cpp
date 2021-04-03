#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;


// --------GOOD CASES!!!--------//
TEST_CASE("Good Board code") {
    ariel::Board board;
    
    board.post(0, 0, Direction::Horizontal, "Hi");
    CHECK(board.read(0, 0, Direction::Horizontal, 2) == string("Hi"));

    board.post(0, 0, Direction::Horizontal, ""); // empty string should'nt change nothing.
    CHECK(board.read(0, 0, Direction::Horizontal, 2) == string("Hi"));

    board.post(0, 1, Direction::Horizontal, "I");
    CHECK(board.read(0, 0, Direction::Horizontal, 2) == string("HI"));

    board.post(0, 0, Direction::Vertical, "Hello");
    CHECK(board.read(0, 0, Direction::Vertical, 5) == string("Hello"));

    board.post(2, 0, Direction::Horizontal, "I am Amit Hajaj");
    board.show();
    CHECK(board.read(2, 0, Direction::Horizontal, 15) == string("I am Amit Hajaj"));
    CHECK(board.read(0, 0, Direction::Vertical, 5) == string("HeIlo"));
    CHECK(board.read(2, 5, Direction::Horizontal, 10) == string("Amit Hajaj"));

    board.post(0, 0, Direction::Horizontal, "This is a test for line drop If this sentence is in line 2, OK");
    CHECK(board.read(0, 0, Direction::Horizontal, 28) == string("This is a test for line drop"));
    CHECK(board.read(0, 29, Direction::Horizontal, 33) == string("If this sentence is in line 2, OK"));

    // Because of the last post we make our board bigger. 
    CHECK(board.read(0, 28, Direction::Horizontal, 5)== string(" If t"));
    CHECK(board.read(2, 5, Direction::Horizontal, 28)== string("Amit Hajaj__________________"));
    

}

// --------BAD CASES!!!--------//
TEST_CASE("Bad Board code-> reading out of bounds, on empty board.") {
    ariel::Board board;// initially set 2x2 board.
    CHECK_THROWS(board.read(50, 50, Direction::Horizontal, 5));
    CHECK_THROWS(board.read(3, 3, Direction::Vertical, 1));
    CHECK_THROWS(board.read(50, 50, Direction::Horizontal, 5));

    
}
TEST_CASE("Bad Board code-> reading out of bounds, but starting from reachable zone."){
    ariel::Board board;
    board.post(0,0, Direction::Horizontal, "Check1");
    board.post(0, 0, Direction::Vertical, "Check2");

    CHECK_THROWS(board.read(0, 0, Direction::Horizontal, 10));
    CHECK_THROWS(board.read(0, 0, Direction::Vertical, 10));

    board.post(0, 6, Direction::Horizontal, " Aye 1, 1212..");
    board.post(6, 0, Direction::Vertical, " Aye 2, 1212..");

    CHECK_THROWS(board.read(0, 6, Direction::Horizontal, 15));
    CHECK_THROWS(board.read(6, 0, Direction::Vertical, 15));
}
TEST_CASE("Bad Board code-> Empty post on empty board."){
    ariel::Board board;
    board.post(0, 0, Direction::Vertical, ""); //empty post.
    CHECK_THROWS(board.read(0, 0, Direction::Vertical, 1));
}

TEST_CASE("Bad Board code-> empty post on a new space."){
    ariel::Board board;
    board.post(0 , 0, Direction::Horizontal, "Hello");
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == string("Hello"));

    board.post(0, 6, Direction::Horizontal, "");
    CHECK_THROWS(board.read(0, 0, Direction::Horizontal, 6));
}


