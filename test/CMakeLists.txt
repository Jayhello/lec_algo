project(lec_algo_test)

find_package(GTest REQUIRED)

function(AddTestTarget test_exe test_src)
    add_executable(${test_exe} ${test_src} test_comm.cpp)
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

AddTestTarget(al_heap_test al_heap_test.cpp)

AddTestTarget(al_list_test al_list_test.cpp)
AddTestTarget(al_que_sta_test al_que_sta_test.cpp)

AddTestTarget(al_slip_wnd al_slip_wnd.cpp)

