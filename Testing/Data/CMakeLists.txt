## Ensure that Data files are copied to build directory

configure_file(${CMAKE_SOURCE_DIR}/Testing/Data/TestData1.txt ${CMAKE_BINARY_DIR}/bin/TestData1.txt @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/bin/TestData1.txt DESTINATION . COMPONENT CONFIG)
configure_file(${CMAKE_SOURCE_DIR}/Testing/Data/TestData2.txt ${CMAKE_BINARY_DIR}/bin/TestData2.txt @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/bin/TestData2.txt DESTINATION . COMPONENT CONFIG)