file(GLOB SOURCES "*.h" "*.cpp" "*.ui" "*.qrc")

add_executable(microrender ${SOURCES})
target_link_libraries(microrender Qt5::Core Qt5::Widgets)