#include "pch.h"
#include "Mesh.h"

Mesh* Mesh::Create()
{
	return new Mesh();
}

Mesh::Mesh(VertexArray* vertexArray) : m_vertexArray(ScopedPtr<VertexArray>(vertexArray))
{

}

Mesh::~Mesh()
{

}