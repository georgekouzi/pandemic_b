
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
    class Researcher : public Player
    {
    private:
        // const string PlayerName="Researcher";
    public:
        Researcher(Board &board, City c) : Player(board, c, "Researcher"){};
        ~Researcher(){};
        Player &discover_cure(Color c);

        // const string& role() const ;
    };

};