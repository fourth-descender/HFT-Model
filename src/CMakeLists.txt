set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Parameters.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Model.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Arrival.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Simulator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Simulation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Statistic.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Writer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Plotter.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)