#!/bin/bash
cmake -Bbuild -DCMAKE_BUILD_TYPE=Release
cd build && make