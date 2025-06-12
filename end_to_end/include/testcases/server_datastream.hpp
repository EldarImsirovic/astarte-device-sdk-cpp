// (C) Copyright 2025, SECO Mind Srl
//
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "case.hpp"
#include "constants/astarte_interfaces.hpp"

namespace testcases {
TestCase server_datastream() {
  return TestCase(
      "Astarte to device",
      std::vector<std::shared_ptr<TestAction>>{
          TestActionConnect::Create(),
          TestActionSleep::Create(std::chrono::seconds(1)),
          TestActionTransmitRESTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/integer_endpoint",
                             AstarteDatastreamIndividual(AstarteData((int32_t)43)))),
          TestActionTransmitRESTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/longinteger_endpoint",
                             AstarteDatastreamIndividual(AstarteData((int64_t)17179869184)))),
          TestActionTransmitRESTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/double_endpoint",
                             AstarteDatastreamIndividual(AstarteData(4245.23)))),
          TestActionTransmitRESTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/boolean_endpoint",
                             AstarteDatastreamIndividual(AstarteData(false)))),
          TestActionTransmitRESTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/string_endpoint",
                             AstarteDatastreamIndividual(AstarteData(std::string("Hello world"))))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/datetime_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::chrono::system_clock::time_point(
                  std::chrono::sys_days(std::chrono::year_month_day(
                      std::chrono::year(1994), std::chrono::month(4), std::chrono::day(12))) +
                  std::chrono::hours(10) + std::chrono::minutes(15) + std::chrono::seconds(0)))))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/binaryblob_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::vector<uint8_t>{0x23, 0x43, 0xF5})))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/integerarray_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::vector<int32_t>{32, 43, 0, 3332})))),
          TestActionTransmitRESTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/longintegerarray_endpoint",
                             AstarteDatastreamIndividual(
                                 AstarteData(std::vector<int64_t>{17179869184, 0, 6486})))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/doublearray_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::vector<double>{0.0, 23.2})))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/booleanarray_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::vector<bool>{false, true, true})))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/stringarray_endpoint",
              AstarteDatastreamIndividual(
                  AstarteData(std::vector<std::string>{"Hello ", "world ", "from ", "C++"})))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/datetimearray_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::vector<
                                                      std::chrono::system_clock::time_point>{
                  std::chrono::sys_days(std::chrono::year_month_day(
                      std::chrono::year(1994), std::chrono::month(4), std::chrono::day(12))) +
                      std::chrono::hours(10) + std::chrono::minutes(15) + std::chrono::seconds(0),
                  std::chrono::sys_days(std::chrono::year_month_day(
                      std::chrono::year(1985), std::chrono::month(5), std::chrono::day(22))) +
                      std::chrono::hours(0) + std::chrono::minutes(0) + std::chrono::seconds(12),
              })))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/binaryblobarray_endpoint",
              AstarteDatastreamIndividual(AstarteData(
                  std::vector<std::vector<uint8_t>>{{0x23, 0x43, 0xF5}, {0x43, 0xF3, 0x00}})))),
          TestActionSleep::Create(std::chrono::seconds(1)),
          TestActionReadReceivedMQTTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/integer_endpoint",
                             AstarteDatastreamIndividual(AstarteData((int32_t)43)))),
          TestActionReadReceivedMQTTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/longinteger_endpoint",
                             AstarteDatastreamIndividual(AstarteData((int64_t)17179869184)))),
          TestActionReadReceivedMQTTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/double_endpoint",
                             AstarteDatastreamIndividual(AstarteData(4245.23)))),
          TestActionReadReceivedMQTTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/boolean_endpoint",
                             AstarteDatastreamIndividual(AstarteData(false)))),
          TestActionReadReceivedMQTTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/string_endpoint",
                             AstarteDatastreamIndividual(AstarteData(std::string("Hello world"))))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/datetime_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::chrono::system_clock::time_point(
                  std::chrono::sys_days(std::chrono::year_month_day(
                      std::chrono::year(1994), std::chrono::month(4), std::chrono::day(12))) +
                  std::chrono::hours(10) + std::chrono::minutes(15) + std::chrono::seconds(0)))))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/binaryblob_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::vector<uint8_t>{0x23, 0x43, 0xF5})))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/integerarray_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::vector<int32_t>{32, 43, 0, 3332})))),
          TestActionReadReceivedMQTTData::Create(
              AstarteMessage(astarte_interfaces::SERVER_DATASTREAM, "/longintegerarray_endpoint",
                             AstarteDatastreamIndividual(
                                 AstarteData(std::vector<int64_t>{17179869184, 0, 6486})))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/doublearray_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::vector<double>{0.0, 23.2})))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/booleanarray_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::vector<bool>{false, true, true})))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/stringarray_endpoint",
              AstarteDatastreamIndividual(
                  AstarteData(std::vector<std::string>{"Hello ", "world ", "from ", "C++"})))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/datetimearray_endpoint",
              AstarteDatastreamIndividual(AstarteData(std::vector<
                                                      std::chrono::system_clock::time_point>{
                  std::chrono::sys_days(std::chrono::year_month_day(
                      std::chrono::year(1994), std::chrono::month(4), std::chrono::day(12))) +
                      std::chrono::hours(10) + std::chrono::minutes(15) + std::chrono::seconds(0),
                  std::chrono::sys_days(std::chrono::year_month_day(
                      std::chrono::year(1985), std::chrono::month(5), std::chrono::day(22))) +
                      std::chrono::hours(0) + std::chrono::minutes(0) + std::chrono::seconds(12),
              })))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::SERVER_DATASTREAM, "/binaryblobarray_endpoint",
              AstarteDatastreamIndividual(AstarteData(
                  std::vector<std::vector<uint8_t>>{{0x23, 0x43, 0xF5}, {0x43, 0xF3, 0x00}})))),
          TestActionSleep::Create(std::chrono::seconds(1)),
          TestActionDisconnect::Create(),
          TestActionSleep::Create(std::chrono::seconds(1))});
}
}  // namespace testcases
