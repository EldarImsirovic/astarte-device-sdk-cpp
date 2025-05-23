#!/bin/bash

# (C) Copyright 2025, SECO Mind Srl
#
# SPDX-License-Identifier: Apache-2.0

function usage() {
    echo "Usage: $0 [--help] [--stdcpp <17|20>]"
    echo ""
    echo "Options:"
    echo "  --help       Show this help message and exit"
    echo "  --stdcpp     Specify the C++ standard to use (17 or 20)"
    exit 0
}

CXX_STANDARD=20

# Parse command-line arguments
while [[ "$#" -gt 0 ]]; do
    case $1 in
        --help) usage ;;
        --stdcpp)
            shift
            if [[ "$1" == "17" || "$1" == "20" ]]; then
                CXX_STANDARD="$1"
            else
                echo "Invalid argument for --stdcpp. Use 17 or 20."
                exit 1
            fi
            ;;
        *)
            echo "Unknown option: $1"
            usage
            ;;
    esac
    shift
done

# Check if the environment and dependencies are ok
if [ ! -d ".venv" ]; then
    python3 -m venv .venv
fi
source .venv/bin/activate
pip install --upgrade pip
package_name="clang-tidy"
package_version="19.1.0"
installed_version=$((pip show $package_name | grep Version | awk '{print $2}') || true)
if [ "$installed_version" != "$package_version" ]; then
    pip install $package_name==$package_version
    if [ $? -ne 0 ]; then
        echo "Failed to install $package_name version $package_version."
        exit 1
    fi
fi

# Create the cmake project
if [[ ! -d "samples/grpc/build" ]]; then
    mkdir -p samples/grpc/build
fi
pushd samples/grpc/build
cmake --fresh -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_CXX_STANDARD=${CXX_STANDARD} -DCMAKE_CXX_STANDARD_REQUIRED=ON -DMAKE_DEPENDENCIES_PUBLIC=ON ..
popd

# Run clang-tidy
clang-tidy -warnings-as-errors=* -extra-arg=-std=c++${CXX_STANDARD} -header-filter='.*(?<!pb)\.hpp$' -p=samples/grpc/build include/astarte_device_sdk/*.hpp private/*.hpp src/*.cpp
