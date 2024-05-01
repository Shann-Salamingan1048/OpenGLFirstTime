#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
int main(void)
{


    /* Initialize the library */
    glfwInit();

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(1000, 1000, "First Time OpenGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) // init glew
    {
        std::cout << "Error!\n";
    }
    std::cout << glGetString(GL_VERSION) << "\n";
    
    float positions[6] =
    {
        -0.5f, -0.5f, 
         0.0f,  0.5f, 
         0.5f, -0.5f, 
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer); // create buffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer); // bind bufffer, buffer of memory
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions,GL_STATIC_DRAW);

    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);


       /* glDrawElements(GL_TRIANGLES,3,)*/
       /* glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.0f,  0.5f);
        glVertex2f( 0.5f, -0.5f);
        glEnd();*/

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}