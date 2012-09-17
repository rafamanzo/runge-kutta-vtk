cmake_minimum_required(VERSION 2.8)

PROJECT(RungeKutta)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

include_directories(includes)

add_executable(RungeKutta MACOSX_BUNDLE Main io/input/Input io/input/AnalyzeReader core/cpp/Tracer io/output/Renderer)

if(VTK_LIBRARIES)
  target_link_libraries(RungeKutta ${VTK_LIBRARIES} X11)
else()
  target_link_libraries(RungeKutta vtkHybrid X11)
endif()