#pragma once

#include <glm/vec3.hpp>

#include "Component.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;

namespace aie
{
	class ShaderProgram;
}

namespace Minity
{
	enum LightType
	{
		DIRECTIONAL,
		OMNI,
		SPOT,
		LIGHT_TYPE_COUNT
	};

	//Abstarct light class. All lights must derive from this
	class Light
	{
	protected:
		//Settings for gizmos
		unsigned int gizSegments = 10;
		float gizMinSize = 0.1f, gizMaxSize = 0.75f;	//In units

	public:
		Light() = delete;
		Light(LightType lightType, bool a_isVisualised = true);

		//Common
		bool		isVisualised = true;	//Gizmo shown, Omni = Sphere, Spot = Cylinder, Directional = Thick line
		LightType	type;
		glm::vec3	position;
		glm::vec3	direction;
		glm::vec3	ambient;
		glm::vec3	diffuse;
		glm::vec3	specular;

		virtual void DrawVisualisation() = 0;	//Should eventually be incorporated into some kind of update/draw function
	};

	//Orthogonal light with direction. Generally used as a sun.
	class DirectionalLight : public Light
	{
	private:
		//Draw the directional light as short and stubby cylinder
		float gizDirLightLengthFactor = 0.75f;
		float gizDirLightWidthFactor = 1.5f;
	public:
		DirectionalLight(bool isVisualised = true);
		void DrawVisualisation() override;
	};

	//Point light where the light attenuates the further away the light is
	class OmniLight : public Light
	{
	protected:
		//Light setting limits
		float minLinearValue = 0.001f, maxLinearValue = 1.5f;
		float lin2quadFactor = 1.f;		//Multiplier between linear and quadratic values

		//Only used by SpotLight during construction
		OmniLight(LightType lightType, bool isVisualised = true);

	public:
		OmniLight(bool isVisualised = true);		//Set values manually later
		OmniLight(float a_constant, float a_linear, float a_quadratic, bool isVisualised = true);

		//Call this if you want to auto calculate quadratic
		virtual void RecalcQuadraticValue();

		//Draw the gizmo for this light
		void DrawVisualisation() override;

	public:
		float constant;
		float linear;
		float quadratic;
	};

	//Omni light with directional cone of focus
	class SpotLight : public OmniLight
	{
		float coneFactor = 1;		//Cone size multiplier (no resize is perfect)
		float outerCutOffLengthFactor = 0.60f;
	public:
		//Constructor will auto calculate quadFactor
		SpotLight(bool isVisualised = true);
		SpotLight(float constant, float linear, float quadratic, float cutOff, float outerCutOff, bool isVisualised = true);

		void DrawVisualisation() override;

	public:
		float cutOff;
		float outerCutOff;
	};
}
