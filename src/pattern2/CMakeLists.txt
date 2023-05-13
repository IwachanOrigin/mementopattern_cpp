
project(pattern2 CXX)

set(MAIN_SRC
  cell.h
  cellmemento.h
  cellmemento.cpp
  main.cpp
  sheetwithmemento.cpp
  sheetwithmemento.h
)

add_executable(
  ${PROJECT_NAME}
  ${MAIN_SRC}
)

