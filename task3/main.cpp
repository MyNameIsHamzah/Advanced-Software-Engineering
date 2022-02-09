#include "unordered_map-and-list.h"


#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    UnorderedMapandList *myUnorderedMapList = new UnorderedMapandList(argv[1]);
    myUnorderedMapList->Sort_Bricks();
    myUnorderedMapList->Print_Sorted_Bricks();

    //MapList *myMapList = new MapList(argv[1]);
    //myMapList->Sort_Bricks();
    //myMapList->Print_Sorted_Bricks();

    //run_Unordered_Map_List_Timing_Tests();
    //run_Map_List_Timing_Tests();

    return 0;
}
