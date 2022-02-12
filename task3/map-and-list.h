#ifndef MAPANDLIST_H
#define MAPANDLIST_H
#include <list>
#include <string>
#include <map>

class MapandList
{
public:
    MapandList(std::string);
    void Get_New_File(std::string);
    void Sort_Bricks();
    void Print_Sorted_Bricks();
    void Timing_Map_List(std::string);

private:
    std::string fileName;
    std::map<std::string, std::string> unsortedData;
    std::list<std::string> sortedData;
    std::pair<std::string, std::string> firstBrick;
    void Format_Data();
    void Pair_Inversion();
    void Easternmost_Sort();
    void Westernmost_Sort();
    std::pair<std::string, std::string> Discover_Bricks(std::string);
};

#endif // MAPANDLIST_H
