#include "Board.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
namespace pandemic
{
    enum data
    {
        city_id = 0,
        city_name = 1,
        color_id = 2,
        color_name = 3,
        neighbors = 4,
        num_of_disease = 5,
        build_research_station = 6,
    };

    void Board::build_color_Disease(Color c, string const &s)
    {
        discover_cure[c] = {s, false};
    }

    void Board::read_connections()
    {
        ifstream read{"cities_map.txt"};

        string newLine;

        while (getline(read, newLine))
        {

            istringstream Word(newLine);
            string nextWord;

            while (Word >> nextWord)
            {
                City city_id = static_cast<City>(stoi(nextWord));
                get<data::city_id>(world_connections[city_id]) = city_id;
                get<data::num_of_disease>(world_connections[city_id]) = 0;
                get<data::build_research_station>(world_connections[city_id]) = false;

                Word >> nextWord;
                get<data::city_name>(world_connections[city_id]) = nextWord;

                Word >> nextWord;
                Color color_id = static_cast<Color>(stoi(nextWord));
                get<data::color_id>(world_connections[city_id]) = color_id;

                Word >> nextWord;
                get<data::color_name>(world_connections[city_id]) = nextWord;

                if (discover_cure.find(color_id) == discover_cure.end())
                {
                    build_color_Disease(color_id, nextWord);
                }

                while (Word >> nextWord)
                {
                    City city = static_cast<City>(stoi(nextWord));
                    get<data::neighbors>(world_connections[city_id]).insert(city);
                    Word >> nextWord;
                }
            }
        }
    }
    bool Board::iFdiscoverCure(Color c)
    {
        return discover_cure[c].second;
        // return discover_cure[get<color_id>(world_connections[c])];
    }

    int &Board::operator[](const City &c)
    {
        return (get<num_of_disease>(world_connections[c]));
    }

    bool Board::is_clean()
    {
        for (const auto &it : world_connections)
        {
            if (get<num_of_disease>(it.second) != 0)
            {
                return false;
            }
        }
        return true;
    }

    ostream &operator<<(ostream &out, const Board &board)
    {
        string s;
        for (const auto &it : board.world_connections)
        {
            s += "city info:\ncity_name = " + get<city_name>(it.second) + "\n" + "city color = " + get<color_name>(it.second) + "\n" + "The level of disease in the city = " + to_string(get<num_of_disease>(it.second)) + "\n" + "Research stations built so far = " + "\n" + "...................................\n";
        }

        return out << s;
    }

    void Board::remove_cures()
    {
        for (auto &it : discover_cure)
        {
            it.second.second = false;
        }
    }

    bool Board::if_connection(City src, City dest)
    {
        return get<neighbors>(world_connections[src]).find(dest) != get<neighbors>(world_connections[src]).end();
    }
    string Board::getCityName(City c)
    {
        return get<city_name>(world_connections[c]);
    }
    void Board::CureTheCity(City c, bool all)
    {
        if (all)
        {
            get<num_of_disease>(world_connections[c]) = 0;
        }
        else
        {
            --get<num_of_disease>(world_connections[c]);
        }
        // return *this;
    }
    int Board::getdis(City c)
    {
        return get<num_of_disease>(world_connections[c]);
    }

    bool Board::haveResearchStation(City c)
    {
        return get<build_research_station>(world_connections[c]);
    }
    void Board::BuildResearchStation(City c)
    {
        get<build_research_station>(world_connections[c]) = true;
    }
    Color Board::getColorCity(City c)
    {

        return get<color_id>(world_connections[c]);
    }
    void Board::discoverCure(Color c)
    {
        discover_cure[c].second = true;
    }
    string Board::getColorNameOfCity(Color c)
    {
        return discover_cure[c].first;
    }
    void Board::remove_stations()
    {
        for (auto &it : world_connections)
        {
            get<build_research_station>(it.second) = false;
        }
    }

};
