#ifndef __MESH_h__
#define __MESH_h__
#include "Base.h"
#include "VertexArray.h"

class Mesh {
public:
	static Mesh* Create();
public:
	Mesh() = default;
	Mesh(VertexArray* vertexArray);
	~Mesh();

	void setVertexArray(VertexArray* va) { m_vertexArray = ScopedPtr<VertexArray>(va); }
	VertexArray* getVertexArray() const { return m_vertexArray.get(); }
private:
	ScopedPtr<VertexArray> m_vertexArray;
};
#endif // __MESH_h__
