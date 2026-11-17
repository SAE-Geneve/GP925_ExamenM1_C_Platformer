cmake_minimum_required(VERSION 3.28) # plancher impose par SFML 3
project(GP925_ExamenM1_C_Platformer CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Les sources sont en UTF-8, MSVC ne le devine pas.
if(MSVC)
    add_compile_options(/utf-8)
endif()

# SFML vient de vcpkg, comme dans vos projets : `vcpkg.json` dit ce qu'il faut et
# vcpkg l'installe a la configuration. CLion met la toolchain en place depuis son
# panneau Vcpkg ; en ligne de commande :
#   cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
find_package(SFML 3 COMPONENTS Graphics REQUIRED)

# Copie le dossier data/ de la cible a cote de son executable.
# Sans ca, les chemins relatifs du code ne trouvent rien a l'execution.
function(copy_data target)
    add_custom_command(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
            "${CMAKE_CURRENT_SOURCE_DIR}/data" "$<TARGET_FILE_DIR:${target}>/data")
endfunction()

add_subdirectory(platformer)
