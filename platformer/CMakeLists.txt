add_executable(platformer
        main.cc
        src/heros.cc
        src/niveau.cc)

target_include_directories(platformer PRIVATE include)
target_link_libraries(platformer PRIVATE SFML::Graphics)

# Les assets sont livres avec le projet : le chemin est cable ici, pas devine a l'execution.
target_compile_definitions(platformer PRIVATE
        DOSSIER_DES_ASSETS="${CMAKE_CURRENT_SOURCE_DIR}/assets")
