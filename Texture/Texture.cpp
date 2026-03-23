#define STB_IMAGE_IMPLEMENTATION
#include "Texture.h"

Texture::Texture(Shader& shader, const char* Path, const char* LocName, int Loc) {
    this->Path = Path;
    this->Loc = Loc;
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(Path, &width, &height, &nrChannels, 0);
    if (data)
    {
        GLenum Format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, Format, width, height, 0, Format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    SetInt(shader, LocName, Loc);

}

void Texture::BindTexture() {
    glBindTexture(GL_TEXTURE_2D, ID);
}


void Texture::ActivateTexture() {
    glActiveTexture(GL_TEXTURE0 + Loc);
}