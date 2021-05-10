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
    class Medic : public Player
    {
    private:
        // const string PlayerName="Medic";
    public:
        Medic(Board &board, City c) : Player(board, c, "Medic"){};
        ~Medic(){};
        Player &treat(City);
        Player &drive(City);
        Player &fly_direct(City);
        Player &fly_charter(City);
        Player &fly_shuttle(City);
        // const string& role() const ;
    };

};