#ifndef __CAMERA3D_h__
#define __CAMERA3D_h__
#include "pch.h"
#include "glm.hpp"

class Camera3D
{
public:
	Camera3D();
	~Camera3D();
	void setProjection(const float width, const float height);
	inline void setPosition(const glm::vec3& pos) { m_position = pos; calculateView(); }
	inline void setRotation(const glm::vec3& rot) { m_rotation = rot; calculateView(); }
	inline const glm::mat4& getViewProjection() const { return m_viewProjMat; }
	inline const glm::mat4& getView() const { return m_viewMat; }
	inline const glm::mat4& getProjection() const { return m_projectionMat; }
private:
	void calculateViewProjection();
	void calculateView();
private:
	glm::mat4 m_projectionMat;
	glm::mat4 m_viewMat;
	glm::mat4 m_viewProjMat;

	glm::vec3 m_position{0.0f,0.0f,10.0f};
	glm::vec3 m_rotation{0.0f,0.0f,0.0f}; // For now use euler angles to store rotation.

	float m_fovy = 45.0f;
	float m_zNear = .1f;
	float m_zFar = 1000.0f;

};
#endif // __CAMERA3D_h__
