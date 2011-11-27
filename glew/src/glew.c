/*
** The OpenGL Extension Wrangler Library
** Copyright (C) 2003, 2002, Milan Ikits <milan.ikits@ieee.org>
** Copyright (C) 2003, 2002, Marcelo E. Magallon <mmagallo@debian.org>
** Copyright (C) 2002, Lev Povalahev <levp@gmx.net>
** All rights reserved.
** 
** Redistribution and use in source and binary forms, with or without 
** modification, are permitted provided that the following conditions are met:
** 
** * Redistributions of source code must retain the above copyright notice, 
**   this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice, 
**   this list of conditions and the following disclaimer in the documentation 
**   and/or other materials provided with the distribution.
** * The name of the author may be used to endorse or promote products 
**   derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
** THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <GL/glew.h>
#include <GL/wglew.h>
#include <GL/glxew.h>

#ifdef _WIN32
#  define glewGetProcAddress(name) wglGetProcAddress(name)
#else
#  ifdef GLEW_NEEDS_CUSTOM_GET_PROCADDRESS
#    define glewGetProcAddress(name) __dlopenGetProcAddress(name)
#  else
#    define glewGetProcAddress(name) (*glXGetProcAddressARB)(name)
#  endif /* GLEW_NEEDS_CUSTOM_GET_PROCADDRESS */
#endif /* _WIN32 */

#ifdef GLEW_NEEDS_CUSTOM_GET_PROCADDRESS
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static void* __dlopenGetProcAddress (const GLubyte *procName)
{
  static void *h = NULL;
  static void *gpa;

  if (!h)
  {
    if (!(h = dlopen(NULL, RTLD_LAZY | RTLD_LOCAL))) return NULL;
    gpa = dlsym(h, "glXGetProcAddress");
  }

  if (gpa != NULL)
    return ((void* (*)(const GLubyte*))gpa)(procName);
  else
    return dlsym(h, (const char *)procName);
}
#endif /* GLEW_NEEDS_CUSTOM_GET_PROCADDRESS */

/* ----------------------------- GL_VERSION_1_1 ---------------------------- */

#ifdef GL_VERSION_1_1

GLboolean GLEW_VERSION_1_1 = GL_FALSE;

#endif /* GL_VERSION_1_1 */

/* ----------------------------- GL_VERSION_1_2 ---------------------------- */

#ifdef GL_VERSION_1_2

PFNGLCOPYTEXSUBIMAGE3DPROC glewCopyTexSubImage3D = NULL;
PFNGLDRAWRANGEELEMENTSPROC glewDrawRangeElements = NULL;
PFNGLTEXIMAGE3DPROC glewTexImage3D = NULL;
PFNGLTEXSUBIMAGE3DPROC glewTexSubImage3D = NULL;

static GLboolean _glewInit_GL_VERSION_1_2 (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)glewGetProcAddress("glCopyTexSubImage3D")) == NULL) || r;
  r = ((glewDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)glewGetProcAddress("glDrawRangeElements")) == NULL) || r;
  r = ((glewTexImage3D = (PFNGLTEXIMAGE3DPROC)glewGetProcAddress("glTexImage3D")) == NULL) || r;
  r = ((glewTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)glewGetProcAddress("glTexSubImage3D")) == NULL) || r;

  return r;
}

GLboolean GLEW_VERSION_1_2 = GL_FALSE;

#endif /* GL_VERSION_1_2 */

/* ----------------------------- GL_VERSION_1_3 ---------------------------- */

#ifdef GL_VERSION_1_3

PFNGLACTIVETEXTUREPROC glewActiveTexture = NULL;
PFNGLCLIENTACTIVETEXTUREPROC glewClientActiveTexture = NULL;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glewCompressedTexImage1D = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glewCompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glewCompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glewCompressedTexSubImage1D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glewCompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glewCompressedTexSubImage3D = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glewGetCompressedTexImage = NULL;
PFNGLLOADTRANSPOSEMATRIXDPROC glewLoadTransposeMatrixd = NULL;
PFNGLLOADTRANSPOSEMATRIXFPROC glewLoadTransposeMatrixf = NULL;
PFNGLMULTTRANSPOSEMATRIXDPROC glewMultTransposeMatrixd = NULL;
PFNGLMULTTRANSPOSEMATRIXFPROC glewMultTransposeMatrixf = NULL;
PFNGLMULTITEXCOORD1DPROC glewMultiTexCoord1d = NULL;
PFNGLMULTITEXCOORD1DVPROC glewMultiTexCoord1dv = NULL;
PFNGLMULTITEXCOORD1FPROC glewMultiTexCoord1f = NULL;
PFNGLMULTITEXCOORD1FVPROC glewMultiTexCoord1fv = NULL;
PFNGLMULTITEXCOORD1IPROC glewMultiTexCoord1i = NULL;
PFNGLMULTITEXCOORD1IVPROC glewMultiTexCoord1iv = NULL;
PFNGLMULTITEXCOORD1SPROC glewMultiTexCoord1s = NULL;
PFNGLMULTITEXCOORD1SVPROC glewMultiTexCoord1sv = NULL;
PFNGLMULTITEXCOORD2DPROC glewMultiTexCoord2d = NULL;
PFNGLMULTITEXCOORD2DVPROC glewMultiTexCoord2dv = NULL;
PFNGLMULTITEXCOORD2FPROC glewMultiTexCoord2f = NULL;
PFNGLMULTITEXCOORD2FVPROC glewMultiTexCoord2fv = NULL;
PFNGLMULTITEXCOORD2IPROC glewMultiTexCoord2i = NULL;
PFNGLMULTITEXCOORD2IVPROC glewMultiTexCoord2iv = NULL;
PFNGLMULTITEXCOORD2SPROC glewMultiTexCoord2s = NULL;
PFNGLMULTITEXCOORD2SVPROC glewMultiTexCoord2sv = NULL;
PFNGLMULTITEXCOORD3DPROC glewMultiTexCoord3d = NULL;
PFNGLMULTITEXCOORD3DVPROC glewMultiTexCoord3dv = NULL;
PFNGLMULTITEXCOORD3FPROC glewMultiTexCoord3f = NULL;
PFNGLMULTITEXCOORD3FVPROC glewMultiTexCoord3fv = NULL;
PFNGLMULTITEXCOORD3IPROC glewMultiTexCoord3i = NULL;
PFNGLMULTITEXCOORD3IVPROC glewMultiTexCoord3iv = NULL;
PFNGLMULTITEXCOORD3SPROC glewMultiTexCoord3s = NULL;
PFNGLMULTITEXCOORD3SVPROC glewMultiTexCoord3sv = NULL;
PFNGLMULTITEXCOORD4DPROC glewMultiTexCoord4d = NULL;
PFNGLMULTITEXCOORD4DVPROC glewMultiTexCoord4dv = NULL;
PFNGLMULTITEXCOORD4FPROC glewMultiTexCoord4f = NULL;
PFNGLMULTITEXCOORD4FVPROC glewMultiTexCoord4fv = NULL;
PFNGLMULTITEXCOORD4IPROC glewMultiTexCoord4i = NULL;
PFNGLMULTITEXCOORD4IVPROC glewMultiTexCoord4iv = NULL;
PFNGLMULTITEXCOORD4SPROC glewMultiTexCoord4s = NULL;
PFNGLMULTITEXCOORD4SVPROC glewMultiTexCoord4sv = NULL;
PFNGLSAMPLECOVERAGEPROC glewSampleCoverage = NULL;

static GLboolean _glewInit_GL_VERSION_1_3 (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewActiveTexture = (PFNGLACTIVETEXTUREPROC)glewGetProcAddress("glActiveTexture")) == NULL) || r;
  r = ((glewClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)glewGetProcAddress("glClientActiveTexture")) == NULL) || r;
  r = ((glewCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)glewGetProcAddress("glCompressedTexImage1D")) == NULL) || r;
  r = ((glewCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)glewGetProcAddress("glCompressedTexImage2D")) == NULL) || r;
  r = ((glewCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)glewGetProcAddress("glCompressedTexImage3D")) == NULL) || r;
  r = ((glewCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)glewGetProcAddress("glCompressedTexSubImage1D")) == NULL) || r;
  r = ((glewCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)glewGetProcAddress("glCompressedTexSubImage2D")) == NULL) || r;
  r = ((glewCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)glewGetProcAddress("glCompressedTexSubImage3D")) == NULL) || r;
  r = ((glewGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)glewGetProcAddress("glGetCompressedTexImage")) == NULL) || r;
  r = ((glewLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC)glewGetProcAddress("glLoadTransposeMatrixd")) == NULL) || r;
  r = ((glewLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC)glewGetProcAddress("glLoadTransposeMatrixf")) == NULL) || r;
  r = ((glewMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC)glewGetProcAddress("glMultTransposeMatrixd")) == NULL) || r;
  r = ((glewMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC)glewGetProcAddress("glMultTransposeMatrixf")) == NULL) || r;
  r = ((glewMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC)glewGetProcAddress("glMultiTexCoord1d")) == NULL) || r;
  r = ((glewMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC)glewGetProcAddress("glMultiTexCoord1dv")) == NULL) || r;
  r = ((glewMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC)glewGetProcAddress("glMultiTexCoord1f")) == NULL) || r;
  r = ((glewMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC)glewGetProcAddress("glMultiTexCoord1fv")) == NULL) || r;
  r = ((glewMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC)glewGetProcAddress("glMultiTexCoord1i")) == NULL) || r;
  r = ((glewMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC)glewGetProcAddress("glMultiTexCoord1iv")) == NULL) || r;
  r = ((glewMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC)glewGetProcAddress("glMultiTexCoord1s")) == NULL) || r;
  r = ((glewMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC)glewGetProcAddress("glMultiTexCoord1sv")) == NULL) || r;
  r = ((glewMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC)glewGetProcAddress("glMultiTexCoord2d")) == NULL) || r;
  r = ((glewMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC)glewGetProcAddress("glMultiTexCoord2dv")) == NULL) || r;
  r = ((glewMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC)glewGetProcAddress("glMultiTexCoord2f")) == NULL) || r;
  r = ((glewMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC)glewGetProcAddress("glMultiTexCoord2fv")) == NULL) || r;
  r = ((glewMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC)glewGetProcAddress("glMultiTexCoord2i")) == NULL) || r;
  r = ((glewMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC)glewGetProcAddress("glMultiTexCoord2iv")) == NULL) || r;
  r = ((glewMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC)glewGetProcAddress("glMultiTexCoord2s")) == NULL) || r;
  r = ((glewMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC)glewGetProcAddress("glMultiTexCoord2sv")) == NULL) || r;
  r = ((glewMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC)glewGetProcAddress("glMultiTexCoord3d")) == NULL) || r;
  r = ((glewMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC)glewGetProcAddress("glMultiTexCoord3dv")) == NULL) || r;
  r = ((glewMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC)glewGetProcAddress("glMultiTexCoord3f")) == NULL) || r;
  r = ((glewMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC)glewGetProcAddress("glMultiTexCoord3fv")) == NULL) || r;
  r = ((glewMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC)glewGetProcAddress("glMultiTexCoord3i")) == NULL) || r;
  r = ((glewMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC)glewGetProcAddress("glMultiTexCoord3iv")) == NULL) || r;
  r = ((glewMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC)glewGetProcAddress("glMultiTexCoord3s")) == NULL) || r;
  r = ((glewMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC)glewGetProcAddress("glMultiTexCoord3sv")) == NULL) || r;
  r = ((glewMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC)glewGetProcAddress("glMultiTexCoord4d")) == NULL) || r;
  r = ((glewMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC)glewGetProcAddress("glMultiTexCoord4dv")) == NULL) || r;
  r = ((glewMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)glewGetProcAddress("glMultiTexCoord4f")) == NULL) || r;
  r = ((glewMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC)glewGetProcAddress("glMultiTexCoord4fv")) == NULL) || r;
  r = ((glewMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC)glewGetProcAddress("glMultiTexCoord4i")) == NULL) || r;
  r = ((glewMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC)glewGetProcAddress("glMultiTexCoord4iv")) == NULL) || r;
  r = ((glewMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC)glewGetProcAddress("glMultiTexCoord4s")) == NULL) || r;
  r = ((glewMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC)glewGetProcAddress("glMultiTexCoord4sv")) == NULL) || r;
  r = ((glewSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)glewGetProcAddress("glSampleCoverage")) == NULL) || r;

  return r;
}

GLboolean GLEW_VERSION_1_3 = GL_FALSE;

#endif /* GL_VERSION_1_3 */

/* ----------------------------- GL_VERSION_1_4 ---------------------------- */

#ifdef GL_VERSION_1_4

PFNGLBLENDFUNCSEPARATEPROC glewBlendFuncSeparate = NULL;
PFNGLFOGCOORDPOINTERPROC glewFogCoordPointer = NULL;
PFNGLFOGCOORDDPROC glewFogCoordd = NULL;
PFNGLFOGCOORDDVPROC glewFogCoorddv = NULL;
PFNGLFOGCOORDFPROC glewFogCoordf = NULL;
PFNGLFOGCOORDFVPROC glewFogCoordfv = NULL;
PFNGLMULTIDRAWARRAYSPROC glewMultiDrawArrays = NULL;
PFNGLMULTIDRAWELEMENTSPROC glewMultiDrawElements = NULL;
PFNGLPOINTPARAMETERFPROC glewPointParameterf = NULL;
PFNGLPOINTPARAMETERFVPROC glewPointParameterfv = NULL;
PFNGLSECONDARYCOLOR3BPROC glewSecondaryColor3b = NULL;
PFNGLSECONDARYCOLOR3BVPROC glewSecondaryColor3bv = NULL;
PFNGLSECONDARYCOLOR3DPROC glewSecondaryColor3d = NULL;
PFNGLSECONDARYCOLOR3DVPROC glewSecondaryColor3dv = NULL;
PFNGLSECONDARYCOLOR3FPROC glewSecondaryColor3f = NULL;
PFNGLSECONDARYCOLOR3FVPROC glewSecondaryColor3fv = NULL;
PFNGLSECONDARYCOLOR3IPROC glewSecondaryColor3i = NULL;
PFNGLSECONDARYCOLOR3IVPROC glewSecondaryColor3iv = NULL;
PFNGLSECONDARYCOLOR3SPROC glewSecondaryColor3s = NULL;
PFNGLSECONDARYCOLOR3SVPROC glewSecondaryColor3sv = NULL;
PFNGLSECONDARYCOLOR3UBPROC glewSecondaryColor3ub = NULL;
PFNGLSECONDARYCOLOR3UBVPROC glewSecondaryColor3ubv = NULL;
PFNGLSECONDARYCOLOR3UIPROC glewSecondaryColor3ui = NULL;
PFNGLSECONDARYCOLOR3UIVPROC glewSecondaryColor3uiv = NULL;
PFNGLSECONDARYCOLOR3USPROC glewSecondaryColor3us = NULL;
PFNGLSECONDARYCOLOR3USVPROC glewSecondaryColor3usv = NULL;
PFNGLSECONDARYCOLORPOINTERPROC glewSecondaryColorPointer = NULL;
PFNGLWINDOWPOS2DPROC glewWindowPos2d = NULL;
PFNGLWINDOWPOS2DVPROC glewWindowPos2dv = NULL;
PFNGLWINDOWPOS2FPROC glewWindowPos2f = NULL;
PFNGLWINDOWPOS2FVPROC glewWindowPos2fv = NULL;
PFNGLWINDOWPOS2IPROC glewWindowPos2i = NULL;
PFNGLWINDOWPOS2IVPROC glewWindowPos2iv = NULL;
PFNGLWINDOWPOS2SPROC glewWindowPos2s = NULL;
PFNGLWINDOWPOS2SVPROC glewWindowPos2sv = NULL;
PFNGLWINDOWPOS3DPROC glewWindowPos3d = NULL;
PFNGLWINDOWPOS3DVPROC glewWindowPos3dv = NULL;
PFNGLWINDOWPOS3FPROC glewWindowPos3f = NULL;
PFNGLWINDOWPOS3FVPROC glewWindowPos3fv = NULL;
PFNGLWINDOWPOS3IPROC glewWindowPos3i = NULL;
PFNGLWINDOWPOS3IVPROC glewWindowPos3iv = NULL;
PFNGLWINDOWPOS3SPROC glewWindowPos3s = NULL;
PFNGLWINDOWPOS3SVPROC glewWindowPos3sv = NULL;

static GLboolean _glewInit_GL_VERSION_1_4 (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)glewGetProcAddress("glBlendFuncSeparate")) == NULL) || r;
  r = ((glewFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC)glewGetProcAddress("glFogCoordPointer")) == NULL) || r;
  r = ((glewFogCoordd = (PFNGLFOGCOORDDPROC)glewGetProcAddress("glFogCoordd")) == NULL) || r;
  r = ((glewFogCoorddv = (PFNGLFOGCOORDDVPROC)glewGetProcAddress("glFogCoorddv")) == NULL) || r;
  r = ((glewFogCoordf = (PFNGLFOGCOORDFPROC)glewGetProcAddress("glFogCoordf")) == NULL) || r;
  r = ((glewFogCoordfv = (PFNGLFOGCOORDFVPROC)glewGetProcAddress("glFogCoordfv")) == NULL) || r;
  r = ((glewMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)glewGetProcAddress("glMultiDrawArrays")) == NULL) || r;
  r = ((glewMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)glewGetProcAddress("glMultiDrawElements")) == NULL) || r;
  r = ((glewPointParameterf = (PFNGLPOINTPARAMETERFPROC)glewGetProcAddress("glPointParameterf")) == NULL) || r;
  r = ((glewPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)glewGetProcAddress("glPointParameterfv")) == NULL) || r;
  r = ((glewSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC)glewGetProcAddress("glSecondaryColor3b")) == NULL) || r;
  r = ((glewSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC)glewGetProcAddress("glSecondaryColor3bv")) == NULL) || r;
  r = ((glewSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC)glewGetProcAddress("glSecondaryColor3d")) == NULL) || r;
  r = ((glewSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC)glewGetProcAddress("glSecondaryColor3dv")) == NULL) || r;
  r = ((glewSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC)glewGetProcAddress("glSecondaryColor3f")) == NULL) || r;
  r = ((glewSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)glewGetProcAddress("glSecondaryColor3fv")) == NULL) || r;
  r = ((glewSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC)glewGetProcAddress("glSecondaryColor3i")) == NULL) || r;
  r = ((glewSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC)glewGetProcAddress("glSecondaryColor3iv")) == NULL) || r;
  r = ((glewSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC)glewGetProcAddress("glSecondaryColor3s")) == NULL) || r;
  r = ((glewSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC)glewGetProcAddress("glSecondaryColor3sv")) == NULL) || r;
  r = ((glewSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC)glewGetProcAddress("glSecondaryColor3ub")) == NULL) || r;
  r = ((glewSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC)glewGetProcAddress("glSecondaryColor3ubv")) == NULL) || r;
  r = ((glewSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC)glewGetProcAddress("glSecondaryColor3ui")) == NULL) || r;
  r = ((glewSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC)glewGetProcAddress("glSecondaryColor3uiv")) == NULL) || r;
  r = ((glewSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC)glewGetProcAddress("glSecondaryColor3us")) == NULL) || r;
  r = ((glewSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC)glewGetProcAddress("glSecondaryColor3usv")) == NULL) || r;
  r = ((glewSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC)glewGetProcAddress("glSecondaryColorPointer")) == NULL) || r;
  r = ((glewWindowPos2d = (PFNGLWINDOWPOS2DPROC)glewGetProcAddress("glWindowPos2d")) == NULL) || r;
  r = ((glewWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)glewGetProcAddress("glWindowPos2dv")) == NULL) || r;
  r = ((glewWindowPos2f = (PFNGLWINDOWPOS2FPROC)glewGetProcAddress("glWindowPos2f")) == NULL) || r;
  r = ((glewWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)glewGetProcAddress("glWindowPos2fv")) == NULL) || r;
  r = ((glewWindowPos2i = (PFNGLWINDOWPOS2IPROC)glewGetProcAddress("glWindowPos2i")) == NULL) || r;
  r = ((glewWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)glewGetProcAddress("glWindowPos2iv")) == NULL) || r;
  r = ((glewWindowPos2s = (PFNGLWINDOWPOS2SPROC)glewGetProcAddress("glWindowPos2s")) == NULL) || r;
  r = ((glewWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)glewGetProcAddress("glWindowPos2sv")) == NULL) || r;
  r = ((glewWindowPos3d = (PFNGLWINDOWPOS3DPROC)glewGetProcAddress("glWindowPos3d")) == NULL) || r;
  r = ((glewWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)glewGetProcAddress("glWindowPos3dv")) == NULL) || r;
  r = ((glewWindowPos3f = (PFNGLWINDOWPOS3FPROC)glewGetProcAddress("glWindowPos3f")) == NULL) || r;
  r = ((glewWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)glewGetProcAddress("glWindowPos3fv")) == NULL) || r;
  r = ((glewWindowPos3i = (PFNGLWINDOWPOS3IPROC)glewGetProcAddress("glWindowPos3i")) == NULL) || r;
  r = ((glewWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)glewGetProcAddress("glWindowPos3iv")) == NULL) || r;
  r = ((glewWindowPos3s = (PFNGLWINDOWPOS3SPROC)glewGetProcAddress("glWindowPos3s")) == NULL) || r;
  r = ((glewWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)glewGetProcAddress("glWindowPos3sv")) == NULL) || r;

  return r;
}

GLboolean GLEW_VERSION_1_4 = GL_FALSE;

#endif /* GL_VERSION_1_4 */

/* -------------------------- GL_3DFX_multisample -------------------------- */

#ifdef GL_3DFX_multisample

GLboolean GLEW_3DFX_multisample = GL_FALSE;

#endif /* GL_3DFX_multisample */

/* ---------------------------- GL_3DFX_tbuffer ---------------------------- */

#ifdef GL_3DFX_tbuffer

PFNGLTBUFFERMASK3DFXPROC glewTbufferMask3DFX = NULL;

static GLboolean _glewInit_GL_3DFX_tbuffer (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewTbufferMask3DFX = (PFNGLTBUFFERMASK3DFXPROC)glewGetProcAddress("glTbufferMask3DFX")) == NULL) || r;

  return r;
}

GLboolean GLEW_3DFX_tbuffer = GL_FALSE;

#endif /* GL_3DFX_tbuffer */

/* -------------------- GL_3DFX_texture_compression_FXT1 ------------------- */

#ifdef GL_3DFX_texture_compression_FXT1

GLboolean GLEW_3DFX_texture_compression_FXT1 = GL_FALSE;

#endif /* GL_3DFX_texture_compression_FXT1 */

/* ------------------------ GL_APPLE_client_storage ------------------------ */

#ifdef GL_APPLE_client_storage

GLboolean GLEW_APPLE_client_storage = GL_FALSE;

#endif /* GL_APPLE_client_storage */

/* ------------------------- GL_APPLE_element_array ------------------------ */

#ifdef GL_APPLE_element_array

PFNGLDRAWELEMENTARRAYAPPLEPROC glewDrawElementArrayAPPLE = NULL;
PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC glewDrawRangeElementArrayAPPLE = NULL;
PFNGLELEMENTPOINTERAPPLEPROC glewElementPointerAPPLE = NULL;
PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC glewMultiDrawElementArrayAPPLE = NULL;
PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC glewMultiDrawRangeElementArrayAPPLE = NULL;

static GLboolean _glewInit_GL_APPLE_element_array (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewDrawElementArrayAPPLE = (PFNGLDRAWELEMENTARRAYAPPLEPROC)glewGetProcAddress("glDrawElementArrayAPPLE")) == NULL) || r;
  r = ((glewDrawRangeElementArrayAPPLE = (PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)glewGetProcAddress("glDrawRangeElementArrayAPPLE")) == NULL) || r;
  r = ((glewElementPointerAPPLE = (PFNGLELEMENTPOINTERAPPLEPROC)glewGetProcAddress("glElementPointerAPPLE")) == NULL) || r;
  r = ((glewMultiDrawElementArrayAPPLE = (PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)glewGetProcAddress("glMultiDrawElementArrayAPPLE")) == NULL) || r;
  r = ((glewMultiDrawRangeElementArrayAPPLE = (PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)glewGetProcAddress("glMultiDrawRangeElementArrayAPPLE")) == NULL) || r;

  return r;
}

GLboolean GLEW_APPLE_element_array = GL_FALSE;

#endif /* GL_APPLE_element_array */

/* ----------------------------- GL_APPLE_fence ---------------------------- */

#ifdef GL_APPLE_fence

PFNGLDELETEFENCESAPPLEPROC glewDeleteFencesAPPLE = NULL;
PFNGLFINISHFENCEAPPLEPROC glewFinishFenceAPPLE = NULL;
PFNGLFINISHOBJECTAPPLEPROC glewFinishObjectAPPLE = NULL;
PFNGLGENFENCESAPPLEPROC glewGenFencesAPPLE = NULL;
PFNGLISFENCEAPPLEPROC glewIsFenceAPPLE = NULL;
PFNGLSETFENCEAPPLEPROC glewSetFenceAPPLE = NULL;
PFNGLTESTFENCEAPPLEPROC glewTestFenceAPPLE = NULL;
PFNGLTESTOBJECTAPPLEPROC glewTestObjectAPPLE = NULL;

static GLboolean _glewInit_GL_APPLE_fence (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewDeleteFencesAPPLE = (PFNGLDELETEFENCESAPPLEPROC)glewGetProcAddress("glDeleteFencesAPPLE")) == NULL) || r;
  r = ((glewFinishFenceAPPLE = (PFNGLFINISHFENCEAPPLEPROC)glewGetProcAddress("glFinishFenceAPPLE")) == NULL) || r;
  r = ((glewFinishObjectAPPLE = (PFNGLFINISHOBJECTAPPLEPROC)glewGetProcAddress("glFinishObjectAPPLE")) == NULL) || r;
  r = ((glewGenFencesAPPLE = (PFNGLGENFENCESAPPLEPROC)glewGetProcAddress("glGenFencesAPPLE")) == NULL) || r;
  r = ((glewIsFenceAPPLE = (PFNGLISFENCEAPPLEPROC)glewGetProcAddress("glIsFenceAPPLE")) == NULL) || r;
  r = ((glewSetFenceAPPLE = (PFNGLSETFENCEAPPLEPROC)glewGetProcAddress("glSetFenceAPPLE")) == NULL) || r;
  r = ((glewTestFenceAPPLE = (PFNGLTESTFENCEAPPLEPROC)glewGetProcAddress("glTestFenceAPPLE")) == NULL) || r;
  r = ((glewTestObjectAPPLE = (PFNGLTESTOBJECTAPPLEPROC)glewGetProcAddress("glTestObjectAPPLE")) == NULL) || r;

  return r;
}

GLboolean GLEW_APPLE_fence = GL_FALSE;

#endif /* GL_APPLE_fence */

/* ------------------------ GL_APPLE_specular_vector ----------------------- */

#ifdef GL_APPLE_specular_vector

GLboolean GLEW_APPLE_specular_vector = GL_FALSE;

#endif /* GL_APPLE_specular_vector */

/* ------------------------ GL_APPLE_transform_hint ------------------------ */

#ifdef GL_APPLE_transform_hint

GLboolean GLEW_APPLE_transform_hint = GL_FALSE;

#endif /* GL_APPLE_transform_hint */

/* ---------------------- GL_APPLE_vertex_array_object --------------------- */

#ifdef GL_APPLE_vertex_array_object

PFNGLBINDVERTEXARRAYAPPLEPROC glewBindVertexArrayAPPLE = NULL;
PFNGLDELETEVERTEXARRAYSAPPLEPROC glewDeleteVertexArraysAPPLE = NULL;
PFNGLGENVERTEXARRAYSAPPLEPROC glewGenVertexArraysAPPLE = NULL;
PFNGLISVERTEXARRAYAPPLEPROC glewIsVertexArrayAPPLE = NULL;

static GLboolean _glewInit_GL_APPLE_vertex_array_object (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBindVertexArrayAPPLE = (PFNGLBINDVERTEXARRAYAPPLEPROC)glewGetProcAddress("glBindVertexArrayAPPLE")) == NULL) || r;
  r = ((glewDeleteVertexArraysAPPLE = (PFNGLDELETEVERTEXARRAYSAPPLEPROC)glewGetProcAddress("glDeleteVertexArraysAPPLE")) == NULL) || r;
  r = ((glewGenVertexArraysAPPLE = (PFNGLGENVERTEXARRAYSAPPLEPROC)glewGetProcAddress("glGenVertexArraysAPPLE")) == NULL) || r;
  r = ((glewIsVertexArrayAPPLE = (PFNGLISVERTEXARRAYAPPLEPROC)glewGetProcAddress("glIsVertexArrayAPPLE")) == NULL) || r;

  return r;
}

GLboolean GLEW_APPLE_vertex_array_object = GL_FALSE;

#endif /* GL_APPLE_vertex_array_object */

/* ---------------------- GL_APPLE_vertex_array_range ---------------------- */

#ifdef GL_APPLE_vertex_array_range

PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC glewFlushVertexArrayRangeAPPLE = NULL;
PFNGLVERTEXARRAYPARAMETERIAPPLEPROC glewVertexArrayParameteriAPPLE = NULL;
PFNGLVERTEXARRAYRANGEAPPLEPROC glewVertexArrayRangeAPPLE = NULL;

static GLboolean _glewInit_GL_APPLE_vertex_array_range (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewFlushVertexArrayRangeAPPLE = (PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)glewGetProcAddress("glFlushVertexArrayRangeAPPLE")) == NULL) || r;
  r = ((glewVertexArrayParameteriAPPLE = (PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)glewGetProcAddress("glVertexArrayParameteriAPPLE")) == NULL) || r;
  r = ((glewVertexArrayRangeAPPLE = (PFNGLVERTEXARRAYRANGEAPPLEPROC)glewGetProcAddress("glVertexArrayRangeAPPLE")) == NULL) || r;

  return r;
}

GLboolean GLEW_APPLE_vertex_array_range = GL_FALSE;

#endif /* GL_APPLE_vertex_array_range */

/* --------------------------- GL_APPLE_ycbcr_422 -------------------------- */

#ifdef GL_APPLE_ycbcr_422

GLboolean GLEW_APPLE_ycbcr_422 = GL_FALSE;

#endif /* GL_APPLE_ycbcr_422 */

/* -------------------------- GL_ARB_depth_texture ------------------------- */

#ifdef GL_ARB_depth_texture

GLboolean GLEW_ARB_depth_texture = GL_FALSE;

#endif /* GL_ARB_depth_texture */

/* ------------------------ GL_ARB_fragment_program ------------------------ */

#ifdef GL_ARB_fragment_program

GLboolean GLEW_ARB_fragment_program = GL_FALSE;

#endif /* GL_ARB_fragment_program */

/* ----------------------------- GL_ARB_imaging ---------------------------- */

#ifdef GL_ARB_imaging

PFNGLBLENDCOLORPROC glewBlendColor = NULL;
PFNGLBLENDEQUATIONPROC glewBlendEquation = NULL;
PFNGLCOLORSUBTABLEPROC glewColorSubTable = NULL;
PFNGLCOLORTABLEPROC glewColorTable = NULL;
PFNGLCOLORTABLEPARAMETERFVPROC glewColorTableParameterfv = NULL;
PFNGLCOLORTABLEPARAMETERIVPROC glewColorTableParameteriv = NULL;
PFNGLCONVOLUTIONFILTER1DPROC glewConvolutionFilter1D = NULL;
PFNGLCONVOLUTIONFILTER2DPROC glewConvolutionFilter2D = NULL;
PFNGLCONVOLUTIONPARAMETERFPROC glewConvolutionParameterf = NULL;
PFNGLCONVOLUTIONPARAMETERFVPROC glewConvolutionParameterfv = NULL;
PFNGLCONVOLUTIONPARAMETERIPROC glewConvolutionParameteri = NULL;
PFNGLCONVOLUTIONPARAMETERIVPROC glewConvolutionParameteriv = NULL;
PFNGLCOPYCOLORSUBTABLEPROC glewCopyColorSubTable = NULL;
PFNGLCOPYCOLORTABLEPROC glewCopyColorTable = NULL;
PFNGLCOPYCONVOLUTIONFILTER1DPROC glewCopyConvolutionFilter1D = NULL;
PFNGLCOPYCONVOLUTIONFILTER2DPROC glewCopyConvolutionFilter2D = NULL;
PFNGLGETCOLORTABLEPROC glewGetColorTable = NULL;
PFNGLGETCOLORTABLEPARAMETERFVPROC glewGetColorTableParameterfv = NULL;
PFNGLGETCOLORTABLEPARAMETERIVPROC glewGetColorTableParameteriv = NULL;
PFNGLGETCONVOLUTIONFILTERPROC glewGetConvolutionFilter = NULL;
PFNGLGETCONVOLUTIONPARAMETERFVPROC glewGetConvolutionParameterfv = NULL;
PFNGLGETCONVOLUTIONPARAMETERIVPROC glewGetConvolutionParameteriv = NULL;
PFNGLGETHISTOGRAMPROC glewGetHistogram = NULL;
PFNGLGETHISTOGRAMPARAMETERFVPROC glewGetHistogramParameterfv = NULL;
PFNGLGETHISTOGRAMPARAMETERIVPROC glewGetHistogramParameteriv = NULL;
PFNGLGETMINMAXPROC glewGetMinmax = NULL;
PFNGLGETMINMAXPARAMETERFVPROC glewGetMinmaxParameterfv = NULL;
PFNGLGETMINMAXPARAMETERIVPROC glewGetMinmaxParameteriv = NULL;
PFNGLGETSEPARABLEFILTERPROC glewGetSeparableFilter = NULL;
PFNGLHISTOGRAMPROC glewHistogram = NULL;
PFNGLMINMAXPROC glewMinmax = NULL;
PFNGLRESETHISTOGRAMPROC glewResetHistogram = NULL;
PFNGLRESETMINMAXPROC glewResetMinmax = NULL;
PFNGLSEPARABLEFILTER2DPROC glewSeparableFilter2D = NULL;

static GLboolean _glewInit_GL_ARB_imaging (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBlendColor = (PFNGLBLENDCOLORPROC)glewGetProcAddress("glBlendColor")) == NULL) || r;
  r = ((glewBlendEquation = (PFNGLBLENDEQUATIONPROC)glewGetProcAddress("glBlendEquation")) == NULL) || r;
  r = ((glewColorSubTable = (PFNGLCOLORSUBTABLEPROC)glewGetProcAddress("glColorSubTable")) == NULL) || r;
  r = ((glewColorTable = (PFNGLCOLORTABLEPROC)glewGetProcAddress("glColorTable")) == NULL) || r;
  r = ((glewColorTableParameterfv = (PFNGLCOLORTABLEPARAMETERFVPROC)glewGetProcAddress("glColorTableParameterfv")) == NULL) || r;
  r = ((glewColorTableParameteriv = (PFNGLCOLORTABLEPARAMETERIVPROC)glewGetProcAddress("glColorTableParameteriv")) == NULL) || r;
  r = ((glewConvolutionFilter1D = (PFNGLCONVOLUTIONFILTER1DPROC)glewGetProcAddress("glConvolutionFilter1D")) == NULL) || r;
  r = ((glewConvolutionFilter2D = (PFNGLCONVOLUTIONFILTER2DPROC)glewGetProcAddress("glConvolutionFilter2D")) == NULL) || r;
  r = ((glewConvolutionParameterf = (PFNGLCONVOLUTIONPARAMETERFPROC)glewGetProcAddress("glConvolutionParameterf")) == NULL) || r;
  r = ((glewConvolutionParameterfv = (PFNGLCONVOLUTIONPARAMETERFVPROC)glewGetProcAddress("glConvolutionParameterfv")) == NULL) || r;
  r = ((glewConvolutionParameteri = (PFNGLCONVOLUTIONPARAMETERIPROC)glewGetProcAddress("glConvolutionParameteri")) == NULL) || r;
  r = ((glewConvolutionParameteriv = (PFNGLCONVOLUTIONPARAMETERIVPROC)glewGetProcAddress("glConvolutionParameteriv")) == NULL) || r;
  r = ((glewCopyColorSubTable = (PFNGLCOPYCOLORSUBTABLEPROC)glewGetProcAddress("glCopyColorSubTable")) == NULL) || r;
  r = ((glewCopyColorTable = (PFNGLCOPYCOLORTABLEPROC)glewGetProcAddress("glCopyColorTable")) == NULL) || r;
  r = ((glewCopyConvolutionFilter1D = (PFNGLCOPYCONVOLUTIONFILTER1DPROC)glewGetProcAddress("glCopyConvolutionFilter1D")) == NULL) || r;
  r = ((glewCopyConvolutionFilter2D = (PFNGLCOPYCONVOLUTIONFILTER2DPROC)glewGetProcAddress("glCopyConvolutionFilter2D")) == NULL) || r;
  r = ((glewGetColorTable = (PFNGLGETCOLORTABLEPROC)glewGetProcAddress("glGetColorTable")) == NULL) || r;
  r = ((glewGetColorTableParameterfv = (PFNGLGETCOLORTABLEPARAMETERFVPROC)glewGetProcAddress("glGetColorTableParameterfv")) == NULL) || r;
  r = ((glewGetColorTableParameteriv = (PFNGLGETCOLORTABLEPARAMETERIVPROC)glewGetProcAddress("glGetColorTableParameteriv")) == NULL) || r;
  r = ((glewGetConvolutionFilter = (PFNGLGETCONVOLUTIONFILTERPROC)glewGetProcAddress("glGetConvolutionFilter")) == NULL) || r;
  r = ((glewGetConvolutionParameterfv = (PFNGLGETCONVOLUTIONPARAMETERFVPROC)glewGetProcAddress("glGetConvolutionParameterfv")) == NULL) || r;
  r = ((glewGetConvolutionParameteriv = (PFNGLGETCONVOLUTIONPARAMETERIVPROC)glewGetProcAddress("glGetConvolutionParameteriv")) == NULL) || r;
  r = ((glewGetHistogram = (PFNGLGETHISTOGRAMPROC)glewGetProcAddress("glGetHistogram")) == NULL) || r;
  r = ((glewGetHistogramParameterfv = (PFNGLGETHISTOGRAMPARAMETERFVPROC)glewGetProcAddress("glGetHistogramParameterfv")) == NULL) || r;
  r = ((glewGetHistogramParameteriv = (PFNGLGETHISTOGRAMPARAMETERIVPROC)glewGetProcAddress("glGetHistogramParameteriv")) == NULL) || r;
  r = ((glewGetMinmax = (PFNGLGETMINMAXPROC)glewGetProcAddress("glGetMinmax")) == NULL) || r;
  r = ((glewGetMinmaxParameterfv = (PFNGLGETMINMAXPARAMETERFVPROC)glewGetProcAddress("glGetMinmaxParameterfv")) == NULL) || r;
  r = ((glewGetMinmaxParameteriv = (PFNGLGETMINMAXPARAMETERIVPROC)glewGetProcAddress("glGetMinmaxParameteriv")) == NULL) || r;
  r = ((glewGetSeparableFilter = (PFNGLGETSEPARABLEFILTERPROC)glewGetProcAddress("glGetSeparableFilter")) == NULL) || r;
  r = ((glewHistogram = (PFNGLHISTOGRAMPROC)glewGetProcAddress("glHistogram")) == NULL) || r;
  r = ((glewMinmax = (PFNGLMINMAXPROC)glewGetProcAddress("glMinmax")) == NULL) || r;
  r = ((glewResetHistogram = (PFNGLRESETHISTOGRAMPROC)glewGetProcAddress("glResetHistogram")) == NULL) || r;
  r = ((glewResetMinmax = (PFNGLRESETMINMAXPROC)glewGetProcAddress("glResetMinmax")) == NULL) || r;
  r = ((glewSeparableFilter2D = (PFNGLSEPARABLEFILTER2DPROC)glewGetProcAddress("glSeparableFilter2D")) == NULL) || r;

  return r;
}

GLboolean GLEW_ARB_imaging = GL_FALSE;

#endif /* GL_ARB_imaging */

/* ------------------------- GL_ARB_matrix_palette ------------------------- */

#ifdef GL_ARB_matrix_palette

PFNGLCURRENTPALETTEMATRIXARBPROC glewCurrentPaletteMatrixARB = NULL;
PFNGLMATRIXINDEXPOINTERARBPROC glewMatrixIndexPointerARB = NULL;
PFNGLMATRIXINDEXUBVARBPROC glewMatrixIndexubvARB = NULL;
PFNGLMATRIXINDEXUIVARBPROC glewMatrixIndexuivARB = NULL;
PFNGLMATRIXINDEXUSVARBPROC glewMatrixIndexusvARB = NULL;

static GLboolean _glewInit_GL_ARB_matrix_palette (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewCurrentPaletteMatrixARB = (PFNGLCURRENTPALETTEMATRIXARBPROC)glewGetProcAddress("glCurrentPaletteMatrixARB")) == NULL) || r;
  r = ((glewMatrixIndexPointerARB = (PFNGLMATRIXINDEXPOINTERARBPROC)glewGetProcAddress("glMatrixIndexPointerARB")) == NULL) || r;
  r = ((glewMatrixIndexubvARB = (PFNGLMATRIXINDEXUBVARBPROC)glewGetProcAddress("glMatrixIndexubvARB")) == NULL) || r;
  r = ((glewMatrixIndexuivARB = (PFNGLMATRIXINDEXUIVARBPROC)glewGetProcAddress("glMatrixIndexuivARB")) == NULL) || r;
  r = ((glewMatrixIndexusvARB = (PFNGLMATRIXINDEXUSVARBPROC)glewGetProcAddress("glMatrixIndexusvARB")) == NULL) || r;

  return r;
}

GLboolean GLEW_ARB_matrix_palette = GL_FALSE;

#endif /* GL_ARB_matrix_palette */

/* --------------------------- GL_ARB_multisample -------------------------- */

#ifdef GL_ARB_multisample

PFNGLSAMPLECOVERAGEARBPROC glewSampleCoverageARB = NULL;

static GLboolean _glewInit_GL_ARB_multisample (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewSampleCoverageARB = (PFNGLSAMPLECOVERAGEARBPROC)glewGetProcAddress("glSampleCoverageARB")) == NULL) || r;

  return r;
}

GLboolean GLEW_ARB_multisample = GL_FALSE;

#endif /* GL_ARB_multisample */

/* -------------------------- GL_ARB_multitexture -------------------------- */

#ifdef GL_ARB_multitexture

PFNGLACTIVETEXTUREARBPROC glewActiveTextureARB = NULL;
PFNGLCLIENTACTIVETEXTUREARBPROC glewClientActiveTextureARB = NULL;
PFNGLMULTITEXCOORD1DARBPROC glewMultiTexCoord1dARB = NULL;
PFNGLMULTITEXCOORD1DVARBPROC glewMultiTexCoord1dvARB = NULL;
PFNGLMULTITEXCOORD1FARBPROC glewMultiTexCoord1fARB = NULL;
PFNGLMULTITEXCOORD1FVARBPROC glewMultiTexCoord1fvARB = NULL;
PFNGLMULTITEXCOORD1IARBPROC glewMultiTexCoord1iARB = NULL;
PFNGLMULTITEXCOORD1IVARBPROC glewMultiTexCoord1ivARB = NULL;
PFNGLMULTITEXCOORD1SARBPROC glewMultiTexCoord1sARB = NULL;
PFNGLMULTITEXCOORD1SVARBPROC glewMultiTexCoord1svARB = NULL;
PFNGLMULTITEXCOORD2DARBPROC glewMultiTexCoord2dARB = NULL;
PFNGLMULTITEXCOORD2DVARBPROC glewMultiTexCoord2dvARB = NULL;
PFNGLMULTITEXCOORD2FARBPROC glewMultiTexCoord2fARB = NULL;
PFNGLMULTITEXCOORD2FVARBPROC glewMultiTexCoord2fvARB = NULL;
PFNGLMULTITEXCOORD2IARBPROC glewMultiTexCoord2iARB = NULL;
PFNGLMULTITEXCOORD2IVARBPROC glewMultiTexCoord2ivARB = NULL;
PFNGLMULTITEXCOORD2SARBPROC glewMultiTexCoord2sARB = NULL;
PFNGLMULTITEXCOORD2SVARBPROC glewMultiTexCoord2svARB = NULL;
PFNGLMULTITEXCOORD3DARBPROC glewMultiTexCoord3dARB = NULL;
PFNGLMULTITEXCOORD3DVARBPROC glewMultiTexCoord3dvARB = NULL;
PFNGLMULTITEXCOORD3FARBPROC glewMultiTexCoord3fARB = NULL;
PFNGLMULTITEXCOORD3FVARBPROC glewMultiTexCoord3fvARB = NULL;
PFNGLMULTITEXCOORD3IARBPROC glewMultiTexCoord3iARB = NULL;
PFNGLMULTITEXCOORD3IVARBPROC glewMultiTexCoord3ivARB = NULL;
PFNGLMULTITEXCOORD3SARBPROC glewMultiTexCoord3sARB = NULL;
PFNGLMULTITEXCOORD3SVARBPROC glewMultiTexCoord3svARB = NULL;
PFNGLMULTITEXCOORD4DARBPROC glewMultiTexCoord4dARB = NULL;
PFNGLMULTITEXCOORD4DVARBPROC glewMultiTexCoord4dvARB = NULL;
PFNGLMULTITEXCOORD4FARBPROC glewMultiTexCoord4fARB = NULL;
PFNGLMULTITEXCOORD4FVARBPROC glewMultiTexCoord4fvARB = NULL;
PFNGLMULTITEXCOORD4IARBPROC glewMultiTexCoord4iARB = NULL;
PFNGLMULTITEXCOORD4IVARBPROC glewMultiTexCoord4ivARB = NULL;
PFNGLMULTITEXCOORD4SARBPROC glewMultiTexCoord4sARB = NULL;
PFNGLMULTITEXCOORD4SVARBPROC glewMultiTexCoord4svARB = NULL;

static GLboolean _glewInit_GL_ARB_multitexture (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)glewGetProcAddress("glActiveTextureARB")) == NULL) || r;
  r = ((glewClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC)glewGetProcAddress("glClientActiveTextureARB")) == NULL) || r;
  r = ((glewMultiTexCoord1dARB = (PFNGLMULTITEXCOORD1DARBPROC)glewGetProcAddress("glMultiTexCoord1dARB")) == NULL) || r;
  r = ((glewMultiTexCoord1dvARB = (PFNGLMULTITEXCOORD1DVARBPROC)glewGetProcAddress("glMultiTexCoord1dvARB")) == NULL) || r;
  r = ((glewMultiTexCoord1fARB = (PFNGLMULTITEXCOORD1FARBPROC)glewGetProcAddress("glMultiTexCoord1fARB")) == NULL) || r;
  r = ((glewMultiTexCoord1fvARB = (PFNGLMULTITEXCOORD1FVARBPROC)glewGetProcAddress("glMultiTexCoord1fvARB")) == NULL) || r;
  r = ((glewMultiTexCoord1iARB = (PFNGLMULTITEXCOORD1IARBPROC)glewGetProcAddress("glMultiTexCoord1iARB")) == NULL) || r;
  r = ((glewMultiTexCoord1ivARB = (PFNGLMULTITEXCOORD1IVARBPROC)glewGetProcAddress("glMultiTexCoord1ivARB")) == NULL) || r;
  r = ((glewMultiTexCoord1sARB = (PFNGLMULTITEXCOORD1SARBPROC)glewGetProcAddress("glMultiTexCoord1sARB")) == NULL) || r;
  r = ((glewMultiTexCoord1svARB = (PFNGLMULTITEXCOORD1SVARBPROC)glewGetProcAddress("glMultiTexCoord1svARB")) == NULL) || r;
  r = ((glewMultiTexCoord2dARB = (PFNGLMULTITEXCOORD2DARBPROC)glewGetProcAddress("glMultiTexCoord2dARB")) == NULL) || r;
  r = ((glewMultiTexCoord2dvARB = (PFNGLMULTITEXCOORD2DVARBPROC)glewGetProcAddress("glMultiTexCoord2dvARB")) == NULL) || r;
  r = ((glewMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC)glewGetProcAddress("glMultiTexCoord2fARB")) == NULL) || r;
  r = ((glewMultiTexCoord2fvARB = (PFNGLMULTITEXCOORD2FVARBPROC)glewGetProcAddress("glMultiTexCoord2fvARB")) == NULL) || r;
  r = ((glewMultiTexCoord2iARB = (PFNGLMULTITEXCOORD2IARBPROC)glewGetProcAddress("glMultiTexCoord2iARB")) == NULL) || r;
  r = ((glewMultiTexCoord2ivARB = (PFNGLMULTITEXCOORD2IVARBPROC)glewGetProcAddress("glMultiTexCoord2ivARB")) == NULL) || r;
  r = ((glewMultiTexCoord2sARB = (PFNGLMULTITEXCOORD2SARBPROC)glewGetProcAddress("glMultiTexCoord2sARB")) == NULL) || r;
  r = ((glewMultiTexCoord2svARB = (PFNGLMULTITEXCOORD2SVARBPROC)glewGetProcAddress("glMultiTexCoord2svARB")) == NULL) || r;
  r = ((glewMultiTexCoord3dARB = (PFNGLMULTITEXCOORD3DARBPROC)glewGetProcAddress("glMultiTexCoord3dARB")) == NULL) || r;
  r = ((glewMultiTexCoord3dvARB = (PFNGLMULTITEXCOORD3DVARBPROC)glewGetProcAddress("glMultiTexCoord3dvARB")) == NULL) || r;
  r = ((glewMultiTexCoord3fARB = (PFNGLMULTITEXCOORD3FARBPROC)glewGetProcAddress("glMultiTexCoord3fARB")) == NULL) || r;
  r = ((glewMultiTexCoord3fvARB = (PFNGLMULTITEXCOORD3FVARBPROC)glewGetProcAddress("glMultiTexCoord3fvARB")) == NULL) || r;
  r = ((glewMultiTexCoord3iARB = (PFNGLMULTITEXCOORD3IARBPROC)glewGetProcAddress("glMultiTexCoord3iARB")) == NULL) || r;
  r = ((glewMultiTexCoord3ivARB = (PFNGLMULTITEXCOORD3IVARBPROC)glewGetProcAddress("glMultiTexCoord3ivARB")) == NULL) || r;
  r = ((glewMultiTexCoord3sARB = (PFNGLMULTITEXCOORD3SARBPROC)glewGetProcAddress("glMultiTexCoord3sARB")) == NULL) || r;
  r = ((glewMultiTexCoord3svARB = (PFNGLMULTITEXCOORD3SVARBPROC)glewGetProcAddress("glMultiTexCoord3svARB")) == NULL) || r;
  r = ((glewMultiTexCoord4dARB = (PFNGLMULTITEXCOORD4DARBPROC)glewGetProcAddress("glMultiTexCoord4dARB")) == NULL) || r;
  r = ((glewMultiTexCoord4dvARB = (PFNGLMULTITEXCOORD4DVARBPROC)glewGetProcAddress("glMultiTexCoord4dvARB")) == NULL) || r;
  r = ((glewMultiTexCoord4fARB = (PFNGLMULTITEXCOORD4FARBPROC)glewGetProcAddress("glMultiTexCoord4fARB")) == NULL) || r;
  r = ((glewMultiTexCoord4fvARB = (PFNGLMULTITEXCOORD4FVARBPROC)glewGetProcAddress("glMultiTexCoord4fvARB")) == NULL) || r;
  r = ((glewMultiTexCoord4iARB = (PFNGLMULTITEXCOORD4IARBPROC)glewGetProcAddress("glMultiTexCoord4iARB")) == NULL) || r;
  r = ((glewMultiTexCoord4ivARB = (PFNGLMULTITEXCOORD4IVARBPROC)glewGetProcAddress("glMultiTexCoord4ivARB")) == NULL) || r;
  r = ((glewMultiTexCoord4sARB = (PFNGLMULTITEXCOORD4SARBPROC)glewGetProcAddress("glMultiTexCoord4sARB")) == NULL) || r;
  r = ((glewMultiTexCoord4svARB = (PFNGLMULTITEXCOORD4SVARBPROC)glewGetProcAddress("glMultiTexCoord4svARB")) == NULL) || r;

  return r;
}

GLboolean GLEW_ARB_multitexture = GL_FALSE;

#endif /* GL_ARB_multitexture */

/* ------------------------- GL_ARB_occlusion_query ------------------------ */

#ifdef GL_ARB_occlusion_query

PFNGLBEGINQUERYARBPROC glewBeginQueryARB = NULL;
PFNGLDELETEQUERIESARBPROC glewDeleteQueriesARB = NULL;
PFNGLENDQUERYARBPROC glewEndQueryARB = NULL;
PFNGLGENQUERIESARBPROC glewGenQueriesARB = NULL;
PFNGLGETQUERYOBJECTIVARBPROC glewGetQueryObjectivARB = NULL;
PFNGLGETQUERYOBJECTUIVARBPROC glewGetQueryObjectuivARB = NULL;
PFNGLGETQUERYIVARBPROC glewGetQueryivARB = NULL;
PFNGLISQUERYARBPROC glewIsQueryARB = NULL;

static GLboolean _glewInit_GL_ARB_occlusion_query (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBeginQueryARB = (PFNGLBEGINQUERYARBPROC)glewGetProcAddress("glBeginQueryARB")) == NULL) || r;
  r = ((glewDeleteQueriesARB = (PFNGLDELETEQUERIESARBPROC)glewGetProcAddress("glDeleteQueriesARB")) == NULL) || r;
  r = ((glewEndQueryARB = (PFNGLENDQUERYARBPROC)glewGetProcAddress("glEndQueryARB")) == NULL) || r;
  r = ((glewGenQueriesARB = (PFNGLGENQUERIESARBPROC)glewGetProcAddress("glGenQueriesARB")) == NULL) || r;
  r = ((glewGetQueryObjectivARB = (PFNGLGETQUERYOBJECTIVARBPROC)glewGetProcAddress("glGetQueryObjectivARB")) == NULL) || r;
  r = ((glewGetQueryObjectuivARB = (PFNGLGETQUERYOBJECTUIVARBPROC)glewGetProcAddress("glGetQueryObjectuivARB")) == NULL) || r;
  r = ((glewGetQueryivARB = (PFNGLGETQUERYIVARBPROC)glewGetProcAddress("glGetQueryivARB")) == NULL) || r;
  r = ((glewIsQueryARB = (PFNGLISQUERYARBPROC)glewGetProcAddress("glIsQueryARB")) == NULL) || r;

  return r;
}

GLboolean GLEW_ARB_occlusion_query = GL_FALSE;

#endif /* GL_ARB_occlusion_query */

/* ------------------------ GL_ARB_point_parameters ------------------------ */

#ifdef GL_ARB_point_parameters

PFNGLPOINTPARAMETERFARBPROC glewPointParameterfARB = NULL;
PFNGLPOINTPARAMETERFVARBPROC glewPointParameterfvARB = NULL;

static GLboolean _glewInit_GL_ARB_point_parameters (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewPointParameterfARB = (PFNGLPOINTPARAMETERFARBPROC)glewGetProcAddress("glPointParameterfARB")) == NULL) || r;
  r = ((glewPointParameterfvARB = (PFNGLPOINTPARAMETERFVARBPROC)glewGetProcAddress("glPointParameterfvARB")) == NULL) || r;

  return r;
}

GLboolean GLEW_ARB_point_parameters = GL_FALSE;

#endif /* GL_ARB_point_parameters */

/* -------------------------- GL_ARB_point_sprite -------------------------- */

#ifdef GL_ARB_point_sprite

GLboolean GLEW_ARB_point_sprite = GL_FALSE;

#endif /* GL_ARB_point_sprite */

/* ---------------------- GL_ARB_shading_language_100 ---------------------- */

#ifdef GL_ARB_shading_language_100

GLboolean GLEW_ARB_shading_language_100 = GL_FALSE;

#endif /* GL_ARB_shading_language_100 */

/* ----------------------------- GL_ARB_shadow ----------------------------- */

#ifdef GL_ARB_shadow

GLboolean GLEW_ARB_shadow = GL_FALSE;

#endif /* GL_ARB_shadow */

/* ------------------------- GL_ARB_shadow_ambient ------------------------- */

#ifdef GL_ARB_shadow_ambient

GLboolean GLEW_ARB_shadow_ambient = GL_FALSE;

#endif /* GL_ARB_shadow_ambient */

/* ---------------------- GL_ARB_texture_border_clamp ---------------------- */

#ifdef GL_ARB_texture_border_clamp

GLboolean GLEW_ARB_texture_border_clamp = GL_FALSE;

#endif /* GL_ARB_texture_border_clamp */

/* ----------------------- GL_ARB_texture_compression ---------------------- */

#ifdef GL_ARB_texture_compression

PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glewCompressedTexImage1DARB = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glewCompressedTexImage2DARB = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glewCompressedTexImage3DARB = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glewCompressedTexSubImage1DARB = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glewCompressedTexSubImage2DARB = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glewCompressedTexSubImage3DARB = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glewGetCompressedTexImageARB = NULL;

static GLboolean _glewInit_GL_ARB_texture_compression (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewCompressedTexImage1DARB = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)glewGetProcAddress("glCompressedTexImage1DARB")) == NULL) || r;
  r = ((glewCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)glewGetProcAddress("glCompressedTexImage2DARB")) == NULL) || r;
  r = ((glewCompressedTexImage3DARB = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)glewGetProcAddress("glCompressedTexImage3DARB")) == NULL) || r;
  r = ((glewCompressedTexSubImage1DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)glewGetProcAddress("glCompressedTexSubImage1DARB")) == NULL) || r;
  r = ((glewCompressedTexSubImage2DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)glewGetProcAddress("glCompressedTexSubImage2DARB")) == NULL) || r;
  r = ((glewCompressedTexSubImage3DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)glewGetProcAddress("glCompressedTexSubImage3DARB")) == NULL) || r;
  r = ((glewGetCompressedTexImageARB = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)glewGetProcAddress("glGetCompressedTexImageARB")) == NULL) || r;

  return r;
}

GLboolean GLEW_ARB_texture_compression = GL_FALSE;

#endif /* GL_ARB_texture_compression */

/* ------------------------ GL_ARB_texture_cube_map ------------------------ */

#ifdef GL_ARB_texture_cube_map

GLboolean GLEW_ARB_texture_cube_map = GL_FALSE;

#endif /* GL_ARB_texture_cube_map */

/* ------------------------- GL_ARB_texture_env_add ------------------------ */

#ifdef GL_ARB_texture_env_add

GLboolean GLEW_ARB_texture_env_add = GL_FALSE;

#endif /* GL_ARB_texture_env_add */

/* ----------------------- GL_ARB_texture_env_combine ---------------------- */

#ifdef GL_ARB_texture_env_combine

GLboolean GLEW_ARB_texture_env_combine = GL_FALSE;

#endif /* GL_ARB_texture_env_combine */

/* ---------------------- GL_ARB_texture_env_crossbar ---------------------- */

#ifdef GL_ARB_texture_env_crossbar

GLboolean GLEW_ARB_texture_env_crossbar = GL_FALSE;

#endif /* GL_ARB_texture_env_crossbar */

/* ------------------------ GL_ARB_texture_env_dot3 ------------------------ */

#ifdef GL_ARB_texture_env_dot3

GLboolean GLEW_ARB_texture_env_dot3 = GL_FALSE;

#endif /* GL_ARB_texture_env_dot3 */

/* --------------------- GL_ARB_texture_mirrored_repeat -------------------- */

#ifdef GL_ARB_texture_mirrored_repeat

GLboolean GLEW_ARB_texture_mirrored_repeat = GL_FALSE;

#endif /* GL_ARB_texture_mirrored_repeat */

/* -------------------- GL_ARB_texture_non_power_of_two -------------------- */

#ifdef GL_ARB_texture_non_power_of_two

GLboolean GLEW_ARB_texture_non_power_of_two = GL_FALSE;

#endif /* GL_ARB_texture_non_power_of_two */

/* ------------------------ GL_ARB_transpose_matrix ------------------------ */

#ifdef GL_ARB_transpose_matrix

GLboolean GLEW_ARB_transpose_matrix = GL_FALSE;

#endif /* GL_ARB_transpose_matrix */

/* -------------------------- GL_ARB_vertex_blend -------------------------- */

#ifdef GL_ARB_vertex_blend

PFNGLVERTEXBLENDARBPROC glewVertexBlendARB = NULL;
PFNGLWEIGHTPOINTERARBPROC glewWeightPointerARB = NULL;
PFNGLWEIGHTBVARBPROC glewWeightbvARB = NULL;
PFNGLWEIGHTDVARBPROC glewWeightdvARB = NULL;
PFNGLWEIGHTFVARBPROC glewWeightfvARB = NULL;
PFNGLWEIGHTIVARBPROC glewWeightivARB = NULL;
PFNGLWEIGHTSVARBPROC glewWeightsvARB = NULL;
PFNGLWEIGHTUBVARBPROC glewWeightubvARB = NULL;
PFNGLWEIGHTUIVARBPROC glewWeightuivARB = NULL;
PFNGLWEIGHTUSVARBPROC glewWeightusvARB = NULL;

static GLboolean _glewInit_GL_ARB_vertex_blend (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewVertexBlendARB = (PFNGLVERTEXBLENDARBPROC)glewGetProcAddress("glVertexBlendARB")) == NULL) || r;
  r = ((glewWeightPointerARB = (PFNGLWEIGHTPOINTERARBPROC)glewGetProcAddress("glWeightPointerARB")) == NULL) || r;
  r = ((glewWeightbvARB = (PFNGLWEIGHTBVARBPROC)glewGetProcAddress("glWeightbvARB")) == NULL) || r;
  r = ((glewWeightdvARB = (PFNGLWEIGHTDVARBPROC)glewGetProcAddress("glWeightdvARB")) == NULL) || r;
  r = ((glewWeightfvARB = (PFNGLWEIGHTFVARBPROC)glewGetProcAddress("glWeightfvARB")) == NULL) || r;
  r = ((glewWeightivARB = (PFNGLWEIGHTIVARBPROC)glewGetProcAddress("glWeightivARB")) == NULL) || r;
  r = ((glewWeightsvARB = (PFNGLWEIGHTSVARBPROC)glewGetProcAddress("glWeightsvARB")) == NULL) || r;
  r = ((glewWeightubvARB = (PFNGLWEIGHTUBVARBPROC)glewGetProcAddress("glWeightubvARB")) == NULL) || r;
  r = ((glewWeightuivARB = (PFNGLWEIGHTUIVARBPROC)glewGetProcAddress("glWeightuivARB")) == NULL) || r;
  r = ((glewWeightusvARB = (PFNGLWEIGHTUSVARBPROC)glewGetProcAddress("glWeightusvARB")) == NULL) || r;

  return r;
}

GLboolean GLEW_ARB_vertex_blend = GL_FALSE;

#endif /* GL_ARB_vertex_blend */

/* ---------------------- GL_ARB_vertex_buffer_object ---------------------- */

#ifdef GL_ARB_vertex_buffer_object

PFNGLBINDBUFFERARBPROC glewBindBufferARB = NULL;
PFNGLBUFFERDATAARBPROC glewBufferDataARB = NULL;
PFNGLBUFFERSUBDATAARBPROC glewBufferSubDataARB = NULL;
PFNGLDELETEBUFFERSARBPROC glewDeleteBuffersARB = NULL;
PFNGLGENBUFFERSARBPROC glewGenBuffersARB = NULL;
PFNGLGETBUFFERPARAMETERIVARBPROC glewGetBufferParameterivARB = NULL;
PFNGLGETBUFFERPOINTERVARBPROC glewGetBufferPointervARB = NULL;
PFNGLGETBUFFERSUBDATAARBPROC glewGetBufferSubDataARB = NULL;
PFNGLISBUFFERARBPROC glewIsBufferARB = NULL;
PFNGLMAPBUFFERARBPROC glewMapBufferARB = NULL;
PFNGLUNMAPBUFFERARBPROC glewUnmapBufferARB = NULL;

static GLboolean _glewInit_GL_ARB_vertex_buffer_object (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBindBufferARB = (PFNGLBINDBUFFERARBPROC)glewGetProcAddress("glBindBufferARB")) == NULL) || r;
  r = ((glewBufferDataARB = (PFNGLBUFFERDATAARBPROC)glewGetProcAddress("glBufferDataARB")) == NULL) || r;
  r = ((glewBufferSubDataARB = (PFNGLBUFFERSUBDATAARBPROC)glewGetProcAddress("glBufferSubDataARB")) == NULL) || r;
  r = ((glewDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC)glewGetProcAddress("glDeleteBuffersARB")) == NULL) || r;
  r = ((glewGenBuffersARB = (PFNGLGENBUFFERSARBPROC)glewGetProcAddress("glGenBuffersARB")) == NULL) || r;
  r = ((glewGetBufferParameterivARB = (PFNGLGETBUFFERPARAMETERIVARBPROC)glewGetProcAddress("glGetBufferParameterivARB")) == NULL) || r;
  r = ((glewGetBufferPointervARB = (PFNGLGETBUFFERPOINTERVARBPROC)glewGetProcAddress("glGetBufferPointervARB")) == NULL) || r;
  r = ((glewGetBufferSubDataARB = (PFNGLGETBUFFERSUBDATAARBPROC)glewGetProcAddress("glGetBufferSubDataARB")) == NULL) || r;
  r = ((glewIsBufferARB = (PFNGLISBUFFERARBPROC)glewGetProcAddress("glIsBufferARB")) == NULL) || r;
  r = ((glewMapBufferARB = (PFNGLMAPBUFFERARBPROC)glewGetProcAddress("glMapBufferARB")) == NULL) || r;
  r = ((glewUnmapBufferARB = (PFNGLUNMAPBUFFERARBPROC)glewGetProcAddress("glUnmapBufferARB")) == NULL) || r;

  return r;
}

GLboolean GLEW_ARB_vertex_buffer_object = GL_FALSE;

#endif /* GL_ARB_vertex_buffer_object */

/* ------------------------- GL_ARB_vertex_program ------------------------- */

#ifdef GL_ARB_vertex_program

PFNGLBINDPROGRAMARBPROC glewBindProgramARB = NULL;
PFNGLDELETEPROGRAMSARBPROC glewDeleteProgramsARB = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glewDisableVertexAttribArrayARB = NULL;
PFNGLENABLEVERTEXATTRIBARRAYARBPROC glewEnableVertexAttribArrayARB = NULL;
PFNGLGENPROGRAMSARBPROC glewGenProgramsARB = NULL;
PFNGLGETPROGRAMENVPARAMETERDVARBPROC glewGetProgramEnvParameterdvARB = NULL;
PFNGLGETPROGRAMENVPARAMETERFVARBPROC glewGetProgramEnvParameterfvARB = NULL;
PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glewGetProgramLocalParameterdvARB = NULL;
PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glewGetProgramLocalParameterfvARB = NULL;
PFNGLGETPROGRAMSTRINGARBPROC glewGetProgramStringARB = NULL;
PFNGLGETPROGRAMIVARBPROC glewGetProgramivARB = NULL;
PFNGLGETVERTEXATTRIBPOINTERVARBPROC glewGetVertexAttribPointervARB = NULL;
PFNGLGETVERTEXATTRIBDVARBPROC glewGetVertexAttribdvARB = NULL;
PFNGLGETVERTEXATTRIBFVARBPROC glewGetVertexAttribfvARB = NULL;
PFNGLGETVERTEXATTRIBIVARBPROC glewGetVertexAttribivARB = NULL;
PFNGLISPROGRAMARBPROC glewIsProgramARB = NULL;
PFNGLPROGRAMENVPARAMETER4DARBPROC glewProgramEnvParameter4dARB = NULL;
PFNGLPROGRAMENVPARAMETER4DVARBPROC glewProgramEnvParameter4dvARB = NULL;
PFNGLPROGRAMENVPARAMETER4FARBPROC glewProgramEnvParameter4fARB = NULL;
PFNGLPROGRAMENVPARAMETER4FVARBPROC glewProgramEnvParameter4fvARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4DARBPROC glewProgramLocalParameter4dARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glewProgramLocalParameter4dvARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4FARBPROC glewProgramLocalParameter4fARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glewProgramLocalParameter4fvARB = NULL;
PFNGLPROGRAMSTRINGARBPROC glewProgramStringARB = NULL;
PFNGLVERTEXATTRIB1DARBPROC glewVertexAttrib1dARB = NULL;
PFNGLVERTEXATTRIB1DVARBPROC glewVertexAttrib1dvARB = NULL;
PFNGLVERTEXATTRIB1FARBPROC glewVertexAttrib1fARB = NULL;
PFNGLVERTEXATTRIB1FVARBPROC glewVertexAttrib1fvARB = NULL;
PFNGLVERTEXATTRIB1SARBPROC glewVertexAttrib1sARB = NULL;
PFNGLVERTEXATTRIB1SVARBPROC glewVertexAttrib1svARB = NULL;
PFNGLVERTEXATTRIB2DARBPROC glewVertexAttrib2dARB = NULL;
PFNGLVERTEXATTRIB2DVARBPROC glewVertexAttrib2dvARB = NULL;
PFNGLVERTEXATTRIB2FARBPROC glewVertexAttrib2fARB = NULL;
PFNGLVERTEXATTRIB2FVARBPROC glewVertexAttrib2fvARB = NULL;
PFNGLVERTEXATTRIB2SARBPROC glewVertexAttrib2sARB = NULL;
PFNGLVERTEXATTRIB2SVARBPROC glewVertexAttrib2svARB = NULL;
PFNGLVERTEXATTRIB3DARBPROC glewVertexAttrib3dARB = NULL;
PFNGLVERTEXATTRIB3DVARBPROC glewVertexAttrib3dvARB = NULL;
PFNGLVERTEXATTRIB3FARBPROC glewVertexAttrib3fARB = NULL;
PFNGLVERTEXATTRIB3FVARBPROC glewVertexAttrib3fvARB = NULL;
PFNGLVERTEXATTRIB3SARBPROC glewVertexAttrib3sARB = NULL;
PFNGLVERTEXATTRIB3SVARBPROC glewVertexAttrib3svARB = NULL;
PFNGLVERTEXATTRIB4NBVARBPROC glewVertexAttrib4NbvARB = NULL;
PFNGLVERTEXATTRIB4NIVARBPROC glewVertexAttrib4NivARB = NULL;
PFNGLVERTEXATTRIB4NSVARBPROC glewVertexAttrib4NsvARB = NULL;
PFNGLVERTEXATTRIB4NUBARBPROC glewVertexAttrib4NubARB = NULL;
PFNGLVERTEXATTRIB4NUBVARBPROC glewVertexAttrib4NubvARB = NULL;
PFNGLVERTEXATTRIB4NUIVARBPROC glewVertexAttrib4NuivARB = NULL;
PFNGLVERTEXATTRIB4NUSVARBPROC glewVertexAttrib4NusvARB = NULL;
PFNGLVERTEXATTRIB4BVARBPROC glewVertexAttrib4bvARB = NULL;
PFNGLVERTEXATTRIB4DARBPROC glewVertexAttrib4dARB = NULL;
PFNGLVERTEXATTRIB4DVARBPROC glewVertexAttrib4dvARB = NULL;
PFNGLVERTEXATTRIB4FARBPROC glewVertexAttrib4fARB = NULL;
PFNGLVERTEXATTRIB4FVARBPROC glewVertexAttrib4fvARB = NULL;
PFNGLVERTEXATTRIB4IVARBPROC glewVertexAttrib4ivARB = NULL;
PFNGLVERTEXATTRIB4SARBPROC glewVertexAttrib4sARB = NULL;
PFNGLVERTEXATTRIB4SVARBPROC glewVertexAttrib4svARB = NULL;
PFNGLVERTEXATTRIB4UBVARBPROC glewVertexAttrib4ubvARB = NULL;
PFNGLVERTEXATTRIB4UIVARBPROC glewVertexAttrib4uivARB = NULL;
PFNGLVERTEXATTRIB4USVARBPROC glewVertexAttrib4usvARB = NULL;
PFNGLVERTEXATTRIBPOINTERARBPROC glewVertexAttribPointerARB = NULL;

static GLboolean _glewInit_GL_ARB_vertex_program (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBindProgramARB = (PFNGLBINDPROGRAMARBPROC)glewGetProcAddress("glBindProgramARB")) == NULL) || r;
  r = ((glewDeleteProgramsARB = (PFNGLDELETEPROGRAMSARBPROC)glewGetProcAddress("glDeleteProgramsARB")) == NULL) || r;
  r = ((glewDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)glewGetProcAddress("glDisableVertexAttribArrayARB")) == NULL) || r;
  r = ((glewEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC)glewGetProcAddress("glEnableVertexAttribArrayARB")) == NULL) || r;
  r = ((glewGenProgramsARB = (PFNGLGENPROGRAMSARBPROC)glewGetProcAddress("glGenProgramsARB")) == NULL) || r;
  r = ((glewGetProgramEnvParameterdvARB = (PFNGLGETPROGRAMENVPARAMETERDVARBPROC)glewGetProcAddress("glGetProgramEnvParameterdvARB")) == NULL) || r;
  r = ((glewGetProgramEnvParameterfvARB = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC)glewGetProcAddress("glGetProgramEnvParameterfvARB")) == NULL) || r;
  r = ((glewGetProgramLocalParameterdvARB = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)glewGetProcAddress("glGetProgramLocalParameterdvARB")) == NULL) || r;
  r = ((glewGetProgramLocalParameterfvARB = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)glewGetProcAddress("glGetProgramLocalParameterfvARB")) == NULL) || r;
  r = ((glewGetProgramStringARB = (PFNGLGETPROGRAMSTRINGARBPROC)glewGetProcAddress("glGetProgramStringARB")) == NULL) || r;
  r = ((glewGetProgramivARB = (PFNGLGETPROGRAMIVARBPROC)glewGetProcAddress("glGetProgramivARB")) == NULL) || r;
  r = ((glewGetVertexAttribPointervARB = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC)glewGetProcAddress("glGetVertexAttribPointervARB")) == NULL) || r;
  r = ((glewGetVertexAttribdvARB = (PFNGLGETVERTEXATTRIBDVARBPROC)glewGetProcAddress("glGetVertexAttribdvARB")) == NULL) || r;
  r = ((glewGetVertexAttribfvARB = (PFNGLGETVERTEXATTRIBFVARBPROC)glewGetProcAddress("glGetVertexAttribfvARB")) == NULL) || r;
  r = ((glewGetVertexAttribivARB = (PFNGLGETVERTEXATTRIBIVARBPROC)glewGetProcAddress("glGetVertexAttribivARB")) == NULL) || r;
  r = ((glewIsProgramARB = (PFNGLISPROGRAMARBPROC)glewGetProcAddress("glIsProgramARB")) == NULL) || r;
  r = ((glewProgramEnvParameter4dARB = (PFNGLPROGRAMENVPARAMETER4DARBPROC)glewGetProcAddress("glProgramEnvParameter4dARB")) == NULL) || r;
  r = ((glewProgramEnvParameter4dvARB = (PFNGLPROGRAMENVPARAMETER4DVARBPROC)glewGetProcAddress("glProgramEnvParameter4dvARB")) == NULL) || r;
  r = ((glewProgramEnvParameter4fARB = (PFNGLPROGRAMENVPARAMETER4FARBPROC)glewGetProcAddress("glProgramEnvParameter4fARB")) == NULL) || r;
  r = ((glewProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARBPROC)glewGetProcAddress("glProgramEnvParameter4fvARB")) == NULL) || r;
  r = ((glewProgramLocalParameter4dARB = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC)glewGetProcAddress("glProgramLocalParameter4dARB")) == NULL) || r;
  r = ((glewProgramLocalParameter4dvARB = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)glewGetProcAddress("glProgramLocalParameter4dvARB")) == NULL) || r;
  r = ((glewProgramLocalParameter4fARB = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC)glewGetProcAddress("glProgramLocalParameter4fARB")) == NULL) || r;
  r = ((glewProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)glewGetProcAddress("glProgramLocalParameter4fvARB")) == NULL) || r;
  r = ((glewProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC)glewGetProcAddress("glProgramStringARB")) == NULL) || r;
  r = ((glewVertexAttrib1dARB = (PFNGLVERTEXATTRIB1DARBPROC)glewGetProcAddress("glVertexAttrib1dARB")) == NULL) || r;
  r = ((glewVertexAttrib1dvARB = (PFNGLVERTEXATTRIB1DVARBPROC)glewGetProcAddress("glVertexAttrib1dvARB")) == NULL) || r;
  r = ((glewVertexAttrib1fARB = (PFNGLVERTEXATTRIB1FARBPROC)glewGetProcAddress("glVertexAttrib1fARB")) == NULL) || r;
  r = ((glewVertexAttrib1fvARB = (PFNGLVERTEXATTRIB1FVARBPROC)glewGetProcAddress("glVertexAttrib1fvARB")) == NULL) || r;
  r = ((glewVertexAttrib1sARB = (PFNGLVERTEXATTRIB1SARBPROC)glewGetProcAddress("glVertexAttrib1sARB")) == NULL) || r;
  r = ((glewVertexAttrib1svARB = (PFNGLVERTEXATTRIB1SVARBPROC)glewGetProcAddress("glVertexAttrib1svARB")) == NULL) || r;
  r = ((glewVertexAttrib2dARB = (PFNGLVERTEXATTRIB2DARBPROC)glewGetProcAddress("glVertexAttrib2dARB")) == NULL) || r;
  r = ((glewVertexAttrib2dvARB = (PFNGLVERTEXATTRIB2DVARBPROC)glewGetProcAddress("glVertexAttrib2dvARB")) == NULL) || r;
  r = ((glewVertexAttrib2fARB = (PFNGLVERTEXATTRIB2FARBPROC)glewGetProcAddress("glVertexAttrib2fARB")) == NULL) || r;
  r = ((glewVertexAttrib2fvARB = (PFNGLVERTEXATTRIB2FVARBPROC)glewGetProcAddress("glVertexAttrib2fvARB")) == NULL) || r;
  r = ((glewVertexAttrib2sARB = (PFNGLVERTEXATTRIB2SARBPROC)glewGetProcAddress("glVertexAttrib2sARB")) == NULL) || r;
  r = ((glewVertexAttrib2svARB = (PFNGLVERTEXATTRIB2SVARBPROC)glewGetProcAddress("glVertexAttrib2svARB")) == NULL) || r;
  r = ((glewVertexAttrib3dARB = (PFNGLVERTEXATTRIB3DARBPROC)glewGetProcAddress("glVertexAttrib3dARB")) == NULL) || r;
  r = ((glewVertexAttrib3dvARB = (PFNGLVERTEXATTRIB3DVARBPROC)glewGetProcAddress("glVertexAttrib3dvARB")) == NULL) || r;
  r = ((glewVertexAttrib3fARB = (PFNGLVERTEXATTRIB3FARBPROC)glewGetProcAddress("glVertexAttrib3fARB")) == NULL) || r;
  r = ((glewVertexAttrib3fvARB = (PFNGLVERTEXATTRIB3FVARBPROC)glewGetProcAddress("glVertexAttrib3fvARB")) == NULL) || r;
  r = ((glewVertexAttrib3sARB = (PFNGLVERTEXATTRIB3SARBPROC)glewGetProcAddress("glVertexAttrib3sARB")) == NULL) || r;
  r = ((glewVertexAttrib3svARB = (PFNGLVERTEXATTRIB3SVARBPROC)glewGetProcAddress("glVertexAttrib3svARB")) == NULL) || r;
  r = ((glewVertexAttrib4NbvARB = (PFNGLVERTEXATTRIB4NBVARBPROC)glewGetProcAddress("glVertexAttrib4NbvARB")) == NULL) || r;
  r = ((glewVertexAttrib4NivARB = (PFNGLVERTEXATTRIB4NIVARBPROC)glewGetProcAddress("glVertexAttrib4NivARB")) == NULL) || r;
  r = ((glewVertexAttrib4NsvARB = (PFNGLVERTEXATTRIB4NSVARBPROC)glewGetProcAddress("glVertexAttrib4NsvARB")) == NULL) || r;
  r = ((glewVertexAttrib4NubARB = (PFNGLVERTEXATTRIB4NUBARBPROC)glewGetProcAddress("glVertexAttrib4NubARB")) == NULL) || r;
  r = ((glewVertexAttrib4NubvARB = (PFNGLVERTEXATTRIB4NUBVARBPROC)glewGetProcAddress("glVertexAttrib4NubvARB")) == NULL) || r;
  r = ((glewVertexAttrib4NuivARB = (PFNGLVERTEXATTRIB4NUIVARBPROC)glewGetProcAddress("glVertexAttrib4NuivARB")) == NULL) || r;
  r = ((glewVertexAttrib4NusvARB = (PFNGLVERTEXATTRIB4NUSVARBPROC)glewGetProcAddress("glVertexAttrib4NusvARB")) == NULL) || r;
  r = ((glewVertexAttrib4bvARB = (PFNGLVERTEXATTRIB4BVARBPROC)glewGetProcAddress("glVertexAttrib4bvARB")) == NULL) || r;
  r = ((glewVertexAttrib4dARB = (PFNGLVERTEXATTRIB4DARBPROC)glewGetProcAddress("glVertexAttrib4dARB")) == NULL) || r;
  r = ((glewVertexAttrib4dvARB = (PFNGLVERTEXATTRIB4DVARBPROC)glewGetProcAddress("glVertexAttrib4dvARB")) == NULL) || r;
  r = ((glewVertexAttrib4fARB = (PFNGLVERTEXATTRIB4FARBPROC)glewGetProcAddress("glVertexAttrib4fARB")) == NULL) || r;
  r = ((glewVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARBPROC)glewGetProcAddress("glVertexAttrib4fvARB")) == NULL) || r;
  r = ((glewVertexAttrib4ivARB = (PFNGLVERTEXATTRIB4IVARBPROC)glewGetProcAddress("glVertexAttrib4ivARB")) == NULL) || r;
  r = ((glewVertexAttrib4sARB = (PFNGLVERTEXATTRIB4SARBPROC)glewGetProcAddress("glVertexAttrib4sARB")) == NULL) || r;
  r = ((glewVertexAttrib4svARB = (PFNGLVERTEXATTRIB4SVARBPROC)glewGetProcAddress("glVertexAttrib4svARB")) == NULL) || r;
  r = ((glewVertexAttrib4ubvARB = (PFNGLVERTEXATTRIB4UBVARBPROC)glewGetProcAddress("glVertexAttrib4ubvARB")) == NULL) || r;
  r = ((glewVertexAttrib4uivARB = (PFNGLVERTEXATTRIB4UIVARBPROC)glewGetProcAddress("glVertexAttrib4uivARB")) == NULL) || r;
  r = ((glewVertexAttrib4usvARB = (PFNGLVERTEXATTRIB4USVARBPROC)glewGetProcAddress("glVertexAttrib4usvARB")) == NULL) || r;
  r = ((glewVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC)glewGetProcAddress("glVertexAttribPointerARB")) == NULL) || r;

  return r;
}

GLboolean GLEW_ARB_vertex_program = GL_FALSE;

#endif /* GL_ARB_vertex_program */

/* --------------------------- GL_ARB_window_pos --------------------------- */

#ifdef GL_ARB_window_pos

PFNGLWINDOWPOS2DARBPROC glewWindowPos2dARB = NULL;
PFNGLWINDOWPOS2DVARBPROC glewWindowPos2dvARB = NULL;
PFNGLWINDOWPOS2FARBPROC glewWindowPos2fARB = NULL;
PFNGLWINDOWPOS2FVARBPROC glewWindowPos2fvARB = NULL;
PFNGLWINDOWPOS2IARBPROC glewWindowPos2iARB = NULL;
PFNGLWINDOWPOS2IVARBPROC glewWindowPos2ivARB = NULL;
PFNGLWINDOWPOS2SARBPROC glewWindowPos2sARB = NULL;
PFNGLWINDOWPOS2SVARBPROC glewWindowPos2svARB = NULL;
PFNGLWINDOWPOS3DARBPROC glewWindowPos3dARB = NULL;
PFNGLWINDOWPOS3DVARBPROC glewWindowPos3dvARB = NULL;
PFNGLWINDOWPOS3FARBPROC glewWindowPos3fARB = NULL;
PFNGLWINDOWPOS3FVARBPROC glewWindowPos3fvARB = NULL;
PFNGLWINDOWPOS3IARBPROC glewWindowPos3iARB = NULL;
PFNGLWINDOWPOS3IVARBPROC glewWindowPos3ivARB = NULL;
PFNGLWINDOWPOS3SARBPROC glewWindowPos3sARB = NULL;
PFNGLWINDOWPOS3SVARBPROC glewWindowPos3svARB = NULL;

static GLboolean _glewInit_GL_ARB_window_pos (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewWindowPos2dARB = (PFNGLWINDOWPOS2DARBPROC)glewGetProcAddress("glWindowPos2dARB")) == NULL) || r;
  r = ((glewWindowPos2dvARB = (PFNGLWINDOWPOS2DVARBPROC)glewGetProcAddress("glWindowPos2dvARB")) == NULL) || r;
  r = ((glewWindowPos2fARB = (PFNGLWINDOWPOS2FARBPROC)glewGetProcAddress("glWindowPos2fARB")) == NULL) || r;
  r = ((glewWindowPos2fvARB = (PFNGLWINDOWPOS2FVARBPROC)glewGetProcAddress("glWindowPos2fvARB")) == NULL) || r;
  r = ((glewWindowPos2iARB = (PFNGLWINDOWPOS2IARBPROC)glewGetProcAddress("glWindowPos2iARB")) == NULL) || r;
  r = ((glewWindowPos2ivARB = (PFNGLWINDOWPOS2IVARBPROC)glewGetProcAddress("glWindowPos2ivARB")) == NULL) || r;
  r = ((glewWindowPos2sARB = (PFNGLWINDOWPOS2SARBPROC)glewGetProcAddress("glWindowPos2sARB")) == NULL) || r;
  r = ((glewWindowPos2svARB = (PFNGLWINDOWPOS2SVARBPROC)glewGetProcAddress("glWindowPos2svARB")) == NULL) || r;
  r = ((glewWindowPos3dARB = (PFNGLWINDOWPOS3DARBPROC)glewGetProcAddress("glWindowPos3dARB")) == NULL) || r;
  r = ((glewWindowPos3dvARB = (PFNGLWINDOWPOS3DVARBPROC)glewGetProcAddress("glWindowPos3dvARB")) == NULL) || r;
  r = ((glewWindowPos3fARB = (PFNGLWINDOWPOS3FARBPROC)glewGetProcAddress("glWindowPos3fARB")) == NULL) || r;
  r = ((glewWindowPos3fvARB = (PFNGLWINDOWPOS3FVARBPROC)glewGetProcAddress("glWindowPos3fvARB")) == NULL) || r;
  r = ((glewWindowPos3iARB = (PFNGLWINDOWPOS3IARBPROC)glewGetProcAddress("glWindowPos3iARB")) == NULL) || r;
  r = ((glewWindowPos3ivARB = (PFNGLWINDOWPOS3IVARBPROC)glewGetProcAddress("glWindowPos3ivARB")) == NULL) || r;
  r = ((glewWindowPos3sARB = (PFNGLWINDOWPOS3SARBPROC)glewGetProcAddress("glWindowPos3sARB")) == NULL) || r;
  r = ((glewWindowPos3svARB = (PFNGLWINDOWPOS3SVARBPROC)glewGetProcAddress("glWindowPos3svARB")) == NULL) || r;

  return r;
}

GLboolean GLEW_ARB_window_pos = GL_FALSE;

#endif /* GL_ARB_window_pos */

/* ------------------------- GL_ATIX_point_sprites ------------------------- */

#ifdef GL_ATIX_point_sprites

GLboolean GLEW_ATIX_point_sprites = GL_FALSE;

#endif /* GL_ATIX_point_sprites */

/* ---------------------- GL_ATIX_texture_env_combine3 --------------------- */

#ifdef GL_ATIX_texture_env_combine3

GLboolean GLEW_ATIX_texture_env_combine3 = GL_FALSE;

#endif /* GL_ATIX_texture_env_combine3 */

/* ----------------------- GL_ATIX_texture_env_route ----------------------- */

#ifdef GL_ATIX_texture_env_route

GLboolean GLEW_ATIX_texture_env_route = GL_FALSE;

#endif /* GL_ATIX_texture_env_route */

/* ---------------- GL_ATIX_vertex_shader_output_point_size ---------------- */

#ifdef GL_ATIX_vertex_shader_output_point_size

GLboolean GLEW_ATIX_vertex_shader_output_point_size = GL_FALSE;

#endif /* GL_ATIX_vertex_shader_output_point_size */

/* -------------------------- GL_ATI_draw_buffers -------------------------- */

#ifdef GL_ATI_draw_buffers

PFNGLDRAWBUFFERSATIPROC glewDrawBuffersATI = NULL;

static GLboolean _glewInit_GL_ATI_draw_buffers (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewDrawBuffersATI = (PFNGLDRAWBUFFERSATIPROC)glewGetProcAddress("glDrawBuffersATI")) == NULL) || r;

  return r;
}

GLboolean GLEW_ATI_draw_buffers = GL_FALSE;

#endif /* GL_ATI_draw_buffers */

/* -------------------------- GL_ATI_element_array ------------------------- */

#ifdef GL_ATI_element_array

PFNGLDRAWELEMENTARRAYATIPROC glewDrawElementArrayATI = NULL;
PFNGLDRAWRANGEELEMENTARRAYATIPROC glewDrawRangeElementArrayATI = NULL;
PFNGLELEMENTPOINTERATIPROC glewElementPointerATI = NULL;

static GLboolean _glewInit_GL_ATI_element_array (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewDrawElementArrayATI = (PFNGLDRAWELEMENTARRAYATIPROC)glewGetProcAddress("glDrawElementArrayATI")) == NULL) || r;
  r = ((glewDrawRangeElementArrayATI = (PFNGLDRAWRANGEELEMENTARRAYATIPROC)glewGetProcAddress("glDrawRangeElementArrayATI")) == NULL) || r;
  r = ((glewElementPointerATI = (PFNGLELEMENTPOINTERATIPROC)glewGetProcAddress("glElementPointerATI")) == NULL) || r;

  return r;
}

GLboolean GLEW_ATI_element_array = GL_FALSE;

#endif /* GL_ATI_element_array */

/* ------------------------- GL_ATI_envmap_bumpmap ------------------------- */

#ifdef GL_ATI_envmap_bumpmap

PFNGLGETTEXBUMPPARAMETERFVATIPROC glewGetTexBumpParameterfvATI = NULL;
PFNGLGETTEXBUMPPARAMETERIVATIPROC glewGetTexBumpParameterivATI = NULL;
PFNGLTEXBUMPPARAMETERFVATIPROC glewTexBumpParameterfvATI = NULL;
PFNGLTEXBUMPPARAMETERIVATIPROC glewTexBumpParameterivATI = NULL;

static GLboolean _glewInit_GL_ATI_envmap_bumpmap (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewGetTexBumpParameterfvATI = (PFNGLGETTEXBUMPPARAMETERFVATIPROC)glewGetProcAddress("glGetTexBumpParameterfvATI")) == NULL) || r;
  r = ((glewGetTexBumpParameterivATI = (PFNGLGETTEXBUMPPARAMETERIVATIPROC)glewGetProcAddress("glGetTexBumpParameterivATI")) == NULL) || r;
  r = ((glewTexBumpParameterfvATI = (PFNGLTEXBUMPPARAMETERFVATIPROC)glewGetProcAddress("glTexBumpParameterfvATI")) == NULL) || r;
  r = ((glewTexBumpParameterivATI = (PFNGLTEXBUMPPARAMETERIVATIPROC)glewGetProcAddress("glTexBumpParameterivATI")) == NULL) || r;

  return r;
}

GLboolean GLEW_ATI_envmap_bumpmap = GL_FALSE;

#endif /* GL_ATI_envmap_bumpmap */

/* ------------------------- GL_ATI_fragment_shader ------------------------ */

#ifdef GL_ATI_fragment_shader

PFNGLALPHAFRAGMENTOP1ATIPROC glewAlphaFragmentOp1ATI = NULL;
PFNGLALPHAFRAGMENTOP2ATIPROC glewAlphaFragmentOp2ATI = NULL;
PFNGLALPHAFRAGMENTOP3ATIPROC glewAlphaFragmentOp3ATI = NULL;
PFNGLBEGINFRAGMENTSHADERATIPROC glewBeginFragmentShaderATI = NULL;
PFNGLBINDFRAGMENTSHADERATIPROC glewBindFragmentShaderATI = NULL;
PFNGLCOLORFRAGMENTOP1ATIPROC glewColorFragmentOp1ATI = NULL;
PFNGLCOLORFRAGMENTOP2ATIPROC glewColorFragmentOp2ATI = NULL;
PFNGLCOLORFRAGMENTOP3ATIPROC glewColorFragmentOp3ATI = NULL;
PFNGLDELETEFRAGMENTSHADERATIPROC glewDeleteFragmentShaderATI = NULL;
PFNGLENDFRAGMENTSHADERATIPROC glewEndFragmentShaderATI = NULL;
PFNGLGENFRAGMENTSHADERSATIPROC glewGenFragmentShadersATI = NULL;
PFNGLPASSTEXCOORDATIPROC glewPassTexCoordATI = NULL;
PFNGLSAMPLEMAPATIPROC glewSampleMapATI = NULL;
PFNGLSETFRAGMENTSHADERCONSTANTATIPROC glewSetFragmentShaderConstantATI = NULL;

static GLboolean _glewInit_GL_ATI_fragment_shader (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewAlphaFragmentOp1ATI = (PFNGLALPHAFRAGMENTOP1ATIPROC)glewGetProcAddress("glAlphaFragmentOp1ATI")) == NULL) || r;
  r = ((glewAlphaFragmentOp2ATI = (PFNGLALPHAFRAGMENTOP2ATIPROC)glewGetProcAddress("glAlphaFragmentOp2ATI")) == NULL) || r;
  r = ((glewAlphaFragmentOp3ATI = (PFNGLALPHAFRAGMENTOP3ATIPROC)glewGetProcAddress("glAlphaFragmentOp3ATI")) == NULL) || r;
  r = ((glewBeginFragmentShaderATI = (PFNGLBEGINFRAGMENTSHADERATIPROC)glewGetProcAddress("glBeginFragmentShaderATI")) == NULL) || r;
  r = ((glewBindFragmentShaderATI = (PFNGLBINDFRAGMENTSHADERATIPROC)glewGetProcAddress("glBindFragmentShaderATI")) == NULL) || r;
  r = ((glewColorFragmentOp1ATI = (PFNGLCOLORFRAGMENTOP1ATIPROC)glewGetProcAddress("glColorFragmentOp1ATI")) == NULL) || r;
  r = ((glewColorFragmentOp2ATI = (PFNGLCOLORFRAGMENTOP2ATIPROC)glewGetProcAddress("glColorFragmentOp2ATI")) == NULL) || r;
  r = ((glewColorFragmentOp3ATI = (PFNGLCOLORFRAGMENTOP3ATIPROC)glewGetProcAddress("glColorFragmentOp3ATI")) == NULL) || r;
  r = ((glewDeleteFragmentShaderATI = (PFNGLDELETEFRAGMENTSHADERATIPROC)glewGetProcAddress("glDeleteFragmentShaderATI")) == NULL) || r;
  r = ((glewEndFragmentShaderATI = (PFNGLENDFRAGMENTSHADERATIPROC)glewGetProcAddress("glEndFragmentShaderATI")) == NULL) || r;
  r = ((glewGenFragmentShadersATI = (PFNGLGENFRAGMENTSHADERSATIPROC)glewGetProcAddress("glGenFragmentShadersATI")) == NULL) || r;
  r = ((glewPassTexCoordATI = (PFNGLPASSTEXCOORDATIPROC)glewGetProcAddress("glPassTexCoordATI")) == NULL) || r;
  r = ((glewSampleMapATI = (PFNGLSAMPLEMAPATIPROC)glewGetProcAddress("glSampleMapATI")) == NULL) || r;
  r = ((glewSetFragmentShaderConstantATI = (PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)glewGetProcAddress("glSetFragmentShaderConstantATI")) == NULL) || r;

  return r;
}

GLboolean GLEW_ATI_fragment_shader = GL_FALSE;

#endif /* GL_ATI_fragment_shader */

/* ------------------------ GL_ATI_map_object_buffer ----------------------- */

#ifdef GL_ATI_map_object_buffer

PFNGLMAPOBJECTBUFFERATIPROC glewMapObjectBufferATI = NULL;
PFNGLUNMAPOBJECTBUFFERATIPROC glewUnmapObjectBufferATI = NULL;

static GLboolean _glewInit_GL_ATI_map_object_buffer (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewMapObjectBufferATI = (PFNGLMAPOBJECTBUFFERATIPROC)glewGetProcAddress("glMapObjectBufferATI")) == NULL) || r;
  r = ((glewUnmapObjectBufferATI = (PFNGLUNMAPOBJECTBUFFERATIPROC)glewGetProcAddress("glUnmapObjectBufferATI")) == NULL) || r;

  return r;
}

GLboolean GLEW_ATI_map_object_buffer = GL_FALSE;

#endif /* GL_ATI_map_object_buffer */

/* -------------------------- GL_ATI_pn_triangles -------------------------- */

#ifdef GL_ATI_pn_triangles

PFNGLPNTRIANGLESFATIPROC glPNTrianglewesfATI = NULL;
PFNGLPNTRIANGLESIATIPROC glPNTrianglewesiATI = NULL;

static GLboolean _glewInit_GL_ATI_pn_triangles (void)
{
  GLboolean r = GL_FALSE;

  r = ((glPNTrianglewesfATI = (PFNGLPNTRIANGLESFATIPROC)glewGetProcAddress("glPNTrianglesfATI")) == NULL) || r;
  r = ((glPNTrianglewesiATI = (PFNGLPNTRIANGLESIATIPROC)glewGetProcAddress("glPNTrianglesiATI")) == NULL) || r;

  return r;
}

GLboolean GLEW_ATI_pn_triangles = GL_FALSE;

#endif /* GL_ATI_pn_triangles */

/* ------------------------ GL_ATI_separate_stencil ------------------------ */

#ifdef GL_ATI_separate_stencil

PFNGLSTENCILFUNCSEPARATEATIPROC glewStencilFuncSeparateATI = NULL;
PFNGLSTENCILOPSEPARATEATIPROC glewStencilOpSeparateATI = NULL;

static GLboolean _glewInit_GL_ATI_separate_stencil (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewStencilFuncSeparateATI = (PFNGLSTENCILFUNCSEPARATEATIPROC)glewGetProcAddress("glStencilFuncSeparateATI")) == NULL) || r;
  r = ((glewStencilOpSeparateATI = (PFNGLSTENCILOPSEPARATEATIPROC)glewGetProcAddress("glStencilOpSeparateATI")) == NULL) || r;

  return r;
}

GLboolean GLEW_ATI_separate_stencil = GL_FALSE;

#endif /* GL_ATI_separate_stencil */

/* ---------------------- GL_ATI_text_fragment_shader ---------------------- */

#ifdef GL_ATI_text_fragment_shader

GLboolean GLEW_ATI_text_fragment_shader = GL_FALSE;

#endif /* GL_ATI_text_fragment_shader */

/* ---------------------- GL_ATI_texture_env_combine3 ---------------------- */

#ifdef GL_ATI_texture_env_combine3

GLboolean GLEW_ATI_texture_env_combine3 = GL_FALSE;

#endif /* GL_ATI_texture_env_combine3 */

/* -------------------------- GL_ATI_texture_float ------------------------- */

#ifdef GL_ATI_texture_float

GLboolean GLEW_ATI_texture_float = GL_FALSE;

#endif /* GL_ATI_texture_float */

/* ----------------------- GL_ATI_texture_mirror_once ---------------------- */

#ifdef GL_ATI_texture_mirror_once

GLboolean GLEW_ATI_texture_mirror_once = GL_FALSE;

#endif /* GL_ATI_texture_mirror_once */

/* ----------------------- GL_ATI_vertex_array_object ---------------------- */

#ifdef GL_ATI_vertex_array_object

PFNGLARRAYOBJECTATIPROC glewArrayObjectATI = NULL;
PFNGLFREEOBJECTBUFFERATIPROC glewFreeObjectBufferATI = NULL;
PFNGLGETARRAYOBJECTFVATIPROC glewGetArrayObjectfvATI = NULL;
PFNGLGETARRAYOBJECTIVATIPROC glewGetArrayObjectivATI = NULL;
PFNGLGETOBJECTBUFFERFVATIPROC glewGetObjectBufferfvATI = NULL;
PFNGLGETOBJECTBUFFERIVATIPROC glewGetObjectBufferivATI = NULL;
PFNGLGETVARIANTARRAYOBJECTFVATIPROC glewGetVariantArrayObjectfvATI = NULL;
PFNGLGETVARIANTARRAYOBJECTIVATIPROC glewGetVariantArrayObjectivATI = NULL;
PFNGLISOBJECTBUFFERATIPROC glewIsObjectBufferATI = NULL;
PFNGLNEWOBJECTBUFFERATIPROC glewNewObjectBufferATI = NULL;
PFNGLUPDATEOBJECTBUFFERATIPROC glewUpdateObjectBufferATI = NULL;
PFNGLVARIANTARRAYOBJECTATIPROC glewVariantArrayObjectATI = NULL;

static GLboolean _glewInit_GL_ATI_vertex_array_object (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewArrayObjectATI = (PFNGLARRAYOBJECTATIPROC)glewGetProcAddress("glArrayObjectATI")) == NULL) || r;
  r = ((glewFreeObjectBufferATI = (PFNGLFREEOBJECTBUFFERATIPROC)glewGetProcAddress("glFreeObjectBufferATI")) == NULL) || r;
  r = ((glewGetArrayObjectfvATI = (PFNGLGETARRAYOBJECTFVATIPROC)glewGetProcAddress("glGetArrayObjectfvATI")) == NULL) || r;
  r = ((glewGetArrayObjectivATI = (PFNGLGETARRAYOBJECTIVATIPROC)glewGetProcAddress("glGetArrayObjectivATI")) == NULL) || r;
  r = ((glewGetObjectBufferfvATI = (PFNGLGETOBJECTBUFFERFVATIPROC)glewGetProcAddress("glGetObjectBufferfvATI")) == NULL) || r;
  r = ((glewGetObjectBufferivATI = (PFNGLGETOBJECTBUFFERIVATIPROC)glewGetProcAddress("glGetObjectBufferivATI")) == NULL) || r;
  r = ((glewGetVariantArrayObjectfvATI = (PFNGLGETVARIANTARRAYOBJECTFVATIPROC)glewGetProcAddress("glGetVariantArrayObjectfvATI")) == NULL) || r;
  r = ((glewGetVariantArrayObjectivATI = (PFNGLGETVARIANTARRAYOBJECTIVATIPROC)glewGetProcAddress("glGetVariantArrayObjectivATI")) == NULL) || r;
  r = ((glewIsObjectBufferATI = (PFNGLISOBJECTBUFFERATIPROC)glewGetProcAddress("glIsObjectBufferATI")) == NULL) || r;
  r = ((glewNewObjectBufferATI = (PFNGLNEWOBJECTBUFFERATIPROC)glewGetProcAddress("glNewObjectBufferATI")) == NULL) || r;
  r = ((glewUpdateObjectBufferATI = (PFNGLUPDATEOBJECTBUFFERATIPROC)glewGetProcAddress("glUpdateObjectBufferATI")) == NULL) || r;
  r = ((glewVariantArrayObjectATI = (PFNGLVARIANTARRAYOBJECTATIPROC)glewGetProcAddress("glVariantArrayObjectATI")) == NULL) || r;

  return r;
}

GLboolean GLEW_ATI_vertex_array_object = GL_FALSE;

#endif /* GL_ATI_vertex_array_object */

/* ------------------- GL_ATI_vertex_attrib_array_object ------------------- */

#ifdef GL_ATI_vertex_attrib_array_object

PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC glewGetVertexAttribArrayObjectfvATI = NULL;
PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC glewGetVertexAttribArrayObjectivATI = NULL;
PFNGLVERTEXATTRIBARRAYOBJECTATIPROC glewVertexAttribArrayObjectATI = NULL;

static GLboolean _glewInit_GL_ATI_vertex_attrib_array_object (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewGetVertexAttribArrayObjectfvATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)glewGetProcAddress("glGetVertexAttribArrayObjectfvATI")) == NULL) || r;
  r = ((glewGetVertexAttribArrayObjectivATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)glewGetProcAddress("glGetVertexAttribArrayObjectivATI")) == NULL) || r;
  r = ((glewVertexAttribArrayObjectATI = (PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)glewGetProcAddress("glVertexAttribArrayObjectATI")) == NULL) || r;

  return r;
}

GLboolean GLEW_ATI_vertex_attrib_array_object = GL_FALSE;

#endif /* GL_ATI_vertex_attrib_array_object */

/* ------------------------- GL_ATI_vertex_streams ------------------------- */

#ifdef GL_ATI_vertex_streams

PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC glewClientActiveVertexStreamATI = NULL;
PFNGLNORMALSTREAM3BATIPROC glewNormalStream3bATI = NULL;
PFNGLNORMALSTREAM3BVATIPROC glewNormalStream3bvATI = NULL;
PFNGLNORMALSTREAM3DATIPROC glewNormalStream3dATI = NULL;
PFNGLNORMALSTREAM3DVATIPROC glewNormalStream3dvATI = NULL;
PFNGLNORMALSTREAM3FATIPROC glewNormalStream3fATI = NULL;
PFNGLNORMALSTREAM3FVATIPROC glewNormalStream3fvATI = NULL;
PFNGLNORMALSTREAM3IATIPROC glewNormalStream3iATI = NULL;
PFNGLNORMALSTREAM3IVATIPROC glewNormalStream3ivATI = NULL;
PFNGLNORMALSTREAM3SATIPROC glewNormalStream3sATI = NULL;
PFNGLNORMALSTREAM3SVATIPROC glewNormalStream3svATI = NULL;
PFNGLVERTEXBLENDENVFATIPROC glewVertexBlendEnvfATI = NULL;
PFNGLVERTEXBLENDENVIATIPROC glewVertexBlendEnviATI = NULL;
PFNGLVERTEXSTREAM2DATIPROC glewVertexStream2dATI = NULL;
PFNGLVERTEXSTREAM2DVATIPROC glewVertexStream2dvATI = NULL;
PFNGLVERTEXSTREAM2FATIPROC glewVertexStream2fATI = NULL;
PFNGLVERTEXSTREAM2FVATIPROC glewVertexStream2fvATI = NULL;
PFNGLVERTEXSTREAM2IATIPROC glewVertexStream2iATI = NULL;
PFNGLVERTEXSTREAM2IVATIPROC glewVertexStream2ivATI = NULL;
PFNGLVERTEXSTREAM2SATIPROC glewVertexStream2sATI = NULL;
PFNGLVERTEXSTREAM2SVATIPROC glewVertexStream2svATI = NULL;
PFNGLVERTEXSTREAM3DATIPROC glewVertexStream3dATI = NULL;
PFNGLVERTEXSTREAM3DVATIPROC glewVertexStream3dvATI = NULL;
PFNGLVERTEXSTREAM3FATIPROC glewVertexStream3fATI = NULL;
PFNGLVERTEXSTREAM3FVATIPROC glewVertexStream3fvATI = NULL;
PFNGLVERTEXSTREAM3IATIPROC glewVertexStream3iATI = NULL;
PFNGLVERTEXSTREAM3IVATIPROC glewVertexStream3ivATI = NULL;
PFNGLVERTEXSTREAM3SATIPROC glewVertexStream3sATI = NULL;
PFNGLVERTEXSTREAM3SVATIPROC glewVertexStream3svATI = NULL;
PFNGLVERTEXSTREAM4DATIPROC glewVertexStream4dATI = NULL;
PFNGLVERTEXSTREAM4DVATIPROC glewVertexStream4dvATI = NULL;
PFNGLVERTEXSTREAM4FATIPROC glewVertexStream4fATI = NULL;
PFNGLVERTEXSTREAM4FVATIPROC glewVertexStream4fvATI = NULL;
PFNGLVERTEXSTREAM4IATIPROC glewVertexStream4iATI = NULL;
PFNGLVERTEXSTREAM4IVATIPROC glewVertexStream4ivATI = NULL;
PFNGLVERTEXSTREAM4SATIPROC glewVertexStream4sATI = NULL;
PFNGLVERTEXSTREAM4SVATIPROC glewVertexStream4svATI = NULL;

static GLboolean _glewInit_GL_ATI_vertex_streams (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewClientActiveVertexStreamATI = (PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)glewGetProcAddress("glClientActiveVertexStreamATI")) == NULL) || r;
  r = ((glewNormalStream3bATI = (PFNGLNORMALSTREAM3BATIPROC)glewGetProcAddress("glNormalStream3bATI")) == NULL) || r;
  r = ((glewNormalStream3bvATI = (PFNGLNORMALSTREAM3BVATIPROC)glewGetProcAddress("glNormalStream3bvATI")) == NULL) || r;
  r = ((glewNormalStream3dATI = (PFNGLNORMALSTREAM3DATIPROC)glewGetProcAddress("glNormalStream3dATI")) == NULL) || r;
  r = ((glewNormalStream3dvATI = (PFNGLNORMALSTREAM3DVATIPROC)glewGetProcAddress("glNormalStream3dvATI")) == NULL) || r;
  r = ((glewNormalStream3fATI = (PFNGLNORMALSTREAM3FATIPROC)glewGetProcAddress("glNormalStream3fATI")) == NULL) || r;
  r = ((glewNormalStream3fvATI = (PFNGLNORMALSTREAM3FVATIPROC)glewGetProcAddress("glNormalStream3fvATI")) == NULL) || r;
  r = ((glewNormalStream3iATI = (PFNGLNORMALSTREAM3IATIPROC)glewGetProcAddress("glNormalStream3iATI")) == NULL) || r;
  r = ((glewNormalStream3ivATI = (PFNGLNORMALSTREAM3IVATIPROC)glewGetProcAddress("glNormalStream3ivATI")) == NULL) || r;
  r = ((glewNormalStream3sATI = (PFNGLNORMALSTREAM3SATIPROC)glewGetProcAddress("glNormalStream3sATI")) == NULL) || r;
  r = ((glewNormalStream3svATI = (PFNGLNORMALSTREAM3SVATIPROC)glewGetProcAddress("glNormalStream3svATI")) == NULL) || r;
  r = ((glewVertexBlendEnvfATI = (PFNGLVERTEXBLENDENVFATIPROC)glewGetProcAddress("glVertexBlendEnvfATI")) == NULL) || r;
  r = ((glewVertexBlendEnviATI = (PFNGLVERTEXBLENDENVIATIPROC)glewGetProcAddress("glVertexBlendEnviATI")) == NULL) || r;
  r = ((glewVertexStream2dATI = (PFNGLVERTEXSTREAM2DATIPROC)glewGetProcAddress("glVertexStream2dATI")) == NULL) || r;
  r = ((glewVertexStream2dvATI = (PFNGLVERTEXSTREAM2DVATIPROC)glewGetProcAddress("glVertexStream2dvATI")) == NULL) || r;
  r = ((glewVertexStream2fATI = (PFNGLVERTEXSTREAM2FATIPROC)glewGetProcAddress("glVertexStream2fATI")) == NULL) || r;
  r = ((glewVertexStream2fvATI = (PFNGLVERTEXSTREAM2FVATIPROC)glewGetProcAddress("glVertexStream2fvATI")) == NULL) || r;
  r = ((glewVertexStream2iATI = (PFNGLVERTEXSTREAM2IATIPROC)glewGetProcAddress("glVertexStream2iATI")) == NULL) || r;
  r = ((glewVertexStream2ivATI = (PFNGLVERTEXSTREAM2IVATIPROC)glewGetProcAddress("glVertexStream2ivATI")) == NULL) || r;
  r = ((glewVertexStream2sATI = (PFNGLVERTEXSTREAM2SATIPROC)glewGetProcAddress("glVertexStream2sATI")) == NULL) || r;
  r = ((glewVertexStream2svATI = (PFNGLVERTEXSTREAM2SVATIPROC)glewGetProcAddress("glVertexStream2svATI")) == NULL) || r;
  r = ((glewVertexStream3dATI = (PFNGLVERTEXSTREAM3DATIPROC)glewGetProcAddress("glVertexStream3dATI")) == NULL) || r;
  r = ((glewVertexStream3dvATI = (PFNGLVERTEXSTREAM3DVATIPROC)glewGetProcAddress("glVertexStream3dvATI")) == NULL) || r;
  r = ((glewVertexStream3fATI = (PFNGLVERTEXSTREAM3FATIPROC)glewGetProcAddress("glVertexStream3fATI")) == NULL) || r;
  r = ((glewVertexStream3fvATI = (PFNGLVERTEXSTREAM3FVATIPROC)glewGetProcAddress("glVertexStream3fvATI")) == NULL) || r;
  r = ((glewVertexStream3iATI = (PFNGLVERTEXSTREAM3IATIPROC)glewGetProcAddress("glVertexStream3iATI")) == NULL) || r;
  r = ((glewVertexStream3ivATI = (PFNGLVERTEXSTREAM3IVATIPROC)glewGetProcAddress("glVertexStream3ivATI")) == NULL) || r;
  r = ((glewVertexStream3sATI = (PFNGLVERTEXSTREAM3SATIPROC)glewGetProcAddress("glVertexStream3sATI")) == NULL) || r;
  r = ((glewVertexStream3svATI = (PFNGLVERTEXSTREAM3SVATIPROC)glewGetProcAddress("glVertexStream3svATI")) == NULL) || r;
  r = ((glewVertexStream4dATI = (PFNGLVERTEXSTREAM4DATIPROC)glewGetProcAddress("glVertexStream4dATI")) == NULL) || r;
  r = ((glewVertexStream4dvATI = (PFNGLVERTEXSTREAM4DVATIPROC)glewGetProcAddress("glVertexStream4dvATI")) == NULL) || r;
  r = ((glewVertexStream4fATI = (PFNGLVERTEXSTREAM4FATIPROC)glewGetProcAddress("glVertexStream4fATI")) == NULL) || r;
  r = ((glewVertexStream4fvATI = (PFNGLVERTEXSTREAM4FVATIPROC)glewGetProcAddress("glVertexStream4fvATI")) == NULL) || r;
  r = ((glewVertexStream4iATI = (PFNGLVERTEXSTREAM4IATIPROC)glewGetProcAddress("glVertexStream4iATI")) == NULL) || r;
  r = ((glewVertexStream4ivATI = (PFNGLVERTEXSTREAM4IVATIPROC)glewGetProcAddress("glVertexStream4ivATI")) == NULL) || r;
  r = ((glewVertexStream4sATI = (PFNGLVERTEXSTREAM4SATIPROC)glewGetProcAddress("glVertexStream4sATI")) == NULL) || r;
  r = ((glewVertexStream4svATI = (PFNGLVERTEXSTREAM4SVATIPROC)glewGetProcAddress("glVertexStream4svATI")) == NULL) || r;

  return r;
}

GLboolean GLEW_ATI_vertex_streams = GL_FALSE;

#endif /* GL_ATI_vertex_streams */

/* --------------------------- GL_EXT_422_pixels --------------------------- */

#ifdef GL_EXT_422_pixels

GLboolean GLEW_EXT_422_pixels = GL_FALSE;

#endif /* GL_EXT_422_pixels */

/* ------------------------------ GL_EXT_abgr ------------------------------ */

#ifdef GL_EXT_abgr

GLboolean GLEW_EXT_abgr = GL_FALSE;

#endif /* GL_EXT_abgr */

/* ------------------------------ GL_EXT_bgra ------------------------------ */

#ifdef GL_EXT_bgra

GLboolean GLEW_EXT_bgra = GL_FALSE;

#endif /* GL_EXT_bgra */

/* --------------------------- GL_EXT_blend_color -------------------------- */

#ifdef GL_EXT_blend_color

PFNGLBLENDCOLOREXTPROC glewBlendColorEXT = NULL;

static GLboolean _glewInit_GL_EXT_blend_color (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBlendColorEXT = (PFNGLBLENDCOLOREXTPROC)glewGetProcAddress("glBlendColorEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_blend_color = GL_FALSE;

#endif /* GL_EXT_blend_color */

/* ----------------------- GL_EXT_blend_func_separate ---------------------- */

#ifdef GL_EXT_blend_func_separate

PFNGLBLENDFUNCSEPARATEEXTPROC glewBlendFuncSeparateEXT = NULL;

static GLboolean _glewInit_GL_EXT_blend_func_separate (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBlendFuncSeparateEXT = (PFNGLBLENDFUNCSEPARATEEXTPROC)glewGetProcAddress("glBlendFuncSeparateEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_blend_func_separate = GL_FALSE;

#endif /* GL_EXT_blend_func_separate */

/* ------------------------- GL_EXT_blend_logic_op ------------------------- */

#ifdef GL_EXT_blend_logic_op

GLboolean GLEW_EXT_blend_logic_op = GL_FALSE;

#endif /* GL_EXT_blend_logic_op */

/* -------------------------- GL_EXT_blend_minmax -------------------------- */

#ifdef GL_EXT_blend_minmax

PFNGLBLENDEQUATIONEXTPROC glewBlendEquationEXT = NULL;

static GLboolean _glewInit_GL_EXT_blend_minmax (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBlendEquationEXT = (PFNGLBLENDEQUATIONEXTPROC)glewGetProcAddress("glBlendEquationEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_blend_minmax = GL_FALSE;

#endif /* GL_EXT_blend_minmax */

/* ------------------------- GL_EXT_blend_subtract ------------------------- */

#ifdef GL_EXT_blend_subtract

GLboolean GLEW_EXT_blend_subtract = GL_FALSE;

#endif /* GL_EXT_blend_subtract */

/* ------------------------ GL_EXT_clip_volume_hint ------------------------ */

#ifdef GL_EXT_clip_volume_hint

GLboolean GLEW_EXT_clip_volume_hint = GL_FALSE;

#endif /* GL_EXT_clip_volume_hint */

/* ------------------------------ GL_EXT_cmyka ----------------------------- */

#ifdef GL_EXT_cmyka

GLboolean GLEW_EXT_cmyka = GL_FALSE;

#endif /* GL_EXT_cmyka */

/* ------------------------- GL_EXT_color_subtable ------------------------- */

#ifdef GL_EXT_color_subtable

PFNGLCOLORSUBTABLEEXTPROC glewColorSubTableEXT = NULL;
PFNGLCOPYCOLORSUBTABLEEXTPROC glewCopyColorSubTableEXT = NULL;

static GLboolean _glewInit_GL_EXT_color_subtable (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewColorSubTableEXT = (PFNGLCOLORSUBTABLEEXTPROC)glewGetProcAddress("glColorSubTableEXT")) == NULL) || r;
  r = ((glewCopyColorSubTableEXT = (PFNGLCOPYCOLORSUBTABLEEXTPROC)glewGetProcAddress("glCopyColorSubTableEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_color_subtable = GL_FALSE;

#endif /* GL_EXT_color_subtable */

/* ---------------------- GL_EXT_compiled_vertex_array --------------------- */

#ifdef GL_EXT_compiled_vertex_array

PFNGLLOCKARRAYSEXTPROC glewLockArraysEXT = NULL;
PFNGLUNLOCKARRAYSEXTPROC glewUnlockArraysEXT = NULL;

static GLboolean _glewInit_GL_EXT_compiled_vertex_array (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewLockArraysEXT = (PFNGLLOCKARRAYSEXTPROC)glewGetProcAddress("glLockArraysEXT")) == NULL) || r;
  r = ((glewUnlockArraysEXT = (PFNGLUNLOCKARRAYSEXTPROC)glewGetProcAddress("glUnlockArraysEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_compiled_vertex_array = GL_FALSE;

#endif /* GL_EXT_compiled_vertex_array */

/* --------------------------- GL_EXT_convolution -------------------------- */

#ifdef GL_EXT_convolution

PFNGLCONVOLUTIONFILTER1DEXTPROC glewConvolutionFilter1DEXT = NULL;
PFNGLCONVOLUTIONFILTER2DEXTPROC glewConvolutionFilter2DEXT = NULL;
PFNGLCONVOLUTIONPARAMETERFEXTPROC glewConvolutionParameterfEXT = NULL;
PFNGLCONVOLUTIONPARAMETERFVEXTPROC glewConvolutionParameterfvEXT = NULL;
PFNGLCONVOLUTIONPARAMETERIEXTPROC glewConvolutionParameteriEXT = NULL;
PFNGLCONVOLUTIONPARAMETERIVEXTPROC glewConvolutionParameterivEXT = NULL;
PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC glewCopyConvolutionFilter1DEXT = NULL;
PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC glewCopyConvolutionFilter2DEXT = NULL;
PFNGLGETCONVOLUTIONFILTEREXTPROC glewGetConvolutionFilterEXT = NULL;
PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC glewGetConvolutionParameterfvEXT = NULL;
PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC glewGetConvolutionParameterivEXT = NULL;
PFNGLGETSEPARABLEFILTEREXTPROC glewGetSeparableFilterEXT = NULL;
PFNGLSEPARABLEFILTER2DEXTPROC glewSeparableFilter2DEXT = NULL;

static GLboolean _glewInit_GL_EXT_convolution (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewConvolutionFilter1DEXT = (PFNGLCONVOLUTIONFILTER1DEXTPROC)glewGetProcAddress("glConvolutionFilter1DEXT")) == NULL) || r;
  r = ((glewConvolutionFilter2DEXT = (PFNGLCONVOLUTIONFILTER2DEXTPROC)glewGetProcAddress("glConvolutionFilter2DEXT")) == NULL) || r;
  r = ((glewConvolutionParameterfEXT = (PFNGLCONVOLUTIONPARAMETERFEXTPROC)glewGetProcAddress("glConvolutionParameterfEXT")) == NULL) || r;
  r = ((glewConvolutionParameterfvEXT = (PFNGLCONVOLUTIONPARAMETERFVEXTPROC)glewGetProcAddress("glConvolutionParameterfvEXT")) == NULL) || r;
  r = ((glewConvolutionParameteriEXT = (PFNGLCONVOLUTIONPARAMETERIEXTPROC)glewGetProcAddress("glConvolutionParameteriEXT")) == NULL) || r;
  r = ((glewConvolutionParameterivEXT = (PFNGLCONVOLUTIONPARAMETERIVEXTPROC)glewGetProcAddress("glConvolutionParameterivEXT")) == NULL) || r;
  r = ((glewCopyConvolutionFilter1DEXT = (PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)glewGetProcAddress("glCopyConvolutionFilter1DEXT")) == NULL) || r;
  r = ((glewCopyConvolutionFilter2DEXT = (PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)glewGetProcAddress("glCopyConvolutionFilter2DEXT")) == NULL) || r;
  r = ((glewGetConvolutionFilterEXT = (PFNGLGETCONVOLUTIONFILTEREXTPROC)glewGetProcAddress("glGetConvolutionFilterEXT")) == NULL) || r;
  r = ((glewGetConvolutionParameterfvEXT = (PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)glewGetProcAddress("glGetConvolutionParameterfvEXT")) == NULL) || r;
  r = ((glewGetConvolutionParameterivEXT = (PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)glewGetProcAddress("glGetConvolutionParameterivEXT")) == NULL) || r;
  r = ((glewGetSeparableFilterEXT = (PFNGLGETSEPARABLEFILTEREXTPROC)glewGetProcAddress("glGetSeparableFilterEXT")) == NULL) || r;
  r = ((glewSeparableFilter2DEXT = (PFNGLSEPARABLEFILTER2DEXTPROC)glewGetProcAddress("glSeparableFilter2DEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_convolution = GL_FALSE;

#endif /* GL_EXT_convolution */

/* ------------------------ GL_EXT_coordinate_frame ------------------------ */

#ifdef GL_EXT_coordinate_frame

PFNGLBINORMALPOINTEREXTPROC glewBinormalPointerEXT = NULL;
PFNGLTANGENTPOINTEREXTPROC glewTangentPointerEXT = NULL;

static GLboolean _glewInit_GL_EXT_coordinate_frame (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBinormalPointerEXT = (PFNGLBINORMALPOINTEREXTPROC)glewGetProcAddress("glBinormalPointerEXT")) == NULL) || r;
  r = ((glewTangentPointerEXT = (PFNGLTANGENTPOINTEREXTPROC)glewGetProcAddress("glTangentPointerEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_coordinate_frame = GL_FALSE;

#endif /* GL_EXT_coordinate_frame */

/* -------------------------- GL_EXT_copy_texture -------------------------- */

#ifdef GL_EXT_copy_texture

PFNGLCOPYTEXIMAGE1DEXTPROC glewCopyTexImage1DEXT = NULL;
PFNGLCOPYTEXIMAGE2DEXTPROC glewCopyTexImage2DEXT = NULL;
PFNGLCOPYTEXSUBIMAGE1DEXTPROC glewCopyTexSubImage1DEXT = NULL;
PFNGLCOPYTEXSUBIMAGE2DEXTPROC glewCopyTexSubImage2DEXT = NULL;
PFNGLCOPYTEXSUBIMAGE3DEXTPROC glewCopyTexSubImage3DEXT = NULL;

static GLboolean _glewInit_GL_EXT_copy_texture (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewCopyTexImage1DEXT = (PFNGLCOPYTEXIMAGE1DEXTPROC)glewGetProcAddress("glCopyTexImage1DEXT")) == NULL) || r;
  r = ((glewCopyTexImage2DEXT = (PFNGLCOPYTEXIMAGE2DEXTPROC)glewGetProcAddress("glCopyTexImage2DEXT")) == NULL) || r;
  r = ((glewCopyTexSubImage1DEXT = (PFNGLCOPYTEXSUBIMAGE1DEXTPROC)glewGetProcAddress("glCopyTexSubImage1DEXT")) == NULL) || r;
  r = ((glewCopyTexSubImage2DEXT = (PFNGLCOPYTEXSUBIMAGE2DEXTPROC)glewGetProcAddress("glCopyTexSubImage2DEXT")) == NULL) || r;
  r = ((glewCopyTexSubImage3DEXT = (PFNGLCOPYTEXSUBIMAGE3DEXTPROC)glewGetProcAddress("glCopyTexSubImage3DEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_copy_texture = GL_FALSE;

#endif /* GL_EXT_copy_texture */

/* --------------------------- GL_EXT_cull_vertex -------------------------- */

#ifdef GL_EXT_cull_vertex

PFNGLCULLPARAMETERDVEXTPROC glewCullParameterdvEXT = NULL;
PFNGLCULLPARAMETERFVEXTPROC glewCullParameterfvEXT = NULL;

static GLboolean _glewInit_GL_EXT_cull_vertex (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewCullParameterdvEXT = (PFNGLCULLPARAMETERDVEXTPROC)glewGetProcAddress("glCullParameterdvEXT")) == NULL) || r;
  r = ((glewCullParameterfvEXT = (PFNGLCULLPARAMETERFVEXTPROC)glewGetProcAddress("glCullParameterfvEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_cull_vertex = GL_FALSE;

#endif /* GL_EXT_cull_vertex */

/* ------------------------ GL_EXT_depth_bounds_test ----------------------- */

#ifdef GL_EXT_depth_bounds_test

PFNGLDEPTHBOUNDSEXTPROC glewDepthBoundsEXT = NULL;

static GLboolean _glewInit_GL_EXT_depth_bounds_test (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewDepthBoundsEXT = (PFNGLDEPTHBOUNDSEXTPROC)glewGetProcAddress("glDepthBoundsEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_depth_bounds_test = GL_FALSE;

#endif /* GL_EXT_depth_bounds_test */

/* ----------------------- GL_EXT_draw_range_elements ---------------------- */

#ifdef GL_EXT_draw_range_elements

GLboolean GLEW_EXT_draw_range_elements = GL_FALSE;

#endif /* GL_EXT_draw_range_elements */

/* ---------------------------- GL_EXT_fog_coord --------------------------- */

#ifdef GL_EXT_fog_coord

PFNGLFOGCOORDPOINTEREXTPROC glewFogCoordPointerEXT = NULL;
PFNGLFOGCOORDDEXTPROC glewFogCoorddEXT = NULL;
PFNGLFOGCOORDDVEXTPROC glewFogCoorddvEXT = NULL;
PFNGLFOGCOORDFEXTPROC glewFogCoordfEXT = NULL;
PFNGLFOGCOORDFVEXTPROC glewFogCoordfvEXT = NULL;

static GLboolean _glewInit_GL_EXT_fog_coord (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewFogCoordPointerEXT = (PFNGLFOGCOORDPOINTEREXTPROC)glewGetProcAddress("glFogCoordPointerEXT")) == NULL) || r;
  r = ((glewFogCoorddEXT = (PFNGLFOGCOORDDEXTPROC)glewGetProcAddress("glFogCoorddEXT")) == NULL) || r;
  r = ((glewFogCoorddvEXT = (PFNGLFOGCOORDDVEXTPROC)glewGetProcAddress("glFogCoorddvEXT")) == NULL) || r;
  r = ((glewFogCoordfEXT = (PFNGLFOGCOORDFEXTPROC)glewGetProcAddress("glFogCoordfEXT")) == NULL) || r;
  r = ((glewFogCoordfvEXT = (PFNGLFOGCOORDFVEXTPROC)glewGetProcAddress("glFogCoordfvEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_fog_coord = GL_FALSE;

#endif /* GL_EXT_fog_coord */

/* ------------------------ GL_EXT_fragment_lighting ----------------------- */

#ifdef GL_EXT_fragment_lighting

PFNGLFRAGMENTCOLORMATERIALEXTPROC glewFragmentColorMaterialEXT = NULL;
PFNGLFRAGMENTLIGHTMODELFEXTPROC glewFragmentLightModelfEXT = NULL;
PFNGLFRAGMENTLIGHTMODELFVEXTPROC glewFragmentLightModelfvEXT = NULL;
PFNGLFRAGMENTLIGHTMODELIEXTPROC glewFragmentLightModeliEXT = NULL;
PFNGLFRAGMENTLIGHTMODELIVEXTPROC glewFragmentLightModelivEXT = NULL;
PFNGLFRAGMENTLIGHTFEXTPROC glewFragmentLightfEXT = NULL;
PFNGLFRAGMENTLIGHTFVEXTPROC glewFragmentLightfvEXT = NULL;
PFNGLFRAGMENTLIGHTIEXTPROC glewFragmentLightiEXT = NULL;
PFNGLFRAGMENTLIGHTIVEXTPROC glewFragmentLightivEXT = NULL;
PFNGLFRAGMENTMATERIALFEXTPROC glewFragmentMaterialfEXT = NULL;
PFNGLFRAGMENTMATERIALFVEXTPROC glewFragmentMaterialfvEXT = NULL;
PFNGLFRAGMENTMATERIALIEXTPROC glewFragmentMaterialiEXT = NULL;
PFNGLFRAGMENTMATERIALIVEXTPROC glewFragmentMaterialivEXT = NULL;
PFNGLGETFRAGMENTLIGHTFVEXTPROC glewGetFragmentLightfvEXT = NULL;
PFNGLGETFRAGMENTLIGHTIVEXTPROC glewGetFragmentLightivEXT = NULL;
PFNGLGETFRAGMENTMATERIALFVEXTPROC glewGetFragmentMaterialfvEXT = NULL;
PFNGLGETFRAGMENTMATERIALIVEXTPROC glewGetFragmentMaterialivEXT = NULL;
PFNGLLIGHTENVIEXTPROC glewLightEnviEXT = NULL;

static GLboolean _glewInit_GL_EXT_fragment_lighting (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewFragmentColorMaterialEXT = (PFNGLFRAGMENTCOLORMATERIALEXTPROC)glewGetProcAddress("glFragmentColorMaterialEXT")) == NULL) || r;
  r = ((glewFragmentLightModelfEXT = (PFNGLFRAGMENTLIGHTMODELFEXTPROC)glewGetProcAddress("glFragmentLightModelfEXT")) == NULL) || r;
  r = ((glewFragmentLightModelfvEXT = (PFNGLFRAGMENTLIGHTMODELFVEXTPROC)glewGetProcAddress("glFragmentLightModelfvEXT")) == NULL) || r;
  r = ((glewFragmentLightModeliEXT = (PFNGLFRAGMENTLIGHTMODELIEXTPROC)glewGetProcAddress("glFragmentLightModeliEXT")) == NULL) || r;
  r = ((glewFragmentLightModelivEXT = (PFNGLFRAGMENTLIGHTMODELIVEXTPROC)glewGetProcAddress("glFragmentLightModelivEXT")) == NULL) || r;
  r = ((glewFragmentLightfEXT = (PFNGLFRAGMENTLIGHTFEXTPROC)glewGetProcAddress("glFragmentLightfEXT")) == NULL) || r;
  r = ((glewFragmentLightfvEXT = (PFNGLFRAGMENTLIGHTFVEXTPROC)glewGetProcAddress("glFragmentLightfvEXT")) == NULL) || r;
  r = ((glewFragmentLightiEXT = (PFNGLFRAGMENTLIGHTIEXTPROC)glewGetProcAddress("glFragmentLightiEXT")) == NULL) || r;
  r = ((glewFragmentLightivEXT = (PFNGLFRAGMENTLIGHTIVEXTPROC)glewGetProcAddress("glFragmentLightivEXT")) == NULL) || r;
  r = ((glewFragmentMaterialfEXT = (PFNGLFRAGMENTMATERIALFEXTPROC)glewGetProcAddress("glFragmentMaterialfEXT")) == NULL) || r;
  r = ((glewFragmentMaterialfvEXT = (PFNGLFRAGMENTMATERIALFVEXTPROC)glewGetProcAddress("glFragmentMaterialfvEXT")) == NULL) || r;
  r = ((glewFragmentMaterialiEXT = (PFNGLFRAGMENTMATERIALIEXTPROC)glewGetProcAddress("glFragmentMaterialiEXT")) == NULL) || r;
  r = ((glewFragmentMaterialivEXT = (PFNGLFRAGMENTMATERIALIVEXTPROC)glewGetProcAddress("glFragmentMaterialivEXT")) == NULL) || r;
  r = ((glewGetFragmentLightfvEXT = (PFNGLGETFRAGMENTLIGHTFVEXTPROC)glewGetProcAddress("glGetFragmentLightfvEXT")) == NULL) || r;
  r = ((glewGetFragmentLightivEXT = (PFNGLGETFRAGMENTLIGHTIVEXTPROC)glewGetProcAddress("glGetFragmentLightivEXT")) == NULL) || r;
  r = ((glewGetFragmentMaterialfvEXT = (PFNGLGETFRAGMENTMATERIALFVEXTPROC)glewGetProcAddress("glGetFragmentMaterialfvEXT")) == NULL) || r;
  r = ((glewGetFragmentMaterialivEXT = (PFNGLGETFRAGMENTMATERIALIVEXTPROC)glewGetProcAddress("glGetFragmentMaterialivEXT")) == NULL) || r;
  r = ((glewLightEnviEXT = (PFNGLLIGHTENVIEXTPROC)glewGetProcAddress("glLightEnviEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_fragment_lighting = GL_FALSE;

#endif /* GL_EXT_fragment_lighting */

/* ---------------------------- GL_EXT_histogram --------------------------- */

#ifdef GL_EXT_histogram

PFNGLGETHISTOGRAMEXTPROC glewGetHistogramEXT = NULL;
PFNGLGETHISTOGRAMPARAMETERFVEXTPROC glewGetHistogramParameterfvEXT = NULL;
PFNGLGETHISTOGRAMPARAMETERIVEXTPROC glewGetHistogramParameterivEXT = NULL;
PFNGLGETMINMAXEXTPROC glewGetMinmaxEXT = NULL;
PFNGLGETMINMAXPARAMETERFVEXTPROC glewGetMinmaxParameterfvEXT = NULL;
PFNGLGETMINMAXPARAMETERIVEXTPROC glewGetMinmaxParameterivEXT = NULL;
PFNGLHISTOGRAMEXTPROC glewHistogramEXT = NULL;
PFNGLMINMAXEXTPROC glewMinmaxEXT = NULL;
PFNGLRESETHISTOGRAMEXTPROC glewResetHistogramEXT = NULL;
PFNGLRESETMINMAXEXTPROC glewResetMinmaxEXT = NULL;

static GLboolean _glewInit_GL_EXT_histogram (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewGetHistogramEXT = (PFNGLGETHISTOGRAMEXTPROC)glewGetProcAddress("glGetHistogramEXT")) == NULL) || r;
  r = ((glewGetHistogramParameterfvEXT = (PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)glewGetProcAddress("glGetHistogramParameterfvEXT")) == NULL) || r;
  r = ((glewGetHistogramParameterivEXT = (PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)glewGetProcAddress("glGetHistogramParameterivEXT")) == NULL) || r;
  r = ((glewGetMinmaxEXT = (PFNGLGETMINMAXEXTPROC)glewGetProcAddress("glGetMinmaxEXT")) == NULL) || r;
  r = ((glewGetMinmaxParameterfvEXT = (PFNGLGETMINMAXPARAMETERFVEXTPROC)glewGetProcAddress("glGetMinmaxParameterfvEXT")) == NULL) || r;
  r = ((glewGetMinmaxParameterivEXT = (PFNGLGETMINMAXPARAMETERIVEXTPROC)glewGetProcAddress("glGetMinmaxParameterivEXT")) == NULL) || r;
  r = ((glewHistogramEXT = (PFNGLHISTOGRAMEXTPROC)glewGetProcAddress("glHistogramEXT")) == NULL) || r;
  r = ((glewMinmaxEXT = (PFNGLMINMAXEXTPROC)glewGetProcAddress("glMinmaxEXT")) == NULL) || r;
  r = ((glewResetHistogramEXT = (PFNGLRESETHISTOGRAMEXTPROC)glewGetProcAddress("glResetHistogramEXT")) == NULL) || r;
  r = ((glewResetMinmaxEXT = (PFNGLRESETMINMAXEXTPROC)glewGetProcAddress("glResetMinmaxEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_histogram = GL_FALSE;

#endif /* GL_EXT_histogram */

/* ----------------------- GL_EXT_index_array_formats ---------------------- */

#ifdef GL_EXT_index_array_formats

GLboolean GLEW_EXT_index_array_formats = GL_FALSE;

#endif /* GL_EXT_index_array_formats */

/* --------------------------- GL_EXT_index_func --------------------------- */

#ifdef GL_EXT_index_func

PFNGLINDEXFUNCEXTPROC glewIndexFuncEXT = NULL;

static GLboolean _glewInit_GL_EXT_index_func (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewIndexFuncEXT = (PFNGLINDEXFUNCEXTPROC)glewGetProcAddress("glIndexFuncEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_index_func = GL_FALSE;

#endif /* GL_EXT_index_func */

/* ------------------------- GL_EXT_index_material ------------------------- */

#ifdef GL_EXT_index_material

PFNGLINDEXMATERIALEXTPROC glewIndexMaterialEXT = NULL;

static GLboolean _glewInit_GL_EXT_index_material (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewIndexMaterialEXT = (PFNGLINDEXMATERIALEXTPROC)glewGetProcAddress("glIndexMaterialEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_index_material = GL_FALSE;

#endif /* GL_EXT_index_material */

/* -------------------------- GL_EXT_index_texture ------------------------- */

#ifdef GL_EXT_index_texture

GLboolean GLEW_EXT_index_texture = GL_FALSE;

#endif /* GL_EXT_index_texture */

/* -------------------------- GL_EXT_light_texture ------------------------- */

#ifdef GL_EXT_light_texture

PFNGLAPPLYTEXTUREEXTPROC glewApplyTextureEXT = NULL;
PFNGLTEXTURELIGHTEXTPROC glewTextureLightEXT = NULL;
PFNGLTEXTUREMATERIALEXTPROC glewTextureMaterialEXT = NULL;

static GLboolean _glewInit_GL_EXT_light_texture (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewApplyTextureEXT = (PFNGLAPPLYTEXTUREEXTPROC)glewGetProcAddress("glApplyTextureEXT")) == NULL) || r;
  r = ((glewTextureLightEXT = (PFNGLTEXTURELIGHTEXTPROC)glewGetProcAddress("glTextureLightEXT")) == NULL) || r;
  r = ((glewTextureMaterialEXT = (PFNGLTEXTUREMATERIALEXTPROC)glewGetProcAddress("glTextureMaterialEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_light_texture = GL_FALSE;

#endif /* GL_EXT_light_texture */

/* ------------------------- GL_EXT_misc_attribute ------------------------- */

#ifdef GL_EXT_misc_attribute

GLboolean GLEW_EXT_misc_attribute = GL_FALSE;

#endif /* GL_EXT_misc_attribute */

/* ------------------------ GL_EXT_multi_draw_arrays ----------------------- */

#ifdef GL_EXT_multi_draw_arrays

PFNGLMULTIDRAWARRAYSEXTPROC glewMultiDrawArraysEXT = NULL;
PFNGLMULTIDRAWELEMENTSEXTPROC glewMultiDrawElementsEXT = NULL;

static GLboolean _glewInit_GL_EXT_multi_draw_arrays (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewMultiDrawArraysEXT = (PFNGLMULTIDRAWARRAYSEXTPROC)glewGetProcAddress("glMultiDrawArraysEXT")) == NULL) || r;
  r = ((glewMultiDrawElementsEXT = (PFNGLMULTIDRAWELEMENTSEXTPROC)glewGetProcAddress("glMultiDrawElementsEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_multi_draw_arrays = GL_FALSE;

#endif /* GL_EXT_multi_draw_arrays */

/* --------------------------- GL_EXT_multisample -------------------------- */

#ifdef GL_EXT_multisample

PFNGLSAMPLEMASKEXTPROC glewSampleMaskEXT = NULL;
PFNGLSAMPLEPATTERNEXTPROC glewSamplePatternEXT = NULL;

static GLboolean _glewInit_GL_EXT_multisample (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewSampleMaskEXT = (PFNGLSAMPLEMASKEXTPROC)glewGetProcAddress("glSampleMaskEXT")) == NULL) || r;
  r = ((glewSamplePatternEXT = (PFNGLSAMPLEPATTERNEXTPROC)glewGetProcAddress("glSamplePatternEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_multisample = GL_FALSE;

#endif /* GL_EXT_multisample */

/* -------------------------- GL_EXT_packed_pixels ------------------------- */

#ifdef GL_EXT_packed_pixels

GLboolean GLEW_EXT_packed_pixels = GL_FALSE;

#endif /* GL_EXT_packed_pixels */

/* ------------------------ GL_EXT_paletted_texture ------------------------ */

#ifdef GL_EXT_paletted_texture

PFNGLCOLORTABLEEXTPROC glewColorTableEXT = NULL;
PFNGLGETCOLORTABLEEXTPROC glewGetColorTableEXT = NULL;
PFNGLGETCOLORTABLEPARAMETERFVEXTPROC glewGetColorTableParameterfvEXT = NULL;
PFNGLGETCOLORTABLEPARAMETERIVEXTPROC glewGetColorTableParameterivEXT = NULL;

static GLboolean _glewInit_GL_EXT_paletted_texture (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewColorTableEXT = (PFNGLCOLORTABLEEXTPROC)glewGetProcAddress("glColorTableEXT")) == NULL) || r;
  r = ((glewGetColorTableEXT = (PFNGLGETCOLORTABLEEXTPROC)glewGetProcAddress("glGetColorTableEXT")) == NULL) || r;
  r = ((glewGetColorTableParameterfvEXT = (PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)glewGetProcAddress("glGetColorTableParameterfvEXT")) == NULL) || r;
  r = ((glewGetColorTableParameterivEXT = (PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)glewGetProcAddress("glGetColorTableParameterivEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_paletted_texture = GL_FALSE;

#endif /* GL_EXT_paletted_texture */

/* ------------------------- GL_EXT_pixel_transform ------------------------ */

#ifdef GL_EXT_pixel_transform

PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC glewGetPixelTransformParameterfvEXT = NULL;
PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC glewGetPixelTransformParameterivEXT = NULL;
PFNGLPIXELTRANSFORMPARAMETERFEXTPROC glewPixelTransformParameterfEXT = NULL;
PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC glewPixelTransformParameterfvEXT = NULL;
PFNGLPIXELTRANSFORMPARAMETERIEXTPROC glewPixelTransformParameteriEXT = NULL;
PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC glewPixelTransformParameterivEXT = NULL;

static GLboolean _glewInit_GL_EXT_pixel_transform (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewGetPixelTransformParameterfvEXT = (PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC)glewGetProcAddress("glGetPixelTransformParameterfvEXT")) == NULL) || r;
  r = ((glewGetPixelTransformParameterivEXT = (PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC)glewGetProcAddress("glGetPixelTransformParameterivEXT")) == NULL) || r;
  r = ((glewPixelTransformParameterfEXT = (PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)glewGetProcAddress("glPixelTransformParameterfEXT")) == NULL) || r;
  r = ((glewPixelTransformParameterfvEXT = (PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)glewGetProcAddress("glPixelTransformParameterfvEXT")) == NULL) || r;
  r = ((glewPixelTransformParameteriEXT = (PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)glewGetProcAddress("glPixelTransformParameteriEXT")) == NULL) || r;
  r = ((glewPixelTransformParameterivEXT = (PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)glewGetProcAddress("glPixelTransformParameterivEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_pixel_transform = GL_FALSE;

#endif /* GL_EXT_pixel_transform */

/* ------------------- GL_EXT_pixel_transform_color_table ------------------ */

#ifdef GL_EXT_pixel_transform_color_table

GLboolean GLEW_EXT_pixel_transform_color_table = GL_FALSE;

#endif /* GL_EXT_pixel_transform_color_table */

/* ------------------------ GL_EXT_point_parameters ------------------------ */

#ifdef GL_EXT_point_parameters

PFNGLPOINTPARAMETERFEXTPROC glewPointParameterfEXT = NULL;
PFNGLPOINTPARAMETERFVEXTPROC glewPointParameterfvEXT = NULL;

static GLboolean _glewInit_GL_EXT_point_parameters (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewPointParameterfEXT = (PFNGLPOINTPARAMETERFEXTPROC)glewGetProcAddress("glPointParameterfEXT")) == NULL) || r;
  r = ((glewPointParameterfvEXT = (PFNGLPOINTPARAMETERFVEXTPROC)glewGetProcAddress("glPointParameterfvEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_point_parameters = GL_FALSE;

#endif /* GL_EXT_point_parameters */

/* ------------------------- GL_EXT_polygon_offset ------------------------- */

#ifdef GL_EXT_polygon_offset

PFNGLPOLYGONOFFSETEXTPROC glewPolygonOffsetEXT = NULL;

static GLboolean _glewInit_GL_EXT_polygon_offset (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewPolygonOffsetEXT = (PFNGLPOLYGONOFFSETEXTPROC)glewGetProcAddress("glPolygonOffsetEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_polygon_offset = GL_FALSE;

#endif /* GL_EXT_polygon_offset */

/* ------------------------- GL_EXT_rescale_normal ------------------------- */

#ifdef GL_EXT_rescale_normal

GLboolean GLEW_EXT_rescale_normal = GL_FALSE;

#endif /* GL_EXT_rescale_normal */

/* -------------------------- GL_EXT_scene_marker -------------------------- */

#ifdef GL_EXT_scene_marker

PFNGLBEGINSCENEEXTPROC glewBeginSceneEXT = NULL;
PFNGLENDSCENEEXTPROC glewEndSceneEXT = NULL;

static GLboolean _glewInit_GL_EXT_scene_marker (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBeginSceneEXT = (PFNGLBEGINSCENEEXTPROC)glewGetProcAddress("glBeginSceneEXT")) == NULL) || r;
  r = ((glewEndSceneEXT = (PFNGLENDSCENEEXTPROC)glewGetProcAddress("glEndSceneEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_scene_marker = GL_FALSE;

#endif /* GL_EXT_scene_marker */

/* ------------------------- GL_EXT_secondary_color ------------------------ */

#ifdef GL_EXT_secondary_color

PFNGLSECONDARYCOLOR3BEXTPROC glewSecondaryColor3bEXT = NULL;
PFNGLSECONDARYCOLOR3BVEXTPROC glewSecondaryColor3bvEXT = NULL;
PFNGLSECONDARYCOLOR3DEXTPROC glewSecondaryColor3dEXT = NULL;
PFNGLSECONDARYCOLOR3DVEXTPROC glewSecondaryColor3dvEXT = NULL;
PFNGLSECONDARYCOLOR3FEXTPROC glewSecondaryColor3fEXT = NULL;
PFNGLSECONDARYCOLOR3FVEXTPROC glewSecondaryColor3fvEXT = NULL;
PFNGLSECONDARYCOLOR3IEXTPROC glewSecondaryColor3iEXT = NULL;
PFNGLSECONDARYCOLOR3IVEXTPROC glewSecondaryColor3ivEXT = NULL;
PFNGLSECONDARYCOLOR3SEXTPROC glewSecondaryColor3sEXT = NULL;
PFNGLSECONDARYCOLOR3SVEXTPROC glewSecondaryColor3svEXT = NULL;
PFNGLSECONDARYCOLOR3UBEXTPROC glewSecondaryColor3ubEXT = NULL;
PFNGLSECONDARYCOLOR3UBVEXTPROC glewSecondaryColor3ubvEXT = NULL;
PFNGLSECONDARYCOLOR3UIEXTPROC glewSecondaryColor3uiEXT = NULL;
PFNGLSECONDARYCOLOR3UIVEXTPROC glewSecondaryColor3uivEXT = NULL;
PFNGLSECONDARYCOLOR3USEXTPROC glewSecondaryColor3usEXT = NULL;
PFNGLSECONDARYCOLOR3USVEXTPROC glewSecondaryColor3usvEXT = NULL;
PFNGLSECONDARYCOLORPOINTEREXTPROC glewSecondaryColorPointerEXT = NULL;

static GLboolean _glewInit_GL_EXT_secondary_color (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewSecondaryColor3bEXT = (PFNGLSECONDARYCOLOR3BEXTPROC)glewGetProcAddress("glSecondaryColor3bEXT")) == NULL) || r;
  r = ((glewSecondaryColor3bvEXT = (PFNGLSECONDARYCOLOR3BVEXTPROC)glewGetProcAddress("glSecondaryColor3bvEXT")) == NULL) || r;
  r = ((glewSecondaryColor3dEXT = (PFNGLSECONDARYCOLOR3DEXTPROC)glewGetProcAddress("glSecondaryColor3dEXT")) == NULL) || r;
  r = ((glewSecondaryColor3dvEXT = (PFNGLSECONDARYCOLOR3DVEXTPROC)glewGetProcAddress("glSecondaryColor3dvEXT")) == NULL) || r;
  r = ((glewSecondaryColor3fEXT = (PFNGLSECONDARYCOLOR3FEXTPROC)glewGetProcAddress("glSecondaryColor3fEXT")) == NULL) || r;
  r = ((glewSecondaryColor3fvEXT = (PFNGLSECONDARYCOLOR3FVEXTPROC)glewGetProcAddress("glSecondaryColor3fvEXT")) == NULL) || r;
  r = ((glewSecondaryColor3iEXT = (PFNGLSECONDARYCOLOR3IEXTPROC)glewGetProcAddress("glSecondaryColor3iEXT")) == NULL) || r;
  r = ((glewSecondaryColor3ivEXT = (PFNGLSECONDARYCOLOR3IVEXTPROC)glewGetProcAddress("glSecondaryColor3ivEXT")) == NULL) || r;
  r = ((glewSecondaryColor3sEXT = (PFNGLSECONDARYCOLOR3SEXTPROC)glewGetProcAddress("glSecondaryColor3sEXT")) == NULL) || r;
  r = ((glewSecondaryColor3svEXT = (PFNGLSECONDARYCOLOR3SVEXTPROC)glewGetProcAddress("glSecondaryColor3svEXT")) == NULL) || r;
  r = ((glewSecondaryColor3ubEXT = (PFNGLSECONDARYCOLOR3UBEXTPROC)glewGetProcAddress("glSecondaryColor3ubEXT")) == NULL) || r;
  r = ((glewSecondaryColor3ubvEXT = (PFNGLSECONDARYCOLOR3UBVEXTPROC)glewGetProcAddress("glSecondaryColor3ubvEXT")) == NULL) || r;
  r = ((glewSecondaryColor3uiEXT = (PFNGLSECONDARYCOLOR3UIEXTPROC)glewGetProcAddress("glSecondaryColor3uiEXT")) == NULL) || r;
  r = ((glewSecondaryColor3uivEXT = (PFNGLSECONDARYCOLOR3UIVEXTPROC)glewGetProcAddress("glSecondaryColor3uivEXT")) == NULL) || r;
  r = ((glewSecondaryColor3usEXT = (PFNGLSECONDARYCOLOR3USEXTPROC)glewGetProcAddress("glSecondaryColor3usEXT")) == NULL) || r;
  r = ((glewSecondaryColor3usvEXT = (PFNGLSECONDARYCOLOR3USVEXTPROC)glewGetProcAddress("glSecondaryColor3usvEXT")) == NULL) || r;
  r = ((glewSecondaryColorPointerEXT = (PFNGLSECONDARYCOLORPOINTEREXTPROC)glewGetProcAddress("glSecondaryColorPointerEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_secondary_color = GL_FALSE;

#endif /* GL_EXT_secondary_color */

/* --------------------- GL_EXT_separate_specular_color -------------------- */

#ifdef GL_EXT_separate_specular_color

GLboolean GLEW_EXT_separate_specular_color = GL_FALSE;

#endif /* GL_EXT_separate_specular_color */

/* -------------------------- GL_EXT_shadow_funcs -------------------------- */

#ifdef GL_EXT_shadow_funcs

GLboolean GLEW_EXT_shadow_funcs = GL_FALSE;

#endif /* GL_EXT_shadow_funcs */

/* --------------------- GL_EXT_shared_texture_palette --------------------- */

#ifdef GL_EXT_shared_texture_palette

GLboolean GLEW_EXT_shared_texture_palette = GL_FALSE;

#endif /* GL_EXT_shared_texture_palette */

/* ------------------------ GL_EXT_stencil_two_side ------------------------ */

#ifdef GL_EXT_stencil_two_side

PFNGLACTIVESTENCILFACEEXTPROC glewActiveStencilFaceEXT = NULL;

static GLboolean _glewInit_GL_EXT_stencil_two_side (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewActiveStencilFaceEXT = (PFNGLACTIVESTENCILFACEEXTPROC)glewGetProcAddress("glActiveStencilFaceEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_stencil_two_side = GL_FALSE;

#endif /* GL_EXT_stencil_two_side */

/* -------------------------- GL_EXT_stencil_wrap -------------------------- */

#ifdef GL_EXT_stencil_wrap

GLboolean GLEW_EXT_stencil_wrap = GL_FALSE;

#endif /* GL_EXT_stencil_wrap */

/* --------------------------- GL_EXT_subtexture --------------------------- */

#ifdef GL_EXT_subtexture

PFNGLTEXSUBIMAGE1DEXTPROC glewTexSubImage1DEXT = NULL;
PFNGLTEXSUBIMAGE2DEXTPROC glewTexSubImage2DEXT = NULL;
PFNGLTEXSUBIMAGE3DEXTPROC glewTexSubImage3DEXT = NULL;

static GLboolean _glewInit_GL_EXT_subtexture (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewTexSubImage1DEXT = (PFNGLTEXSUBIMAGE1DEXTPROC)glewGetProcAddress("glTexSubImage1DEXT")) == NULL) || r;
  r = ((glewTexSubImage2DEXT = (PFNGLTEXSUBIMAGE2DEXTPROC)glewGetProcAddress("glTexSubImage2DEXT")) == NULL) || r;
  r = ((glewTexSubImage3DEXT = (PFNGLTEXSUBIMAGE3DEXTPROC)glewGetProcAddress("glTexSubImage3DEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_subtexture = GL_FALSE;

#endif /* GL_EXT_subtexture */

/* ----------------------------- GL_EXT_texture ---------------------------- */

#ifdef GL_EXT_texture

GLboolean GLEW_EXT_texture = GL_FALSE;

#endif /* GL_EXT_texture */

/* ---------------------------- GL_EXT_texture3D --------------------------- */

#ifdef GL_EXT_texture3D

PFNGLTEXIMAGE3DEXTPROC glewTexImage3DEXT = NULL;

static GLboolean _glewInit_GL_EXT_texture3D (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewTexImage3DEXT = (PFNGLTEXIMAGE3DEXTPROC)glewGetProcAddress("glTexImage3DEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_texture3D = GL_FALSE;

#endif /* GL_EXT_texture3D */

/* -------------------- GL_EXT_texture_compression_s3tc -------------------- */

#ifdef GL_EXT_texture_compression_s3tc

GLboolean GLEW_EXT_texture_compression_s3tc = GL_FALSE;

#endif /* GL_EXT_texture_compression_s3tc */

/* --------------------------- GL_EXT_texture_env -------------------------- */

#ifdef GL_EXT_texture_env

GLboolean GLEW_EXT_texture_env = GL_FALSE;

#endif /* GL_EXT_texture_env */

/* ------------------------- GL_EXT_texture_env_add ------------------------ */

#ifdef GL_EXT_texture_env_add

GLboolean GLEW_EXT_texture_env_add = GL_FALSE;

#endif /* GL_EXT_texture_env_add */

/* ----------------------- GL_EXT_texture_env_combine ---------------------- */

#ifdef GL_EXT_texture_env_combine

GLboolean GLEW_EXT_texture_env_combine = GL_FALSE;

#endif /* GL_EXT_texture_env_combine */

/* ------------------------ GL_EXT_texture_env_dot3 ------------------------ */

#ifdef GL_EXT_texture_env_dot3

GLboolean GLEW_EXT_texture_env_dot3 = GL_FALSE;

#endif /* GL_EXT_texture_env_dot3 */

/* ------------------- GL_EXT_texture_filter_anisotropic ------------------- */

#ifdef GL_EXT_texture_filter_anisotropic

GLboolean GLEW_EXT_texture_filter_anisotropic = GL_FALSE;

#endif /* GL_EXT_texture_filter_anisotropic */

/* ------------------------ GL_EXT_texture_lod_bias ------------------------ */

#ifdef GL_EXT_texture_lod_bias

GLboolean GLEW_EXT_texture_lod_bias = GL_FALSE;

#endif /* GL_EXT_texture_lod_bias */

/* ---------------------- GL_EXT_texture_mirror_clamp ---------------------- */

#ifdef GL_EXT_texture_mirror_clamp

GLboolean GLEW_EXT_texture_mirror_clamp = GL_FALSE;

#endif /* GL_EXT_texture_mirror_clamp */

/* ------------------------- GL_EXT_texture_object ------------------------- */

#ifdef GL_EXT_texture_object

PFNGLARETEXTURESRESIDENTEXTPROC glewAreTexturesResidentEXT = NULL;
PFNGLBINDTEXTUREEXTPROC glewBindTextureEXT = NULL;
PFNGLDELETETEXTURESEXTPROC glewDeleteTexturesEXT = NULL;
PFNGLGENTEXTURESEXTPROC glewGenTexturesEXT = NULL;
PFNGLISTEXTUREEXTPROC glewIsTextureEXT = NULL;
PFNGLPRIORITIZETEXTURESEXTPROC glewPrioritizeTexturesEXT = NULL;

static GLboolean _glewInit_GL_EXT_texture_object (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewAreTexturesResidentEXT = (PFNGLARETEXTURESRESIDENTEXTPROC)glewGetProcAddress("glAreTexturesResidentEXT")) == NULL) || r;
  r = ((glewBindTextureEXT = (PFNGLBINDTEXTUREEXTPROC)glewGetProcAddress("glBindTextureEXT")) == NULL) || r;
  r = ((glewDeleteTexturesEXT = (PFNGLDELETETEXTURESEXTPROC)glewGetProcAddress("glDeleteTexturesEXT")) == NULL) || r;
  r = ((glewGenTexturesEXT = (PFNGLGENTEXTURESEXTPROC)glewGetProcAddress("glGenTexturesEXT")) == NULL) || r;
  r = ((glewIsTextureEXT = (PFNGLISTEXTUREEXTPROC)glewGetProcAddress("glIsTextureEXT")) == NULL) || r;
  r = ((glewPrioritizeTexturesEXT = (PFNGLPRIORITIZETEXTURESEXTPROC)glewGetProcAddress("glPrioritizeTexturesEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_texture_object = GL_FALSE;

#endif /* GL_EXT_texture_object */

/* --------------------- GL_EXT_texture_perturb_normal --------------------- */

#ifdef GL_EXT_texture_perturb_normal

PFNGLTEXTURENORMALEXTPROC glewTextureNormalEXT = NULL;

static GLboolean _glewInit_GL_EXT_texture_perturb_normal (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewTextureNormalEXT = (PFNGLTEXTURENORMALEXTPROC)glewGetProcAddress("glTextureNormalEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_texture_perturb_normal = GL_FALSE;

#endif /* GL_EXT_texture_perturb_normal */

/* ------------------------ GL_EXT_texture_rectangle ----------------------- */

#ifdef GL_EXT_texture_rectangle

GLboolean GLEW_EXT_texture_rectangle = GL_FALSE;

#endif /* GL_EXT_texture_rectangle */

/* -------------------------- GL_EXT_vertex_array -------------------------- */

#ifdef GL_EXT_vertex_array

PFNGLARRAYELEMENTEXTPROC glewArrayElementEXT = NULL;
PFNGLCOLORPOINTEREXTPROC glewColorPointerEXT = NULL;
PFNGLDRAWARRAYSEXTPROC glewDrawArraysEXT = NULL;
PFNGLEDGEFLAGPOINTEREXTPROC glewEdgeFlagPointerEXT = NULL;
PFNGLGETPOINTERVEXTPROC glewGetPointervEXT = NULL;
PFNGLINDEXPOINTEREXTPROC glewIndexPointerEXT = NULL;
PFNGLNORMALPOINTEREXTPROC glewNormalPointerEXT = NULL;
PFNGLTEXCOORDPOINTEREXTPROC glewTexCoordPointerEXT = NULL;
PFNGLVERTEXPOINTEREXTPROC glewVertexPointerEXT = NULL;

static GLboolean _glewInit_GL_EXT_vertex_array (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewArrayElementEXT = (PFNGLARRAYELEMENTEXTPROC)glewGetProcAddress("glArrayElementEXT")) == NULL) || r;
  r = ((glewColorPointerEXT = (PFNGLCOLORPOINTEREXTPROC)glewGetProcAddress("glColorPointerEXT")) == NULL) || r;
  r = ((glewDrawArraysEXT = (PFNGLDRAWARRAYSEXTPROC)glewGetProcAddress("glDrawArraysEXT")) == NULL) || r;
  r = ((glewEdgeFlagPointerEXT = (PFNGLEDGEFLAGPOINTEREXTPROC)glewGetProcAddress("glEdgeFlagPointerEXT")) == NULL) || r;
  r = ((glewGetPointervEXT = (PFNGLGETPOINTERVEXTPROC)glewGetProcAddress("glGetPointervEXT")) == NULL) || r;
  r = ((glewIndexPointerEXT = (PFNGLINDEXPOINTEREXTPROC)glewGetProcAddress("glIndexPointerEXT")) == NULL) || r;
  r = ((glewNormalPointerEXT = (PFNGLNORMALPOINTEREXTPROC)glewGetProcAddress("glNormalPointerEXT")) == NULL) || r;
  r = ((glewTexCoordPointerEXT = (PFNGLTEXCOORDPOINTEREXTPROC)glewGetProcAddress("glTexCoordPointerEXT")) == NULL) || r;
  r = ((glewVertexPointerEXT = (PFNGLVERTEXPOINTEREXTPROC)glewGetProcAddress("glVertexPointerEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_vertex_array = GL_FALSE;

#endif /* GL_EXT_vertex_array */

/* -------------------------- GL_EXT_vertex_shader ------------------------- */

#ifdef GL_EXT_vertex_shader

PFNGLBEGINVERTEXSHADEREXTPROC glewBeginVertexShaderEXT = NULL;
PFNGLBINDLIGHTPARAMETEREXTPROC glewBindLightParameterEXT = NULL;
PFNGLBINDMATERIALPARAMETEREXTPROC glewBindMaterialParameterEXT = NULL;
PFNGLBINDPARAMETEREXTPROC glewBindParameterEXT = NULL;
PFNGLBINDTEXGENPARAMETEREXTPROC glewBindTexGenParameterEXT = NULL;
PFNGLBINDTEXTUREUNITPARAMETEREXTPROC glewBindTextureUnitParameterEXT = NULL;
PFNGLBINDVERTEXSHADEREXTPROC glewBindVertexShaderEXT = NULL;
PFNGLDELETEVERTEXSHADEREXTPROC glewDeleteVertexShaderEXT = NULL;
PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC glewDisableVariantClientStateEXT = NULL;
PFNGLENABLEVARIANTCLIENTSTATEEXTPROC glewEnableVariantClientStateEXT = NULL;
PFNGLENDVERTEXSHADEREXTPROC glewEndVertexShaderEXT = NULL;
PFNGLEXTRACTCOMPONENTEXTPROC glewExtractComponentEXT = NULL;
PFNGLGENSYMBOLSEXTPROC glewGenSymbolsEXT = NULL;
PFNGLGENVERTEXSHADERSEXTPROC glewGenVertexShadersEXT = NULL;
PFNGLGETINVARIANTBOOLEANVEXTPROC glewGetInvariantBooleanvEXT = NULL;
PFNGLGETINVARIANTFLOATVEXTPROC glewGetInvariantFloatvEXT = NULL;
PFNGLGETINVARIANTINTEGERVEXTPROC glewGetInvariantIntegervEXT = NULL;
PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC glewGetLocalConstantBooleanvEXT = NULL;
PFNGLGETLOCALCONSTANTFLOATVEXTPROC glewGetLocalConstantFloatvEXT = NULL;
PFNGLGETLOCALCONSTANTINTEGERVEXTPROC glewGetLocalConstantIntegervEXT = NULL;
PFNGLGETVARIANTBOOLEANVEXTPROC glewGetVariantBooleanvEXT = NULL;
PFNGLGETVARIANTFLOATVEXTPROC glewGetVariantFloatvEXT = NULL;
PFNGLGETVARIANTINTEGERVEXTPROC glewGetVariantIntegervEXT = NULL;
PFNGLGETVARIANTPOINTERVEXTPROC glewGetVariantPointervEXT = NULL;
PFNGLINSERTCOMPONENTEXTPROC glewInsertComponentEXT = NULL;
PFNGLISVARIANTENABLEDEXTPROC glewIsVariantEnabledEXT = NULL;
PFNGLSETINVARIANTEXTPROC glewSetInvariantEXT = NULL;
PFNGLSETLOCALCONSTANTEXTPROC glewSetLocalConstantEXT = NULL;
PFNGLSHADEROP1EXTPROC glewShaderOp1EXT = NULL;
PFNGLSHADEROP2EXTPROC glewShaderOp2EXT = NULL;
PFNGLSHADEROP3EXTPROC glewShaderOp3EXT = NULL;
PFNGLSWIZZLEEXTPROC glewSwizzleEXT = NULL;
PFNGLVARIANTPOINTEREXTPROC glewVariantPointerEXT = NULL;
PFNGLVARIANTBVEXTPROC glewVariantbvEXT = NULL;
PFNGLVARIANTDVEXTPROC glewVariantdvEXT = NULL;
PFNGLVARIANTFVEXTPROC glewVariantfvEXT = NULL;
PFNGLVARIANTIVEXTPROC glewVariantivEXT = NULL;
PFNGLVARIANTSVEXTPROC glewVariantsvEXT = NULL;
PFNGLVARIANTUBVEXTPROC glewVariantubvEXT = NULL;
PFNGLVARIANTUIVEXTPROC glewVariantuivEXT = NULL;
PFNGLVARIANTUSVEXTPROC glewVariantusvEXT = NULL;
PFNGLWRITEMASKEXTPROC glewWriteMaskEXT = NULL;

static GLboolean _glewInit_GL_EXT_vertex_shader (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBeginVertexShaderEXT = (PFNGLBEGINVERTEXSHADEREXTPROC)glewGetProcAddress("glBeginVertexShaderEXT")) == NULL) || r;
  r = ((glewBindLightParameterEXT = (PFNGLBINDLIGHTPARAMETEREXTPROC)glewGetProcAddress("glBindLightParameterEXT")) == NULL) || r;
  r = ((glewBindMaterialParameterEXT = (PFNGLBINDMATERIALPARAMETEREXTPROC)glewGetProcAddress("glBindMaterialParameterEXT")) == NULL) || r;
  r = ((glewBindParameterEXT = (PFNGLBINDPARAMETEREXTPROC)glewGetProcAddress("glBindParameterEXT")) == NULL) || r;
  r = ((glewBindTexGenParameterEXT = (PFNGLBINDTEXGENPARAMETEREXTPROC)glewGetProcAddress("glBindTexGenParameterEXT")) == NULL) || r;
  r = ((glewBindTextureUnitParameterEXT = (PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)glewGetProcAddress("glBindTextureUnitParameterEXT")) == NULL) || r;
  r = ((glewBindVertexShaderEXT = (PFNGLBINDVERTEXSHADEREXTPROC)glewGetProcAddress("glBindVertexShaderEXT")) == NULL) || r;
  r = ((glewDeleteVertexShaderEXT = (PFNGLDELETEVERTEXSHADEREXTPROC)glewGetProcAddress("glDeleteVertexShaderEXT")) == NULL) || r;
  r = ((glewDisableVariantClientStateEXT = (PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)glewGetProcAddress("glDisableVariantClientStateEXT")) == NULL) || r;
  r = ((glewEnableVariantClientStateEXT = (PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)glewGetProcAddress("glEnableVariantClientStateEXT")) == NULL) || r;
  r = ((glewEndVertexShaderEXT = (PFNGLENDVERTEXSHADEREXTPROC)glewGetProcAddress("glEndVertexShaderEXT")) == NULL) || r;
  r = ((glewExtractComponentEXT = (PFNGLEXTRACTCOMPONENTEXTPROC)glewGetProcAddress("glExtractComponentEXT")) == NULL) || r;
  r = ((glewGenSymbolsEXT = (PFNGLGENSYMBOLSEXTPROC)glewGetProcAddress("glGenSymbolsEXT")) == NULL) || r;
  r = ((glewGenVertexShadersEXT = (PFNGLGENVERTEXSHADERSEXTPROC)glewGetProcAddress("glGenVertexShadersEXT")) == NULL) || r;
  r = ((glewGetInvariantBooleanvEXT = (PFNGLGETINVARIANTBOOLEANVEXTPROC)glewGetProcAddress("glGetInvariantBooleanvEXT")) == NULL) || r;
  r = ((glewGetInvariantFloatvEXT = (PFNGLGETINVARIANTFLOATVEXTPROC)glewGetProcAddress("glGetInvariantFloatvEXT")) == NULL) || r;
  r = ((glewGetInvariantIntegervEXT = (PFNGLGETINVARIANTINTEGERVEXTPROC)glewGetProcAddress("glGetInvariantIntegervEXT")) == NULL) || r;
  r = ((glewGetLocalConstantBooleanvEXT = (PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)glewGetProcAddress("glGetLocalConstantBooleanvEXT")) == NULL) || r;
  r = ((glewGetLocalConstantFloatvEXT = (PFNGLGETLOCALCONSTANTFLOATVEXTPROC)glewGetProcAddress("glGetLocalConstantFloatvEXT")) == NULL) || r;
  r = ((glewGetLocalConstantIntegervEXT = (PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)glewGetProcAddress("glGetLocalConstantIntegervEXT")) == NULL) || r;
  r = ((glewGetVariantBooleanvEXT = (PFNGLGETVARIANTBOOLEANVEXTPROC)glewGetProcAddress("glGetVariantBooleanvEXT")) == NULL) || r;
  r = ((glewGetVariantFloatvEXT = (PFNGLGETVARIANTFLOATVEXTPROC)glewGetProcAddress("glGetVariantFloatvEXT")) == NULL) || r;
  r = ((glewGetVariantIntegervEXT = (PFNGLGETVARIANTINTEGERVEXTPROC)glewGetProcAddress("glGetVariantIntegervEXT")) == NULL) || r;
  r = ((glewGetVariantPointervEXT = (PFNGLGETVARIANTPOINTERVEXTPROC)glewGetProcAddress("glGetVariantPointervEXT")) == NULL) || r;
  r = ((glewInsertComponentEXT = (PFNGLINSERTCOMPONENTEXTPROC)glewGetProcAddress("glInsertComponentEXT")) == NULL) || r;
  r = ((glewIsVariantEnabledEXT = (PFNGLISVARIANTENABLEDEXTPROC)glewGetProcAddress("glIsVariantEnabledEXT")) == NULL) || r;
  r = ((glewSetInvariantEXT = (PFNGLSETINVARIANTEXTPROC)glewGetProcAddress("glSetInvariantEXT")) == NULL) || r;
  r = ((glewSetLocalConstantEXT = (PFNGLSETLOCALCONSTANTEXTPROC)glewGetProcAddress("glSetLocalConstantEXT")) == NULL) || r;
  r = ((glewShaderOp1EXT = (PFNGLSHADEROP1EXTPROC)glewGetProcAddress("glShaderOp1EXT")) == NULL) || r;
  r = ((glewShaderOp2EXT = (PFNGLSHADEROP2EXTPROC)glewGetProcAddress("glShaderOp2EXT")) == NULL) || r;
  r = ((glewShaderOp3EXT = (PFNGLSHADEROP3EXTPROC)glewGetProcAddress("glShaderOp3EXT")) == NULL) || r;
  r = ((glewSwizzleEXT = (PFNGLSWIZZLEEXTPROC)glewGetProcAddress("glSwizzleEXT")) == NULL) || r;
  r = ((glewVariantPointerEXT = (PFNGLVARIANTPOINTEREXTPROC)glewGetProcAddress("glVariantPointerEXT")) == NULL) || r;
  r = ((glewVariantbvEXT = (PFNGLVARIANTBVEXTPROC)glewGetProcAddress("glVariantbvEXT")) == NULL) || r;
  r = ((glewVariantdvEXT = (PFNGLVARIANTDVEXTPROC)glewGetProcAddress("glVariantdvEXT")) == NULL) || r;
  r = ((glewVariantfvEXT = (PFNGLVARIANTFVEXTPROC)glewGetProcAddress("glVariantfvEXT")) == NULL) || r;
  r = ((glewVariantivEXT = (PFNGLVARIANTIVEXTPROC)glewGetProcAddress("glVariantivEXT")) == NULL) || r;
  r = ((glewVariantsvEXT = (PFNGLVARIANTSVEXTPROC)glewGetProcAddress("glVariantsvEXT")) == NULL) || r;
  r = ((glewVariantubvEXT = (PFNGLVARIANTUBVEXTPROC)glewGetProcAddress("glVariantubvEXT")) == NULL) || r;
  r = ((glewVariantuivEXT = (PFNGLVARIANTUIVEXTPROC)glewGetProcAddress("glVariantuivEXT")) == NULL) || r;
  r = ((glewVariantusvEXT = (PFNGLVARIANTUSVEXTPROC)glewGetProcAddress("glVariantusvEXT")) == NULL) || r;
  r = ((glewWriteMaskEXT = (PFNGLWRITEMASKEXTPROC)glewGetProcAddress("glWriteMaskEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_vertex_shader = GL_FALSE;

#endif /* GL_EXT_vertex_shader */

/* ------------------------ GL_EXT_vertex_weighting ------------------------ */

#ifdef GL_EXT_vertex_weighting

PFNGLVERTEXWEIGHTPOINTEREXTPROC glewVertexWeightPointerEXT = NULL;
PFNGLVERTEXWEIGHTFEXTPROC glewVertexWeightfEXT = NULL;
PFNGLVERTEXWEIGHTFVEXTPROC glewVertexWeightfvEXT = NULL;

static GLboolean _glewInit_GL_EXT_vertex_weighting (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewVertexWeightPointerEXT = (PFNGLVERTEXWEIGHTPOINTEREXTPROC)glewGetProcAddress("glVertexWeightPointerEXT")) == NULL) || r;
  r = ((glewVertexWeightfEXT = (PFNGLVERTEXWEIGHTFEXTPROC)glewGetProcAddress("glVertexWeightfEXT")) == NULL) || r;
  r = ((glewVertexWeightfvEXT = (PFNGLVERTEXWEIGHTFVEXTPROC)glewGetProcAddress("glVertexWeightfvEXT")) == NULL) || r;

  return r;
}

GLboolean GLEW_EXT_vertex_weighting = GL_FALSE;

#endif /* GL_EXT_vertex_weighting */

/* --------------------- GL_HP_convolution_border_modes -------------------- */

#ifdef GL_HP_convolution_border_modes

GLboolean GLEW_HP_convolution_border_modes = GL_FALSE;

#endif /* GL_HP_convolution_border_modes */

/* ------------------------- GL_HP_image_transform ------------------------- */

#ifdef GL_HP_image_transform

PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC glewGetImageTransformParameterfvHP = NULL;
PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC glewGetImageTransformParameterivHP = NULL;
PFNGLIMAGETRANSFORMPARAMETERFHPPROC glewImageTransformParameterfHP = NULL;
PFNGLIMAGETRANSFORMPARAMETERFVHPPROC glewImageTransformParameterfvHP = NULL;
PFNGLIMAGETRANSFORMPARAMETERIHPPROC glewImageTransformParameteriHP = NULL;
PFNGLIMAGETRANSFORMPARAMETERIVHPPROC glewImageTransformParameterivHP = NULL;

static GLboolean _glewInit_GL_HP_image_transform (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewGetImageTransformParameterfvHP = (PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)glewGetProcAddress("glGetImageTransformParameterfvHP")) == NULL) || r;
  r = ((glewGetImageTransformParameterivHP = (PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)glewGetProcAddress("glGetImageTransformParameterivHP")) == NULL) || r;
  r = ((glewImageTransformParameterfHP = (PFNGLIMAGETRANSFORMPARAMETERFHPPROC)glewGetProcAddress("glImageTransformParameterfHP")) == NULL) || r;
  r = ((glewImageTransformParameterfvHP = (PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)glewGetProcAddress("glImageTransformParameterfvHP")) == NULL) || r;
  r = ((glewImageTransformParameteriHP = (PFNGLIMAGETRANSFORMPARAMETERIHPPROC)glewGetProcAddress("glImageTransformParameteriHP")) == NULL) || r;
  r = ((glewImageTransformParameterivHP = (PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)glewGetProcAddress("glImageTransformParameterivHP")) == NULL) || r;

  return r;
}

GLboolean GLEW_HP_image_transform = GL_FALSE;

#endif /* GL_HP_image_transform */

/* -------------------------- GL_HP_occlusion_test ------------------------- */

#ifdef GL_HP_occlusion_test

GLboolean GLEW_HP_occlusion_test = GL_FALSE;

#endif /* GL_HP_occlusion_test */

/* ------------------------- GL_HP_texture_lighting ------------------------ */

#ifdef GL_HP_texture_lighting

GLboolean GLEW_HP_texture_lighting = GL_FALSE;

#endif /* GL_HP_texture_lighting */

/* --------------------------- GL_IBM_cull_vertex -------------------------- */

#ifdef GL_IBM_cull_vertex

GLboolean GLEW_IBM_cull_vertex = GL_FALSE;

#endif /* GL_IBM_cull_vertex */

/* ---------------------- GL_IBM_multimode_draw_arrays --------------------- */

#ifdef GL_IBM_multimode_draw_arrays

PFNGLMULTIMODEDRAWARRAYSIBMPROC glewMultiModeDrawArraysIBM = NULL;
PFNGLMULTIMODEDRAWELEMENTSIBMPROC glewMultiModeDrawElementsIBM = NULL;

static GLboolean _glewInit_GL_IBM_multimode_draw_arrays (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewMultiModeDrawArraysIBM = (PFNGLMULTIMODEDRAWARRAYSIBMPROC)glewGetProcAddress("glMultiModeDrawArraysIBM")) == NULL) || r;
  r = ((glewMultiModeDrawElementsIBM = (PFNGLMULTIMODEDRAWELEMENTSIBMPROC)glewGetProcAddress("glMultiModeDrawElementsIBM")) == NULL) || r;

  return r;
}

GLboolean GLEW_IBM_multimode_draw_arrays = GL_FALSE;

#endif /* GL_IBM_multimode_draw_arrays */

/* ------------------------- GL_IBM_rasterpos_clip ------------------------- */

#ifdef GL_IBM_rasterpos_clip

GLboolean GLEW_IBM_rasterpos_clip = GL_FALSE;

#endif /* GL_IBM_rasterpos_clip */

/* --------------------------- GL_IBM_static_data -------------------------- */

#ifdef GL_IBM_static_data

GLboolean GLEW_IBM_static_data = GL_FALSE;

#endif /* GL_IBM_static_data */

/* --------------------- GL_IBM_texture_mirrored_repeat -------------------- */

#ifdef GL_IBM_texture_mirrored_repeat

GLboolean GLEW_IBM_texture_mirrored_repeat = GL_FALSE;

#endif /* GL_IBM_texture_mirrored_repeat */

/* ----------------------- GL_IBM_vertex_array_lists ----------------------- */

#ifdef GL_IBM_vertex_array_lists

PFNGLCOLORPOINTERLISTIBMPROC glewColorPointerListIBM = NULL;
PFNGLEDGEFLAGPOINTERLISTIBMPROC glewEdgeFlagPointerListIBM = NULL;
PFNGLFOGCOORDPOINTERLISTIBMPROC glewFogCoordPointerListIBM = NULL;
PFNGLINDEXPOINTERLISTIBMPROC glewIndexPointerListIBM = NULL;
PFNGLNORMALPOINTERLISTIBMPROC glewNormalPointerListIBM = NULL;
PFNGLSECONDARYCOLORPOINTERLISTIBMPROC glewSecondaryColorPointerListIBM = NULL;
PFNGLTEXCOORDPOINTERLISTIBMPROC glewTexCoordPointerListIBM = NULL;
PFNGLVERTEXPOINTERLISTIBMPROC glewVertexPointerListIBM = NULL;

static GLboolean _glewInit_GL_IBM_vertex_array_lists (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewColorPointerListIBM = (PFNGLCOLORPOINTERLISTIBMPROC)glewGetProcAddress("glColorPointerListIBM")) == NULL) || r;
  r = ((glewEdgeFlagPointerListIBM = (PFNGLEDGEFLAGPOINTERLISTIBMPROC)glewGetProcAddress("glEdgeFlagPointerListIBM")) == NULL) || r;
  r = ((glewFogCoordPointerListIBM = (PFNGLFOGCOORDPOINTERLISTIBMPROC)glewGetProcAddress("glFogCoordPointerListIBM")) == NULL) || r;
  r = ((glewIndexPointerListIBM = (PFNGLINDEXPOINTERLISTIBMPROC)glewGetProcAddress("glIndexPointerListIBM")) == NULL) || r;
  r = ((glewNormalPointerListIBM = (PFNGLNORMALPOINTERLISTIBMPROC)glewGetProcAddress("glNormalPointerListIBM")) == NULL) || r;
  r = ((glewSecondaryColorPointerListIBM = (PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)glewGetProcAddress("glSecondaryColorPointerListIBM")) == NULL) || r;
  r = ((glewTexCoordPointerListIBM = (PFNGLTEXCOORDPOINTERLISTIBMPROC)glewGetProcAddress("glTexCoordPointerListIBM")) == NULL) || r;
  r = ((glewVertexPointerListIBM = (PFNGLVERTEXPOINTERLISTIBMPROC)glewGetProcAddress("glVertexPointerListIBM")) == NULL) || r;

  return r;
}

GLboolean GLEW_IBM_vertex_array_lists = GL_FALSE;

#endif /* GL_IBM_vertex_array_lists */

/* -------------------------- GL_INGR_color_clamp -------------------------- */

#ifdef GL_INGR_color_clamp

GLboolean GLEW_INGR_color_clamp = GL_FALSE;

#endif /* GL_INGR_color_clamp */

/* ------------------------- GL_INGR_interlace_read ------------------------ */

#ifdef GL_INGR_interlace_read

GLboolean GLEW_INGR_interlace_read = GL_FALSE;

#endif /* GL_INGR_interlace_read */

/* ------------------------ GL_INTEL_parallel_arrays ----------------------- */

#ifdef GL_INTEL_parallel_arrays

PFNGLCOLORPOINTERVINTELPROC glewColorPointervINTEL = NULL;
PFNGLNORMALPOINTERVINTELPROC glewNormalPointervINTEL = NULL;
PFNGLTEXCOORDPOINTERVINTELPROC glewTexCoordPointervINTEL = NULL;
PFNGLVERTEXPOINTERVINTELPROC glewVertexPointervINTEL = NULL;

static GLboolean _glewInit_GL_INTEL_parallel_arrays (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewColorPointervINTEL = (PFNGLCOLORPOINTERVINTELPROC)glewGetProcAddress("glColorPointervINTEL")) == NULL) || r;
  r = ((glewNormalPointervINTEL = (PFNGLNORMALPOINTERVINTELPROC)glewGetProcAddress("glNormalPointervINTEL")) == NULL) || r;
  r = ((glewTexCoordPointervINTEL = (PFNGLTEXCOORDPOINTERVINTELPROC)glewGetProcAddress("glTexCoordPointervINTEL")) == NULL) || r;
  r = ((glewVertexPointervINTEL = (PFNGLVERTEXPOINTERVINTELPROC)glewGetProcAddress("glVertexPointervINTEL")) == NULL) || r;

  return r;
}

GLboolean GLEW_INTEL_parallel_arrays = GL_FALSE;

#endif /* GL_INTEL_parallel_arrays */

/* ------------------------ GL_INTEL_texture_scissor ----------------------- */

#ifdef GL_INTEL_texture_scissor

PFNGLTEXSCISSORFUNCINTELPROC glewTexScissorFuncINTEL = NULL;
PFNGLTEXSCISSORINTELPROC glewTexScissorINTEL = NULL;

static GLboolean _glewInit_GL_INTEL_texture_scissor (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewTexScissorFuncINTEL = (PFNGLTEXSCISSORFUNCINTELPROC)glewGetProcAddress("glTexScissorFuncINTEL")) == NULL) || r;
  r = ((glewTexScissorINTEL = (PFNGLTEXSCISSORINTELPROC)glewGetProcAddress("glTexScissorINTEL")) == NULL) || r;

  return r;
}

GLboolean GLEW_INTEL_texture_scissor = GL_FALSE;

#endif /* GL_INTEL_texture_scissor */

/* ------------------------- GL_MESA_resize_buffers ------------------------ */

#ifdef GL_MESA_resize_buffers

PFNGLRESIZEBUFFERSMESAPROC glewResizeBuffersMESA = NULL;

static GLboolean _glewInit_GL_MESA_resize_buffers (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewResizeBuffersMESA = (PFNGLRESIZEBUFFERSMESAPROC)glewGetProcAddress("glResizeBuffersMESA")) == NULL) || r;

  return r;
}

GLboolean GLEW_MESA_resize_buffers = GL_FALSE;

#endif /* GL_MESA_resize_buffers */

/* --------------------------- GL_MESA_window_pos -------------------------- */

#ifdef GL_MESA_window_pos

PFNGLWINDOWPOS2DMESAPROC glewWindowPos2dMESA = NULL;
PFNGLWINDOWPOS2DVMESAPROC glewWindowPos2dvMESA = NULL;
PFNGLWINDOWPOS2FMESAPROC glewWindowPos2fMESA = NULL;
PFNGLWINDOWPOS2FVMESAPROC glewWindowPos2fvMESA = NULL;
PFNGLWINDOWPOS2IMESAPROC glewWindowPos2iMESA = NULL;
PFNGLWINDOWPOS2IVMESAPROC glewWindowPos2ivMESA = NULL;
PFNGLWINDOWPOS2SMESAPROC glewWindowPos2sMESA = NULL;
PFNGLWINDOWPOS2SVMESAPROC glewWindowPos2svMESA = NULL;
PFNGLWINDOWPOS3DMESAPROC glewWindowPos3dMESA = NULL;
PFNGLWINDOWPOS3DVMESAPROC glewWindowPos3dvMESA = NULL;
PFNGLWINDOWPOS3FMESAPROC glewWindowPos3fMESA = NULL;
PFNGLWINDOWPOS3FVMESAPROC glewWindowPos3fvMESA = NULL;
PFNGLWINDOWPOS3IMESAPROC glewWindowPos3iMESA = NULL;
PFNGLWINDOWPOS3IVMESAPROC glewWindowPos3ivMESA = NULL;
PFNGLWINDOWPOS3SMESAPROC glewWindowPos3sMESA = NULL;
PFNGLWINDOWPOS3SVMESAPROC glewWindowPos3svMESA = NULL;
PFNGLWINDOWPOS4DMESAPROC glewWindowPos4dMESA = NULL;
PFNGLWINDOWPOS4DVMESAPROC glewWindowPos4dvMESA = NULL;
PFNGLWINDOWPOS4FMESAPROC glewWindowPos4fMESA = NULL;
PFNGLWINDOWPOS4FVMESAPROC glewWindowPos4fvMESA = NULL;
PFNGLWINDOWPOS4IMESAPROC glewWindowPos4iMESA = NULL;
PFNGLWINDOWPOS4IVMESAPROC glewWindowPos4ivMESA = NULL;
PFNGLWINDOWPOS4SMESAPROC glewWindowPos4sMESA = NULL;
PFNGLWINDOWPOS4SVMESAPROC glewWindowPos4svMESA = NULL;

static GLboolean _glewInit_GL_MESA_window_pos (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewWindowPos2dMESA = (PFNGLWINDOWPOS2DMESAPROC)glewGetProcAddress("glWindowPos2dMESA")) == NULL) || r;
  r = ((glewWindowPos2dvMESA = (PFNGLWINDOWPOS2DVMESAPROC)glewGetProcAddress("glWindowPos2dvMESA")) == NULL) || r;
  r = ((glewWindowPos2fMESA = (PFNGLWINDOWPOS2FMESAPROC)glewGetProcAddress("glWindowPos2fMESA")) == NULL) || r;
  r = ((glewWindowPos2fvMESA = (PFNGLWINDOWPOS2FVMESAPROC)glewGetProcAddress("glWindowPos2fvMESA")) == NULL) || r;
  r = ((glewWindowPos2iMESA = (PFNGLWINDOWPOS2IMESAPROC)glewGetProcAddress("glWindowPos2iMESA")) == NULL) || r;
  r = ((glewWindowPos2ivMESA = (PFNGLWINDOWPOS2IVMESAPROC)glewGetProcAddress("glWindowPos2ivMESA")) == NULL) || r;
  r = ((glewWindowPos2sMESA = (PFNGLWINDOWPOS2SMESAPROC)glewGetProcAddress("glWindowPos2sMESA")) == NULL) || r;
  r = ((glewWindowPos2svMESA = (PFNGLWINDOWPOS2SVMESAPROC)glewGetProcAddress("glWindowPos2svMESA")) == NULL) || r;
  r = ((glewWindowPos3dMESA = (PFNGLWINDOWPOS3DMESAPROC)glewGetProcAddress("glWindowPos3dMESA")) == NULL) || r;
  r = ((glewWindowPos3dvMESA = (PFNGLWINDOWPOS3DVMESAPROC)glewGetProcAddress("glWindowPos3dvMESA")) == NULL) || r;
  r = ((glewWindowPos3fMESA = (PFNGLWINDOWPOS3FMESAPROC)glewGetProcAddress("glWindowPos3fMESA")) == NULL) || r;
  r = ((glewWindowPos3fvMESA = (PFNGLWINDOWPOS3FVMESAPROC)glewGetProcAddress("glWindowPos3fvMESA")) == NULL) || r;
  r = ((glewWindowPos3iMESA = (PFNGLWINDOWPOS3IMESAPROC)glewGetProcAddress("glWindowPos3iMESA")) == NULL) || r;
  r = ((glewWindowPos3ivMESA = (PFNGLWINDOWPOS3IVMESAPROC)glewGetProcAddress("glWindowPos3ivMESA")) == NULL) || r;
  r = ((glewWindowPos3sMESA = (PFNGLWINDOWPOS3SMESAPROC)glewGetProcAddress("glWindowPos3sMESA")) == NULL) || r;
  r = ((glewWindowPos3svMESA = (PFNGLWINDOWPOS3SVMESAPROC)glewGetProcAddress("glWindowPos3svMESA")) == NULL) || r;
  r = ((glewWindowPos4dMESA = (PFNGLWINDOWPOS4DMESAPROC)glewGetProcAddress("glWindowPos4dMESA")) == NULL) || r;
  r = ((glewWindowPos4dvMESA = (PFNGLWINDOWPOS4DVMESAPROC)glewGetProcAddress("glWindowPos4dvMESA")) == NULL) || r;
  r = ((glewWindowPos4fMESA = (PFNGLWINDOWPOS4FMESAPROC)glewGetProcAddress("glWindowPos4fMESA")) == NULL) || r;
  r = ((glewWindowPos4fvMESA = (PFNGLWINDOWPOS4FVMESAPROC)glewGetProcAddress("glWindowPos4fvMESA")) == NULL) || r;
  r = ((glewWindowPos4iMESA = (PFNGLWINDOWPOS4IMESAPROC)glewGetProcAddress("glWindowPos4iMESA")) == NULL) || r;
  r = ((glewWindowPos4ivMESA = (PFNGLWINDOWPOS4IVMESAPROC)glewGetProcAddress("glWindowPos4ivMESA")) == NULL) || r;
  r = ((glewWindowPos4sMESA = (PFNGLWINDOWPOS4SMESAPROC)glewGetProcAddress("glWindowPos4sMESA")) == NULL) || r;
  r = ((glewWindowPos4svMESA = (PFNGLWINDOWPOS4SVMESAPROC)glewGetProcAddress("glWindowPos4svMESA")) == NULL) || r;

  return r;
}

GLboolean GLEW_MESA_window_pos = GL_FALSE;

#endif /* GL_MESA_window_pos */

/* --------------------------- GL_NV_blend_square -------------------------- */

#ifdef GL_NV_blend_square

GLboolean GLEW_NV_blend_square = GL_FALSE;

#endif /* GL_NV_blend_square */

/* ----------------------- GL_NV_copy_depth_to_color ----------------------- */

#ifdef GL_NV_copy_depth_to_color

GLboolean GLEW_NV_copy_depth_to_color = GL_FALSE;

#endif /* GL_NV_copy_depth_to_color */

/* --------------------------- GL_NV_depth_clamp --------------------------- */

#ifdef GL_NV_depth_clamp

GLboolean GLEW_NV_depth_clamp = GL_FALSE;

#endif /* GL_NV_depth_clamp */

/* -------------------------- GL_NV_element_array -------------------------- */

#ifdef GL_NV_element_array

PFNGLDRAWELEMENTARRAYNVPROC glewDrawElementArrayNV = NULL;
PFNGLDRAWRANGEELEMENTARRAYNVPROC glewDrawRangeElementArrayNV = NULL;
PFNGLELEMENTPOINTERNVPROC glewElementPointerNV = NULL;
PFNGLMULTIDRAWELEMENTARRAYNVPROC glewMultiDrawElementArrayNV = NULL;
PFNGLMULTIDRAWRANGEELEMENTARRAYNVPROC glewMultiDrawRangeElementArrayNV = NULL;

static GLboolean _glewInit_GL_NV_element_array (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewDrawElementArrayNV = (PFNGLDRAWELEMENTARRAYNVPROC)glewGetProcAddress("glDrawElementArrayNV")) == NULL) || r;
  r = ((glewDrawRangeElementArrayNV = (PFNGLDRAWRANGEELEMENTARRAYNVPROC)glewGetProcAddress("glDrawRangeElementArrayNV")) == NULL) || r;
  r = ((glewElementPointerNV = (PFNGLELEMENTPOINTERNVPROC)glewGetProcAddress("glElementPointerNV")) == NULL) || r;
  r = ((glewMultiDrawElementArrayNV = (PFNGLMULTIDRAWELEMENTARRAYNVPROC)glewGetProcAddress("glMultiDrawElementArrayNV")) == NULL) || r;
  r = ((glewMultiDrawRangeElementArrayNV = (PFNGLMULTIDRAWRANGEELEMENTARRAYNVPROC)glewGetProcAddress("glMultiDrawRangeElementArrayNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_element_array = GL_FALSE;

#endif /* GL_NV_element_array */

/* ---------------------------- GL_NV_evaluators --------------------------- */

#ifdef GL_NV_evaluators

PFNGLEVALMAPSNVPROC glewEvalMapsNV = NULL;
PFNGLGETMAPATTRIBPARAMETERFVNVPROC glewGetMapAttribParameterfvNV = NULL;
PFNGLGETMAPATTRIBPARAMETERIVNVPROC glewGetMapAttribParameterivNV = NULL;
PFNGLGETMAPCONTROLPOINTSNVPROC glewGetMapControlPointsNV = NULL;
PFNGLGETMAPPARAMETERFVNVPROC glewGetMapParameterfvNV = NULL;
PFNGLGETMAPPARAMETERIVNVPROC glewGetMapParameterivNV = NULL;
PFNGLMAPCONTROLPOINTSNVPROC glewMapControlPointsNV = NULL;
PFNGLMAPPARAMETERFVNVPROC glewMapParameterfvNV = NULL;
PFNGLMAPPARAMETERIVNVPROC glewMapParameterivNV = NULL;

static GLboolean _glewInit_GL_NV_evaluators (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewEvalMapsNV = (PFNGLEVALMAPSNVPROC)glewGetProcAddress("glEvalMapsNV")) == NULL) || r;
  r = ((glewGetMapAttribParameterfvNV = (PFNGLGETMAPATTRIBPARAMETERFVNVPROC)glewGetProcAddress("glGetMapAttribParameterfvNV")) == NULL) || r;
  r = ((glewGetMapAttribParameterivNV = (PFNGLGETMAPATTRIBPARAMETERIVNVPROC)glewGetProcAddress("glGetMapAttribParameterivNV")) == NULL) || r;
  r = ((glewGetMapControlPointsNV = (PFNGLGETMAPCONTROLPOINTSNVPROC)glewGetProcAddress("glGetMapControlPointsNV")) == NULL) || r;
  r = ((glewGetMapParameterfvNV = (PFNGLGETMAPPARAMETERFVNVPROC)glewGetProcAddress("glGetMapParameterfvNV")) == NULL) || r;
  r = ((glewGetMapParameterivNV = (PFNGLGETMAPPARAMETERIVNVPROC)glewGetProcAddress("glGetMapParameterivNV")) == NULL) || r;
  r = ((glewMapControlPointsNV = (PFNGLMAPCONTROLPOINTSNVPROC)glewGetProcAddress("glMapControlPointsNV")) == NULL) || r;
  r = ((glewMapParameterfvNV = (PFNGLMAPPARAMETERFVNVPROC)glewGetProcAddress("glMapParameterfvNV")) == NULL) || r;
  r = ((glewMapParameterivNV = (PFNGLMAPPARAMETERIVNVPROC)glewGetProcAddress("glMapParameterivNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_evaluators = GL_FALSE;

#endif /* GL_NV_evaluators */

/* ------------------------------ GL_NV_fence ------------------------------ */

#ifdef GL_NV_fence

PFNGLDELETEFENCESNVPROC glewDeleteFencesNV = NULL;
PFNGLFINISHFENCENVPROC glewFinishFenceNV = NULL;
PFNGLGENFENCESNVPROC glewGenFencesNV = NULL;
PFNGLGETFENCEIVNVPROC glewGetFenceivNV = NULL;
PFNGLISFENCENVPROC glewIsFenceNV = NULL;
PFNGLSETFENCENVPROC glewSetFenceNV = NULL;
PFNGLTESTFENCENVPROC glewTestFenceNV = NULL;

static GLboolean _glewInit_GL_NV_fence (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewDeleteFencesNV = (PFNGLDELETEFENCESNVPROC)glewGetProcAddress("glDeleteFencesNV")) == NULL) || r;
  r = ((glewFinishFenceNV = (PFNGLFINISHFENCENVPROC)glewGetProcAddress("glFinishFenceNV")) == NULL) || r;
  r = ((glewGenFencesNV = (PFNGLGENFENCESNVPROC)glewGetProcAddress("glGenFencesNV")) == NULL) || r;
  r = ((glewGetFenceivNV = (PFNGLGETFENCEIVNVPROC)glewGetProcAddress("glGetFenceivNV")) == NULL) || r;
  r = ((glewIsFenceNV = (PFNGLISFENCENVPROC)glewGetProcAddress("glIsFenceNV")) == NULL) || r;
  r = ((glewSetFenceNV = (PFNGLSETFENCENVPROC)glewGetProcAddress("glSetFenceNV")) == NULL) || r;
  r = ((glewTestFenceNV = (PFNGLTESTFENCENVPROC)glewGetProcAddress("glTestFenceNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_fence = GL_FALSE;

#endif /* GL_NV_fence */

/* --------------------------- GL_NV_float_buffer -------------------------- */

#ifdef GL_NV_float_buffer

GLboolean GLEW_NV_float_buffer = GL_FALSE;

#endif /* GL_NV_float_buffer */

/* --------------------------- GL_NV_fog_distance -------------------------- */

#ifdef GL_NV_fog_distance

GLboolean GLEW_NV_fog_distance = GL_FALSE;

#endif /* GL_NV_fog_distance */

/* ------------------------- GL_NV_fragment_program ------------------------ */

#ifdef GL_NV_fragment_program

PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC glewGetProgramNamedParameterdvNV = NULL;
PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC glewGetProgramNamedParameterfvNV = NULL;
PFNGLPROGRAMNAMEDPARAMETER4DNVPROC glewProgramNamedParameter4dNV = NULL;
PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC glewProgramNamedParameter4dvNV = NULL;
PFNGLPROGRAMNAMEDPARAMETER4FNVPROC glewProgramNamedParameter4fNV = NULL;
PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC glewProgramNamedParameter4fvNV = NULL;

static GLboolean _glewInit_GL_NV_fragment_program (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewGetProgramNamedParameterdvNV = (PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)glewGetProcAddress("glGetProgramNamedParameterdvNV")) == NULL) || r;
  r = ((glewGetProgramNamedParameterfvNV = (PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)glewGetProcAddress("glGetProgramNamedParameterfvNV")) == NULL) || r;
  r = ((glewProgramNamedParameter4dNV = (PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)glewGetProcAddress("glProgramNamedParameter4dNV")) == NULL) || r;
  r = ((glewProgramNamedParameter4dvNV = (PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)glewGetProcAddress("glProgramNamedParameter4dvNV")) == NULL) || r;
  r = ((glewProgramNamedParameter4fNV = (PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)glewGetProcAddress("glProgramNamedParameter4fNV")) == NULL) || r;
  r = ((glewProgramNamedParameter4fvNV = (PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)glewGetProcAddress("glProgramNamedParameter4fvNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_fragment_program = GL_FALSE;

#endif /* GL_NV_fragment_program */

/* ---------------------------- GL_NV_half_float --------------------------- */

#ifdef GL_NV_half_float

PFNGLCOLOR3HNVPROC glewColor3hNV = NULL;
PFNGLCOLOR3HVNVPROC glewColor3hvNV = NULL;
PFNGLCOLOR4HNVPROC glewColor4hNV = NULL;
PFNGLCOLOR4HVNVPROC glewColor4hvNV = NULL;
PFNGLFOGCOORDHNVPROC glewFogCoordhNV = NULL;
PFNGLFOGCOORDHVNVPROC glewFogCoordhvNV = NULL;
PFNGLMULTITEXCOORD1HNVPROC glewMultiTexCoord1hNV = NULL;
PFNGLMULTITEXCOORD1HVNVPROC glewMultiTexCoord1hvNV = NULL;
PFNGLMULTITEXCOORD2HNVPROC glewMultiTexCoord2hNV = NULL;
PFNGLMULTITEXCOORD2HVNVPROC glewMultiTexCoord2hvNV = NULL;
PFNGLMULTITEXCOORD3HNVPROC glewMultiTexCoord3hNV = NULL;
PFNGLMULTITEXCOORD3HVNVPROC glewMultiTexCoord3hvNV = NULL;
PFNGLMULTITEXCOORD4HNVPROC glewMultiTexCoord4hNV = NULL;
PFNGLMULTITEXCOORD4HVNVPROC glewMultiTexCoord4hvNV = NULL;
PFNGLNORMAL3HNVPROC glewNormal3hNV = NULL;
PFNGLNORMAL3HVNVPROC glewNormal3hvNV = NULL;
PFNGLSECONDARYCOLOR3HNVPROC glewSecondaryColor3hNV = NULL;
PFNGLSECONDARYCOLOR3HVNVPROC glewSecondaryColor3hvNV = NULL;
PFNGLTEXCOORD1HNVPROC glewTexCoord1hNV = NULL;
PFNGLTEXCOORD1HVNVPROC glewTexCoord1hvNV = NULL;
PFNGLTEXCOORD2HNVPROC glewTexCoord2hNV = NULL;
PFNGLTEXCOORD2HVNVPROC glewTexCoord2hvNV = NULL;
PFNGLTEXCOORD3HNVPROC glewTexCoord3hNV = NULL;
PFNGLTEXCOORD3HVNVPROC glewTexCoord3hvNV = NULL;
PFNGLTEXCOORD4HNVPROC glewTexCoord4hNV = NULL;
PFNGLTEXCOORD4HVNVPROC glewTexCoord4hvNV = NULL;
PFNGLVERTEX2HNVPROC glewVertex2hNV = NULL;
PFNGLVERTEX2HVNVPROC glewVertex2hvNV = NULL;
PFNGLVERTEX3HNVPROC glewVertex3hNV = NULL;
PFNGLVERTEX3HVNVPROC glewVertex3hvNV = NULL;
PFNGLVERTEX4HNVPROC glewVertex4hNV = NULL;
PFNGLVERTEX4HVNVPROC glewVertex4hvNV = NULL;
PFNGLVERTEXATTRIB1HNVPROC glewVertexAttrib1hNV = NULL;
PFNGLVERTEXATTRIB1HVNVPROC glewVertexAttrib1hvNV = NULL;
PFNGLVERTEXATTRIB2HNVPROC glewVertexAttrib2hNV = NULL;
PFNGLVERTEXATTRIB2HVNVPROC glewVertexAttrib2hvNV = NULL;
PFNGLVERTEXATTRIB3HNVPROC glewVertexAttrib3hNV = NULL;
PFNGLVERTEXATTRIB3HVNVPROC glewVertexAttrib3hvNV = NULL;
PFNGLVERTEXATTRIB4HNVPROC glewVertexAttrib4hNV = NULL;
PFNGLVERTEXATTRIB4HVNVPROC glewVertexAttrib4hvNV = NULL;
PFNGLVERTEXATTRIBS1HVNVPROC glewVertexAttribs1hvNV = NULL;
PFNGLVERTEXATTRIBS2HVNVPROC glewVertexAttribs2hvNV = NULL;
PFNGLVERTEXATTRIBS3HVNVPROC glewVertexAttribs3hvNV = NULL;
PFNGLVERTEXATTRIBS4HVNVPROC glewVertexAttribs4hvNV = NULL;
PFNGLVERTEXWEIGHTHNVPROC glewVertexWeighthNV = NULL;
PFNGLVERTEXWEIGHTHVNVPROC glewVertexWeighthvNV = NULL;

static GLboolean _glewInit_GL_NV_half_float (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewColor3hNV = (PFNGLCOLOR3HNVPROC)glewGetProcAddress("glColor3hNV")) == NULL) || r;
  r = ((glewColor3hvNV = (PFNGLCOLOR3HVNVPROC)glewGetProcAddress("glColor3hvNV")) == NULL) || r;
  r = ((glewColor4hNV = (PFNGLCOLOR4HNVPROC)glewGetProcAddress("glColor4hNV")) == NULL) || r;
  r = ((glewColor4hvNV = (PFNGLCOLOR4HVNVPROC)glewGetProcAddress("glColor4hvNV")) == NULL) || r;
  r = ((glewFogCoordhNV = (PFNGLFOGCOORDHNVPROC)glewGetProcAddress("glFogCoordhNV")) == NULL) || r;
  r = ((glewFogCoordhvNV = (PFNGLFOGCOORDHVNVPROC)glewGetProcAddress("glFogCoordhvNV")) == NULL) || r;
  r = ((glewMultiTexCoord1hNV = (PFNGLMULTITEXCOORD1HNVPROC)glewGetProcAddress("glMultiTexCoord1hNV")) == NULL) || r;
  r = ((glewMultiTexCoord1hvNV = (PFNGLMULTITEXCOORD1HVNVPROC)glewGetProcAddress("glMultiTexCoord1hvNV")) == NULL) || r;
  r = ((glewMultiTexCoord2hNV = (PFNGLMULTITEXCOORD2HNVPROC)glewGetProcAddress("glMultiTexCoord2hNV")) == NULL) || r;
  r = ((glewMultiTexCoord2hvNV = (PFNGLMULTITEXCOORD2HVNVPROC)glewGetProcAddress("glMultiTexCoord2hvNV")) == NULL) || r;
  r = ((glewMultiTexCoord3hNV = (PFNGLMULTITEXCOORD3HNVPROC)glewGetProcAddress("glMultiTexCoord3hNV")) == NULL) || r;
  r = ((glewMultiTexCoord3hvNV = (PFNGLMULTITEXCOORD3HVNVPROC)glewGetProcAddress("glMultiTexCoord3hvNV")) == NULL) || r;
  r = ((glewMultiTexCoord4hNV = (PFNGLMULTITEXCOORD4HNVPROC)glewGetProcAddress("glMultiTexCoord4hNV")) == NULL) || r;
  r = ((glewMultiTexCoord4hvNV = (PFNGLMULTITEXCOORD4HVNVPROC)glewGetProcAddress("glMultiTexCoord4hvNV")) == NULL) || r;
  r = ((glewNormal3hNV = (PFNGLNORMAL3HNVPROC)glewGetProcAddress("glNormal3hNV")) == NULL) || r;
  r = ((glewNormal3hvNV = (PFNGLNORMAL3HVNVPROC)glewGetProcAddress("glNormal3hvNV")) == NULL) || r;
  r = ((glewSecondaryColor3hNV = (PFNGLSECONDARYCOLOR3HNVPROC)glewGetProcAddress("glSecondaryColor3hNV")) == NULL) || r;
  r = ((glewSecondaryColor3hvNV = (PFNGLSECONDARYCOLOR3HVNVPROC)glewGetProcAddress("glSecondaryColor3hvNV")) == NULL) || r;
  r = ((glewTexCoord1hNV = (PFNGLTEXCOORD1HNVPROC)glewGetProcAddress("glTexCoord1hNV")) == NULL) || r;
  r = ((glewTexCoord1hvNV = (PFNGLTEXCOORD1HVNVPROC)glewGetProcAddress("glTexCoord1hvNV")) == NULL) || r;
  r = ((glewTexCoord2hNV = (PFNGLTEXCOORD2HNVPROC)glewGetProcAddress("glTexCoord2hNV")) == NULL) || r;
  r = ((glewTexCoord2hvNV = (PFNGLTEXCOORD2HVNVPROC)glewGetProcAddress("glTexCoord2hvNV")) == NULL) || r;
  r = ((glewTexCoord3hNV = (PFNGLTEXCOORD3HNVPROC)glewGetProcAddress("glTexCoord3hNV")) == NULL) || r;
  r = ((glewTexCoord3hvNV = (PFNGLTEXCOORD3HVNVPROC)glewGetProcAddress("glTexCoord3hvNV")) == NULL) || r;
  r = ((glewTexCoord4hNV = (PFNGLTEXCOORD4HNVPROC)glewGetProcAddress("glTexCoord4hNV")) == NULL) || r;
  r = ((glewTexCoord4hvNV = (PFNGLTEXCOORD4HVNVPROC)glewGetProcAddress("glTexCoord4hvNV")) == NULL) || r;
  r = ((glewVertex2hNV = (PFNGLVERTEX2HNVPROC)glewGetProcAddress("glVertex2hNV")) == NULL) || r;
  r = ((glewVertex2hvNV = (PFNGLVERTEX2HVNVPROC)glewGetProcAddress("glVertex2hvNV")) == NULL) || r;
  r = ((glewVertex3hNV = (PFNGLVERTEX3HNVPROC)glewGetProcAddress("glVertex3hNV")) == NULL) || r;
  r = ((glewVertex3hvNV = (PFNGLVERTEX3HVNVPROC)glewGetProcAddress("glVertex3hvNV")) == NULL) || r;
  r = ((glewVertex4hNV = (PFNGLVERTEX4HNVPROC)glewGetProcAddress("glVertex4hNV")) == NULL) || r;
  r = ((glewVertex4hvNV = (PFNGLVERTEX4HVNVPROC)glewGetProcAddress("glVertex4hvNV")) == NULL) || r;
  r = ((glewVertexAttrib1hNV = (PFNGLVERTEXATTRIB1HNVPROC)glewGetProcAddress("glVertexAttrib1hNV")) == NULL) || r;
  r = ((glewVertexAttrib1hvNV = (PFNGLVERTEXATTRIB1HVNVPROC)glewGetProcAddress("glVertexAttrib1hvNV")) == NULL) || r;
  r = ((glewVertexAttrib2hNV = (PFNGLVERTEXATTRIB2HNVPROC)glewGetProcAddress("glVertexAttrib2hNV")) == NULL) || r;
  r = ((glewVertexAttrib2hvNV = (PFNGLVERTEXATTRIB2HVNVPROC)glewGetProcAddress("glVertexAttrib2hvNV")) == NULL) || r;
  r = ((glewVertexAttrib3hNV = (PFNGLVERTEXATTRIB3HNVPROC)glewGetProcAddress("glVertexAttrib3hNV")) == NULL) || r;
  r = ((glewVertexAttrib3hvNV = (PFNGLVERTEXATTRIB3HVNVPROC)glewGetProcAddress("glVertexAttrib3hvNV")) == NULL) || r;
  r = ((glewVertexAttrib4hNV = (PFNGLVERTEXATTRIB4HNVPROC)glewGetProcAddress("glVertexAttrib4hNV")) == NULL) || r;
  r = ((glewVertexAttrib4hvNV = (PFNGLVERTEXATTRIB4HVNVPROC)glewGetProcAddress("glVertexAttrib4hvNV")) == NULL) || r;
  r = ((glewVertexAttribs1hvNV = (PFNGLVERTEXATTRIBS1HVNVPROC)glewGetProcAddress("glVertexAttribs1hvNV")) == NULL) || r;
  r = ((glewVertexAttribs2hvNV = (PFNGLVERTEXATTRIBS2HVNVPROC)glewGetProcAddress("glVertexAttribs2hvNV")) == NULL) || r;
  r = ((glewVertexAttribs3hvNV = (PFNGLVERTEXATTRIBS3HVNVPROC)glewGetProcAddress("glVertexAttribs3hvNV")) == NULL) || r;
  r = ((glewVertexAttribs4hvNV = (PFNGLVERTEXATTRIBS4HVNVPROC)glewGetProcAddress("glVertexAttribs4hvNV")) == NULL) || r;
  r = ((glewVertexWeighthNV = (PFNGLVERTEXWEIGHTHNVPROC)glewGetProcAddress("glVertexWeighthNV")) == NULL) || r;
  r = ((glewVertexWeighthvNV = (PFNGLVERTEXWEIGHTHVNVPROC)glewGetProcAddress("glVertexWeighthvNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_half_float = GL_FALSE;

#endif /* GL_NV_half_float */

/* ------------------------ GL_NV_light_max_exponent ----------------------- */

#ifdef GL_NV_light_max_exponent

GLboolean GLEW_NV_light_max_exponent = GL_FALSE;

#endif /* GL_NV_light_max_exponent */

/* --------------------- GL_NV_multisample_filter_hint --------------------- */

#ifdef GL_NV_multisample_filter_hint

GLboolean GLEW_NV_multisample_filter_hint = GL_FALSE;

#endif /* GL_NV_multisample_filter_hint */

/* ------------------------- GL_NV_occlusion_query ------------------------- */

#ifdef GL_NV_occlusion_query

PFNGLBEGINOCCLUSIONQUERYNVPROC glewBeginOcclusionQueryNV = NULL;
PFNGLDELETEOCCLUSIONQUERIESNVPROC glewDeleteOcclusionQueriesNV = NULL;
PFNGLENDOCCLUSIONQUERYNVPROC glewEndOcclusionQueryNV = NULL;
PFNGLGENOCCLUSIONQUERIESNVPROC glewGenOcclusionQueriesNV = NULL;
PFNGLGETOCCLUSIONQUERYIVNVPROC glewGetOcclusionQueryivNV = NULL;
PFNGLGETOCCLUSIONQUERYUIVNVPROC glewGetOcclusionQueryuivNV = NULL;
PFNGLISOCCLUSIONQUERYNVPROC glewIsOcclusionQueryNV = NULL;

static GLboolean _glewInit_GL_NV_occlusion_query (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewBeginOcclusionQueryNV = (PFNGLBEGINOCCLUSIONQUERYNVPROC)glewGetProcAddress("glBeginOcclusionQueryNV")) == NULL) || r;
  r = ((glewDeleteOcclusionQueriesNV = (PFNGLDELETEOCCLUSIONQUERIESNVPROC)glewGetProcAddress("glDeleteOcclusionQueriesNV")) == NULL) || r;
  r = ((glewEndOcclusionQueryNV = (PFNGLENDOCCLUSIONQUERYNVPROC)glewGetProcAddress("glEndOcclusionQueryNV")) == NULL) || r;
  r = ((glewGenOcclusionQueriesNV = (PFNGLGENOCCLUSIONQUERIESNVPROC)glewGetProcAddress("glGenOcclusionQueriesNV")) == NULL) || r;
  r = ((glewGetOcclusionQueryivNV = (PFNGLGETOCCLUSIONQUERYIVNVPROC)glewGetProcAddress("glGetOcclusionQueryivNV")) == NULL) || r;
  r = ((glewGetOcclusionQueryuivNV = (PFNGLGETOCCLUSIONQUERYUIVNVPROC)glewGetProcAddress("glGetOcclusionQueryuivNV")) == NULL) || r;
  r = ((glewIsOcclusionQueryNV = (PFNGLISOCCLUSIONQUERYNVPROC)glewGetProcAddress("glIsOcclusionQueryNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_occlusion_query = GL_FALSE;

#endif /* GL_NV_occlusion_query */

/* ----------------------- GL_NV_packed_depth_stencil ---------------------- */

#ifdef GL_NV_packed_depth_stencil

GLboolean GLEW_NV_packed_depth_stencil = GL_FALSE;

#endif /* GL_NV_packed_depth_stencil */

/* ------------------------- GL_NV_pixel_data_range ------------------------ */

#ifdef GL_NV_pixel_data_range

PFNGLFLUSHPIXELDATARANGENVPROC glewFlushPixelDataRangeNV = NULL;
PFNGLPIXELDATARANGENVPROC glewPixelDataRangeNV = NULL;

static GLboolean _glewInit_GL_NV_pixel_data_range (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewFlushPixelDataRangeNV = (PFNGLFLUSHPIXELDATARANGENVPROC)glewGetProcAddress("glFlushPixelDataRangeNV")) == NULL) || r;
  r = ((glewPixelDataRangeNV = (PFNGLPIXELDATARANGENVPROC)glewGetProcAddress("glPixelDataRangeNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_pixel_data_range = GL_FALSE;

#endif /* GL_NV_pixel_data_range */

/* --------------------------- GL_NV_point_sprite -------------------------- */

#ifdef GL_NV_point_sprite

PFNGLPOINTPARAMETERINVPROC glewPointParameteriNV = NULL;
PFNGLPOINTPARAMETERIVNVPROC glewPointParameterivNV = NULL;

static GLboolean _glewInit_GL_NV_point_sprite (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewPointParameteriNV = (PFNGLPOINTPARAMETERINVPROC)glewGetProcAddress("glPointParameteriNV")) == NULL) || r;
  r = ((glewPointParameterivNV = (PFNGLPOINTPARAMETERIVNVPROC)glewGetProcAddress("glPointParameterivNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_point_sprite = GL_FALSE;

#endif /* GL_NV_point_sprite */

/* ------------------------ GL_NV_primitive_restart ------------------------ */

#ifdef GL_NV_primitive_restart

PFNGLPRIMITIVERESTARTINDEXNVPROC glewPrimitiveRestartIndexNV = NULL;
PFNGLPRIMITIVERESTARTNVPROC glewPrimitiveRestartNV = NULL;

static GLboolean _glewInit_GL_NV_primitive_restart (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewPrimitiveRestartIndexNV = (PFNGLPRIMITIVERESTARTINDEXNVPROC)glewGetProcAddress("glPrimitiveRestartIndexNV")) == NULL) || r;
  r = ((glewPrimitiveRestartNV = (PFNGLPRIMITIVERESTARTNVPROC)glewGetProcAddress("glPrimitiveRestartNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_primitive_restart = GL_FALSE;

#endif /* GL_NV_primitive_restart */

/* ------------------------ GL_NV_register_combiners ----------------------- */

#ifdef GL_NV_register_combiners

PFNGLCOMBINERINPUTNVPROC glewCombinerInputNV = NULL;
PFNGLCOMBINEROUTPUTNVPROC glewCombinerOutputNV = NULL;
PFNGLCOMBINERPARAMETERFNVPROC glewCombinerParameterfNV = NULL;
PFNGLCOMBINERPARAMETERFVNVPROC glewCombinerParameterfvNV = NULL;
PFNGLCOMBINERPARAMETERINVPROC glewCombinerParameteriNV = NULL;
PFNGLCOMBINERPARAMETERIVNVPROC glewCombinerParameterivNV = NULL;
PFNGLFINALCOMBINERINPUTNVPROC glewFinalCombinerInputNV = NULL;
PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC glewGetCombinerInputParameterfvNV = NULL;
PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC glewGetCombinerInputParameterivNV = NULL;
PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC glewGetCombinerOutputParameterfvNV = NULL;
PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC glewGetCombinerOutputParameterivNV = NULL;
PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC glewGetFinalCombinerInputParameterfvNV = NULL;
PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC glewGetFinalCombinerInputParameterivNV = NULL;

static GLboolean _glewInit_GL_NV_register_combiners (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewCombinerInputNV = (PFNGLCOMBINERINPUTNVPROC)glewGetProcAddress("glCombinerInputNV")) == NULL) || r;
  r = ((glewCombinerOutputNV = (PFNGLCOMBINEROUTPUTNVPROC)glewGetProcAddress("glCombinerOutputNV")) == NULL) || r;
  r = ((glewCombinerParameterfNV = (PFNGLCOMBINERPARAMETERFNVPROC)glewGetProcAddress("glCombinerParameterfNV")) == NULL) || r;
  r = ((glewCombinerParameterfvNV = (PFNGLCOMBINERPARAMETERFVNVPROC)glewGetProcAddress("glCombinerParameterfvNV")) == NULL) || r;
  r = ((glewCombinerParameteriNV = (PFNGLCOMBINERPARAMETERINVPROC)glewGetProcAddress("glCombinerParameteriNV")) == NULL) || r;
  r = ((glewCombinerParameterivNV = (PFNGLCOMBINERPARAMETERIVNVPROC)glewGetProcAddress("glCombinerParameterivNV")) == NULL) || r;
  r = ((glewFinalCombinerInputNV = (PFNGLFINALCOMBINERINPUTNVPROC)glewGetProcAddress("glFinalCombinerInputNV")) == NULL) || r;
  r = ((glewGetCombinerInputParameterfvNV = (PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)glewGetProcAddress("glGetCombinerInputParameterfvNV")) == NULL) || r;
  r = ((glewGetCombinerInputParameterivNV = (PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)glewGetProcAddress("glGetCombinerInputParameterivNV")) == NULL) || r;
  r = ((glewGetCombinerOutputParameterfvNV = (PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)glewGetProcAddress("glGetCombinerOutputParameterfvNV")) == NULL) || r;
  r = ((glewGetCombinerOutputParameterivNV = (PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)glewGetProcAddress("glGetCombinerOutputParameterivNV")) == NULL) || r;
  r = ((glewGetFinalCombinerInputParameterfvNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)glewGetProcAddress("glGetFinalCombinerInputParameterfvNV")) == NULL) || r;
  r = ((glewGetFinalCombinerInputParameterivNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)glewGetProcAddress("glGetFinalCombinerInputParameterivNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_register_combiners = GL_FALSE;

#endif /* GL_NV_register_combiners */

/* ----------------------- GL_NV_register_combiners2 ----------------------- */

#ifdef GL_NV_register_combiners2

PFNGLCOMBINERSTAGEPARAMETERFVNVPROC glewCombinerStageParameterfvNV = NULL;
PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC glewGetCombinerStageParameterfvNV = NULL;

static GLboolean _glewInit_GL_NV_register_combiners2 (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewCombinerStageParameterfvNV = (PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)glewGetProcAddress("glCombinerStageParameterfvNV")) == NULL) || r;
  r = ((glewGetCombinerStageParameterfvNV = (PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)glewGetProcAddress("glGetCombinerStageParameterfvNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_register_combiners2 = GL_FALSE;

#endif /* GL_NV_register_combiners2 */

/* -------------------------- GL_NV_texgen_emboss -------------------------- */

#ifdef GL_NV_texgen_emboss

GLboolean GLEW_NV_texgen_emboss = GL_FALSE;

#endif /* GL_NV_texgen_emboss */

/* ------------------------ GL_NV_texgen_reflection ------------------------ */

#ifdef GL_NV_texgen_reflection

GLboolean GLEW_NV_texgen_reflection = GL_FALSE;

#endif /* GL_NV_texgen_reflection */

/* --------------------- GL_NV_texture_compression_vtc --------------------- */

#ifdef GL_NV_texture_compression_vtc

GLboolean GLEW_NV_texture_compression_vtc = GL_FALSE;

#endif /* GL_NV_texture_compression_vtc */

/* ----------------------- GL_NV_texture_env_combine4 ---------------------- */

#ifdef GL_NV_texture_env_combine4

GLboolean GLEW_NV_texture_env_combine4 = GL_FALSE;

#endif /* GL_NV_texture_env_combine4 */

/* ---------------------- GL_NV_texture_expand_normal ---------------------- */

#ifdef GL_NV_texture_expand_normal

GLboolean GLEW_NV_texture_expand_normal = GL_FALSE;

#endif /* GL_NV_texture_expand_normal */

/* ------------------------ GL_NV_texture_rectangle ------------------------ */

#ifdef GL_NV_texture_rectangle

GLboolean GLEW_NV_texture_rectangle = GL_FALSE;

#endif /* GL_NV_texture_rectangle */

/* -------------------------- GL_NV_texture_shader ------------------------- */

#ifdef GL_NV_texture_shader

GLboolean GLEW_NV_texture_shader = GL_FALSE;

#endif /* GL_NV_texture_shader */

/* ------------------------- GL_NV_texture_shader2 ------------------------- */

#ifdef GL_NV_texture_shader2

GLboolean GLEW_NV_texture_shader2 = GL_FALSE;

#endif /* GL_NV_texture_shader2 */

/* ------------------------- GL_NV_texture_shader3 ------------------------- */

#ifdef GL_NV_texture_shader3

GLboolean GLEW_NV_texture_shader3 = GL_FALSE;

#endif /* GL_NV_texture_shader3 */

/* ------------------------ GL_NV_vertex_array_range ----------------------- */

#ifdef GL_NV_vertex_array_range

PFNGLFLUSHVERTEXARRAYRANGENVPROC glewFlushVertexArrayRangeNV = NULL;
PFNGLVERTEXARRAYRANGENVPROC glewVertexArrayRangeNV = NULL;

static GLboolean _glewInit_GL_NV_vertex_array_range (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewFlushVertexArrayRangeNV = (PFNGLFLUSHVERTEXARRAYRANGENVPROC)glewGetProcAddress("glFlushVertexArrayRangeNV")) == NULL) || r;
  r = ((glewVertexArrayRangeNV = (PFNGLVERTEXARRAYRANGENVPROC)glewGetProcAddress("glVertexArrayRangeNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_vertex_array_range = GL_FALSE;

#endif /* GL_NV_vertex_array_range */

/* ----------------------- GL_NV_vertex_array_range2 ----------------------- */

#ifdef GL_NV_vertex_array_range2

GLboolean GLEW_NV_vertex_array_range2 = GL_FALSE;

#endif /* GL_NV_vertex_array_range2 */

/* -------------------------- GL_NV_vertex_program ------------------------- */

#ifdef GL_NV_vertex_program

PFNGLAREPROGRAMSRESIDENTNVPROC glewAreProgramsResidentNV = NULL;
PFNGLBINDPROGRAMNVPROC glewBindProgramNV = NULL;
PFNGLDELETEPROGRAMSNVPROC glewDeleteProgramsNV = NULL;
PFNGLEXECUTEPROGRAMNVPROC glewExecuteProgramNV = NULL;
PFNGLGENPROGRAMSNVPROC glewGenProgramsNV = NULL;
PFNGLGETPROGRAMPARAMETERDVNVPROC glewGetProgramParameterdvNV = NULL;
PFNGLGETPROGRAMPARAMETERFVNVPROC glewGetProgramParameterfvNV = NULL;
PFNGLGETPROGRAMSTRINGNVPROC glewGetProgramStringNV = NULL;
PFNGLGETPROGRAMIVNVPROC glewGetProgramivNV = NULL;
PFNGLGETTRACKMATRIXIVNVPROC glewGetTrackMatrixivNV = NULL;
PFNGLGETVERTEXATTRIBPOINTERVNVPROC glewGetVertexAttribPointervNV = NULL;
PFNGLGETVERTEXATTRIBDVNVPROC glewGetVertexAttribdvNV = NULL;
PFNGLGETVERTEXATTRIBFVNVPROC glewGetVertexAttribfvNV = NULL;
PFNGLGETVERTEXATTRIBIVNVPROC glewGetVertexAttribivNV = NULL;
PFNGLISPROGRAMNVPROC glewIsProgramNV = NULL;
PFNGLLOADPROGRAMNVPROC glewLoadProgramNV = NULL;
PFNGLPROGRAMPARAMETER4DNVPROC glewProgramParameter4dNV = NULL;
PFNGLPROGRAMPARAMETER4DVNVPROC glewProgramParameter4dvNV = NULL;
PFNGLPROGRAMPARAMETER4FNVPROC glewProgramParameter4fNV = NULL;
PFNGLPROGRAMPARAMETER4FVNVPROC glewProgramParameter4fvNV = NULL;
PFNGLPROGRAMPARAMETERS4DVNVPROC glewProgramParameters4dvNV = NULL;
PFNGLPROGRAMPARAMETERS4FVNVPROC glewProgramParameters4fvNV = NULL;
PFNGLREQUESTRESIDENTPROGRAMSNVPROC glewRequestResidentProgramsNV = NULL;
PFNGLTRACKMATRIXNVPROC glewTrackMatrixNV = NULL;
PFNGLVERTEXATTRIB1DNVPROC glewVertexAttrib1dNV = NULL;
PFNGLVERTEXATTRIB1DVNVPROC glewVertexAttrib1dvNV = NULL;
PFNGLVERTEXATTRIB1FNVPROC glewVertexAttrib1fNV = NULL;
PFNGLVERTEXATTRIB1FVNVPROC glewVertexAttrib1fvNV = NULL;
PFNGLVERTEXATTRIB1SNVPROC glewVertexAttrib1sNV = NULL;
PFNGLVERTEXATTRIB1SVNVPROC glewVertexAttrib1svNV = NULL;
PFNGLVERTEXATTRIB2DNVPROC glewVertexAttrib2dNV = NULL;
PFNGLVERTEXATTRIB2DVNVPROC glewVertexAttrib2dvNV = NULL;
PFNGLVERTEXATTRIB2FNVPROC glewVertexAttrib2fNV = NULL;
PFNGLVERTEXATTRIB2FVNVPROC glewVertexAttrib2fvNV = NULL;
PFNGLVERTEXATTRIB2SNVPROC glewVertexAttrib2sNV = NULL;
PFNGLVERTEXATTRIB2SVNVPROC glewVertexAttrib2svNV = NULL;
PFNGLVERTEXATTRIB3DNVPROC glewVertexAttrib3dNV = NULL;
PFNGLVERTEXATTRIB3DVNVPROC glewVertexAttrib3dvNV = NULL;
PFNGLVERTEXATTRIB3FNVPROC glewVertexAttrib3fNV = NULL;
PFNGLVERTEXATTRIB3FVNVPROC glewVertexAttrib3fvNV = NULL;
PFNGLVERTEXATTRIB3SNVPROC glewVertexAttrib3sNV = NULL;
PFNGLVERTEXATTRIB3SVNVPROC glewVertexAttrib3svNV = NULL;
PFNGLVERTEXATTRIB4DNVPROC glewVertexAttrib4dNV = NULL;
PFNGLVERTEXATTRIB4DVNVPROC glewVertexAttrib4dvNV = NULL;
PFNGLVERTEXATTRIB4FNVPROC glewVertexAttrib4fNV = NULL;
PFNGLVERTEXATTRIB4FVNVPROC glewVertexAttrib4fvNV = NULL;
PFNGLVERTEXATTRIB4SNVPROC glewVertexAttrib4sNV = NULL;
PFNGLVERTEXATTRIB4SVNVPROC glewVertexAttrib4svNV = NULL;
PFNGLVERTEXATTRIB4UBNVPROC glewVertexAttrib4ubNV = NULL;
PFNGLVERTEXATTRIB4UBVNVPROC glewVertexAttrib4ubvNV = NULL;
PFNGLVERTEXATTRIBPOINTERNVPROC glewVertexAttribPointerNV = NULL;
PFNGLVERTEXATTRIBS1DVNVPROC glewVertexAttribs1dvNV = NULL;
PFNGLVERTEXATTRIBS1FVNVPROC glewVertexAttribs1fvNV = NULL;
PFNGLVERTEXATTRIBS1SVNVPROC glewVertexAttribs1svNV = NULL;
PFNGLVERTEXATTRIBS2DVNVPROC glewVertexAttribs2dvNV = NULL;
PFNGLVERTEXATTRIBS2FVNVPROC glewVertexAttribs2fvNV = NULL;
PFNGLVERTEXATTRIBS2SVNVPROC glewVertexAttribs2svNV = NULL;
PFNGLVERTEXATTRIBS3DVNVPROC glewVertexAttribs3dvNV = NULL;
PFNGLVERTEXATTRIBS3FVNVPROC glewVertexAttribs3fvNV = NULL;
PFNGLVERTEXATTRIBS3SVNVPROC glewVertexAttribs3svNV = NULL;
PFNGLVERTEXATTRIBS4DVNVPROC glewVertexAttribs4dvNV = NULL;
PFNGLVERTEXATTRIBS4FVNVPROC glewVertexAttribs4fvNV = NULL;
PFNGLVERTEXATTRIBS4SVNVPROC glewVertexAttribs4svNV = NULL;
PFNGLVERTEXATTRIBS4UBVNVPROC glewVertexAttribs4ubvNV = NULL;

static GLboolean _glewInit_GL_NV_vertex_program (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewAreProgramsResidentNV = (PFNGLAREPROGRAMSRESIDENTNVPROC)glewGetProcAddress("glAreProgramsResidentNV")) == NULL) || r;
  r = ((glewBindProgramNV = (PFNGLBINDPROGRAMNVPROC)glewGetProcAddress("glBindProgramNV")) == NULL) || r;
  r = ((glewDeleteProgramsNV = (PFNGLDELETEPROGRAMSNVPROC)glewGetProcAddress("glDeleteProgramsNV")) == NULL) || r;
  r = ((glewExecuteProgramNV = (PFNGLEXECUTEPROGRAMNVPROC)glewGetProcAddress("glExecuteProgramNV")) == NULL) || r;
  r = ((glewGenProgramsNV = (PFNGLGENPROGRAMSNVPROC)glewGetProcAddress("glGenProgramsNV")) == NULL) || r;
  r = ((glewGetProgramParameterdvNV = (PFNGLGETPROGRAMPARAMETERDVNVPROC)glewGetProcAddress("glGetProgramParameterdvNV")) == NULL) || r;
  r = ((glewGetProgramParameterfvNV = (PFNGLGETPROGRAMPARAMETERFVNVPROC)glewGetProcAddress("glGetProgramParameterfvNV")) == NULL) || r;
  r = ((glewGetProgramStringNV = (PFNGLGETPROGRAMSTRINGNVPROC)glewGetProcAddress("glGetProgramStringNV")) == NULL) || r;
  r = ((glewGetProgramivNV = (PFNGLGETPROGRAMIVNVPROC)glewGetProcAddress("glGetProgramivNV")) == NULL) || r;
  r = ((glewGetTrackMatrixivNV = (PFNGLGETTRACKMATRIXIVNVPROC)glewGetProcAddress("glGetTrackMatrixivNV")) == NULL) || r;
  r = ((glewGetVertexAttribPointervNV = (PFNGLGETVERTEXATTRIBPOINTERVNVPROC)glewGetProcAddress("glGetVertexAttribPointervNV")) == NULL) || r;
  r = ((glewGetVertexAttribdvNV = (PFNGLGETVERTEXATTRIBDVNVPROC)glewGetProcAddress("glGetVertexAttribdvNV")) == NULL) || r;
  r = ((glewGetVertexAttribfvNV = (PFNGLGETVERTEXATTRIBFVNVPROC)glewGetProcAddress("glGetVertexAttribfvNV")) == NULL) || r;
  r = ((glewGetVertexAttribivNV = (PFNGLGETVERTEXATTRIBIVNVPROC)glewGetProcAddress("glGetVertexAttribivNV")) == NULL) || r;
  r = ((glewIsProgramNV = (PFNGLISPROGRAMNVPROC)glewGetProcAddress("glIsProgramNV")) == NULL) || r;
  r = ((glewLoadProgramNV = (PFNGLLOADPROGRAMNVPROC)glewGetProcAddress("glLoadProgramNV")) == NULL) || r;
  r = ((glewProgramParameter4dNV = (PFNGLPROGRAMPARAMETER4DNVPROC)glewGetProcAddress("glProgramParameter4dNV")) == NULL) || r;
  r = ((glewProgramParameter4dvNV = (PFNGLPROGRAMPARAMETER4DVNVPROC)glewGetProcAddress("glProgramParameter4dvNV")) == NULL) || r;
  r = ((glewProgramParameter4fNV = (PFNGLPROGRAMPARAMETER4FNVPROC)glewGetProcAddress("glProgramParameter4fNV")) == NULL) || r;
  r = ((glewProgramParameter4fvNV = (PFNGLPROGRAMPARAMETER4FVNVPROC)glewGetProcAddress("glProgramParameter4fvNV")) == NULL) || r;
  r = ((glewProgramParameters4dvNV = (PFNGLPROGRAMPARAMETERS4DVNVPROC)glewGetProcAddress("glProgramParameters4dvNV")) == NULL) || r;
  r = ((glewProgramParameters4fvNV = (PFNGLPROGRAMPARAMETERS4FVNVPROC)glewGetProcAddress("glProgramParameters4fvNV")) == NULL) || r;
  r = ((glewRequestResidentProgramsNV = (PFNGLREQUESTRESIDENTPROGRAMSNVPROC)glewGetProcAddress("glRequestResidentProgramsNV")) == NULL) || r;
  r = ((glewTrackMatrixNV = (PFNGLTRACKMATRIXNVPROC)glewGetProcAddress("glTrackMatrixNV")) == NULL) || r;
  r = ((glewVertexAttrib1dNV = (PFNGLVERTEXATTRIB1DNVPROC)glewGetProcAddress("glVertexAttrib1dNV")) == NULL) || r;
  r = ((glewVertexAttrib1dvNV = (PFNGLVERTEXATTRIB1DVNVPROC)glewGetProcAddress("glVertexAttrib1dvNV")) == NULL) || r;
  r = ((glewVertexAttrib1fNV = (PFNGLVERTEXATTRIB1FNVPROC)glewGetProcAddress("glVertexAttrib1fNV")) == NULL) || r;
  r = ((glewVertexAttrib1fvNV = (PFNGLVERTEXATTRIB1FVNVPROC)glewGetProcAddress("glVertexAttrib1fvNV")) == NULL) || r;
  r = ((glewVertexAttrib1sNV = (PFNGLVERTEXATTRIB1SNVPROC)glewGetProcAddress("glVertexAttrib1sNV")) == NULL) || r;
  r = ((glewVertexAttrib1svNV = (PFNGLVERTEXATTRIB1SVNVPROC)glewGetProcAddress("glVertexAttrib1svNV")) == NULL) || r;
  r = ((glewVertexAttrib2dNV = (PFNGLVERTEXATTRIB2DNVPROC)glewGetProcAddress("glVertexAttrib2dNV")) == NULL) || r;
  r = ((glewVertexAttrib2dvNV = (PFNGLVERTEXATTRIB2DVNVPROC)glewGetProcAddress("glVertexAttrib2dvNV")) == NULL) || r;
  r = ((glewVertexAttrib2fNV = (PFNGLVERTEXATTRIB2FNVPROC)glewGetProcAddress("glVertexAttrib2fNV")) == NULL) || r;
  r = ((glewVertexAttrib2fvNV = (PFNGLVERTEXATTRIB2FVNVPROC)glewGetProcAddress("glVertexAttrib2fvNV")) == NULL) || r;
  r = ((glewVertexAttrib2sNV = (PFNGLVERTEXATTRIB2SNVPROC)glewGetProcAddress("glVertexAttrib2sNV")) == NULL) || r;
  r = ((glewVertexAttrib2svNV = (PFNGLVERTEXATTRIB2SVNVPROC)glewGetProcAddress("glVertexAttrib2svNV")) == NULL) || r;
  r = ((glewVertexAttrib3dNV = (PFNGLVERTEXATTRIB3DNVPROC)glewGetProcAddress("glVertexAttrib3dNV")) == NULL) || r;
  r = ((glewVertexAttrib3dvNV = (PFNGLVERTEXATTRIB3DVNVPROC)glewGetProcAddress("glVertexAttrib3dvNV")) == NULL) || r;
  r = ((glewVertexAttrib3fNV = (PFNGLVERTEXATTRIB3FNVPROC)glewGetProcAddress("glVertexAttrib3fNV")) == NULL) || r;
  r = ((glewVertexAttrib3fvNV = (PFNGLVERTEXATTRIB3FVNVPROC)glewGetProcAddress("glVertexAttrib3fvNV")) == NULL) || r;
  r = ((glewVertexAttrib3sNV = (PFNGLVERTEXATTRIB3SNVPROC)glewGetProcAddress("glVertexAttrib3sNV")) == NULL) || r;
  r = ((glewVertexAttrib3svNV = (PFNGLVERTEXATTRIB3SVNVPROC)glewGetProcAddress("glVertexAttrib3svNV")) == NULL) || r;
  r = ((glewVertexAttrib4dNV = (PFNGLVERTEXATTRIB4DNVPROC)glewGetProcAddress("glVertexAttrib4dNV")) == NULL) || r;
  r = ((glewVertexAttrib4dvNV = (PFNGLVERTEXATTRIB4DVNVPROC)glewGetProcAddress("glVertexAttrib4dvNV")) == NULL) || r;
  r = ((glewVertexAttrib4fNV = (PFNGLVERTEXATTRIB4FNVPROC)glewGetProcAddress("glVertexAttrib4fNV")) == NULL) || r;
  r = ((glewVertexAttrib4fvNV = (PFNGLVERTEXATTRIB4FVNVPROC)glewGetProcAddress("glVertexAttrib4fvNV")) == NULL) || r;
  r = ((glewVertexAttrib4sNV = (PFNGLVERTEXATTRIB4SNVPROC)glewGetProcAddress("glVertexAttrib4sNV")) == NULL) || r;
  r = ((glewVertexAttrib4svNV = (PFNGLVERTEXATTRIB4SVNVPROC)glewGetProcAddress("glVertexAttrib4svNV")) == NULL) || r;
  r = ((glewVertexAttrib4ubNV = (PFNGLVERTEXATTRIB4UBNVPROC)glewGetProcAddress("glVertexAttrib4ubNV")) == NULL) || r;
  r = ((glewVertexAttrib4ubvNV = (PFNGLVERTEXATTRIB4UBVNVPROC)glewGetProcAddress("glVertexAttrib4ubvNV")) == NULL) || r;
  r = ((glewVertexAttribPointerNV = (PFNGLVERTEXATTRIBPOINTERNVPROC)glewGetProcAddress("glVertexAttribPointerNV")) == NULL) || r;
  r = ((glewVertexAttribs1dvNV = (PFNGLVERTEXATTRIBS1DVNVPROC)glewGetProcAddress("glVertexAttribs1dvNV")) == NULL) || r;
  r = ((glewVertexAttribs1fvNV = (PFNGLVERTEXATTRIBS1FVNVPROC)glewGetProcAddress("glVertexAttribs1fvNV")) == NULL) || r;
  r = ((glewVertexAttribs1svNV = (PFNGLVERTEXATTRIBS1SVNVPROC)glewGetProcAddress("glVertexAttribs1svNV")) == NULL) || r;
  r = ((glewVertexAttribs2dvNV = (PFNGLVERTEXATTRIBS2DVNVPROC)glewGetProcAddress("glVertexAttribs2dvNV")) == NULL) || r;
  r = ((glewVertexAttribs2fvNV = (PFNGLVERTEXATTRIBS2FVNVPROC)glewGetProcAddress("glVertexAttribs2fvNV")) == NULL) || r;
  r = ((glewVertexAttribs2svNV = (PFNGLVERTEXATTRIBS2SVNVPROC)glewGetProcAddress("glVertexAttribs2svNV")) == NULL) || r;
  r = ((glewVertexAttribs3dvNV = (PFNGLVERTEXATTRIBS3DVNVPROC)glewGetProcAddress("glVertexAttribs3dvNV")) == NULL) || r;
  r = ((glewVertexAttribs3fvNV = (PFNGLVERTEXATTRIBS3FVNVPROC)glewGetProcAddress("glVertexAttribs3fvNV")) == NULL) || r;
  r = ((glewVertexAttribs3svNV = (PFNGLVERTEXATTRIBS3SVNVPROC)glewGetProcAddress("glVertexAttribs3svNV")) == NULL) || r;
  r = ((glewVertexAttribs4dvNV = (PFNGLVERTEXATTRIBS4DVNVPROC)glewGetProcAddress("glVertexAttribs4dvNV")) == NULL) || r;
  r = ((glewVertexAttribs4fvNV = (PFNGLVERTEXATTRIBS4FVNVPROC)glewGetProcAddress("glVertexAttribs4fvNV")) == NULL) || r;
  r = ((glewVertexAttribs4svNV = (PFNGLVERTEXATTRIBS4SVNVPROC)glewGetProcAddress("glVertexAttribs4svNV")) == NULL) || r;
  r = ((glewVertexAttribs4ubvNV = (PFNGLVERTEXATTRIBS4UBVNVPROC)glewGetProcAddress("glVertexAttribs4ubvNV")) == NULL) || r;

  return r;
}

GLboolean GLEW_NV_vertex_program = GL_FALSE;

#endif /* GL_NV_vertex_program */

/* ------------------------ GL_NV_vertex_program1_1 ------------------------ */

#ifdef GL_NV_vertex_program1_1

GLboolean GLEW_NV_vertex_program1_1 = GL_FALSE;

#endif /* GL_NV_vertex_program1_1 */

/* ------------------------- GL_NV_vertex_program2 ------------------------- */

#ifdef GL_NV_vertex_program2

GLboolean GLEW_NV_vertex_program2 = GL_FALSE;

#endif /* GL_NV_vertex_program2 */

/* ---------------------------- GL_OML_interlace --------------------------- */

#ifdef GL_OML_interlace

GLboolean GLEW_OML_interlace = GL_FALSE;

#endif /* GL_OML_interlace */

/* ---------------------------- GL_OML_resample ---------------------------- */

#ifdef GL_OML_resample

GLboolean GLEW_OML_resample = GL_FALSE;

#endif /* GL_OML_resample */

/* ---------------------------- GL_OML_subsample --------------------------- */

#ifdef GL_OML_subsample

GLboolean GLEW_OML_subsample = GL_FALSE;

#endif /* GL_OML_subsample */

/* --------------------------- GL_PGI_misc_hints --------------------------- */

#ifdef GL_PGI_misc_hints

GLboolean GLEW_PGI_misc_hints = GL_FALSE;

#endif /* GL_PGI_misc_hints */

/* -------------------------- GL_PGI_vertex_hints -------------------------- */

#ifdef GL_PGI_vertex_hints

GLboolean GLEW_PGI_vertex_hints = GL_FALSE;

#endif /* GL_PGI_vertex_hints */

/* ----------------------- GL_REND_screen_coordinates ---------------------- */

#ifdef GL_REND_screen_coordinates

GLboolean GLEW_REND_screen_coordinates = GL_FALSE;

#endif /* GL_REND_screen_coordinates */

/* ------------------------------- GL_S3_s3tc ------------------------------ */

#ifdef GL_S3_s3tc

GLboolean GLEW_S3_s3tc = GL_FALSE;

#endif /* GL_S3_s3tc */

/* -------------------------- GL_SGIS_color_range -------------------------- */

#ifdef GL_SGIS_color_range

GLboolean GLEW_SGIS_color_range = GL_FALSE;

#endif /* GL_SGIS_color_range */

/* ------------------------- GL_SGIS_detail_texture ------------------------ */

#ifdef GL_SGIS_detail_texture

PFNGLDETAILTEXFUNCSGISPROC glewDetailTexFuncSGIS = NULL;
PFNGLGETDETAILTEXFUNCSGISPROC glewGetDetailTexFuncSGIS = NULL;

static GLboolean _glewInit_GL_SGIS_detail_texture (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewDetailTexFuncSGIS = (PFNGLDETAILTEXFUNCSGISPROC)glewGetProcAddress("glDetailTexFuncSGIS")) == NULL) || r;
  r = ((glewGetDetailTexFuncSGIS = (PFNGLGETDETAILTEXFUNCSGISPROC)glewGetProcAddress("glGetDetailTexFuncSGIS")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIS_detail_texture = GL_FALSE;

#endif /* GL_SGIS_detail_texture */

/* -------------------------- GL_SGIS_fog_function ------------------------- */

#ifdef GL_SGIS_fog_function

PFNGLFOGFUNCSGISPROC glewFogFuncSGIS = NULL;
PFNGLGETFOGFUNCSGISPROC glewGetFogFuncSGIS = NULL;

static GLboolean _glewInit_GL_SGIS_fog_function (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewFogFuncSGIS = (PFNGLFOGFUNCSGISPROC)glewGetProcAddress("glFogFuncSGIS")) == NULL) || r;
  r = ((glewGetFogFuncSGIS = (PFNGLGETFOGFUNCSGISPROC)glewGetProcAddress("glGetFogFuncSGIS")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIS_fog_function = GL_FALSE;

#endif /* GL_SGIS_fog_function */

/* ------------------------ GL_SGIS_generate_mipmap ------------------------ */

#ifdef GL_SGIS_generate_mipmap

GLboolean GLEW_SGIS_generate_mipmap = GL_FALSE;

#endif /* GL_SGIS_generate_mipmap */

/* -------------------------- GL_SGIS_multisample -------------------------- */

#ifdef GL_SGIS_multisample

PFNGLSAMPLEMASKSGISPROC glewSampleMaskSGIS = NULL;
PFNGLSAMPLEPATTERNSGISPROC glewSamplePatternSGIS = NULL;

static GLboolean _glewInit_GL_SGIS_multisample (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewSampleMaskSGIS = (PFNGLSAMPLEMASKSGISPROC)glewGetProcAddress("glSampleMaskSGIS")) == NULL) || r;
  r = ((glewSamplePatternSGIS = (PFNGLSAMPLEPATTERNSGISPROC)glewGetProcAddress("glSamplePatternSGIS")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIS_multisample = GL_FALSE;

#endif /* GL_SGIS_multisample */

/* ------------------------- GL_SGIS_pixel_texture ------------------------- */

#ifdef GL_SGIS_pixel_texture

GLboolean GLEW_SGIS_pixel_texture = GL_FALSE;

#endif /* GL_SGIS_pixel_texture */

/* ------------------------ GL_SGIS_sharpen_texture ------------------------ */

#ifdef GL_SGIS_sharpen_texture

PFNGLGETSHARPENTEXFUNCSGISPROC glewGetSharpenTexFuncSGIS = NULL;
PFNGLSHARPENTEXFUNCSGISPROC glewSharpenTexFuncSGIS = NULL;

static GLboolean _glewInit_GL_SGIS_sharpen_texture (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewGetSharpenTexFuncSGIS = (PFNGLGETSHARPENTEXFUNCSGISPROC)glewGetProcAddress("glGetSharpenTexFuncSGIS")) == NULL) || r;
  r = ((glewSharpenTexFuncSGIS = (PFNGLSHARPENTEXFUNCSGISPROC)glewGetProcAddress("glSharpenTexFuncSGIS")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIS_sharpen_texture = GL_FALSE;

#endif /* GL_SGIS_sharpen_texture */

/* --------------------------- GL_SGIS_texture4D --------------------------- */

#ifdef GL_SGIS_texture4D

PFNGLTEXIMAGE4DSGISPROC glewTexImage4DSGIS = NULL;
PFNGLTEXSUBIMAGE4DSGISPROC glewTexSubImage4DSGIS = NULL;

static GLboolean _glewInit_GL_SGIS_texture4D (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewTexImage4DSGIS = (PFNGLTEXIMAGE4DSGISPROC)glewGetProcAddress("glTexImage4DSGIS")) == NULL) || r;
  r = ((glewTexSubImage4DSGIS = (PFNGLTEXSUBIMAGE4DSGISPROC)glewGetProcAddress("glTexSubImage4DSGIS")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIS_texture4D = GL_FALSE;

#endif /* GL_SGIS_texture4D */

/* ---------------------- GL_SGIS_texture_border_clamp --------------------- */

#ifdef GL_SGIS_texture_border_clamp

GLboolean GLEW_SGIS_texture_border_clamp = GL_FALSE;

#endif /* GL_SGIS_texture_border_clamp */

/* ----------------------- GL_SGIS_texture_edge_clamp ---------------------- */

#ifdef GL_SGIS_texture_edge_clamp

GLboolean GLEW_SGIS_texture_edge_clamp = GL_FALSE;

#endif /* GL_SGIS_texture_edge_clamp */

/* ------------------------ GL_SGIS_texture_filter4 ------------------------ */

#ifdef GL_SGIS_texture_filter4

PFNGLGETTEXFILTERFUNCSGISPROC glewGetTexFilterFuncSGIS = NULL;
PFNGLTEXFILTERFUNCSGISPROC glewTexFilterFuncSGIS = NULL;

static GLboolean _glewInit_GL_SGIS_texture_filter4 (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewGetTexFilterFuncSGIS = (PFNGLGETTEXFILTERFUNCSGISPROC)glewGetProcAddress("glGetTexFilterFuncSGIS")) == NULL) || r;
  r = ((glewTexFilterFuncSGIS = (PFNGLTEXFILTERFUNCSGISPROC)glewGetProcAddress("glTexFilterFuncSGIS")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIS_texture_filter4 = GL_FALSE;

#endif /* GL_SGIS_texture_filter4 */

/* -------------------------- GL_SGIS_texture_lod -------------------------- */

#ifdef GL_SGIS_texture_lod

GLboolean GLEW_SGIS_texture_lod = GL_FALSE;

#endif /* GL_SGIS_texture_lod */

/* ------------------------- GL_SGIS_texture_select ------------------------ */

#ifdef GL_SGIS_texture_select

GLboolean GLEW_SGIS_texture_select = GL_FALSE;

#endif /* GL_SGIS_texture_select */

/* ----------------------------- GL_SGIX_async ----------------------------- */

#ifdef GL_SGIX_async

PFNGLASYNCMARKERSGIXPROC glewAsyncMarkerSGIX = NULL;
PFNGLDELETEASYNCMARKERSSGIXPROC glewDeleteAsyncMarkersSGIX = NULL;
PFNGLFINISHASYNCSGIXPROC glewFinishAsyncSGIX = NULL;
PFNGLGENASYNCMARKERSSGIXPROC glewGenAsyncMarkersSGIX = NULL;
PFNGLISASYNCMARKERSGIXPROC glewIsAsyncMarkerSGIX = NULL;
PFNGLPOLLASYNCSGIXPROC glewPollAsyncSGIX = NULL;

static GLboolean _glewInit_GL_SGIX_async (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewAsyncMarkerSGIX = (PFNGLASYNCMARKERSGIXPROC)glewGetProcAddress("glAsyncMarkerSGIX")) == NULL) || r;
  r = ((glewDeleteAsyncMarkersSGIX = (PFNGLDELETEASYNCMARKERSSGIXPROC)glewGetProcAddress("glDeleteAsyncMarkersSGIX")) == NULL) || r;
  r = ((glewFinishAsyncSGIX = (PFNGLFINISHASYNCSGIXPROC)glewGetProcAddress("glFinishAsyncSGIX")) == NULL) || r;
  r = ((glewGenAsyncMarkersSGIX = (PFNGLGENASYNCMARKERSSGIXPROC)glewGetProcAddress("glGenAsyncMarkersSGIX")) == NULL) || r;
  r = ((glewIsAsyncMarkerSGIX = (PFNGLISASYNCMARKERSGIXPROC)glewGetProcAddress("glIsAsyncMarkerSGIX")) == NULL) || r;
  r = ((glewPollAsyncSGIX = (PFNGLPOLLASYNCSGIXPROC)glewGetProcAddress("glPollAsyncSGIX")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIX_async = GL_FALSE;

#endif /* GL_SGIX_async */

/* ------------------------ GL_SGIX_async_histogram ------------------------ */

#ifdef GL_SGIX_async_histogram

GLboolean GLEW_SGIX_async_histogram = GL_FALSE;

#endif /* GL_SGIX_async_histogram */

/* -------------------------- GL_SGIX_async_pixel -------------------------- */

#ifdef GL_SGIX_async_pixel

GLboolean GLEW_SGIX_async_pixel = GL_FALSE;

#endif /* GL_SGIX_async_pixel */

/* ----------------------- GL_SGIX_blend_alpha_minmax ---------------------- */

#ifdef GL_SGIX_blend_alpha_minmax

GLboolean GLEW_SGIX_blend_alpha_minmax = GL_FALSE;

#endif /* GL_SGIX_blend_alpha_minmax */

/* ---------------------------- GL_SGIX_clipmap ---------------------------- */

#ifdef GL_SGIX_clipmap

GLboolean GLEW_SGIX_clipmap = GL_FALSE;

#endif /* GL_SGIX_clipmap */

/* ------------------------- GL_SGIX_depth_texture ------------------------- */

#ifdef GL_SGIX_depth_texture

GLboolean GLEW_SGIX_depth_texture = GL_FALSE;

#endif /* GL_SGIX_depth_texture */

/* -------------------------- GL_SGIX_flush_raster ------------------------- */

#ifdef GL_SGIX_flush_raster

PFNGLFLUSHRASTERSGIXPROC glewFlushRasterSGIX = NULL;

static GLboolean _glewInit_GL_SGIX_flush_raster (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewFlushRasterSGIX = (PFNGLFLUSHRASTERSGIXPROC)glewGetProcAddress("glFlushRasterSGIX")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIX_flush_raster = GL_FALSE;

#endif /* GL_SGIX_flush_raster */

/* --------------------------- GL_SGIX_fog_offset -------------------------- */

#ifdef GL_SGIX_fog_offset

GLboolean GLEW_SGIX_fog_offset = GL_FALSE;

#endif /* GL_SGIX_fog_offset */

/* -------------------------- GL_SGIX_fog_texture -------------------------- */

#ifdef GL_SGIX_fog_texture

PFNGLTEXTUREFOGSGIXPROC glewTextureFogSGIX = NULL;

static GLboolean _glewInit_GL_SGIX_fog_texture (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewTextureFogSGIX = (PFNGLTEXTUREFOGSGIXPROC)glewGetProcAddress("glTextureFogSGIX")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIX_fog_texture = GL_FALSE;

#endif /* GL_SGIX_fog_texture */

/* ------------------- GL_SGIX_fragment_specular_lighting ------------------ */

#ifdef GL_SGIX_fragment_specular_lighting

PFNGLFRAGMENTCOLORMATERIALSGIXPROC glewFragmentColorMaterialSGIX = NULL;
PFNGLFRAGMENTLIGHTMODELFSGIXPROC glewFragmentLightModelfSGIX = NULL;
PFNGLFRAGMENTLIGHTMODELFVSGIXPROC glewFragmentLightModelfvSGIX = NULL;
PFNGLFRAGMENTLIGHTMODELISGIXPROC glewFragmentLightModeliSGIX = NULL;
PFNGLFRAGMENTLIGHTMODELIVSGIXPROC glewFragmentLightModelivSGIX = NULL;
PFNGLFRAGMENTLIGHTFSGIXPROC glewFragmentLightfSGIX = NULL;
PFNGLFRAGMENTLIGHTFVSGIXPROC glewFragmentLightfvSGIX = NULL;
PFNGLFRAGMENTLIGHTISGIXPROC glewFragmentLightiSGIX = NULL;
PFNGLFRAGMENTLIGHTIVSGIXPROC glewFragmentLightivSGIX = NULL;
PFNGLFRAGMENTMATERIALFSGIXPROC glewFragmentMaterialfSGIX = NULL;
PFNGLFRAGMENTMATERIALFVSGIXPROC glewFragmentMaterialfvSGIX = NULL;
PFNGLFRAGMENTMATERIALISGIXPROC glewFragmentMaterialiSGIX = NULL;
PFNGLFRAGMENTMATERIALIVSGIXPROC glewFragmentMaterialivSGIX = NULL;
PFNGLGETFRAGMENTLIGHTFVSGIXPROC glewGetFragmentLightfvSGIX = NULL;
PFNGLGETFRAGMENTLIGHTIVSGIXPROC glewGetFragmentLightivSGIX = NULL;
PFNGLGETFRAGMENTMATERIALFVSGIXPROC glewGetFragmentMaterialfvSGIX = NULL;
PFNGLGETFRAGMENTMATERIALIVSGIXPROC glewGetFragmentMaterialivSGIX = NULL;

static GLboolean _glewInit_GL_SGIX_fragment_specular_lighting (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewFragmentColorMaterialSGIX = (PFNGLFRAGMENTCOLORMATERIALSGIXPROC)glewGetProcAddress("glFragmentColorMaterialSGIX")) == NULL) || r;
  r = ((glewFragmentLightModelfSGIX = (PFNGLFRAGMENTLIGHTMODELFSGIXPROC)glewGetProcAddress("glFragmentLightModelfSGIX")) == NULL) || r;
  r = ((glewFragmentLightModelfvSGIX = (PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)glewGetProcAddress("glFragmentLightModelfvSGIX")) == NULL) || r;
  r = ((glewFragmentLightModeliSGIX = (PFNGLFRAGMENTLIGHTMODELISGIXPROC)glewGetProcAddress("glFragmentLightModeliSGIX")) == NULL) || r;
  r = ((glewFragmentLightModelivSGIX = (PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)glewGetProcAddress("glFragmentLightModelivSGIX")) == NULL) || r;
  r = ((glewFragmentLightfSGIX = (PFNGLFRAGMENTLIGHTFSGIXPROC)glewGetProcAddress("glFragmentLightfSGIX")) == NULL) || r;
  r = ((glewFragmentLightfvSGIX = (PFNGLFRAGMENTLIGHTFVSGIXPROC)glewGetProcAddress("glFragmentLightfvSGIX")) == NULL) || r;
  r = ((glewFragmentLightiSGIX = (PFNGLFRAGMENTLIGHTISGIXPROC)glewGetProcAddress("glFragmentLightiSGIX")) == NULL) || r;
  r = ((glewFragmentLightivSGIX = (PFNGLFRAGMENTLIGHTIVSGIXPROC)glewGetProcAddress("glFragmentLightivSGIX")) == NULL) || r;
  r = ((glewFragmentMaterialfSGIX = (PFNGLFRAGMENTMATERIALFSGIXPROC)glewGetProcAddress("glFragmentMaterialfSGIX")) == NULL) || r;
  r = ((glewFragmentMaterialfvSGIX = (PFNGLFRAGMENTMATERIALFVSGIXPROC)glewGetProcAddress("glFragmentMaterialfvSGIX")) == NULL) || r;
  r = ((glewFragmentMaterialiSGIX = (PFNGLFRAGMENTMATERIALISGIXPROC)glewGetProcAddress("glFragmentMaterialiSGIX")) == NULL) || r;
  r = ((glewFragmentMaterialivSGIX = (PFNGLFRAGMENTMATERIALIVSGIXPROC)glewGetProcAddress("glFragmentMaterialivSGIX")) == NULL) || r;
  r = ((glewGetFragmentLightfvSGIX = (PFNGLGETFRAGMENTLIGHTFVSGIXPROC)glewGetProcAddress("glGetFragmentLightfvSGIX")) == NULL) || r;
  r = ((glewGetFragmentLightivSGIX = (PFNGLGETFRAGMENTLIGHTIVSGIXPROC)glewGetProcAddress("glGetFragmentLightivSGIX")) == NULL) || r;
  r = ((glewGetFragmentMaterialfvSGIX = (PFNGLGETFRAGMENTMATERIALFVSGIXPROC)glewGetProcAddress("glGetFragmentMaterialfvSGIX")) == NULL) || r;
  r = ((glewGetFragmentMaterialivSGIX = (PFNGLGETFRAGMENTMATERIALIVSGIXPROC)glewGetProcAddress("glGetFragmentMaterialivSGIX")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIX_fragment_specular_lighting = GL_FALSE;

#endif /* GL_SGIX_fragment_specular_lighting */

/* --------------------------- GL_SGIX_framezoom --------------------------- */

#ifdef GL_SGIX_framezoom

PFNGLFRAMEZOOMSGIXPROC glewFrameZoomSGIX = NULL;

static GLboolean _glewInit_GL_SGIX_framezoom (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewFrameZoomSGIX = (PFNGLFRAMEZOOMSGIXPROC)glewGetProcAddress("glFrameZoomSGIX")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIX_framezoom = GL_FALSE;

#endif /* GL_SGIX_framezoom */

/* --------------------------- GL_SGIX_interlace --------------------------- */

#ifdef GL_SGIX_interlace

GLboolean GLEW_SGIX_interlace = GL_FALSE;

#endif /* GL_SGIX_interlace */

/* ------------------------- GL_SGIX_ir_instrument1 ------------------------ */

#ifdef GL_SGIX_ir_instrument1

GLboolean GLEW_SGIX_ir_instrument1 = GL_FALSE;

#endif /* GL_SGIX_ir_instrument1 */

/* ------------------------- GL_SGIX_list_priority ------------------------- */

#ifdef GL_SGIX_list_priority

GLboolean GLEW_SGIX_list_priority = GL_FALSE;

#endif /* GL_SGIX_list_priority */

/* ------------------------- GL_SGIX_pixel_texture ------------------------- */

#ifdef GL_SGIX_pixel_texture

PFNGLPIXELTEXGENSGIXPROC glewPixelTexGenSGIX = NULL;

static GLboolean _glewInit_GL_SGIX_pixel_texture (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewPixelTexGenSGIX = (PFNGLPIXELTEXGENSGIXPROC)glewGetProcAddress("glPixelTexGenSGIX")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIX_pixel_texture = GL_FALSE;

#endif /* GL_SGIX_pixel_texture */

/* ----------------------- GL_SGIX_pixel_texture_bits ---------------------- */

#ifdef GL_SGIX_pixel_texture_bits

GLboolean GLEW_SGIX_pixel_texture_bits = GL_FALSE;

#endif /* GL_SGIX_pixel_texture_bits */

/* ------------------------ GL_SGIX_reference_plane ------------------------ */

#ifdef GL_SGIX_reference_plane

PFNGLREFERENCEPLANESGIXPROC glewReferencePlaneSGIX = NULL;

static GLboolean _glewInit_GL_SGIX_reference_plane (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewReferencePlaneSGIX = (PFNGLREFERENCEPLANESGIXPROC)glewGetProcAddress("glReferencePlaneSGIX")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIX_reference_plane = GL_FALSE;

#endif /* GL_SGIX_reference_plane */

/* ---------------------------- GL_SGIX_resample --------------------------- */

#ifdef GL_SGIX_resample

GLboolean GLEW_SGIX_resample = GL_FALSE;

#endif /* GL_SGIX_resample */

/* ----------------------------- GL_SGIX_shadow ---------------------------- */

#ifdef GL_SGIX_shadow

GLboolean GLEW_SGIX_shadow = GL_FALSE;

#endif /* GL_SGIX_shadow */

/* ------------------------- GL_SGIX_shadow_ambient ------------------------ */

#ifdef GL_SGIX_shadow_ambient

GLboolean GLEW_SGIX_shadow_ambient = GL_FALSE;

#endif /* GL_SGIX_shadow_ambient */

/* ----------------------------- GL_SGIX_sprite ---------------------------- */

#ifdef GL_SGIX_sprite

PFNGLSPRITEPARAMETERFSGIXPROC glewSpriteParameterfSGIX = NULL;
PFNGLSPRITEPARAMETERFVSGIXPROC glewSpriteParameterfvSGIX = NULL;
PFNGLSPRITEPARAMETERISGIXPROC glewSpriteParameteriSGIX = NULL;
PFNGLSPRITEPARAMETERIVSGIXPROC glewSpriteParameterivSGIX = NULL;

static GLboolean _glewInit_GL_SGIX_sprite (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewSpriteParameterfSGIX = (PFNGLSPRITEPARAMETERFSGIXPROC)glewGetProcAddress("glSpriteParameterfSGIX")) == NULL) || r;
  r = ((glewSpriteParameterfvSGIX = (PFNGLSPRITEPARAMETERFVSGIXPROC)glewGetProcAddress("glSpriteParameterfvSGIX")) == NULL) || r;
  r = ((glewSpriteParameteriSGIX = (PFNGLSPRITEPARAMETERISGIXPROC)glewGetProcAddress("glSpriteParameteriSGIX")) == NULL) || r;
  r = ((glewSpriteParameterivSGIX = (PFNGLSPRITEPARAMETERIVSGIXPROC)glewGetProcAddress("glSpriteParameterivSGIX")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIX_sprite = GL_FALSE;

#endif /* GL_SGIX_sprite */

/* ----------------------- GL_SGIX_tag_sample_buffer ----------------------- */

#ifdef GL_SGIX_tag_sample_buffer

PFNGLTAGSAMPLEBUFFERSGIXPROC glewTagSampleBufferSGIX = NULL;

static GLboolean _glewInit_GL_SGIX_tag_sample_buffer (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewTagSampleBufferSGIX = (PFNGLTAGSAMPLEBUFFERSGIXPROC)glewGetProcAddress("glTagSampleBufferSGIX")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGIX_tag_sample_buffer = GL_FALSE;

#endif /* GL_SGIX_tag_sample_buffer */

/* ------------------------ GL_SGIX_texture_add_env ------------------------ */

#ifdef GL_SGIX_texture_add_env

GLboolean GLEW_SGIX_texture_add_env = GL_FALSE;

#endif /* GL_SGIX_texture_add_env */

/* -------------------- GL_SGIX_texture_coordinate_clamp ------------------- */

#ifdef GL_SGIX_texture_coordinate_clamp

GLboolean GLEW_SGIX_texture_coordinate_clamp = GL_FALSE;

#endif /* GL_SGIX_texture_coordinate_clamp */

/* ------------------------ GL_SGIX_texture_lod_bias ----------------------- */

#ifdef GL_SGIX_texture_lod_bias

GLboolean GLEW_SGIX_texture_lod_bias = GL_FALSE;

#endif /* GL_SGIX_texture_lod_bias */

/* ---------------------- GL_SGIX_texture_multi_buffer --------------------- */

#ifdef GL_SGIX_texture_multi_buffer

GLboolean GLEW_SGIX_texture_multi_buffer = GL_FALSE;

#endif /* GL_SGIX_texture_multi_buffer */

/* ------------------------- GL_SGIX_texture_range ------------------------- */

#ifdef GL_SGIX_texture_range

GLboolean GLEW_SGIX_texture_range = GL_FALSE;

#endif /* GL_SGIX_texture_range */

/* ----------------------- GL_SGIX_texture_scale_bias ---------------------- */

#ifdef GL_SGIX_texture_scale_bias

GLboolean GLEW_SGIX_texture_scale_bias = GL_FALSE;

#endif /* GL_SGIX_texture_scale_bias */

/* ------------------------- GL_SGIX_vertex_preclip ------------------------ */

#ifdef GL_SGIX_vertex_preclip

GLboolean GLEW_SGIX_vertex_preclip = GL_FALSE;

#endif /* GL_SGIX_vertex_preclip */

/* ---------------------- GL_SGIX_vertex_preclip_hint ---------------------- */

#ifdef GL_SGIX_vertex_preclip_hint

GLboolean GLEW_SGIX_vertex_preclip_hint = GL_FALSE;

#endif /* GL_SGIX_vertex_preclip_hint */

/* ----------------------------- GL_SGIX_ycrcb ----------------------------- */

#ifdef GL_SGIX_ycrcb

GLboolean GLEW_SGIX_ycrcb = GL_FALSE;

#endif /* GL_SGIX_ycrcb */

/* -------------------------- GL_SGI_color_matrix -------------------------- */

#ifdef GL_SGI_color_matrix

GLboolean GLEW_SGI_color_matrix = GL_FALSE;

#endif /* GL_SGI_color_matrix */

/* --------------------------- GL_SGI_color_table -------------------------- */

#ifdef GL_SGI_color_table

PFNGLCOLORTABLEPARAMETERFVSGIPROC glewColorTableParameterfvSGI = NULL;
PFNGLCOLORTABLEPARAMETERIVSGIPROC glewColorTableParameterivSGI = NULL;
PFNGLCOLORTABLESGIPROC glewColorTableSGI = NULL;
PFNGLCOPYCOLORTABLESGIPROC glewCopyColorTableSGI = NULL;
PFNGLGETCOLORTABLEPARAMETERFVSGIPROC glewGetColorTableParameterfvSGI = NULL;
PFNGLGETCOLORTABLEPARAMETERIVSGIPROC glewGetColorTableParameterivSGI = NULL;
PFNGLGETCOLORTABLESGIPROC glewGetColorTableSGI = NULL;

static GLboolean _glewInit_GL_SGI_color_table (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewColorTableParameterfvSGI = (PFNGLCOLORTABLEPARAMETERFVSGIPROC)glewGetProcAddress("glColorTableParameterfvSGI")) == NULL) || r;
  r = ((glewColorTableParameterivSGI = (PFNGLCOLORTABLEPARAMETERIVSGIPROC)glewGetProcAddress("glColorTableParameterivSGI")) == NULL) || r;
  r = ((glewColorTableSGI = (PFNGLCOLORTABLESGIPROC)glewGetProcAddress("glColorTableSGI")) == NULL) || r;
  r = ((glewCopyColorTableSGI = (PFNGLCOPYCOLORTABLESGIPROC)glewGetProcAddress("glCopyColorTableSGI")) == NULL) || r;
  r = ((glewGetColorTableParameterfvSGI = (PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)glewGetProcAddress("glGetColorTableParameterfvSGI")) == NULL) || r;
  r = ((glewGetColorTableParameterivSGI = (PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)glewGetProcAddress("glGetColorTableParameterivSGI")) == NULL) || r;
  r = ((glewGetColorTableSGI = (PFNGLGETCOLORTABLESGIPROC)glewGetProcAddress("glGetColorTableSGI")) == NULL) || r;

  return r;
}

GLboolean GLEW_SGI_color_table = GL_FALSE;

#endif /* GL_SGI_color_table */

/* ----------------------- GL_SGI_texture_color_table ---------------------- */

#ifdef GL_SGI_texture_color_table

GLboolean GLEW_SGI_texture_color_table = GL_FALSE;

#endif /* GL_SGI_texture_color_table */

/* ------------------------- GL_SUNX_constant_data ------------------------- */

#ifdef GL_SUNX_constant_data

PFNGLFINISHTEXTURESUNXPROC glewFinishTextureSUNX = NULL;

static GLboolean _glewInit_GL_SUNX_constant_data (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewFinishTextureSUNX = (PFNGLFINISHTEXTURESUNXPROC)glewGetProcAddress("glFinishTextureSUNX")) == NULL) || r;

  return r;
}

GLboolean GLEW_SUNX_constant_data = GL_FALSE;

#endif /* GL_SUNX_constant_data */

/* -------------------- GL_SUN_convolution_border_modes -------------------- */

#ifdef GL_SUN_convolution_border_modes

GLboolean GLEW_SUN_convolution_border_modes = GL_FALSE;

#endif /* GL_SUN_convolution_border_modes */

/* -------------------------- GL_SUN_global_alpha -------------------------- */

#ifdef GL_SUN_global_alpha

PFNGLGLOBALALPHAFACTORBSUNPROC glewGlobalAlphaFactorbSUN = NULL;
PFNGLGLOBALALPHAFACTORDSUNPROC glewGlobalAlphaFactordSUN = NULL;
PFNGLGLOBALALPHAFACTORFSUNPROC glewGlobalAlphaFactorfSUN = NULL;
PFNGLGLOBALALPHAFACTORISUNPROC glewGlobalAlphaFactoriSUN = NULL;
PFNGLGLOBALALPHAFACTORSSUNPROC glewGlobalAlphaFactorsSUN = NULL;
PFNGLGLOBALALPHAFACTORUBSUNPROC glewGlobalAlphaFactorubSUN = NULL;
PFNGLGLOBALALPHAFACTORUISUNPROC glewGlobalAlphaFactoruiSUN = NULL;
PFNGLGLOBALALPHAFACTORUSSUNPROC glewGlobalAlphaFactorusSUN = NULL;

static GLboolean _glewInit_GL_SUN_global_alpha (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewGlobalAlphaFactorbSUN = (PFNGLGLOBALALPHAFACTORBSUNPROC)glewGetProcAddress("glGlobalAlphaFactorbSUN")) == NULL) || r;
  r = ((glewGlobalAlphaFactordSUN = (PFNGLGLOBALALPHAFACTORDSUNPROC)glewGetProcAddress("glGlobalAlphaFactordSUN")) == NULL) || r;
  r = ((glewGlobalAlphaFactorfSUN = (PFNGLGLOBALALPHAFACTORFSUNPROC)glewGetProcAddress("glGlobalAlphaFactorfSUN")) == NULL) || r;
  r = ((glewGlobalAlphaFactoriSUN = (PFNGLGLOBALALPHAFACTORISUNPROC)glewGetProcAddress("glGlobalAlphaFactoriSUN")) == NULL) || r;
  r = ((glewGlobalAlphaFactorsSUN = (PFNGLGLOBALALPHAFACTORSSUNPROC)glewGetProcAddress("glGlobalAlphaFactorsSUN")) == NULL) || r;
  r = ((glewGlobalAlphaFactorubSUN = (PFNGLGLOBALALPHAFACTORUBSUNPROC)glewGetProcAddress("glGlobalAlphaFactorubSUN")) == NULL) || r;
  r = ((glewGlobalAlphaFactoruiSUN = (PFNGLGLOBALALPHAFACTORUISUNPROC)glewGetProcAddress("glGlobalAlphaFactoruiSUN")) == NULL) || r;
  r = ((glewGlobalAlphaFactorusSUN = (PFNGLGLOBALALPHAFACTORUSSUNPROC)glewGetProcAddress("glGlobalAlphaFactorusSUN")) == NULL) || r;

  return r;
}

GLboolean GLEW_SUN_global_alpha = GL_FALSE;

#endif /* GL_SUN_global_alpha */

/* --------------------------- GL_SUN_mesh_array --------------------------- */

#ifdef GL_SUN_mesh_array

GLboolean GLEW_SUN_mesh_array = GL_FALSE;

#endif /* GL_SUN_mesh_array */

/* --------------------------- GL_SUN_slice_accum -------------------------- */

#ifdef GL_SUN_slice_accum

GLboolean GLEW_SUN_slice_accum = GL_FALSE;

#endif /* GL_SUN_slice_accum */

/* -------------------------- GL_SUN_triangle_list ------------------------- */

#ifdef GL_SUN_triangle_list

PFNGLREPLACEMENTCODEPOINTERSUNPROC glewReplacementCodePointerSUN = NULL;
PFNGLREPLACEMENTCODEUBSUNPROC glewReplacementCodeubSUN = NULL;
PFNGLREPLACEMENTCODEUBVSUNPROC glewReplacementCodeubvSUN = NULL;
PFNGLREPLACEMENTCODEUISUNPROC glewReplacementCodeuiSUN = NULL;
PFNGLREPLACEMENTCODEUIVSUNPROC glewReplacementCodeuivSUN = NULL;
PFNGLREPLACEMENTCODEUSSUNPROC glewReplacementCodeusSUN = NULL;
PFNGLREPLACEMENTCODEUSVSUNPROC glewReplacementCodeusvSUN = NULL;

static GLboolean _glewInit_GL_SUN_triangle_list (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewReplacementCodePointerSUN = (PFNGLREPLACEMENTCODEPOINTERSUNPROC)glewGetProcAddress("glReplacementCodePointerSUN")) == NULL) || r;
  r = ((glewReplacementCodeubSUN = (PFNGLREPLACEMENTCODEUBSUNPROC)glewGetProcAddress("glReplacementCodeubSUN")) == NULL) || r;
  r = ((glewReplacementCodeubvSUN = (PFNGLREPLACEMENTCODEUBVSUNPROC)glewGetProcAddress("glReplacementCodeubvSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiSUN = (PFNGLREPLACEMENTCODEUISUNPROC)glewGetProcAddress("glReplacementCodeuiSUN")) == NULL) || r;
  r = ((glewReplacementCodeuivSUN = (PFNGLREPLACEMENTCODEUIVSUNPROC)glewGetProcAddress("glReplacementCodeuivSUN")) == NULL) || r;
  r = ((glewReplacementCodeusSUN = (PFNGLREPLACEMENTCODEUSSUNPROC)glewGetProcAddress("glReplacementCodeusSUN")) == NULL) || r;
  r = ((glewReplacementCodeusvSUN = (PFNGLREPLACEMENTCODEUSVSUNPROC)glewGetProcAddress("glReplacementCodeusvSUN")) == NULL) || r;

  return r;
}

GLboolean GLEW_SUN_triangle_list = GL_FALSE;

#endif /* GL_SUN_triangle_list */

/* ----------------------------- GL_SUN_vertex ----------------------------- */

#ifdef GL_SUN_vertex

PFNGLCOLOR3FVERTEX3FSUNPROC glewColor3fVertex3fSUN = NULL;
PFNGLCOLOR3FVERTEX3FVSUNPROC glewColor3fVertex3fvSUN = NULL;
PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC glewColor4fNormal3fVertex3fSUN = NULL;
PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC glewColor4fNormal3fVertex3fvSUN = NULL;
PFNGLCOLOR4UBVERTEX2FSUNPROC glewColor4ubVertex2fSUN = NULL;
PFNGLCOLOR4UBVERTEX2FVSUNPROC glewColor4ubVertex2fvSUN = NULL;
PFNGLCOLOR4UBVERTEX3FSUNPROC glewColor4ubVertex3fSUN = NULL;
PFNGLCOLOR4UBVERTEX3FVSUNPROC glewColor4ubVertex3fvSUN = NULL;
PFNGLNORMAL3FVERTEX3FSUNPROC glewNormal3fVertex3fSUN = NULL;
PFNGLNORMAL3FVERTEX3FVSUNPROC glewNormal3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC glewReplacementCodeuiColor3fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC glewReplacementCodeuiColor3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC glewReplacementCodeuiColor4fNormal3fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC glewReplacementCodeuiColor4fNormal3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC glewReplacementCodeuiColor4ubVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC glewReplacementCodeuiColor4ubVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC glewReplacementCodeuiNormal3fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC glewReplacementCodeuiNormal3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glewReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glewReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC glewReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glewReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC glewReplacementCodeuiTexCoord2fVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC glewReplacementCodeuiTexCoord2fVertex3fvSUN = NULL;
PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC glewReplacementCodeuiVertex3fSUN = NULL;
PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC glewReplacementCodeuiVertex3fvSUN = NULL;
PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC glewTexCoord2fColor3fVertex3fSUN = NULL;
PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC glewTexCoord2fColor3fVertex3fvSUN = NULL;
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glewTexCoord2fColor4fNormal3fVertex3fSUN = NULL;
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glewTexCoord2fColor4fNormal3fVertex3fvSUN = NULL;
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC glewTexCoord2fColor4ubVertex3fSUN = NULL;
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC glewTexCoord2fColor4ubVertex3fvSUN = NULL;
PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC glewTexCoord2fNormal3fVertex3fSUN = NULL;
PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glewTexCoord2fNormal3fVertex3fvSUN = NULL;
PFNGLTEXCOORD2FVERTEX3FSUNPROC glewTexCoord2fVertex3fSUN = NULL;
PFNGLTEXCOORD2FVERTEX3FVSUNPROC glewTexCoord2fVertex3fvSUN = NULL;
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC glewTexCoord4fColor4fNormal3fVertex4fSUN = NULL;
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC glewTexCoord4fColor4fNormal3fVertex4fvSUN = NULL;
PFNGLTEXCOORD4FVERTEX4FSUNPROC glewTexCoord4fVertex4fSUN = NULL;
PFNGLTEXCOORD4FVERTEX4FVSUNPROC glewTexCoord4fVertex4fvSUN = NULL;

static GLboolean _glewInit_GL_SUN_vertex (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewColor3fVertex3fSUN = (PFNGLCOLOR3FVERTEX3FSUNPROC)glewGetProcAddress("glColor3fVertex3fSUN")) == NULL) || r;
  r = ((glewColor3fVertex3fvSUN = (PFNGLCOLOR3FVERTEX3FVSUNPROC)glewGetProcAddress("glColor3fVertex3fvSUN")) == NULL) || r;
  r = ((glewColor4fNormal3fVertex3fSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)glewGetProcAddress("glColor4fNormal3fVertex3fSUN")) == NULL) || r;
  r = ((glewColor4fNormal3fVertex3fvSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)glewGetProcAddress("glColor4fNormal3fVertex3fvSUN")) == NULL) || r;
  r = ((glewColor4ubVertex2fSUN = (PFNGLCOLOR4UBVERTEX2FSUNPROC)glewGetProcAddress("glColor4ubVertex2fSUN")) == NULL) || r;
  r = ((glewColor4ubVertex2fvSUN = (PFNGLCOLOR4UBVERTEX2FVSUNPROC)glewGetProcAddress("glColor4ubVertex2fvSUN")) == NULL) || r;
  r = ((glewColor4ubVertex3fSUN = (PFNGLCOLOR4UBVERTEX3FSUNPROC)glewGetProcAddress("glColor4ubVertex3fSUN")) == NULL) || r;
  r = ((glewColor4ubVertex3fvSUN = (PFNGLCOLOR4UBVERTEX3FVSUNPROC)glewGetProcAddress("glColor4ubVertex3fvSUN")) == NULL) || r;
  r = ((glewNormal3fVertex3fSUN = (PFNGLNORMAL3FVERTEX3FSUNPROC)glewGetProcAddress("glNormal3fVertex3fSUN")) == NULL) || r;
  r = ((glewNormal3fVertex3fvSUN = (PFNGLNORMAL3FVERTEX3FVSUNPROC)glewGetProcAddress("glNormal3fVertex3fvSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiColor3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)glewGetProcAddress("glReplacementCodeuiColor3fVertex3fSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiColor3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)glewGetProcAddress("glReplacementCodeuiColor3fVertex3fvSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)glewGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)glewGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fvSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiColor4ubVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)glewGetProcAddress("glReplacementCodeuiColor4ubVertex3fSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiColor4ubVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)glewGetProcAddress("glReplacementCodeuiColor4ubVertex3fvSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)glewGetProcAddress("glReplacementCodeuiNormal3fVertex3fSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)glewGetProcAddress("glReplacementCodeuiNormal3fVertex3fvSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)glewGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)glewGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)glewGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)glewGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiTexCoord2fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)glewGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiTexCoord2fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)glewGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fvSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiVertex3fSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)glewGetProcAddress("glReplacementCodeuiVertex3fSUN")) == NULL) || r;
  r = ((glewReplacementCodeuiVertex3fvSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)glewGetProcAddress("glReplacementCodeuiVertex3fvSUN")) == NULL) || r;
  r = ((glewTexCoord2fColor3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)glewGetProcAddress("glTexCoord2fColor3fVertex3fSUN")) == NULL) || r;
  r = ((glewTexCoord2fColor3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)glewGetProcAddress("glTexCoord2fColor3fVertex3fvSUN")) == NULL) || r;
  r = ((glewTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)glewGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fSUN")) == NULL) || r;
  r = ((glewTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)glewGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fvSUN")) == NULL) || r;
  r = ((glewTexCoord2fColor4ubVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)glewGetProcAddress("glTexCoord2fColor4ubVertex3fSUN")) == NULL) || r;
  r = ((glewTexCoord2fColor4ubVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)glewGetProcAddress("glTexCoord2fColor4ubVertex3fvSUN")) == NULL) || r;
  r = ((glewTexCoord2fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)glewGetProcAddress("glTexCoord2fNormal3fVertex3fSUN")) == NULL) || r;
  r = ((glewTexCoord2fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)glewGetProcAddress("glTexCoord2fNormal3fVertex3fvSUN")) == NULL) || r;
  r = ((glewTexCoord2fVertex3fSUN = (PFNGLTEXCOORD2FVERTEX3FSUNPROC)glewGetProcAddress("glTexCoord2fVertex3fSUN")) == NULL) || r;
  r = ((glewTexCoord2fVertex3fvSUN = (PFNGLTEXCOORD2FVERTEX3FVSUNPROC)glewGetProcAddress("glTexCoord2fVertex3fvSUN")) == NULL) || r;
  r = ((glewTexCoord4fColor4fNormal3fVertex4fSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)glewGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fSUN")) == NULL) || r;
  r = ((glewTexCoord4fColor4fNormal3fVertex4fvSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)glewGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fvSUN")) == NULL) || r;
  r = ((glewTexCoord4fVertex4fSUN = (PFNGLTEXCOORD4FVERTEX4FSUNPROC)glewGetProcAddress("glTexCoord4fVertex4fSUN")) == NULL) || r;
  r = ((glewTexCoord4fVertex4fvSUN = (PFNGLTEXCOORD4FVERTEX4FVSUNPROC)glewGetProcAddress("glTexCoord4fVertex4fvSUN")) == NULL) || r;

  return r;
}

GLboolean GLEW_SUN_vertex = GL_FALSE;

#endif /* GL_SUN_vertex */

/* -------------------------- GL_WIN_phong_shading ------------------------- */

#ifdef GL_WIN_phong_shading

GLboolean GLEW_WIN_phong_shading = GL_FALSE;

#endif /* GL_WIN_phong_shading */

/* -------------------------- GL_WIN_specular_fog -------------------------- */

#ifdef GL_WIN_specular_fog

GLboolean GLEW_WIN_specular_fog = GL_FALSE;

#endif /* GL_WIN_specular_fog */

/* ---------------------------- GL_WIN_swap_hint --------------------------- */

#ifdef GL_WIN_swap_hint

PFNGLADDSWAPHINTRECTWINPROC glewAddSwapHintRectWin = NULL;

static GLboolean _glewInit_GL_WIN_swap_hint (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewAddSwapHintRectWin = (PFNGLADDSWAPHINTRECTWINPROC)glewGetProcAddress("glAddSwapHintRectWin")) == NULL) || r;

  return r;
}

GLboolean GLEW_WIN_swap_hint = GL_FALSE;

#endif /* GL_WIN_swap_hint */

#ifdef _WIN32

/* -------------------------- WGL_3DFX_multisample ------------------------- */

#ifdef WGL_3DFX_multisample

GLboolean WGLEW_3DFX_multisample = GL_FALSE;

#endif /* WGL_3DFX_multisample */

/* ------------------------- WGL_ARB_buffer_region ------------------------- */

#ifdef WGL_ARB_buffer_region

PFNWGLCREATEBUFFERREGIONARBPROC wglewCreateBufferRegionARB = NULL;
PFNWGLDELETEBUFFERREGIONARBPROC wglewDeleteBufferRegionARB = NULL;
PFNWGLRESTOREBUFFERREGIONARBPROC wglewRestoreBufferRegionARB = NULL;
PFNWGLSAVEBUFFERREGIONARBPROC wglewSaveBufferRegionARB = NULL;

static GLboolean _glewInit_WGL_ARB_buffer_region (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewCreateBufferRegionARB = (PFNWGLCREATEBUFFERREGIONARBPROC)glewGetProcAddress("wglCreateBufferRegionARB")) == NULL) || r;
  r = ((wglewDeleteBufferRegionARB = (PFNWGLDELETEBUFFERREGIONARBPROC)glewGetProcAddress("wglDeleteBufferRegionARB")) == NULL) || r;
  r = ((wglewRestoreBufferRegionARB = (PFNWGLRESTOREBUFFERREGIONARBPROC)glewGetProcAddress("wglRestoreBufferRegionARB")) == NULL) || r;
  r = ((wglewSaveBufferRegionARB = (PFNWGLSAVEBUFFERREGIONARBPROC)glewGetProcAddress("wglSaveBufferRegionARB")) == NULL) || r;

  return r;
}

GLboolean WGLEW_ARB_buffer_region = GL_FALSE;

#endif /* WGL_ARB_buffer_region */

/* ----------------------- WGL_ARB_extensions_string ----------------------- */

#ifdef WGL_ARB_extensions_string

PFNWGLGETEXTENSIONSSTRINGARBPROC wglewGetExtensionsStringARB = NULL;

static GLboolean _glewInit_WGL_ARB_extensions_string (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)glewGetProcAddress("wglGetExtensionsStringARB")) == NULL) || r;

  return r;
}

GLboolean WGLEW_ARB_extensions_string = GL_FALSE;

#endif /* WGL_ARB_extensions_string */

/* ----------------------- WGL_ARB_make_current_read ----------------------- */

#ifdef WGL_ARB_make_current_read

PFNWGLGETCURRENTREADDCARBPROC wglewGetCurrentReadDCARB = NULL;
PFNWGLMAKECONTEXTCURRENTARBPROC wglewMakeContextCurrentARB = NULL;

static GLboolean _glewInit_WGL_ARB_make_current_read (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewGetCurrentReadDCARB = (PFNWGLGETCURRENTREADDCARBPROC)glewGetProcAddress("wglGetCurrentReadDCARB")) == NULL) || r;
  r = ((wglewMakeContextCurrentARB = (PFNWGLMAKECONTEXTCURRENTARBPROC)glewGetProcAddress("wglMakeContextCurrentARB")) == NULL) || r;

  return r;
}

GLboolean WGLEW_ARB_make_current_read = GL_FALSE;

#endif /* WGL_ARB_make_current_read */

/* -------------------------- WGL_ARB_multisample -------------------------- */

#ifdef WGL_ARB_multisample

GLboolean WGLEW_ARB_multisample = GL_FALSE;

#endif /* WGL_ARB_multisample */

/* ---------------------------- WGL_ARB_pbuffer ---------------------------- */

#ifdef WGL_ARB_pbuffer

PFNWGLCREATEPBUFFERARBPROC wglewCreatePbufferARB = NULL;
PFNWGLDESTROYPBUFFERARBPROC wglewDestroyPbufferARB = NULL;
PFNWGLGETPBUFFERDCARBPROC wglewGetPbufferDCARB = NULL;
PFNWGLQUERYPBUFFERARBPROC wglewQueryPbufferARB = NULL;
PFNWGLRELEASEPBUFFERDCARBPROC wglewReleasePbufferDCARB = NULL;

static GLboolean _glewInit_WGL_ARB_pbuffer (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewCreatePbufferARB = (PFNWGLCREATEPBUFFERARBPROC)glewGetProcAddress("wglCreatePbufferARB")) == NULL) || r;
  r = ((wglewDestroyPbufferARB = (PFNWGLDESTROYPBUFFERARBPROC)glewGetProcAddress("wglDestroyPbufferARB")) == NULL) || r;
  r = ((wglewGetPbufferDCARB = (PFNWGLGETPBUFFERDCARBPROC)glewGetProcAddress("wglGetPbufferDCARB")) == NULL) || r;
  r = ((wglewQueryPbufferARB = (PFNWGLQUERYPBUFFERARBPROC)glewGetProcAddress("wglQueryPbufferARB")) == NULL) || r;
  r = ((wglewReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARBPROC)glewGetProcAddress("wglReleasePbufferDCARB")) == NULL) || r;

  return r;
}

GLboolean WGLEW_ARB_pbuffer = GL_FALSE;

#endif /* WGL_ARB_pbuffer */

/* -------------------------- WGL_ARB_pixel_format ------------------------- */

#ifdef WGL_ARB_pixel_format

PFNWGLCHOOSEPIXELFORMATARBPROC wglewChoosePixelFormatARB = NULL;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglewGetPixelFormatAttribfvARB = NULL;
PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglewGetPixelFormatAttribivARB = NULL;

static GLboolean _glewInit_WGL_ARB_pixel_format (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)glewGetProcAddress("wglChoosePixelFormatARB")) == NULL) || r;
  r = ((wglewGetPixelFormatAttribfvARB = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC)glewGetProcAddress("wglGetPixelFormatAttribfvARB")) == NULL) || r;
  r = ((wglewGetPixelFormatAttribivARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC)glewGetProcAddress("wglGetPixelFormatAttribivARB")) == NULL) || r;

  return r;
}

GLboolean WGLEW_ARB_pixel_format = GL_FALSE;

#endif /* WGL_ARB_pixel_format */

/* ------------------------- WGL_ARB_render_texture ------------------------ */

#ifdef WGL_ARB_render_texture

PFNWGLBINDTEXIMAGEARBPROC wglewBindTexImageARB = NULL;
PFNWGLRELEASETEXIMAGEARBPROC wglewReleaseTexImageARB = NULL;
PFNWGLSETPBUFFERATTRIBARBPROC wglewSetPbufferAttribARB = NULL;

static GLboolean _glewInit_WGL_ARB_render_texture (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewBindTexImageARB = (PFNWGLBINDTEXIMAGEARBPROC)glewGetProcAddress("wglBindTexImageARB")) == NULL) || r;
  r = ((wglewReleaseTexImageARB = (PFNWGLRELEASETEXIMAGEARBPROC)glewGetProcAddress("wglReleaseTexImageARB")) == NULL) || r;
  r = ((wglewSetPbufferAttribARB = (PFNWGLSETPBUFFERATTRIBARBPROC)glewGetProcAddress("wglSetPbufferAttribARB")) == NULL) || r;

  return r;
}

GLboolean WGLEW_ARB_render_texture = GL_FALSE;

#endif /* WGL_ARB_render_texture */

/* ----------------------- WGL_ATI_pixel_format_float ---------------------- */

#ifdef WGL_ATI_pixel_format_float

GLboolean WGLEW_ATI_pixel_format_float = GL_FALSE;

#endif /* WGL_ATI_pixel_format_float */

/* -------------------------- WGL_EXT_depth_float -------------------------- */

#ifdef WGL_EXT_depth_float

GLboolean WGLEW_EXT_depth_float = GL_FALSE;

#endif /* WGL_EXT_depth_float */

/* ---------------------- WGL_EXT_display_color_table ---------------------- */

#ifdef WGL_EXT_display_color_table

PFNWGLBINDDISPLAYCOLORTABLEEXTPROC wglewBindDisplayColorTableEXT = NULL;
PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC wglewCreateDisplayColorTableEXT = NULL;
PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC wglewDestroyDisplayColorTableEXT = NULL;
PFNWGLLOADDISPLAYCOLORTABLEEXTPROC wglewLoadDisplayColorTableEXT = NULL;

static GLboolean _glewInit_WGL_EXT_display_color_table (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewBindDisplayColorTableEXT = (PFNWGLBINDDISPLAYCOLORTABLEEXTPROC)glewGetProcAddress("wglBindDisplayColorTableEXT")) == NULL) || r;
  r = ((wglewCreateDisplayColorTableEXT = (PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC)glewGetProcAddress("wglCreateDisplayColorTableEXT")) == NULL) || r;
  r = ((wglewDestroyDisplayColorTableEXT = (PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC)glewGetProcAddress("wglDestroyDisplayColorTableEXT")) == NULL) || r;
  r = ((wglewLoadDisplayColorTableEXT = (PFNWGLLOADDISPLAYCOLORTABLEEXTPROC)glewGetProcAddress("wglLoadDisplayColorTableEXT")) == NULL) || r;

  return r;
}

GLboolean WGLEW_EXT_display_color_table = GL_FALSE;

#endif /* WGL_EXT_display_color_table */

/* ----------------------- WGL_EXT_extensions_string ----------------------- */

#ifdef WGL_EXT_extensions_string

PFNWGLGETEXTENSIONSSTRINGEXTPROC wglewGetExtensionsStringEXT = NULL;

static GLboolean _glewInit_WGL_EXT_extensions_string (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)glewGetProcAddress("wglGetExtensionsStringEXT")) == NULL) || r;

  return r;
}

GLboolean WGLEW_EXT_extensions_string = GL_FALSE;

#endif /* WGL_EXT_extensions_string */

/* ----------------------- WGL_EXT_make_current_read ----------------------- */

#ifdef WGL_EXT_make_current_read

PFNWGLGETCURRENTREADDCEXTPROC wglewGetCurrentReadDCEXT = NULL;
PFNWGLMAKECONTEXTCURRENTEXTPROC wglewMakeContextCurrentEXT = NULL;

static GLboolean _glewInit_WGL_EXT_make_current_read (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewGetCurrentReadDCEXT = (PFNWGLGETCURRENTREADDCEXTPROC)glewGetProcAddress("wglGetCurrentReadDCEXT")) == NULL) || r;
  r = ((wglewMakeContextCurrentEXT = (PFNWGLMAKECONTEXTCURRENTEXTPROC)glewGetProcAddress("wglMakeContextCurrentEXT")) == NULL) || r;

  return r;
}

GLboolean WGLEW_EXT_make_current_read = GL_FALSE;

#endif /* WGL_EXT_make_current_read */

/* -------------------------- WGL_EXT_multisample -------------------------- */

#ifdef WGL_EXT_multisample

GLboolean WGLEW_EXT_multisample = GL_FALSE;

#endif /* WGL_EXT_multisample */

/* ---------------------------- WGL_EXT_pbuffer ---------------------------- */

#ifdef WGL_EXT_pbuffer

PFNWGLCREATEPBUFFEREXTPROC wglewCreatePbufferEXT = NULL;
PFNWGLDESTROYPBUFFEREXTPROC wglewDestroyPbufferEXT = NULL;
PFNWGLGETPBUFFERDCEXTPROC wglewGetPbufferDCEXT = NULL;
PFNWGLQUERYPBUFFEREXTPROC wglewQueryPbufferEXT = NULL;
PFNWGLRELEASEPBUFFERDCEXTPROC wglewReleasePbufferDCEXT = NULL;

static GLboolean _glewInit_WGL_EXT_pbuffer (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewCreatePbufferEXT = (PFNWGLCREATEPBUFFEREXTPROC)glewGetProcAddress("wglCreatePbufferEXT")) == NULL) || r;
  r = ((wglewDestroyPbufferEXT = (PFNWGLDESTROYPBUFFEREXTPROC)glewGetProcAddress("wglDestroyPbufferEXT")) == NULL) || r;
  r = ((wglewGetPbufferDCEXT = (PFNWGLGETPBUFFERDCEXTPROC)glewGetProcAddress("wglGetPbufferDCEXT")) == NULL) || r;
  r = ((wglewQueryPbufferEXT = (PFNWGLQUERYPBUFFEREXTPROC)glewGetProcAddress("wglQueryPbufferEXT")) == NULL) || r;
  r = ((wglewReleasePbufferDCEXT = (PFNWGLRELEASEPBUFFERDCEXTPROC)glewGetProcAddress("wglReleasePbufferDCEXT")) == NULL) || r;

  return r;
}

GLboolean WGLEW_EXT_pbuffer = GL_FALSE;

#endif /* WGL_EXT_pbuffer */

/* -------------------------- WGL_EXT_pixel_format ------------------------- */

#ifdef WGL_EXT_pixel_format

PFNWGLCHOOSEPIXELFORMATEXTPROC wglewChoosePixelFormatEXT = NULL;
PFNWGLGETPIXELFORMATATTRIBFVEXTPROC wglewGetPixelFormatAttribfvEXT = NULL;
PFNWGLGETPIXELFORMATATTRIBIVEXTPROC wglewGetPixelFormatAttribivEXT = NULL;

static GLboolean _glewInit_WGL_EXT_pixel_format (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewChoosePixelFormatEXT = (PFNWGLCHOOSEPIXELFORMATEXTPROC)glewGetProcAddress("wglChoosePixelFormatEXT")) == NULL) || r;
  r = ((wglewGetPixelFormatAttribfvEXT = (PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)glewGetProcAddress("wglGetPixelFormatAttribfvEXT")) == NULL) || r;
  r = ((wglewGetPixelFormatAttribivEXT = (PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)glewGetProcAddress("wglGetPixelFormatAttribivEXT")) == NULL) || r;

  return r;
}

GLboolean WGLEW_EXT_pixel_format = GL_FALSE;

#endif /* WGL_EXT_pixel_format */

/* -------------------------- WGL_EXT_swap_control ------------------------- */

#ifdef WGL_EXT_swap_control

PFNWGLGETSWAPINTERVALEXTPROC wglewGetSwapIntervalEXT = NULL;
PFNWGLSWAPINTERVALEXTPROC wglewSwapIntervalEXT = NULL;

static GLboolean _glewInit_WGL_EXT_swap_control (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)glewGetProcAddress("wglGetSwapIntervalEXT")) == NULL) || r;
  r = ((wglewSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)glewGetProcAddress("wglSwapIntervalEXT")) == NULL) || r;

  return r;
}

GLboolean WGLEW_EXT_swap_control = GL_FALSE;

#endif /* WGL_EXT_swap_control */

/* --------------------- WGL_I3D_digital_video_control --------------------- */

#ifdef WGL_I3D_digital_video_control

PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC wglewGetDigitalVideoParametersI3D = NULL;
PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC wglewSetDigitalVideoParametersI3D = NULL;

static GLboolean _glewInit_WGL_I3D_digital_video_control (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewGetDigitalVideoParametersI3D = (PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)glewGetProcAddress("wglGetDigitalVideoParametersI3D")) == NULL) || r;
  r = ((wglewSetDigitalVideoParametersI3D = (PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)glewGetProcAddress("wglSetDigitalVideoParametersI3D")) == NULL) || r;

  return r;
}

GLboolean WGLEW_I3D_digital_video_control = GL_FALSE;

#endif /* WGL_I3D_digital_video_control */

/* ----------------------------- WGL_I3D_gamma ----------------------------- */

#ifdef WGL_I3D_gamma

PFNWGLGETGAMMATABLEI3DPROC wglewGetGammaTableI3D = NULL;
PFNWGLGETGAMMATABLEPARAMETERSI3DPROC wglewGetGammaTableParametersI3D = NULL;
PFNWGLSETGAMMATABLEI3DPROC wglewSetGammaTableI3D = NULL;
PFNWGLSETGAMMATABLEPARAMETERSI3DPROC wglewSetGammaTableParametersI3D = NULL;

static GLboolean _glewInit_WGL_I3D_gamma (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewGetGammaTableI3D = (PFNWGLGETGAMMATABLEI3DPROC)glewGetProcAddress("wglGetGammaTableI3D")) == NULL) || r;
  r = ((wglewGetGammaTableParametersI3D = (PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)glewGetProcAddress("wglGetGammaTableParametersI3D")) == NULL) || r;
  r = ((wglewSetGammaTableI3D = (PFNWGLSETGAMMATABLEI3DPROC)glewGetProcAddress("wglSetGammaTableI3D")) == NULL) || r;
  r = ((wglewSetGammaTableParametersI3D = (PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)glewGetProcAddress("wglSetGammaTableParametersI3D")) == NULL) || r;

  return r;
}

GLboolean WGLEW_I3D_gamma = GL_FALSE;

#endif /* WGL_I3D_gamma */

/* ---------------------------- WGL_I3D_genlock ---------------------------- */

#ifdef WGL_I3D_genlock

PFNWGLDISABLEGENLOCKI3DPROC wglewDisableGenlockI3D = NULL;
PFNWGLENABLEGENLOCKI3DPROC wglewEnableGenlockI3D = NULL;
PFNWGLGENLOCKSAMPLERATEI3DPROC wglewGenlockSampleRateI3D = NULL;
PFNWGLGENLOCKSOURCEDELAYI3DPROC wglewGenlockSourceDelayI3D = NULL;
PFNWGLGENLOCKSOURCEEDGEI3DPROC wglewGenlockSourceEdgeI3D = NULL;
PFNWGLGENLOCKSOURCEI3DPROC wglewGenlockSourceI3D = NULL;
PFNWGLGETGENLOCKSAMPLERATEI3DPROC wglewGetGenlockSampleRateI3D = NULL;
PFNWGLGETGENLOCKSOURCEDELAYI3DPROC wglewGetGenlockSourceDelayI3D = NULL;
PFNWGLGETGENLOCKSOURCEEDGEI3DPROC wglewGetGenlockSourceEdgeI3D = NULL;
PFNWGLGETGENLOCKSOURCEI3DPROC wglewGetGenlockSourceI3D = NULL;
PFNWGLISENABLEDGENLOCKI3DPROC wglewIsEnabledGenlockI3D = NULL;
PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC wglewQueryGenlockMaxSourceDelayI3D = NULL;

static GLboolean _glewInit_WGL_I3D_genlock (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewDisableGenlockI3D = (PFNWGLDISABLEGENLOCKI3DPROC)glewGetProcAddress("wglDisableGenlockI3D")) == NULL) || r;
  r = ((wglewEnableGenlockI3D = (PFNWGLENABLEGENLOCKI3DPROC)glewGetProcAddress("wglEnableGenlockI3D")) == NULL) || r;
  r = ((wglewGenlockSampleRateI3D = (PFNWGLGENLOCKSAMPLERATEI3DPROC)glewGetProcAddress("wglGenlockSampleRateI3D")) == NULL) || r;
  r = ((wglewGenlockSourceDelayI3D = (PFNWGLGENLOCKSOURCEDELAYI3DPROC)glewGetProcAddress("wglGenlockSourceDelayI3D")) == NULL) || r;
  r = ((wglewGenlockSourceEdgeI3D = (PFNWGLGENLOCKSOURCEEDGEI3DPROC)glewGetProcAddress("wglGenlockSourceEdgeI3D")) == NULL) || r;
  r = ((wglewGenlockSourceI3D = (PFNWGLGENLOCKSOURCEI3DPROC)glewGetProcAddress("wglGenlockSourceI3D")) == NULL) || r;
  r = ((wglewGetGenlockSampleRateI3D = (PFNWGLGETGENLOCKSAMPLERATEI3DPROC)glewGetProcAddress("wglGetGenlockSampleRateI3D")) == NULL) || r;
  r = ((wglewGetGenlockSourceDelayI3D = (PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)glewGetProcAddress("wglGetGenlockSourceDelayI3D")) == NULL) || r;
  r = ((wglewGetGenlockSourceEdgeI3D = (PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)glewGetProcAddress("wglGetGenlockSourceEdgeI3D")) == NULL) || r;
  r = ((wglewGetGenlockSourceI3D = (PFNWGLGETGENLOCKSOURCEI3DPROC)glewGetProcAddress("wglGetGenlockSourceI3D")) == NULL) || r;
  r = ((wglewIsEnabledGenlockI3D = (PFNWGLISENABLEDGENLOCKI3DPROC)glewGetProcAddress("wglIsEnabledGenlockI3D")) == NULL) || r;
  r = ((wglewQueryGenlockMaxSourceDelayI3D = (PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)glewGetProcAddress("wglQueryGenlockMaxSourceDelayI3D")) == NULL) || r;

  return r;
}

GLboolean WGLEW_I3D_genlock = GL_FALSE;

#endif /* WGL_I3D_genlock */

/* -------------------------- WGL_I3D_image_buffer ------------------------- */

#ifdef WGL_I3D_image_buffer

PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC wglewAssociateImageBufferEventsI3D = NULL;
PFNWGLCREATEIMAGEBUFFERI3DPROC wglewCreateImageBufferI3D = NULL;
PFNWGLDESTROYIMAGEBUFFERI3DPROC wglewDestroyImageBufferI3D = NULL;
PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC wglewReleaseImageBufferEventsI3D = NULL;

static GLboolean _glewInit_WGL_I3D_image_buffer (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewAssociateImageBufferEventsI3D = (PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)glewGetProcAddress("wglAssociateImageBufferEventsI3D")) == NULL) || r;
  r = ((wglewCreateImageBufferI3D = (PFNWGLCREATEIMAGEBUFFERI3DPROC)glewGetProcAddress("wglCreateImageBufferI3D")) == NULL) || r;
  r = ((wglewDestroyImageBufferI3D = (PFNWGLDESTROYIMAGEBUFFERI3DPROC)glewGetProcAddress("wglDestroyImageBufferI3D")) == NULL) || r;
  r = ((wglewReleaseImageBufferEventsI3D = (PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)glewGetProcAddress("wglReleaseImageBufferEventsI3D")) == NULL) || r;

  return r;
}

GLboolean WGLEW_I3D_image_buffer = GL_FALSE;

#endif /* WGL_I3D_image_buffer */

/* ------------------------ WGL_I3D_swap_frame_lock ------------------------ */

#ifdef WGL_I3D_swap_frame_lock

PFNWGLDISABLEFRAMELOCKI3DPROC wglewDisableFrameLockI3D = NULL;
PFNWGLENABLEFRAMELOCKI3DPROC wglewEnableFrameLockI3D = NULL;
PFNWGLISENABLEDFRAMELOCKI3DPROC wglewIsEnabledFrameLockI3D = NULL;
PFNWGLQUERYFRAMELOCKMASTERI3DPROC wglewQueryFrameLockMasterI3D = NULL;

static GLboolean _glewInit_WGL_I3D_swap_frame_lock (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewDisableFrameLockI3D = (PFNWGLDISABLEFRAMELOCKI3DPROC)glewGetProcAddress("wglDisableFrameLockI3D")) == NULL) || r;
  r = ((wglewEnableFrameLockI3D = (PFNWGLENABLEFRAMELOCKI3DPROC)glewGetProcAddress("wglEnableFrameLockI3D")) == NULL) || r;
  r = ((wglewIsEnabledFrameLockI3D = (PFNWGLISENABLEDFRAMELOCKI3DPROC)glewGetProcAddress("wglIsEnabledFrameLockI3D")) == NULL) || r;
  r = ((wglewQueryFrameLockMasterI3D = (PFNWGLQUERYFRAMELOCKMASTERI3DPROC)glewGetProcAddress("wglQueryFrameLockMasterI3D")) == NULL) || r;

  return r;
}

GLboolean WGLEW_I3D_swap_frame_lock = GL_FALSE;

#endif /* WGL_I3D_swap_frame_lock */

/* ------------------------ WGL_I3D_swap_frame_usage ----------------------- */

#ifdef WGL_I3D_swap_frame_usage

PFNWGLBEGINFRAMETRACKINGI3DPROC wglewBeginFrameTrackingI3D = NULL;
PFNWGLENDFRAMETRACKINGI3DPROC wglewEndFrameTrackingI3D = NULL;
PFNWGLGETFRAMEUSAGEI3DPROC wglewGetFrameUsageI3D = NULL;
PFNWGLQUERYFRAMETRACKINGI3DPROC wglewQueryFrameTrackingI3D = NULL;

static GLboolean _glewInit_WGL_I3D_swap_frame_usage (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewBeginFrameTrackingI3D = (PFNWGLBEGINFRAMETRACKINGI3DPROC)glewGetProcAddress("wglBeginFrameTrackingI3D")) == NULL) || r;
  r = ((wglewEndFrameTrackingI3D = (PFNWGLENDFRAMETRACKINGI3DPROC)glewGetProcAddress("wglEndFrameTrackingI3D")) == NULL) || r;
  r = ((wglewGetFrameUsageI3D = (PFNWGLGETFRAMEUSAGEI3DPROC)glewGetProcAddress("wglGetFrameUsageI3D")) == NULL) || r;
  r = ((wglewQueryFrameTrackingI3D = (PFNWGLQUERYFRAMETRACKINGI3DPROC)glewGetProcAddress("wglQueryFrameTrackingI3D")) == NULL) || r;

  return r;
}

GLboolean WGLEW_I3D_swap_frame_usage = GL_FALSE;

#endif /* WGL_I3D_swap_frame_usage */

/* -------------------------- WGL_NV_float_buffer -------------------------- */

#ifdef WGL_NV_float_buffer

GLboolean WGLEW_NV_float_buffer = GL_FALSE;

#endif /* WGL_NV_float_buffer */

/* ---------------------- WGL_NV_render_depth_texture ---------------------- */

#ifdef WGL_NV_render_depth_texture

GLboolean WGLEW_NV_render_depth_texture = GL_FALSE;

#endif /* WGL_NV_render_depth_texture */

/* -------------------- WGL_NV_render_texture_rectangle -------------------- */

#ifdef WGL_NV_render_texture_rectangle

GLboolean WGLEW_NV_render_texture_rectangle = GL_FALSE;

#endif /* WGL_NV_render_texture_rectangle */

/* ----------------------- WGL_NV_vertex_array_range ----------------------- */

#ifdef WGL_NV_vertex_array_range

PFNWGLALLOCATEMEMORYNVPROC wglewAllocateMemoryNV = NULL;
PFNWGLFREEMEMORYNVPROC wglewFreeMemoryNV = NULL;

static GLboolean _glewInit_WGL_NV_vertex_array_range (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewAllocateMemoryNV = (PFNWGLALLOCATEMEMORYNVPROC)glewGetProcAddress("wglAllocateMemoryNV")) == NULL) || r;
  r = ((wglewFreeMemoryNV = (PFNWGLFREEMEMORYNVPROC)glewGetProcAddress("wglFreeMemoryNV")) == NULL) || r;

  return r;
}

GLboolean WGLEW_NV_vertex_array_range = GL_FALSE;

#endif /* WGL_NV_vertex_array_range */

/* -------------------------- WGL_OML_sync_control ------------------------- */

#ifdef WGL_OML_sync_control

PFNWGLGETMSCRATEOMLPROC wglewGetMscRateOML = NULL;
PFNWGLGETSYNCVALUESOMLPROC wglewGetSyncValuesOML = NULL;
PFNWGLSWAPBUFFERSMSCOMLPROC wglewSwapBuffersMscOML = NULL;
PFNWGLSWAPLAYERBUFFERSMSCOMLPROC wglewSwapLayerBuffersMscOML = NULL;
PFNWGLWAITFORMSCOMLPROC wglewWaitForMscOML = NULL;
PFNWGLWAITFORSBCOMLPROC wglewWaitForSbcOML = NULL;

static GLboolean _glewInit_WGL_OML_sync_control (void)
{
  GLboolean r = GL_FALSE;

  r = ((wglewGetMscRateOML = (PFNWGLGETMSCRATEOMLPROC)glewGetProcAddress("wglGetMscRateOML")) == NULL) || r;
  r = ((wglewGetSyncValuesOML = (PFNWGLGETSYNCVALUESOMLPROC)glewGetProcAddress("wglGetSyncValuesOML")) == NULL) || r;
  r = ((wglewSwapBuffersMscOML = (PFNWGLSWAPBUFFERSMSCOMLPROC)glewGetProcAddress("wglSwapBuffersMscOML")) == NULL) || r;
  r = ((wglewSwapLayerBuffersMscOML = (PFNWGLSWAPLAYERBUFFERSMSCOMLPROC)glewGetProcAddress("wglSwapLayerBuffersMscOML")) == NULL) || r;
  r = ((wglewWaitForMscOML = (PFNWGLWAITFORMSCOMLPROC)glewGetProcAddress("wglWaitForMscOML")) == NULL) || r;
  r = ((wglewWaitForSbcOML = (PFNWGLWAITFORSBCOMLPROC)glewGetProcAddress("wglWaitForSbcOML")) == NULL) || r;

  return r;
}

GLboolean WGLEW_OML_sync_control = GL_FALSE;

#endif /* WGL_OML_sync_control */

#else /* _UNIX */


/* ---------------------------- GLX_VERSION_1_0 ---------------------------- */

#ifdef GLX_VERSION_1_0

GLboolean GLXEW_VERSION_1_0 = GL_FALSE;

#endif /* GLX_VERSION_1_0 */

/* ---------------------------- GLX_VERSION_1_1 ---------------------------- */

#ifdef GLX_VERSION_1_1

GLboolean GLXEW_VERSION_1_1 = GL_FALSE;

#endif /* GLX_VERSION_1_1 */

/* ---------------------------- GLX_VERSION_1_2 ---------------------------- */

#ifdef GLX_VERSION_1_2

PFNGLXGETCURRENTDISPLAYPROC glewXGetCurrentDisplay = NULL;

static GLboolean _glewInit_GLX_VERSION_1_2 (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXGetCurrentDisplay = (PFNGLXGETCURRENTDISPLAYPROC)glewGetProcAddress("glXGetCurrentDisplay")) == NULL) || r;

  return r;
}

GLboolean GLXEW_VERSION_1_2 = GL_FALSE;

#endif /* GLX_VERSION_1_2 */

/* ---------------------------- GLX_VERSION_1_3 ---------------------------- */

#ifdef GLX_VERSION_1_3

PFNGLXCHOOSEFBCONFIGPROC glewXChooseFBConfig = NULL;
PFNGLXCREATENEWCONTEXTPROC glewXCreateNewContext = NULL;
PFNGLXCREATEPBUFFERPROC glewXCreatePbuffer = NULL;
PFNGLXCREATEPIXMAPPROC glewXCreatePixmap = NULL;
PFNGLXCREATEWINDOWPROC glewXCreateWindow = NULL;
PFNGLXDESTROYPBUFFERPROC glewXDestroyPbuffer = NULL;
PFNGLXDESTROYPIXMAPPROC glewXDestroyPixmap = NULL;
PFNGLXDESTROYWINDOWPROC glewXDestroyWindow = NULL;
PFNGLXGETCURRENTREADDRAWABLEPROC glewXGetCurrentReadDrawable = NULL;
PFNGLXGETFBCONFIGATTRIBPROC glewXGetFBConfigAttrib = NULL;
PFNGLXGETFBCONFIGSPROC glewXGetFBConfigs = NULL;
PFNGLXGETSELECTEDEVENTPROC glewXGetSelectedEvent = NULL;
PFNGLXGETVISUALFROMFBCONFIGPROC glewXGetVisualFromFBConfig = NULL;
PFNGLXMAKECONTEXTCURRENTPROC glewXMakeContextCurrent = NULL;
PFNGLXQUERYCONTEXTPROC glewXQueryContext = NULL;
PFNGLXQUERYDRAWABLEPROC glewXQueryDrawable = NULL;
PFNGLXSELECTEVENTPROC glewXSelectEvent = NULL;

static GLboolean _glewInit_GLX_VERSION_1_3 (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXChooseFBConfig = (PFNGLXCHOOSEFBCONFIGPROC)glewGetProcAddress("glXChooseFBConfig")) == NULL) || r;
  r = ((glewXCreateNewContext = (PFNGLXCREATENEWCONTEXTPROC)glewGetProcAddress("glXCreateNewContext")) == NULL) || r;
  r = ((glewXCreatePbuffer = (PFNGLXCREATEPBUFFERPROC)glewGetProcAddress("glXCreatePbuffer")) == NULL) || r;
  r = ((glewXCreatePixmap = (PFNGLXCREATEPIXMAPPROC)glewGetProcAddress("glXCreatePixmap")) == NULL) || r;
  r = ((glewXCreateWindow = (PFNGLXCREATEWINDOWPROC)glewGetProcAddress("glXCreateWindow")) == NULL) || r;
  r = ((glewXDestroyPbuffer = (PFNGLXDESTROYPBUFFERPROC)glewGetProcAddress("glXDestroyPbuffer")) == NULL) || r;
  r = ((glewXDestroyPixmap = (PFNGLXDESTROYPIXMAPPROC)glewGetProcAddress("glXDestroyPixmap")) == NULL) || r;
  r = ((glewXDestroyWindow = (PFNGLXDESTROYWINDOWPROC)glewGetProcAddress("glXDestroyWindow")) == NULL) || r;
  r = ((glewXGetCurrentReadDrawable = (PFNGLXGETCURRENTREADDRAWABLEPROC)glewGetProcAddress("glXGetCurrentReadDrawable")) == NULL) || r;
  r = ((glewXGetFBConfigAttrib = (PFNGLXGETFBCONFIGATTRIBPROC)glewGetProcAddress("glXGetFBConfigAttrib")) == NULL) || r;
  r = ((glewXGetFBConfigs = (PFNGLXGETFBCONFIGSPROC)glewGetProcAddress("glXGetFBConfigs")) == NULL) || r;
  r = ((glewXGetSelectedEvent = (PFNGLXGETSELECTEDEVENTPROC)glewGetProcAddress("glXGetSelectedEvent")) == NULL) || r;
  r = ((glewXGetVisualFromFBConfig = (PFNGLXGETVISUALFROMFBCONFIGPROC)glewGetProcAddress("glXGetVisualFromFBConfig")) == NULL) || r;
  r = ((glewXMakeContextCurrent = (PFNGLXMAKECONTEXTCURRENTPROC)glewGetProcAddress("glXMakeContextCurrent")) == NULL) || r;
  r = ((glewXQueryContext = (PFNGLXQUERYCONTEXTPROC)glewGetProcAddress("glXQueryContext")) == NULL) || r;
  r = ((glewXQueryDrawable = (PFNGLXQUERYDRAWABLEPROC)glewGetProcAddress("glXQueryDrawable")) == NULL) || r;
  r = ((glewXSelectEvent = (PFNGLXSELECTEVENTPROC)glewGetProcAddress("glXSelectEvent")) == NULL) || r;

  return r;
}

GLboolean GLXEW_VERSION_1_3 = GL_FALSE;

#endif /* GLX_VERSION_1_3 */

/* ---------------------------- GLX_VERSION_1_4 ---------------------------- */

#ifdef GLX_VERSION_1_4

GLboolean GLXEW_VERSION_1_4 = GL_FALSE;

#endif /* GLX_VERSION_1_4 */

/* -------------------------- GLX_3DFX_multisample ------------------------- */

#ifdef GLX_3DFX_multisample

GLboolean GLXEW_3DFX_multisample = GL_FALSE;

#endif /* GLX_3DFX_multisample */

/* ------------------------ GLX_ARB_get_proc_address ----------------------- */

#ifdef GLX_ARB_get_proc_address

GLboolean GLXEW_ARB_get_proc_address = GL_FALSE;

#endif /* GLX_ARB_get_proc_address */

/* -------------------------- GLX_ARB_multisample -------------------------- */

#ifdef GLX_ARB_multisample

GLboolean GLXEW_ARB_multisample = GL_FALSE;

#endif /* GLX_ARB_multisample */

/* ------------------------- GLX_EXT_import_context ------------------------ */

#ifdef GLX_EXT_import_context

PFNGLXFREECONTEXTEXTPROC glewXFreeContextEXT = NULL;
PFNGLXGETCONTEXTIDEXTPROC glewXGetContextIDEXT = NULL;
PFNGLXIMPORTCONTEXTEXTPROC glewXImportContextEXT = NULL;
PFNGLXQUERYCONTEXTINFOEXTPROC glewXQueryContextInfoEXT = NULL;

static GLboolean _glewInit_GLX_EXT_import_context (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXFreeContextEXT = (PFNGLXFREECONTEXTEXTPROC)glewGetProcAddress("glXFreeContextEXT")) == NULL) || r;
  r = ((glewXGetContextIDEXT = (PFNGLXGETCONTEXTIDEXTPROC)glewGetProcAddress("glXGetContextIDEXT")) == NULL) || r;
  r = ((glewXImportContextEXT = (PFNGLXIMPORTCONTEXTEXTPROC)glewGetProcAddress("glXImportContextEXT")) == NULL) || r;
  r = ((glewXQueryContextInfoEXT = (PFNGLXQUERYCONTEXTINFOEXTPROC)glewGetProcAddress("glXQueryContextInfoEXT")) == NULL) || r;

  return r;
}

GLboolean GLXEW_EXT_import_context = GL_FALSE;

#endif /* GLX_EXT_import_context */

/* -------------------------- GLX_EXT_scene_marker ------------------------- */

#ifdef GLX_EXT_scene_marker

GLboolean GLXEW_EXT_scene_marker = GL_FALSE;

#endif /* GLX_EXT_scene_marker */

/* -------------------------- GLX_EXT_visual_info -------------------------- */

#ifdef GLX_EXT_visual_info

GLboolean GLXEW_EXT_visual_info = GL_FALSE;

#endif /* GLX_EXT_visual_info */

/* ------------------------- GLX_EXT_visual_rating ------------------------- */

#ifdef GLX_EXT_visual_rating

GLboolean GLXEW_EXT_visual_rating = GL_FALSE;

#endif /* GLX_EXT_visual_rating */

/* ------------------------ GLX_MESA_copy_sub_buffer ----------------------- */

#ifdef GLX_MESA_copy_sub_buffer

PFNGLXCOPYSUBBUFFERMESAPROC glewXCopySubBufferMESA = NULL;

static GLboolean _glewInit_GLX_MESA_copy_sub_buffer (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXCopySubBufferMESA = (PFNGLXCOPYSUBBUFFERMESAPROC)glewGetProcAddress("glXCopySubBufferMESA")) == NULL) || r;

  return r;
}

GLboolean GLXEW_MESA_copy_sub_buffer = GL_FALSE;

#endif /* GLX_MESA_copy_sub_buffer */

/* ------------------------ GLX_MESA_pixmap_colormap ----------------------- */

#ifdef GLX_MESA_pixmap_colormap

PFNGLXCREATEGLXPIXMAPMESAPROC glewXCreateGLXPixmapMESA = NULL;

static GLboolean _glewInit_GLX_MESA_pixmap_colormap (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXCreateGLXPixmapMESA = (PFNGLXCREATEGLXPIXMAPMESAPROC)glewGetProcAddress("glXCreateGLXPixmapMESA")) == NULL) || r;

  return r;
}

GLboolean GLXEW_MESA_pixmap_colormap = GL_FALSE;

#endif /* GLX_MESA_pixmap_colormap */

/* ------------------------ GLX_MESA_release_buffers ----------------------- */

#ifdef GLX_MESA_release_buffers

PFNGLXRELEASEBUFFERSMESAPROC glewXReleaseBuffersMESA = NULL;

static GLboolean _glewInit_GLX_MESA_release_buffers (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXReleaseBuffersMESA = (PFNGLXRELEASEBUFFERSMESAPROC)glewGetProcAddress("glXReleaseBuffersMESA")) == NULL) || r;

  return r;
}

GLboolean GLXEW_MESA_release_buffers = GL_FALSE;

#endif /* GLX_MESA_release_buffers */

/* ------------------------- GLX_MESA_set_3dfx_mode ------------------------ */

#ifdef GLX_MESA_set_3dfx_mode

PFNGLXSET3DFXMODEMESAPROC glewXSet3DfxModeMESA = NULL;

static GLboolean _glewInit_GLX_MESA_set_3dfx_mode (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXSet3DfxModeMESA = (PFNGLXSET3DFXMODEMESAPROC)glewGetProcAddress("glXSet3DfxModeMESA")) == NULL) || r;

  return r;
}

GLboolean GLXEW_MESA_set_3dfx_mode = GL_FALSE;

#endif /* GLX_MESA_set_3dfx_mode */

/* -------------------------- GLX_NV_float_buffer -------------------------- */

#ifdef GLX_NV_float_buffer

GLboolean GLXEW_NV_float_buffer = GL_FALSE;

#endif /* GLX_NV_float_buffer */

/* ----------------------- GLX_NV_vertex_array_range ----------------------- */

#ifdef GLX_NV_vertex_array_range

PFNGLXALLOCATEMEMORYNVPROC glewXAllocateMemoryNV = NULL;
PFNGLXFREEMEMORYNVPROC glewXFreeMemoryNV = NULL;

static GLboolean _glewInit_GLX_NV_vertex_array_range (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXAllocateMemoryNV = (PFNGLXALLOCATEMEMORYNVPROC)glewGetProcAddress("glXAllocateMemoryNV")) == NULL) || r;
  r = ((glewXFreeMemoryNV = (PFNGLXFREEMEMORYNVPROC)glewGetProcAddress("glXFreeMemoryNV")) == NULL) || r;

  return r;
}

GLboolean GLXEW_NV_vertex_array_range = GL_FALSE;

#endif /* GLX_NV_vertex_array_range */

/* -------------------------- GLX_OML_swap_method -------------------------- */

#ifdef GLX_OML_swap_method

GLboolean GLXEW_OML_swap_method = GL_FALSE;

#endif /* GLX_OML_swap_method */

/* -------------------------- GLX_OML_sync_control ------------------------- */

#if defined(GLX_OML_sync_control) && defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#include <inttypes.h>

PFNGLXGETMSCRATEOMLPROC glewXGetMscRateOML = NULL;
PFNGLXGETSYNCVALUESOMLPROC glewXGetSyncValuesOML = NULL;
PFNGLXSWAPBUFFERSMSCOMLPROC glewXSwapBuffersMscOML = NULL;
PFNGLXWAITFORMSCOMLPROC glewXWaitForMscOML = NULL;
PFNGLXWAITFORSBCOMLPROC glewXWaitForSbcOML = NULL;

static GLboolean _glewInit_GLX_OML_sync_control (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXGetMscRateOML = (PFNGLXGETMSCRATEOMLPROC)glewGetProcAddress("glXGetMscRateOML")) == NULL) || r;
  r = ((glewXGetSyncValuesOML = (PFNGLXGETSYNCVALUESOMLPROC)glewGetProcAddress("glXGetSyncValuesOML")) == NULL) || r;
  r = ((glewXSwapBuffersMscOML = (PFNGLXSWAPBUFFERSMSCOMLPROC)glewGetProcAddress("glXSwapBuffersMscOML")) == NULL) || r;
  r = ((glewXWaitForMscOML = (PFNGLXWAITFORMSCOMLPROC)glewGetProcAddress("glXWaitForMscOML")) == NULL) || r;
  r = ((glewXWaitForSbcOML = (PFNGLXWAITFORSBCOMLPROC)glewGetProcAddress("glXWaitForSbcOML")) == NULL) || r;

  return r;
}

GLboolean GLXEW_OML_sync_control = GL_FALSE;

#endif /* GLX_OML_sync_control */

/* ------------------------ GLX_SGIS_blended_overlay ----------------------- */

#ifdef GLX_SGIS_blended_overlay

GLboolean GLXEW_SGIS_blended_overlay = GL_FALSE;

#endif /* GLX_SGIS_blended_overlay */

/* -------------------------- GLX_SGIS_color_range ------------------------- */

#ifdef GLX_SGIS_color_range

GLboolean GLXEW_SGIS_color_range = GL_FALSE;

#endif /* GLX_SGIS_color_range */

/* -------------------------- GLX_SGIS_multisample ------------------------- */

#ifdef GLX_SGIS_multisample

GLboolean GLXEW_SGIS_multisample = GL_FALSE;

#endif /* GLX_SGIS_multisample */

/* ---------------------- GLX_SGIS_shared_multisample ---------------------- */

#ifdef GLX_SGIS_shared_multisample

GLboolean GLXEW_SGIS_shared_multisample = GL_FALSE;

#endif /* GLX_SGIS_shared_multisample */

/* --------------------------- GLX_SGIX_fbconfig --------------------------- */

#ifdef GLX_SGIX_fbconfig

PFNGLXCHOOSEFBCONFIGSGIXPROC glewXChooseFBConfigSGIX = NULL;
PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC glewXCreateContextWithConfigSGIX = NULL;
PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC glewXCreateGLXPixmapWithConfigSGIX = NULL;
PFNGLXGETFBCONFIGATTRIBSGIXPROC glewXGetFBConfigAttribSGIX = NULL;
PFNGLXGETFBCONFIGFROMVISUALSGIXPROC glewXGetFBConfigFromVisualSGIX = NULL;
PFNGLXGETVISUALFROMFBCONFIGSGIXPROC glewXGetVisualFromFBConfigSGIX = NULL;

static GLboolean _glewInit_GLX_SGIX_fbconfig (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXChooseFBConfigSGIX = (PFNGLXCHOOSEFBCONFIGSGIXPROC)glewGetProcAddress("glXChooseFBConfigSGIX")) == NULL) || r;
  r = ((glewXCreateContextWithConfigSGIX = (PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC)glewGetProcAddress("glXCreateContextWithConfigSGIX")) == NULL) || r;
  r = ((glewXCreateGLXPixmapWithConfigSGIX = (PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC)glewGetProcAddress("glXCreateGLXPixmapWithConfigSGIX")) == NULL) || r;
  r = ((glewXGetFBConfigAttribSGIX = (PFNGLXGETFBCONFIGATTRIBSGIXPROC)glewGetProcAddress("glXGetFBConfigAttribSGIX")) == NULL) || r;
  r = ((glewXGetFBConfigFromVisualSGIX = (PFNGLXGETFBCONFIGFROMVISUALSGIXPROC)glewGetProcAddress("glXGetFBConfigFromVisualSGIX")) == NULL) || r;
  r = ((glewXGetVisualFromFBConfigSGIX = (PFNGLXGETVISUALFROMFBCONFIGSGIXPROC)glewGetProcAddress("glXGetVisualFromFBConfigSGIX")) == NULL) || r;

  return r;
}

GLboolean GLXEW_SGIX_fbconfig = GL_FALSE;

#endif /* GLX_SGIX_fbconfig */

/* ---------------------------- GLX_SGIX_pbuffer --------------------------- */

#ifdef GLX_SGIX_pbuffer

PFNGLXCREATEGLXPBUFFERSGIXPROC glewXCreateGLXPbufferSGIX = NULL;
PFNGLXDESTROYGLXPBUFFERSGIXPROC glewXDestroyGLXPbufferSGIX = NULL;
PFNGLXGETSELECTEDEVENTSGIXPROC glewXGetSelectedEventSGIX = NULL;
PFNGLXQUERYGLXPBUFFERSGIXPROC glewXQueryGLXPbufferSGIX = NULL;
PFNGLXSELECTEVENTSGIXPROC glewXSelectEventSGIX = NULL;

static GLboolean _glewInit_GLX_SGIX_pbuffer (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXCreateGLXPbufferSGIX = (PFNGLXCREATEGLXPBUFFERSGIXPROC)glewGetProcAddress("glXCreateGLXPbufferSGIX")) == NULL) || r;
  r = ((glewXDestroyGLXPbufferSGIX = (PFNGLXDESTROYGLXPBUFFERSGIXPROC)glewGetProcAddress("glXDestroyGLXPbufferSGIX")) == NULL) || r;
  r = ((glewXGetSelectedEventSGIX = (PFNGLXGETSELECTEDEVENTSGIXPROC)glewGetProcAddress("glXGetSelectedEventSGIX")) == NULL) || r;
  r = ((glewXQueryGLXPbufferSGIX = (PFNGLXQUERYGLXPBUFFERSGIXPROC)glewGetProcAddress("glXQueryGLXPbufferSGIX")) == NULL) || r;
  r = ((glewXSelectEventSGIX = (PFNGLXSELECTEVENTSGIXPROC)glewGetProcAddress("glXSelectEventSGIX")) == NULL) || r;

  return r;
}

GLboolean GLXEW_SGIX_pbuffer = GL_FALSE;

#endif /* GLX_SGIX_pbuffer */

/* ------------------------- GLX_SGIX_swap_barrier ------------------------- */

#ifdef GLX_SGIX_swap_barrier

PFNGLXBINDSWAPBARRIERSGIXPROC glewXBindSwapBarrierSGIX = NULL;
PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC glewXQueryMaxSwapBarriersSGIX = NULL;

static GLboolean _glewInit_GLX_SGIX_swap_barrier (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXBindSwapBarrierSGIX = (PFNGLXBINDSWAPBARRIERSGIXPROC)glewGetProcAddress("glXBindSwapBarrierSGIX")) == NULL) || r;
  r = ((glewXQueryMaxSwapBarriersSGIX = (PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC)glewGetProcAddress("glXQueryMaxSwapBarriersSGIX")) == NULL) || r;

  return r;
}

GLboolean GLXEW_SGIX_swap_barrier = GL_FALSE;

#endif /* GLX_SGIX_swap_barrier */

/* -------------------------- GLX_SGIX_swap_group -------------------------- */

#ifdef GLX_SGIX_swap_group

PFNGLXJOINSWAPGROUPSGIXPROC glewXJoinSwapGroupSGIX = NULL;

static GLboolean _glewInit_GLX_SGIX_swap_group (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXJoinSwapGroupSGIX = (PFNGLXJOINSWAPGROUPSGIXPROC)glewGetProcAddress("glXJoinSwapGroupSGIX")) == NULL) || r;

  return r;
}

GLboolean GLXEW_SGIX_swap_group = GL_FALSE;

#endif /* GLX_SGIX_swap_group */

/* ------------------------- GLX_SGIX_video_resize ------------------------- */

#ifdef GLX_SGIX_video_resize

PFNGLXBINDCHANNELTOWINDOWSGIXPROC glewXBindChannelToWindowSGIX = NULL;
PFNGLXCHANNELRECTSGIXPROC glewXChannelRectSGIX = NULL;
PFNGLXCHANNELRECTSYNCSGIXPROC glewXChannelRectSyncSGIX = NULL;
PFNGLXQUERYCHANNELDELTASSGIXPROC glewXQueryChannelDeltasSGIX = NULL;
PFNGLXQUERYCHANNELRECTSGIXPROC glewXQueryChannelRectSGIX = NULL;

static GLboolean _glewInit_GLX_SGIX_video_resize (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXBindChannelToWindowSGIX = (PFNGLXBINDCHANNELTOWINDOWSGIXPROC)glewGetProcAddress("glXBindChannelToWindowSGIX")) == NULL) || r;
  r = ((glewXChannelRectSGIX = (PFNGLXCHANNELRECTSGIXPROC)glewGetProcAddress("glXChannelRectSGIX")) == NULL) || r;
  r = ((glewXChannelRectSyncSGIX = (PFNGLXCHANNELRECTSYNCSGIXPROC)glewGetProcAddress("glXChannelRectSyncSGIX")) == NULL) || r;
  r = ((glewXQueryChannelDeltasSGIX = (PFNGLXQUERYCHANNELDELTASSGIXPROC)glewGetProcAddress("glXQueryChannelDeltasSGIX")) == NULL) || r;
  r = ((glewXQueryChannelRectSGIX = (PFNGLXQUERYCHANNELRECTSGIXPROC)glewGetProcAddress("glXQueryChannelRectSGIX")) == NULL) || r;

  return r;
}

GLboolean GLXEW_SGIX_video_resize = GL_FALSE;

#endif /* GLX_SGIX_video_resize */

/* ---------------------- GLX_SGIX_visual_select_group --------------------- */

#ifdef GLX_SGIX_visual_select_group

GLboolean GLXEW_SGIX_visual_select_group = GL_FALSE;

#endif /* GLX_SGIX_visual_select_group */

/* ---------------------------- GLX_SGI_cushion ---------------------------- */

#ifdef GLX_SGI_cushion

PFNGLXCUSHIONSGIPROC glewXCushionSGI = NULL;

static GLboolean _glewInit_GLX_SGI_cushion (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXCushionSGI = (PFNGLXCUSHIONSGIPROC)glewGetProcAddress("glXCushionSGI")) == NULL) || r;

  return r;
}

GLboolean GLXEW_SGI_cushion = GL_FALSE;

#endif /* GLX_SGI_cushion */

/* ----------------------- GLX_SGI_make_current_read ----------------------- */

#ifdef GLX_SGI_make_current_read

PFNGLXGETCURRENTREADDRAWABLESGIPROC glewXGetCurrentReadDrawableSGI = NULL;
PFNGLXMAKECURRENTREADSGIPROC glewXMakeCurrentReadSGI = NULL;

static GLboolean _glewInit_GLX_SGI_make_current_read (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXGetCurrentReadDrawableSGI = (PFNGLXGETCURRENTREADDRAWABLESGIPROC)glewGetProcAddress("glXGetCurrentReadDrawableSGI")) == NULL) || r;
  r = ((glewXMakeCurrentReadSGI = (PFNGLXMAKECURRENTREADSGIPROC)glewGetProcAddress("glXMakeCurrentReadSGI")) == NULL) || r;

  return r;
}

GLboolean GLXEW_SGI_make_current_read = GL_FALSE;

#endif /* GLX_SGI_make_current_read */

/* -------------------------- GLX_SGI_swap_control ------------------------- */

#ifdef GLX_SGI_swap_control

PFNGLXSWAPINTERVALSGIPROC glewXSwapIntervalSGI = NULL;

static GLboolean _glewInit_GLX_SGI_swap_control (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXSwapIntervalSGI = (PFNGLXSWAPINTERVALSGIPROC)glewGetProcAddress("glXSwapIntervalSGI")) == NULL) || r;

  return r;
}

GLboolean GLXEW_SGI_swap_control = GL_FALSE;

#endif /* GLX_SGI_swap_control */

/* --------------------------- GLX_SGI_video_sync -------------------------- */

#ifdef GLX_SGI_video_sync

PFNGLXGETVIDEOSYNCSGIPROC glewXGetVideoSyncSGI = NULL;
PFNGLXWAITVIDEOSYNCSGIPROC glewXWaitVideoSyncSGI = NULL;

static GLboolean _glewInit_GLX_SGI_video_sync (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXGetVideoSyncSGI = (PFNGLXGETVIDEOSYNCSGIPROC)glewGetProcAddress("glXGetVideoSyncSGI")) == NULL) || r;
  r = ((glewXWaitVideoSyncSGI = (PFNGLXWAITVIDEOSYNCSGIPROC)glewGetProcAddress("glXWaitVideoSyncSGI")) == NULL) || r;

  return r;
}

GLboolean GLXEW_SGI_video_sync = GL_FALSE;

#endif /* GLX_SGI_video_sync */

/* --------------------- GLX_SUN_get_transparent_index --------------------- */

#ifdef GLX_SUN_get_transparent_index

PFNGLXGETTRANSPARENTINDEXSUNPROC glewXGetTransparentIndexSUN = NULL;

static GLboolean _glewInit_GLX_SUN_get_transparent_index (void)
{
  GLboolean r = GL_FALSE;

  r = ((glewXGetTransparentIndexSUN = (PFNGLXGETTRANSPARENTINDEXSUNPROC)glewGetProcAddress("glXGetTransparentIndexSUN")) == NULL) || r;

  return r;
}

GLboolean GLXEW_SUN_get_transparent_index = GL_FALSE;

#endif /* GLX_SUN_get_transparent_index */

#endif /* _WIN32 */

/* ------------------------------------------------------------------------- */

/*
 * GLEW, just like OpenGL or GLU, does not rely on the standard C library.
 * These functions implement the functionality required in this file.
 */

static GLuint _glewStrLen (const GLubyte *s)
{
  GLuint i=0;
  while (s+i != NULL && s[i] != '\0') i++;
  return i;
}

static GLuint _glewStrCLen (const GLubyte *s, GLubyte c)
{
  GLuint i=0;
  while (s+i != NULL && s[i] != '\0' && s[i] != c) i++;
  return i;
}

static GLboolean _glewStrSame (const GLubyte *a, const GLubyte *b, GLuint n)
{
  GLuint i=0;
  while (i < n && a+i != NULL && b+i != NULL && a[i] == b[i]) i++;
  return i == n;
}

/* 
 * Search for name in the extensions string. Use of strstr()
 * is not sufficient because extension names can be prefixes of
 * other extension names. Could use strtok() but the constant
 * string returned by glGetString might be in read-only memory.
 */
GLboolean glewGetExtension (const GLubyte *name)
{    
  GLubyte *p, *end;
  GLuint len = _glewStrLen(name);
  p = (GLubyte*)glGetString(GL_EXTENSIONS);
  if (0 == p) return GL_FALSE;
  end = p + _glewStrLen(p);
  while (p < end)
  {
    GLuint n = _glewStrCLen(p, ' ');
    if (len == n && _glewStrSame(name, p, n)) return GL_TRUE;
    p += n+1;
  }
  return GL_FALSE;
}

/* ------------------------------------------------------------------------- */

static GLuint _glewInit ()
{
  const GLubyte* s;
  GLuint i;
  /* query opengl version */
  s = glGetString(GL_VERSION);
  if (!s) return GLEW_ERROR_NO_GL_VERSION;
  i=_glewStrCLen(s, '.')+1;
  if (s+i == NULL || s[i] < '1')
  {
    return GLEW_ERROR_GL_VERSION_10_ONLY;
  }
  else
  {
    if (s[2] == '4')
    {
      GLEW_VERSION_1_1 = GL_TRUE;
      GLEW_VERSION_1_2 = GL_TRUE;
      GLEW_VERSION_1_3 = GL_TRUE;
      GLEW_VERSION_1_4 = GL_TRUE;
    }
    if (s[2] == '3')
    {
      GLEW_VERSION_1_1 = GL_TRUE;
      GLEW_VERSION_1_2 = GL_TRUE;
      GLEW_VERSION_1_3 = GL_TRUE;
    }
    if (s[2] == '2')
    {
      GLEW_VERSION_1_1 = GL_TRUE;
      GLEW_VERSION_1_2 = GL_TRUE;
    }
    if (s[2] < '2')
    {
      GLEW_VERSION_1_1 = GL_TRUE;
    }
  }
  /* initialize extensions */
#ifdef GL_VERSION_1_2
  if (glewExperimental || GLEW_VERSION_1_2) GLEW_VERSION_1_2 = !_glewInit_GL_VERSION_1_2();
#endif /* GL_VERSION_1_2 */
#ifdef GL_VERSION_1_3
  if (glewExperimental || GLEW_VERSION_1_3) GLEW_VERSION_1_3 = !_glewInit_GL_VERSION_1_3();
#endif /* GL_VERSION_1_3 */
#ifdef GL_VERSION_1_4
  if (glewExperimental || GLEW_VERSION_1_4) GLEW_VERSION_1_4 = !_glewInit_GL_VERSION_1_4();
#endif /* GL_VERSION_1_4 */
#ifdef GL_3DFX_multisample
  GLEW_3DFX_multisample = glewGetExtension("GL_3DFX_multisample");
#endif /* GL_3DFX_multisample */
#ifdef GL_3DFX_tbuffer
  GLEW_3DFX_tbuffer = glewGetExtension("GL_3DFX_tbuffer");
  if (glewExperimental || GLEW_3DFX_tbuffer) GLEW_3DFX_tbuffer = !_glewInit_GL_3DFX_tbuffer();
#endif /* GL_3DFX_tbuffer */
#ifdef GL_3DFX_texture_compression_FXT1
  GLEW_3DFX_texture_compression_FXT1 = glewGetExtension("GL_3DFX_texture_compression_FXT1");
#endif /* GL_3DFX_texture_compression_FXT1 */
#ifdef GL_APPLE_client_storage
  GLEW_APPLE_client_storage = glewGetExtension("GL_APPLE_client_storage");
#endif /* GL_APPLE_client_storage */
#ifdef GL_APPLE_element_array
  GLEW_APPLE_element_array = glewGetExtension("GL_APPLE_element_array");
  if (glewExperimental || GLEW_APPLE_element_array) GLEW_APPLE_element_array = !_glewInit_GL_APPLE_element_array();
#endif /* GL_APPLE_element_array */
#ifdef GL_APPLE_fence
  GLEW_APPLE_fence = glewGetExtension("GL_APPLE_fence");
  if (glewExperimental || GLEW_APPLE_fence) GLEW_APPLE_fence = !_glewInit_GL_APPLE_fence();
#endif /* GL_APPLE_fence */
#ifdef GL_APPLE_specular_vector
  GLEW_APPLE_specular_vector = glewGetExtension("GL_APPLE_specular_vector");
#endif /* GL_APPLE_specular_vector */
#ifdef GL_APPLE_transform_hint
  GLEW_APPLE_transform_hint = glewGetExtension("GL_APPLE_transform_hint");
#endif /* GL_APPLE_transform_hint */
#ifdef GL_APPLE_vertex_array_object
  GLEW_APPLE_vertex_array_object = glewGetExtension("GL_APPLE_vertex_array_object");
  if (glewExperimental || GLEW_APPLE_vertex_array_object) GLEW_APPLE_vertex_array_object = !_glewInit_GL_APPLE_vertex_array_object();
#endif /* GL_APPLE_vertex_array_object */
#ifdef GL_APPLE_vertex_array_range
  GLEW_APPLE_vertex_array_range = glewGetExtension("GL_APPLE_vertex_array_range");
  if (glewExperimental || GLEW_APPLE_vertex_array_range) GLEW_APPLE_vertex_array_range = !_glewInit_GL_APPLE_vertex_array_range();
#endif /* GL_APPLE_vertex_array_range */
#ifdef GL_APPLE_ycbcr_422
  GLEW_APPLE_ycbcr_422 = glewGetExtension("GL_APPLE_ycbcr_422");
#endif /* GL_APPLE_ycbcr_422 */
#ifdef GL_ARB_depth_texture
  GLEW_ARB_depth_texture = glewGetExtension("GL_ARB_depth_texture");
#endif /* GL_ARB_depth_texture */
#ifdef GL_ARB_fragment_program
  GLEW_ARB_fragment_program = glewGetExtension("GL_ARB_fragment_program");
#endif /* GL_ARB_fragment_program */
#ifdef GL_ARB_imaging
  GLEW_ARB_imaging = glewGetExtension("GL_ARB_imaging");
  if (glewExperimental || GLEW_ARB_imaging) GLEW_ARB_imaging = !_glewInit_GL_ARB_imaging();
#endif /* GL_ARB_imaging */
#ifdef GL_ARB_matrix_palette
  GLEW_ARB_matrix_palette = glewGetExtension("GL_ARB_matrix_palette");
  if (glewExperimental || GLEW_ARB_matrix_palette) GLEW_ARB_matrix_palette = !_glewInit_GL_ARB_matrix_palette();
#endif /* GL_ARB_matrix_palette */
#ifdef GL_ARB_multisample
  GLEW_ARB_multisample = glewGetExtension("GL_ARB_multisample");
  if (glewExperimental || GLEW_ARB_multisample) GLEW_ARB_multisample = !_glewInit_GL_ARB_multisample();
#endif /* GL_ARB_multisample */
#ifdef GL_ARB_multitexture
  GLEW_ARB_multitexture = glewGetExtension("GL_ARB_multitexture");
  if (glewExperimental || GLEW_ARB_multitexture) GLEW_ARB_multitexture = !_glewInit_GL_ARB_multitexture();
#endif /* GL_ARB_multitexture */
#ifdef GL_ARB_occlusion_query
  GLEW_ARB_occlusion_query = glewGetExtension("GL_ARB_occlusion_query");
  if (glewExperimental || GLEW_ARB_occlusion_query) GLEW_ARB_occlusion_query = !_glewInit_GL_ARB_occlusion_query();
#endif /* GL_ARB_occlusion_query */
#ifdef GL_ARB_point_parameters
  GLEW_ARB_point_parameters = glewGetExtension("GL_ARB_point_parameters");
  if (glewExperimental || GLEW_ARB_point_parameters) GLEW_ARB_point_parameters = !_glewInit_GL_ARB_point_parameters();
#endif /* GL_ARB_point_parameters */
#ifdef GL_ARB_point_sprite
  GLEW_ARB_point_sprite = glewGetExtension("GL_ARB_point_sprite");
#endif /* GL_ARB_point_sprite */
#ifdef GL_ARB_shading_language_100
  GLEW_ARB_shading_language_100 = glewGetExtension("GL_ARB_shading_language_100");
#endif /* GL_ARB_shading_language_100 */
#ifdef GL_ARB_shadow
  GLEW_ARB_shadow = glewGetExtension("GL_ARB_shadow");
#endif /* GL_ARB_shadow */
#ifdef GL_ARB_shadow_ambient
  GLEW_ARB_shadow_ambient = glewGetExtension("GL_ARB_shadow_ambient");
#endif /* GL_ARB_shadow_ambient */
#ifdef GL_ARB_texture_border_clamp
  GLEW_ARB_texture_border_clamp = glewGetExtension("GL_ARB_texture_border_clamp");
#endif /* GL_ARB_texture_border_clamp */
#ifdef GL_ARB_texture_compression
  GLEW_ARB_texture_compression = glewGetExtension("GL_ARB_texture_compression");
  if (glewExperimental || GLEW_ARB_texture_compression) GLEW_ARB_texture_compression = !_glewInit_GL_ARB_texture_compression();
#endif /* GL_ARB_texture_compression */
#ifdef GL_ARB_texture_cube_map
  GLEW_ARB_texture_cube_map = glewGetExtension("GL_ARB_texture_cube_map");
#endif /* GL_ARB_texture_cube_map */
#ifdef GL_ARB_texture_env_add
  GLEW_ARB_texture_env_add = glewGetExtension("GL_ARB_texture_env_add");
#endif /* GL_ARB_texture_env_add */
#ifdef GL_ARB_texture_env_combine
  GLEW_ARB_texture_env_combine = glewGetExtension("GL_ARB_texture_env_combine");
#endif /* GL_ARB_texture_env_combine */
#ifdef GL_ARB_texture_env_crossbar
  GLEW_ARB_texture_env_crossbar = glewGetExtension("GL_ARB_texture_env_crossbar");
#endif /* GL_ARB_texture_env_crossbar */
#ifdef GL_ARB_texture_env_dot3
  GLEW_ARB_texture_env_dot3 = glewGetExtension("GL_ARB_texture_env_dot3");
#endif /* GL_ARB_texture_env_dot3 */
#ifdef GL_ARB_texture_mirrored_repeat
  GLEW_ARB_texture_mirrored_repeat = glewGetExtension("GL_ARB_texture_mirrored_repeat");
#endif /* GL_ARB_texture_mirrored_repeat */
#ifdef GL_ARB_texture_non_power_of_two
  GLEW_ARB_texture_non_power_of_two = glewGetExtension("GL_ARB_texture_non_power_of_two");
#endif /* GL_ARB_texture_non_power_of_two */
#ifdef GL_ARB_transpose_matrix
  GLEW_ARB_transpose_matrix = glewGetExtension("GL_ARB_transpose_matrix");
#endif /* GL_ARB_transpose_matrix */
#ifdef GL_ARB_vertex_blend
  GLEW_ARB_vertex_blend = glewGetExtension("GL_ARB_vertex_blend");
  if (glewExperimental || GLEW_ARB_vertex_blend) GLEW_ARB_vertex_blend = !_glewInit_GL_ARB_vertex_blend();
#endif /* GL_ARB_vertex_blend */
#ifdef GL_ARB_vertex_buffer_object
  GLEW_ARB_vertex_buffer_object = glewGetExtension("GL_ARB_vertex_buffer_object");
  if (glewExperimental || GLEW_ARB_vertex_buffer_object) GLEW_ARB_vertex_buffer_object = !_glewInit_GL_ARB_vertex_buffer_object();
#endif /* GL_ARB_vertex_buffer_object */
#ifdef GL_ARB_vertex_program
  GLEW_ARB_vertex_program = glewGetExtension("GL_ARB_vertex_program");
  if (glewExperimental || GLEW_ARB_vertex_program) GLEW_ARB_vertex_program = !_glewInit_GL_ARB_vertex_program();
#endif /* GL_ARB_vertex_program */
#ifdef GL_ARB_window_pos
  GLEW_ARB_window_pos = glewGetExtension("GL_ARB_window_pos");
  if (glewExperimental || GLEW_ARB_window_pos) GLEW_ARB_window_pos = !_glewInit_GL_ARB_window_pos();
#endif /* GL_ARB_window_pos */
#ifdef GL_ATIX_point_sprites
  GLEW_ATIX_point_sprites = glewGetExtension("GL_ATIX_point_sprites");
#endif /* GL_ATIX_point_sprites */
#ifdef GL_ATIX_texture_env_combine3
  GLEW_ATIX_texture_env_combine3 = glewGetExtension("GL_ATIX_texture_env_combine3");
#endif /* GL_ATIX_texture_env_combine3 */
#ifdef GL_ATIX_texture_env_route
  GLEW_ATIX_texture_env_route = glewGetExtension("GL_ATIX_texture_env_route");
#endif /* GL_ATIX_texture_env_route */
#ifdef GL_ATIX_vertex_shader_output_point_size
  GLEW_ATIX_vertex_shader_output_point_size = glewGetExtension("GL_ATIX_vertex_shader_output_point_size");
#endif /* GL_ATIX_vertex_shader_output_point_size */
#ifdef GL_ATI_draw_buffers
  GLEW_ATI_draw_buffers = glewGetExtension("GL_ATI_draw_buffers");
  if (glewExperimental || GLEW_ATI_draw_buffers) GLEW_ATI_draw_buffers = !_glewInit_GL_ATI_draw_buffers();
#endif /* GL_ATI_draw_buffers */
#ifdef GL_ATI_element_array
  GLEW_ATI_element_array = glewGetExtension("GL_ATI_element_array");
  if (glewExperimental || GLEW_ATI_element_array) GLEW_ATI_element_array = !_glewInit_GL_ATI_element_array();
#endif /* GL_ATI_element_array */
#ifdef GL_ATI_envmap_bumpmap
  GLEW_ATI_envmap_bumpmap = glewGetExtension("GL_ATI_envmap_bumpmap");
  if (glewExperimental || GLEW_ATI_envmap_bumpmap) GLEW_ATI_envmap_bumpmap = !_glewInit_GL_ATI_envmap_bumpmap();
#endif /* GL_ATI_envmap_bumpmap */
#ifdef GL_ATI_fragment_shader
  GLEW_ATI_fragment_shader = glewGetExtension("GL_ATI_fragment_shader");
  if (glewExperimental || GLEW_ATI_fragment_shader) GLEW_ATI_fragment_shader = !_glewInit_GL_ATI_fragment_shader();
#endif /* GL_ATI_fragment_shader */
#ifdef GL_ATI_map_object_buffer
  GLEW_ATI_map_object_buffer = glewGetExtension("GL_ATI_map_object_buffer");
  if (glewExperimental || GLEW_ATI_map_object_buffer) GLEW_ATI_map_object_buffer = !_glewInit_GL_ATI_map_object_buffer();
#endif /* GL_ATI_map_object_buffer */
#ifdef GL_ATI_pn_triangles
  GLEW_ATI_pn_triangles = glewGetExtension("GL_ATI_pn_triangles");
  if (glewExperimental || GLEW_ATI_pn_triangles) GLEW_ATI_pn_triangles = !_glewInit_GL_ATI_pn_triangles();
#endif /* GL_ATI_pn_triangles */
#ifdef GL_ATI_separate_stencil
  GLEW_ATI_separate_stencil = glewGetExtension("GL_ATI_separate_stencil");
  if (glewExperimental || GLEW_ATI_separate_stencil) GLEW_ATI_separate_stencil = !_glewInit_GL_ATI_separate_stencil();
#endif /* GL_ATI_separate_stencil */
#ifdef GL_ATI_text_fragment_shader
  GLEW_ATI_text_fragment_shader = glewGetExtension("GL_ATI_text_fragment_shader");
#endif /* GL_ATI_text_fragment_shader */
#ifdef GL_ATI_texture_env_combine3
  GLEW_ATI_texture_env_combine3 = glewGetExtension("GL_ATI_texture_env_combine3");
#endif /* GL_ATI_texture_env_combine3 */
#ifdef GL_ATI_texture_float
  GLEW_ATI_texture_float = glewGetExtension("GL_ATI_texture_float");
#endif /* GL_ATI_texture_float */
#ifdef GL_ATI_texture_mirror_once
  GLEW_ATI_texture_mirror_once = glewGetExtension("GL_ATI_texture_mirror_once");
#endif /* GL_ATI_texture_mirror_once */
#ifdef GL_ATI_vertex_array_object
  GLEW_ATI_vertex_array_object = glewGetExtension("GL_ATI_vertex_array_object");
  if (glewExperimental || GLEW_ATI_vertex_array_object) GLEW_ATI_vertex_array_object = !_glewInit_GL_ATI_vertex_array_object();
#endif /* GL_ATI_vertex_array_object */
#ifdef GL_ATI_vertex_attrib_array_object
  GLEW_ATI_vertex_attrib_array_object = glewGetExtension("GL_ATI_vertex_attrib_array_object");
  if (glewExperimental || GLEW_ATI_vertex_attrib_array_object) GLEW_ATI_vertex_attrib_array_object = !_glewInit_GL_ATI_vertex_attrib_array_object();
#endif /* GL_ATI_vertex_attrib_array_object */
#ifdef GL_ATI_vertex_streams
  GLEW_ATI_vertex_streams = glewGetExtension("GL_ATI_vertex_streams");
  if (glewExperimental || GLEW_ATI_vertex_streams) GLEW_ATI_vertex_streams = !_glewInit_GL_ATI_vertex_streams();
#endif /* GL_ATI_vertex_streams */
#ifdef GL_EXT_422_pixels
  GLEW_EXT_422_pixels = glewGetExtension("GL_EXT_422_pixels");
#endif /* GL_EXT_422_pixels */
#ifdef GL_EXT_abgr
  GLEW_EXT_abgr = glewGetExtension("GL_EXT_abgr");
#endif /* GL_EXT_abgr */
#ifdef GL_EXT_bgra
  GLEW_EXT_bgra = glewGetExtension("GL_EXT_bgra");
#endif /* GL_EXT_bgra */
#ifdef GL_EXT_blend_color
  GLEW_EXT_blend_color = glewGetExtension("GL_EXT_blend_color");
  if (glewExperimental || GLEW_EXT_blend_color) GLEW_EXT_blend_color = !_glewInit_GL_EXT_blend_color();
#endif /* GL_EXT_blend_color */
#ifdef GL_EXT_blend_func_separate
  GLEW_EXT_blend_func_separate = glewGetExtension("GL_EXT_blend_func_separate");
  if (glewExperimental || GLEW_EXT_blend_func_separate) GLEW_EXT_blend_func_separate = !_glewInit_GL_EXT_blend_func_separate();
#endif /* GL_EXT_blend_func_separate */
#ifdef GL_EXT_blend_logic_op
  GLEW_EXT_blend_logic_op = glewGetExtension("GL_EXT_blend_logic_op");
#endif /* GL_EXT_blend_logic_op */
#ifdef GL_EXT_blend_minmax
  GLEW_EXT_blend_minmax = glewGetExtension("GL_EXT_blend_minmax");
  if (glewExperimental || GLEW_EXT_blend_minmax) GLEW_EXT_blend_minmax = !_glewInit_GL_EXT_blend_minmax();
#endif /* GL_EXT_blend_minmax */
#ifdef GL_EXT_blend_subtract
  GLEW_EXT_blend_subtract = glewGetExtension("GL_EXT_blend_subtract");
#endif /* GL_EXT_blend_subtract */
#ifdef GL_EXT_clip_volume_hint
  GLEW_EXT_clip_volume_hint = glewGetExtension("GL_EXT_clip_volume_hint");
#endif /* GL_EXT_clip_volume_hint */
#ifdef GL_EXT_cmyka
  GLEW_EXT_cmyka = glewGetExtension("GL_EXT_cmyka");
#endif /* GL_EXT_cmyka */
#ifdef GL_EXT_color_subtable
  GLEW_EXT_color_subtable = glewGetExtension("GL_EXT_color_subtable");
  if (glewExperimental || GLEW_EXT_color_subtable) GLEW_EXT_color_subtable = !_glewInit_GL_EXT_color_subtable();
#endif /* GL_EXT_color_subtable */
#ifdef GL_EXT_compiled_vertex_array
  GLEW_EXT_compiled_vertex_array = glewGetExtension("GL_EXT_compiled_vertex_array");
  if (glewExperimental || GLEW_EXT_compiled_vertex_array) GLEW_EXT_compiled_vertex_array = !_glewInit_GL_EXT_compiled_vertex_array();
#endif /* GL_EXT_compiled_vertex_array */
#ifdef GL_EXT_convolution
  GLEW_EXT_convolution = glewGetExtension("GL_EXT_convolution");
  if (glewExperimental || GLEW_EXT_convolution) GLEW_EXT_convolution = !_glewInit_GL_EXT_convolution();
#endif /* GL_EXT_convolution */
#ifdef GL_EXT_coordinate_frame
  GLEW_EXT_coordinate_frame = glewGetExtension("GL_EXT_coordinate_frame");
  if (glewExperimental || GLEW_EXT_coordinate_frame) GLEW_EXT_coordinate_frame = !_glewInit_GL_EXT_coordinate_frame();
#endif /* GL_EXT_coordinate_frame */
#ifdef GL_EXT_copy_texture
  GLEW_EXT_copy_texture = glewGetExtension("GL_EXT_copy_texture");
  if (glewExperimental || GLEW_EXT_copy_texture) GLEW_EXT_copy_texture = !_glewInit_GL_EXT_copy_texture();
#endif /* GL_EXT_copy_texture */
#ifdef GL_EXT_cull_vertex
  GLEW_EXT_cull_vertex = glewGetExtension("GL_EXT_cull_vertex");
  if (glewExperimental || GLEW_EXT_cull_vertex) GLEW_EXT_cull_vertex = !_glewInit_GL_EXT_cull_vertex();
#endif /* GL_EXT_cull_vertex */
#ifdef GL_EXT_depth_bounds_test
  GLEW_EXT_depth_bounds_test = glewGetExtension("GL_EXT_depth_bounds_test");
  if (glewExperimental || GLEW_EXT_depth_bounds_test) GLEW_EXT_depth_bounds_test = !_glewInit_GL_EXT_depth_bounds_test();
#endif /* GL_EXT_depth_bounds_test */
#ifdef GL_EXT_draw_range_elements
  GLEW_EXT_draw_range_elements = glewGetExtension("GL_EXT_draw_range_elements");
#endif /* GL_EXT_draw_range_elements */
#ifdef GL_EXT_fog_coord
  GLEW_EXT_fog_coord = glewGetExtension("GL_EXT_fog_coord");
  if (glewExperimental || GLEW_EXT_fog_coord) GLEW_EXT_fog_coord = !_glewInit_GL_EXT_fog_coord();
#endif /* GL_EXT_fog_coord */
#ifdef GL_EXT_fragment_lighting
  GLEW_EXT_fragment_lighting = glewGetExtension("GL_EXT_fragment_lighting");
  if (glewExperimental || GLEW_EXT_fragment_lighting) GLEW_EXT_fragment_lighting = !_glewInit_GL_EXT_fragment_lighting();
#endif /* GL_EXT_fragment_lighting */
#ifdef GL_EXT_histogram
  GLEW_EXT_histogram = glewGetExtension("GL_EXT_histogram");
  if (glewExperimental || GLEW_EXT_histogram) GLEW_EXT_histogram = !_glewInit_GL_EXT_histogram();
#endif /* GL_EXT_histogram */
#ifdef GL_EXT_index_array_formats
  GLEW_EXT_index_array_formats = glewGetExtension("GL_EXT_index_array_formats");
#endif /* GL_EXT_index_array_formats */
#ifdef GL_EXT_index_func
  GLEW_EXT_index_func = glewGetExtension("GL_EXT_index_func");
  if (glewExperimental || GLEW_EXT_index_func) GLEW_EXT_index_func = !_glewInit_GL_EXT_index_func();
#endif /* GL_EXT_index_func */
#ifdef GL_EXT_index_material
  GLEW_EXT_index_material = glewGetExtension("GL_EXT_index_material");
  if (glewExperimental || GLEW_EXT_index_material) GLEW_EXT_index_material = !_glewInit_GL_EXT_index_material();
#endif /* GL_EXT_index_material */
#ifdef GL_EXT_index_texture
  GLEW_EXT_index_texture = glewGetExtension("GL_EXT_index_texture");
#endif /* GL_EXT_index_texture */
#ifdef GL_EXT_light_texture
  GLEW_EXT_light_texture = glewGetExtension("GL_EXT_light_texture");
  if (glewExperimental || GLEW_EXT_light_texture) GLEW_EXT_light_texture = !_glewInit_GL_EXT_light_texture();
#endif /* GL_EXT_light_texture */
#ifdef GL_EXT_misc_attribute
  GLEW_EXT_misc_attribute = glewGetExtension("GL_EXT_misc_attribute");
#endif /* GL_EXT_misc_attribute */
#ifdef GL_EXT_multi_draw_arrays
  GLEW_EXT_multi_draw_arrays = glewGetExtension("GL_EXT_multi_draw_arrays");
  if (glewExperimental || GLEW_EXT_multi_draw_arrays) GLEW_EXT_multi_draw_arrays = !_glewInit_GL_EXT_multi_draw_arrays();
#endif /* GL_EXT_multi_draw_arrays */
#ifdef GL_EXT_multisample
  GLEW_EXT_multisample = glewGetExtension("GL_EXT_multisample");
  if (glewExperimental || GLEW_EXT_multisample) GLEW_EXT_multisample = !_glewInit_GL_EXT_multisample();
#endif /* GL_EXT_multisample */
#ifdef GL_EXT_packed_pixels
  GLEW_EXT_packed_pixels = glewGetExtension("GL_EXT_packed_pixels");
#endif /* GL_EXT_packed_pixels */
#ifdef GL_EXT_paletted_texture
  GLEW_EXT_paletted_texture = glewGetExtension("GL_EXT_paletted_texture");
  if (glewExperimental || GLEW_EXT_paletted_texture) GLEW_EXT_paletted_texture = !_glewInit_GL_EXT_paletted_texture();
#endif /* GL_EXT_paletted_texture */
#ifdef GL_EXT_pixel_transform
  GLEW_EXT_pixel_transform = glewGetExtension("GL_EXT_pixel_transform");
  if (glewExperimental || GLEW_EXT_pixel_transform) GLEW_EXT_pixel_transform = !_glewInit_GL_EXT_pixel_transform();
#endif /* GL_EXT_pixel_transform */
#ifdef GL_EXT_pixel_transform_color_table
  GLEW_EXT_pixel_transform_color_table = glewGetExtension("GL_EXT_pixel_transform_color_table");
#endif /* GL_EXT_pixel_transform_color_table */
#ifdef GL_EXT_point_parameters
  GLEW_EXT_point_parameters = glewGetExtension("GL_EXT_point_parameters");
  if (glewExperimental || GLEW_EXT_point_parameters) GLEW_EXT_point_parameters = !_glewInit_GL_EXT_point_parameters();
#endif /* GL_EXT_point_parameters */
#ifdef GL_EXT_polygon_offset
  GLEW_EXT_polygon_offset = glewGetExtension("GL_EXT_polygon_offset");
  if (glewExperimental || GLEW_EXT_polygon_offset) GLEW_EXT_polygon_offset = !_glewInit_GL_EXT_polygon_offset();
#endif /* GL_EXT_polygon_offset */
#ifdef GL_EXT_rescale_normal
  GLEW_EXT_rescale_normal = glewGetExtension("GL_EXT_rescale_normal");
#endif /* GL_EXT_rescale_normal */
#ifdef GL_EXT_scene_marker
  GLEW_EXT_scene_marker = glewGetExtension("GL_EXT_scene_marker");
  if (glewExperimental || GLEW_EXT_scene_marker) GLEW_EXT_scene_marker = !_glewInit_GL_EXT_scene_marker();
#endif /* GL_EXT_scene_marker */
#ifdef GL_EXT_secondary_color
  GLEW_EXT_secondary_color = glewGetExtension("GL_EXT_secondary_color");
  if (glewExperimental || GLEW_EXT_secondary_color) GLEW_EXT_secondary_color = !_glewInit_GL_EXT_secondary_color();
#endif /* GL_EXT_secondary_color */
#ifdef GL_EXT_separate_specular_color
  GLEW_EXT_separate_specular_color = glewGetExtension("GL_EXT_separate_specular_color");
#endif /* GL_EXT_separate_specular_color */
#ifdef GL_EXT_shadow_funcs
  GLEW_EXT_shadow_funcs = glewGetExtension("GL_EXT_shadow_funcs");
#endif /* GL_EXT_shadow_funcs */
#ifdef GL_EXT_shared_texture_palette
  GLEW_EXT_shared_texture_palette = glewGetExtension("GL_EXT_shared_texture_palette");
#endif /* GL_EXT_shared_texture_palette */
#ifdef GL_EXT_stencil_two_side
  GLEW_EXT_stencil_two_side = glewGetExtension("GL_EXT_stencil_two_side");
  if (glewExperimental || GLEW_EXT_stencil_two_side) GLEW_EXT_stencil_two_side = !_glewInit_GL_EXT_stencil_two_side();
#endif /* GL_EXT_stencil_two_side */
#ifdef GL_EXT_stencil_wrap
  GLEW_EXT_stencil_wrap = glewGetExtension("GL_EXT_stencil_wrap");
#endif /* GL_EXT_stencil_wrap */
#ifdef GL_EXT_subtexture
  GLEW_EXT_subtexture = glewGetExtension("GL_EXT_subtexture");
  if (glewExperimental || GLEW_EXT_subtexture) GLEW_EXT_subtexture = !_glewInit_GL_EXT_subtexture();
#endif /* GL_EXT_subtexture */
#ifdef GL_EXT_texture
  GLEW_EXT_texture = glewGetExtension("GL_EXT_texture");
#endif /* GL_EXT_texture */
#ifdef GL_EXT_texture3D
  GLEW_EXT_texture3D = glewGetExtension("GL_EXT_texture3D");
  if (glewExperimental || GLEW_EXT_texture3D) GLEW_EXT_texture3D = !_glewInit_GL_EXT_texture3D();
#endif /* GL_EXT_texture3D */
#ifdef GL_EXT_texture_compression_s3tc
  GLEW_EXT_texture_compression_s3tc = glewGetExtension("GL_EXT_texture_compression_s3tc");
#endif /* GL_EXT_texture_compression_s3tc */
#ifdef GL_EXT_texture_env
  GLEW_EXT_texture_env = glewGetExtension("GL_EXT_texture_env");
#endif /* GL_EXT_texture_env */
#ifdef GL_EXT_texture_env_add
  GLEW_EXT_texture_env_add = glewGetExtension("GL_EXT_texture_env_add");
#endif /* GL_EXT_texture_env_add */
#ifdef GL_EXT_texture_env_combine
  GLEW_EXT_texture_env_combine = glewGetExtension("GL_EXT_texture_env_combine");
#endif /* GL_EXT_texture_env_combine */
#ifdef GL_EXT_texture_env_dot3
  GLEW_EXT_texture_env_dot3 = glewGetExtension("GL_EXT_texture_env_dot3");
#endif /* GL_EXT_texture_env_dot3 */
#ifdef GL_EXT_texture_filter_anisotropic
  GLEW_EXT_texture_filter_anisotropic = glewGetExtension("GL_EXT_texture_filter_anisotropic");
#endif /* GL_EXT_texture_filter_anisotropic */
#ifdef GL_EXT_texture_lod_bias
  GLEW_EXT_texture_lod_bias = glewGetExtension("GL_EXT_texture_lod_bias");
#endif /* GL_EXT_texture_lod_bias */
#ifdef GL_EXT_texture_mirror_clamp
  GLEW_EXT_texture_mirror_clamp = glewGetExtension("GL_EXT_texture_mirror_clamp");
#endif /* GL_EXT_texture_mirror_clamp */
#ifdef GL_EXT_texture_object
  GLEW_EXT_texture_object = glewGetExtension("GL_EXT_texture_object");
  if (glewExperimental || GLEW_EXT_texture_object) GLEW_EXT_texture_object = !_glewInit_GL_EXT_texture_object();
#endif /* GL_EXT_texture_object */
#ifdef GL_EXT_texture_perturb_normal
  GLEW_EXT_texture_perturb_normal = glewGetExtension("GL_EXT_texture_perturb_normal");
  if (glewExperimental || GLEW_EXT_texture_perturb_normal) GLEW_EXT_texture_perturb_normal = !_glewInit_GL_EXT_texture_perturb_normal();
#endif /* GL_EXT_texture_perturb_normal */
#ifdef GL_EXT_texture_rectangle
  GLEW_EXT_texture_rectangle = glewGetExtension("GL_EXT_texture_rectangle");
#endif /* GL_EXT_texture_rectangle */
#ifdef GL_EXT_vertex_array
  GLEW_EXT_vertex_array = glewGetExtension("GL_EXT_vertex_array");
  if (glewExperimental || GLEW_EXT_vertex_array) GLEW_EXT_vertex_array = !_glewInit_GL_EXT_vertex_array();
#endif /* GL_EXT_vertex_array */
#ifdef GL_EXT_vertex_shader
  GLEW_EXT_vertex_shader = glewGetExtension("GL_EXT_vertex_shader");
  if (glewExperimental || GLEW_EXT_vertex_shader) GLEW_EXT_vertex_shader = !_glewInit_GL_EXT_vertex_shader();
#endif /* GL_EXT_vertex_shader */
#ifdef GL_EXT_vertex_weighting
  GLEW_EXT_vertex_weighting = glewGetExtension("GL_EXT_vertex_weighting");
  if (glewExperimental || GLEW_EXT_vertex_weighting) GLEW_EXT_vertex_weighting = !_glewInit_GL_EXT_vertex_weighting();
#endif /* GL_EXT_vertex_weighting */
#ifdef GL_HP_convolution_border_modes
  GLEW_HP_convolution_border_modes = glewGetExtension("GL_HP_convolution_border_modes");
#endif /* GL_HP_convolution_border_modes */
#ifdef GL_HP_image_transform
  GLEW_HP_image_transform = glewGetExtension("GL_HP_image_transform");
  if (glewExperimental || GLEW_HP_image_transform) GLEW_HP_image_transform = !_glewInit_GL_HP_image_transform();
#endif /* GL_HP_image_transform */
#ifdef GL_HP_occlusion_test
  GLEW_HP_occlusion_test = glewGetExtension("GL_HP_occlusion_test");
#endif /* GL_HP_occlusion_test */
#ifdef GL_HP_texture_lighting
  GLEW_HP_texture_lighting = glewGetExtension("GL_HP_texture_lighting");
#endif /* GL_HP_texture_lighting */
#ifdef GL_IBM_cull_vertex
  GLEW_IBM_cull_vertex = glewGetExtension("GL_IBM_cull_vertex");
#endif /* GL_IBM_cull_vertex */
#ifdef GL_IBM_multimode_draw_arrays
  GLEW_IBM_multimode_draw_arrays = glewGetExtension("GL_IBM_multimode_draw_arrays");
  if (glewExperimental || GLEW_IBM_multimode_draw_arrays) GLEW_IBM_multimode_draw_arrays = !_glewInit_GL_IBM_multimode_draw_arrays();
#endif /* GL_IBM_multimode_draw_arrays */
#ifdef GL_IBM_rasterpos_clip
  GLEW_IBM_rasterpos_clip = glewGetExtension("GL_IBM_rasterpos_clip");
#endif /* GL_IBM_rasterpos_clip */
#ifdef GL_IBM_static_data
  GLEW_IBM_static_data = glewGetExtension("GL_IBM_static_data");
#endif /* GL_IBM_static_data */
#ifdef GL_IBM_texture_mirrored_repeat
  GLEW_IBM_texture_mirrored_repeat = glewGetExtension("GL_IBM_texture_mirrored_repeat");
#endif /* GL_IBM_texture_mirrored_repeat */
#ifdef GL_IBM_vertex_array_lists
  GLEW_IBM_vertex_array_lists = glewGetExtension("GL_IBM_vertex_array_lists");
  if (glewExperimental || GLEW_IBM_vertex_array_lists) GLEW_IBM_vertex_array_lists = !_glewInit_GL_IBM_vertex_array_lists();
#endif /* GL_IBM_vertex_array_lists */
#ifdef GL_INGR_color_clamp
  GLEW_INGR_color_clamp = glewGetExtension("GL_INGR_color_clamp");
#endif /* GL_INGR_color_clamp */
#ifdef GL_INGR_interlace_read
  GLEW_INGR_interlace_read = glewGetExtension("GL_INGR_interlace_read");
#endif /* GL_INGR_interlace_read */
#ifdef GL_INTEL_parallel_arrays
  GLEW_INTEL_parallel_arrays = glewGetExtension("GL_INTEL_parallel_arrays");
  if (glewExperimental || GLEW_INTEL_parallel_arrays) GLEW_INTEL_parallel_arrays = !_glewInit_GL_INTEL_parallel_arrays();
#endif /* GL_INTEL_parallel_arrays */
#ifdef GL_INTEL_texture_scissor
  GLEW_INTEL_texture_scissor = glewGetExtension("GL_INTEL_texture_scissor");
  if (glewExperimental || GLEW_INTEL_texture_scissor) GLEW_INTEL_texture_scissor = !_glewInit_GL_INTEL_texture_scissor();
#endif /* GL_INTEL_texture_scissor */
#ifdef GL_MESA_resize_buffers
  GLEW_MESA_resize_buffers = glewGetExtension("GL_MESA_resize_buffers");
  if (glewExperimental || GLEW_MESA_resize_buffers) GLEW_MESA_resize_buffers = !_glewInit_GL_MESA_resize_buffers();
#endif /* GL_MESA_resize_buffers */
#ifdef GL_MESA_window_pos
  GLEW_MESA_window_pos = glewGetExtension("GL_MESA_window_pos");
  if (glewExperimental || GLEW_MESA_window_pos) GLEW_MESA_window_pos = !_glewInit_GL_MESA_window_pos();
#endif /* GL_MESA_window_pos */
#ifdef GL_NV_blend_square
  GLEW_NV_blend_square = glewGetExtension("GL_NV_blend_square");
#endif /* GL_NV_blend_square */
#ifdef GL_NV_copy_depth_to_color
  GLEW_NV_copy_depth_to_color = glewGetExtension("GL_NV_copy_depth_to_color");
#endif /* GL_NV_copy_depth_to_color */
#ifdef GL_NV_depth_clamp
  GLEW_NV_depth_clamp = glewGetExtension("GL_NV_depth_clamp");
#endif /* GL_NV_depth_clamp */
#ifdef GL_NV_element_array
  GLEW_NV_element_array = glewGetExtension("GL_NV_element_array");
  if (glewExperimental || GLEW_NV_element_array) GLEW_NV_element_array = !_glewInit_GL_NV_element_array();
#endif /* GL_NV_element_array */
#ifdef GL_NV_evaluators
  GLEW_NV_evaluators = glewGetExtension("GL_NV_evaluators");
  if (glewExperimental || GLEW_NV_evaluators) GLEW_NV_evaluators = !_glewInit_GL_NV_evaluators();
#endif /* GL_NV_evaluators */
#ifdef GL_NV_fence
  GLEW_NV_fence = glewGetExtension("GL_NV_fence");
  if (glewExperimental || GLEW_NV_fence) GLEW_NV_fence = !_glewInit_GL_NV_fence();
#endif /* GL_NV_fence */
#ifdef GL_NV_float_buffer
  GLEW_NV_float_buffer = glewGetExtension("GL_NV_float_buffer");
#endif /* GL_NV_float_buffer */
#ifdef GL_NV_fog_distance
  GLEW_NV_fog_distance = glewGetExtension("GL_NV_fog_distance");
#endif /* GL_NV_fog_distance */
#ifdef GL_NV_fragment_program
  GLEW_NV_fragment_program = glewGetExtension("GL_NV_fragment_program");
  if (glewExperimental || GLEW_NV_fragment_program) GLEW_NV_fragment_program = !_glewInit_GL_NV_fragment_program();
#endif /* GL_NV_fragment_program */
#ifdef GL_NV_half_float
  GLEW_NV_half_float = glewGetExtension("GL_NV_half_float");
  if (glewExperimental || GLEW_NV_half_float) GLEW_NV_half_float = !_glewInit_GL_NV_half_float();
#endif /* GL_NV_half_float */
#ifdef GL_NV_light_max_exponent
  GLEW_NV_light_max_exponent = glewGetExtension("GL_NV_light_max_exponent");
#endif /* GL_NV_light_max_exponent */
#ifdef GL_NV_multisample_filter_hint
  GLEW_NV_multisample_filter_hint = glewGetExtension("GL_NV_multisample_filter_hint");
#endif /* GL_NV_multisample_filter_hint */
#ifdef GL_NV_occlusion_query
  GLEW_NV_occlusion_query = glewGetExtension("GL_NV_occlusion_query");
  if (glewExperimental || GLEW_NV_occlusion_query) GLEW_NV_occlusion_query = !_glewInit_GL_NV_occlusion_query();
#endif /* GL_NV_occlusion_query */
#ifdef GL_NV_packed_depth_stencil
  GLEW_NV_packed_depth_stencil = glewGetExtension("GL_NV_packed_depth_stencil");
#endif /* GL_NV_packed_depth_stencil */
#ifdef GL_NV_pixel_data_range
  GLEW_NV_pixel_data_range = glewGetExtension("GL_NV_pixel_data_range");
  if (glewExperimental || GLEW_NV_pixel_data_range) GLEW_NV_pixel_data_range = !_glewInit_GL_NV_pixel_data_range();
#endif /* GL_NV_pixel_data_range */
#ifdef GL_NV_point_sprite
  GLEW_NV_point_sprite = glewGetExtension("GL_NV_point_sprite");
  if (glewExperimental || GLEW_NV_point_sprite) GLEW_NV_point_sprite = !_glewInit_GL_NV_point_sprite();
#endif /* GL_NV_point_sprite */
#ifdef GL_NV_primitive_restart
  GLEW_NV_primitive_restart = glewGetExtension("GL_NV_primitive_restart");
  if (glewExperimental || GLEW_NV_primitive_restart) GLEW_NV_primitive_restart = !_glewInit_GL_NV_primitive_restart();
#endif /* GL_NV_primitive_restart */
#ifdef GL_NV_register_combiners
  GLEW_NV_register_combiners = glewGetExtension("GL_NV_register_combiners");
  if (glewExperimental || GLEW_NV_register_combiners) GLEW_NV_register_combiners = !_glewInit_GL_NV_register_combiners();
#endif /* GL_NV_register_combiners */
#ifdef GL_NV_register_combiners2
  GLEW_NV_register_combiners2 = glewGetExtension("GL_NV_register_combiners2");
  if (glewExperimental || GLEW_NV_register_combiners2) GLEW_NV_register_combiners2 = !_glewInit_GL_NV_register_combiners2();
#endif /* GL_NV_register_combiners2 */
#ifdef GL_NV_texgen_emboss
  GLEW_NV_texgen_emboss = glewGetExtension("GL_NV_texgen_emboss");
#endif /* GL_NV_texgen_emboss */
#ifdef GL_NV_texgen_reflection
  GLEW_NV_texgen_reflection = glewGetExtension("GL_NV_texgen_reflection");
#endif /* GL_NV_texgen_reflection */
#ifdef GL_NV_texture_compression_vtc
  GLEW_NV_texture_compression_vtc = glewGetExtension("GL_NV_texture_compression_vtc");
#endif /* GL_NV_texture_compression_vtc */
#ifdef GL_NV_texture_env_combine4
  GLEW_NV_texture_env_combine4 = glewGetExtension("GL_NV_texture_env_combine4");
#endif /* GL_NV_texture_env_combine4 */
#ifdef GL_NV_texture_expand_normal
  GLEW_NV_texture_expand_normal = glewGetExtension("GL_NV_texture_expand_normal");
#endif /* GL_NV_texture_expand_normal */
#ifdef GL_NV_texture_rectangle
  GLEW_NV_texture_rectangle = glewGetExtension("GL_NV_texture_rectangle");
#endif /* GL_NV_texture_rectangle */
#ifdef GL_NV_texture_shader
  GLEW_NV_texture_shader = glewGetExtension("GL_NV_texture_shader");
#endif /* GL_NV_texture_shader */
#ifdef GL_NV_texture_shader2
  GLEW_NV_texture_shader2 = glewGetExtension("GL_NV_texture_shader2");
#endif /* GL_NV_texture_shader2 */
#ifdef GL_NV_texture_shader3
  GLEW_NV_texture_shader3 = glewGetExtension("GL_NV_texture_shader3");
#endif /* GL_NV_texture_shader3 */
#ifdef GL_NV_vertex_array_range
  GLEW_NV_vertex_array_range = glewGetExtension("GL_NV_vertex_array_range");
  if (glewExperimental || GLEW_NV_vertex_array_range) GLEW_NV_vertex_array_range = !_glewInit_GL_NV_vertex_array_range();
#endif /* GL_NV_vertex_array_range */
#ifdef GL_NV_vertex_array_range2
  GLEW_NV_vertex_array_range2 = glewGetExtension("GL_NV_vertex_array_range2");
#endif /* GL_NV_vertex_array_range2 */
#ifdef GL_NV_vertex_program
  GLEW_NV_vertex_program = glewGetExtension("GL_NV_vertex_program");
  if (glewExperimental || GLEW_NV_vertex_program) GLEW_NV_vertex_program = !_glewInit_GL_NV_vertex_program();
#endif /* GL_NV_vertex_program */
#ifdef GL_NV_vertex_program1_1
  GLEW_NV_vertex_program1_1 = glewGetExtension("GL_NV_vertex_program1_1");
#endif /* GL_NV_vertex_program1_1 */
#ifdef GL_NV_vertex_program2
  GLEW_NV_vertex_program2 = glewGetExtension("GL_NV_vertex_program2");
#endif /* GL_NV_vertex_program2 */
#ifdef GL_OML_interlace
  GLEW_OML_interlace = glewGetExtension("GL_OML_interlace");
#endif /* GL_OML_interlace */
#ifdef GL_OML_resample
  GLEW_OML_resample = glewGetExtension("GL_OML_resample");
#endif /* GL_OML_resample */
#ifdef GL_OML_subsample
  GLEW_OML_subsample = glewGetExtension("GL_OML_subsample");
#endif /* GL_OML_subsample */
#ifdef GL_PGI_misc_hints
  GLEW_PGI_misc_hints = glewGetExtension("GL_PGI_misc_hints");
#endif /* GL_PGI_misc_hints */
#ifdef GL_PGI_vertex_hints
  GLEW_PGI_vertex_hints = glewGetExtension("GL_PGI_vertex_hints");
#endif /* GL_PGI_vertex_hints */
#ifdef GL_REND_screen_coordinates
  GLEW_REND_screen_coordinates = glewGetExtension("GL_REND_screen_coordinates");
#endif /* GL_REND_screen_coordinates */
#ifdef GL_S3_s3tc
  GLEW_S3_s3tc = glewGetExtension("GL_S3_s3tc");
#endif /* GL_S3_s3tc */
#ifdef GL_SGIS_color_range
  GLEW_SGIS_color_range = glewGetExtension("GL_SGIS_color_range");
#endif /* GL_SGIS_color_range */
#ifdef GL_SGIS_detail_texture
  GLEW_SGIS_detail_texture = glewGetExtension("GL_SGIS_detail_texture");
  if (glewExperimental || GLEW_SGIS_detail_texture) GLEW_SGIS_detail_texture = !_glewInit_GL_SGIS_detail_texture();
#endif /* GL_SGIS_detail_texture */
#ifdef GL_SGIS_fog_function
  GLEW_SGIS_fog_function = glewGetExtension("GL_SGIS_fog_function");
  if (glewExperimental || GLEW_SGIS_fog_function) GLEW_SGIS_fog_function = !_glewInit_GL_SGIS_fog_function();
#endif /* GL_SGIS_fog_function */
#ifdef GL_SGIS_generate_mipmap
  GLEW_SGIS_generate_mipmap = glewGetExtension("GL_SGIS_generate_mipmap");
#endif /* GL_SGIS_generate_mipmap */
#ifdef GL_SGIS_multisample
  GLEW_SGIS_multisample = glewGetExtension("GL_SGIS_multisample");
  if (glewExperimental || GLEW_SGIS_multisample) GLEW_SGIS_multisample = !_glewInit_GL_SGIS_multisample();
#endif /* GL_SGIS_multisample */
#ifdef GL_SGIS_pixel_texture
  GLEW_SGIS_pixel_texture = glewGetExtension("GL_SGIS_pixel_texture");
#endif /* GL_SGIS_pixel_texture */
#ifdef GL_SGIS_sharpen_texture
  GLEW_SGIS_sharpen_texture = glewGetExtension("GL_SGIS_sharpen_texture");
  if (glewExperimental || GLEW_SGIS_sharpen_texture) GLEW_SGIS_sharpen_texture = !_glewInit_GL_SGIS_sharpen_texture();
#endif /* GL_SGIS_sharpen_texture */
#ifdef GL_SGIS_texture4D
  GLEW_SGIS_texture4D = glewGetExtension("GL_SGIS_texture4D");
  if (glewExperimental || GLEW_SGIS_texture4D) GLEW_SGIS_texture4D = !_glewInit_GL_SGIS_texture4D();
#endif /* GL_SGIS_texture4D */
#ifdef GL_SGIS_texture_border_clamp
  GLEW_SGIS_texture_border_clamp = glewGetExtension("GL_SGIS_texture_border_clamp");
#endif /* GL_SGIS_texture_border_clamp */
#ifdef GL_SGIS_texture_edge_clamp
  GLEW_SGIS_texture_edge_clamp = glewGetExtension("GL_SGIS_texture_edge_clamp");
#endif /* GL_SGIS_texture_edge_clamp */
#ifdef GL_SGIS_texture_filter4
  GLEW_SGIS_texture_filter4 = glewGetExtension("GL_SGIS_texture_filter4");
  if (glewExperimental || GLEW_SGIS_texture_filter4) GLEW_SGIS_texture_filter4 = !_glewInit_GL_SGIS_texture_filter4();
#endif /* GL_SGIS_texture_filter4 */
#ifdef GL_SGIS_texture_lod
  GLEW_SGIS_texture_lod = glewGetExtension("GL_SGIS_texture_lod");
#endif /* GL_SGIS_texture_lod */
#ifdef GL_SGIS_texture_select
  GLEW_SGIS_texture_select = glewGetExtension("GL_SGIS_texture_select");
#endif /* GL_SGIS_texture_select */
#ifdef GL_SGIX_async
  GLEW_SGIX_async = glewGetExtension("GL_SGIX_async");
  if (glewExperimental || GLEW_SGIX_async) GLEW_SGIX_async = !_glewInit_GL_SGIX_async();
#endif /* GL_SGIX_async */
#ifdef GL_SGIX_async_histogram
  GLEW_SGIX_async_histogram = glewGetExtension("GL_SGIX_async_histogram");
#endif /* GL_SGIX_async_histogram */
#ifdef GL_SGIX_async_pixel
  GLEW_SGIX_async_pixel = glewGetExtension("GL_SGIX_async_pixel");
#endif /* GL_SGIX_async_pixel */
#ifdef GL_SGIX_blend_alpha_minmax
  GLEW_SGIX_blend_alpha_minmax = glewGetExtension("GL_SGIX_blend_alpha_minmax");
#endif /* GL_SGIX_blend_alpha_minmax */
#ifdef GL_SGIX_clipmap
  GLEW_SGIX_clipmap = glewGetExtension("GL_SGIX_clipmap");
#endif /* GL_SGIX_clipmap */
#ifdef GL_SGIX_depth_texture
  GLEW_SGIX_depth_texture = glewGetExtension("GL_SGIX_depth_texture");
#endif /* GL_SGIX_depth_texture */
#ifdef GL_SGIX_flush_raster
  GLEW_SGIX_flush_raster = glewGetExtension("GL_SGIX_flush_raster");
  if (glewExperimental || GLEW_SGIX_flush_raster) GLEW_SGIX_flush_raster = !_glewInit_GL_SGIX_flush_raster();
#endif /* GL_SGIX_flush_raster */
#ifdef GL_SGIX_fog_offset
  GLEW_SGIX_fog_offset = glewGetExtension("GL_SGIX_fog_offset");
#endif /* GL_SGIX_fog_offset */
#ifdef GL_SGIX_fog_texture
  GLEW_SGIX_fog_texture = glewGetExtension("GL_SGIX_fog_texture");
  if (glewExperimental || GLEW_SGIX_fog_texture) GLEW_SGIX_fog_texture = !_glewInit_GL_SGIX_fog_texture();
#endif /* GL_SGIX_fog_texture */
#ifdef GL_SGIX_fragment_specular_lighting
  GLEW_SGIX_fragment_specular_lighting = glewGetExtension("GL_SGIX_fragment_specular_lighting");
  if (glewExperimental || GLEW_SGIX_fragment_specular_lighting) GLEW_SGIX_fragment_specular_lighting = !_glewInit_GL_SGIX_fragment_specular_lighting();
#endif /* GL_SGIX_fragment_specular_lighting */
#ifdef GL_SGIX_framezoom
  GLEW_SGIX_framezoom = glewGetExtension("GL_SGIX_framezoom");
  if (glewExperimental || GLEW_SGIX_framezoom) GLEW_SGIX_framezoom = !_glewInit_GL_SGIX_framezoom();
#endif /* GL_SGIX_framezoom */
#ifdef GL_SGIX_interlace
  GLEW_SGIX_interlace = glewGetExtension("GL_SGIX_interlace");
#endif /* GL_SGIX_interlace */
#ifdef GL_SGIX_ir_instrument1
  GLEW_SGIX_ir_instrument1 = glewGetExtension("GL_SGIX_ir_instrument1");
#endif /* GL_SGIX_ir_instrument1 */
#ifdef GL_SGIX_list_priority
  GLEW_SGIX_list_priority = glewGetExtension("GL_SGIX_list_priority");
#endif /* GL_SGIX_list_priority */
#ifdef GL_SGIX_pixel_texture
  GLEW_SGIX_pixel_texture = glewGetExtension("GL_SGIX_pixel_texture");
  if (glewExperimental || GLEW_SGIX_pixel_texture) GLEW_SGIX_pixel_texture = !_glewInit_GL_SGIX_pixel_texture();
#endif /* GL_SGIX_pixel_texture */
#ifdef GL_SGIX_pixel_texture_bits
  GLEW_SGIX_pixel_texture_bits = glewGetExtension("GL_SGIX_pixel_texture_bits");
#endif /* GL_SGIX_pixel_texture_bits */
#ifdef GL_SGIX_reference_plane
  GLEW_SGIX_reference_plane = glewGetExtension("GL_SGIX_reference_plane");
  if (glewExperimental || GLEW_SGIX_reference_plane) GLEW_SGIX_reference_plane = !_glewInit_GL_SGIX_reference_plane();
#endif /* GL_SGIX_reference_plane */
#ifdef GL_SGIX_resample
  GLEW_SGIX_resample = glewGetExtension("GL_SGIX_resample");
#endif /* GL_SGIX_resample */
#ifdef GL_SGIX_shadow
  GLEW_SGIX_shadow = glewGetExtension("GL_SGIX_shadow");
#endif /* GL_SGIX_shadow */
#ifdef GL_SGIX_shadow_ambient
  GLEW_SGIX_shadow_ambient = glewGetExtension("GL_SGIX_shadow_ambient");
#endif /* GL_SGIX_shadow_ambient */
#ifdef GL_SGIX_sprite
  GLEW_SGIX_sprite = glewGetExtension("GL_SGIX_sprite");
  if (glewExperimental || GLEW_SGIX_sprite) GLEW_SGIX_sprite = !_glewInit_GL_SGIX_sprite();
#endif /* GL_SGIX_sprite */
#ifdef GL_SGIX_tag_sample_buffer
  GLEW_SGIX_tag_sample_buffer = glewGetExtension("GL_SGIX_tag_sample_buffer");
  if (glewExperimental || GLEW_SGIX_tag_sample_buffer) GLEW_SGIX_tag_sample_buffer = !_glewInit_GL_SGIX_tag_sample_buffer();
#endif /* GL_SGIX_tag_sample_buffer */
#ifdef GL_SGIX_texture_add_env
  GLEW_SGIX_texture_add_env = glewGetExtension("GL_SGIX_texture_add_env");
#endif /* GL_SGIX_texture_add_env */
#ifdef GL_SGIX_texture_coordinate_clamp
  GLEW_SGIX_texture_coordinate_clamp = glewGetExtension("GL_SGIX_texture_coordinate_clamp");
#endif /* GL_SGIX_texture_coordinate_clamp */
#ifdef GL_SGIX_texture_lod_bias
  GLEW_SGIX_texture_lod_bias = glewGetExtension("GL_SGIX_texture_lod_bias");
#endif /* GL_SGIX_texture_lod_bias */
#ifdef GL_SGIX_texture_multi_buffer
  GLEW_SGIX_texture_multi_buffer = glewGetExtension("GL_SGIX_texture_multi_buffer");
#endif /* GL_SGIX_texture_multi_buffer */
#ifdef GL_SGIX_texture_range
  GLEW_SGIX_texture_range = glewGetExtension("GL_SGIX_texture_range");
#endif /* GL_SGIX_texture_range */
#ifdef GL_SGIX_texture_scale_bias
  GLEW_SGIX_texture_scale_bias = glewGetExtension("GL_SGIX_texture_scale_bias");
#endif /* GL_SGIX_texture_scale_bias */
#ifdef GL_SGIX_vertex_preclip
  GLEW_SGIX_vertex_preclip = glewGetExtension("GL_SGIX_vertex_preclip");
#endif /* GL_SGIX_vertex_preclip */
#ifdef GL_SGIX_vertex_preclip_hint
  GLEW_SGIX_vertex_preclip_hint = glewGetExtension("GL_SGIX_vertex_preclip_hint");
#endif /* GL_SGIX_vertex_preclip_hint */
#ifdef GL_SGIX_ycrcb
  GLEW_SGIX_ycrcb = glewGetExtension("GL_SGIX_ycrcb");
#endif /* GL_SGIX_ycrcb */
#ifdef GL_SGI_color_matrix
  GLEW_SGI_color_matrix = glewGetExtension("GL_SGI_color_matrix");
#endif /* GL_SGI_color_matrix */
#ifdef GL_SGI_color_table
  GLEW_SGI_color_table = glewGetExtension("GL_SGI_color_table");
  if (glewExperimental || GLEW_SGI_color_table) GLEW_SGI_color_table = !_glewInit_GL_SGI_color_table();
#endif /* GL_SGI_color_table */
#ifdef GL_SGI_texture_color_table
  GLEW_SGI_texture_color_table = glewGetExtension("GL_SGI_texture_color_table");
#endif /* GL_SGI_texture_color_table */
#ifdef GL_SUNX_constant_data
  GLEW_SUNX_constant_data = glewGetExtension("GL_SUNX_constant_data");
  if (glewExperimental || GLEW_SUNX_constant_data) GLEW_SUNX_constant_data = !_glewInit_GL_SUNX_constant_data();
#endif /* GL_SUNX_constant_data */
#ifdef GL_SUN_convolution_border_modes
  GLEW_SUN_convolution_border_modes = glewGetExtension("GL_SUN_convolution_border_modes");
#endif /* GL_SUN_convolution_border_modes */
#ifdef GL_SUN_global_alpha
  GLEW_SUN_global_alpha = glewGetExtension("GL_SUN_global_alpha");
  if (glewExperimental || GLEW_SUN_global_alpha) GLEW_SUN_global_alpha = !_glewInit_GL_SUN_global_alpha();
#endif /* GL_SUN_global_alpha */
#ifdef GL_SUN_mesh_array
  GLEW_SUN_mesh_array = glewGetExtension("GL_SUN_mesh_array");
#endif /* GL_SUN_mesh_array */
#ifdef GL_SUN_slice_accum
  GLEW_SUN_slice_accum = glewGetExtension("GL_SUN_slice_accum");
#endif /* GL_SUN_slice_accum */
#ifdef GL_SUN_triangle_list
  GLEW_SUN_triangle_list = glewGetExtension("GL_SUN_triangle_list");
  if (glewExperimental || GLEW_SUN_triangle_list) GLEW_SUN_triangle_list = !_glewInit_GL_SUN_triangle_list();
#endif /* GL_SUN_triangle_list */
#ifdef GL_SUN_vertex
  GLEW_SUN_vertex = glewGetExtension("GL_SUN_vertex");
  if (glewExperimental || GLEW_SUN_vertex) GLEW_SUN_vertex = !_glewInit_GL_SUN_vertex();
#endif /* GL_SUN_vertex */
#ifdef GL_WIN_phong_shading
  GLEW_WIN_phong_shading = glewGetExtension("GL_WIN_phong_shading");
#endif /* GL_WIN_phong_shading */
#ifdef GL_WIN_specular_fog
  GLEW_WIN_specular_fog = glewGetExtension("GL_WIN_specular_fog");
#endif /* GL_WIN_specular_fog */
#ifdef GL_WIN_swap_hint
  GLEW_WIN_swap_hint = glewGetExtension("GL_WIN_swap_hint");
  if (glewExperimental || GLEW_WIN_swap_hint) GLEW_WIN_swap_hint = !_glewInit_GL_WIN_swap_hint();
#endif /* GL_WIN_swap_hint */
  return GLEW_OK;
}

/* ------------------------------------------------------------------------- */

#ifdef _WIN32

GLboolean wglewGetExtension (const GLubyte *name)
{    
  GLubyte *p, *end;
  GLuint len = _glewStrLen(name);
  if (wglGetExtensionsStringARB == NULL)
    if (wglGetExtensionsStringEXT == NULL)
      return GL_FALSE;
    else
      p = (GLubyte*)wglGetExtensionsStringEXT();
  else
    p = (GLubyte*)wglGetExtensionsStringARB(wglGetCurrentDC());
  if (0 == p) return GL_FALSE;
  end = p + _glewStrLen(p);
  while (p < end)
  {
    GLuint n = _glewStrCLen(p, ' ');
    if (len == n && _glewStrSame(name, p, n)) return GL_TRUE;
    p += n+1;
  }
  return GL_FALSE;
}

static GLuint _wglewInit ()
{
  GLboolean crippled;
  /* find wgl extension string query functions */
  _glewInit_WGL_ARB_extensions_string();
  WGLEW_ARB_extensions_string = wglGetExtensionsStringARB != NULL;
  _glewInit_WGL_EXT_extensions_string();
  WGLEW_EXT_extensions_string = wglGetExtensionsStringEXT != NULL;
  /* initialize extensions */
  crippled = !(WGLEW_ARB_extensions_string || WGLEW_EXT_extensions_string);
#ifdef WGL_3DFX_multisample
  WGLEW_3DFX_multisample = wglewGetExtension("WGL_3DFX_multisample");
#endif /* WGL_3DFX_multisample */
#ifdef WGL_ARB_buffer_region
  WGLEW_ARB_buffer_region = wglewGetExtension("WGL_ARB_buffer_region");
  if (glewExperimental || WGLEW_ARB_buffer_region || crippled) WGLEW_ARB_buffer_region = !_glewInit_WGL_ARB_buffer_region();
#endif /* WGL_ARB_buffer_region */
#ifdef WGL_ARB_extensions_string
  WGLEW_ARB_extensions_string = wglewGetExtension("WGL_ARB_extensions_string");
  if (glewExperimental || WGLEW_ARB_extensions_string || crippled) WGLEW_ARB_extensions_string = !_glewInit_WGL_ARB_extensions_string();
#endif /* WGL_ARB_extensions_string */
#ifdef WGL_ARB_make_current_read
  WGLEW_ARB_make_current_read = wglewGetExtension("WGL_ARB_make_current_read");
  if (glewExperimental || WGLEW_ARB_make_current_read || crippled) WGLEW_ARB_make_current_read = !_glewInit_WGL_ARB_make_current_read();
#endif /* WGL_ARB_make_current_read */
#ifdef WGL_ARB_multisample
  WGLEW_ARB_multisample = wglewGetExtension("WGL_ARB_multisample");
#endif /* WGL_ARB_multisample */
#ifdef WGL_ARB_pbuffer
  WGLEW_ARB_pbuffer = wglewGetExtension("WGL_ARB_pbuffer");
  if (glewExperimental || WGLEW_ARB_pbuffer || crippled) WGLEW_ARB_pbuffer = !_glewInit_WGL_ARB_pbuffer();
#endif /* WGL_ARB_pbuffer */
#ifdef WGL_ARB_pixel_format
  WGLEW_ARB_pixel_format = wglewGetExtension("WGL_ARB_pixel_format");
  if (glewExperimental || WGLEW_ARB_pixel_format || crippled) WGLEW_ARB_pixel_format = !_glewInit_WGL_ARB_pixel_format();
#endif /* WGL_ARB_pixel_format */
#ifdef WGL_ARB_render_texture
  WGLEW_ARB_render_texture = wglewGetExtension("WGL_ARB_render_texture");
  if (glewExperimental || WGLEW_ARB_render_texture || crippled) WGLEW_ARB_render_texture = !_glewInit_WGL_ARB_render_texture();
#endif /* WGL_ARB_render_texture */
#ifdef WGL_ATI_pixel_format_float
  WGLEW_ATI_pixel_format_float = wglewGetExtension("WGL_ATI_pixel_format_float");
#endif /* WGL_ATI_pixel_format_float */
#ifdef WGL_EXT_depth_float
  WGLEW_EXT_depth_float = wglewGetExtension("WGL_EXT_depth_float");
#endif /* WGL_EXT_depth_float */
#ifdef WGL_EXT_display_color_table
  WGLEW_EXT_display_color_table = wglewGetExtension("WGL_EXT_display_color_table");
  if (glewExperimental || WGLEW_EXT_display_color_table || crippled) WGLEW_EXT_display_color_table = !_glewInit_WGL_EXT_display_color_table();
#endif /* WGL_EXT_display_color_table */
#ifdef WGL_EXT_extensions_string
  WGLEW_EXT_extensions_string = wglewGetExtension("WGL_EXT_extensions_string");
  if (glewExperimental || WGLEW_EXT_extensions_string || crippled) WGLEW_EXT_extensions_string = !_glewInit_WGL_EXT_extensions_string();
#endif /* WGL_EXT_extensions_string */
#ifdef WGL_EXT_make_current_read
  WGLEW_EXT_make_current_read = wglewGetExtension("WGL_EXT_make_current_read");
  if (glewExperimental || WGLEW_EXT_make_current_read || crippled) WGLEW_EXT_make_current_read = !_glewInit_WGL_EXT_make_current_read();
#endif /* WGL_EXT_make_current_read */
#ifdef WGL_EXT_multisample
  WGLEW_EXT_multisample = wglewGetExtension("WGL_EXT_multisample");
#endif /* WGL_EXT_multisample */
#ifdef WGL_EXT_pbuffer
  WGLEW_EXT_pbuffer = wglewGetExtension("WGL_EXT_pbuffer");
  if (glewExperimental || WGLEW_EXT_pbuffer || crippled) WGLEW_EXT_pbuffer = !_glewInit_WGL_EXT_pbuffer();
#endif /* WGL_EXT_pbuffer */
#ifdef WGL_EXT_pixel_format
  WGLEW_EXT_pixel_format = wglewGetExtension("WGL_EXT_pixel_format");
  if (glewExperimental || WGLEW_EXT_pixel_format || crippled) WGLEW_EXT_pixel_format = !_glewInit_WGL_EXT_pixel_format();
#endif /* WGL_EXT_pixel_format */
#ifdef WGL_EXT_swap_control
  WGLEW_EXT_swap_control = wglewGetExtension("WGL_EXT_swap_control");
  if (glewExperimental || WGLEW_EXT_swap_control || crippled) WGLEW_EXT_swap_control = !_glewInit_WGL_EXT_swap_control();
#endif /* WGL_EXT_swap_control */
#ifdef WGL_I3D_digital_video_control
  WGLEW_I3D_digital_video_control = wglewGetExtension("WGL_I3D_digital_video_control");
  if (glewExperimental || WGLEW_I3D_digital_video_control || crippled) WGLEW_I3D_digital_video_control = !_glewInit_WGL_I3D_digital_video_control();
#endif /* WGL_I3D_digital_video_control */
#ifdef WGL_I3D_gamma
  WGLEW_I3D_gamma = wglewGetExtension("WGL_I3D_gamma");
  if (glewExperimental || WGLEW_I3D_gamma || crippled) WGLEW_I3D_gamma = !_glewInit_WGL_I3D_gamma();
#endif /* WGL_I3D_gamma */
#ifdef WGL_I3D_genlock
  WGLEW_I3D_genlock = wglewGetExtension("WGL_I3D_genlock");
  if (glewExperimental || WGLEW_I3D_genlock || crippled) WGLEW_I3D_genlock = !_glewInit_WGL_I3D_genlock();
#endif /* WGL_I3D_genlock */
#ifdef WGL_I3D_image_buffer
  WGLEW_I3D_image_buffer = wglewGetExtension("WGL_I3D_image_buffer");
  if (glewExperimental || WGLEW_I3D_image_buffer || crippled) WGLEW_I3D_image_buffer = !_glewInit_WGL_I3D_image_buffer();
#endif /* WGL_I3D_image_buffer */
#ifdef WGL_I3D_swap_frame_lock
  WGLEW_I3D_swap_frame_lock = wglewGetExtension("WGL_I3D_swap_frame_lock");
  if (glewExperimental || WGLEW_I3D_swap_frame_lock || crippled) WGLEW_I3D_swap_frame_lock = !_glewInit_WGL_I3D_swap_frame_lock();
#endif /* WGL_I3D_swap_frame_lock */
#ifdef WGL_I3D_swap_frame_usage
  WGLEW_I3D_swap_frame_usage = wglewGetExtension("WGL_I3D_swap_frame_usage");
  if (glewExperimental || WGLEW_I3D_swap_frame_usage || crippled) WGLEW_I3D_swap_frame_usage = !_glewInit_WGL_I3D_swap_frame_usage();
#endif /* WGL_I3D_swap_frame_usage */
#ifdef WGL_NV_float_buffer
  WGLEW_NV_float_buffer = wglewGetExtension("WGL_NV_float_buffer");
#endif /* WGL_NV_float_buffer */
#ifdef WGL_NV_render_depth_texture
  WGLEW_NV_render_depth_texture = wglewGetExtension("WGL_NV_render_depth_texture");
#endif /* WGL_NV_render_depth_texture */
#ifdef WGL_NV_render_texture_rectangle
  WGLEW_NV_render_texture_rectangle = wglewGetExtension("WGL_NV_render_texture_rectangle");
#endif /* WGL_NV_render_texture_rectangle */
#ifdef WGL_NV_vertex_array_range
  WGLEW_NV_vertex_array_range = wglewGetExtension("WGL_NV_vertex_array_range");
  if (glewExperimental || WGLEW_NV_vertex_array_range || crippled) WGLEW_NV_vertex_array_range = !_glewInit_WGL_NV_vertex_array_range();
#endif /* WGL_NV_vertex_array_range */
#ifdef WGL_OML_sync_control
  WGLEW_OML_sync_control = wglewGetExtension("WGL_OML_sync_control");
  if (glewExperimental || WGLEW_OML_sync_control || crippled) WGLEW_OML_sync_control = !_glewInit_WGL_OML_sync_control();
#endif /* WGL_OML_sync_control */
  return GLEW_OK;
}

#else /* _UNIX */

GLboolean glxewGetExtension (const GLubyte *name)
{    
  GLubyte *p, *end;
  GLuint len = _glewStrLen(name);
  if (glXQueryExtensionsString == NULL || glXGetCurrentDisplay == NULL) return GL_FALSE;
  p = (GLubyte*)glXQueryExtensionsString(glXGetCurrentDisplay(), DefaultScreen(glXGetCurrentDisplay()));
  if (0 == p) return GL_FALSE;
  end = p + _glewStrLen(p);
  while (p < end)
  {
    GLuint n = _glewStrCLen(p, ' ');
    if (len == n && _glewStrSame(name, p, n)) return GL_TRUE;
    p += n+1;
  }
  return GL_FALSE;
}

static GLuint _glxewInit ()
{
  int major, minor;
  /* initialize core GLX 1.2 */
  if (_glewInit_GLX_VERSION_1_2()) return GLEW_ERROR_GLX_VERSION_11_ONLY;
  /* query GLX version */
  glXQueryVersion(glXGetCurrentDisplay(), &major, &minor);
  switch (minor)
  {
    case 4:
    GLXEW_VERSION_1_4 = GL_TRUE;
    case 3:
    GLXEW_VERSION_1_3 = GL_TRUE;
    case 2:
    GLXEW_VERSION_1_2 = GL_TRUE;
    GLXEW_VERSION_1_1 = GL_TRUE;
    GLXEW_VERSION_1_0 = GL_TRUE;
    break;
    default:
    return GLEW_ERROR_GLX_VERSION_11_ONLY;
    break;
  }
  /* initialize extensions */
#ifdef GLX_VERSION_1_3
  if (glewExperimental || GLXEW_VERSION_1_3) GLXEW_VERSION_1_3 = !_glewInit_GLX_VERSION_1_3();
#endif /* GLX_VERSION_1_3 */
#ifdef GLX_3DFX_multisample
  GLXEW_3DFX_multisample = glxewGetExtension("GLX_3DFX_multisample");
#endif /* GLX_3DFX_multisample */
#ifdef GLX_ARB_get_proc_address
  GLXEW_ARB_get_proc_address = glxewGetExtension("GLX_ARB_get_proc_address");
#endif /* GLX_ARB_get_proc_address */
#ifdef GLX_ARB_multisample
  GLXEW_ARB_multisample = glxewGetExtension("GLX_ARB_multisample");
#endif /* GLX_ARB_multisample */
#ifdef GLX_EXT_import_context
  GLXEW_EXT_import_context = glxewGetExtension("GLX_EXT_import_context");
  if (glewExperimental || GLXEW_EXT_import_context) GLXEW_EXT_import_context = !_glewInit_GLX_EXT_import_context();
#endif /* GLX_EXT_import_context */
#ifdef GLX_EXT_scene_marker
  GLXEW_EXT_scene_marker = glxewGetExtension("GLX_EXT_scene_marker");
#endif /* GLX_EXT_scene_marker */
#ifdef GLX_EXT_visual_info
  GLXEW_EXT_visual_info = glxewGetExtension("GLX_EXT_visual_info");
#endif /* GLX_EXT_visual_info */
#ifdef GLX_EXT_visual_rating
  GLXEW_EXT_visual_rating = glxewGetExtension("GLX_EXT_visual_rating");
#endif /* GLX_EXT_visual_rating */
#ifdef GLX_MESA_copy_sub_buffer
  GLXEW_MESA_copy_sub_buffer = glxewGetExtension("GLX_MESA_copy_sub_buffer");
  if (glewExperimental || GLXEW_MESA_copy_sub_buffer) GLXEW_MESA_copy_sub_buffer = !_glewInit_GLX_MESA_copy_sub_buffer();
#endif /* GLX_MESA_copy_sub_buffer */
#ifdef GLX_MESA_pixmap_colormap
  GLXEW_MESA_pixmap_colormap = glxewGetExtension("GLX_MESA_pixmap_colormap");
  if (glewExperimental || GLXEW_MESA_pixmap_colormap) GLXEW_MESA_pixmap_colormap = !_glewInit_GLX_MESA_pixmap_colormap();
#endif /* GLX_MESA_pixmap_colormap */
#ifdef GLX_MESA_release_buffers
  GLXEW_MESA_release_buffers = glxewGetExtension("GLX_MESA_release_buffers");
  if (glewExperimental || GLXEW_MESA_release_buffers) GLXEW_MESA_release_buffers = !_glewInit_GLX_MESA_release_buffers();
#endif /* GLX_MESA_release_buffers */
#ifdef GLX_MESA_set_3dfx_mode
  GLXEW_MESA_set_3dfx_mode = glxewGetExtension("GLX_MESA_set_3dfx_mode");
  if (glewExperimental || GLXEW_MESA_set_3dfx_mode) GLXEW_MESA_set_3dfx_mode = !_glewInit_GLX_MESA_set_3dfx_mode();
#endif /* GLX_MESA_set_3dfx_mode */
#ifdef GLX_NV_float_buffer
  GLXEW_NV_float_buffer = glxewGetExtension("GLX_NV_float_buffer");
#endif /* GLX_NV_float_buffer */
#ifdef GLX_NV_vertex_array_range
  GLXEW_NV_vertex_array_range = glxewGetExtension("GLX_NV_vertex_array_range");
  if (glewExperimental || GLXEW_NV_vertex_array_range) GLXEW_NV_vertex_array_range = !_glewInit_GLX_NV_vertex_array_range();
#endif /* GLX_NV_vertex_array_range */
#ifdef GLX_OML_swap_method
  GLXEW_OML_swap_method = glxewGetExtension("GLX_OML_swap_method");
#endif /* GLX_OML_swap_method */
#if defined(GLX_OML_sync_control) && defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#include <inttypes.h>
  GLXEW_OML_sync_control = glxewGetExtension("GLX_OML_sync_control");
  if (glewExperimental || GLXEW_OML_sync_control) GLXEW_OML_sync_control = !_glewInit_GLX_OML_sync_control();
#endif /* GLX_OML_sync_control */
#ifdef GLX_SGIS_blended_overlay
  GLXEW_SGIS_blended_overlay = glxewGetExtension("GLX_SGIS_blended_overlay");
#endif /* GLX_SGIS_blended_overlay */
#ifdef GLX_SGIS_color_range
  GLXEW_SGIS_color_range = glxewGetExtension("GLX_SGIS_color_range");
#endif /* GLX_SGIS_color_range */
#ifdef GLX_SGIS_multisample
  GLXEW_SGIS_multisample = glxewGetExtension("GLX_SGIS_multisample");
#endif /* GLX_SGIS_multisample */
#ifdef GLX_SGIS_shared_multisample
  GLXEW_SGIS_shared_multisample = glxewGetExtension("GLX_SGIS_shared_multisample");
#endif /* GLX_SGIS_shared_multisample */
#ifdef GLX_SGIX_fbconfig
  GLXEW_SGIX_fbconfig = glxewGetExtension("GLX_SGIX_fbconfig");
  if (glewExperimental || GLXEW_SGIX_fbconfig) GLXEW_SGIX_fbconfig = !_glewInit_GLX_SGIX_fbconfig();
#endif /* GLX_SGIX_fbconfig */
#ifdef GLX_SGIX_pbuffer
  GLXEW_SGIX_pbuffer = glxewGetExtension("GLX_SGIX_pbuffer");
  if (glewExperimental || GLXEW_SGIX_pbuffer) GLXEW_SGIX_pbuffer = !_glewInit_GLX_SGIX_pbuffer();
#endif /* GLX_SGIX_pbuffer */
#ifdef GLX_SGIX_swap_barrier
  GLXEW_SGIX_swap_barrier = glxewGetExtension("GLX_SGIX_swap_barrier");
  if (glewExperimental || GLXEW_SGIX_swap_barrier) GLXEW_SGIX_swap_barrier = !_glewInit_GLX_SGIX_swap_barrier();
#endif /* GLX_SGIX_swap_barrier */
#ifdef GLX_SGIX_swap_group
  GLXEW_SGIX_swap_group = glxewGetExtension("GLX_SGIX_swap_group");
  if (glewExperimental || GLXEW_SGIX_swap_group) GLXEW_SGIX_swap_group = !_glewInit_GLX_SGIX_swap_group();
#endif /* GLX_SGIX_swap_group */
#ifdef GLX_SGIX_video_resize
  GLXEW_SGIX_video_resize = glxewGetExtension("GLX_SGIX_video_resize");
  if (glewExperimental || GLXEW_SGIX_video_resize) GLXEW_SGIX_video_resize = !_glewInit_GLX_SGIX_video_resize();
#endif /* GLX_SGIX_video_resize */
#ifdef GLX_SGIX_visual_select_group
  GLXEW_SGIX_visual_select_group = glxewGetExtension("GLX_SGIX_visual_select_group");
#endif /* GLX_SGIX_visual_select_group */
#ifdef GLX_SGI_cushion
  GLXEW_SGI_cushion = glxewGetExtension("GLX_SGI_cushion");
  if (glewExperimental || GLXEW_SGI_cushion) GLXEW_SGI_cushion = !_glewInit_GLX_SGI_cushion();
#endif /* GLX_SGI_cushion */
#ifdef GLX_SGI_make_current_read
  GLXEW_SGI_make_current_read = glxewGetExtension("GLX_SGI_make_current_read");
  if (glewExperimental || GLXEW_SGI_make_current_read) GLXEW_SGI_make_current_read = !_glewInit_GLX_SGI_make_current_read();
#endif /* GLX_SGI_make_current_read */
#ifdef GLX_SGI_swap_control
  GLXEW_SGI_swap_control = glxewGetExtension("GLX_SGI_swap_control");
  if (glewExperimental || GLXEW_SGI_swap_control) GLXEW_SGI_swap_control = !_glewInit_GLX_SGI_swap_control();
#endif /* GLX_SGI_swap_control */
#ifdef GLX_SGI_video_sync
  GLXEW_SGI_video_sync = glxewGetExtension("GLX_SGI_video_sync");
  if (glewExperimental || GLXEW_SGI_video_sync) GLXEW_SGI_video_sync = !_glewInit_GLX_SGI_video_sync();
#endif /* GLX_SGI_video_sync */
#ifdef GLX_SUN_get_transparent_index
  GLXEW_SUN_get_transparent_index = glxewGetExtension("GLX_SUN_get_transparent_index");
  if (glewExperimental || GLXEW_SUN_get_transparent_index) GLXEW_SUN_get_transparent_index = !_glewInit_GLX_SUN_get_transparent_index();
#endif /* GLX_SUN_get_transparent_index */
  return GLEW_OK;
}

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

const GLubyte* glewGetErrorString (GLenum error)
{
  static const GLubyte* _glewErrorString[] =
  {
    "no error",
    "missing GL version",
    "GL 1.1 and up are not supported",
    "GLX 1.2 and up are not supported",
    "unknown error"
  };
  if (error > sizeof(_glewErrorString)) error = sizeof(_glewErrorString);
  return _glewErrorString[error];
}

const GLubyte* glewGetString (GLenum name)
{
  static const GLubyte* _glewString[] =
  {
    NULL,
    "1.1.2"
  };
  if (name > sizeof(_glewString)-1) return NULL;
  return _glewString[name];
}

/* ------------------------------------------------------------------------ */

GLboolean glewExperimental = GL_FALSE;

GLenum glewInit ()
{
  GLenum r;
  if ( (r = _glewInit()) ) return r;
#ifdef _WIN32
  return _wglewInit();
#else /* _UNIX */
  return _glxewInit();
#endif /* _WIN32 */
}
