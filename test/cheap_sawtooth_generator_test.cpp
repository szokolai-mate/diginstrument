#include <gtest/gtest.h>
#include <cmath>

#include <CheapSawtoothGenerator.h>

#define FREQUENCY 440
#define CHANNELS 2
#define SAMPLE_RATE 48000

namespace
{
class CheapSawtoothGeneratorTest : public ::testing::Test
{
  protected:
    virtual void SetUp() {}
    virtual void TearDown() {}

    Mixer::CheapSawtoothGenerator<float> generator;
  public:
    CheapSawtoothGeneratorTest():generator(FREQUENCY,CHANNELS,SAMPLE_RATE){}
};
TEST_F(CheapSawtoothGeneratorTest, getFrequency)
{
    EXPECT_EQ(FREQUENCY,generator.getFrequency());
}

TEST_F(CheapSawtoothGeneratorTest, setFrequency)
{
    float testFrequency = 55.78f;
    generator.setFrequency(testFrequency);
    EXPECT_EQ(testFrequency,generator.getFrequency());
}

TEST_F(CheapSawtoothGeneratorTest, setFrequencyWithTransition)
{
    float testFrequency = 55.78f;
    float seconds = 1;
    generator.setFrequency(testFrequency,seconds);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
}

TEST_F(CheapSawtoothGeneratorTest, differentTransitionMethods)
{
    float seconds = 1;

    float testFrequency = 55.78f;

    generator.setFrequency(testFrequency,seconds,"ease-in",2);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
    testFrequency-=1;
    generator.setFrequency(testFrequency,seconds,"ease-in",3);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
    testFrequency-=1;
    generator.setFrequency(testFrequency,seconds,"ease-in",4);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
    testFrequency-=1;
    generator.setFrequency(testFrequency,seconds,"ease-in",5);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
    testFrequency-=1;

    generator.setFrequency(testFrequency,seconds,"ease-out",2);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
    testFrequency-=1;
    generator.setFrequency(testFrequency,seconds,"ease-out",3);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
    testFrequency-=1;
    generator.setFrequency(testFrequency,seconds,"ease-out",4);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
    testFrequency-=1;
    generator.setFrequency(testFrequency,seconds,"ease-out",5);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
    testFrequency-=1;
 
    generator.setFrequency(testFrequency,seconds,"ease-in-out",2);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
    testFrequency-=1;
    generator.setFrequency(testFrequency,seconds,"ease-in-out",3);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
    testFrequency-=1;
    generator.setFrequency(testFrequency,seconds,"ease-in-out",4);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
    testFrequency-=1;
    generator.setFrequency(testFrequency,seconds,"ease-in-out",5);
    generator.get(CHANNELS*SAMPLE_RATE*seconds);
    EXPECT_EQ(testFrequency,generator.getFrequency());
}

TEST_F(CheapSawtoothGeneratorTest, getSize)
{
    int testSize = 512;
    auto vec = generator.get(testSize*CHANNELS);
    EXPECT_EQ(vec.size(),testSize*CHANNELS);
    testSize = 499;
    vec = generator.get(testSize*CHANNELS);
    EXPECT_EQ(vec.size(),testSize*CHANNELS);
    testSize = 107;
    vec = generator.get(testSize*CHANNELS);
    EXPECT_EQ(vec.size(),testSize*CHANNELS);
}
};