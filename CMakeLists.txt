cmake_minimum_required(VERSION 3.10)
project(ColorBot)

set(CMAKE_CXX_STANDARD 17)
set(Boost_INCLUDE_DIR Y:\\Projects\\vcpkg\\installed\\x86-windows\\include)

include_directories(ColorBot PRIVATE third_party/lodepng)
add_executable(ColorBot main.cpp third_party/lodepng/lodepng.cpp bot.cpp bot.h utils.cpp utils.h rgb.cpp rgb.h commands/command.cpp commands/command.h commands/hextoimage.cpp commands/hextoimage.h commands/about.cpp commands/about.h commands/help.cpp commands/help.h commands/color.cpp commands/color.h)
add_subdirectory(third_party/sleepy-discord)
add_subdirectory(third_party/toml11)
target_link_libraries(ColorBot sleepy-discord toml11)
