// This file is part of Tempest-math project
// Author: Karol Kontny

#define GTEST_LANG_CXX11 1 //Workaround for GTest bug

#include "gtest/gtest.h"
#include "tstmath.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
