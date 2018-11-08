//
//  main.cpp
//  MidtermProgram
//
//  Created by Mason Fisher on 10/18/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "mapTypes.h"


int main(int argc, const char * argv[]) {
    DoubleLinked list;
    Validation check;
    list.load();
    list.print();
    check.out("Please input the name of the city that you will start at.");
    string name = check.word();
    DoubleLinked newList(name,list);
    check.out("Please input the name of the city you'd like to visit.");
    name = check.word();
    check.out("The distance to " + name + " is " + to_string(newList.getDistance(name)) + " miles.");
    return 0;
}
