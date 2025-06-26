<!--
Copyright 2025 SECO Mind Srl

SPDX-License-Identifier: Apache-2.0
-->

# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.1.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [unreleased]
### Added
- Method to add a json interface as a string directly, without reading it from a file
- Method to convert an AstarteMessage and AstarteData that returns an std::option instead of an exception

### Changed
- Bump the Astarte message hub proto definitions to v0.8.0

## [0.5.0-beta] - 2025-03-20
### Added
- Initial SDK release, supports connecting to a message hub instance and publish/receive of basic
  Astarte types.
