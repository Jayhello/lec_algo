project(lec_algo)

file(GLOB COMMON_SRCS ./*.cpp ./*.h)

add_library(algo_lib
        ${COMMON_SRCS}
        )