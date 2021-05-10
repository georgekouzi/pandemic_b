#include "Scientist.hpp"
namespace pandemic
{

    Player &Scientist::discover_cure(Color c)
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
                if (lis.size() == numOfNeedColorCityCard)
                {
                    break;
                }
            }

            if (lis.size() != numOfNeedColorCityCard)
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
};