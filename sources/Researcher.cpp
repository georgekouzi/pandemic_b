#include "Researcher.hpp"
namespace pandemic
{
    Player &Researcher::discover_cure(Color c)
    {
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

            if (lis.size() == numOfColorCityCard)
            {
                for (auto it = lis.begin(); it != lis.end(); ++it)
                {
                    Player_card.erase(*it);
                }
                board.discoverCure(c);
            }

            else
            {

                throw invalid_argument("illegal action: you only have " + to_string(lis.size()) + " " + board.getColorNameOfCity(c) + " cards remaining.");
            }
        }

        return *this;
    }
};