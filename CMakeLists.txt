cmake_minimum_required(VERSION 3.12)
project(HDF5_VOL_ASYNC VERSION 0.0.1 LANGUAGES C)

if(NOT HDF5_VOL_ASYNC_INSTALL_BIN_DIR)
  set(HDF5_VOL_ASYNC_INSTALL_BIN_DIR ${CMAKE_INSTALL_PREFIX}/bin)
endif()
if(NOT HDF5_VOL_ASYNC_INSTALL_LIB_DIR)
  set(HDF5_VOL_ASYNC_INSTALL_LIB_DIR ${CMAKE_INSTALL_PREFIX}/lib)
endif()
if(NOT HDF5_VOL_ASYNC_INSTALL_INCLUDE_DIR)
  set(HDF5_VOL_ASYNC_INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)
endif()
if(NOT HDF5_VOL_ASYNC_INSTALL_DATA_DIR)
  set(HDF5_VOL_ASYNC_INSTALL_DATA_DIR ${CMAKE_INSTALL_PREFIX}/share)
endif()
if(NOT HDF5_VOL_ASYNC_INSTALL_TEST_DIR)
  set(HDF5_VOL_ASYNC_INSTALL_TEST_DIR ${CMAKE_INSTALL_PREFIX}/test)
endif()

# install(
#   DIRECTORY
#     ${CMAKE_CURRENT_SOURCE_DIR}
#   DESTINATION
#     ${HDF5_VOL_ASYNC_INSTALL_TEST_DIR}/test
# )


set(HDF5_VOL_ASYNC_PACKAGE "hdf5_vol_async")
set(HDF5_VOL_ASYNC_PACKAGE_NAME "HDF5_VOL_ASYNC")
set(HDF5_VOL_ASYNC_PACKAGE_DESCRIPTION "HDF5 Asynchronous I/O VOL connector")
set(HDF5_VOL_ASYNC_PACKAGE_URL "https://github.com/hpc-io/vol-async")
set(HDF5_VOL_ASYNC_PACKAGE_VENDOR "HPC IO")
message(STATUS "Configuring ${HDF5_VOL_ASYNC_PACKAGE} ${PROJECT_VERSION}")

#-----------------------------------------------------------------------------
# Source
#-----------------------------------------------------------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

#-----------------------------------------------------------------------------
# Testing
#-----------------------------------------------------------------------------
enable_testing()
include(CTest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
