cmake_minimum_required(VERSION 3.10.2)

list(APPEND 
    CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)
    
function(set_target_cpp_standard target standard)
set_target_properties(
    ${target}
    PROPERTIES
        CXX_STANDARD ${standard}
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)
endfunction()

function(enable_target_warnings target)
    target_compile_options(
        ${target}
        PRIVATE
          -Wall
          -Wextra
          -Werror
          -Wundef
          -Wuninitialized
          -Wreorder
          -Wshadow
          -Wpointer-arith
          -Wcast-align
          -Wcast-qual
          -Wconversion
          -Wunused-parameter
          -Wlogical-op
          -Wdouble-promotion
          -Wnon-virtual-dtor
          -Woverloaded-virtual
          -Wduplicated-cond
          -Wduplicated-branches
          -Wnull-dereference
    )
endfunction()
