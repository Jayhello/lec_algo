project(lec_algo_test)

find_package(GTest REQUIRED)

function(AddTestTarget test_exe test_src)
    add_executable(${test_exe} ${test_src})
    target_link_libraries(
            ${test_exe}
            algo_lib
            gtest_main
            gtest
            pthread
    )
endfunction()

AddTestTarget(al_str_test al_str_test.cpp)

AddTestTarget(al_arr_test al_arr_test.cpp)

