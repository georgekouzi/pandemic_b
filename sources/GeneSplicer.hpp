
#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;
namespace pandemic
{
    class GeneSplicer : public Player
    {
    private:
        // const string PlayerName="GeneSplicer";
    public:
        GeneSplicer(Board &board, City c) : Player(board, c, "GeneSplicer"){};
        ~GeneSplicer(){};
        Player &discover_cure(Color c);

        // const string& role() const ;
    };

};