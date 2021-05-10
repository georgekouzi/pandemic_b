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
class FieldDoctor: public Player
{
private:
// const string PlayerName="FieldDoctor"; 
public:
    FieldDoctor(Board& board,City c):Player(board,c,"FieldDoctor"){};
    ~FieldDoctor(){};
    Player &treat(City c);

    // const string& role() const ;
};

};