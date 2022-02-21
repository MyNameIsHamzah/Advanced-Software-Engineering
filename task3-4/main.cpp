#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <unordered_map>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <limits>

using std::chrono::steady_clock;
using std::chrono::milliseconds;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::string;
using std::list;
using std::pair;
using std::unordered_map;
using std::map;

/*
 THIS FILE CONTAINS: TASK 3: 2 IMPLEMENTATIONS
                    TASK 4: TIMING ALG FOR BOTH IMPLEMENTATIONS
                    2 MAIN FUNCTIONS: 1 FOR EACH TASK AT THE BOTTOM


*/

//FIRST IMPLEMENTATION: Unordered map and list

class UnorderedMapandList
{
public:
    void Timing_UnorderedMap_List(string);
    void Sort_Bricks();
    void Display_Wall();
    UnorderedMapandList(string);
    void Form_Brick();
    void Pair_Inversion();
    void Easternmost_Sort();
    void Westernmost_Sort();
    string fileName;
    unordered_map<string, string> unsortedBricks;
    list<string> sortedBricks;
    pair<string, string> startingBrick;
    pair<string, string> Search_Brick(string);

};

UnorderedMapandList::UnorderedMapandList(string fileName)
{
    this->fileName = fileName;
    this->startingBrick.first = "";
    this->startingBrick.second = "";
    Form_Brick();
}

void UnorderedMapandList::Form_Brick()
{
    string empty = "";
    this->unsortedBricks.clear();

    std::ifstream inputPairsFile;
    inputPairsFile.open(fileName);

    string line;
    string north;
    string south;

    while (std::getline(inputPairsFile, line))
    {
        std::istringstream ss(line);
        std::getline(ss, north, ',');
        std::getline(ss, south, ',');

        if (startingBrick.first == empty)
        {
            this->startingBrick.first = north;
            this->startingBrick.second = south;
        }
        this->unsortedBricks.insert(std::make_pair(north, south));
    }
    inputPairsFile.close();
}

pair<string, string> UnorderedMapandList::Search_Brick(string key)
{
    auto na = std::make_pair("","");

    auto foundBrick = this->unsortedBricks.find(key);
    if (foundBrick != unsortedBricks.end())
    {
        pair<string, string> nextBrick;
        nextBrick.first = foundBrick->first;
        nextBrick.second = foundBrick->second;

        // Deletes found brick, so less elements to iterate as time goes on
        this->unsortedBricks.erase(foundBrick);

        return nextBrick;
    }
    else
    {
        return na;
    }
}

void UnorderedMapandList::Easternmost_Sort()
{
    pair<string, string> currentBrick = this->startingBrick;
    this->sortedBricks.push_back(currentBrick.second);
    bool sortingeastwards = true;

    // iterates to the east, stops when there are no more bricks
    while (sortingeastwards)
    {
        currentBrick = Search_Brick(currentBrick.second);
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
    unordered_map<string, string> invertedData;

    for (auto brick : this->unsortedBricks)
    {
        invertedData.insert(std::make_pair(brick.second, brick.first));
    }
    this->unsortedBricks = invertedData;
}
void UnorderedMapandList::Westernmost_Sort()
{
    pair<string, string> currentBrick = this->startingBrick;
    bool sortingwestwards = true;

    // iterates to the west, stops when there are no more bricks
    while (sortingwestwards)
    {
        currentBrick = Search_Brick(currentBrick.second);
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
void UnorderedMapandList::Display_Wall()
{
    for (auto brick : this->sortedBricks)
    {
        std::cout << brick << std::endl;
    }
}

//SECOND IMPLEMENTATION: Map and list

class MapandList
{
public:
    void Timing_Map_List(string);
    void Sort_Bricks();
    void Display_Wall();
    MapandList(string);
    void Form_Brick();
    void Pair_Inversion();
    void Easternmost_Sort();
    void Westernmost_Sort();
    string fileName;
    map<string, string> unsortedBricks;
    list<string> sortedBricks;
    pair<string, string> startingBrick;
    pair<string, string> Search_Brick(string);
};


MapandList::MapandList(string fileName)
{
   this->fileName = fileName;
   this->startingBrick.first = "";
   this->startingBrick.second = "";
   Form_Brick();
}

void MapandList::Form_Brick()
{
   this->unsortedBricks.clear();

   std::ifstream inputPairsFile;
   inputPairsFile.open(fileName);

   string line;
   string north;
   string south;

   while (std::getline(inputPairsFile, line))
   {
       std::istringstream ss(line);
       std::getline(ss, north, ',');
       std::getline(ss, south, ',');

       if (startingBrick.first == "")
       {
           this->startingBrick.first = north;
           this->startingBrick.second = south;
       }
       this->unsortedBricks.insert(std::make_pair(north, south));
   }
   inputPairsFile.close();
}

pair<string, string> MapandList::Search_Brick(string key)
{
   auto na = std::make_pair("","");

   auto foundBrick = this->unsortedBricks.find(key);
   if (foundBrick != unsortedBricks.end())
   {
       pair<string, string> nextBrick;
       nextBrick.first = foundBrick->first;
       nextBrick.second = foundBrick->second;

       // Deletes found brick, so less elements to iterate as time goes on: theoretically shouldt make a difference

       this->unsortedBricks.erase(foundBrick);
       return nextBrick;
   }
   // not found
   else
   {
       return na;
   }
}

void MapandList::Easternmost_Sort()
{
   pair<string, string> currentBrick = this->startingBrick;
   this->sortedBricks.push_back(currentBrick.second);
   bool sortingeastwards = true;

   // iterates to the east, stops when there are no more bricks
   while (sortingeastwards)
   {
       currentBrick = Search_Brick(currentBrick.second);
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
void MapandList::Pair_Inversion()
{
   map<string, string> invertedData;

   for (auto brick : this->unsortedBricks)
   {
       invertedData.insert(std::make_pair(brick.second, brick.first));
   }
   this->unsortedBricks = invertedData;
}
void MapandList::Westernmost_Sort()
{
   pair<string, string> currentBrick = this->startingBrick;
   bool sortingwestwards = true;

   // iterates to the west, stops when there are no more bricks
   while (sortingwestwards)
   {
       currentBrick = Search_Brick(currentBrick.second);
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

void MapandList::Sort_Bricks()
{
   // Sorts the bricks going East
   Easternmost_Sort();

   //invert pairs for western sort
   Pair_Inversion();

   // Sorts the bricks going West
   Westernmost_Sort();

}
void MapandList::Display_Wall()
{
   for (auto brick : this->sortedBricks)
   {
       std::cout << brick << std::endl;
   }
}


//TASK 4 FUNCTIONS

void UnorderedMapandList::Timing_UnorderedMap_List(string fileName)
{

   auto t1 = std::chrono::high_resolution_clock::now();

   UnorderedMapandList *dict = new UnorderedMapandList(fileName);

   dict->Sort_Bricks();

   auto t2 = std::chrono::high_resolution_clock::now();

   duration<double, std::milli> ms_double = t2 - t1;

   std::cout << "sorting bricks with UnorderedMap and list took: "
              << ms_double.count()
              << " milliseconds" << std::endl;

}

void MapandList::Timing_Map_List(string fileName)
{
   auto t1 = std::chrono::high_resolution_clock::now();

   MapandList *dict = new MapandList(fileName);

   dict->Sort_Bricks();

   auto t2 = std::chrono::high_resolution_clock::now();

   duration<double, std::milli> ms_double = t2 - t1;

   std::cout << "sorting bricks with Map and list took: "
              << ms_double.count()
              << " milliseconds" << std::endl;

}


//TASK 3 MAIN FUNCTION

int main(int argc, char *argv[])
{
    //uncomment the 3 lines underneath to run Unordered_map and list implementation
    UnorderedMapandList *theUnorderedMapList = new UnorderedMapandList(argv[1]);
    theUnorderedMapList->Sort_Bricks();
    theUnorderedMapList->Display_Wall();

    //uncomment the 3 lines underneath to run map and list implementation
    //MapandList *theMapandList = new MapandList(argv[1]);
    //theMapandList->Sort_Bricks();
    //theMapandList->Display_Wall();

    return 0;
}


//TASK 4 MAIN FUNCTION

/*
int main(int argc, char *argv[])
{
    //uncomment the 2 lines underneath to run timing unorderedmap and list implementation
    UnorderedMapandList *theUnorderedMapList = new UnorderedMapandList(argv[1]);
    theUnorderedMapList->Timing_UnorderedMap_List(argv[1]);


    //uncomment the 2 lines underneath to run timing map and list implementation
    //MapandList *theMapandList = new MapandList(argv[1]);
    //theMapandList->Timing_Map_List(argv[1]);

    return 0;
}
*/
