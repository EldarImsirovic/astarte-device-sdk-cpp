// (C) Copyright 2025, SECO Mind Srl
//
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <chrono>

#include "case.hpp"
#include "constants/astarte_interfaces.hpp"
#include "constants/astarte_time.hpp"

namespace testcases {
using namespace std::chrono_literals;

TestCase server_property() {
  return TestCase(
      "Server property to Device",
      std::vector<std::shared_ptr<TestAction>>{
          TestActionConnect::Create(), TestActionSleep::Create(std::chrono::seconds(1)),

          // set server properties
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/integer_endpoint",
              AstartePropertyIndividual(AstarteData(43)))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/longinteger_endpoint",
              AstartePropertyIndividual(AstarteData(17179869184)))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/double_endpoint",
              AstartePropertyIndividual(AstarteData(54.4)))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/boolean_endpoint",
              AstartePropertyIndividual(AstarteData(true)))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/string_endpoint",
              AstartePropertyIndividual(AstarteData(std::string("Hello C++!"))))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/datetime_endpoint",
              AstartePropertyIndividual(AstarteData(std::chrono::system_clock::time_point(
                  std::chrono::sys_days{1994y / 4 / 12} + 10h + 15min))))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/binaryblob_endpoint",
              AstartePropertyIndividual(AstarteData(std::vector<uint8_t>{0x23, 0x43, 0xF5})))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/integerarray_endpoint",
              AstartePropertyIndividual(AstarteData(std::vector<int32_t>{13, 2})))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/longintegerarray_endpoint",
              AstartePropertyIndividual(AstarteData(std::vector<int64_t>{17179869184, 5})))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/doublearray_endpoint",
              AstartePropertyIndividual(AstarteData(std::vector<double>{0.5})))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/booleanarray_endpoint",
              AstartePropertyIndividual(AstarteData(std::vector<bool>{false, true})))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/stringarray_endpoint",
              AstartePropertyIndividual(
                  AstarteData(std::vector<std::string>{"Hello ", "world ", "from ", "C++"})))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/datetimearray_endpoint",
              AstartePropertyIndividual(
                  AstarteData(std::vector<std::chrono::system_clock::time_point>{
                      std::chrono::sys_days{1994y / 4 / 12} + 10h + 15min,
                      std::chrono::sys_days{1985y / 5 / 22} + 12s,
                  })))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/binaryblobarray_endpoint",
              AstartePropertyIndividual(AstarteData(
                  std::vector<std::vector<uint8_t>>{{0x23, 0x43, 0xF5}, {0x43, 0xF3, 0x00}})))),

          TestActionSleep::Create(std::chrono::seconds(1)),

          // check if server property have been set
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/integer_endpoint",
              AstartePropertyIndividual(AstarteData(43)))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/longinteger_endpoint",
              AstartePropertyIndividual(AstarteData(17179869184)))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/double_endpoint",
              AstartePropertyIndividual(AstarteData(54.4)))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/boolean_endpoint",
              AstartePropertyIndividual(AstarteData(true)))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/string_endpoint",
              AstartePropertyIndividual(AstarteData(std::string("Hello C++!"))))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/datetime_endpoint",
              AstartePropertyIndividual(AstarteData(std::chrono::system_clock::time_point(
                  std::chrono::sys_days{1994y / 4 / 12} + 10h + 15min))))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/binaryblob_endpoint",
              AstartePropertyIndividual(AstarteData(std::vector<uint8_t>{0x23, 0x43, 0xF5})))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/integerarray_endpoint",
              AstartePropertyIndividual(AstarteData(std::vector<int32_t>{13, 2})))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/longintegerarray_endpoint",
              AstartePropertyIndividual(AstarteData(std::vector<int64_t>{17179869184, 5})))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/doublearray_endpoint",
              AstartePropertyIndividual(AstarteData(std::vector<double>{0.5})))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/booleanarray_endpoint",
              AstartePropertyIndividual(AstarteData(std::vector<bool>{false, true})))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/stringarray_endpoint",
              AstartePropertyIndividual(
                  AstarteData(std::vector<std::string>{"Hello ", "world ", "from ", "C++"})))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/datetimearray_endpoint",
              AstartePropertyIndividual(
                  AstarteData(std::vector<std::chrono::system_clock::time_point>{
                      std::chrono::sys_days{1994y / 4 / 12} + 10h + 15min,
                      std::chrono::sys_days{1985y / 5 / 22} + 12s,
                  })))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/binaryblobarray_endpoint",
              AstartePropertyIndividual(AstarteData(
                  std::vector<std::vector<uint8_t>>{{0x23, 0x43, 0xF5}, {0x43, 0xF3, 0x00}})))),

          TestActionSleep::Create(std::chrono::seconds(1)),

          // unset server properties
          TestActionTransmitRESTData::Create(
              AstarteMessage(astarte_interfaces::ServerProperty::INTERFACE,
                             "/sensor1/integer_endpoint", AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/longinteger_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(
              AstarteMessage(astarte_interfaces::ServerProperty::INTERFACE,
                             "/sensor1/double_endpoint", AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(
              AstarteMessage(astarte_interfaces::ServerProperty::INTERFACE,
                             "/sensor1/boolean_endpoint", AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(
              AstarteMessage(astarte_interfaces::ServerProperty::INTERFACE,
                             "/sensor1/string_endpoint", AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/datetime_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/binaryblob_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/integerarray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/longintegerarray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/doublearray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/booleanarray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/stringarray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/datetimearray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionTransmitRESTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/binaryblobarray_endpoint",
              AstartePropertyIndividual(std::nullopt))),

          TestActionSleep::Create(std::chrono::seconds(1)),

          // check unset server property
          TestActionReadReceivedMQTTData::Create(
              AstarteMessage(astarte_interfaces::ServerProperty::INTERFACE,
                             "/sensor1/integer_endpoint", AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/longinteger_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(
              AstarteMessage(astarte_interfaces::ServerProperty::INTERFACE,
                             "/sensor1/double_endpoint", AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(
              AstarteMessage(astarte_interfaces::ServerProperty::INTERFACE,
                             "/sensor1/boolean_endpoint", AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(
              AstarteMessage(astarte_interfaces::ServerProperty::INTERFACE,
                             "/sensor1/string_endpoint", AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/datetime_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/binaryblob_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/integerarray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/longintegerarray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/doublearray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/booleanarray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/stringarray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/datetimearray_endpoint",
              AstartePropertyIndividual(std::nullopt))),
          TestActionReadReceivedMQTTData::Create(AstarteMessage(
              astarte_interfaces::ServerProperty::INTERFACE, "/sensor1/binaryblobarray_endpoint",
              AstartePropertyIndividual(std::nullopt))),

          TestActionSleep::Create(std::chrono::seconds(1)), TestActionDisconnect::Create(),
          TestActionSleep::Create(std::chrono::seconds(1))});
}
}  // namespace testcases
