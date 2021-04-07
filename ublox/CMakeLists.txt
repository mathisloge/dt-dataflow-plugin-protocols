project(UbloxProtocolPlugin LANGUAGES CXX)

find_package(LibComms CONFIG REQUIRED)
find_package(ublox CONFIG REQUIRED)

set(SOURCES         
    src/protocol_plugin.cpp
    src/protocol_ublox.cpp
    src/ublox_detail.cpp
)

corrade_add_plugin(UbloxProtocolPlugin 
    "${DTDF_PLUGIN_INSTALL_DBG_DIR}"
    "${DTDF_PLUGIN_INSTALL_REL_DIR}"
    UbloxProtocolPlugin.conf 
    ${SOURCES}
)
set_property(TARGET UbloxProtocolPlugin PROPERTY CXX_STANDARD 20)
if(MSVC)
    set_property(TARGET UbloxProtocolPlugin APPEND PROPERTY COMPILE_OPTIONS "/bigobj")
endif()
target_include_directories(
    UbloxProtocolPlugin PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_link_libraries(UbloxProtocolPlugin PRIVATE 
    ProtocolBase
    cc::comms
    cc::ublox
)
