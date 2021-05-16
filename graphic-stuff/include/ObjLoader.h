#ifndef __OBJLOADER_h__
#define __OBJLOADER_h__
#include <string>
#include <vector>
#include "Mesh.h"
#include "glm.hpp"
#include <map>
#include <utility>

struct Vertex {
	glm::vec3 position{ 0 };
	glm::vec3 normal{ 0 };
	glm::vec2 texCoord{ 0 };

	Vertex(glm::vec3 p, glm::vec3 n=glm::vec3(0), glm::vec2 tC=glm::vec2(0))
		: position(p), normal(n), texCoord(tC) { }

	bool operator=(const Vertex& other) {
		return (this->position == other.position) &&
			(this->normal == other.normal) &&
			(this->texCoord == other.texCoord);
	}
};

struct VertexIndex {
	unsigned int position;
	unsigned int normal;
	unsigned int texture;
};

struct Face {
	std::vector<VertexIndex> indices;
	void addVertexIndex(VertexIndex ind) {
		indices.push_back(ind);
	}
};

class Model {
public:
	std::vector<glm::vec3> positons;
	std::vector<glm::vec3> normals;
	std::vector<unsigned int> indices;
	std::map<Vertex, unsigned int> vertices;

	void addVertex(glm::vec3* position, glm::vec3* normal = nullptr)
	{
		// #TODO: Check for duplicate vertices
		for (size_t i = 0; i < positons.size(); i++) {
			if (position&&positons[i] != *position)
				continue;
			if (normal&&normals[i] != *normal)
				continue;

			indices.push_back(static_cast<unsigned int>(i));
			return;
				
		}

		if (position)
			positons.push_back(*position);
		if (normal)
			normals.push_back(*normal);
		indices.push_back(static_cast<unsigned int>(positons.size() - 1));
		
	}
};

class ObjLoader {

public:
	ObjLoader() = default;
	ObjLoader(std::string path);
	~ObjLoader() = default;
	void loadObj(std::string path);
	Mesh* toMesh();
private:
	void parseVertexPosition(std::string line);
	void parseVertexNormal(std::string line);
	void parseFaceIndices(std::string line);

	bool m_hasTexture = false;
	bool m_hasNormals = false;
	std::vector<glm::vec3> m_positions;
	std::vector<glm::vec3> m_normals;
	std::vector<glm::vec2> m_texturePositions;
	std::vector<VertexIndex> m_indices;
	std::vector<Face> m_triangles;

	void parseTexturePosition(std::string line);
};
#endif // __OBJLOADER_h__
