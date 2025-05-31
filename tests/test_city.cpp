#include <xmlvisitor.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockxmlVisitor : public xmlVisitor
{
    MOCK_METHOD(void, cityVisitor, (City*), (override));
};

TEST(City, Accept)
{
    MockXmlVisitor visitor;
    City c1("tehran", 1, 2, 100);
    EXPECT_CALL(visitor, cityVisitor).Times(1);
    c1.accept(&visitor);
}
