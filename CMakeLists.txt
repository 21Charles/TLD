cmake_minimum_required(VERSION 3.16)

project(TLD VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(THIRDPARTY_DIR ${CMAKE_SOURCE_DIR}/thirdparty)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE INLINE src/*.inl)
file(GLOB_RECURSE HEADERS include/*.h)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(TLD ${SOURCES} ${HEADERS} ${INLINE})

set(GLFW_LIB_DIR ${THIRDPARTY_DIR}/.lib)
find_library(GLFW_LIBRARY NAMES glfw3 PATHS ${GLFW_LIB_DIR})

set(GLAD_SRC ${THIRDPARTY_DIR}/GLAD/glad.c)
set(ASSIMP_LIBRARY "${THIRDPARTY_DIR}/.lib/Assimp/assimp-vc143-mt.lib")
set(BULLET_COLLISION_LIBRARY "${THIRDPARTY_DIR}/.lib/Bullet/BulletCollision.lib")
set(BULLET_DYNAMICS_LIBRARY "${THIRDPARTY_DIR}/.lib/Bullet/BulletDynamics.lib")
set(BULLET_MATH_LIBRARY "${THIRDPARTY_DIR}/.lib/Bullet/LinearMath.lib")

include_directories(${THIRDPARTY_DIR})

target_link_libraries(${PROJECT_NAME}
    ${GLFW_LIBRARY}
    ${ASSIMP_LIBRARY}
    ${BULLET_DYNAMICS_LIBRARY}
    ${BULLET_COLLISION_LIBRARY}
    ${BULLET_MATH_LIBRARY}
)

target_sources(${PROJECT_NAME} PRIVATE ${GLAD_SRC})