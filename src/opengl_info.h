/*
*	Copyright (C) 2015 by Liangliang Nan (liangliang.nan@gmail.com)
*
*	This file is part of Mapple: software for processing and rendering
*   meshes and point clouds.
*
*	Mapple is free software; you can redistribute it and/or modify
*	it under the terms of the GNU General Public License Version 3
*	as published by the Free Software Foundation.
*
*	Mapple is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*	GNU General Public License for more details.
*
*	You should have received a copy of the GNU General Public License
*	along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef _OPENGL_OPENGL_INFO_H_
#define _OPENGL_OPENGL_INFO_H_

#include <string>
#include <iostream>
#include <map>


class OpenglInfo
{
public:
	static bool init();
	static bool is_initialized();

	static bool is_supported(const std::string& name);

	// sets the output stream for the messages.
	// if null, std::cout is the default output stream
	static void set_output(std::ostream* out);

	// -------------- general information --------------

	// returns either GL_CONTEXT_CORE_PROFILE_BIT or GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
	static int gl_profile();

	static std::string glew_version();

	static std::string gl_vendor();
	static std::string gl_renderer();
	static std::string gl_version();
	static std::string gl_extensions();
	static std::string glsl_version();

	static int		   gl_major_version();
	static int         gl_minor_version();

	static float	   glew_version_number();
	static float	   gl_version_number();
	static float	   glsl_version_number();

	// ----------------- GPU memory  -------------------

	// in MB. 
	// returns 0 if the query fails.
	// NOTE: (1) OpenGL 2.0 is required.
	//		 (2) currently only NVidia GPU is supported 
	static int total_gpu_memory();
	static int available_gpu_memory();

	// --------------- buffer information ----------------

	/// display current binded buffer info
	static void getCurrentBufferInfo();
	/// display the buffer information
	static void getBufferInfo(unsigned int target, int bufferName);

	// --------------- GLSL information (GLSL version 4.2 is supported )----------------

	// display VAO information, including its attributes
	static void getVAOInfo(unsigned int buffer);

	/// display detailed info for a program
	static void getProgramInfo(unsigned int program);

	// display detailed info for attributes in a program
	static void getAttributesInfo(unsigned int program);

	// display info for all active uniforms in a program
	static void getUniformsInfo(unsigned int program);

	// display a uniform's value(s)
	static void getUniformInfo(unsigned int program, const std::string& uniName);

	// display the values for a uniform in a named block
	static void getUniformInBlockInfo(unsigned int program, const std::string& blockName, const std::string& uniName);

private:
	// printf() style + plus a newline at the end
	static void _add_message(std::string format, ...);

	static bool _init();

	static int  _get_rows(unsigned int type);
	static int  _get_columns(unsigned int type);

	static void _display_uniformf(float *f, int rows, int columns);
	static void _display_uniformi(int *f, int rows, int columns);
	static void _display_uniformui(unsigned int *f, int rows, int columns);
	static void _display_uniformd(double *f, int rows, int columns);
	static int  _get_uniform_byte_size(int size, int uniType, int arrayStride, int matStride);

	enum Types { DONT_KNOW, INT, UNSIGNED_INT, FLOAT, DOUBLE };
	static Types _get_type(unsigned int type);

private:
	static bool	_glew_initialized;

	static bool _spInit;

	static std::ostream*  _output_stream;

	static std::map<int, std::string>	spBufferAccess;
	static std::map<int, std::string>	spBufferUsage;
	static std::map<int, std::string>	spBufferBinding;
	static std::map<int, int>			spBufferBound;
	static std::map<int, int>			spBoundBuffer;
	static std::map<int, std::string>	spDataF;
	static std::map<int, std::string>	spGLSLType;
	static std::map<int, int> 			spGLSLTypeSize;
	static std::map<int, std::string>	spShaderType;
	static std::map<int, std::string>	spTransFeedBufferMode;
	static std::map<int, std::string>	spGLSLPrimitives;
	static std::map<int, std::string>	spTessGenSpacing;
	static std::map<int, std::string>	spVertexOrder;
};


#endif

