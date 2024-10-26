file(GLOB_RECURSE UTILS_BIULD_SOURCE CONFIGURE_DEPENDS src/*.cc include/*.h include/*.hpp)
find_package(ZLIB REQUIRED)
add_library(utils STATIC ${UTILS_BIULD_SOURCE})

target_include_directories(
    utils PUBLIC
    include
)

target_link_libraries(
    utils
    ZLIB::ZLIB
)
