// (C) Copyright 2025, SECO Mind Srl
//
// SPDX-License-Identifier: Apache-2.0

#include "astarte_device_sdk/data.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <chrono>
#include <vector>

using AstarteDeviceSdk::AstarteData;
using AstarteDeviceSdk::AstarteType;

using testing::ContainerEq;

TEST(DataTest, InstantiationInteger) {
  int32_t value = 52;
  auto data = AstarteData(value);
  auto original = data.into<int32_t>();
  EXPECT_EQ(value, original);
}
TEST(DataTest, FormatInteger) {
  int32_t value = 52;
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "52");
}

TEST(DataTest, InstantiationLongInteger) {
  int64_t value = 52;
  auto data = AstarteData(value);
  auto original = data.into<int64_t>();
  EXPECT_EQ(value, original);
}
TEST(DataTest, FormatLongInteger) {
  int64_t value = 52;
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "52");
}

TEST(DataTest, InstantiationDouble) {
  double value = 43.5;
  auto data = AstarteData(value);
  auto original = data.into<double>();
  EXPECT_FLOAT_EQ(value, original);
}
TEST(DataTest, FormatDouble) {
  double value = 43.5;
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "43.5");
}

TEST(DataTest, InstantiationBoolean) {
  bool value = true;
  auto data = AstarteData(value);
  auto original = data.into<bool>();
  EXPECT_EQ(value, original);
}
TEST(DataTest, FormatBoolean) {
  bool value = true;
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "true");
}

TEST(DataTest, InstantiationString) {
  std::string value = "Test string";
  auto data = AstarteData(value);
  auto original = data.into<std::string>();
  EXPECT_STREQ(value.c_str(), original.c_str());
}
TEST(DataTest, FormatString) {
  std::string value = "Test string";
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "\"Test string\"");
}

TEST(DataTest, InstantiationBinaryBlob) {
  std::vector<uint8_t> value = {0x12U, 0x22U, 0x42};
  auto data = AstarteData(value);
  auto original = data.into<std::vector<uint8_t>>();
  EXPECT_THAT(value, ContainerEq(original));
}
TEST(DataTest, FormatBinaryBlob) {
  std::vector<uint8_t> value = {0x12U, 0x22U, 0x42};
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "\"EiJC\"");
}

TEST(DataTest, InstantiationDatetime) {
#if __cplusplus >= 202002L
  std::chrono::system_clock::time_point value =
      std::chrono::sys_days(std::chrono::year_month_day(
          std::chrono::year(1994), std::chrono::month(4), std::chrono::day(12))) +
      std::chrono::hours(10) + std::chrono::minutes(15) + std::chrono::seconds(0);
#else   // __cplusplus >= 202002L
  std::tm dtm = {};
  dtm.tm_year = 1994 - 1900;
  dtm.tm_mon = 4 - 1;
  dtm.tm_mday = 12;
  dtm.tm_hour = 10;
  dtm.tm_min = 15;
  dtm.tm_sec = 0;
  std::time_t time = std::mktime(&dtm);
  std::chrono::system_clock::time_point value = std::chrono::system_clock::from_time_t(time);
#endif  // __cplusplus >= 202002L
  auto data = AstarteData(value);
  auto original = data.into<std::chrono::system_clock::time_point>();
  EXPECT_EQ(value, original);
}
TEST(DataTest, FormatDatetime) {
#if __cplusplus >= 202002L
  std::chrono::system_clock::time_point value =
      std::chrono::sys_days(std::chrono::year_month_day(
          std::chrono::year(1994), std::chrono::month(4), std::chrono::day(12))) +
      std::chrono::hours(10) + std::chrono::minutes(15) + std::chrono::seconds(0);
#else   // __cplusplus >= 202002L
  std::tm dtm = {};
  dtm.tm_year = 1994 - 1900;
  dtm.tm_mon = 4 - 1;
  dtm.tm_mday = 12;
  dtm.tm_hour = 10;
  dtm.tm_min = 15;
  dtm.tm_sec = 0;
  std::time_t time = std::mktime(&dtm);
  std::chrono::system_clock::time_point value = std::chrono::system_clock::from_time_t(time);
#endif  // __cplusplus >= 202002L
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "\"1994-04-12T10:15:00.000Z\"");
}

TEST(DataTest, InstantiationIntegerArray) {
  std::vector<int32_t> value{12, 43, 11, 0};
  auto data = AstarteData(value);
  auto original = data.into<std::vector<int32_t>>();
  EXPECT_THAT(original, ContainerEq(value));
}
TEST(DataTest, FormatIntegerArray) {
  std::vector<int32_t> value{12, 43, 11, 0};
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "[12, 43, 11, 0]");
}

TEST(DataTest, InstantiationLongIntegerArray) {
  std::vector<int64_t> value{0, 8589934592, 11};
  auto data = AstarteData(value);
  auto original = data.into<std::vector<int64_t>>();
  EXPECT_THAT(original, ContainerEq(value));
}
TEST(DataTest, FormatLongIntegerArray) {
  std::vector<int64_t> value{0, 8589934592, 11};
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "[0, 8589934592, 11]");
}

TEST(DataTest, InstantiationDoubleArray) {
  std::vector<double> value{0.0, 43.2};
  auto data = AstarteData(value);
  auto original = data.into<std::vector<double>>();
  EXPECT_THAT(original, ContainerEq(value));
}
TEST(DataTest, FormatDoubleArray) {
  std::vector<double> value{0.0, 43.2};
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "[0, 43.2]");
}

TEST(DataTest, InstantiationBooleanArray) {
  std::vector<bool> value{true, false, false};
  auto data = AstarteData(value);
  auto original = data.into<std::vector<bool>>();
  EXPECT_THAT(original, ContainerEq(value));
}
TEST(DataTest, FormatBooleanArray) {
  std::vector<bool> value{true, false, false};
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "[true, false, false]");
}

TEST(DataTest, InstantiationStringArray) {
  std::vector<std::string> value{"Hello", "C++"};
  auto data = AstarteData(value);
  auto original = data.into<std::vector<std::string>>();
  EXPECT_THAT(original, ContainerEq(value));
}
TEST(DataTest, FormatStringArray) {
  std::vector<std::string> value{"Hello", "C++"};
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "[\"Hello\", \"C++\"]");
}

TEST(DataTest, InstantiationBinaryBlobArray) {
  std::vector<std::vector<uint8_t>> value{{0x12U, 0x22U, 0x42}, {0x10U, 0x8FU}};
  auto data = AstarteData(value);
  auto original = data.into<std::vector<std::vector<uint8_t>>>();
  EXPECT_THAT(original, ContainerEq(value));
}
TEST(DataTest, FormatBinaryBlobArray) {
  std::vector<std::vector<uint8_t>> value{{0x12U, 0x22U, 0x42}, {0x10U, 0x8FU}};
  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "[\"EiJC\", \"EI8=\"]");
}

TEST(DataTest, InstantiationDatetimeArray) {
#if __cplusplus >= 202002L
  std::chrono::system_clock::time_point datetime0 =
      std::chrono::sys_days(std::chrono::year_month_day(
          std::chrono::year(1994), std::chrono::month(4), std::chrono::day(12))) +
      std::chrono::hours(10) + std::chrono::minutes(15) + std::chrono::seconds(0);
  std::chrono::system_clock::time_point datetime1 =
      std::chrono::sys_days(std::chrono::year_month_day(
          std::chrono::year(1984), std::chrono::month(5), std::chrono::day(2))) +
      std::chrono::hours(10) + std::chrono::minutes(15) + std::chrono::seconds(0);
  std::vector<std::chrono::system_clock::time_point> value{datetime0, datetime1};
#else   // __cplusplus >= 202002L
  std::tm tm0 = {};
  tm0.tm_year = 1994 - 1900;
  tm0.tm_mon = 4 - 1;
  tm0.tm_mday = 12;
  tm0.tm_hour = 10;
  tm0.tm_min = 15;
  tm0.tm_sec = 0;
  std::time_t time0 = std::mktime(&tm0);
  std::tm tm1 = {};
  tm1.tm_year = 1984 - 1900;
  tm1.tm_mon = 5 - 1;
  tm1.tm_mday = 2;
  tm1.tm_hour = 10;
  tm1.tm_min = 15;
  tm1.tm_sec = 0;
  std::time_t time1 = std::mktime(&tm1);
  std::vector<std::chrono::system_clock::time_point> value{
      std::chrono::system_clock::from_time_t(time0), std::chrono::system_clock::from_time_t(time1)};
#endif  // __cplusplus >= 202002L
  auto data = AstarteData(value);
  auto original = data.into<std::vector<std::chrono::system_clock::time_point>>();
  EXPECT_THAT(original, ContainerEq(value));
}
TEST(DataTest, FormatDatetimeArray) {
#if __cplusplus >= 202002L
  std::chrono::system_clock::time_point datetime0 =
      std::chrono::sys_days(std::chrono::year_month_day(
          std::chrono::year(1994), std::chrono::month(4), std::chrono::day(12))) +
      std::chrono::hours(10) + std::chrono::minutes(15) + std::chrono::seconds(0);
  std::chrono::system_clock::time_point datetime1 =
      std::chrono::sys_days(std::chrono::year_month_day(
          std::chrono::year(1984), std::chrono::month(5), std::chrono::day(2))) +
      std::chrono::hours(10) + std::chrono::minutes(15) + std::chrono::seconds(0);
  std::vector<std::chrono::system_clock::time_point> value{datetime0, datetime1};
#else   // __cplusplus >= 202002L
  std::tm tm0 = {};
  tm0.tm_year = 1994 - 1900;
  tm0.tm_mon = 4 - 1;
  tm0.tm_mday = 12;
  tm0.tm_hour = 10;
  tm0.tm_min = 15;
  tm0.tm_sec = 0;
  std::time_t time0 = std::mktime(&tm0);
  std::tm tm1 = {};
  tm1.tm_year = 1984 - 1900;
  tm1.tm_mon = 5 - 1;
  tm1.tm_mday = 2;
  tm1.tm_hour = 10;
  tm1.tm_min = 15;
  tm1.tm_sec = 0;
  std::time_t time1 = std::mktime(&tm1);
  std::vector<std::chrono::system_clock::time_point> value{
      std::chrono::system_clock::from_time_t(time0), std::chrono::system_clock::from_time_t(time1)};
#endif  // __cplusplus >= 202002L

  auto data = AstarteData(value);
  auto str = data.format();
  EXPECT_STREQ(str.c_str(), "[\"1994-04-12T10:15:00.000Z\", \"1984-05-02T10:15:00.000Z\"]");
}
