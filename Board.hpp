#ifndef BOARD
#define BOARD

#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
#include <map>
#include <utility>
using namespace std;

namespace ariel{
    class Board{
        private:
            u_int GGleft; //the leftest space on the board that there is an add.
            u_int GGdown; //the lowest space on the board that there is an add.

            std::map<std::pair<u_int, u_int>, char> board; //represent the board.

        public:
            Board();
            void post(u_int row, u_int column, Direction w, string content);
            string read(u_int row, u_int column, Direction w, u_int lentgh);
            void show();
    };
}

#endif