#include <glad/glad.h>
#include <iostream>

#include "Core/App.h"
#include "OpenGL/Shader.h"
#include "OpenGL/Program.h"
#include "OpenGL/BufferObject.h"
#include "OpenGL/Vao.h"
#include "OpenGL/Texture2D.h"

float vertices[] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,  // first Triangle
    1, 2, 3   // second Triangle
};

int main()
{
    App app;
    try
    {
        app.initialize();

        // PROGRAM
        
        Shader vertex(GL_VERTEX_SHADER);
        Shader fragment(GL_FRAGMENT_SHADER);

        vertex.source(app.fileManager.readTextFile("resources/shaders/vertex.shader"));
        fragment.source(app.fileManager.readTextFile("resources/shaders/fragment.shader"));

        Program program(vertex.getId(), fragment.getId());
        program.link();

        // TEXTURE

        Texture2D tex;
        TextureData tdata = app.fileManager.loadTextureData("resources/textures/container.jpg");
        tex.bind();

        tex.setParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
        tex.setParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
        tex.setParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        tex.setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        tex.data(tdata.data, tdata.width, tdata.height);

        tex.unbind();
        tdata.destroy();

        // TEXTURE 2
        Texture2D tex2;
        TextureData tdata2 = app.fileManager.loadTextureData("resources/textures/awesomeface.png");
        tex2.bind();

        tex2.setParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
        tex2.setParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
        tex2.setParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        tex2.setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        tex2.data(tdata2.data, tdata2.width, tdata2.height, GL_RGBA);

        tex2.unbind();
        tdata2.destroy();

        // VAO

        BufferObject vbo(GL_ARRAY_BUFFER), ebo(GL_ELEMENT_ARRAY_BUFFER);
        Vao vao;

        vao.bind();
        vbo.bind();
        ebo.bind();

        vbo.data(sizeof(vertices), vertices, GL_STATIC_DRAW);
        ebo.data(sizeof(indices), indices, GL_STATIC_DRAW);

        vao.queueAttrib(GL_FLOAT, 3);
        vao.queueAttrib(GL_FLOAT, 3);
        vao.queueAttrib(GL_FLOAT, 2);
        vao.setAttribs();

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        vbo.unbind();

        // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
        // ebo.unbind();

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        vao.unbind();

        // RENDERING LOOP
        program.use();
        program.setUniform1i("texture1", 0);
        program.setUniform1i("texture2", 1);

        while (!app.shouldClose())
        {
            app.startFrame();

            Texture2D::activateUnit(0);
            tex.bind();
            Texture2D::activateUnit(1);
            tex2.bind();

            program.use();
            vao.bind();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            app.endFrame();
        }
        app.terminate();    // for some reason won't work if taken out of try-catch
    }
    catch(const std::exception& e)
    {
        app.logger.log(e.what());
        app.terminate();
    }

    return 0;
}