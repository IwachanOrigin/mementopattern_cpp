
project(pattern1 CXX)

set(MAIN_SRC
  cell.h
  main.cpp
  sheet.cpp
  sheet.h
)

add_executable(
  ${PROJECT_NAME}
  ${MAIN_SRC}
)

