#include <city.h>
#include <house.h>
#include <industry.h>
#include <xmlvisitor.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;

class MockxmlVisitor : public xmlVisitor
{
public:
    MOCK_METHOD(void, cityVisitor, (City* city), (override));
    MOCK_METHOD(void, houseVisitor, (House* house), (override));
    MOCK_METHOD(void, industryVisitor, (Industry* industry), (override));
};

class MockHouse : public House
{
public:
    MOCK_METHOD(int, getStairs(), (City* city), (override));
};

TEST(CityTest, Accept)
{
    MockxmlVisitor visitor;
    City c1("tehran", 1, 2, 100);
    EXPECT_CALL(visitor, cityVisitor(_)).Times(1);
    c1.accept(&visitor);
}

TEST(HouseTest, Accept)
{
    MockxmlVisitor visitor;
    MockHouse h1(3, 2, 3);
    EXPECT_CALL(visitor, houseVisitor(_)).Times(1);
    EXPECT_CALL(h1, getStairs()).Times(1);
    h1.accept(&visitor);
}

TEST(HouseTest, Accept)
{
    House h1(3, 2, 3);
    EXPECT_EQ(h1.getStairs(), 3);
}

/* TEST(HouseTest, Accept)
{
    MockHouse h1(3, 2, 3);
    EXPECT_CALL(h1, getStairs()).Times(1);
    h1.accept(&visitor);
} */

TEST(IndustryTests, Accept)
{
    MockxmlVisitor visitor;
    Industry i1("cast", 100, 1, 3);
    EXPECT_CALL(visitor, industryVisitor(_)).Times(1);
    i1.accept(&visitor);
}

