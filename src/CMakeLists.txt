cmake_minimum_required(VERSION 3.10)


add_executable(shape_executable
    main.cpp
    Figures/ShapeFactory.cpp
   
)

target_link_libraries(shape_executable PRIVATE  sfml-graphics sfml-window sfml-system)

# Эта команда будет выполняться после сборки shape_executable.
# Она копирует директорию ../fonts (относительно папки src)
# в новую папку fonts рядом с исполняемым файлом.
add_custom_command(
    TARGET shape_executable POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/../fonts" # Источник: draw_shape/fonts
            $<TARGET_FILE_DIR:shape_executable>/fonts # Назначение: build/src/fonts
    COMMENT "Copying fonts to output directory"
)

target_compile_options(shape_executable PRIVATE ${PROJECT_COMPILE_OPTIONS})
