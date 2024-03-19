cmake_minimum_required (VERSION 3.10)
project (SUNDIALS-Sandbox)

set(SUNDIALS_DIR "$ENV{SUNDIALS_ROOT}" CACHE STRING "SUNDIALS root directory")
find_package(SUNDIALS REQUIRED)

add_executable(testMyNVector
  testMyNVector.c
  myNVector.c)
target_link_libraries(testMyNVector SUNDIALS::core m)

add_executable(testMySUNLinearSolver
  testMySUNLinearSolver.c
  mySUNLinearSolver.c
  myNVector.c)
target_link_libraries(testMySUNLinearSolver SUNDIALS::core m)
