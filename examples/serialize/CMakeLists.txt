# test serialization

add_executable(test_serialization serialize.cpp)
# Link OpenDIS into ExampleSender
target_link_libraries(test_serialization PRIVATE opendis::dis7)
target_include_directories(test_serialization PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/examples>
)

add_executable(test_radar radartest.cpp)
# Link OpenDIS into ExampleSender
target_link_libraries(test_radar PRIVATE opendis::dis7)
target_include_directories(test_radar PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/examples>
)

include(FetchContent)

FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent.git
  GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(json_test serialize_json.cpp)
# Link OpenDIS into ExampleSender
target_link_libraries(json_test
 PRIVATE
  opendis::dis7
  nlohmann_json::nlohmann_json
)

target_include_directories(json_test PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/examples>
)