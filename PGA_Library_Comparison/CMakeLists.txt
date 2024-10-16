# CMakeList.txt : CMake project for PGA_Library_Comparison, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (PGA_Library_Comparison "PGA_Library_Comparison.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PGA_Library_Comparison PROPERTY CXX_STANDARD 20)
endif()

include(FetchContent)

# This tracks the latest commit on the master branch of the Klein
# repository. Instead of `origin/master`, you can specify a specific
# commit hash or tag.
FetchContent_Declare(
    klein
    GIT_REPOSITORY https://github.com/jeremyong/Klein.git
    GIT_TAG origin/master
)

FetchContent_MakeAvailable(klein)

target_link_libraries(PGA_Library_Comparison PUBLIC klein::klein)
