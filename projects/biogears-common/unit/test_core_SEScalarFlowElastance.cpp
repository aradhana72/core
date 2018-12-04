//-------------------------------------------------------------------------------------------
//- Copyright 2017 Applied Research Associates, Inc.
//- Licensed under the Apache License, Version 2.0 (the "License"); you may not use
//- this file except in compliance with the License. You may obtain a copy of the License
//- at:
//- http://www.apache.org/licenses/LICENSE-2.0
//- Unless required by applicable law or agreed to in writing, software distributed under
//- the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
//- CONDITIONS OF ANY KIND, either express or implied. See the License for the
//-  specific language governing permissions and limitations under the License.
//-------------------------------------------------------------------------------------------
//!
//! @author David Lee
//! @date   2017 Aug 3rd
//!
//! Unit Test for Biogears-common Config
//!
#include <thread>

#include <gtest/gtest.h>

#include <biogears/cdm/properties/SEScalarFlowElastance.h>


#ifdef DISABLE_BIOGEARS_SEScalarFlowElastance_TEST
#define TEST_FIXTURE_NAME DISABLED_SEScalarFlowElastance_Fixture
#else
#define TEST_FIXTURE_NAME SEScalarFlowElastance_Fixture
#endif

// The fixture for testing class Foo.
class TEST_FIXTURE_NAME : public ::testing::Test {
protected:
  // You can do set-up work for each test here.
  TEST_FIXTURE_NAME() = default;

  // You can do clean-up work that doesn't throw exceptions here.
  virtual ~TEST_FIXTURE_NAME() = default;

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  // Code here will be called immediately after the constructor (right
  // before each test).
  virtual void SetUp();

  // Code here will be called immediately after each test (right
  // before the destructor).
  virtual void TearDown();
};

void TEST_FIXTURE_NAME::SetUp()
{
}

void TEST_FIXTURE_NAME::TearDown()
{
}

TEST_F(TEST_FIXTURE_NAME, Unload)
{
  biogears::SEScalarFlowElastance FlowElastance = biogears::SEScalarFlowElastance();
  auto ptr = FlowElastance.Unload();
  EXPECT_EQ(ptr, nullptr);
}

TEST_F(TEST_FIXTURE_NAME, IsValidUnit)
{
  bool unit0 = biogears::FlowElastanceUnit::IsValidUnit("cmH2O/L");
  bool unit1 = biogears::FlowElastanceUnit::IsValidUnit("mmHg/mL");
  bool unit2 = biogears::FlowElastanceUnit::IsValidUnit("Pa/m^3");
  EXPECT_EQ(unit0, true);
  EXPECT_EQ(unit1, true);
  EXPECT_EQ(unit2, true);
  bool unit6 = biogears::FlowElastanceUnit::IsValidUnit("DEADBEEF");
  EXPECT_EQ(unit6, false);
}

TEST_F(TEST_FIXTURE_NAME, GetCompoundUnit)
{
  biogears::FlowElastanceUnit mu0 = biogears::FlowElastanceUnit::GetCompoundUnit("cmH2O/L");
  biogears::FlowElastanceUnit mu1 = biogears::FlowElastanceUnit::GetCompoundUnit("mmHg/mL");
  biogears::FlowElastanceUnit mu2 = biogears::FlowElastanceUnit::GetCompoundUnit("Pa/m^3");
  EXPECT_EQ(mu0, biogears::FlowElastanceUnit::cmH2O_Per_L);
  EXPECT_EQ(mu1, biogears::FlowElastanceUnit::mmHg_Per_mL);
  EXPECT_EQ(mu2, biogears::FlowElastanceUnit::Pa_Per_m3);
  EXPECT_THROW(biogears::FlowElastanceUnit::GetCompoundUnit("DEADBEEF"),biogears::CommonDataModelException);
}