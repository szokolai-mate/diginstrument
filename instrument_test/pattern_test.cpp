#include <gtest/gtest.h>

#include <Pattern.h>

namespace
{
class PatternTest : public ::testing::Test
{
  protected:
    virtual void SetUp() {}
    virtual void TearDown() {}

};
TEST_F(PatternTest, serialize)
{
    Composition::Note first("first");
    Composition::Note second("second");
    Composition::Note third("third");
    Composition::Note fourth("fourth");

    Composition::Pattern second_to_fourth;
    Composition::Pattern second_to_third;
    
    second_to_fourth.add(second,1);
    second_to_fourth.add(third,1.1f);
    second_to_fourth.add(fourth,2);

    second_to_third.add(second,1);
    second_to_third.add(third,1.1f);

    Composition::Pattern main;

    main.add(first,0);
    main.add(second_to_fourth,0);
    main.add(second_to_third,1);
    main.add(first,0);


    auto res = main.serialize();
    bool b = true;
    float max = res[0].first;
    for(auto a : res){
        b= max<=a.first;
    }
    EXPECT_TRUE(b);
    EXPECT_EQ(res[0].second,"first");
}

TEST_F(PatternTest, remove)
{
    Composition::Note first("first");
    Composition::Note second("second");
    Composition::Note third("third");
    Composition::Note fourth("fourth");

    Composition::Pattern second_to_fourth;
    Composition::Pattern second_to_third;
    
    second_to_fourth.add(second,1);
    second_to_fourth.add(third,1.1f);
    second_to_fourth.add(fourth,2);

    second_to_third.add(second,1);
    second_to_third.add(third,1.1f);

    Composition::Pattern main;

    main.add(first,0);
    main.add(second_to_fourth,0);
    main.add(second_to_third,1);

    main.remove(first,0);
    main.remove(second_to_third,1);

    auto res = main.serialize();
    bool b = true;
    float max = res[0].first;
    for(auto a : res){
        b= max<=a.first;
    }
    EXPECT_TRUE(b);
    EXPECT_EQ(3,res.size());
    EXPECT_NE(res[0].second,"first");
}


TEST_F(PatternTest, multisetRemove)
{
    Composition::Note first("first");
    Composition::Note second("second");
    Composition::Note third("third");
    Composition::Note fourth("fourth");

    Composition::Pattern second_to_fourth;
    Composition::Pattern second_to_third;
    
    second_to_fourth.add(second,1);
    second_to_fourth.add(third,1.1f);
    second_to_fourth.add(fourth,2);

    second_to_third.add(second,1);
    second_to_third.add(third,1.1f);

    Composition::Pattern main;

    main.add(first,0);
    main.add(first,0);
    main.add(second_to_fourth,0);
    main.add(second_to_third,1);

    main.remove(first,0);
    main.remove(second_to_third,1);

    auto res = main.serialize();
    bool b = true;
    float max = res[0].first;
    for(auto a : res){
        b= max<=a.first;
    }
    EXPECT_TRUE(b);
    EXPECT_EQ(4,res.size());
    EXPECT_EQ(res[0].second,"first");
}

TEST_F(PatternTest, getLength)
{
    Composition::Note first("first");
    Composition::Note second("second");
    Composition::Note third("third");
    Composition::Note fourth("fourth");
    Composition::Note longnote("long",20);

    Composition::Pattern second_to_fourth;
    Composition::Pattern second_to_third;
    
    second_to_fourth.add(second,1);
    second_to_fourth.add(third,1.1f);
    second_to_fourth.add(fourth,2);
    second_to_fourth.add(longnote,1);

    second_to_third.add(second,1);
    second_to_third.add(third,1.1f);

    Composition::Pattern main;

    main.add(first,0);
    main.add(longnote,20);
    main.add(second_to_fourth,0);
    main.add(second_to_third,1);

    EXPECT_EQ(main.getLength(),40);

    main.remove(longnote,20);

    EXPECT_EQ(main.getLength(),21);
}

};