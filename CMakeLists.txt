cmake_minimum_required (VERSION 3.10)
project(fileio VERSION 0.1.2 DESCRIPTION "File Input/Output Library")
add_executable (csv-rw main.cxx)
configure_file (data.csv data.csv COPYONLY)
add_library (fileio SHARED
  fileio.cxx)
set_target_properties(fileio PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(fileio PROPERTIES SOVERSION 0)
set_target_properties(fileio PROPERTIES PUBLIC_HEADER fileio.hxx)
target_link_libraries(csv-rw fileio)
configure_file(fileio.pc.in fileio.pc @ONLY)

include(GNUInstallDirs)
set (CMAKE_INSTALL_PREFIX "/usr")
install(TARGETS fileio
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/fileio.pc
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
