#include <industry.h>
#include <xmlvisitor.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;

class MockxmlVisitor : public xmlVisitor
{
public:
    MOCK_METHOD(void, industryVisitor, (Industry* industry), (override));
};

TEST(IndustryTests, Accept)
{
    MockxmlVisitor visitor;
    Industry i1("cast", 100, 1, 3);
    EXPECT_CALL(visitor, industryVisitor(_)).Times(1);
    i1.accept(&visitor);
}
