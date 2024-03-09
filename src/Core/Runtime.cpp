#include "Core/Runtime.h"

#include "Core/App.h"
#include "Core/util.h"
#include "OpenGL/BufferObject.h"
#include "OpenGL/Program.h"
#include "OpenGL/Shader.h"
#include "OpenGL/Texture2D.h"
#include "OpenGL/Vao.h"

float vertices[] = {
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,  -0.5f, -0.5f, 1.0f, 0.0f,
    0.5f,  0.5f,  -0.5f, 1.0f, 1.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f, -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

    -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, 0.5f,  -0.5f, 0.5f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f, 0.5f,  0.5f,  0.0f, 1.0f, -0.5f, -0.5f, 0.5f,  0.0f, 0.0f,

    -0.5f, 0.5f,  0.5f,  1.0f, 0.0f, -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, -0.5f, 0.5f,  0.5f,  1.0f, 0.0f,

    0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
    0.5f,  -0.5f, -0.5f, 0.0f, 1.0f, 0.5f,  -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f,  -0.5f, 0.5f,  0.0f, 0.0f, 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.5f,  -0.5f, -0.5f, 1.0f, 1.0f,
    0.5f,  -0.5f, 0.5f,  1.0f, 0.0f, 0.5f,  -0.5f, 0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

    -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f, 0.5f,  0.5f,  -0.5f, 1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, 0.5f,  0.5f,  0.0f, 0.0f, -0.5f, 0.5f,  -0.5f, 0.0f, 1.0f};

int Runtime::startApplication() {
  App app;
  path_t exe = Path::getProgramPath();

  try {
    app.initialize();

    // PROGRAM

    Shader vertex(ShaderType::VERTEX), fragment(ShaderType::FRAGMENT);
    vertex.compile(FileManager::readTextFile(exe / "shaders/vertex.shader"));
    fragment.compile(
        FileManager::readTextFile(exe / "shaders/fragment.shader"));

    Program program(vertex, fragment);
    program.link();

    // TEXTURE

    Texture2D tex;
    TextureData tdata =
        FileManager::loadTextureData((exe / "textures/container.jpg").c_str());
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
    TextureData tdata2 = FileManager::loadTextureData(
        (exe / "textures/awesomeface.png").c_str());
    tex2.bind();

    tex2.setParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
    tex2.setParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
    tex2.setParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    tex2.setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    tex2.data(tdata2.data, tdata2.width, tdata2.height, GL_RGBA);

    tex2.unbind();
    tdata2.destroy();

    // VAO

    Vbo vbo;
    Vao vao;

    vao.bind();
    vbo.bind();

    vbo.data(sizeof(vertices), vertices, GL_STATIC_DRAW);

    vao.queueAttrib(GL_FLOAT, 3);
    vao.queueAttrib(GL_FLOAT, 2);
    vao.setAttribs();

    // note that this is allowed, the call to glVertexAttribPointer registered
    // VBO as the vertex attribute's bound vertex buffer object so afterwards we
    // can safely unbind
    vbo.unbind();

    // remember: do NOT unbind the EBO while a VAO is active as the bound
    // element buffer object IS stored in the VAO; keep the EBO bound.
    // ebo.unbind();

    // You can unbind the VAO afterwards so other VAO calls won't accidentally
    // modify this VAO, but this rarely happens. Modifying other VAOs requires a
    // call to glBindVertexArray anyways so we generally don't unbind VAOs (nor
    // VBOs) when it's not directly necessary.
    vao.unbind();

    //  TRANSFORM
    glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
    glm::mat4 model = glm::mat4(1.0f);
    model =
        glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 proj = glm::perspective(
        glm::radians(50.0f), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f,
        100.0f);

    // RENDERING LOOP
    program.use();
    program.setUniform1i("texture1", 0);
    program.setUniform1i("texture2", 1);
    program.setUniformMat4f("model", model);
    program.setUniformMat4f("view", view);
    program.setUniformMat4f("projection", proj);

    float rot_speed = 0.1f;

    while (!app.shouldClose()) {
      app.startFrame();

      model = glm::rotate(model,
                          glm::radians(rot_speed * 200.0f * Time::deltaTime()),
                          glm::vec3(0.0f, 0.0f, 1.0f));
      program.setUniformMat4f("model", model);

      Texture2D::activateUnit(0);
      tex.bind();
      Texture2D::activateUnit(1);
      tex2.bind();

      program.use();
      vao.bind();
      glDrawArrays(GL_TRIANGLES, 0, 36);

      {
        ImGui::Begin("Specs");
        ImGui::SliderFloat("rotation speed", &rot_speed, -5.0f, 5.0f);
        if (ImGui::Button("reset")) rot_speed = 0.0f;
        ImGui::ColorEdit3("clear color", (float*)&(app.bg_color));
        ImGui::End();
      }

      app.endFrame();
    }
    app.terminate();  // for some reason won't work if taken out of try-catch
  } catch (const std::exception& e) {
    app.logger.log(e.what());
    std::string logs = app.logger.pullLogs();
    FileManager::appendTextFile(Path::getDataPath() / "log.txt", logs);
    app.terminate();
  }

  return 0;
}