#ifndef VENDOR_PCH_H
#define VENDOR_PCH_H

#include <glad/glad.h>
/// padding (necessary because Google style keeps bringing them in reverse
/// order)
#include <GLFW/glfw3.h>
#include <stb_image/stb_image.h>

/// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>

/// STD
#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <map>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

// BOOST
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

/// ImGui
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"

/// Platform-dependent
#ifdef _WIN32

#include <shlobj_core.h>

#include <chrono>

#elif __linux__

#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

#endif

#endif