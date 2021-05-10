#include "GeneSplicer.hpp"
namespace pandemic
{

    Player &GeneSplicer::discover_cure(Color c)
    {
        if (!this->board.haveResearchStation(this->_location))
        {
            throw invalid_argument("illegal action: There is no research station in the city of " + board.getCityName(this->_location) + " that you are in");
        }
        if (!board.iFdiscoverCure(c))
        {

            if (Player_card.size() == numOfColorCityCard)
            {
                for (auto it = Player_card.begin(); it != Player_card.end();)
                {

                    it = Player_card.erase(it);
                }

                board.discoverCure(c);
            }

            else
            {

                throw invalid_argument("illegal action: you only have " + to_string(Player_card.size()) + " cards remaining.");
            }
        }

        return *this;
    }

};