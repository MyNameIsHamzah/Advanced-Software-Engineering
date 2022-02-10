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

/*void UnorderedMapandList::Get_New_File(std::string newfile)
{
    this->fileName = newfile;
    Load_Data();
}*/

void UnorderedMapandList::Format_Data()
{
    this->unsortedData.clear();

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

        // starting point for unsorted data list
        if (firstBrick.first == "")
        {
            this->firstBrick.first = north;
            this->firstBrick.second = south;
        }
        this->unsortedData.insert(std::make_pair(north, south));
    }
    inputPairsFile.close();
}

std::pair<std::string, std::string> UnorderedMapandList::Discover_Bricks(std::string key)
{
    auto empty = std::make_pair("","");

    // iterator to found brick location
    auto foundBrick = this->unsortedData.find(key);
    if (foundBrick != unsortedData.end())
    {
        // Creates a new pair
        std::pair<std::string, std::string> nextBrick;
        nextBrick.first = foundBrick->first;
        nextBrick.second = foundBrick->second;
        // Deletes the old pair from the structure
        this->unsortedData.erase(foundBrick);
        return nextBrick;
    }
    // Brick wasn't found
    else
    {
        return empty;
    }
}

void UnorderedMapandList::Easternmost_Sort()
{
    std::pair<std::string, std::string> currentBrick = this->firstBrick;
    this->sortedData.push_back(currentBrick.second);
    bool sortingeastwards = true;

    // iterates to the east, stops when there are no more bricks
    while (sortingeastwards)
    {
        currentBrick = Discover_Bricks(currentBrick.second);
        // occurs if brick was not found
        if (currentBrick.first == "")
        {
            sortingeastwards = false;
        }
        else
        {
            this->sortedData.push_back(currentBrick.second);
        }
    }
}
void UnorderedMapandList::Pair_Inversion()
{
    std::unordered_map<std::string, std::string> invertedData;

    for (auto brick : this->unsortedData)
    {
        invertedData.insert(std::make_pair(brick.second, brick.first));
    }
    this->unsortedData = invertedData;
}
void UnorderedMapandList::Westernmost_Sort()
{
    std::pair<std::string, std::string> currentBrick = this->firstBrick;
    bool sortingwestwards = true;

    // iterates to the west, stops when there are no more bricks
    while (sortingwestwards)
    {
        currentBrick = Discover_Bricks(currentBrick.second);
        // Next brick was not found
        if (currentBrick.first == "")
        {
            sortingwestwards = false;
        }
        else
        {
            this->sortedData.push_front(currentBrick.second);
        }
    }
}

void UnorderedMapandList::Sort_Bricks()
{
    // Sorts the bricks going East
    Easternmost_Sort();

    //invert pars to
    Pair_Inversion();

    // Sorts the bricks going West
    Westernmost_Sort();

}
void UnorderedMapandList::Print_Sorted_Bricks()
{
    for (auto brick : this->sortedData)
    {
        std::cout << brick << std::endl;
    }
}





