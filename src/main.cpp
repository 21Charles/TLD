#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <SPDLOG/spdlog.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    if (!glfwInit()) {
        spdlog::critical("Couldn't initialize GLFW");
        return -1;
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(800, 600, "Game", nullptr, nullptr);
    if (!window) {
        spdlog::critical("Couldn't create windows");
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        spdlog::critical("Couldn't load GLFW definitions");
        return -1;
    }


    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    while (!glfwWindowShouldClose(window)) {

        glfwPollEvents();


        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(window);
    }


    glfwTerminate();
    return 0;
}