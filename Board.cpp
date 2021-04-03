#include "Direction.hpp"
#include "Board.hpp"

#include <iostream>
#include <stdexcept>
#include <map>

using ariel::Direction;
using namespace std;


namespace ariel{

        Board::Board()
        {
            this->GGdown = 0;
            this->GGleft = 0;
        }
            
       
        void Board::post(u_int row, u_int colomn, Direction w, string content){
            if(content.size() != 0)
            {
                std::pair<u_int, u_int> p;
                p.first = row;
                p.second = colomn;
                
                // if it horizontally, so we need to move only with coloumns. And update the GGleft if needed.
                if(w==Direction::Horizontal){
                    // dir = colomn;
                    if(colomn + content.size() > this->GGleft)
                    {
                        this->GGleft = colomn + content.size();
                    }

                    for(u_int i=0; i<content.size(); i++)
                    {
                        p.second = colomn+i;
                        this->board[p] = content[i];
                    }
                }
                // move only in the rowes. And update the GGdown if needed.
                else{
                    // dir = row;
                    if(row + content.size() > this->GGdown)
                    {
                        this->GGdown = row + content.size();
                    }

                    for(u_int i=0; i<content.size(); i++)
                    {
                        p.first= row+i;
                        this->board[p] = content[i];
                    }
                }
            }

        }

        string Board::read(u_int row,u_int column, Direction w, u_int lentgh){
            string ans;
            // u_int dir;
            // if(row > this->GGdown || column > this->GGleft){
            //     throw std::bad_exception();
            // }

            std::pair<u_int, u_int> p;
            p.first = row;
            p.second= column;

            if(w == Direction::Horizontal)
            {
                // dir = column;
                for(u_int i=0; i<lentgh; i++)
                {
                    p.second = column+i;
                    //if this key is not written yet, read the "_" char and move to next iteration.
                    try{
                        this->board.at(p);
                    }
                    catch(std::exception& e)
                    {
                        ans += "_";
                        continue;
                    }
                    ans += this->board.find(p)->second;
                    
                }
            }
            else{
                // dir = row;
                for(u_int i=0; i<lentgh; i++)
                {
                    p.first = row+i;
                    //if this key is not written yet, read the "_" char and move to next iteration.
                    try{
                        this->board.at(p);
                    }
                    catch(std::exception& e)
                    {
                        ans += "_";
                        continue;
                    }
                    ans += this->board.find(p)->second;
                }
            }
            return ans;  
        }

        void Board::show(){
            string ans = "";

            for(u_int i=0; i<this->GGdown; i++){
                cout << this->read(i, 0, Direction::Horizontal, this->GGleft);
                cout << "\n";
            }
            
        //     std::pair<u_int, u_int> p;
        //     p.first = 0;
        //     p.second = 0;

        //     for(u_int i=0; i<this->GGdown; i++){
        //         p.first = i;
        //         for(u_int j=0; j<this->GGleft; j++){
        //             p.second = j;
        //             try{
        //                 this->board.at(p);
        //             }
        //             catch(std::exception& e)
        //             {
        //                 cout << "_";
        //                 continue;
        //             }
        //             cout << this->board[p];
        //         }
        //         cout << "\n";
        //     }
        }
}