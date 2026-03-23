#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../shader_program/LocSet.h"
#include "../shader_program/shader_program.h"

class Camera {
public:
    Camera(glm::vec3 InitialPos, float Speed, float Sensitivity, float Width, float Hieght);
    void Use_Camera_Movement(GLFWwindow* window);
    void Set_Mouse(GLFWwindow* window);
    glm::mat4 Get_View();
private:
    float FPS = 1.0f / DeltaTime;
    glm::vec3 Direction;
    glm::vec3 CameraPos;
    glm::vec3 CameraFront;
    glm::vec3 CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    float Pitch = 0.0f;
    float Yaw = -90.0f;
    float LastX;
    float LastY;
    float Xoffset;
    float Yoffset;
    float Speed;
    float FirstMouse;
    float Sensitivity;
    float DeltaTime = 0.0f;
    float LastFrame = 0.0f;
    glm::mat4 View = glm::mat4(1.0f);
};
