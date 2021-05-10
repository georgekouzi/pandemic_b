#include "Virologist.hpp"
namespace pandemic
{
    Player &Virologist::treat(City c)
    {

        if (_location == c)
        {

            Player::treat(c);
        }
        else if (board[c] == 0)
        {
            throw invalid_argument("illegal action: no more cubes remain in " + board.getCityName(c));
        }

        else if (Player_card.find(c) != Player_card.end())
        {
            if (board.iFdiscoverCure(board.getColorCity(c)))
            {
                Player_card.erase(c);
                board.CureTheCity(c, true);
            }
            else
            {
                Player_card.erase(c);
                board.CureTheCity(c, false);
            }
        }

        else if (Player_card.find(c) == Player_card.end())
        {
            throw invalid_argument("illegal action: you do not have the " + board.getCityName(c) + " card to treat this city");
        }

        else
        {
            throw invalid_argument("illegal action: you discarded the " + board.getCityName(c) + " card");
        }

        return *this;
    }

};