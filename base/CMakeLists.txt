project(ProtocolBase LANGUAGES CXX)


add_library(ProtocolBase STATIC src/protocol_plugin.cpp)

set_property(TARGET ProtocolBase PROPERTY CXX_STANDARD 20)

target_link_libraries(ProtocolBase PUBLIC 
    Corrade::PluginManager
    Magnum::Magnum
    Magnum::GL
    imgui::imgui
    dt::imnodes
    dt::DtDataflowCore
    dt::DtDataflowPlugin
)

target_include_directories(ProtocolBase PUBLIC include)
