// modified from Project 0

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cuda_gl_interop.h>
#include <cuda_runtime.h>
#include <glm/glm.hpp>
#include <util/glslUtility.hpp>
#include <util/utilityCore.hpp>
#include <memory>

#include "registration.h"
#include "pointcloud.h"

using namespace std;

//====================================
// GL Stuff
//====================================

GLuint positionLocation = 0;   // Match results from glslUtility::createProgram.
GLuint velocitiesLocation = 1; // Also see attribtueLocations below.
const char *attributeLocations[] = { "Position", "Velocity" };

GLuint pointVAO = 0;
GLuint pointVBO_positions = 0;
GLuint pointVBO_velocities = 0;
GLuint pointIBO = 0;
GLuint displayImage;
GLuint program[2];

const unsigned int PROG_POINT = 0;

const float fovy = (float) (PI / 4);
const float zNear = 0.10f;
const float zFar = 10.0f;
int width = 1280;
int height = 720;
int pointSize = 2;

// For camera controls
bool leftMousePressed = false;
bool rightMousePressed = false;
bool middleMousePressed = false;
double lastX;
double lastY;
float theta = 1.22f;
float phi = -0.70f;
float zoom = 4.0f;
glm::vec3 lookAt = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 cameraPosition;

glm::mat4 projection;

//====================================
// Main
//====================================

const char *projectName;

int main(int argc, char* argv[]);

//====================================
// Main loop
//====================================
void mainLoop();
void errorCallback(int error, const char *description);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void mousePositionCallback(GLFWwindow* window, double xpos, double ypos);
void updateCamera();
void runCUDA();

//====================================
// Setup/init Stuff
//====================================
bool init(int argc, char **argv);
void initVAO();
void initShaders(GLuint *program);