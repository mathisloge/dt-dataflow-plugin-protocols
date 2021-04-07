project(NmeaProtocolPlugin LANGUAGES CXX)

add_subdirectory(nmea)

set(SOURCES         
    src/handler.cpp
    src/protocol_nmea.cpp
    src/protocol_plugin.cpp
)

corrade_add_plugin(NmeaProtocolPlugin 
    "${DTDF_PLUGIN_INSTALL_DBG_DIR}"
    "${DTDF_PLUGIN_INSTALL_REL_DIR}"
    NmeaProtocolPlugin.conf 
    ${SOURCES}
)
set_property(TARGET NmeaProtocolPlugin PROPERTY CXX_STANDARD 20)
target_include_directories(
    NmeaProtocolPlugin PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_link_libraries(NmeaProtocolPlugin PRIVATE 
    ProtocolBase
    nmea::nmea
)
