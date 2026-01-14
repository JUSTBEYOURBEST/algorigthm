include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

function(add_algorithm_test test_source)
    # 取文件名（不含路径、不含后缀）
    get_filename_component(test_name ${test_source} NAME_WE)

    # 拼接最终可执行文件名
    set(target_name algorithm_${test_name})

    add_executable(${target_name}
            ${test_source}
    )

    target_link_libraries(${target_name}
            PRIVATE
            algorithm_lib
            GTest::gtest
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(${target_name})
endfunction()

add_algorithm_test(diff_test.cc)
