#include "Camera.h"

Camera::Camera(glm::vec3 InitialPos, float Speed, float Sensitivity,float Width, float Hieght) {
	this->CameraPos = InitialPos;
	this->Speed = Speed;
	this->Sensitivity = Sensitivity;
	this->LastX = Width / 2;
	this->LastY = Hieght / 2;
}

void Camera::Use_Camera_Movement(GLFWwindow* window) {

    float CurrentFrame = glfwGetTime();
    DeltaTime = CurrentFrame - LastFrame;
    LastFrame = CurrentFrame;
    const float CamSpeed = Speed * DeltaTime;
	 
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        CameraPos += CamSpeed * CameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        CameraPos -= CamSpeed * CameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        CameraPos -= glm::normalize(glm::cross(CameraFront, CameraUp)) * CamSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        CameraPos += glm::normalize(glm::cross(CameraFront, CameraUp)) * CamSpeed;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        CameraPos += CameraUp * CamSpeed;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        CameraPos -= CameraUp * CamSpeed;

}

glm::mat4 Camera::Get_View() {
    View = glm::lookAt(CameraPos, CameraPos + CameraFront, CameraUp);
    return View;
}


void Camera::Set_Mouse(GLFWwindow* window) {
        double Xpos, Ypos;
        glfwGetCursorPos(window, &Xpos, &Ypos);

        if (FirstMouse) {
            LastX = Xpos;
            LastY = Ypos;
            FirstMouse = false;
        }

        Xoffset = Xpos - LastX;
        Yoffset = LastY - Ypos;
        LastX = Xpos;
        LastY = Ypos;


        Xoffset *= Sensitivity;
        Yoffset *= Sensitivity;

        Yaw += Xoffset;
        Pitch += Yoffset;

        if (Pitch > 90.0f) {
            Pitch = 90.0f;
        }

        if (Pitch < -90.0f) {
            Pitch = -90.0f;
        }

        this->Direction.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        this->Direction.y = sin(glm::radians(Pitch));
        this->Direction.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));

        CameraFront = glm::normalize(Direction);
        std::cout << Yaw;
        std::cout << Pitch;
    
}