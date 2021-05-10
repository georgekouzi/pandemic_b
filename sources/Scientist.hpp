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
class Scientist: public Player
{
private:
int  numOfNeedColorCityCard;
// const string PlayerName="Scientist"; 
public:
    Scientist(Board& board,City c,int n):Player(board,c,"Scientist"),numOfNeedColorCityCard(n){};
    ~Scientist(){};
    Player &discover_cure(Color c);

};

};