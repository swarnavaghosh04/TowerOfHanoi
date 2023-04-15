cmake_minimum_required(VERSION 3.0.0)
project(CMakeTemplate
    VERSION 0.1.0
    LANGUAGES C CXX
    HOMEPAGE_URL "https://github.com/swarnavaghosh04/CMake-Template"
    DESCRIPTION "Template for CMake projects")

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")

include(GNUInstallDirs)
include(CTest)
enable_testing()

set(DEBUG_FILE "${CMAKE_BINARY_DIR}/debug_log.txt" CACHE FILEPATH
"Log debug to this file when CMAKE_BULD_TYPE is Debug or RelWithDebInfo")
set(CPACK_PACKAGE_CONTACT "Swarnava Ghosh <swarnavaghosh04@gmail.com>")
set(CPACK_PACKAGE_VENDOR "Swarnava Ghosh")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "gcc,cmake")
set(CPACK_RPM_PACKAGE_REQUIRES "gcc,cmake")
set(CPACK_RPM_PACKAGE_LICENSE "MIT")

add_subdirectory(src)
add_subdirectory(tests)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT "${PROJECT_NAME}_Runtime"
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT "${PROJECT_NAME}_Development"
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT "${PROJECT_NAME}_Development"
)
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(
    FILES LICENSE DESTINATION ${CMAKE_INSTALL_DATADIR}/licenses/${PROJECT_NAME}
)
install(
    EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${${PROJECT_NAME}_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

export(
    EXPORT ${PROJECT_NAME}Targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/PKGBUILD.in
    ${CMAKE_CURRENT_BINARY_DIR}/PKGBUILD
    @ONLY)

include(CPack)
