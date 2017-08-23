// Std. Includes
#include <iostream>
#include <map>
#include <string>
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// FreeType
#include <ft2build.h>
#include FT_FREETYPE_H
// GL includes
#include "Shader.h"
#include "textRender.h"

// Properties
const GLuint WIDTH = 800, HEIGHT = 600;




// The MAIN function, from here we start our application and run the Game loop
int main()
{
    // Init GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr); // Windowed
    glfwMakeContextCurrent(window);

    // Initialize GLEW to setup the OpenGL Function pointers
    glewExperimental = GL_TRUE;
    glewInit();

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);

    textRender tr(800,600,"/home/wnl/workspace/textRender/SourceHanSerifCN-Bold.otf");


    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check and call events
        glfwPollEvents();

        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        std::string s("d!($等等UI方法那边");
        tr.RenderText(s,(GLfloat)35.0f,(GLfloat)35.0f,1.0f, glm::vec3(0.5, 0.8f, 0.2f));
        std::string s1("corn");
        tr.RenderText(s1,(GLfloat)350.0f,(GLfloat)350.0f,1.0f, glm::vec3(0.5, 0.8f, 0.2f));

        // Swap the buffers
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

