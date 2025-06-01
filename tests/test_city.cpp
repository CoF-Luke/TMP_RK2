/* #include <city.h>
#include <xmlvisitor.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;

class MockxmlVisitor : public xmlVisitor
{
public:
    MOCK_METHOD(void, cityVisitor, (City* city), (override));
};

TEST(CityTest, Accept)
{
    MockxmlVisitor visitor;
    City c1("tehran", 1, 2, 100);
    EXPECT_CALL(visitor, cityVisitor(_)).Times(1);
    c1.accept(&visitor);
}
 */