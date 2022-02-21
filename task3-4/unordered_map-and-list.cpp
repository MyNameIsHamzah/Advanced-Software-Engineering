 #include "unordered_map-and-list.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

UnorderedMapandList::UnorderedMapandList(std::string fileName)
{
    this->fileName = fileName;
    this->firstBrick.first = "";
    this->firstBrick.second = "";
    Format_Data();
}

void UnorderedMapandList::Format_Data()
{
    std::string empty = "";
    this->unsortedBricks.clear();

    std::ifstream inputPairsFile;
    inputPairsFile.open(fileName);

    std::string line;
    std::string north;
    std::string south;

    while (std::getline(inputPairsFile, line))
    {
        std::istringstream ss(line);
        std::getline(ss, north, ',');
        std::getline(ss, south, ',');

        // insert first brick
        if (firstBrick.first == empty)
        {
            this->firstBrick.first = north;
            this->firstBrick.second = south;
        }
        this->unsortedBricks.insert(std::make_pair(north, south));
    }
    inputPairsFile.close();
}

std::pair<std::string, std::string> UnorderedMapandList::Discover_Bricks(std::string key)
{
    auto na = std::make_pair("","");
    // iterator to found location
    auto foundBrick = this->unsortedBricks.find(key);
    if (foundBrick != unsortedBricks.end())
    {
        std::pair<std::string, std::string> nextBrick;
        nextBrick.first = foundBrick->first;
        nextBrick.second = foundBrick->second;
        // Deletes found brick, so less elements to iterate as time goes on
        this->unsortedBricks.erase(foundBrick);

        return nextBrick;
    }
    // not found
    else
    {
        return na;
    }
}

void UnorderedMapandList::Easternmost_Sort()
{
    std::pair<std::string, std::string> currentBrick = this->firstBrick;
    this->sortedBricks.push_back(currentBrick.second);
    bool sortingeastwards = true;

    // iterates to the east, stops when there are no more bricks
    while (sortingeastwards)
    {
        currentBrick = Discover_Bricks(currentBrick.second);
        //brick was not found
        if (currentBrick.first == "")
        {
            sortingeastwards = false;
        }
        else
        {
            this->sortedBricks.push_back(currentBrick.second);
        }
    }
}
void UnorderedMapandList::Pair_Inversion()
{
    std::unordered_map<std::string, std::string> invertedData;

    for (auto brick : this->unsortedBricks)
    {
        invertedData.insert(std::make_pair(brick.second, brick.first));
    }
    this->unsortedBricks = invertedData;
}
void UnorderedMapandList::Westernmost_Sort()
{
    std::pair<std::string, std::string> currentBrick = this->firstBrick;
    bool sortingwestwards = true;

    // iterates to the west, stops when there are no more bricks
    while (sortingwestwards)
    {
        currentBrick = Discover_Bricks(currentBrick.second);
        //brick was not found
        if (currentBrick.first == "")
        {
            sortingwestwards = false;
        }
        else
        {
            this->sortedBricks.push_front(currentBrick.second);
        }
    }
}

void UnorderedMapandList::Sort_Bricks()
{
    // Sorts the bricks going East
    Easternmost_Sort();

    //invert pairs for western sort
    Pair_Inversion();

    // Sorts the bricks going West
    Westernmost_Sort();

}
void UnorderedMapandList::Print_Sorted_Bricks()
{
    for (auto brick : this->sortedBricks)
    {
        std::cout << brick << std::endl;
    }
}





