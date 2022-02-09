#ifndef UNORDERED_MAPANDLIST_H
#define UNORDERED_MAPANDLIST_H

#include <list>
#include <string>
#include <unordered_map>

class UnorderedMapandList
{
public:
    UnorderedMapandList(std::string);
    void Change_File(std::string);
    void Sort_Bricks();
    void Print_Sorted_Bricks();
private:
    std::string fileName;
    std::unordered_map<std::string, std::string> unsortedData;
    std::list< std::string> sortedData;
    std::pair<std::string, std::string> firstBrick;
    void Load_Data();
    void Invert_Data();
    void Sort_Eastern();
    void Sort_Western();
    std::pair<std::string, std::string> Find_Next_Brick(std::string);
};


#endif // UNORDERED_MAPANDLIST_H
