include_directories (include/)

file(GLOB_RECURSE sources source/lunar/*.cpp source/lunar/*.h include/lunar/*.h)

if (LUNAR_BUILD_SHARED)
    message(STATUS "Building shared libraries (-DLUNAR_BUILD_SHARED=OFF to disable)")
    add_library(lunar SHARED ${sources} ${mmsources})
    set_target_properties(lunar PROPERTIES
            OUTPUT_NAME lunar
            DEBUG_POSTFIX -d
            VERSION ${LUNAR_VERSION}
            SOVERSION ${LUNAR_MAJOR_VERSION}
            FOLDER lunar
            )
    set(install_libs ${install_libs} lunar)
endif (LUNAR_BUILD_SHARED)

if (LUNAR_BUILD_STATIC)
    message(STATUS "Building static libraries (-DLUNAR_BUILD_STATIC=OFF to disable)")
    add_library(lunarstatic STATIC ${sources} ${mmsources})
    set_target_properties(lunarstatic PROPERTIES DEBUG_POSTFIX -d FOLDER lunar)
    set(install_libs ${install_libs} lunarstatic)
endif (LUNAR_BUILD_STATIC)

# Library installation directory
if(NOT DEFINED CMAKE_INSTALL_LIBDIR)
    set(CMAKE_INSTALL_LIBDIR lib)
endif(NOT DEFINED CMAKE_INSTALL_LIBDIR)
set(libdir ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR})

message(STATUS "Installing header files...")
install(
    DIRECTORY "include/lunar"
    DESTINATION "include"
    FILES_MATCHING PATTERN "*.h"
)

message(STATUS "Installing library files...")
install(
    TARGETS ${install_libs}
    LIBRARY DESTINATION "${libdir}"
    ARCHIVE DESTINATION "${libdir}"
    RUNTIME DESTINATION "bin"
)
