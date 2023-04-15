add_library(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

target_compile_definitions(${PROJECT_NAME} PUBLIC
    $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:DEBUG_FILE="${DEBUG_FILE}">)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)