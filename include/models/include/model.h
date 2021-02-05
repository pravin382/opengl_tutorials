#ifndef MODEL_H
#define MODEL_H
#include "mesh.h"


#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "stb/stb_image.h"
#include <map>
#include <fstream>
#include <sstream>

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);

class Model
{

public:
    Model(char* path, bool gamma);
    void Draw(Shader &Shader);
    
private:
    // model data
    std::vector<Texture> textures_loaded;
    std::vector<Mesh> meshes;
    std::string directory;
    bool gammaCorrection;
    
    void loadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};

#endif
