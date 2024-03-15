#ifndef PCH_VENDORPCH_H_
#define PCH_VENDORPCH_H_

#include <glad/glad.h>
// padding (necessary because auto format keeps bringing them in reverse order)
#include <GLFW/glfw3.h>
#include <stb_image/stb_image.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>

// Standard Library
#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// BOOST
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>

// ImGui
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"

// Platform dependent
#ifdef _WIN32
/// Windows

#define NOMINMAX  // turns off windows std::min and std::max implementation
#include <shlobj_core.h>
#include <chrono>

#elif __linux__
/// Linux

#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

#endif

#endif