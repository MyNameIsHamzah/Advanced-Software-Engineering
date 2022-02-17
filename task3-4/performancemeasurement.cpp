#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <limits>
#include "unordered_map-and-list.h"
#include "map-and-list.h"


using std::chrono::steady_clock;
using std::chrono::milliseconds;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::ofstream;
using std::string;

void UnorderedMapandList::Timing_UnorderedMap_List(std::string fileName)
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

void MapandList::Timing_Map_List(std::string fileName)
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
