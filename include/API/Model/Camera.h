#pragma once
#ifndef NUKEE_CAMERA_H
#define NUKEE_CAMERA_H
#include <boost/thread.hpp>
#include "render/irender.h"
#include "render/opengl/nukeogl.h"
#include "render/universal/nukebgfx.h"
#include <boost/bind.hpp>

class NUKEENGINE_API Camera : public NukeComponent
{
private:
	boost::thread* renderThread;


public:
    bool invertMouse = false;
    iRender *renderer = nullptr;
	Texture renderTex;
	int r_width = 640, r_height = 480;
    float fov = 90, _near = 0.3f, _far = 10000;
	unsigned long int renderLayers;
    bool freeMode;

	Camera();

	Camera(iRender* renderer);

	Camera(GameObject* parent, iRender* renderer);

	Vector3 ScreenPosToWorldRay(
		int mouseX, int mouseY,             // Mouse position, in pixels, from bottom-left corner of the window
		int screenWidth, int screenHeight,  // Window size, in pixels
		glm::mat4 ViewMatrix,               // Camera position and orientation
		glm::mat4 ProjectionMatrix         // Camera parameters (ratio, field of view, near and far planes)
		, glm::vec3& out_origin
	);

	bool  RayOBBIntersection(
		glm::vec3 ray_origin,        // Ray origin, in world space
		glm::vec3 ray_direction,     // Ray direction (NOT target position!), in world space. Must be normalize()'d.
		glm::vec3 aabb_min,          // Minimum X,Y,Z coords of the mesh when not transformed at all.
		glm::vec3 aabb_max,          // Maximum X,Y,Z coords. Often aabb_min*-1 if your mesh is centered, but it's not always the case.
		glm::mat4 ModelMatrix,       // Transformation applied to the mesh (which will thus be also applied to its bounding box)
		float& intersection_distance // Output : distance between ray_origin and the intersection with the OBB
	);

	void ProcessKeyboard();


	void Init(GameObject* parent);
	void FixedUpdate();
	void Update();
	void Reset();
	void Pause();
	void Destroy();
};
#endif // !NUKEE_CAMERA_H
