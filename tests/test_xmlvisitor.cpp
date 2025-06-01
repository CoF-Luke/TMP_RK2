#include <city.h>
#include <house.h>
#include <industry.h>
#include <visitor.h>
#include <xmlvisitor.h>

#include <vector>
#include <iostream>
#include <sstream>
#include <gtest/gtest.h>

TEST(MainTest, OutputToConsole) {
    std::streambuf* oldCout = std::cout.rdbuf();
    std::stringstream capture;
    std::cout.rdbuf(capture.rdbuf());

    std::vector<Place*> mapItems;
    City c1("tehran", 1, 2, 100);
    mapItems.push_back(&c1);
    House h1(3, 2, 3);
    mapItems.push_back(&h1);
    Industry i1("cast", 100, 1, 3);
    mapItems.push_back(&i1);
    xmlVisitor xml;

    for(auto it = mapItems.begin(); it != mapItems.end(); it++)
    {
        (*it)->accept(&xml);
    }

    std::cout.rdbuf(oldCout);

    std::string output = capture.str();
    EXPECT_EQ(output.find("Hello, world!"), "3");

    std::cout << "Expected: 3 \nOutput: " << output << std::endl; 
}