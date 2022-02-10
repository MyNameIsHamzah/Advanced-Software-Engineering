#ifndef UNORDERED_MAPANDLIST_H
#define UNORDERED_MAPANDLIST_H

#include <list>
#include <string>
#include <unordered_map>

class UnorderedMapandList
{
public:
    UnorderedMapandList(std::string);
    void Get_New_File(std::string);
    void Sort_Bricks();
    void Print_Sorted_Bricks();
private:
    std::string fileName;
    std::unordered_map<std::string, std::string> unsortedData;
    std::list< std::string> sortedData;
    std::pair<std::string, std::string> firstBrick;
    void Format_Data();
    void Pair_Inversion();
    void Easternmost_Sort();
    void Westernmost_Sort();
    std::pair<std::string, std::string> Discover_Bricks(std::string);
};


#endif // UNORDERED_MAPANDLIST_H
