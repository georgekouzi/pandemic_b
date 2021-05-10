
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
    class OperationsExpert : public Player
    {
    private:
        // const string PlayerName="OperationsExpert";
    public:
        OperationsExpert(Board &board, City c) : Player(board, c, "OperationsExpert"){};
        ~OperationsExpert(){};
        Player & build()override;
    };

};