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
    class Dispatcher : public Player
    {
    private:
        // const string PlayerName="Dispatcher";
    public:
        Dispatcher(Board &board, City c) : Player(board, c, "Dispatcher"){};
        ~Dispatcher(){};
        Player &fly_direct(City)override;

        // const string& role() const ;
    };

};