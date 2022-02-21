#include "unordered_map-and-list.h"
#include "map-and-list.h"

#include <iostream>
#include <string>

//TASK3

int main(int argc, char *argv[])
{
    //Unordered_map and list implementation
    UnorderedMapandList *theUnorderedMapList = new UnorderedMapandList(argv[1]);
    theUnorderedMapList->Sort_Bricks();
    theUnorderedMapList->Print_Sorted_Bricks();

    //map and list implementation
    //MapandList *theMapandList = new MapandList(argv[1]);
    //theMapandList->Sort_Bricks();
    //theMapandList->Print_Sorted_Bricks();

    return 0;
}


//TASK4

/*
int main(int argc, char *argv[])
{
    //timing unorderedmap and list implementation
    UnorderedMapandList *theUnorderedMapList = new UnorderedMapandList(argv[1]);
    theUnorderedMapList->Timing_UnorderedMap_List(argv[1]);


    //timing map and list implementation
    //MapandList *theMapandList = new MapandList(argv[1]);
    //theMapandList->Timing_Map_List(argv[1]);

    return 0;
}
*/
