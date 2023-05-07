#include "pch.h"
#include "ObjLoader.h"
#include "Logger.h"
#include <sstream>

ObjLoader::ObjLoader(std::string path)
{
	loadObj(path);
}

void ObjLoader::loadObj(std::string path)
{
	std::ifstream stream(path, std::ios_base::binary);
	if(!stream.fail())
	{

		std::string line;
		while (!stream.eof()) {
			char c;
			stream.get(c);
			if (stream.eof())
				break;
			switch (c) {
			case 'v':
			{
				char c2;
				stream.get(c2);
				switch (c2) {
				case 't':
				{
					// Texture: object has textures
					m_hasTexture = true;
					std::getline(stream, line);
					parseTexturePosition(line);
				}
				case 'n':
				{
					// normal
					//stream.putback(c2);
					//stream.putback(c);
					m_hasNormals = true;
					std::getline(stream, line);
					parseVertexNormal(line);
				}
				break;
				case ' ':
				{
					// position
					//stream.putback(c2);
					//stream.putback(c);
					std::getline(stream, line);
					parseVertexPosition(line);
				}
				break;
				}
			}
			break;
			case 'f':
			{
				// Indices for face
				//stream.putback(c);
				std::getline(stream, line);
				parseFaceIndices(line);
			}
			break;
			default:
				stream.ignore(256, '\n');
				break;
			}
		}
	}
	else {
		Logger::WriteErrorString("Could not open file");
	}

}

Mesh* ObjLoader::toMesh()
{

	// First create model
	Model m;

	for (auto& tri : m_triangles) {
		for (auto& ind : tri.indices) {
			m.addVertex(&m_positions[ind.position - 1], &m_normals[ind.normal - 1]);
		}
	}

	std::vector<float> vertexData;
	for (size_t i = 0; i < m.positons.size(); i++) {
		// Position
		vertexData.push_back(m.positons[i].x);
		vertexData.push_back(m.positons[i].y);
		vertexData.push_back(m.positons[i].z);

		// Normal
		vertexData.push_back(m.normals[i].x);
		vertexData.push_back(m.normals[i].y);
		vertexData.push_back(m.normals[i].z);

	}
	if (vertexData.size() == 0)
		return nullptr;
	auto indexData = m.indices;
	auto va = VertexArray::Create();

	auto vb = VertexBuffer::Create();
	vb->setData(static_cast<void*>(&vertexData[0]), vertexData.size() * sizeof(float));

	Layout l;
	l.addMember<float>(3);
	l.addMember<float>(3);
	vb->setLayout(l);

	auto ib = IndexBuffer::Create();
	ib->setData(static_cast<void*>(&indexData[0]), indexData.size() * sizeof(float), static_cast<unsigned int>(indexData.size()));
	va->addVertexBuffer(vb);
	va->addIndexBuffer(ib);

	auto mesh = Mesh::Create();
	mesh->setVertexArray(va);
	return mesh;
}

void ObjLoader::parseVertexPosition(std::string line)
{
	std::cout << line << std::endl;
	std::stringstream str(line);
	//str.ignore(256, ' ');
	float x, y, z;
	str >> x;
	str >> y;
	str >> z;
	m_positions.push_back({ x,y,z });


	std::cout << "position values: {" << x << ", " << y << ", " << z << "}" << std::endl;
}

void ObjLoader::parseVertexNormal(std::string line)
{
	std::cout << line << std::endl;
	std::stringstream str(line);
	//str.ignore(256, ' ');
	float x, y, z;
	str >> x;
	str >> y;
	str >> z;
	m_normals.push_back({ x,y,z });


	std::cout << "normal values: {" << x << ", " << y << ", " << z << "}" << std::endl;
}

void ObjLoader::parseFaceIndices(std::string line)
{
	std::cout << line << std::endl;
	std::stringstream ss(line);
	char c;
	VertexIndex vertInd;
	Face t;
	while (ss.get(c))
	{
		if (c == ' ') {
			ss >> vertInd.position;
			if (m_hasTexture) {
				// texture index
				// Ignore the divider
				ss.ignore(1);
				// Read the texture index
				ss >> vertInd.texture;
			}
			else {
				ss.ignore(1);
			}
			
			ss.ignore(1);
			ss >> vertInd.normal;
			m_indices.push_back(vertInd);
			t.addVertexIndex(vertInd);

		}
	}
	m_triangles.push_back(t);
}

void ObjLoader::parseTexturePosition(std::string line)
{
	std::cout << line << std::endl;
	float x, y;

	std::stringstream ss(line);
	ss >> x;
	ss >> y;
	m_texturePositions.push_back({ x, y });
}
