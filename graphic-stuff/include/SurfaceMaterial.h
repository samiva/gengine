#ifndef __SURFACEMATERIAL_h__
#define __SURFACEMATERIAL_h__
#include "Material.h"
#include "glm.hpp"

class SurfaceMaterial : public Material {
	public:
	SurfaceMaterial(ShaderProgram* shader, const glm::vec3 ambient=glm::vec3(0.0f), 
		const glm::vec3 diffuse=glm::vec3(0.0f), const glm::vec3 specular = glm::vec3(0.0f), 
		const float shininess=0.0f) : Material(shader), _ambient(ambient), _diffuse(diffuse), _specular(specular), _shininess(shininess)
	{

	}
	
	void setAmbient(glm::vec3 val) { _ambient = val; }
	void setDiffuse(glm::vec3 val) { _diffuse = val; }
	void setSpecular(glm::vec3 val) { _specular = val; }
	void setShininess(float val) { _shininess = val; }

	glm::vec3 getAmbient() const { return _ambient; }
	glm::vec3 getDiffuse() const { return _diffuse; }
	glm::vec3 getSpecular() const { return _specular; }
	float getShininess() const { return _shininess; }
private:
	glm::vec3 _ambient;
	glm::vec3 _diffuse;
	glm::vec3 _specular;
	float _shininess;

};
#endif // __SURFACEMATERIAL_h__
