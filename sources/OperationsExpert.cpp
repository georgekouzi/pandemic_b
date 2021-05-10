#include "OperationsExpert.hpp"
namespace pandemic
{
    
    Player & OperationsExpert::build()
    {

        if (!this->board.haveResearchStation(this->_location))
        {
            this->board.BuildResearchStation(this->_location);
        }
        return *this;
    }

};