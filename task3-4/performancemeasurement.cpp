#include <iostream>
#include <chrono>
#include <fstream>
#include <string>

#include "unordered_map-and-list.h"
#include "map-and-list.h"


using std::chrono::steady_clock;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;
using std::ofstream;
using std::string;

void UnorderedMapandList::Timing_UnorderedMap_List(std::string fileName)
{
   UnorderedMapandList *dict = new UnorderedMapandList(fileName);

   auto t1 = std::chrono::high_resolution_clock::now();

   dict->Sort_Bricks();

   auto t2 = std::chrono::high_resolution_clock::now();

   std::cout << "sorting bricks with UnorderedMap and list took: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
              << " nanoseconds" << std::endl;

}

void MapandList::Timing_Map_List(std::string fileName)
{
   MapandList *dict = new MapandList(fileName);

   auto t1 = std::chrono::high_resolution_clock::now();

   dict->Sort_Bricks();

   auto t2 = std::chrono::high_resolution_clock::now();

   std::cout << "sorting bricks with Map and list took: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
              << " nanoseconds" << std::endl;

}
