/**
* @file      rasterize.h
* @brief     CUDA-accelerated rasterization pipeline.
* @authors   Skeleton code: Yining Karl Li, Kai Ninomiya, Shuai Shao (Shrek)
* @date      2018-11-02
* @copyright University of Pennsylvania & STUDENT
*/

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>

void copyPointsToVBO(float *vbodptr_positions, float *vbodptr_velocities);
glm::mat4 constructTransformationMatrix(const glm::vec3 &translation, const glm::vec3& rotation, const glm::vec3& scale);
void registrationInit(const std:: vector<glm::vec4>& pts);
void registration(int method);
void registrationFree();
