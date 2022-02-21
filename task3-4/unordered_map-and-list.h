#ifndef UNORDERED_MAPANDLIST_H
#define UNORDERED_MAPANDLIST_H

#include <list>
#include <string>
#include <unordered_map>

class UnorderedMapandList
{
public:
    void Timing_UnorderedMap_List(std::string);
    void Sort_Bricks();
    void Print_Sorted_Bricks();
    UnorderedMapandList(std::string);

private:
    void Format_Data();
    void Pair_Inversion();
    void Easternmost_Sort();
    void Westernmost_Sort();
    std::string fileName;
    std::unordered_map<std::string, std::string> unsortedBricks;
    std::list< std::string> sortedBricks;
    std::pair<std::string, std::string> firstBrick;
    std::pair<std::string, std::string> Discover_Bricks(std::string);

};


#endif // UNORDERED_MAPANDLIST_H
