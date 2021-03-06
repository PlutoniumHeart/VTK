/*=========================================================================

  Program:   Visualization Toolkit

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkglShader.h"

#include <GL/glew.h>

namespace vtkgl {

Shader::Shader(Type type, const std::string &source)
  : ShaderType(type), Handle(0), Dirty(true), Source(source)
{
}

Shader::~Shader()
{
}

void Shader::SetType(Type type)
{
  this->ShaderType = type;
  this->Dirty = true;
}

void Shader::SetSource(const std::string &source)
{
  this->Source = source;
  this->Dirty = true;
}

bool Shader::Compile()
{
  if (this->Source.empty() || this->ShaderType == Unknown || !this->Dirty)
    {
    return false;
    }

  // Ensure we delete the previous shader if necessary.
  if (Handle != 0)
    {
    glDeleteShader(static_cast<GLuint>(Handle));
    Handle = 0;
    }

  GLenum type = ShaderType == Vertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;
  // TODO: handle geometry shaders if supported

  GLuint handle = glCreateShader(type);
  const GLchar *source = static_cast<const GLchar *>(this->Source.c_str());
  glShaderSource(handle, 1, &source, NULL);
  glCompileShader(handle);
  GLint isCompiled;
  glGetShaderiv(handle, GL_COMPILE_STATUS, &isCompiled);

  // Handle shader compilation failures.
  if (!isCompiled)
    {
    GLint length(0);
    glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &length);
    if (length > 1)
      {
      char *logMessage = new char[length];
      glGetShaderInfoLog(handle, length, NULL, logMessage);
      this->Error = logMessage;
      delete[] logMessage;
      }
    glDeleteShader(handle);
    return false;
  }

  // The shader compiled, store its handle and return success.
  this->Handle = static_cast<int>(handle);
  this->Dirty = false;

  return true;
}

void Shader::Cleanup()
{
  if (this->ShaderType == Unknown || this->Handle == 0)
    {
    return;
    }

  glDeleteShader(static_cast<GLuint>(this->Handle));
  this->Handle = 0;
  this->Dirty = false;
}

}
