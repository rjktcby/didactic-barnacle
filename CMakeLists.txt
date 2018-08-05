cmake_minimum_required(VERSION 3.1)

project(JpegCucumber)

# option(CUKE_DISABLE_BOOST_TEST  "" ON)
# option(CUKE_DISABLE_UNIT_TESTS  "" ON)
# option(CUKE_DISABLE_E2E_TESTS   "" ON)
# option(CUKE_DISABLE_QT          "" ON)

# -DCUKE_DISABLE_BOOST_TEST=ON -DCUKE_DISABLE_UNIT_TESTS=ON -DCUKE_DISABLE_E2E_TESTS=ON -DCUKE_DISABLE_QT=ON


# option(CUKE_DISABLE_GTEST       "Disable Google Test framework" OFF)
# option(CUKE_ENABLE_EXAMPLES     "Enable the examples" OFF)
# add_subdirectory(cucumber-cpp cucumber-cpp)

# if(TARGET GTest::GTest)
# list(FIND CMAKE_CXX_COMPILE_FEATURES cxx_variadic_templates HAS_VARIADIC_TEMPLATES)
# if(HAS_VARIADIC_TEMPLATES GREATER -1)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(GMock REQUIRED)
find_package(CucumberCpp REQUIRED)

add_executable(EncodingSteps features/step_definitions/EncodingSteps)

target_include_directories(EncodingSteps PRIVATE ${CUCUMBER_CPP_INCLUDE_DIRS})
target_link_libraries(EncodingSteps PRIVATE ${CUCUMBER_CPP_LIB} GTest::GTest)

target_compile_features(EncodingSteps PRIVATE cxx_variadic_templates)

# endif()
# endif()
