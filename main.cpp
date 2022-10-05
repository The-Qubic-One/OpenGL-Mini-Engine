#include <glad/glad.h>
//#include <GLFW/glfw3.h>
#include <iostream>

#include "Core/App.h"
#include "OpenGL/Shader.h"
#include "OpenGL/Program.h"
#include "OpenGL/BufferObject.h"
#include "OpenGL/Vao.h"

float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,  // first Triangle
    1, 2, 3   // second Triangle
};

float texCoords[] = {
    0.0f, 0.0f,  // lower-left corner  
    1.0f, 0.0f,  // lower-right corner
    0.5f, 1.0f   // top-center corner
};

/*
    rendering requirements:

    program
        shaders
            src
            uniforms
                name
                value
    VAO
        vbo
        ebo
        list of attributes
            type
            n of variables
            stride
*/

int main()
{
    App app;
    try
    {
        app.init();
        // PROGRAM
        Shader vertex(GL_VERTEX_SHADER);
        Shader fragment(GL_FRAGMENT_SHADER);
        vertex.source(app.fileManager.readTextFile("resources/shaders/vertex.shader"));
        fragment.source(app.fileManager.readTextFile("resources/shaders/fragment.shader"));
        Program program(vertex.getId(), fragment.getId());
        program.link();

        BufferObject vbo(GL_ARRAY_BUFFER), ebo(GL_ELEMENT_ARRAY_BUFFER);
        Vao vao;

        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        vao.bind();
        vbo.bind();
        ebo.bind();

        vbo.data(sizeof(vertices), vertices, GL_STATIC_DRAW);
        ebo.data(sizeof(indices), indices, GL_STATIC_DRAW);
        vao.addAttrib(3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        vbo.unbind();

        // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
        // ebo.unbind();

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        vao.unbind();

        // uncomment this call to draw in wireframe polygons.
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        while (!app.shouldClose())
        {
            app.startFrame();

            // draw our first triangle
            program.use(); // glUseProgram(program.getId());

            float timeValue = (float)glfwGetTime();
            float greenValue = sin(timeValue) / 2.0f + 0.5f;

            program.setUniform4f("ourColor", 0.0f, greenValue, 0.0f, 1.0f);

            vao.bind(); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
            //glDrawArrays(GL_TRIANGLES, 0, 6);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            // vao.unbind(); // no need to unbind it every time 

            app.endFrame();
        }

    }
    catch(const std::exception& e)
    {
        app.logger.log(e.what());
    }

    return 0;
}