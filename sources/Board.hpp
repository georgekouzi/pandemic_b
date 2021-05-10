#pragma once

#include <iostream>
#include <map>
#include <unordered_map>

#include <set>
#include "City.hpp"
#include "Color.hpp"
#include <tuple>
#include <vector>

using namespace std;

namespace pandemic
{
    class Board
    {
    private:
        map<City, tuple<City, string, Color, string, set<City>, int, bool>> world_connections;
        map<Color,pair<string,bool>> discover_cure;
        void read_connections();
        void build_color_Disease(Color,string const& s);

    public:
        Board()
        {
            read_connections();
            
        };
        ~Board(){};
        bool if_connection(City src, City dest);
        int &operator[](const City &);
        friend ostream &operator<<(ostream &out, const Board &board);
        bool is_clean();
        void remove_cures();
        void remove_stations();
        string getCityName(City);
        string getColorNameOfCity(Color);
        bool iFdiscoverCure(Color);
        void CureTheCity(City, bool all );
        int getdis(City c);
        void BuildResearchStation(City c);
        bool haveResearchStation(City c);
        Color getColorCity(City c);
        void discoverCure(Color);

    };

};
