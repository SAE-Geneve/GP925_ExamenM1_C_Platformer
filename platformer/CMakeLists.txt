add_executable(platformer
        main.cc
        src/heros.cc
        src/niveau.cc)

target_include_directories(platformer PRIVATE include)
target_link_libraries(platformer PRIVATE SFML::Graphics)

# Les assets voyagent avec le binaire : data/ est copie a cote de l'executable.
copy_data(platformer)
