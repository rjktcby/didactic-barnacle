# - Try to find Cucumber-Cpp
# This module defines
#
# CUCUMBER_CPP_FOUND
# CUCUMBER_CPP_INCLUDE_DIRS
# CUCUMBER_CPP_LIBRARIES

find_path(CUCUMBER_CPP_INCLUDE_DIR cucumber-cpp/autodetect.hpp)

find_library(CUCUMBER_CPP_LIB NAMES libcucumber-cpp.so)
find_library(CUCUMBER_CPP_LIB_NOMAIN NAMES libcucumber-cpp-nomain.so)

set(CUCUMBER_CPP_LIBRARIES ${CUCUMBER_CPP_LIB} ${CUCUMBER_CPP_LIB_NOMAIN})
set(CUCUMBER_CPP_INCLUDE_DIRS ${CUCUMBER_CPP_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CucumberCpp DEFAULT_MSG
                 CUCUMBER_CPP_LIB
				 CUCUMBER_CPP_LIB_NOMAIN
				 CUCUMBER_CPP_INCLUDE_DIR
)

mark_as_advanced(CUCUMBER_CPP_LIB 
         CUCUMBER_CPP_LIB_NOMAIN
		 CUCUMBER_CPP_INCLUDE_DIR
)