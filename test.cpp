#include "pch.h"

#define _AFXDLL
#include "..\winralter\stdafx.h"

#include <gtest/gtest.h>

#include "..\winralter\CwrHelper.h"

namespace gtests {
    namespace winralters_test {

            // The fixture for testing class Foo.
            class wrTest : public testing::Test
            {
            protected:
                // You can remove any or all of the following functions if their bodies would
                // be empty.

                wrTest()
                {
                    // You can do set-up work for each test here.
                }

                ~wrTest() override
                {
                    // You can do clean-up work that doesn't throw exceptions here.
                }

                // If the constructor and destructor are not enough for setting up
                // and cleaning up each test, you can define the following methods:

                void SetUp() override
                {
                    // Code here will be called immediately after the constructor (right
                    // before each test).
                }

                void TearDown() override
                {
                    // Code here will be called immediately after each test (right
                    // before the destructor).
                }

                // Class members declared here can be used by all tests in the test suite
                // for Foo.
            };

            winralter::CwrHelper gwrHelper;

            TEST_F(wrTest, GetPermanentConfig)
            {                
                EXPECT_EQ(gwrHelper.GetConfigFilePath(0), "D:\\MyDocs\\winralter.ini"); // 0 = PermanentConfig
            }

            TEST_F(wrTest, GetTemporaryConfig)
            {
                EXPECT_EQ(gwrHelper.GetConfigFilePath(1), "D:\\MyDocs\\devProjects\\cpp\\gtest\\x64\\Debug\\winralter.inf"); // 1 = TemporaryConfig
            }
 
    }  // namespace project
}  // namespace gtests

int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}