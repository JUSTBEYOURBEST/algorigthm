include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
        glog
        GIT_REPOSITORY https://github.com/google/glog.git
        GIT_TAG v0.6.0
)

# 禁用 glog 的测试，避免与 googletest 冲突
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glog)

function(add_algorithm_test test_source)
    get_filename_component(test_name ${test_source} NAME_WE)

    set(target_name algorithm_${test_name})

    add_executable(${target_name}
            ${test_source}
    )

    target_link_libraries(${target_name}
            PRIVATE
            algorithm_lib
            GTest::gtest
            GTest::gtest_main
            glog::glog
    )

    include(GoogleTest)
    gtest_discover_tests(${target_name})
endfunction()

add_algorithm_test(diff_test.cc)
add_algorithm_test(string_test.cc)
add_algorithm_test(comprehensive_test.cc)
add_algorithm_test(graph_test.cc)
add_algorithm_test(link_list_test.cc)
