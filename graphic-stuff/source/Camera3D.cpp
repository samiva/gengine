#include "pch.h"
#include "Camera3D.h"
#include "gtc/matrix_transform.hpp"
Camera3D::Camera3D()
{
	setProjection(800, 600);
	calculateView();
	calculateViewProjection();
}

Camera3D::~Camera3D()
{

}

void Camera3D::setProjection(const float width, const float height)
{
	m_projectionMat = glm::perspective(m_fovy, width / height, m_zNear, m_zFar);
}

void Camera3D::calculateViewProjection()
{
	m_viewProjMat = m_projectionMat * m_viewMat;
}

void Camera3D::calculateView()
{
	//glm::vec3 dir(0.0f, 0.0f, 1.0f);
	//auto target = m_position - dir * 10.0f;
	//m_viewMat = glm::lookAt(m_position, target, glm::vec3(0.0f, 1.0f, 0.0f));
	
	auto T = glm::translate(glm::mat4(1), m_position);
	auto Rx = glm::rotate(glm::mat4(1), m_rotation.x, glm::vec3(1, 0, 0));
	auto Ry = glm::rotate(glm::mat4(1), m_rotation.y, glm::vec3(0, 1, 0));
	auto Rz = glm::rotate(glm::mat4(1), m_rotation.z, glm::vec3(0, 0, 1));
	auto R = Rz*Ry*Rx;
	m_viewMat = glm::inverse(T*R);
	m_viewProjMat = m_projectionMat * m_viewMat;
}