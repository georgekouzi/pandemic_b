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
    class Virologist : public Player
    {
    private:
        // const string PlayerName="Virologist";
    public:
        Virologist(Board &board, City c) : Player(board, c, "Virologist"){};
        ~Virologist(){};
        Player &treat(City);
        // const string& role() const ;
    };

};