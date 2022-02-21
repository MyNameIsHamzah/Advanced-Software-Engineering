#ifndef MAPANDLIST_H
#define MAPANDLIST_H
#include <list>
#include <string>
#include <map>

class MapandList
{
public:
    void Timing_Map_List(std::string);
    void Sort_Bricks();
    void Print_Sorted_Bricks();
    MapandList(std::string);


private:
    void Format_Data();
    void Pair_Inversion();
    void Easternmost_Sort();
    void Westernmost_Sort();
    std::string fileName;
    std::map<std::string, std::string> unsortedBricks;
    std::list<std::string> sortedBricks;
    std::pair<std::string, std::string> firstBrick;
    std::pair<std::string, std::string> Discover_Bricks(std::string);
};

#endif // MAPANDLIST_H
