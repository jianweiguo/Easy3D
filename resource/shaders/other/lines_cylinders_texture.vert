#version 150
// please send comments or report bug to: liangliang.nan@gmail.com

// It uses geometry shader for vertex generation.
// The code does not cover round caps.

//#extension GL_EXT_gpu_shader4 : enable

layout(std140) uniform Matrices {
	mat4 MV;
	mat4 invMV;
	mat4 PROJ;
	mat4 MVP;
	mat4 MANIP;
	mat3 NORMAL;
	mat4 SHADOW;
	bool clippingPlaneEnabled;
	bool crossSectionEnabled;
	vec4 clippingPlane0;
	vec4 clippingPlane1;
};

in  vec3 vtx_position;	// point position
in  vec2 vtx_texcoord;

out vec2 vOutTexcoord;

void main()
{
	gl_Position = MV * MANIP * vec4(vtx_position, 1.0);

	vOutTexcoord = vtx_texcoord;
}