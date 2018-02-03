#include <gtest/gtest.h>

#include <Instrument.h>
#include <Note.h>

namespace
{
class SimpleInstrumentTest : public ::testing::Test
{
  protected:
    virtual void SetUp() {}
    virtual void TearDown() {}

};

TEST_F(SimpleInstrumentTest, add)
{
    Instrument::Simple<float> instrument;
    Instrument::Note::Baked<float> testnote;

    auto res = instrument.getNoteset();
    EXPECT_EQ(res.size(),0);

    instrument.add(testnote,"testNote");

    res = instrument.getNoteset();  
    EXPECT_EQ(res.size(),1);
}

TEST_F(SimpleInstrumentTest, remove)
{
    Instrument::Simple<float> instrument;
    Instrument::Note::Baked<float> testnote;
    Instrument::Note::Baked<float> testnote2;

    auto res = instrument.getNoteset();
    EXPECT_EQ(res.size(),0);

    instrument.add(testnote,"testNote");
    instrument.add(testnote2,"remove");

    res = instrument.getNoteset();  
    EXPECT_EQ(res.size(),2);

    instrument.remove("remove");

    res = instrument.getNoteset();  
    EXPECT_EQ(res.size(),1);
}

TEST_F(SimpleInstrumentTest, play)
{
    //! \todo TODO
    EXPECT_EQ(0,1);
}

};