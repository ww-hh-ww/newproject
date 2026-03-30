cmake_minimum_required(VERSION 3.10.0)
project(String_on_class VERSION 0.1.0 LANGUAGES C CXX)

# 1. 定义源文件列表（把所有 .cpp 都列在这里）
set(SOURCES
    "main.cpp"
    "src/StringBuilder.cpp"
)

# 2. 创建可执行程序
add_executable(String_on_class ${SOURCES})

# 3. 现代写法：将头文件目录关联到目标（Target）
# 这样编译器就知道去哪里找 String.h 和 StringBuilder.h 了
target_include_directories(String_on_class PRIVATE 
    include
)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
