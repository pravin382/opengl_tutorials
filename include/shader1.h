#ifndef SHADER_H
#define SHADER_H

#include<glad/glad.h>
#include "../lib/glm/glm/glm.hpp"
#include "../lib/glm/glm/gtc/matrix_transform.hpp"
#include "../lib/glm/glm/gtc/type_ptr.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    // the program ID
    unsigned int ID;
    
    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    
    // use/activate the shader
    void use();
    
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setfloat(const std::string &name, float value) const;
    
    void setMat4(const std::string &name, glm::mat4 &mat) const;
    
private:
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif
