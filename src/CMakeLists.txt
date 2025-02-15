add_executable(dsa-practice main.cpp)

target_include_directories(
  dsa-practice 
  PRIVATE 
  array)

target_link_libraries(
  dsa-practice
  PRIVATE
          myproject::myproject_warnings)

target_link_system_libraries(
  dsa-practice
  PRIVATE
          spdlog::spdlog)