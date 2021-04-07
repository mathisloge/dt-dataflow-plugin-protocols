project(MavlinkProtocolPlugin LANGUAGES CXX)


add_library(c_library_v2 INTERFACE)
target_include_directories(c_library_v2 PUBLIC c_library_v2)
