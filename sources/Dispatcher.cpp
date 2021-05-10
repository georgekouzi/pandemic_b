#include "Dispatcher.hpp"
namespace pandemic
{
    Player &Dispatcher::fly_direct(City c)
    {
        if (c == this->_location)
        {
            throw invalid_argument("illegal action: cannot fly from city to it self");
        }
        if (board.haveResearchStation(this->_location))
        {
            this->_location = c;
        }
        else
        {

            Player::fly_direct(c);
        }

        return *this;
    };

};