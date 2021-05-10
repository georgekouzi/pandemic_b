#include "Medic.hpp"
namespace pandemic
{
    Player &Medic::treat(City c)
    {
        if (_location != c)
        {
            throw invalid_argument("illegal action: You should be in " + board.getCityName(c) + " to treat the city");
        }

         if (board[c] == 0)
        {
            throw invalid_argument("illegal action: no more cubes remain in " + board.getCityName(c));
        }
        board.CureTheCity(c, true);

        return *this;
    }
    Player &Medic::drive(City c)
    {
        Player::drive(c);

        if (board.iFdiscoverCure(board.getColorCity(c)))
        {
            board.CureTheCity(c, true);
        }
        return *this;
    }

    Player &Medic::fly_direct(City c)
    {
        Player::fly_direct(c);

        if (board.iFdiscoverCure(board.getColorCity(c)))
        {
            board.CureTheCity(c, true);
        }
        return *this;
    }

    Player &Medic::fly_charter(City c)
    {
        Player::fly_charter(c);

        if (board.iFdiscoverCure(board.getColorCity(c)))
        {
            board.CureTheCity(c, true);
        }
        return *this;
    }

    Player &Medic::fly_shuttle(City c)
    {
        Player::fly_shuttle(c);

        if (board.iFdiscoverCure(board.getColorCity(c)))
        {
            board.CureTheCity(c, true);
        }
        return *this;
    }

};