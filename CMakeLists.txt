cmake_minimum_required(VERSION 3.1)

project(JpegCucumber)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(GMock REQUIRED)
find_package(CucumberCpp REQUIRED)
find_package(JPEG REQUIRED)

set(EncodingSteps_sources
"features/step_definitions/ParameterDefs.cpp"
"features/step_definitions/EncodingSteps.cpp"
)

set(GeneratedSteps_sources
"features/step_definitions/GeneratedSteps.cpp"
)

add_executable(EncodingSteps ${EncodingSteps_sources})

set_property(TARGET EncodingSteps PROPERTY CXX_STANDARD 14)

target_include_directories(EncodingSteps PRIVATE ${CUCUMBER_CPP_INCLUDE_DIRS} ${JPEG_INCLUDE_DIR})
target_link_libraries(EncodingSteps PRIVATE ${CUCUMBER_CPP_LIB} GTest::GTest ${JPEG_LIBRARY})

target_compile_features(EncodingSteps PRIVATE cxx_variadic_templates)
