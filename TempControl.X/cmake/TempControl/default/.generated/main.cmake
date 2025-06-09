# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(TempControl_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(TempControl_default_default_XC8_FILE_TYPE_assemble)
add_library(TempControl_default_default_XC8_assemble OBJECT ${TempControl_default_default_XC8_FILE_TYPE_assemble})
    TempControl_default_default_XC8_assemble_rule(TempControl_default_default_XC8_assemble)
    list(APPEND TempControl_default_library_list "$<TARGET_OBJECTS:TempControl_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(TempControl_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(TempControl_default_default_XC8_assemblePreprocess OBJECT ${TempControl_default_default_XC8_FILE_TYPE_assemblePreprocess})
    TempControl_default_default_XC8_assemblePreprocess_rule(TempControl_default_default_XC8_assemblePreprocess)
    list(APPEND TempControl_default_library_list "$<TARGET_OBJECTS:TempControl_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(TempControl_default_default_XC8_FILE_TYPE_compile)
add_library(TempControl_default_default_XC8_compile OBJECT ${TempControl_default_default_XC8_FILE_TYPE_compile})
    TempControl_default_default_XC8_compile_rule(TempControl_default_default_XC8_compile)
    list(APPEND TempControl_default_library_list "$<TARGET_OBJECTS:TempControl_default_default_XC8_compile>")
endif()


add_executable(${TempControl_default_image_name} ${TempControl_default_library_list})
set_target_properties(${TempControl_default_image_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TempControl_default_output_dir})

target_link_libraries(${TempControl_default_image_name} PRIVATE ${TempControl_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
TempControl_default_link_rule(${TempControl_default_image_name})




