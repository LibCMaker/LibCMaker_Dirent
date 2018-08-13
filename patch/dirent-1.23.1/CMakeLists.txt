cmake_minimum_required (VERSION 2.8.11)

project(dirent LANGUAGES)

# Install dirent.h
if(WIN32)
    install (FILES include/dirent.h DESTINATION include)
else(WIN32)
    cmake_policy(SET CMP0037 OLD) # Supress warnings about fake install
    add_custom_target(install) # Fake install target
endif(WIN32)
