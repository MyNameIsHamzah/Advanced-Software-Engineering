#include "unordered_map-and-list.h"
#include "map-and-list.h"

#include <iostream>
#include <string>

/*int main(int argc, char *argv[])
{
   // UnorderedMapandList *myUnorderedMapList = new UnorderedMapandList(argv[1]);
   // myUnorderedMapList->Sort_Bricks();
    //myUnorderedMapList->Print_Sorted_Bricks();

    MapandList *myMapandList = new MapandList(argv[1]);
    myMapandList->Sort_Bricks();
    myMapandList->Print_Sorted_Bricks();

    return 0;
}*/

int main(int argc, char *argv[])
{
   /* //timing unorderedmap and list implementation
    UnorderedMapandList *myUnorderedMapList = new UnorderedMapandList(argv[1]);
    myUnorderedMapList->Timing_UnorderedMap_List(argv[1]);
*/

    //timing map and list implementation
    MapandList *myMapandList = new MapandList(argv[1]);
    myMapandList->Timing_Map_List(argv[1]);

    return 0;
}
