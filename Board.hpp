#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel{
    class Board{
        public:
            void post(int row, int column, Direction w, string content);
            string read(int row, int column, Direction w, int lentgh);
            string show();
    };
}