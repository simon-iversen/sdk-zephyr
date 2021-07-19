# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

set(mcuboot_OVERLAY_CONFIG                # Add this line
  ${CMAKE_CURRENT_LIST_DIR}/mcuboot.conf  # Add this line
)                                     # Add this line

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

target_sources(app PRIVATE src/main.c)
