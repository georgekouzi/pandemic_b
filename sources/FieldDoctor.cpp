#include "FieldDoctor.hpp"
namespace pandemic
{
    Player &FieldDoctor::treat(City c)
    {
        if (_location == c)
        {

            Player::treat(c);
        }
        else if (board[c] == 0)
        {
            throw invalid_argument("illegal action: no more cubes remain in " + board.getCityName(c));
        }

        else if (board.if_connection(this->_location, c))
        {
            if (board.iFdiscoverCure(board.getColorCity(c)))
            {
                board.CureTheCity(c, true);
            }
            else
            {
                board.CureTheCity(c, false);
            }
        }
        else
        {
            throw invalid_argument("illegal action: " + board.getCityName(c) + " is not connected to " + board.getCityName(this->_location));
        }

        return *this;
    }

};