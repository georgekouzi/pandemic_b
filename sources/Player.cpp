#include "Player.hpp"
#include <list>

using namespace std;
namespace pandemic
{
    void Player::remove_cards()
    {
        for (auto it = Player_card.begin(); it != Player_card.end();)
        {
            it = Player_card.erase(it);
        }
    }

    Player &Player::take_card(City c)
    {
        //If the card is not found, we will put it on the map.
        if (Player_card.find(c) == Player_card.end())
        {
            Player_card.insert(c);
        }

        return *this;
    }

    Player &Player::drive(City c)
    {
        if (c == this->_location)
        {
            throw invalid_argument("illegal action: cannot drive from city to it self");
        }
        if (!board.if_connection(this->_location, c))
        {
            throw invalid_argument("illegal action: " + board.getCityName(c) + " is not connected to " + board.getCityName(this->_location));
        }
        this->_location = c;
        return *this;
    }

    Player &Player::fly_direct(City c)
    {
        if (c == this->_location)
        {
            throw invalid_argument("illegal action: cannot fly from city to it self");
        }
        if (Player_card.find(c) == Player_card.end())
        {
            throw invalid_argument(" illegal action: you do not have the card of " + board.getCityName(c));
        }
        Player_card.erase(c);
        this->_location = c;
        return *this;
    }

    Player &Player::fly_charter(City c)
    {
        if (c == this->_location)
        {
            throw invalid_argument("illegal action: cannot fly from city to it self");
        }
        if (Player_card.find(this->_location) == Player_card.end())
        {
            throw invalid_argument(" you do not have the " + board.getCityName(this->_location) + " card (the card of the city you are in)");
        }

        Player_card.erase(Player_card.find(this->_location));
        this->_location = c;
        return *this;
    }
    Player &Player::fly_shuttle(City c)
    {
        if (c == this->_location)
        {
            throw invalid_argument("illegal action: cannot fly from city to it self");
        }

        if (!this->board.haveResearchStation(this->_location) && !this->board.haveResearchStation(c))
        {
            throw invalid_argument("illegal action: There is no research station in the city of " + board.getCityName(this->_location) + " that you are in , and there is no research station in the city of " + board.getCityName(c) + " that you want to travel");
        }
        if (!this->board.haveResearchStation(this->_location))
        {
            throw invalid_argument("illegal action: There is no research station in the city of " + board.getCityName(this->_location) + " that you are in");
        }
        if (!this->board.haveResearchStation(c))
        {
            throw invalid_argument("illegal action: There is no research station in the city of " + board.getCityName(c) + " that you want to travel");
        }

        this->_location = c;
        return *this;
    }
    Player &Player::discover_cure(Color c)
    {
        if (!this->board.haveResearchStation(this->_location))
        {
            throw invalid_argument("illegal action: There is no research station in the city of " + board.getCityName(this->_location) + " that you are in");
        }
        if (!board.iFdiscoverCure(c))
        {
            list<City> lis;

            for (const auto &it : Player_card)
            {
                if (board.getColorCity(it) == c)
                {
                    lis.push_back(it);
                }
                if (lis.size() == numOfColorCityCard)
                {
                    break;
                }
            }

            if (lis.size() != numOfColorCityCard)
            {
                throw invalid_argument("illegal action: you only have " + to_string(lis.size()) + " " + board.getColorNameOfCity(c) + " cards remaining.");
            }

            for (auto it = lis.begin(); it != lis.end(); ++it)
            {
                Player_card.erase(*it);
            }
            board.discoverCure(c);
            return *this;
        }
        return *this;
    }

    Player &Player::treat(City c)
    {
        if (_location != c)
        {
            throw invalid_argument("illegal action: You should be in " + board.getCityName(c) + " to treat the city");
        }
        if (board[c] == 0)
        {
            throw invalid_argument("illegal action: no more cubes remain in " + board.getCityName(c));
        }

        if (board.iFdiscoverCure(board.getColorCity(c)))
        {
            board.CureTheCity(c, true);
        }
        else
        {
            board.CureTheCity(c, false);
        }

        return *this;
    }

    const string &Player::role() const
    {
        return PlayerName;
    }

    string Player::get_pos()
    {
        return board.getCityName(this->_location);
    }

    Player &Player::build()
    {

        if (Player_card.find(this->_location) == Player_card.end())
        {

            throw invalid_argument(" you do not have the " + board.getCityName(this->_location) + " card (the card of the city you are in)");
        }

        if (!board.haveResearchStation(this->_location))
        {
            Player_card.erase(this->_location);
            board.BuildResearchStation(this->_location);
        }
        return *this;
    }
};