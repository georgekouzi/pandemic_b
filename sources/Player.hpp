#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <iostream>
#include <unordered_map>
#include <list>
#include <set>

using namespace std;
namespace pandemic
{

    class Player
    {
    protected:
        const int numOfColorCityCard = 5;
        set<City> Player_card;

        // unordered_map<City, Player *> Players_pos;
        City _location;
        Board &board;
        const string PlayerName;

    public:
        Player(Board &b, City location) : board(b), _location(location){};
        Player(Board &b, City location, string s) : board(b), _location(location), PlayerName(s){};
        ~Player(){};
        virtual Player &drive(City);
        virtual Player &fly_direct(City);
        virtual Player &fly_charter(City);
        virtual Player &fly_shuttle(City);
        virtual Player & build();
        virtual Player &discover_cure(Color);
        virtual Player &treat(City);
        virtual const string &role() const;
        virtual Player &take_card(City);
        void remove_cards();
        string get_pos();
    };

};