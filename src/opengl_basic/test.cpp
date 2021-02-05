#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]){
    std::string vertexPath = "../shader_files/fragment_shader.fs";
    std::string vertexCode;
    //std::string fragmentCode;
    std::ifstream vShaderFile;
    //std::ifstream fShaderFile;
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        // open files
        vShaderFile.open(vertexPath);
        
        std::stringstream vShaderStream;
        // read file's buffer content into streams
        vShaderStream << vShaderFile.rdbuf();

        
        // close the file handlers
        vShaderFile.close();

        // convert stream into string
        vertexCode = vShaderStream.str();

        
        std::cout << vertexCode <<std::endl;
    }
    catch (std::ifstream::failure e){
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    }
    
    return 0;
}
