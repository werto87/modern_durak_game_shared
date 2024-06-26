##
## Copyright (c) 2024 Waldemar Schneider (w-schneider1987 at web dot de)
##
## Distributed under the Boost Software License, Version 1.0.
## (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


add_library(modern_durak_game_shared INTERFACE)


add_library(myproject::modern_durak_game_shared ALIAS modern_durak_game_shared)


find_package(durak)
find_package(modern_durak_game_option)

target_link_libraries(modern_durak_game_shared INTERFACE
        durak::durak
        Boost::headers
        modern_durak_game_option::modern_durak_game_option
        )

target_include_directories(modern_durak_game_shared INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

target_compile_features(modern_durak_game_shared INTERFACE cxx_std_20)

install(FILES
        modern_durak_game_shared.hxx
        DESTINATION include/modern_durak_game_shared
        )
install(TARGETS modern_durak_game_shared DESTINATION lib)
