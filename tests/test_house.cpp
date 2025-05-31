#include <house.h>
#include <xmlvisitor.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;

class MockxmlVisitor : public xmlVisitor
{
public:
    MOCK_METHOD(void, houseVisitor, (House* house), (override));
};

TEST(HouseTest, Accept)
{
    MockxmlVisitor visitor;
    House h1(3, 2, 3);
    EXPECT_CALL(visitor, houseVisitor(_)).Times(1);
    h1.accept(&visitor);
}
