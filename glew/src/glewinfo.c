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

#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/wglew.h>
#include <GL/glxew.h>

static FILE* f;

static void glewPrintExt (const GLubyte* name, GLint defined)
{
  unsigned int i;
  fprintf(f, "\n%s:", name);
  for (i=0; i<62-strlen((const char*)name); i++) fprintf(f, " ");
  fprintf(f, "%s\n", defined ? "OK" : "MISSING");
  for (i=0; i<strlen((const char*)name)+1; i++) fprintf(f, "-");
  fprintf(f, "\n");
  fflush(f);
}

static void glewInfoFunc (const GLubyte* name, GLint undefined)
{
  unsigned int i;
  fprintf(f, "  %s:", name);
  for (i=0; i<60-strlen((const char*)name); i++) fprintf(f, " ");
  fprintf(f, "%s\n", undefined ? "MISSING" : "OK");
  fflush(f);
}

/* ----------------------------- GL_VERSION_1_1 ---------------------------- */

#ifdef GL_VERSION_1_1

static void _glewInfo_GL_VERSION_1_1 (void)
{
  glewPrintExt("GL_VERSION_1_1", GLEW_VERSION_1_1);
}

#endif /* GL_VERSION_1_1 */

/* ----------------------------- GL_VERSION_1_2 ---------------------------- */

#ifdef GL_VERSION_1_2

static void _glewInfo_GL_VERSION_1_2 (void)
{
  glewPrintExt("GL_VERSION_1_2", GLEW_VERSION_1_2);

  glewInfoFunc("glCopyTexSubImage3D", glewCopyTexSubImage3D == NULL);
  glewInfoFunc("glDrawRangeElements", glewDrawRangeElements == NULL);
  glewInfoFunc("glTexImage3D", glewTexImage3D == NULL);
  glewInfoFunc("glTexSubImage3D", glewTexSubImage3D == NULL);
}

#endif /* GL_VERSION_1_2 */

/* ----------------------------- GL_VERSION_1_3 ---------------------------- */

#ifdef GL_VERSION_1_3

static void _glewInfo_GL_VERSION_1_3 (void)
{
  glewPrintExt("GL_VERSION_1_3", GLEW_VERSION_1_3);

  glewInfoFunc("glActiveTexture", glewActiveTexture == NULL);
  glewInfoFunc("glClientActiveTexture", glewClientActiveTexture == NULL);
  glewInfoFunc("glCompressedTexImage1D", glewCompressedTexImage1D == NULL);
  glewInfoFunc("glCompressedTexImage2D", glewCompressedTexImage2D == NULL);
  glewInfoFunc("glCompressedTexImage3D", glewCompressedTexImage3D == NULL);
  glewInfoFunc("glCompressedTexSubImage1D", glewCompressedTexSubImage1D == NULL);
  glewInfoFunc("glCompressedTexSubImage2D", glewCompressedTexSubImage2D == NULL);
  glewInfoFunc("glCompressedTexSubImage3D", glewCompressedTexSubImage3D == NULL);
  glewInfoFunc("glGetCompressedTexImage", glewGetCompressedTexImage == NULL);
  glewInfoFunc("glLoadTransposeMatrixd", glewLoadTransposeMatrixd == NULL);
  glewInfoFunc("glLoadTransposeMatrixf", glewLoadTransposeMatrixf == NULL);
  glewInfoFunc("glMultTransposeMatrixd", glewMultTransposeMatrixd == NULL);
  glewInfoFunc("glMultTransposeMatrixf", glewMultTransposeMatrixf == NULL);
  glewInfoFunc("glMultiTexCoord1d", glewMultiTexCoord1d == NULL);
  glewInfoFunc("glMultiTexCoord1dv", glewMultiTexCoord1dv == NULL);
  glewInfoFunc("glMultiTexCoord1f", glewMultiTexCoord1f == NULL);
  glewInfoFunc("glMultiTexCoord1fv", glewMultiTexCoord1fv == NULL);
  glewInfoFunc("glMultiTexCoord1i", glewMultiTexCoord1i == NULL);
  glewInfoFunc("glMultiTexCoord1iv", glewMultiTexCoord1iv == NULL);
  glewInfoFunc("glMultiTexCoord1s", glewMultiTexCoord1s == NULL);
  glewInfoFunc("glMultiTexCoord1sv", glewMultiTexCoord1sv == NULL);
  glewInfoFunc("glMultiTexCoord2d", glewMultiTexCoord2d == NULL);
  glewInfoFunc("glMultiTexCoord2dv", glewMultiTexCoord2dv == NULL);
  glewInfoFunc("glMultiTexCoord2f", glewMultiTexCoord2f == NULL);
  glewInfoFunc("glMultiTexCoord2fv", glewMultiTexCoord2fv == NULL);
  glewInfoFunc("glMultiTexCoord2i", glewMultiTexCoord2i == NULL);
  glewInfoFunc("glMultiTexCoord2iv", glewMultiTexCoord2iv == NULL);
  glewInfoFunc("glMultiTexCoord2s", glewMultiTexCoord2s == NULL);
  glewInfoFunc("glMultiTexCoord2sv", glewMultiTexCoord2sv == NULL);
  glewInfoFunc("glMultiTexCoord3d", glewMultiTexCoord3d == NULL);
  glewInfoFunc("glMultiTexCoord3dv", glewMultiTexCoord3dv == NULL);
  glewInfoFunc("glMultiTexCoord3f", glewMultiTexCoord3f == NULL);
  glewInfoFunc("glMultiTexCoord3fv", glewMultiTexCoord3fv == NULL);
  glewInfoFunc("glMultiTexCoord3i", glewMultiTexCoord3i == NULL);
  glewInfoFunc("glMultiTexCoord3iv", glewMultiTexCoord3iv == NULL);
  glewInfoFunc("glMultiTexCoord3s", glewMultiTexCoord3s == NULL);
  glewInfoFunc("glMultiTexCoord3sv", glewMultiTexCoord3sv == NULL);
  glewInfoFunc("glMultiTexCoord4d", glewMultiTexCoord4d == NULL);
  glewInfoFunc("glMultiTexCoord4dv", glewMultiTexCoord4dv == NULL);
  glewInfoFunc("glMultiTexCoord4f", glewMultiTexCoord4f == NULL);
  glewInfoFunc("glMultiTexCoord4fv", glewMultiTexCoord4fv == NULL);
  glewInfoFunc("glMultiTexCoord4i", glewMultiTexCoord4i == NULL);
  glewInfoFunc("glMultiTexCoord4iv", glewMultiTexCoord4iv == NULL);
  glewInfoFunc("glMultiTexCoord4s", glewMultiTexCoord4s == NULL);
  glewInfoFunc("glMultiTexCoord4sv", glewMultiTexCoord4sv == NULL);
  glewInfoFunc("glSampleCoverage", glewSampleCoverage == NULL);
}

#endif /* GL_VERSION_1_3 */

/* ----------------------------- GL_VERSION_1_4 ---------------------------- */

#ifdef GL_VERSION_1_4

static void _glewInfo_GL_VERSION_1_4 (void)
{
  glewPrintExt("GL_VERSION_1_4", GLEW_VERSION_1_4);

  glewInfoFunc("glBlendColor", glewBlendColor == NULL);
  glewInfoFunc("glBlendEquation", glewBlendEquation == NULL);
  glewInfoFunc("glBlendFuncSeparate", glewBlendFuncSeparate == NULL);
  glewInfoFunc("glFogCoordPointer", glewFogCoordPointer == NULL);
  glewInfoFunc("glFogCoordd", glewFogCoordd == NULL);
  glewInfoFunc("glFogCoorddv", glewFogCoorddv == NULL);
  glewInfoFunc("glFogCoordf", glewFogCoordf == NULL);
  glewInfoFunc("glFogCoordfv", glewFogCoordfv == NULL);
  glewInfoFunc("glMultiDrawArrays", glewMultiDrawArrays == NULL);
  glewInfoFunc("glMultiDrawElements", glewMultiDrawElements == NULL);
  glewInfoFunc("glPointParameterf", glewPointParameterf == NULL);
  glewInfoFunc("glPointParameterfv", glewPointParameterfv == NULL);
  glewInfoFunc("glSecondaryColor3b", glewSecondaryColor3b == NULL);
  glewInfoFunc("glSecondaryColor3bv", glewSecondaryColor3bv == NULL);
  glewInfoFunc("glSecondaryColor3d", glewSecondaryColor3d == NULL);
  glewInfoFunc("glSecondaryColor3dv", glewSecondaryColor3dv == NULL);
  glewInfoFunc("glSecondaryColor3f", glewSecondaryColor3f == NULL);
  glewInfoFunc("glSecondaryColor3fv", glewSecondaryColor3fv == NULL);
  glewInfoFunc("glSecondaryColor3i", glewSecondaryColor3i == NULL);
  glewInfoFunc("glSecondaryColor3iv", glewSecondaryColor3iv == NULL);
  glewInfoFunc("glSecondaryColor3s", glewSecondaryColor3s == NULL);
  glewInfoFunc("glSecondaryColor3sv", glewSecondaryColor3sv == NULL);
  glewInfoFunc("glSecondaryColor3ub", glewSecondaryColor3ub == NULL);
  glewInfoFunc("glSecondaryColor3ubv", glewSecondaryColor3ubv == NULL);
  glewInfoFunc("glSecondaryColor3ui", glewSecondaryColor3ui == NULL);
  glewInfoFunc("glSecondaryColor3uiv", glewSecondaryColor3uiv == NULL);
  glewInfoFunc("glSecondaryColor3us", glewSecondaryColor3us == NULL);
  glewInfoFunc("glSecondaryColor3usv", glewSecondaryColor3usv == NULL);
  glewInfoFunc("glSecondaryColorPointer", glewSecondaryColorPointer == NULL);
  glewInfoFunc("glWindowPos2d", glewWindowPos2d == NULL);
  glewInfoFunc("glWindowPos2dv", glewWindowPos2dv == NULL);
  glewInfoFunc("glWindowPos2f", glewWindowPos2f == NULL);
  glewInfoFunc("glWindowPos2fv", glewWindowPos2fv == NULL);
  glewInfoFunc("glWindowPos2i", glewWindowPos2i == NULL);
  glewInfoFunc("glWindowPos2iv", glewWindowPos2iv == NULL);
  glewInfoFunc("glWindowPos2s", glewWindowPos2s == NULL);
  glewInfoFunc("glWindowPos2sv", glewWindowPos2sv == NULL);
  glewInfoFunc("glWindowPos3d", glewWindowPos3d == NULL);
  glewInfoFunc("glWindowPos3dv", glewWindowPos3dv == NULL);
  glewInfoFunc("glWindowPos3f", glewWindowPos3f == NULL);
  glewInfoFunc("glWindowPos3fv", glewWindowPos3fv == NULL);
  glewInfoFunc("glWindowPos3i", glewWindowPos3i == NULL);
  glewInfoFunc("glWindowPos3iv", glewWindowPos3iv == NULL);
  glewInfoFunc("glWindowPos3s", glewWindowPos3s == NULL);
  glewInfoFunc("glWindowPos3sv", glewWindowPos3sv == NULL);
}

#endif /* GL_VERSION_1_4 */

/* -------------------------- GL_3DFX_multisample -------------------------- */

#ifdef GL_3DFX_multisample

static void _glewInfo_GL_3DFX_multisample (void)
{
  glewPrintExt("GL_3DFX_multisample", GLEW_3DFX_multisample);
}

#endif /* GL_3DFX_multisample */

/* ---------------------------- GL_3DFX_tbuffer ---------------------------- */

#ifdef GL_3DFX_tbuffer

static void _glewInfo_GL_3DFX_tbuffer (void)
{
  glewPrintExt("GL_3DFX_tbuffer", GLEW_3DFX_tbuffer);

  glewInfoFunc("glTbufferMask3DFX", glewTbufferMask3DFX == NULL);
}

#endif /* GL_3DFX_tbuffer */

/* -------------------- GL_3DFX_texture_compression_FXT1 ------------------- */

#ifdef GL_3DFX_texture_compression_FXT1

static void _glewInfo_GL_3DFX_texture_compression_FXT1 (void)
{
  glewPrintExt("GL_3DFX_texture_compression_FXT1", GLEW_3DFX_texture_compression_FXT1);
}

#endif /* GL_3DFX_texture_compression_FXT1 */

/* ------------------------ GL_APPLE_client_storage ------------------------ */

#ifdef GL_APPLE_client_storage

static void _glewInfo_GL_APPLE_client_storage (void)
{
  glewPrintExt("GL_APPLE_client_storage", GLEW_APPLE_client_storage);
}

#endif /* GL_APPLE_client_storage */

/* ------------------------- GL_APPLE_element_array ------------------------ */

#ifdef GL_APPLE_element_array

static void _glewInfo_GL_APPLE_element_array (void)
{
  glewPrintExt("GL_APPLE_element_array", GLEW_APPLE_element_array);

  glewInfoFunc("glDrawElementArrayAPPLE", glewDrawElementArrayAPPLE == NULL);
  glewInfoFunc("glDrawRangeElementArrayAPPLE", glewDrawRangeElementArrayAPPLE == NULL);
  glewInfoFunc("glElementPointerAPPLE", glewElementPointerAPPLE == NULL);
  glewInfoFunc("glMultiDrawElementArrayAPPLE", glewMultiDrawElementArrayAPPLE == NULL);
  glewInfoFunc("glMultiDrawRangeElementArrayAPPLE", glewMultiDrawRangeElementArrayAPPLE == NULL);
}

#endif /* GL_APPLE_element_array */

/* ----------------------------- GL_APPLE_fence ---------------------------- */

#ifdef GL_APPLE_fence

static void _glewInfo_GL_APPLE_fence (void)
{
  glewPrintExt("GL_APPLE_fence", GLEW_APPLE_fence);

  glewInfoFunc("glDeleteFencesAPPLE", glewDeleteFencesAPPLE == NULL);
  glewInfoFunc("glFinishFenceAPPLE", glewFinishFenceAPPLE == NULL);
  glewInfoFunc("glFinishObjectAPPLE", glewFinishObjectAPPLE == NULL);
  glewInfoFunc("glGenFencesAPPLE", glewGenFencesAPPLE == NULL);
  glewInfoFunc("glIsFenceAPPLE", glewIsFenceAPPLE == NULL);
  glewInfoFunc("glSetFenceAPPLE", glewSetFenceAPPLE == NULL);
  glewInfoFunc("glTestFenceAPPLE", glewTestFenceAPPLE == NULL);
  glewInfoFunc("glTestObjectAPPLE", glewTestObjectAPPLE == NULL);
}

#endif /* GL_APPLE_fence */

/* ------------------------ GL_APPLE_specular_vector ----------------------- */

#ifdef GL_APPLE_specular_vector

static void _glewInfo_GL_APPLE_specular_vector (void)
{
  glewPrintExt("GL_APPLE_specular_vector", GLEW_APPLE_specular_vector);
}

#endif /* GL_APPLE_specular_vector */

/* ------------------------ GL_APPLE_transform_hint ------------------------ */

#ifdef GL_APPLE_transform_hint

static void _glewInfo_GL_APPLE_transform_hint (void)
{
  glewPrintExt("GL_APPLE_transform_hint", GLEW_APPLE_transform_hint);
}

#endif /* GL_APPLE_transform_hint */

/* ---------------------- GL_APPLE_vertex_array_object --------------------- */

#ifdef GL_APPLE_vertex_array_object

static void _glewInfo_GL_APPLE_vertex_array_object (void)
{
  glewPrintExt("GL_APPLE_vertex_array_object", GLEW_APPLE_vertex_array_object);

  glewInfoFunc("glBindVertexArrayAPPLE", glewBindVertexArrayAPPLE == NULL);
  glewInfoFunc("glDeleteVertexArraysAPPLE", glewDeleteVertexArraysAPPLE == NULL);
  glewInfoFunc("glGenVertexArraysAPPLE", glewGenVertexArraysAPPLE == NULL);
  glewInfoFunc("glIsVertexArrayAPPLE", glewIsVertexArrayAPPLE == NULL);
}

#endif /* GL_APPLE_vertex_array_object */

/* ---------------------- GL_APPLE_vertex_array_range ---------------------- */

#ifdef GL_APPLE_vertex_array_range

static void _glewInfo_GL_APPLE_vertex_array_range (void)
{
  glewPrintExt("GL_APPLE_vertex_array_range", GLEW_APPLE_vertex_array_range);

  glewInfoFunc("glFlushVertexArrayRangeAPPLE", glewFlushVertexArrayRangeAPPLE == NULL);
  glewInfoFunc("glVertexArrayParameteriAPPLE", glewVertexArrayParameteriAPPLE == NULL);
  glewInfoFunc("glVertexArrayRangeAPPLE", glewVertexArrayRangeAPPLE == NULL);
}

#endif /* GL_APPLE_vertex_array_range */

/* --------------------------- GL_APPLE_ycbcr_422 -------------------------- */

#ifdef GL_APPLE_ycbcr_422

static void _glewInfo_GL_APPLE_ycbcr_422 (void)
{
  glewPrintExt("GL_APPLE_ycbcr_422", GLEW_APPLE_ycbcr_422);
}

#endif /* GL_APPLE_ycbcr_422 */

/* -------------------------- GL_ARB_depth_texture ------------------------- */

#ifdef GL_ARB_depth_texture

static void _glewInfo_GL_ARB_depth_texture (void)
{
  glewPrintExt("GL_ARB_depth_texture", GLEW_ARB_depth_texture);
}

#endif /* GL_ARB_depth_texture */

/* ------------------------ GL_ARB_fragment_program ------------------------ */

#ifdef GL_ARB_fragment_program

static void _glewInfo_GL_ARB_fragment_program (void)
{
  glewPrintExt("GL_ARB_fragment_program", GLEW_ARB_fragment_program);
}

#endif /* GL_ARB_fragment_program */

/* ----------------------------- GL_ARB_imaging ---------------------------- */

#ifdef GL_ARB_imaging

static void _glewInfo_GL_ARB_imaging (void)
{
  glewPrintExt("GL_ARB_imaging", GLEW_ARB_imaging);

  glewInfoFunc("glBlendColor", glewBlendColor == NULL);
  glewInfoFunc("glBlendEquation", glewBlendEquation == NULL);
  glewInfoFunc("glColorSubTable", glewColorSubTable == NULL);
  glewInfoFunc("glColorTable", glewColorTable == NULL);
  glewInfoFunc("glColorTableParameterfv", glewColorTableParameterfv == NULL);
  glewInfoFunc("glColorTableParameteriv", glewColorTableParameteriv == NULL);
  glewInfoFunc("glConvolutionFilter1D", glewConvolutionFilter1D == NULL);
  glewInfoFunc("glConvolutionFilter2D", glewConvolutionFilter2D == NULL);
  glewInfoFunc("glConvolutionParameterf", glewConvolutionParameterf == NULL);
  glewInfoFunc("glConvolutionParameterfv", glewConvolutionParameterfv == NULL);
  glewInfoFunc("glConvolutionParameteri", glewConvolutionParameteri == NULL);
  glewInfoFunc("glConvolutionParameteriv", glewConvolutionParameteriv == NULL);
  glewInfoFunc("glCopyColorSubTable", glewCopyColorSubTable == NULL);
  glewInfoFunc("glCopyColorTable", glewCopyColorTable == NULL);
  glewInfoFunc("glCopyConvolutionFilter1D", glewCopyConvolutionFilter1D == NULL);
  glewInfoFunc("glCopyConvolutionFilter2D", glewCopyConvolutionFilter2D == NULL);
  glewInfoFunc("glGetColorTable", glewGetColorTable == NULL);
  glewInfoFunc("glGetColorTableParameterfv", glewGetColorTableParameterfv == NULL);
  glewInfoFunc("glGetColorTableParameteriv", glewGetColorTableParameteriv == NULL);
  glewInfoFunc("glGetConvolutionFilter", glewGetConvolutionFilter == NULL);
  glewInfoFunc("glGetConvolutionParameterfv", glewGetConvolutionParameterfv == NULL);
  glewInfoFunc("glGetConvolutionParameteriv", glewGetConvolutionParameteriv == NULL);
  glewInfoFunc("glGetHistogram", glewGetHistogram == NULL);
  glewInfoFunc("glGetHistogramParameterfv", glewGetHistogramParameterfv == NULL);
  glewInfoFunc("glGetHistogramParameteriv", glewGetHistogramParameteriv == NULL);
  glewInfoFunc("glGetMinmax", glewGetMinmax == NULL);
  glewInfoFunc("glGetMinmaxParameterfv", glewGetMinmaxParameterfv == NULL);
  glewInfoFunc("glGetMinmaxParameteriv", glewGetMinmaxParameteriv == NULL);
  glewInfoFunc("glGetSeparableFilter", glewGetSeparableFilter == NULL);
  glewInfoFunc("glHistogram", glewHistogram == NULL);
  glewInfoFunc("glMinmax", glewMinmax == NULL);
  glewInfoFunc("glResetHistogram", glewResetHistogram == NULL);
  glewInfoFunc("glResetMinmax", glewResetMinmax == NULL);
  glewInfoFunc("glSeparableFilter2D", glewSeparableFilter2D == NULL);
}

#endif /* GL_ARB_imaging */

/* ------------------------- GL_ARB_matrix_palette ------------------------- */

#ifdef GL_ARB_matrix_palette

static void _glewInfo_GL_ARB_matrix_palette (void)
{
  glewPrintExt("GL_ARB_matrix_palette", GLEW_ARB_matrix_palette);

  glewInfoFunc("glCurrentPaletteMatrixARB", glewCurrentPaletteMatrixARB == NULL);
  glewInfoFunc("glMatrixIndexPointerARB", glewMatrixIndexPointerARB == NULL);
  glewInfoFunc("glMatrixIndexubvARB", glewMatrixIndexubvARB == NULL);
  glewInfoFunc("glMatrixIndexuivARB", glewMatrixIndexuivARB == NULL);
  glewInfoFunc("glMatrixIndexusvARB", glewMatrixIndexusvARB == NULL);
}

#endif /* GL_ARB_matrix_palette */

/* --------------------------- GL_ARB_multisample -------------------------- */

#ifdef GL_ARB_multisample

static void _glewInfo_GL_ARB_multisample (void)
{
  glewPrintExt("GL_ARB_multisample", GLEW_ARB_multisample);

  glewInfoFunc("glSampleCoverageARB", glewSampleCoverageARB == NULL);
}

#endif /* GL_ARB_multisample */

/* -------------------------- GL_ARB_multitexture -------------------------- */

#ifdef GL_ARB_multitexture

static void _glewInfo_GL_ARB_multitexture (void)
{
  glewPrintExt("GL_ARB_multitexture", GLEW_ARB_multitexture);

  glewInfoFunc("glActiveTextureARB", glewActiveTextureARB == NULL);
  glewInfoFunc("glClientActiveTextureARB", glewClientActiveTextureARB == NULL);
  glewInfoFunc("glMultiTexCoord1dARB", glewMultiTexCoord1dARB == NULL);
  glewInfoFunc("glMultiTexCoord1dvARB", glewMultiTexCoord1dvARB == NULL);
  glewInfoFunc("glMultiTexCoord1fARB", glewMultiTexCoord1fARB == NULL);
  glewInfoFunc("glMultiTexCoord1fvARB", glewMultiTexCoord1fvARB == NULL);
  glewInfoFunc("glMultiTexCoord1iARB", glewMultiTexCoord1iARB == NULL);
  glewInfoFunc("glMultiTexCoord1ivARB", glewMultiTexCoord1ivARB == NULL);
  glewInfoFunc("glMultiTexCoord1sARB", glewMultiTexCoord1sARB == NULL);
  glewInfoFunc("glMultiTexCoord1svARB", glewMultiTexCoord1svARB == NULL);
  glewInfoFunc("glMultiTexCoord2dARB", glewMultiTexCoord2dARB == NULL);
  glewInfoFunc("glMultiTexCoord2dvARB", glewMultiTexCoord2dvARB == NULL);
  glewInfoFunc("glMultiTexCoord2fARB", glewMultiTexCoord2fARB == NULL);
  glewInfoFunc("glMultiTexCoord2fvARB", glewMultiTexCoord2fvARB == NULL);
  glewInfoFunc("glMultiTexCoord2iARB", glewMultiTexCoord2iARB == NULL);
  glewInfoFunc("glMultiTexCoord2ivARB", glewMultiTexCoord2ivARB == NULL);
  glewInfoFunc("glMultiTexCoord2sARB", glewMultiTexCoord2sARB == NULL);
  glewInfoFunc("glMultiTexCoord2svARB", glewMultiTexCoord2svARB == NULL);
  glewInfoFunc("glMultiTexCoord3dARB", glewMultiTexCoord3dARB == NULL);
  glewInfoFunc("glMultiTexCoord3dvARB", glewMultiTexCoord3dvARB == NULL);
  glewInfoFunc("glMultiTexCoord3fARB", glewMultiTexCoord3fARB == NULL);
  glewInfoFunc("glMultiTexCoord3fvARB", glewMultiTexCoord3fvARB == NULL);
  glewInfoFunc("glMultiTexCoord3iARB", glewMultiTexCoord3iARB == NULL);
  glewInfoFunc("glMultiTexCoord3ivARB", glewMultiTexCoord3ivARB == NULL);
  glewInfoFunc("glMultiTexCoord3sARB", glewMultiTexCoord3sARB == NULL);
  glewInfoFunc("glMultiTexCoord3svARB", glewMultiTexCoord3svARB == NULL);
  glewInfoFunc("glMultiTexCoord4dARB", glewMultiTexCoord4dARB == NULL);
  glewInfoFunc("glMultiTexCoord4dvARB", glewMultiTexCoord4dvARB == NULL);
  glewInfoFunc("glMultiTexCoord4fARB", glewMultiTexCoord4fARB == NULL);
  glewInfoFunc("glMultiTexCoord4fvARB", glewMultiTexCoord4fvARB == NULL);
  glewInfoFunc("glMultiTexCoord4iARB", glewMultiTexCoord4iARB == NULL);
  glewInfoFunc("glMultiTexCoord4ivARB", glewMultiTexCoord4ivARB == NULL);
  glewInfoFunc("glMultiTexCoord4sARB", glewMultiTexCoord4sARB == NULL);
  glewInfoFunc("glMultiTexCoord4svARB", glewMultiTexCoord4svARB == NULL);
}

#endif /* GL_ARB_multitexture */

/* ------------------------- GL_ARB_occlusion_query ------------------------ */

#ifdef GL_ARB_occlusion_query

static void _glewInfo_GL_ARB_occlusion_query (void)
{
  glewPrintExt("GL_ARB_occlusion_query", GLEW_ARB_occlusion_query);

  glewInfoFunc("glBeginQueryARB", glewBeginQueryARB == NULL);
  glewInfoFunc("glDeleteQueriesARB", glewDeleteQueriesARB == NULL);
  glewInfoFunc("glEndQueryARB", glewEndQueryARB == NULL);
  glewInfoFunc("glGenQueriesARB", glewGenQueriesARB == NULL);
  glewInfoFunc("glGetQueryObjectivARB", glewGetQueryObjectivARB == NULL);
  glewInfoFunc("glGetQueryObjectuivARB", glewGetQueryObjectuivARB == NULL);
  glewInfoFunc("glGetQueryivARB", glewGetQueryivARB == NULL);
  glewInfoFunc("glIsQueryARB", glewIsQueryARB == NULL);
}

#endif /* GL_ARB_occlusion_query */

/* ------------------------ GL_ARB_point_parameters ------------------------ */

#ifdef GL_ARB_point_parameters

static void _glewInfo_GL_ARB_point_parameters (void)
{
  glewPrintExt("GL_ARB_point_parameters", GLEW_ARB_point_parameters);

  glewInfoFunc("glPointParameterfARB", glewPointParameterfARB == NULL);
  glewInfoFunc("glPointParameterfvARB", glewPointParameterfvARB == NULL);
}

#endif /* GL_ARB_point_parameters */

/* -------------------------- GL_ARB_point_sprite -------------------------- */

#ifdef GL_ARB_point_sprite

static void _glewInfo_GL_ARB_point_sprite (void)
{
  glewPrintExt("GL_ARB_point_sprite", GLEW_ARB_point_sprite);
}

#endif /* GL_ARB_point_sprite */

/* ---------------------- GL_ARB_shading_language_100 ---------------------- */

#ifdef GL_ARB_shading_language_100

static void _glewInfo_GL_ARB_shading_language_100 (void)
{
  glewPrintExt("GL_ARB_shading_language_100", GLEW_ARB_shading_language_100);
}

#endif /* GL_ARB_shading_language_100 */

/* ----------------------------- GL_ARB_shadow ----------------------------- */

#ifdef GL_ARB_shadow

static void _glewInfo_GL_ARB_shadow (void)
{
  glewPrintExt("GL_ARB_shadow", GLEW_ARB_shadow);
}

#endif /* GL_ARB_shadow */

/* ------------------------- GL_ARB_shadow_ambient ------------------------- */

#ifdef GL_ARB_shadow_ambient

static void _glewInfo_GL_ARB_shadow_ambient (void)
{
  glewPrintExt("GL_ARB_shadow_ambient", GLEW_ARB_shadow_ambient);
}

#endif /* GL_ARB_shadow_ambient */

/* ---------------------- GL_ARB_texture_border_clamp ---------------------- */

#ifdef GL_ARB_texture_border_clamp

static void _glewInfo_GL_ARB_texture_border_clamp (void)
{
  glewPrintExt("GL_ARB_texture_border_clamp", GLEW_ARB_texture_border_clamp);
}

#endif /* GL_ARB_texture_border_clamp */

/* ----------------------- GL_ARB_texture_compression ---------------------- */

#ifdef GL_ARB_texture_compression

static void _glewInfo_GL_ARB_texture_compression (void)
{
  glewPrintExt("GL_ARB_texture_compression", GLEW_ARB_texture_compression);

  glewInfoFunc("glCompressedTexImage1DARB", glewCompressedTexImage1DARB == NULL);
  glewInfoFunc("glCompressedTexImage2DARB", glewCompressedTexImage2DARB == NULL);
  glewInfoFunc("glCompressedTexImage3DARB", glewCompressedTexImage3DARB == NULL);
  glewInfoFunc("glCompressedTexSubImage1DARB", glewCompressedTexSubImage1DARB == NULL);
  glewInfoFunc("glCompressedTexSubImage2DARB", glewCompressedTexSubImage2DARB == NULL);
  glewInfoFunc("glCompressedTexSubImage3DARB", glewCompressedTexSubImage3DARB == NULL);
  glewInfoFunc("glGetCompressedTexImageARB", glewGetCompressedTexImageARB == NULL);
}

#endif /* GL_ARB_texture_compression */

/* ------------------------ GL_ARB_texture_cube_map ------------------------ */

#ifdef GL_ARB_texture_cube_map

static void _glewInfo_GL_ARB_texture_cube_map (void)
{
  glewPrintExt("GL_ARB_texture_cube_map", GLEW_ARB_texture_cube_map);
}

#endif /* GL_ARB_texture_cube_map */

/* ------------------------- GL_ARB_texture_env_add ------------------------ */

#ifdef GL_ARB_texture_env_add

static void _glewInfo_GL_ARB_texture_env_add (void)
{
  glewPrintExt("GL_ARB_texture_env_add", GLEW_ARB_texture_env_add);
}

#endif /* GL_ARB_texture_env_add */

/* ----------------------- GL_ARB_texture_env_combine ---------------------- */

#ifdef GL_ARB_texture_env_combine

static void _glewInfo_GL_ARB_texture_env_combine (void)
{
  glewPrintExt("GL_ARB_texture_env_combine", GLEW_ARB_texture_env_combine);
}

#endif /* GL_ARB_texture_env_combine */

/* ---------------------- GL_ARB_texture_env_crossbar ---------------------- */

#ifdef GL_ARB_texture_env_crossbar

static void _glewInfo_GL_ARB_texture_env_crossbar (void)
{
  glewPrintExt("GL_ARB_texture_env_crossbar", GLEW_ARB_texture_env_crossbar);
}

#endif /* GL_ARB_texture_env_crossbar */

/* ------------------------ GL_ARB_texture_env_dot3 ------------------------ */

#ifdef GL_ARB_texture_env_dot3

static void _glewInfo_GL_ARB_texture_env_dot3 (void)
{
  glewPrintExt("GL_ARB_texture_env_dot3", GLEW_ARB_texture_env_dot3);
}

#endif /* GL_ARB_texture_env_dot3 */

/* --------------------- GL_ARB_texture_mirrored_repeat -------------------- */

#ifdef GL_ARB_texture_mirrored_repeat

static void _glewInfo_GL_ARB_texture_mirrored_repeat (void)
{
  glewPrintExt("GL_ARB_texture_mirrored_repeat", GLEW_ARB_texture_mirrored_repeat);
}

#endif /* GL_ARB_texture_mirrored_repeat */

/* -------------------- GL_ARB_texture_non_power_of_two -------------------- */

#ifdef GL_ARB_texture_non_power_of_two

static void _glewInfo_GL_ARB_texture_non_power_of_two (void)
{
  glewPrintExt("GL_ARB_texture_non_power_of_two", GLEW_ARB_texture_non_power_of_two);
}

#endif /* GL_ARB_texture_non_power_of_two */

/* ------------------------ GL_ARB_transpose_matrix ------------------------ */

#ifdef GL_ARB_transpose_matrix

static void _glewInfo_GL_ARB_transpose_matrix (void)
{
  glewPrintExt("GL_ARB_transpose_matrix", GLEW_ARB_transpose_matrix);
}

#endif /* GL_ARB_transpose_matrix */

/* -------------------------- GL_ARB_vertex_blend -------------------------- */

#ifdef GL_ARB_vertex_blend

static void _glewInfo_GL_ARB_vertex_blend (void)
{
  glewPrintExt("GL_ARB_vertex_blend", GLEW_ARB_vertex_blend);

  glewInfoFunc("glVertexBlendARB", glewVertexBlendARB == NULL);
  glewInfoFunc("glWeightPointerARB", glewWeightPointerARB == NULL);
  glewInfoFunc("glWeightbvARB", glewWeightbvARB == NULL);
  glewInfoFunc("glWeightdvARB", glewWeightdvARB == NULL);
  glewInfoFunc("glWeightfvARB", glewWeightfvARB == NULL);
  glewInfoFunc("glWeightivARB", glewWeightivARB == NULL);
  glewInfoFunc("glWeightsvARB", glewWeightsvARB == NULL);
  glewInfoFunc("glWeightubvARB", glewWeightubvARB == NULL);
  glewInfoFunc("glWeightuivARB", glewWeightuivARB == NULL);
  glewInfoFunc("glWeightusvARB", glewWeightusvARB == NULL);
}

#endif /* GL_ARB_vertex_blend */

/* ---------------------- GL_ARB_vertex_buffer_object ---------------------- */

#ifdef GL_ARB_vertex_buffer_object

static void _glewInfo_GL_ARB_vertex_buffer_object (void)
{
  glewPrintExt("GL_ARB_vertex_buffer_object", GLEW_ARB_vertex_buffer_object);

  glewInfoFunc("glBindBufferARB", glewBindBufferARB == NULL);
  glewInfoFunc("glBufferDataARB", glewBufferDataARB == NULL);
  glewInfoFunc("glBufferSubDataARB", glewBufferSubDataARB == NULL);
  glewInfoFunc("glDeleteBuffersARB", glewDeleteBuffersARB == NULL);
  glewInfoFunc("glGenBuffersARB", glewGenBuffersARB == NULL);
  glewInfoFunc("glGetBufferParameterivARB", glewGetBufferParameterivARB == NULL);
  glewInfoFunc("glGetBufferPointervARB", glewGetBufferPointervARB == NULL);
  glewInfoFunc("glGetBufferSubDataARB", glewGetBufferSubDataARB == NULL);
  glewInfoFunc("glIsBufferARB", glewIsBufferARB == NULL);
  glewInfoFunc("glMapBufferARB", glewMapBufferARB == NULL);
  glewInfoFunc("glUnmapBufferARB", glewUnmapBufferARB == NULL);
}

#endif /* GL_ARB_vertex_buffer_object */

/* ------------------------- GL_ARB_vertex_program ------------------------- */

#ifdef GL_ARB_vertex_program

static void _glewInfo_GL_ARB_vertex_program (void)
{
  glewPrintExt("GL_ARB_vertex_program", GLEW_ARB_vertex_program);

  glewInfoFunc("glBindProgramARB", glewBindProgramARB == NULL);
  glewInfoFunc("glDeleteProgramsARB", glewDeleteProgramsARB == NULL);
  glewInfoFunc("glDisableVertexAttribArrayARB", glewDisableVertexAttribArrayARB == NULL);
  glewInfoFunc("glEnableVertexAttribArrayARB", glewEnableVertexAttribArrayARB == NULL);
  glewInfoFunc("glGenProgramsARB", glewGenProgramsARB == NULL);
  glewInfoFunc("glGetProgramEnvParameterdvARB", glewGetProgramEnvParameterdvARB == NULL);
  glewInfoFunc("glGetProgramEnvParameterfvARB", glewGetProgramEnvParameterfvARB == NULL);
  glewInfoFunc("glGetProgramLocalParameterdvARB", glewGetProgramLocalParameterdvARB == NULL);
  glewInfoFunc("glGetProgramLocalParameterfvARB", glewGetProgramLocalParameterfvARB == NULL);
  glewInfoFunc("glGetProgramStringARB", glewGetProgramStringARB == NULL);
  glewInfoFunc("glGetProgramivARB", glewGetProgramivARB == NULL);
  glewInfoFunc("glGetVertexAttribPointervARB", glewGetVertexAttribPointervARB == NULL);
  glewInfoFunc("glGetVertexAttribdvARB", glewGetVertexAttribdvARB == NULL);
  glewInfoFunc("glGetVertexAttribfvARB", glewGetVertexAttribfvARB == NULL);
  glewInfoFunc("glGetVertexAttribivARB", glewGetVertexAttribivARB == NULL);
  glewInfoFunc("glIsProgramARB", glewIsProgramARB == NULL);
  glewInfoFunc("glProgramEnvParameter4dARB", glewProgramEnvParameter4dARB == NULL);
  glewInfoFunc("glProgramEnvParameter4dvARB", glewProgramEnvParameter4dvARB == NULL);
  glewInfoFunc("glProgramEnvParameter4fARB", glewProgramEnvParameter4fARB == NULL);
  glewInfoFunc("glProgramEnvParameter4fvARB", glewProgramEnvParameter4fvARB == NULL);
  glewInfoFunc("glProgramLocalParameter4dARB", glewProgramLocalParameter4dARB == NULL);
  glewInfoFunc("glProgramLocalParameter4dvARB", glewProgramLocalParameter4dvARB == NULL);
  glewInfoFunc("glProgramLocalParameter4fARB", glewProgramLocalParameter4fARB == NULL);
  glewInfoFunc("glProgramLocalParameter4fvARB", glewProgramLocalParameter4fvARB == NULL);
  glewInfoFunc("glProgramStringARB", glewProgramStringARB == NULL);
  glewInfoFunc("glVertexAttrib1dARB", glewVertexAttrib1dARB == NULL);
  glewInfoFunc("glVertexAttrib1dvARB", glewVertexAttrib1dvARB == NULL);
  glewInfoFunc("glVertexAttrib1fARB", glewVertexAttrib1fARB == NULL);
  glewInfoFunc("glVertexAttrib1fvARB", glewVertexAttrib1fvARB == NULL);
  glewInfoFunc("glVertexAttrib1sARB", glewVertexAttrib1sARB == NULL);
  glewInfoFunc("glVertexAttrib1svARB", glewVertexAttrib1svARB == NULL);
  glewInfoFunc("glVertexAttrib2dARB", glewVertexAttrib2dARB == NULL);
  glewInfoFunc("glVertexAttrib2dvARB", glewVertexAttrib2dvARB == NULL);
  glewInfoFunc("glVertexAttrib2fARB", glewVertexAttrib2fARB == NULL);
  glewInfoFunc("glVertexAttrib2fvARB", glewVertexAttrib2fvARB == NULL);
  glewInfoFunc("glVertexAttrib2sARB", glewVertexAttrib2sARB == NULL);
  glewInfoFunc("glVertexAttrib2svARB", glewVertexAttrib2svARB == NULL);
  glewInfoFunc("glVertexAttrib3dARB", glewVertexAttrib3dARB == NULL);
  glewInfoFunc("glVertexAttrib3dvARB", glewVertexAttrib3dvARB == NULL);
  glewInfoFunc("glVertexAttrib3fARB", glewVertexAttrib3fARB == NULL);
  glewInfoFunc("glVertexAttrib3fvARB", glewVertexAttrib3fvARB == NULL);
  glewInfoFunc("glVertexAttrib3sARB", glewVertexAttrib3sARB == NULL);
  glewInfoFunc("glVertexAttrib3svARB", glewVertexAttrib3svARB == NULL);
  glewInfoFunc("glVertexAttrib4NbvARB", glewVertexAttrib4NbvARB == NULL);
  glewInfoFunc("glVertexAttrib4NivARB", glewVertexAttrib4NivARB == NULL);
  glewInfoFunc("glVertexAttrib4NsvARB", glewVertexAttrib4NsvARB == NULL);
  glewInfoFunc("glVertexAttrib4NubARB", glewVertexAttrib4NubARB == NULL);
  glewInfoFunc("glVertexAttrib4NubvARB", glewVertexAttrib4NubvARB == NULL);
  glewInfoFunc("glVertexAttrib4NuivARB", glewVertexAttrib4NuivARB == NULL);
  glewInfoFunc("glVertexAttrib4NusvARB", glewVertexAttrib4NusvARB == NULL);
  glewInfoFunc("glVertexAttrib4bvARB", glewVertexAttrib4bvARB == NULL);
  glewInfoFunc("glVertexAttrib4dARB", glewVertexAttrib4dARB == NULL);
  glewInfoFunc("glVertexAttrib4dvARB", glewVertexAttrib4dvARB == NULL);
  glewInfoFunc("glVertexAttrib4fARB", glewVertexAttrib4fARB == NULL);
  glewInfoFunc("glVertexAttrib4fvARB", glewVertexAttrib4fvARB == NULL);
  glewInfoFunc("glVertexAttrib4ivARB", glewVertexAttrib4ivARB == NULL);
  glewInfoFunc("glVertexAttrib4sARB", glewVertexAttrib4sARB == NULL);
  glewInfoFunc("glVertexAttrib4svARB", glewVertexAttrib4svARB == NULL);
  glewInfoFunc("glVertexAttrib4ubvARB", glewVertexAttrib4ubvARB == NULL);
  glewInfoFunc("glVertexAttrib4uivARB", glewVertexAttrib4uivARB == NULL);
  glewInfoFunc("glVertexAttrib4usvARB", glewVertexAttrib4usvARB == NULL);
  glewInfoFunc("glVertexAttribPointerARB", glewVertexAttribPointerARB == NULL);
}

#endif /* GL_ARB_vertex_program */

/* --------------------------- GL_ARB_window_pos --------------------------- */

#ifdef GL_ARB_window_pos

static void _glewInfo_GL_ARB_window_pos (void)
{
  glewPrintExt("GL_ARB_window_pos", GLEW_ARB_window_pos);

  glewInfoFunc("glWindowPos2dARB", glewWindowPos2dARB == NULL);
  glewInfoFunc("glWindowPos2dvARB", glewWindowPos2dvARB == NULL);
  glewInfoFunc("glWindowPos2fARB", glewWindowPos2fARB == NULL);
  glewInfoFunc("glWindowPos2fvARB", glewWindowPos2fvARB == NULL);
  glewInfoFunc("glWindowPos2iARB", glewWindowPos2iARB == NULL);
  glewInfoFunc("glWindowPos2ivARB", glewWindowPos2ivARB == NULL);
  glewInfoFunc("glWindowPos2sARB", glewWindowPos2sARB == NULL);
  glewInfoFunc("glWindowPos2svARB", glewWindowPos2svARB == NULL);
  glewInfoFunc("glWindowPos3dARB", glewWindowPos3dARB == NULL);
  glewInfoFunc("glWindowPos3dvARB", glewWindowPos3dvARB == NULL);
  glewInfoFunc("glWindowPos3fARB", glewWindowPos3fARB == NULL);
  glewInfoFunc("glWindowPos3fvARB", glewWindowPos3fvARB == NULL);
  glewInfoFunc("glWindowPos3iARB", glewWindowPos3iARB == NULL);
  glewInfoFunc("glWindowPos3ivARB", glewWindowPos3ivARB == NULL);
  glewInfoFunc("glWindowPos3sARB", glewWindowPos3sARB == NULL);
  glewInfoFunc("glWindowPos3svARB", glewWindowPos3svARB == NULL);
}

#endif /* GL_ARB_window_pos */

/* ------------------------- GL_ATIX_point_sprites ------------------------- */

#ifdef GL_ATIX_point_sprites

static void _glewInfo_GL_ATIX_point_sprites (void)
{
  glewPrintExt("GL_ATIX_point_sprites", GLEW_ATIX_point_sprites);
}

#endif /* GL_ATIX_point_sprites */

/* ---------------------- GL_ATIX_texture_env_combine3 --------------------- */

#ifdef GL_ATIX_texture_env_combine3

static void _glewInfo_GL_ATIX_texture_env_combine3 (void)
{
  glewPrintExt("GL_ATIX_texture_env_combine3", GLEW_ATIX_texture_env_combine3);
}

#endif /* GL_ATIX_texture_env_combine3 */

/* ----------------------- GL_ATIX_texture_env_route ----------------------- */

#ifdef GL_ATIX_texture_env_route

static void _glewInfo_GL_ATIX_texture_env_route (void)
{
  glewPrintExt("GL_ATIX_texture_env_route", GLEW_ATIX_texture_env_route);
}

#endif /* GL_ATIX_texture_env_route */

/* ---------------- GL_ATIX_vertex_shader_output_point_size ---------------- */

#ifdef GL_ATIX_vertex_shader_output_point_size

static void _glewInfo_GL_ATIX_vertex_shader_output_point_size (void)
{
  glewPrintExt("GL_ATIX_vertex_shader_output_point_size", GLEW_ATIX_vertex_shader_output_point_size);
}

#endif /* GL_ATIX_vertex_shader_output_point_size */

/* -------------------------- GL_ATI_draw_buffers -------------------------- */

#ifdef GL_ATI_draw_buffers

static void _glewInfo_GL_ATI_draw_buffers (void)
{
  glewPrintExt("GL_ATI_draw_buffers", GLEW_ATI_draw_buffers);

  glewInfoFunc("glDrawBuffersATI", glewDrawBuffersATI == NULL);
}

#endif /* GL_ATI_draw_buffers */

/* -------------------------- GL_ATI_element_array ------------------------- */

#ifdef GL_ATI_element_array

static void _glewInfo_GL_ATI_element_array (void)
{
  glewPrintExt("GL_ATI_element_array", GLEW_ATI_element_array);

  glewInfoFunc("glDrawElementArrayATI", glewDrawElementArrayATI == NULL);
  glewInfoFunc("glDrawRangeElementArrayATI", glewDrawRangeElementArrayATI == NULL);
  glewInfoFunc("glElementPointerATI", glewElementPointerATI == NULL);
}

#endif /* GL_ATI_element_array */

/* ------------------------- GL_ATI_envmap_bumpmap ------------------------- */

#ifdef GL_ATI_envmap_bumpmap

static void _glewInfo_GL_ATI_envmap_bumpmap (void)
{
  glewPrintExt("GL_ATI_envmap_bumpmap", GLEW_ATI_envmap_bumpmap);

  glewInfoFunc("glGetTexBumpParameterfvATI", glewGetTexBumpParameterfvATI == NULL);
  glewInfoFunc("glGetTexBumpParameterivATI", glewGetTexBumpParameterivATI == NULL);
  glewInfoFunc("glTexBumpParameterfvATI", glewTexBumpParameterfvATI == NULL);
  glewInfoFunc("glTexBumpParameterivATI", glewTexBumpParameterivATI == NULL);
}

#endif /* GL_ATI_envmap_bumpmap */

/* ------------------------- GL_ATI_fragment_shader ------------------------ */

#ifdef GL_ATI_fragment_shader

static void _glewInfo_GL_ATI_fragment_shader (void)
{
  glewPrintExt("GL_ATI_fragment_shader", GLEW_ATI_fragment_shader);

  glewInfoFunc("glAlphaFragmentOp1ATI", glewAlphaFragmentOp1ATI == NULL);
  glewInfoFunc("glAlphaFragmentOp2ATI", glewAlphaFragmentOp2ATI == NULL);
  glewInfoFunc("glAlphaFragmentOp3ATI", glewAlphaFragmentOp3ATI == NULL);
  glewInfoFunc("glBeginFragmentShaderATI", glewBeginFragmentShaderATI == NULL);
  glewInfoFunc("glBindFragmentShaderATI", glewBindFragmentShaderATI == NULL);
  glewInfoFunc("glColorFragmentOp1ATI", glewColorFragmentOp1ATI == NULL);
  glewInfoFunc("glColorFragmentOp2ATI", glewColorFragmentOp2ATI == NULL);
  glewInfoFunc("glColorFragmentOp3ATI", glewColorFragmentOp3ATI == NULL);
  glewInfoFunc("glDeleteFragmentShaderATI", glewDeleteFragmentShaderATI == NULL);
  glewInfoFunc("glEndFragmentShaderATI", glewEndFragmentShaderATI == NULL);
  glewInfoFunc("glGenFragmentShadersATI", glewGenFragmentShadersATI == NULL);
  glewInfoFunc("glPassTexCoordATI", glewPassTexCoordATI == NULL);
  glewInfoFunc("glSampleMapATI", glewSampleMapATI == NULL);
  glewInfoFunc("glSetFragmentShaderConstantATI", glewSetFragmentShaderConstantATI == NULL);
}

#endif /* GL_ATI_fragment_shader */

/* ------------------------ GL_ATI_map_object_buffer ----------------------- */

#ifdef GL_ATI_map_object_buffer

static void _glewInfo_GL_ATI_map_object_buffer (void)
{
  glewPrintExt("GL_ATI_map_object_buffer", GLEW_ATI_map_object_buffer);

  glewInfoFunc("glMapObjectBufferATI", glewMapObjectBufferATI == NULL);
  glewInfoFunc("glUnmapObjectBufferATI", glewUnmapObjectBufferATI == NULL);
}

#endif /* GL_ATI_map_object_buffer */

/* -------------------------- GL_ATI_pn_triangles -------------------------- */

#ifdef GL_ATI_pn_triangles

static void _glewInfo_GL_ATI_pn_triangles (void)
{
  glewPrintExt("GL_ATI_pn_triangles", GLEW_ATI_pn_triangles);

  glewInfoFunc("glPNTrianglesfATI", glPNTrianglewesfATI == NULL);
  glewInfoFunc("glPNTrianglesiATI", glPNTrianglewesiATI == NULL);
}

#endif /* GL_ATI_pn_triangles */

/* ------------------------ GL_ATI_separate_stencil ------------------------ */

#ifdef GL_ATI_separate_stencil

static void _glewInfo_GL_ATI_separate_stencil (void)
{
  glewPrintExt("GL_ATI_separate_stencil", GLEW_ATI_separate_stencil);

  glewInfoFunc("glStencilFuncSeparateATI", glewStencilFuncSeparateATI == NULL);
  glewInfoFunc("glStencilOpSeparateATI", glewStencilOpSeparateATI == NULL);
}

#endif /* GL_ATI_separate_stencil */

/* ---------------------- GL_ATI_text_fragment_shader ---------------------- */

#ifdef GL_ATI_text_fragment_shader

static void _glewInfo_GL_ATI_text_fragment_shader (void)
{
  glewPrintExt("GL_ATI_text_fragment_shader", GLEW_ATI_text_fragment_shader);
}

#endif /* GL_ATI_text_fragment_shader */

/* ---------------------- GL_ATI_texture_env_combine3 ---------------------- */

#ifdef GL_ATI_texture_env_combine3

static void _glewInfo_GL_ATI_texture_env_combine3 (void)
{
  glewPrintExt("GL_ATI_texture_env_combine3", GLEW_ATI_texture_env_combine3);
}

#endif /* GL_ATI_texture_env_combine3 */

/* -------------------------- GL_ATI_texture_float ------------------------- */

#ifdef GL_ATI_texture_float

static void _glewInfo_GL_ATI_texture_float (void)
{
  glewPrintExt("GL_ATI_texture_float", GLEW_ATI_texture_float);
}

#endif /* GL_ATI_texture_float */

/* ----------------------- GL_ATI_texture_mirror_once ---------------------- */

#ifdef GL_ATI_texture_mirror_once

static void _glewInfo_GL_ATI_texture_mirror_once (void)
{
  glewPrintExt("GL_ATI_texture_mirror_once", GLEW_ATI_texture_mirror_once);
}

#endif /* GL_ATI_texture_mirror_once */

/* ----------------------- GL_ATI_vertex_array_object ---------------------- */

#ifdef GL_ATI_vertex_array_object

static void _glewInfo_GL_ATI_vertex_array_object (void)
{
  glewPrintExt("GL_ATI_vertex_array_object", GLEW_ATI_vertex_array_object);

  glewInfoFunc("glArrayObjectATI", glewArrayObjectATI == NULL);
  glewInfoFunc("glFreeObjectBufferATI", glewFreeObjectBufferATI == NULL);
  glewInfoFunc("glGetArrayObjectfvATI", glewGetArrayObjectfvATI == NULL);
  glewInfoFunc("glGetArrayObjectivATI", glewGetArrayObjectivATI == NULL);
  glewInfoFunc("glGetObjectBufferfvATI", glewGetObjectBufferfvATI == NULL);
  glewInfoFunc("glGetObjectBufferivATI", glewGetObjectBufferivATI == NULL);
  glewInfoFunc("glGetVariantArrayObjectfvATI", glewGetVariantArrayObjectfvATI == NULL);
  glewInfoFunc("glGetVariantArrayObjectivATI", glewGetVariantArrayObjectivATI == NULL);
  glewInfoFunc("glIsObjectBufferATI", glewIsObjectBufferATI == NULL);
  glewInfoFunc("glNewObjectBufferATI", glewNewObjectBufferATI == NULL);
  glewInfoFunc("glUpdateObjectBufferATI", glewUpdateObjectBufferATI == NULL);
  glewInfoFunc("glVariantArrayObjectATI", glewVariantArrayObjectATI == NULL);
}

#endif /* GL_ATI_vertex_array_object */

/* ------------------- GL_ATI_vertex_attrib_array_object ------------------- */

#ifdef GL_ATI_vertex_attrib_array_object

static void _glewInfo_GL_ATI_vertex_attrib_array_object (void)
{
  glewPrintExt("GL_ATI_vertex_attrib_array_object", GLEW_ATI_vertex_attrib_array_object);

  glewInfoFunc("glGetVertexAttribArrayObjectfvATI", glewGetVertexAttribArrayObjectfvATI == NULL);
  glewInfoFunc("glGetVertexAttribArrayObjectivATI", glewGetVertexAttribArrayObjectivATI == NULL);
  glewInfoFunc("glVertexAttribArrayObjectATI", glewVertexAttribArrayObjectATI == NULL);
}

#endif /* GL_ATI_vertex_attrib_array_object */

/* ------------------------- GL_ATI_vertex_streams ------------------------- */

#ifdef GL_ATI_vertex_streams

static void _glewInfo_GL_ATI_vertex_streams (void)
{
  glewPrintExt("GL_ATI_vertex_streams", GLEW_ATI_vertex_streams);

  glewInfoFunc("glClientActiveVertexStreamATI", glewClientActiveVertexStreamATI == NULL);
  glewInfoFunc("glNormalStream3bATI", glewNormalStream3bATI == NULL);
  glewInfoFunc("glNormalStream3bvATI", glewNormalStream3bvATI == NULL);
  glewInfoFunc("glNormalStream3dATI", glewNormalStream3dATI == NULL);
  glewInfoFunc("glNormalStream3dvATI", glewNormalStream3dvATI == NULL);
  glewInfoFunc("glNormalStream3fATI", glewNormalStream3fATI == NULL);
  glewInfoFunc("glNormalStream3fvATI", glewNormalStream3fvATI == NULL);
  glewInfoFunc("glNormalStream3iATI", glewNormalStream3iATI == NULL);
  glewInfoFunc("glNormalStream3ivATI", glewNormalStream3ivATI == NULL);
  glewInfoFunc("glNormalStream3sATI", glewNormalStream3sATI == NULL);
  glewInfoFunc("glNormalStream3svATI", glewNormalStream3svATI == NULL);
  glewInfoFunc("glVertexBlendEnvfATI", glewVertexBlendEnvfATI == NULL);
  glewInfoFunc("glVertexBlendEnviATI", glewVertexBlendEnviATI == NULL);
  glewInfoFunc("glVertexStream2dATI", glewVertexStream2dATI == NULL);
  glewInfoFunc("glVertexStream2dvATI", glewVertexStream2dvATI == NULL);
  glewInfoFunc("glVertexStream2fATI", glewVertexStream2fATI == NULL);
  glewInfoFunc("glVertexStream2fvATI", glewVertexStream2fvATI == NULL);
  glewInfoFunc("glVertexStream2iATI", glewVertexStream2iATI == NULL);
  glewInfoFunc("glVertexStream2ivATI", glewVertexStream2ivATI == NULL);
  glewInfoFunc("glVertexStream2sATI", glewVertexStream2sATI == NULL);
  glewInfoFunc("glVertexStream2svATI", glewVertexStream2svATI == NULL);
  glewInfoFunc("glVertexStream3dATI", glewVertexStream3dATI == NULL);
  glewInfoFunc("glVertexStream3dvATI", glewVertexStream3dvATI == NULL);
  glewInfoFunc("glVertexStream3fATI", glewVertexStream3fATI == NULL);
  glewInfoFunc("glVertexStream3fvATI", glewVertexStream3fvATI == NULL);
  glewInfoFunc("glVertexStream3iATI", glewVertexStream3iATI == NULL);
  glewInfoFunc("glVertexStream3ivATI", glewVertexStream3ivATI == NULL);
  glewInfoFunc("glVertexStream3sATI", glewVertexStream3sATI == NULL);
  glewInfoFunc("glVertexStream3svATI", glewVertexStream3svATI == NULL);
  glewInfoFunc("glVertexStream4dATI", glewVertexStream4dATI == NULL);
  glewInfoFunc("glVertexStream4dvATI", glewVertexStream4dvATI == NULL);
  glewInfoFunc("glVertexStream4fATI", glewVertexStream4fATI == NULL);
  glewInfoFunc("glVertexStream4fvATI", glewVertexStream4fvATI == NULL);
  glewInfoFunc("glVertexStream4iATI", glewVertexStream4iATI == NULL);
  glewInfoFunc("glVertexStream4ivATI", glewVertexStream4ivATI == NULL);
  glewInfoFunc("glVertexStream4sATI", glewVertexStream4sATI == NULL);
  glewInfoFunc("glVertexStream4svATI", glewVertexStream4svATI == NULL);
}

#endif /* GL_ATI_vertex_streams */

/* --------------------------- GL_EXT_422_pixels --------------------------- */

#ifdef GL_EXT_422_pixels

static void _glewInfo_GL_EXT_422_pixels (void)
{
  glewPrintExt("GL_EXT_422_pixels", GLEW_EXT_422_pixels);
}

#endif /* GL_EXT_422_pixels */

/* ------------------------------ GL_EXT_abgr ------------------------------ */

#ifdef GL_EXT_abgr

static void _glewInfo_GL_EXT_abgr (void)
{
  glewPrintExt("GL_EXT_abgr", GLEW_EXT_abgr);
}

#endif /* GL_EXT_abgr */

/* ------------------------------ GL_EXT_bgra ------------------------------ */

#ifdef GL_EXT_bgra

static void _glewInfo_GL_EXT_bgra (void)
{
  glewPrintExt("GL_EXT_bgra", GLEW_EXT_bgra);
}

#endif /* GL_EXT_bgra */

/* --------------------------- GL_EXT_blend_color -------------------------- */

#ifdef GL_EXT_blend_color

static void _glewInfo_GL_EXT_blend_color (void)
{
  glewPrintExt("GL_EXT_blend_color", GLEW_EXT_blend_color);

  glewInfoFunc("glBlendColorEXT", glewBlendColorEXT == NULL);
}

#endif /* GL_EXT_blend_color */

/* ----------------------- GL_EXT_blend_func_separate ---------------------- */

#ifdef GL_EXT_blend_func_separate

static void _glewInfo_GL_EXT_blend_func_separate (void)
{
  glewPrintExt("GL_EXT_blend_func_separate", GLEW_EXT_blend_func_separate);

  glewInfoFunc("glBlendFuncSeparateEXT", glewBlendFuncSeparateEXT == NULL);
}

#endif /* GL_EXT_blend_func_separate */

/* ------------------------- GL_EXT_blend_logic_op ------------------------- */

#ifdef GL_EXT_blend_logic_op

static void _glewInfo_GL_EXT_blend_logic_op (void)
{
  glewPrintExt("GL_EXT_blend_logic_op", GLEW_EXT_blend_logic_op);
}

#endif /* GL_EXT_blend_logic_op */

/* -------------------------- GL_EXT_blend_minmax -------------------------- */

#ifdef GL_EXT_blend_minmax

static void _glewInfo_GL_EXT_blend_minmax (void)
{
  glewPrintExt("GL_EXT_blend_minmax", GLEW_EXT_blend_minmax);

  glewInfoFunc("glBlendEquationEXT", glewBlendEquationEXT == NULL);
}

#endif /* GL_EXT_blend_minmax */

/* ------------------------- GL_EXT_blend_subtract ------------------------- */

#ifdef GL_EXT_blend_subtract

static void _glewInfo_GL_EXT_blend_subtract (void)
{
  glewPrintExt("GL_EXT_blend_subtract", GLEW_EXT_blend_subtract);
}

#endif /* GL_EXT_blend_subtract */

/* ------------------------ GL_EXT_clip_volume_hint ------------------------ */

#ifdef GL_EXT_clip_volume_hint

static void _glewInfo_GL_EXT_clip_volume_hint (void)
{
  glewPrintExt("GL_EXT_clip_volume_hint", GLEW_EXT_clip_volume_hint);
}

#endif /* GL_EXT_clip_volume_hint */

/* ------------------------------ GL_EXT_cmyka ----------------------------- */

#ifdef GL_EXT_cmyka

static void _glewInfo_GL_EXT_cmyka (void)
{
  glewPrintExt("GL_EXT_cmyka", GLEW_EXT_cmyka);
}

#endif /* GL_EXT_cmyka */

/* ------------------------- GL_EXT_color_subtable ------------------------- */

#ifdef GL_EXT_color_subtable

static void _glewInfo_GL_EXT_color_subtable (void)
{
  glewPrintExt("GL_EXT_color_subtable", GLEW_EXT_color_subtable);

  glewInfoFunc("glColorSubTableEXT", glewColorSubTableEXT == NULL);
  glewInfoFunc("glCopyColorSubTableEXT", glewCopyColorSubTableEXT == NULL);
}

#endif /* GL_EXT_color_subtable */

/* ---------------------- GL_EXT_compiled_vertex_array --------------------- */

#ifdef GL_EXT_compiled_vertex_array

static void _glewInfo_GL_EXT_compiled_vertex_array (void)
{
  glewPrintExt("GL_EXT_compiled_vertex_array", GLEW_EXT_compiled_vertex_array);

  glewInfoFunc("glLockArraysEXT", glewLockArraysEXT == NULL);
  glewInfoFunc("glUnlockArraysEXT", glewUnlockArraysEXT == NULL);
}

#endif /* GL_EXT_compiled_vertex_array */

/* --------------------------- GL_EXT_convolution -------------------------- */

#ifdef GL_EXT_convolution

static void _glewInfo_GL_EXT_convolution (void)
{
  glewPrintExt("GL_EXT_convolution", GLEW_EXT_convolution);

  glewInfoFunc("glConvolutionFilter1DEXT", glewConvolutionFilter1DEXT == NULL);
  glewInfoFunc("glConvolutionFilter2DEXT", glewConvolutionFilter2DEXT == NULL);
  glewInfoFunc("glConvolutionParameterfEXT", glewConvolutionParameterfEXT == NULL);
  glewInfoFunc("glConvolutionParameterfvEXT", glewConvolutionParameterfvEXT == NULL);
  glewInfoFunc("glConvolutionParameteriEXT", glewConvolutionParameteriEXT == NULL);
  glewInfoFunc("glConvolutionParameterivEXT", glewConvolutionParameterivEXT == NULL);
  glewInfoFunc("glCopyConvolutionFilter1DEXT", glewCopyConvolutionFilter1DEXT == NULL);
  glewInfoFunc("glCopyConvolutionFilter2DEXT", glewCopyConvolutionFilter2DEXT == NULL);
  glewInfoFunc("glGetConvolutionFilterEXT", glewGetConvolutionFilterEXT == NULL);
  glewInfoFunc("glGetConvolutionParameterfvEXT", glewGetConvolutionParameterfvEXT == NULL);
  glewInfoFunc("glGetConvolutionParameterivEXT", glewGetConvolutionParameterivEXT == NULL);
  glewInfoFunc("glGetSeparableFilterEXT", glewGetSeparableFilterEXT == NULL);
  glewInfoFunc("glSeparableFilter2DEXT", glewSeparableFilter2DEXT == NULL);
}

#endif /* GL_EXT_convolution */

/* ------------------------ GL_EXT_coordinate_frame ------------------------ */

#ifdef GL_EXT_coordinate_frame

static void _glewInfo_GL_EXT_coordinate_frame (void)
{
  glewPrintExt("GL_EXT_coordinate_frame", GLEW_EXT_coordinate_frame);

  glewInfoFunc("glBinormalPointerEXT", glewBinormalPointerEXT == NULL);
  glewInfoFunc("glTangentPointerEXT", glewTangentPointerEXT == NULL);
}

#endif /* GL_EXT_coordinate_frame */

/* -------------------------- GL_EXT_copy_texture -------------------------- */

#ifdef GL_EXT_copy_texture

static void _glewInfo_GL_EXT_copy_texture (void)
{
  glewPrintExt("GL_EXT_copy_texture", GLEW_EXT_copy_texture);

  glewInfoFunc("glCopyTexImage1DEXT", glewCopyTexImage1DEXT == NULL);
  glewInfoFunc("glCopyTexImage2DEXT", glewCopyTexImage2DEXT == NULL);
  glewInfoFunc("glCopyTexSubImage1DEXT", glewCopyTexSubImage1DEXT == NULL);
  glewInfoFunc("glCopyTexSubImage2DEXT", glewCopyTexSubImage2DEXT == NULL);
  glewInfoFunc("glCopyTexSubImage3DEXT", glewCopyTexSubImage3DEXT == NULL);
}

#endif /* GL_EXT_copy_texture */

/* --------------------------- GL_EXT_cull_vertex -------------------------- */

#ifdef GL_EXT_cull_vertex

static void _glewInfo_GL_EXT_cull_vertex (void)
{
  glewPrintExt("GL_EXT_cull_vertex", GLEW_EXT_cull_vertex);

  glewInfoFunc("glCullParameterdvEXT", glewCullParameterdvEXT == NULL);
  glewInfoFunc("glCullParameterfvEXT", glewCullParameterfvEXT == NULL);
}

#endif /* GL_EXT_cull_vertex */

/* ------------------------ GL_EXT_depth_bounds_test ----------------------- */

#ifdef GL_EXT_depth_bounds_test

static void _glewInfo_GL_EXT_depth_bounds_test (void)
{
  glewPrintExt("GL_EXT_depth_bounds_test", GLEW_EXT_depth_bounds_test);

  glewInfoFunc("glDepthBoundsEXT", glewDepthBoundsEXT == NULL);
}

#endif /* GL_EXT_depth_bounds_test */

/* ----------------------- GL_EXT_draw_range_elements ---------------------- */

#ifdef GL_EXT_draw_range_elements

static void _glewInfo_GL_EXT_draw_range_elements (void)
{
  glewPrintExt("GL_EXT_draw_range_elements", GLEW_EXT_draw_range_elements);
}

#endif /* GL_EXT_draw_range_elements */

/* ---------------------------- GL_EXT_fog_coord --------------------------- */

#ifdef GL_EXT_fog_coord

static void _glewInfo_GL_EXT_fog_coord (void)
{
  glewPrintExt("GL_EXT_fog_coord", GLEW_EXT_fog_coord);

  glewInfoFunc("glFogCoordPointerEXT", glewFogCoordPointerEXT == NULL);
  glewInfoFunc("glFogCoorddEXT", glewFogCoorddEXT == NULL);
  glewInfoFunc("glFogCoorddvEXT", glewFogCoorddvEXT == NULL);
  glewInfoFunc("glFogCoordfEXT", glewFogCoordfEXT == NULL);
  glewInfoFunc("glFogCoordfvEXT", glewFogCoordfvEXT == NULL);
}

#endif /* GL_EXT_fog_coord */

/* ------------------------ GL_EXT_fragment_lighting ----------------------- */

#ifdef GL_EXT_fragment_lighting

static void _glewInfo_GL_EXT_fragment_lighting (void)
{
  glewPrintExt("GL_EXT_fragment_lighting", GLEW_EXT_fragment_lighting);

  glewInfoFunc("glFragmentColorMaterialEXT", glewFragmentColorMaterialEXT == NULL);
  glewInfoFunc("glFragmentLightModelfEXT", glewFragmentLightModelfEXT == NULL);
  glewInfoFunc("glFragmentLightModelfvEXT", glewFragmentLightModelfvEXT == NULL);
  glewInfoFunc("glFragmentLightModeliEXT", glewFragmentLightModeliEXT == NULL);
  glewInfoFunc("glFragmentLightModelivEXT", glewFragmentLightModelivEXT == NULL);
  glewInfoFunc("glFragmentLightfEXT", glewFragmentLightfEXT == NULL);
  glewInfoFunc("glFragmentLightfvEXT", glewFragmentLightfvEXT == NULL);
  glewInfoFunc("glFragmentLightiEXT", glewFragmentLightiEXT == NULL);
  glewInfoFunc("glFragmentLightivEXT", glewFragmentLightivEXT == NULL);
  glewInfoFunc("glFragmentMaterialfEXT", glewFragmentMaterialfEXT == NULL);
  glewInfoFunc("glFragmentMaterialfvEXT", glewFragmentMaterialfvEXT == NULL);
  glewInfoFunc("glFragmentMaterialiEXT", glewFragmentMaterialiEXT == NULL);
  glewInfoFunc("glFragmentMaterialivEXT", glewFragmentMaterialivEXT == NULL);
  glewInfoFunc("glGetFragmentLightfvEXT", glewGetFragmentLightfvEXT == NULL);
  glewInfoFunc("glGetFragmentLightivEXT", glewGetFragmentLightivEXT == NULL);
  glewInfoFunc("glGetFragmentMaterialfvEXT", glewGetFragmentMaterialfvEXT == NULL);
  glewInfoFunc("glGetFragmentMaterialivEXT", glewGetFragmentMaterialivEXT == NULL);
  glewInfoFunc("glLightEnviEXT", glewLightEnviEXT == NULL);
}

#endif /* GL_EXT_fragment_lighting */

/* ---------------------------- GL_EXT_histogram --------------------------- */

#ifdef GL_EXT_histogram

static void _glewInfo_GL_EXT_histogram (void)
{
  glewPrintExt("GL_EXT_histogram", GLEW_EXT_histogram);

  glewInfoFunc("glGetHistogramEXT", glewGetHistogramEXT == NULL);
  glewInfoFunc("glGetHistogramParameterfvEXT", glewGetHistogramParameterfvEXT == NULL);
  glewInfoFunc("glGetHistogramParameterivEXT", glewGetHistogramParameterivEXT == NULL);
  glewInfoFunc("glGetMinmaxEXT", glewGetMinmaxEXT == NULL);
  glewInfoFunc("glGetMinmaxParameterfvEXT", glewGetMinmaxParameterfvEXT == NULL);
  glewInfoFunc("glGetMinmaxParameterivEXT", glewGetMinmaxParameterivEXT == NULL);
  glewInfoFunc("glHistogramEXT", glewHistogramEXT == NULL);
  glewInfoFunc("glMinmaxEXT", glewMinmaxEXT == NULL);
  glewInfoFunc("glResetHistogramEXT", glewResetHistogramEXT == NULL);
  glewInfoFunc("glResetMinmaxEXT", glewResetMinmaxEXT == NULL);
}

#endif /* GL_EXT_histogram */

/* ----------------------- GL_EXT_index_array_formats ---------------------- */

#ifdef GL_EXT_index_array_formats

static void _glewInfo_GL_EXT_index_array_formats (void)
{
  glewPrintExt("GL_EXT_index_array_formats", GLEW_EXT_index_array_formats);
}

#endif /* GL_EXT_index_array_formats */

/* --------------------------- GL_EXT_index_func --------------------------- */

#ifdef GL_EXT_index_func

static void _glewInfo_GL_EXT_index_func (void)
{
  glewPrintExt("GL_EXT_index_func", GLEW_EXT_index_func);

  glewInfoFunc("glIndexFuncEXT", glewIndexFuncEXT == NULL);
}

#endif /* GL_EXT_index_func */

/* ------------------------- GL_EXT_index_material ------------------------- */

#ifdef GL_EXT_index_material

static void _glewInfo_GL_EXT_index_material (void)
{
  glewPrintExt("GL_EXT_index_material", GLEW_EXT_index_material);

  glewInfoFunc("glIndexMaterialEXT", glewIndexMaterialEXT == NULL);
}

#endif /* GL_EXT_index_material */

/* -------------------------- GL_EXT_index_texture ------------------------- */

#ifdef GL_EXT_index_texture

static void _glewInfo_GL_EXT_index_texture (void)
{
  glewPrintExt("GL_EXT_index_texture", GLEW_EXT_index_texture);
}

#endif /* GL_EXT_index_texture */

/* -------------------------- GL_EXT_light_texture ------------------------- */

#ifdef GL_EXT_light_texture

static void _glewInfo_GL_EXT_light_texture (void)
{
  glewPrintExt("GL_EXT_light_texture", GLEW_EXT_light_texture);

  glewInfoFunc("glApplyTextureEXT", glewApplyTextureEXT == NULL);
  glewInfoFunc("glTextureLightEXT", glewTextureLightEXT == NULL);
  glewInfoFunc("glTextureMaterialEXT", glewTextureMaterialEXT == NULL);
}

#endif /* GL_EXT_light_texture */

/* ------------------------- GL_EXT_misc_attribute ------------------------- */

#ifdef GL_EXT_misc_attribute

static void _glewInfo_GL_EXT_misc_attribute (void)
{
  glewPrintExt("GL_EXT_misc_attribute", GLEW_EXT_misc_attribute);
}

#endif /* GL_EXT_misc_attribute */

/* ------------------------ GL_EXT_multi_draw_arrays ----------------------- */

#ifdef GL_EXT_multi_draw_arrays

static void _glewInfo_GL_EXT_multi_draw_arrays (void)
{
  glewPrintExt("GL_EXT_multi_draw_arrays", GLEW_EXT_multi_draw_arrays);

  glewInfoFunc("glMultiDrawArraysEXT", glewMultiDrawArraysEXT == NULL);
  glewInfoFunc("glMultiDrawElementsEXT", glewMultiDrawElementsEXT == NULL);
}

#endif /* GL_EXT_multi_draw_arrays */

/* --------------------------- GL_EXT_multisample -------------------------- */

#ifdef GL_EXT_multisample

static void _glewInfo_GL_EXT_multisample (void)
{
  glewPrintExt("GL_EXT_multisample", GLEW_EXT_multisample);

  glewInfoFunc("glSampleMaskEXT", glewSampleMaskEXT == NULL);
  glewInfoFunc("glSamplePatternEXT", glewSamplePatternEXT == NULL);
}

#endif /* GL_EXT_multisample */

/* -------------------------- GL_EXT_packed_pixels ------------------------- */

#ifdef GL_EXT_packed_pixels

static void _glewInfo_GL_EXT_packed_pixels (void)
{
  glewPrintExt("GL_EXT_packed_pixels", GLEW_EXT_packed_pixels);
}

#endif /* GL_EXT_packed_pixels */

/* ------------------------ GL_EXT_paletted_texture ------------------------ */

#ifdef GL_EXT_paletted_texture

static void _glewInfo_GL_EXT_paletted_texture (void)
{
  glewPrintExt("GL_EXT_paletted_texture", GLEW_EXT_paletted_texture);

  glewInfoFunc("glColorTableEXT", glewColorTableEXT == NULL);
  glewInfoFunc("glGetColorTableEXT", glewGetColorTableEXT == NULL);
  glewInfoFunc("glGetColorTableParameterfvEXT", glewGetColorTableParameterfvEXT == NULL);
  glewInfoFunc("glGetColorTableParameterivEXT", glewGetColorTableParameterivEXT == NULL);
}

#endif /* GL_EXT_paletted_texture */

/* ------------------------- GL_EXT_pixel_transform ------------------------ */

#ifdef GL_EXT_pixel_transform

static void _glewInfo_GL_EXT_pixel_transform (void)
{
  glewPrintExt("GL_EXT_pixel_transform", GLEW_EXT_pixel_transform);

  glewInfoFunc("glGetPixelTransformParameterfvEXT", glewGetPixelTransformParameterfvEXT == NULL);
  glewInfoFunc("glGetPixelTransformParameterivEXT", glewGetPixelTransformParameterivEXT == NULL);
  glewInfoFunc("glPixelTransformParameterfEXT", glewPixelTransformParameterfEXT == NULL);
  glewInfoFunc("glPixelTransformParameterfvEXT", glewPixelTransformParameterfvEXT == NULL);
  glewInfoFunc("glPixelTransformParameteriEXT", glewPixelTransformParameteriEXT == NULL);
  glewInfoFunc("glPixelTransformParameterivEXT", glewPixelTransformParameterivEXT == NULL);
}

#endif /* GL_EXT_pixel_transform */

/* ------------------- GL_EXT_pixel_transform_color_table ------------------ */

#ifdef GL_EXT_pixel_transform_color_table

static void _glewInfo_GL_EXT_pixel_transform_color_table (void)
{
  glewPrintExt("GL_EXT_pixel_transform_color_table", GLEW_EXT_pixel_transform_color_table);
}

#endif /* GL_EXT_pixel_transform_color_table */

/* ------------------------ GL_EXT_point_parameters ------------------------ */

#ifdef GL_EXT_point_parameters

static void _glewInfo_GL_EXT_point_parameters (void)
{
  glewPrintExt("GL_EXT_point_parameters", GLEW_EXT_point_parameters);

  glewInfoFunc("glPointParameterfEXT", glewPointParameterfEXT == NULL);
  glewInfoFunc("glPointParameterfvEXT", glewPointParameterfvEXT == NULL);
}

#endif /* GL_EXT_point_parameters */

/* ------------------------- GL_EXT_polygon_offset ------------------------- */

#ifdef GL_EXT_polygon_offset

static void _glewInfo_GL_EXT_polygon_offset (void)
{
  glewPrintExt("GL_EXT_polygon_offset", GLEW_EXT_polygon_offset);

  glewInfoFunc("glPolygonOffsetEXT", glewPolygonOffsetEXT == NULL);
}

#endif /* GL_EXT_polygon_offset */

/* ------------------------- GL_EXT_rescale_normal ------------------------- */

#ifdef GL_EXT_rescale_normal

static void _glewInfo_GL_EXT_rescale_normal (void)
{
  glewPrintExt("GL_EXT_rescale_normal", GLEW_EXT_rescale_normal);
}

#endif /* GL_EXT_rescale_normal */

/* -------------------------- GL_EXT_scene_marker -------------------------- */

#ifdef GL_EXT_scene_marker

static void _glewInfo_GL_EXT_scene_marker (void)
{
  glewPrintExt("GL_EXT_scene_marker", GLEW_EXT_scene_marker);

  glewInfoFunc("glBeginSceneEXT", glewBeginSceneEXT == NULL);
  glewInfoFunc("glEndSceneEXT", glewEndSceneEXT == NULL);
}

#endif /* GL_EXT_scene_marker */

/* ------------------------- GL_EXT_secondary_color ------------------------ */

#ifdef GL_EXT_secondary_color

static void _glewInfo_GL_EXT_secondary_color (void)
{
  glewPrintExt("GL_EXT_secondary_color", GLEW_EXT_secondary_color);

  glewInfoFunc("glSecondaryColor3bEXT", glewSecondaryColor3bEXT == NULL);
  glewInfoFunc("glSecondaryColor3bvEXT", glewSecondaryColor3bvEXT == NULL);
  glewInfoFunc("glSecondaryColor3dEXT", glewSecondaryColor3dEXT == NULL);
  glewInfoFunc("glSecondaryColor3dvEXT", glewSecondaryColor3dvEXT == NULL);
  glewInfoFunc("glSecondaryColor3fEXT", glewSecondaryColor3fEXT == NULL);
  glewInfoFunc("glSecondaryColor3fvEXT", glewSecondaryColor3fvEXT == NULL);
  glewInfoFunc("glSecondaryColor3iEXT", glewSecondaryColor3iEXT == NULL);
  glewInfoFunc("glSecondaryColor3ivEXT", glewSecondaryColor3ivEXT == NULL);
  glewInfoFunc("glSecondaryColor3sEXT", glewSecondaryColor3sEXT == NULL);
  glewInfoFunc("glSecondaryColor3svEXT", glewSecondaryColor3svEXT == NULL);
  glewInfoFunc("glSecondaryColor3ubEXT", glewSecondaryColor3ubEXT == NULL);
  glewInfoFunc("glSecondaryColor3ubvEXT", glewSecondaryColor3ubvEXT == NULL);
  glewInfoFunc("glSecondaryColor3uiEXT", glewSecondaryColor3uiEXT == NULL);
  glewInfoFunc("glSecondaryColor3uivEXT", glewSecondaryColor3uivEXT == NULL);
  glewInfoFunc("glSecondaryColor3usEXT", glewSecondaryColor3usEXT == NULL);
  glewInfoFunc("glSecondaryColor3usvEXT", glewSecondaryColor3usvEXT == NULL);
  glewInfoFunc("glSecondaryColorPointerEXT", glewSecondaryColorPointerEXT == NULL);
}

#endif /* GL_EXT_secondary_color */

/* --------------------- GL_EXT_separate_specular_color -------------------- */

#ifdef GL_EXT_separate_specular_color

static void _glewInfo_GL_EXT_separate_specular_color (void)
{
  glewPrintExt("GL_EXT_separate_specular_color", GLEW_EXT_separate_specular_color);
}

#endif /* GL_EXT_separate_specular_color */

/* -------------------------- GL_EXT_shadow_funcs -------------------------- */

#ifdef GL_EXT_shadow_funcs

static void _glewInfo_GL_EXT_shadow_funcs (void)
{
  glewPrintExt("GL_EXT_shadow_funcs", GLEW_EXT_shadow_funcs);
}

#endif /* GL_EXT_shadow_funcs */

/* --------------------- GL_EXT_shared_texture_palette --------------------- */

#ifdef GL_EXT_shared_texture_palette

static void _glewInfo_GL_EXT_shared_texture_palette (void)
{
  glewPrintExt("GL_EXT_shared_texture_palette", GLEW_EXT_shared_texture_palette);
}

#endif /* GL_EXT_shared_texture_palette */

/* ------------------------ GL_EXT_stencil_two_side ------------------------ */

#ifdef GL_EXT_stencil_two_side

static void _glewInfo_GL_EXT_stencil_two_side (void)
{
  glewPrintExt("GL_EXT_stencil_two_side", GLEW_EXT_stencil_two_side);

  glewInfoFunc("glActiveStencilFaceEXT", glewActiveStencilFaceEXT == NULL);
}

#endif /* GL_EXT_stencil_two_side */

/* -------------------------- GL_EXT_stencil_wrap -------------------------- */

#ifdef GL_EXT_stencil_wrap

static void _glewInfo_GL_EXT_stencil_wrap (void)
{
  glewPrintExt("GL_EXT_stencil_wrap", GLEW_EXT_stencil_wrap);
}

#endif /* GL_EXT_stencil_wrap */

/* --------------------------- GL_EXT_subtexture --------------------------- */

#ifdef GL_EXT_subtexture

static void _glewInfo_GL_EXT_subtexture (void)
{
  glewPrintExt("GL_EXT_subtexture", GLEW_EXT_subtexture);

  glewInfoFunc("glTexSubImage1DEXT", glewTexSubImage1DEXT == NULL);
  glewInfoFunc("glTexSubImage2DEXT", glewTexSubImage2DEXT == NULL);
  glewInfoFunc("glTexSubImage3DEXT", glewTexSubImage3DEXT == NULL);
}

#endif /* GL_EXT_subtexture */

/* ----------------------------- GL_EXT_texture ---------------------------- */

#ifdef GL_EXT_texture

static void _glewInfo_GL_EXT_texture (void)
{
  glewPrintExt("GL_EXT_texture", GLEW_EXT_texture);
}

#endif /* GL_EXT_texture */

/* ---------------------------- GL_EXT_texture3D --------------------------- */

#ifdef GL_EXT_texture3D

static void _glewInfo_GL_EXT_texture3D (void)
{
  glewPrintExt("GL_EXT_texture3D", GLEW_EXT_texture3D);

  glewInfoFunc("glTexImage3DEXT", glewTexImage3DEXT == NULL);
}

#endif /* GL_EXT_texture3D */

/* -------------------- GL_EXT_texture_compression_s3tc -------------------- */

#ifdef GL_EXT_texture_compression_s3tc

static void _glewInfo_GL_EXT_texture_compression_s3tc (void)
{
  glewPrintExt("GL_EXT_texture_compression_s3tc", GLEW_EXT_texture_compression_s3tc);
}

#endif /* GL_EXT_texture_compression_s3tc */

/* --------------------------- GL_EXT_texture_env -------------------------- */

#ifdef GL_EXT_texture_env

static void _glewInfo_GL_EXT_texture_env (void)
{
  glewPrintExt("GL_EXT_texture_env", GLEW_EXT_texture_env);
}

#endif /* GL_EXT_texture_env */

/* ------------------------- GL_EXT_texture_env_add ------------------------ */

#ifdef GL_EXT_texture_env_add

static void _glewInfo_GL_EXT_texture_env_add (void)
{
  glewPrintExt("GL_EXT_texture_env_add", GLEW_EXT_texture_env_add);
}

#endif /* GL_EXT_texture_env_add */

/* ----------------------- GL_EXT_texture_env_combine ---------------------- */

#ifdef GL_EXT_texture_env_combine

static void _glewInfo_GL_EXT_texture_env_combine (void)
{
  glewPrintExt("GL_EXT_texture_env_combine", GLEW_EXT_texture_env_combine);
}

#endif /* GL_EXT_texture_env_combine */

/* ------------------------ GL_EXT_texture_env_dot3 ------------------------ */

#ifdef GL_EXT_texture_env_dot3

static void _glewInfo_GL_EXT_texture_env_dot3 (void)
{
  glewPrintExt("GL_EXT_texture_env_dot3", GLEW_EXT_texture_env_dot3);
}

#endif /* GL_EXT_texture_env_dot3 */

/* ------------------- GL_EXT_texture_filter_anisotropic ------------------- */

#ifdef GL_EXT_texture_filter_anisotropic

static void _glewInfo_GL_EXT_texture_filter_anisotropic (void)
{
  glewPrintExt("GL_EXT_texture_filter_anisotropic", GLEW_EXT_texture_filter_anisotropic);
}

#endif /* GL_EXT_texture_filter_anisotropic */

/* ------------------------ GL_EXT_texture_lod_bias ------------------------ */

#ifdef GL_EXT_texture_lod_bias

static void _glewInfo_GL_EXT_texture_lod_bias (void)
{
  glewPrintExt("GL_EXT_texture_lod_bias", GLEW_EXT_texture_lod_bias);
}

#endif /* GL_EXT_texture_lod_bias */

/* ---------------------- GL_EXT_texture_mirror_clamp ---------------------- */

#ifdef GL_EXT_texture_mirror_clamp

static void _glewInfo_GL_EXT_texture_mirror_clamp (void)
{
  glewPrintExt("GL_EXT_texture_mirror_clamp", GLEW_EXT_texture_mirror_clamp);
}

#endif /* GL_EXT_texture_mirror_clamp */

/* ------------------------- GL_EXT_texture_object ------------------------- */

#ifdef GL_EXT_texture_object

static void _glewInfo_GL_EXT_texture_object (void)
{
  glewPrintExt("GL_EXT_texture_object", GLEW_EXT_texture_object);

  glewInfoFunc("glAreTexturesResidentEXT", glewAreTexturesResidentEXT == NULL);
  glewInfoFunc("glBindTextureEXT", glewBindTextureEXT == NULL);
  glewInfoFunc("glDeleteTexturesEXT", glewDeleteTexturesEXT == NULL);
  glewInfoFunc("glGenTexturesEXT", glewGenTexturesEXT == NULL);
  glewInfoFunc("glIsTextureEXT", glewIsTextureEXT == NULL);
  glewInfoFunc("glPrioritizeTexturesEXT", glewPrioritizeTexturesEXT == NULL);
}

#endif /* GL_EXT_texture_object */

/* --------------------- GL_EXT_texture_perturb_normal --------------------- */

#ifdef GL_EXT_texture_perturb_normal

static void _glewInfo_GL_EXT_texture_perturb_normal (void)
{
  glewPrintExt("GL_EXT_texture_perturb_normal", GLEW_EXT_texture_perturb_normal);

  glewInfoFunc("glTextureNormalEXT", glewTextureNormalEXT == NULL);
}

#endif /* GL_EXT_texture_perturb_normal */

/* ------------------------ GL_EXT_texture_rectangle ----------------------- */

#ifdef GL_EXT_texture_rectangle

static void _glewInfo_GL_EXT_texture_rectangle (void)
{
  glewPrintExt("GL_EXT_texture_rectangle", GLEW_EXT_texture_rectangle);
}

#endif /* GL_EXT_texture_rectangle */

/* -------------------------- GL_EXT_vertex_array -------------------------- */

#ifdef GL_EXT_vertex_array

static void _glewInfo_GL_EXT_vertex_array (void)
{
  glewPrintExt("GL_EXT_vertex_array", GLEW_EXT_vertex_array);

  glewInfoFunc("glArrayElementEXT", glewArrayElementEXT == NULL);
  glewInfoFunc("glColorPointerEXT", glewColorPointerEXT == NULL);
  glewInfoFunc("glDrawArraysEXT", glewDrawArraysEXT == NULL);
  glewInfoFunc("glEdgeFlagPointerEXT", glewEdgeFlagPointerEXT == NULL);
  glewInfoFunc("glGetPointervEXT", glewGetPointervEXT == NULL);
  glewInfoFunc("glIndexPointerEXT", glewIndexPointerEXT == NULL);
  glewInfoFunc("glNormalPointerEXT", glewNormalPointerEXT == NULL);
  glewInfoFunc("glTexCoordPointerEXT", glewTexCoordPointerEXT == NULL);
  glewInfoFunc("glVertexPointerEXT", glewVertexPointerEXT == NULL);
}

#endif /* GL_EXT_vertex_array */

/* -------------------------- GL_EXT_vertex_shader ------------------------- */

#ifdef GL_EXT_vertex_shader

static void _glewInfo_GL_EXT_vertex_shader (void)
{
  glewPrintExt("GL_EXT_vertex_shader", GLEW_EXT_vertex_shader);

  glewInfoFunc("glBeginVertexShaderEXT", glewBeginVertexShaderEXT == NULL);
  glewInfoFunc("glBindLightParameterEXT", glewBindLightParameterEXT == NULL);
  glewInfoFunc("glBindMaterialParameterEXT", glewBindMaterialParameterEXT == NULL);
  glewInfoFunc("glBindParameterEXT", glewBindParameterEXT == NULL);
  glewInfoFunc("glBindTexGenParameterEXT", glewBindTexGenParameterEXT == NULL);
  glewInfoFunc("glBindTextureUnitParameterEXT", glewBindTextureUnitParameterEXT == NULL);
  glewInfoFunc("glBindVertexShaderEXT", glewBindVertexShaderEXT == NULL);
  glewInfoFunc("glDeleteVertexShaderEXT", glewDeleteVertexShaderEXT == NULL);
  glewInfoFunc("glDisableVariantClientStateEXT", glewDisableVariantClientStateEXT == NULL);
  glewInfoFunc("glEnableVariantClientStateEXT", glewEnableVariantClientStateEXT == NULL);
  glewInfoFunc("glEndVertexShaderEXT", glewEndVertexShaderEXT == NULL);
  glewInfoFunc("glExtractComponentEXT", glewExtractComponentEXT == NULL);
  glewInfoFunc("glGenSymbolsEXT", glewGenSymbolsEXT == NULL);
  glewInfoFunc("glGenVertexShadersEXT", glewGenVertexShadersEXT == NULL);
  glewInfoFunc("glGetInvariantBooleanvEXT", glewGetInvariantBooleanvEXT == NULL);
  glewInfoFunc("glGetInvariantFloatvEXT", glewGetInvariantFloatvEXT == NULL);
  glewInfoFunc("glGetInvariantIntegervEXT", glewGetInvariantIntegervEXT == NULL);
  glewInfoFunc("glGetLocalConstantBooleanvEXT", glewGetLocalConstantBooleanvEXT == NULL);
  glewInfoFunc("glGetLocalConstantFloatvEXT", glewGetLocalConstantFloatvEXT == NULL);
  glewInfoFunc("glGetLocalConstantIntegervEXT", glewGetLocalConstantIntegervEXT == NULL);
  glewInfoFunc("glGetVariantBooleanvEXT", glewGetVariantBooleanvEXT == NULL);
  glewInfoFunc("glGetVariantFloatvEXT", glewGetVariantFloatvEXT == NULL);
  glewInfoFunc("glGetVariantIntegervEXT", glewGetVariantIntegervEXT == NULL);
  glewInfoFunc("glGetVariantPointervEXT", glewGetVariantPointervEXT == NULL);
  glewInfoFunc("glInsertComponentEXT", glewInsertComponentEXT == NULL);
  glewInfoFunc("glIsVariantEnabledEXT", glewIsVariantEnabledEXT == NULL);
  glewInfoFunc("glSetInvariantEXT", glewSetInvariantEXT == NULL);
  glewInfoFunc("glSetLocalConstantEXT", glewSetLocalConstantEXT == NULL);
  glewInfoFunc("glShaderOp1EXT", glewShaderOp1EXT == NULL);
  glewInfoFunc("glShaderOp2EXT", glewShaderOp2EXT == NULL);
  glewInfoFunc("glShaderOp3EXT", glewShaderOp3EXT == NULL);
  glewInfoFunc("glSwizzleEXT", glewSwizzleEXT == NULL);
  glewInfoFunc("glVariantPointerEXT", glewVariantPointerEXT == NULL);
  glewInfoFunc("glVariantbvEXT", glewVariantbvEXT == NULL);
  glewInfoFunc("glVariantdvEXT", glewVariantdvEXT == NULL);
  glewInfoFunc("glVariantfvEXT", glewVariantfvEXT == NULL);
  glewInfoFunc("glVariantivEXT", glewVariantivEXT == NULL);
  glewInfoFunc("glVariantsvEXT", glewVariantsvEXT == NULL);
  glewInfoFunc("glVariantubvEXT", glewVariantubvEXT == NULL);
  glewInfoFunc("glVariantuivEXT", glewVariantuivEXT == NULL);
  glewInfoFunc("glVariantusvEXT", glewVariantusvEXT == NULL);
  glewInfoFunc("glWriteMaskEXT", glewWriteMaskEXT == NULL);
}

#endif /* GL_EXT_vertex_shader */

/* ------------------------ GL_EXT_vertex_weighting ------------------------ */

#ifdef GL_EXT_vertex_weighting

static void _glewInfo_GL_EXT_vertex_weighting (void)
{
  glewPrintExt("GL_EXT_vertex_weighting", GLEW_EXT_vertex_weighting);

  glewInfoFunc("glVertexWeightPointerEXT", glewVertexWeightPointerEXT == NULL);
  glewInfoFunc("glVertexWeightfEXT", glewVertexWeightfEXT == NULL);
  glewInfoFunc("glVertexWeightfvEXT", glewVertexWeightfvEXT == NULL);
}

#endif /* GL_EXT_vertex_weighting */

/* --------------------- GL_HP_convolution_border_modes -------------------- */

#ifdef GL_HP_convolution_border_modes

static void _glewInfo_GL_HP_convolution_border_modes (void)
{
  glewPrintExt("GL_HP_convolution_border_modes", GLEW_HP_convolution_border_modes);
}

#endif /* GL_HP_convolution_border_modes */

/* ------------------------- GL_HP_image_transform ------------------------- */

#ifdef GL_HP_image_transform

static void _glewInfo_GL_HP_image_transform (void)
{
  glewPrintExt("GL_HP_image_transform", GLEW_HP_image_transform);

  glewInfoFunc("glGetImageTransformParameterfvHP", glewGetImageTransformParameterfvHP == NULL);
  glewInfoFunc("glGetImageTransformParameterivHP", glewGetImageTransformParameterivHP == NULL);
  glewInfoFunc("glImageTransformParameterfHP", glewImageTransformParameterfHP == NULL);
  glewInfoFunc("glImageTransformParameterfvHP", glewImageTransformParameterfvHP == NULL);
  glewInfoFunc("glImageTransformParameteriHP", glewImageTransformParameteriHP == NULL);
  glewInfoFunc("glImageTransformParameterivHP", glewImageTransformParameterivHP == NULL);
}

#endif /* GL_HP_image_transform */

/* -------------------------- GL_HP_occlusion_test ------------------------- */

#ifdef GL_HP_occlusion_test

static void _glewInfo_GL_HP_occlusion_test (void)
{
  glewPrintExt("GL_HP_occlusion_test", GLEW_HP_occlusion_test);
}

#endif /* GL_HP_occlusion_test */

/* ------------------------- GL_HP_texture_lighting ------------------------ */

#ifdef GL_HP_texture_lighting

static void _glewInfo_GL_HP_texture_lighting (void)
{
  glewPrintExt("GL_HP_texture_lighting", GLEW_HP_texture_lighting);
}

#endif /* GL_HP_texture_lighting */

/* --------------------------- GL_IBM_cull_vertex -------------------------- */

#ifdef GL_IBM_cull_vertex

static void _glewInfo_GL_IBM_cull_vertex (void)
{
  glewPrintExt("GL_IBM_cull_vertex", GLEW_IBM_cull_vertex);
}

#endif /* GL_IBM_cull_vertex */

/* ---------------------- GL_IBM_multimode_draw_arrays --------------------- */

#ifdef GL_IBM_multimode_draw_arrays

static void _glewInfo_GL_IBM_multimode_draw_arrays (void)
{
  glewPrintExt("GL_IBM_multimode_draw_arrays", GLEW_IBM_multimode_draw_arrays);

  glewInfoFunc("glMultiModeDrawArraysIBM", glewMultiModeDrawArraysIBM == NULL);
  glewInfoFunc("glMultiModeDrawElementsIBM", glewMultiModeDrawElementsIBM == NULL);
}

#endif /* GL_IBM_multimode_draw_arrays */

/* ------------------------- GL_IBM_rasterpos_clip ------------------------- */

#ifdef GL_IBM_rasterpos_clip

static void _glewInfo_GL_IBM_rasterpos_clip (void)
{
  glewPrintExt("GL_IBM_rasterpos_clip", GLEW_IBM_rasterpos_clip);
}

#endif /* GL_IBM_rasterpos_clip */

/* --------------------------- GL_IBM_static_data -------------------------- */

#ifdef GL_IBM_static_data

static void _glewInfo_GL_IBM_static_data (void)
{
  glewPrintExt("GL_IBM_static_data", GLEW_IBM_static_data);
}

#endif /* GL_IBM_static_data */

/* --------------------- GL_IBM_texture_mirrored_repeat -------------------- */

#ifdef GL_IBM_texture_mirrored_repeat

static void _glewInfo_GL_IBM_texture_mirrored_repeat (void)
{
  glewPrintExt("GL_IBM_texture_mirrored_repeat", GLEW_IBM_texture_mirrored_repeat);
}

#endif /* GL_IBM_texture_mirrored_repeat */

/* ----------------------- GL_IBM_vertex_array_lists ----------------------- */

#ifdef GL_IBM_vertex_array_lists

static void _glewInfo_GL_IBM_vertex_array_lists (void)
{
  glewPrintExt("GL_IBM_vertex_array_lists", GLEW_IBM_vertex_array_lists);

  glewInfoFunc("glColorPointerListIBM", glewColorPointerListIBM == NULL);
  glewInfoFunc("glEdgeFlagPointerListIBM", glewEdgeFlagPointerListIBM == NULL);
  glewInfoFunc("glFogCoordPointerListIBM", glewFogCoordPointerListIBM == NULL);
  glewInfoFunc("glIndexPointerListIBM", glewIndexPointerListIBM == NULL);
  glewInfoFunc("glNormalPointerListIBM", glewNormalPointerListIBM == NULL);
  glewInfoFunc("glSecondaryColorPointerListIBM", glewSecondaryColorPointerListIBM == NULL);
  glewInfoFunc("glTexCoordPointerListIBM", glewTexCoordPointerListIBM == NULL);
  glewInfoFunc("glVertexPointerListIBM", glewVertexPointerListIBM == NULL);
}

#endif /* GL_IBM_vertex_array_lists */

/* -------------------------- GL_INGR_color_clamp -------------------------- */

#ifdef GL_INGR_color_clamp

static void _glewInfo_GL_INGR_color_clamp (void)
{
  glewPrintExt("GL_INGR_color_clamp", GLEW_INGR_color_clamp);
}

#endif /* GL_INGR_color_clamp */

/* ------------------------- GL_INGR_interlace_read ------------------------ */

#ifdef GL_INGR_interlace_read

static void _glewInfo_GL_INGR_interlace_read (void)
{
  glewPrintExt("GL_INGR_interlace_read", GLEW_INGR_interlace_read);
}

#endif /* GL_INGR_interlace_read */

/* ------------------------ GL_INTEL_parallel_arrays ----------------------- */

#ifdef GL_INTEL_parallel_arrays

static void _glewInfo_GL_INTEL_parallel_arrays (void)
{
  glewPrintExt("GL_INTEL_parallel_arrays", GLEW_INTEL_parallel_arrays);

  glewInfoFunc("glColorPointervINTEL", glewColorPointervINTEL == NULL);
  glewInfoFunc("glNormalPointervINTEL", glewNormalPointervINTEL == NULL);
  glewInfoFunc("glTexCoordPointervINTEL", glewTexCoordPointervINTEL == NULL);
  glewInfoFunc("glVertexPointervINTEL", glewVertexPointervINTEL == NULL);
}

#endif /* GL_INTEL_parallel_arrays */

/* ------------------------ GL_INTEL_texture_scissor ----------------------- */

#ifdef GL_INTEL_texture_scissor

static void _glewInfo_GL_INTEL_texture_scissor (void)
{
  glewPrintExt("GL_INTEL_texture_scissor", GLEW_INTEL_texture_scissor);

  glewInfoFunc("glTexScissorFuncINTEL", glewTexScissorFuncINTEL == NULL);
  glewInfoFunc("glTexScissorINTEL", glewTexScissorINTEL == NULL);
}

#endif /* GL_INTEL_texture_scissor */

/* ------------------------- GL_MESA_resize_buffers ------------------------ */

#ifdef GL_MESA_resize_buffers

static void _glewInfo_GL_MESA_resize_buffers (void)
{
  glewPrintExt("GL_MESA_resize_buffers", GLEW_MESA_resize_buffers);

  glewInfoFunc("glResizeBuffersMESA", glewResizeBuffersMESA == NULL);
}

#endif /* GL_MESA_resize_buffers */

/* --------------------------- GL_MESA_window_pos -------------------------- */

#ifdef GL_MESA_window_pos

static void _glewInfo_GL_MESA_window_pos (void)
{
  glewPrintExt("GL_MESA_window_pos", GLEW_MESA_window_pos);

  glewInfoFunc("glWindowPos2dMESA", glewWindowPos2dMESA == NULL);
  glewInfoFunc("glWindowPos2dvMESA", glewWindowPos2dvMESA == NULL);
  glewInfoFunc("glWindowPos2fMESA", glewWindowPos2fMESA == NULL);
  glewInfoFunc("glWindowPos2fvMESA", glewWindowPos2fvMESA == NULL);
  glewInfoFunc("glWindowPos2iMESA", glewWindowPos2iMESA == NULL);
  glewInfoFunc("glWindowPos2ivMESA", glewWindowPos2ivMESA == NULL);
  glewInfoFunc("glWindowPos2sMESA", glewWindowPos2sMESA == NULL);
  glewInfoFunc("glWindowPos2svMESA", glewWindowPos2svMESA == NULL);
  glewInfoFunc("glWindowPos3dMESA", glewWindowPos3dMESA == NULL);
  glewInfoFunc("glWindowPos3dvMESA", glewWindowPos3dvMESA == NULL);
  glewInfoFunc("glWindowPos3fMESA", glewWindowPos3fMESA == NULL);
  glewInfoFunc("glWindowPos3fvMESA", glewWindowPos3fvMESA == NULL);
  glewInfoFunc("glWindowPos3iMESA", glewWindowPos3iMESA == NULL);
  glewInfoFunc("glWindowPos3ivMESA", glewWindowPos3ivMESA == NULL);
  glewInfoFunc("glWindowPos3sMESA", glewWindowPos3sMESA == NULL);
  glewInfoFunc("glWindowPos3svMESA", glewWindowPos3svMESA == NULL);
  glewInfoFunc("glWindowPos4dMESA", glewWindowPos4dMESA == NULL);
  glewInfoFunc("glWindowPos4dvMESA", glewWindowPos4dvMESA == NULL);
  glewInfoFunc("glWindowPos4fMESA", glewWindowPos4fMESA == NULL);
  glewInfoFunc("glWindowPos4fvMESA", glewWindowPos4fvMESA == NULL);
  glewInfoFunc("glWindowPos4iMESA", glewWindowPos4iMESA == NULL);
  glewInfoFunc("glWindowPos4ivMESA", glewWindowPos4ivMESA == NULL);
  glewInfoFunc("glWindowPos4sMESA", glewWindowPos4sMESA == NULL);
  glewInfoFunc("glWindowPos4svMESA", glewWindowPos4svMESA == NULL);
}

#endif /* GL_MESA_window_pos */

/* --------------------------- GL_NV_blend_square -------------------------- */

#ifdef GL_NV_blend_square

static void _glewInfo_GL_NV_blend_square (void)
{
  glewPrintExt("GL_NV_blend_square", GLEW_NV_blend_square);
}

#endif /* GL_NV_blend_square */

/* ----------------------- GL_NV_copy_depth_to_color ----------------------- */

#ifdef GL_NV_copy_depth_to_color

static void _glewInfo_GL_NV_copy_depth_to_color (void)
{
  glewPrintExt("GL_NV_copy_depth_to_color", GLEW_NV_copy_depth_to_color);
}

#endif /* GL_NV_copy_depth_to_color */

/* --------------------------- GL_NV_depth_clamp --------------------------- */

#ifdef GL_NV_depth_clamp

static void _glewInfo_GL_NV_depth_clamp (void)
{
  glewPrintExt("GL_NV_depth_clamp", GLEW_NV_depth_clamp);
}

#endif /* GL_NV_depth_clamp */

/* -------------------------- GL_NV_element_array -------------------------- */

#ifdef GL_NV_element_array

static void _glewInfo_GL_NV_element_array (void)
{
  glewPrintExt("GL_NV_element_array", GLEW_NV_element_array);

  glewInfoFunc("glDrawElementArrayNV", glewDrawElementArrayNV == NULL);
  glewInfoFunc("glDrawRangeElementArrayNV", glewDrawRangeElementArrayNV == NULL);
  glewInfoFunc("glElementPointerNV", glewElementPointerNV == NULL);
  glewInfoFunc("glMultiDrawElementArrayNV", glewMultiDrawElementArrayNV == NULL);
  glewInfoFunc("glMultiDrawRangeElementArrayNV", glewMultiDrawRangeElementArrayNV == NULL);
}

#endif /* GL_NV_element_array */

/* ---------------------------- GL_NV_evaluators --------------------------- */

#ifdef GL_NV_evaluators

static void _glewInfo_GL_NV_evaluators (void)
{
  glewPrintExt("GL_NV_evaluators", GLEW_NV_evaluators);

  glewInfoFunc("glEvalMapsNV", glewEvalMapsNV == NULL);
  glewInfoFunc("glGetMapAttribParameterfvNV", glewGetMapAttribParameterfvNV == NULL);
  glewInfoFunc("glGetMapAttribParameterivNV", glewGetMapAttribParameterivNV == NULL);
  glewInfoFunc("glGetMapControlPointsNV", glewGetMapControlPointsNV == NULL);
  glewInfoFunc("glGetMapParameterfvNV", glewGetMapParameterfvNV == NULL);
  glewInfoFunc("glGetMapParameterivNV", glewGetMapParameterivNV == NULL);
  glewInfoFunc("glMapControlPointsNV", glewMapControlPointsNV == NULL);
  glewInfoFunc("glMapParameterfvNV", glewMapParameterfvNV == NULL);
  glewInfoFunc("glMapParameterivNV", glewMapParameterivNV == NULL);
}

#endif /* GL_NV_evaluators */

/* ------------------------------ GL_NV_fence ------------------------------ */

#ifdef GL_NV_fence

static void _glewInfo_GL_NV_fence (void)
{
  glewPrintExt("GL_NV_fence", GLEW_NV_fence);

  glewInfoFunc("glDeleteFencesNV", glewDeleteFencesNV == NULL);
  glewInfoFunc("glFinishFenceNV", glewFinishFenceNV == NULL);
  glewInfoFunc("glGenFencesNV", glewGenFencesNV == NULL);
  glewInfoFunc("glGetFenceivNV", glewGetFenceivNV == NULL);
  glewInfoFunc("glIsFenceNV", glewIsFenceNV == NULL);
  glewInfoFunc("glSetFenceNV", glewSetFenceNV == NULL);
  glewInfoFunc("glTestFenceNV", glewTestFenceNV == NULL);
}

#endif /* GL_NV_fence */

/* --------------------------- GL_NV_float_buffer -------------------------- */

#ifdef GL_NV_float_buffer

static void _glewInfo_GL_NV_float_buffer (void)
{
  glewPrintExt("GL_NV_float_buffer", GLEW_NV_float_buffer);
}

#endif /* GL_NV_float_buffer */

/* --------------------------- GL_NV_fog_distance -------------------------- */

#ifdef GL_NV_fog_distance

static void _glewInfo_GL_NV_fog_distance (void)
{
  glewPrintExt("GL_NV_fog_distance", GLEW_NV_fog_distance);
}

#endif /* GL_NV_fog_distance */

/* ------------------------- GL_NV_fragment_program ------------------------ */

#ifdef GL_NV_fragment_program

static void _glewInfo_GL_NV_fragment_program (void)
{
  glewPrintExt("GL_NV_fragment_program", GLEW_NV_fragment_program);

  glewInfoFunc("glGetProgramNamedParameterdvNV", glewGetProgramNamedParameterdvNV == NULL);
  glewInfoFunc("glGetProgramNamedParameterfvNV", glewGetProgramNamedParameterfvNV == NULL);
  glewInfoFunc("glProgramNamedParameter4dNV", glewProgramNamedParameter4dNV == NULL);
  glewInfoFunc("glProgramNamedParameter4dvNV", glewProgramNamedParameter4dvNV == NULL);
  glewInfoFunc("glProgramNamedParameter4fNV", glewProgramNamedParameter4fNV == NULL);
  glewInfoFunc("glProgramNamedParameter4fvNV", glewProgramNamedParameter4fvNV == NULL);
}

#endif /* GL_NV_fragment_program */

/* ---------------------------- GL_NV_half_float --------------------------- */

#ifdef GL_NV_half_float

static void _glewInfo_GL_NV_half_float (void)
{
  glewPrintExt("GL_NV_half_float", GLEW_NV_half_float);

  glewInfoFunc("glColor3hNV", glewColor3hNV == NULL);
  glewInfoFunc("glColor3hvNV", glewColor3hvNV == NULL);
  glewInfoFunc("glColor4hNV", glewColor4hNV == NULL);
  glewInfoFunc("glColor4hvNV", glewColor4hvNV == NULL);
  glewInfoFunc("glFogCoordhNV", glewFogCoordhNV == NULL);
  glewInfoFunc("glFogCoordhvNV", glewFogCoordhvNV == NULL);
  glewInfoFunc("glMultiTexCoord1hNV", glewMultiTexCoord1hNV == NULL);
  glewInfoFunc("glMultiTexCoord1hvNV", glewMultiTexCoord1hvNV == NULL);
  glewInfoFunc("glMultiTexCoord2hNV", glewMultiTexCoord2hNV == NULL);
  glewInfoFunc("glMultiTexCoord2hvNV", glewMultiTexCoord2hvNV == NULL);
  glewInfoFunc("glMultiTexCoord3hNV", glewMultiTexCoord3hNV == NULL);
  glewInfoFunc("glMultiTexCoord3hvNV", glewMultiTexCoord3hvNV == NULL);
  glewInfoFunc("glMultiTexCoord4hNV", glewMultiTexCoord4hNV == NULL);
  glewInfoFunc("glMultiTexCoord4hvNV", glewMultiTexCoord4hvNV == NULL);
  glewInfoFunc("glNormal3hNV", glewNormal3hNV == NULL);
  glewInfoFunc("glNormal3hvNV", glewNormal3hvNV == NULL);
  glewInfoFunc("glSecondaryColor3hNV", glewSecondaryColor3hNV == NULL);
  glewInfoFunc("glSecondaryColor3hvNV", glewSecondaryColor3hvNV == NULL);
  glewInfoFunc("glTexCoord1hNV", glewTexCoord1hNV == NULL);
  glewInfoFunc("glTexCoord1hvNV", glewTexCoord1hvNV == NULL);
  glewInfoFunc("glTexCoord2hNV", glewTexCoord2hNV == NULL);
  glewInfoFunc("glTexCoord2hvNV", glewTexCoord2hvNV == NULL);
  glewInfoFunc("glTexCoord3hNV", glewTexCoord3hNV == NULL);
  glewInfoFunc("glTexCoord3hvNV", glewTexCoord3hvNV == NULL);
  glewInfoFunc("glTexCoord4hNV", glewTexCoord4hNV == NULL);
  glewInfoFunc("glTexCoord4hvNV", glewTexCoord4hvNV == NULL);
  glewInfoFunc("glVertex2hNV", glewVertex2hNV == NULL);
  glewInfoFunc("glVertex2hvNV", glewVertex2hvNV == NULL);
  glewInfoFunc("glVertex3hNV", glewVertex3hNV == NULL);
  glewInfoFunc("glVertex3hvNV", glewVertex3hvNV == NULL);
  glewInfoFunc("glVertex4hNV", glewVertex4hNV == NULL);
  glewInfoFunc("glVertex4hvNV", glewVertex4hvNV == NULL);
  glewInfoFunc("glVertexAttrib1hNV", glewVertexAttrib1hNV == NULL);
  glewInfoFunc("glVertexAttrib1hvNV", glewVertexAttrib1hvNV == NULL);
  glewInfoFunc("glVertexAttrib2hNV", glewVertexAttrib2hNV == NULL);
  glewInfoFunc("glVertexAttrib2hvNV", glewVertexAttrib2hvNV == NULL);
  glewInfoFunc("glVertexAttrib3hNV", glewVertexAttrib3hNV == NULL);
  glewInfoFunc("glVertexAttrib3hvNV", glewVertexAttrib3hvNV == NULL);
  glewInfoFunc("glVertexAttrib4hNV", glewVertexAttrib4hNV == NULL);
  glewInfoFunc("glVertexAttrib4hvNV", glewVertexAttrib4hvNV == NULL);
  glewInfoFunc("glVertexAttribs1hvNV", glewVertexAttribs1hvNV == NULL);
  glewInfoFunc("glVertexAttribs2hvNV", glewVertexAttribs2hvNV == NULL);
  glewInfoFunc("glVertexAttribs3hvNV", glewVertexAttribs3hvNV == NULL);
  glewInfoFunc("glVertexAttribs4hvNV", glewVertexAttribs4hvNV == NULL);
  glewInfoFunc("glVertexWeighthNV", glewVertexWeighthNV == NULL);
  glewInfoFunc("glVertexWeighthvNV", glewVertexWeighthvNV == NULL);
}

#endif /* GL_NV_half_float */

/* ------------------------ GL_NV_light_max_exponent ----------------------- */

#ifdef GL_NV_light_max_exponent

static void _glewInfo_GL_NV_light_max_exponent (void)
{
  glewPrintExt("GL_NV_light_max_exponent", GLEW_NV_light_max_exponent);
}

#endif /* GL_NV_light_max_exponent */

/* --------------------- GL_NV_multisample_filter_hint --------------------- */

#ifdef GL_NV_multisample_filter_hint

static void _glewInfo_GL_NV_multisample_filter_hint (void)
{
  glewPrintExt("GL_NV_multisample_filter_hint", GLEW_NV_multisample_filter_hint);
}

#endif /* GL_NV_multisample_filter_hint */

/* ------------------------- GL_NV_occlusion_query ------------------------- */

#ifdef GL_NV_occlusion_query

static void _glewInfo_GL_NV_occlusion_query (void)
{
  glewPrintExt("GL_NV_occlusion_query", GLEW_NV_occlusion_query);

  glewInfoFunc("glBeginOcclusionQueryNV", glewBeginOcclusionQueryNV == NULL);
  glewInfoFunc("glDeleteOcclusionQueriesNV", glewDeleteOcclusionQueriesNV == NULL);
  glewInfoFunc("glEndOcclusionQueryNV", glewEndOcclusionQueryNV == NULL);
  glewInfoFunc("glGenOcclusionQueriesNV", glewGenOcclusionQueriesNV == NULL);
  glewInfoFunc("glGetOcclusionQueryivNV", glewGetOcclusionQueryivNV == NULL);
  glewInfoFunc("glGetOcclusionQueryuivNV", glewGetOcclusionQueryuivNV == NULL);
  glewInfoFunc("glIsOcclusionQueryNV", glewIsOcclusionQueryNV == NULL);
}

#endif /* GL_NV_occlusion_query */

/* ----------------------- GL_NV_packed_depth_stencil ---------------------- */

#ifdef GL_NV_packed_depth_stencil

static void _glewInfo_GL_NV_packed_depth_stencil (void)
{
  glewPrintExt("GL_NV_packed_depth_stencil", GLEW_NV_packed_depth_stencil);
}

#endif /* GL_NV_packed_depth_stencil */

/* ------------------------- GL_NV_pixel_data_range ------------------------ */

#ifdef GL_NV_pixel_data_range

static void _glewInfo_GL_NV_pixel_data_range (void)
{
  glewPrintExt("GL_NV_pixel_data_range", GLEW_NV_pixel_data_range);

  glewInfoFunc("glFlushPixelDataRangeNV", glewFlushPixelDataRangeNV == NULL);
  glewInfoFunc("glPixelDataRangeNV", glewPixelDataRangeNV == NULL);
}

#endif /* GL_NV_pixel_data_range */

/* --------------------------- GL_NV_point_sprite -------------------------- */

#ifdef GL_NV_point_sprite

static void _glewInfo_GL_NV_point_sprite (void)
{
  glewPrintExt("GL_NV_point_sprite", GLEW_NV_point_sprite);

  glewInfoFunc("glPointParameteriNV", glewPointParameteriNV == NULL);
  glewInfoFunc("glPointParameterivNV", glewPointParameterivNV == NULL);
}

#endif /* GL_NV_point_sprite */

/* ------------------------ GL_NV_primitive_restart ------------------------ */

#ifdef GL_NV_primitive_restart

static void _glewInfo_GL_NV_primitive_restart (void)
{
  glewPrintExt("GL_NV_primitive_restart", GLEW_NV_primitive_restart);

  glewInfoFunc("glPrimitiveRestartIndexNV", glewPrimitiveRestartIndexNV == NULL);
  glewInfoFunc("glPrimitiveRestartNV", glewPrimitiveRestartNV == NULL);
}

#endif /* GL_NV_primitive_restart */

/* ------------------------ GL_NV_register_combiners ----------------------- */

#ifdef GL_NV_register_combiners

static void _glewInfo_GL_NV_register_combiners (void)
{
  glewPrintExt("GL_NV_register_combiners", GLEW_NV_register_combiners);

  glewInfoFunc("glCombinerInputNV", glewCombinerInputNV == NULL);
  glewInfoFunc("glCombinerOutputNV", glewCombinerOutputNV == NULL);
  glewInfoFunc("glCombinerParameterfNV", glewCombinerParameterfNV == NULL);
  glewInfoFunc("glCombinerParameterfvNV", glewCombinerParameterfvNV == NULL);
  glewInfoFunc("glCombinerParameteriNV", glewCombinerParameteriNV == NULL);
  glewInfoFunc("glCombinerParameterivNV", glewCombinerParameterivNV == NULL);
  glewInfoFunc("glFinalCombinerInputNV", glewFinalCombinerInputNV == NULL);
  glewInfoFunc("glGetCombinerInputParameterfvNV", glewGetCombinerInputParameterfvNV == NULL);
  glewInfoFunc("glGetCombinerInputParameterivNV", glewGetCombinerInputParameterivNV == NULL);
  glewInfoFunc("glGetCombinerOutputParameterfvNV", glewGetCombinerOutputParameterfvNV == NULL);
  glewInfoFunc("glGetCombinerOutputParameterivNV", glewGetCombinerOutputParameterivNV == NULL);
  glewInfoFunc("glGetFinalCombinerInputParameterfvNV", glewGetFinalCombinerInputParameterfvNV == NULL);
  glewInfoFunc("glGetFinalCombinerInputParameterivNV", glewGetFinalCombinerInputParameterivNV == NULL);
}

#endif /* GL_NV_register_combiners */

/* ----------------------- GL_NV_register_combiners2 ----------------------- */

#ifdef GL_NV_register_combiners2

static void _glewInfo_GL_NV_register_combiners2 (void)
{
  glewPrintExt("GL_NV_register_combiners2", GLEW_NV_register_combiners2);

  glewInfoFunc("glCombinerStageParameterfvNV", glewCombinerStageParameterfvNV == NULL);
  glewInfoFunc("glGetCombinerStageParameterfvNV", glewGetCombinerStageParameterfvNV == NULL);
}

#endif /* GL_NV_register_combiners2 */

/* -------------------------- GL_NV_texgen_emboss -------------------------- */

#ifdef GL_NV_texgen_emboss

static void _glewInfo_GL_NV_texgen_emboss (void)
{
  glewPrintExt("GL_NV_texgen_emboss", GLEW_NV_texgen_emboss);
}

#endif /* GL_NV_texgen_emboss */

/* ------------------------ GL_NV_texgen_reflection ------------------------ */

#ifdef GL_NV_texgen_reflection

static void _glewInfo_GL_NV_texgen_reflection (void)
{
  glewPrintExt("GL_NV_texgen_reflection", GLEW_NV_texgen_reflection);
}

#endif /* GL_NV_texgen_reflection */

/* --------------------- GL_NV_texture_compression_vtc --------------------- */

#ifdef GL_NV_texture_compression_vtc

static void _glewInfo_GL_NV_texture_compression_vtc (void)
{
  glewPrintExt("GL_NV_texture_compression_vtc", GLEW_NV_texture_compression_vtc);
}

#endif /* GL_NV_texture_compression_vtc */

/* ----------------------- GL_NV_texture_env_combine4 ---------------------- */

#ifdef GL_NV_texture_env_combine4

static void _glewInfo_GL_NV_texture_env_combine4 (void)
{
  glewPrintExt("GL_NV_texture_env_combine4", GLEW_NV_texture_env_combine4);
}

#endif /* GL_NV_texture_env_combine4 */

/* ---------------------- GL_NV_texture_expand_normal ---------------------- */

#ifdef GL_NV_texture_expand_normal

static void _glewInfo_GL_NV_texture_expand_normal (void)
{
  glewPrintExt("GL_NV_texture_expand_normal", GLEW_NV_texture_expand_normal);
}

#endif /* GL_NV_texture_expand_normal */

/* ------------------------ GL_NV_texture_rectangle ------------------------ */

#ifdef GL_NV_texture_rectangle

static void _glewInfo_GL_NV_texture_rectangle (void)
{
  glewPrintExt("GL_NV_texture_rectangle", GLEW_NV_texture_rectangle);
}

#endif /* GL_NV_texture_rectangle */

/* -------------------------- GL_NV_texture_shader ------------------------- */

#ifdef GL_NV_texture_shader

static void _glewInfo_GL_NV_texture_shader (void)
{
  glewPrintExt("GL_NV_texture_shader", GLEW_NV_texture_shader);
}

#endif /* GL_NV_texture_shader */

/* ------------------------- GL_NV_texture_shader2 ------------------------- */

#ifdef GL_NV_texture_shader2

static void _glewInfo_GL_NV_texture_shader2 (void)
{
  glewPrintExt("GL_NV_texture_shader2", GLEW_NV_texture_shader2);
}

#endif /* GL_NV_texture_shader2 */

/* ------------------------- GL_NV_texture_shader3 ------------------------- */

#ifdef GL_NV_texture_shader3

static void _glewInfo_GL_NV_texture_shader3 (void)
{
  glewPrintExt("GL_NV_texture_shader3", GLEW_NV_texture_shader3);
}

#endif /* GL_NV_texture_shader3 */

/* ------------------------ GL_NV_vertex_array_range ----------------------- */

#ifdef GL_NV_vertex_array_range

static void _glewInfo_GL_NV_vertex_array_range (void)
{
  glewPrintExt("GL_NV_vertex_array_range", GLEW_NV_vertex_array_range);

  glewInfoFunc("glFlushVertexArrayRangeNV", glewFlushVertexArrayRangeNV == NULL);
  glewInfoFunc("glVertexArrayRangeNV", glewVertexArrayRangeNV == NULL);
}

#endif /* GL_NV_vertex_array_range */

/* ----------------------- GL_NV_vertex_array_range2 ----------------------- */

#ifdef GL_NV_vertex_array_range2

static void _glewInfo_GL_NV_vertex_array_range2 (void)
{
  glewPrintExt("GL_NV_vertex_array_range2", GLEW_NV_vertex_array_range2);
}

#endif /* GL_NV_vertex_array_range2 */

/* -------------------------- GL_NV_vertex_program ------------------------- */

#ifdef GL_NV_vertex_program

static void _glewInfo_GL_NV_vertex_program (void)
{
  glewPrintExt("GL_NV_vertex_program", GLEW_NV_vertex_program);

  glewInfoFunc("glAreProgramsResidentNV", glewAreProgramsResidentNV == NULL);
  glewInfoFunc("glBindProgramNV", glewBindProgramNV == NULL);
  glewInfoFunc("glDeleteProgramsNV", glewDeleteProgramsNV == NULL);
  glewInfoFunc("glExecuteProgramNV", glewExecuteProgramNV == NULL);
  glewInfoFunc("glGenProgramsNV", glewGenProgramsNV == NULL);
  glewInfoFunc("glGetProgramParameterdvNV", glewGetProgramParameterdvNV == NULL);
  glewInfoFunc("glGetProgramParameterfvNV", glewGetProgramParameterfvNV == NULL);
  glewInfoFunc("glGetProgramStringNV", glewGetProgramStringNV == NULL);
  glewInfoFunc("glGetProgramivNV", glewGetProgramivNV == NULL);
  glewInfoFunc("glGetTrackMatrixivNV", glewGetTrackMatrixivNV == NULL);
  glewInfoFunc("glGetVertexAttribPointervNV", glewGetVertexAttribPointervNV == NULL);
  glewInfoFunc("glGetVertexAttribdvNV", glewGetVertexAttribdvNV == NULL);
  glewInfoFunc("glGetVertexAttribfvNV", glewGetVertexAttribfvNV == NULL);
  glewInfoFunc("glGetVertexAttribivNV", glewGetVertexAttribivNV == NULL);
  glewInfoFunc("glIsProgramNV", glewIsProgramNV == NULL);
  glewInfoFunc("glLoadProgramNV", glewLoadProgramNV == NULL);
  glewInfoFunc("glProgramParameter4dNV", glewProgramParameter4dNV == NULL);
  glewInfoFunc("glProgramParameter4dvNV", glewProgramParameter4dvNV == NULL);
  glewInfoFunc("glProgramParameter4fNV", glewProgramParameter4fNV == NULL);
  glewInfoFunc("glProgramParameter4fvNV", glewProgramParameter4fvNV == NULL);
  glewInfoFunc("glProgramParameters4dvNV", glewProgramParameters4dvNV == NULL);
  glewInfoFunc("glProgramParameters4fvNV", glewProgramParameters4fvNV == NULL);
  glewInfoFunc("glRequestResidentProgramsNV", glewRequestResidentProgramsNV == NULL);
  glewInfoFunc("glTrackMatrixNV", glewTrackMatrixNV == NULL);
  glewInfoFunc("glVertexAttrib1dNV", glewVertexAttrib1dNV == NULL);
  glewInfoFunc("glVertexAttrib1dvNV", glewVertexAttrib1dvNV == NULL);
  glewInfoFunc("glVertexAttrib1fNV", glewVertexAttrib1fNV == NULL);
  glewInfoFunc("glVertexAttrib1fvNV", glewVertexAttrib1fvNV == NULL);
  glewInfoFunc("glVertexAttrib1sNV", glewVertexAttrib1sNV == NULL);
  glewInfoFunc("glVertexAttrib1svNV", glewVertexAttrib1svNV == NULL);
  glewInfoFunc("glVertexAttrib2dNV", glewVertexAttrib2dNV == NULL);
  glewInfoFunc("glVertexAttrib2dvNV", glewVertexAttrib2dvNV == NULL);
  glewInfoFunc("glVertexAttrib2fNV", glewVertexAttrib2fNV == NULL);
  glewInfoFunc("glVertexAttrib2fvNV", glewVertexAttrib2fvNV == NULL);
  glewInfoFunc("glVertexAttrib2sNV", glewVertexAttrib2sNV == NULL);
  glewInfoFunc("glVertexAttrib2svNV", glewVertexAttrib2svNV == NULL);
  glewInfoFunc("glVertexAttrib3dNV", glewVertexAttrib3dNV == NULL);
  glewInfoFunc("glVertexAttrib3dvNV", glewVertexAttrib3dvNV == NULL);
  glewInfoFunc("glVertexAttrib3fNV", glewVertexAttrib3fNV == NULL);
  glewInfoFunc("glVertexAttrib3fvNV", glewVertexAttrib3fvNV == NULL);
  glewInfoFunc("glVertexAttrib3sNV", glewVertexAttrib3sNV == NULL);
  glewInfoFunc("glVertexAttrib3svNV", glewVertexAttrib3svNV == NULL);
  glewInfoFunc("glVertexAttrib4dNV", glewVertexAttrib4dNV == NULL);
  glewInfoFunc("glVertexAttrib4dvNV", glewVertexAttrib4dvNV == NULL);
  glewInfoFunc("glVertexAttrib4fNV", glewVertexAttrib4fNV == NULL);
  glewInfoFunc("glVertexAttrib4fvNV", glewVertexAttrib4fvNV == NULL);
  glewInfoFunc("glVertexAttrib4sNV", glewVertexAttrib4sNV == NULL);
  glewInfoFunc("glVertexAttrib4svNV", glewVertexAttrib4svNV == NULL);
  glewInfoFunc("glVertexAttrib4ubNV", glewVertexAttrib4ubNV == NULL);
  glewInfoFunc("glVertexAttrib4ubvNV", glewVertexAttrib4ubvNV == NULL);
  glewInfoFunc("glVertexAttribPointerNV", glewVertexAttribPointerNV == NULL);
  glewInfoFunc("glVertexAttribs1dvNV", glewVertexAttribs1dvNV == NULL);
  glewInfoFunc("glVertexAttribs1fvNV", glewVertexAttribs1fvNV == NULL);
  glewInfoFunc("glVertexAttribs1svNV", glewVertexAttribs1svNV == NULL);
  glewInfoFunc("glVertexAttribs2dvNV", glewVertexAttribs2dvNV == NULL);
  glewInfoFunc("glVertexAttribs2fvNV", glewVertexAttribs2fvNV == NULL);
  glewInfoFunc("glVertexAttribs2svNV", glewVertexAttribs2svNV == NULL);
  glewInfoFunc("glVertexAttribs3dvNV", glewVertexAttribs3dvNV == NULL);
  glewInfoFunc("glVertexAttribs3fvNV", glewVertexAttribs3fvNV == NULL);
  glewInfoFunc("glVertexAttribs3svNV", glewVertexAttribs3svNV == NULL);
  glewInfoFunc("glVertexAttribs4dvNV", glewVertexAttribs4dvNV == NULL);
  glewInfoFunc("glVertexAttribs4fvNV", glewVertexAttribs4fvNV == NULL);
  glewInfoFunc("glVertexAttribs4svNV", glewVertexAttribs4svNV == NULL);
  glewInfoFunc("glVertexAttribs4ubvNV", glewVertexAttribs4ubvNV == NULL);
}

#endif /* GL_NV_vertex_program */

/* ------------------------ GL_NV_vertex_program1_1 ------------------------ */

#ifdef GL_NV_vertex_program1_1

static void _glewInfo_GL_NV_vertex_program1_1 (void)
{
  glewPrintExt("GL_NV_vertex_program1_1", GLEW_NV_vertex_program1_1);
}

#endif /* GL_NV_vertex_program1_1 */

/* ------------------------- GL_NV_vertex_program2 ------------------------- */

#ifdef GL_NV_vertex_program2

static void _glewInfo_GL_NV_vertex_program2 (void)
{
  glewPrintExt("GL_NV_vertex_program2", GLEW_NV_vertex_program2);
}

#endif /* GL_NV_vertex_program2 */

/* ---------------------------- GL_OML_interlace --------------------------- */

#ifdef GL_OML_interlace

static void _glewInfo_GL_OML_interlace (void)
{
  glewPrintExt("GL_OML_interlace", GLEW_OML_interlace);
}

#endif /* GL_OML_interlace */

/* ---------------------------- GL_OML_resample ---------------------------- */

#ifdef GL_OML_resample

static void _glewInfo_GL_OML_resample (void)
{
  glewPrintExt("GL_OML_resample", GLEW_OML_resample);
}

#endif /* GL_OML_resample */

/* ---------------------------- GL_OML_subsample --------------------------- */

#ifdef GL_OML_subsample

static void _glewInfo_GL_OML_subsample (void)
{
  glewPrintExt("GL_OML_subsample", GLEW_OML_subsample);
}

#endif /* GL_OML_subsample */

/* --------------------------- GL_PGI_misc_hints --------------------------- */

#ifdef GL_PGI_misc_hints

static void _glewInfo_GL_PGI_misc_hints (void)
{
  glewPrintExt("GL_PGI_misc_hints", GLEW_PGI_misc_hints);
}

#endif /* GL_PGI_misc_hints */

/* -------------------------- GL_PGI_vertex_hints -------------------------- */

#ifdef GL_PGI_vertex_hints

static void _glewInfo_GL_PGI_vertex_hints (void)
{
  glewPrintExt("GL_PGI_vertex_hints", GLEW_PGI_vertex_hints);
}

#endif /* GL_PGI_vertex_hints */

/* ----------------------- GL_REND_screen_coordinates ---------------------- */

#ifdef GL_REND_screen_coordinates

static void _glewInfo_GL_REND_screen_coordinates (void)
{
  glewPrintExt("GL_REND_screen_coordinates", GLEW_REND_screen_coordinates);
}

#endif /* GL_REND_screen_coordinates */

/* ------------------------------- GL_S3_s3tc ------------------------------ */

#ifdef GL_S3_s3tc

static void _glewInfo_GL_S3_s3tc (void)
{
  glewPrintExt("GL_S3_s3tc", GLEW_S3_s3tc);
}

#endif /* GL_S3_s3tc */

/* -------------------------- GL_SGIS_color_range -------------------------- */

#ifdef GL_SGIS_color_range

static void _glewInfo_GL_SGIS_color_range (void)
{
  glewPrintExt("GL_SGIS_color_range", GLEW_SGIS_color_range);
}

#endif /* GL_SGIS_color_range */

/* ------------------------- GL_SGIS_detail_texture ------------------------ */

#ifdef GL_SGIS_detail_texture

static void _glewInfo_GL_SGIS_detail_texture (void)
{
  glewPrintExt("GL_SGIS_detail_texture", GLEW_SGIS_detail_texture);

  glewInfoFunc("glDetailTexFuncSGIS", glewDetailTexFuncSGIS == NULL);
  glewInfoFunc("glGetDetailTexFuncSGIS", glewGetDetailTexFuncSGIS == NULL);
}

#endif /* GL_SGIS_detail_texture */

/* -------------------------- GL_SGIS_fog_function ------------------------- */

#ifdef GL_SGIS_fog_function

static void _glewInfo_GL_SGIS_fog_function (void)
{
  glewPrintExt("GL_SGIS_fog_function", GLEW_SGIS_fog_function);

  glewInfoFunc("glFogFuncSGIS", glewFogFuncSGIS == NULL);
  glewInfoFunc("glGetFogFuncSGIS", glewGetFogFuncSGIS == NULL);
}

#endif /* GL_SGIS_fog_function */

/* ------------------------ GL_SGIS_generate_mipmap ------------------------ */

#ifdef GL_SGIS_generate_mipmap

static void _glewInfo_GL_SGIS_generate_mipmap (void)
{
  glewPrintExt("GL_SGIS_generate_mipmap", GLEW_SGIS_generate_mipmap);
}

#endif /* GL_SGIS_generate_mipmap */

/* -------------------------- GL_SGIS_multisample -------------------------- */

#ifdef GL_SGIS_multisample

static void _glewInfo_GL_SGIS_multisample (void)
{
  glewPrintExt("GL_SGIS_multisample", GLEW_SGIS_multisample);

  glewInfoFunc("glSampleMaskSGIS", glewSampleMaskSGIS == NULL);
  glewInfoFunc("glSamplePatternSGIS", glewSamplePatternSGIS == NULL);
}

#endif /* GL_SGIS_multisample */

/* ------------------------- GL_SGIS_pixel_texture ------------------------- */

#ifdef GL_SGIS_pixel_texture

static void _glewInfo_GL_SGIS_pixel_texture (void)
{
  glewPrintExt("GL_SGIS_pixel_texture", GLEW_SGIS_pixel_texture);
}

#endif /* GL_SGIS_pixel_texture */

/* ------------------------ GL_SGIS_sharpen_texture ------------------------ */

#ifdef GL_SGIS_sharpen_texture

static void _glewInfo_GL_SGIS_sharpen_texture (void)
{
  glewPrintExt("GL_SGIS_sharpen_texture", GLEW_SGIS_sharpen_texture);

  glewInfoFunc("glGetSharpenTexFuncSGIS", glewGetSharpenTexFuncSGIS == NULL);
  glewInfoFunc("glSharpenTexFuncSGIS", glewSharpenTexFuncSGIS == NULL);
}

#endif /* GL_SGIS_sharpen_texture */

/* --------------------------- GL_SGIS_texture4D --------------------------- */

#ifdef GL_SGIS_texture4D

static void _glewInfo_GL_SGIS_texture4D (void)
{
  glewPrintExt("GL_SGIS_texture4D", GLEW_SGIS_texture4D);

  glewInfoFunc("glTexImage4DSGIS", glewTexImage4DSGIS == NULL);
  glewInfoFunc("glTexSubImage4DSGIS", glewTexSubImage4DSGIS == NULL);
}

#endif /* GL_SGIS_texture4D */

/* ---------------------- GL_SGIS_texture_border_clamp --------------------- */

#ifdef GL_SGIS_texture_border_clamp

static void _glewInfo_GL_SGIS_texture_border_clamp (void)
{
  glewPrintExt("GL_SGIS_texture_border_clamp", GLEW_SGIS_texture_border_clamp);
}

#endif /* GL_SGIS_texture_border_clamp */

/* ----------------------- GL_SGIS_texture_edge_clamp ---------------------- */

#ifdef GL_SGIS_texture_edge_clamp

static void _glewInfo_GL_SGIS_texture_edge_clamp (void)
{
  glewPrintExt("GL_SGIS_texture_edge_clamp", GLEW_SGIS_texture_edge_clamp);
}

#endif /* GL_SGIS_texture_edge_clamp */

/* ------------------------ GL_SGIS_texture_filter4 ------------------------ */

#ifdef GL_SGIS_texture_filter4

static void _glewInfo_GL_SGIS_texture_filter4 (void)
{
  glewPrintExt("GL_SGIS_texture_filter4", GLEW_SGIS_texture_filter4);

  glewInfoFunc("glGetTexFilterFuncSGIS", glewGetTexFilterFuncSGIS == NULL);
  glewInfoFunc("glTexFilterFuncSGIS", glewTexFilterFuncSGIS == NULL);
}

#endif /* GL_SGIS_texture_filter4 */

/* -------------------------- GL_SGIS_texture_lod -------------------------- */

#ifdef GL_SGIS_texture_lod

static void _glewInfo_GL_SGIS_texture_lod (void)
{
  glewPrintExt("GL_SGIS_texture_lod", GLEW_SGIS_texture_lod);
}

#endif /* GL_SGIS_texture_lod */

/* ------------------------- GL_SGIS_texture_select ------------------------ */

#ifdef GL_SGIS_texture_select

static void _glewInfo_GL_SGIS_texture_select (void)
{
  glewPrintExt("GL_SGIS_texture_select", GLEW_SGIS_texture_select);
}

#endif /* GL_SGIS_texture_select */

/* ----------------------------- GL_SGIX_async ----------------------------- */

#ifdef GL_SGIX_async

static void _glewInfo_GL_SGIX_async (void)
{
  glewPrintExt("GL_SGIX_async", GLEW_SGIX_async);

  glewInfoFunc("glAsyncMarkerSGIX", glewAsyncMarkerSGIX == NULL);
  glewInfoFunc("glDeleteAsyncMarkersSGIX", glewDeleteAsyncMarkersSGIX == NULL);
  glewInfoFunc("glFinishAsyncSGIX", glewFinishAsyncSGIX == NULL);
  glewInfoFunc("glGenAsyncMarkersSGIX", glewGenAsyncMarkersSGIX == NULL);
  glewInfoFunc("glIsAsyncMarkerSGIX", glewIsAsyncMarkerSGIX == NULL);
  glewInfoFunc("glPollAsyncSGIX", glewPollAsyncSGIX == NULL);
}

#endif /* GL_SGIX_async */

/* ------------------------ GL_SGIX_async_histogram ------------------------ */

#ifdef GL_SGIX_async_histogram

static void _glewInfo_GL_SGIX_async_histogram (void)
{
  glewPrintExt("GL_SGIX_async_histogram", GLEW_SGIX_async_histogram);
}

#endif /* GL_SGIX_async_histogram */

/* -------------------------- GL_SGIX_async_pixel -------------------------- */

#ifdef GL_SGIX_async_pixel

static void _glewInfo_GL_SGIX_async_pixel (void)
{
  glewPrintExt("GL_SGIX_async_pixel", GLEW_SGIX_async_pixel);
}

#endif /* GL_SGIX_async_pixel */

/* ----------------------- GL_SGIX_blend_alpha_minmax ---------------------- */

#ifdef GL_SGIX_blend_alpha_minmax

static void _glewInfo_GL_SGIX_blend_alpha_minmax (void)
{
  glewPrintExt("GL_SGIX_blend_alpha_minmax", GLEW_SGIX_blend_alpha_minmax);
}

#endif /* GL_SGIX_blend_alpha_minmax */

/* ---------------------------- GL_SGIX_clipmap ---------------------------- */

#ifdef GL_SGIX_clipmap

static void _glewInfo_GL_SGIX_clipmap (void)
{
  glewPrintExt("GL_SGIX_clipmap", GLEW_SGIX_clipmap);
}

#endif /* GL_SGIX_clipmap */

/* ------------------------- GL_SGIX_depth_texture ------------------------- */

#ifdef GL_SGIX_depth_texture

static void _glewInfo_GL_SGIX_depth_texture (void)
{
  glewPrintExt("GL_SGIX_depth_texture", GLEW_SGIX_depth_texture);
}

#endif /* GL_SGIX_depth_texture */

/* -------------------------- GL_SGIX_flush_raster ------------------------- */

#ifdef GL_SGIX_flush_raster

static void _glewInfo_GL_SGIX_flush_raster (void)
{
  glewPrintExt("GL_SGIX_flush_raster", GLEW_SGIX_flush_raster);

  glewInfoFunc("glFlushRasterSGIX", glewFlushRasterSGIX == NULL);
}

#endif /* GL_SGIX_flush_raster */

/* --------------------------- GL_SGIX_fog_offset -------------------------- */

#ifdef GL_SGIX_fog_offset

static void _glewInfo_GL_SGIX_fog_offset (void)
{
  glewPrintExt("GL_SGIX_fog_offset", GLEW_SGIX_fog_offset);
}

#endif /* GL_SGIX_fog_offset */

/* -------------------------- GL_SGIX_fog_texture -------------------------- */

#ifdef GL_SGIX_fog_texture

static void _glewInfo_GL_SGIX_fog_texture (void)
{
  glewPrintExt("GL_SGIX_fog_texture", GLEW_SGIX_fog_texture);

  glewInfoFunc("glTextureFogSGIX", glewTextureFogSGIX == NULL);
}

#endif /* GL_SGIX_fog_texture */

/* ------------------- GL_SGIX_fragment_specular_lighting ------------------ */

#ifdef GL_SGIX_fragment_specular_lighting

static void _glewInfo_GL_SGIX_fragment_specular_lighting (void)
{
  glewPrintExt("GL_SGIX_fragment_specular_lighting", GLEW_SGIX_fragment_specular_lighting);

  glewInfoFunc("glFragmentColorMaterialSGIX", glewFragmentColorMaterialSGIX == NULL);
  glewInfoFunc("glFragmentLightModelfSGIX", glewFragmentLightModelfSGIX == NULL);
  glewInfoFunc("glFragmentLightModelfvSGIX", glewFragmentLightModelfvSGIX == NULL);
  glewInfoFunc("glFragmentLightModeliSGIX", glewFragmentLightModeliSGIX == NULL);
  glewInfoFunc("glFragmentLightModelivSGIX", glewFragmentLightModelivSGIX == NULL);
  glewInfoFunc("glFragmentLightfSGIX", glewFragmentLightfSGIX == NULL);
  glewInfoFunc("glFragmentLightfvSGIX", glewFragmentLightfvSGIX == NULL);
  glewInfoFunc("glFragmentLightiSGIX", glewFragmentLightiSGIX == NULL);
  glewInfoFunc("glFragmentLightivSGIX", glewFragmentLightivSGIX == NULL);
  glewInfoFunc("glFragmentMaterialfSGIX", glewFragmentMaterialfSGIX == NULL);
  glewInfoFunc("glFragmentMaterialfvSGIX", glewFragmentMaterialfvSGIX == NULL);
  glewInfoFunc("glFragmentMaterialiSGIX", glewFragmentMaterialiSGIX == NULL);
  glewInfoFunc("glFragmentMaterialivSGIX", glewFragmentMaterialivSGIX == NULL);
  glewInfoFunc("glGetFragmentLightfvSGIX", glewGetFragmentLightfvSGIX == NULL);
  glewInfoFunc("glGetFragmentLightivSGIX", glewGetFragmentLightivSGIX == NULL);
  glewInfoFunc("glGetFragmentMaterialfvSGIX", glewGetFragmentMaterialfvSGIX == NULL);
  glewInfoFunc("glGetFragmentMaterialivSGIX", glewGetFragmentMaterialivSGIX == NULL);
}

#endif /* GL_SGIX_fragment_specular_lighting */

/* --------------------------- GL_SGIX_framezoom --------------------------- */

#ifdef GL_SGIX_framezoom

static void _glewInfo_GL_SGIX_framezoom (void)
{
  glewPrintExt("GL_SGIX_framezoom", GLEW_SGIX_framezoom);

  glewInfoFunc("glFrameZoomSGIX", glewFrameZoomSGIX == NULL);
}

#endif /* GL_SGIX_framezoom */

/* --------------------------- GL_SGIX_interlace --------------------------- */

#ifdef GL_SGIX_interlace

static void _glewInfo_GL_SGIX_interlace (void)
{
  glewPrintExt("GL_SGIX_interlace", GLEW_SGIX_interlace);
}

#endif /* GL_SGIX_interlace */

/* ------------------------- GL_SGIX_ir_instrument1 ------------------------ */

#ifdef GL_SGIX_ir_instrument1

static void _glewInfo_GL_SGIX_ir_instrument1 (void)
{
  glewPrintExt("GL_SGIX_ir_instrument1", GLEW_SGIX_ir_instrument1);
}

#endif /* GL_SGIX_ir_instrument1 */

/* ------------------------- GL_SGIX_list_priority ------------------------- */

#ifdef GL_SGIX_list_priority

static void _glewInfo_GL_SGIX_list_priority (void)
{
  glewPrintExt("GL_SGIX_list_priority", GLEW_SGIX_list_priority);
}

#endif /* GL_SGIX_list_priority */

/* ------------------------- GL_SGIX_pixel_texture ------------------------- */

#ifdef GL_SGIX_pixel_texture

static void _glewInfo_GL_SGIX_pixel_texture (void)
{
  glewPrintExt("GL_SGIX_pixel_texture", GLEW_SGIX_pixel_texture);

  glewInfoFunc("glPixelTexGenSGIX", glewPixelTexGenSGIX == NULL);
}

#endif /* GL_SGIX_pixel_texture */

/* ----------------------- GL_SGIX_pixel_texture_bits ---------------------- */

#ifdef GL_SGIX_pixel_texture_bits

static void _glewInfo_GL_SGIX_pixel_texture_bits (void)
{
  glewPrintExt("GL_SGIX_pixel_texture_bits", GLEW_SGIX_pixel_texture_bits);
}

#endif /* GL_SGIX_pixel_texture_bits */

/* ------------------------ GL_SGIX_reference_plane ------------------------ */

#ifdef GL_SGIX_reference_plane

static void _glewInfo_GL_SGIX_reference_plane (void)
{
  glewPrintExt("GL_SGIX_reference_plane", GLEW_SGIX_reference_plane);

  glewInfoFunc("glReferencePlaneSGIX", glewReferencePlaneSGIX == NULL);
}

#endif /* GL_SGIX_reference_plane */

/* ---------------------------- GL_SGIX_resample --------------------------- */

#ifdef GL_SGIX_resample

static void _glewInfo_GL_SGIX_resample (void)
{
  glewPrintExt("GL_SGIX_resample", GLEW_SGIX_resample);
}

#endif /* GL_SGIX_resample */

/* ----------------------------- GL_SGIX_shadow ---------------------------- */

#ifdef GL_SGIX_shadow

static void _glewInfo_GL_SGIX_shadow (void)
{
  glewPrintExt("GL_SGIX_shadow", GLEW_SGIX_shadow);
}

#endif /* GL_SGIX_shadow */

/* ------------------------- GL_SGIX_shadow_ambient ------------------------ */

#ifdef GL_SGIX_shadow_ambient

static void _glewInfo_GL_SGIX_shadow_ambient (void)
{
  glewPrintExt("GL_SGIX_shadow_ambient", GLEW_SGIX_shadow_ambient);
}

#endif /* GL_SGIX_shadow_ambient */

/* ----------------------------- GL_SGIX_sprite ---------------------------- */

#ifdef GL_SGIX_sprite

static void _glewInfo_GL_SGIX_sprite (void)
{
  glewPrintExt("GL_SGIX_sprite", GLEW_SGIX_sprite);

  glewInfoFunc("glSpriteParameterfSGIX", glewSpriteParameterfSGIX == NULL);
  glewInfoFunc("glSpriteParameterfvSGIX", glewSpriteParameterfvSGIX == NULL);
  glewInfoFunc("glSpriteParameteriSGIX", glewSpriteParameteriSGIX == NULL);
  glewInfoFunc("glSpriteParameterivSGIX", glewSpriteParameterivSGIX == NULL);
}

#endif /* GL_SGIX_sprite */

/* ----------------------- GL_SGIX_tag_sample_buffer ----------------------- */

#ifdef GL_SGIX_tag_sample_buffer

static void _glewInfo_GL_SGIX_tag_sample_buffer (void)
{
  glewPrintExt("GL_SGIX_tag_sample_buffer", GLEW_SGIX_tag_sample_buffer);

  glewInfoFunc("glTagSampleBufferSGIX", glewTagSampleBufferSGIX == NULL);
}

#endif /* GL_SGIX_tag_sample_buffer */

/* ------------------------ GL_SGIX_texture_add_env ------------------------ */

#ifdef GL_SGIX_texture_add_env

static void _glewInfo_GL_SGIX_texture_add_env (void)
{
  glewPrintExt("GL_SGIX_texture_add_env", GLEW_SGIX_texture_add_env);
}

#endif /* GL_SGIX_texture_add_env */

/* -------------------- GL_SGIX_texture_coordinate_clamp ------------------- */

#ifdef GL_SGIX_texture_coordinate_clamp

static void _glewInfo_GL_SGIX_texture_coordinate_clamp (void)
{
  glewPrintExt("GL_SGIX_texture_coordinate_clamp", GLEW_SGIX_texture_coordinate_clamp);
}

#endif /* GL_SGIX_texture_coordinate_clamp */

/* ------------------------ GL_SGIX_texture_lod_bias ----------------------- */

#ifdef GL_SGIX_texture_lod_bias

static void _glewInfo_GL_SGIX_texture_lod_bias (void)
{
  glewPrintExt("GL_SGIX_texture_lod_bias", GLEW_SGIX_texture_lod_bias);
}

#endif /* GL_SGIX_texture_lod_bias */

/* ---------------------- GL_SGIX_texture_multi_buffer --------------------- */

#ifdef GL_SGIX_texture_multi_buffer

static void _glewInfo_GL_SGIX_texture_multi_buffer (void)
{
  glewPrintExt("GL_SGIX_texture_multi_buffer", GLEW_SGIX_texture_multi_buffer);
}

#endif /* GL_SGIX_texture_multi_buffer */

/* ------------------------- GL_SGIX_texture_range ------------------------- */

#ifdef GL_SGIX_texture_range

static void _glewInfo_GL_SGIX_texture_range (void)
{
  glewPrintExt("GL_SGIX_texture_range", GLEW_SGIX_texture_range);
}

#endif /* GL_SGIX_texture_range */

/* ----------------------- GL_SGIX_texture_scale_bias ---------------------- */

#ifdef GL_SGIX_texture_scale_bias

static void _glewInfo_GL_SGIX_texture_scale_bias (void)
{
  glewPrintExt("GL_SGIX_texture_scale_bias", GLEW_SGIX_texture_scale_bias);
}

#endif /* GL_SGIX_texture_scale_bias */

/* ------------------------- GL_SGIX_vertex_preclip ------------------------ */

#ifdef GL_SGIX_vertex_preclip

static void _glewInfo_GL_SGIX_vertex_preclip (void)
{
  glewPrintExt("GL_SGIX_vertex_preclip", GLEW_SGIX_vertex_preclip);
}

#endif /* GL_SGIX_vertex_preclip */

/* ---------------------- GL_SGIX_vertex_preclip_hint ---------------------- */

#ifdef GL_SGIX_vertex_preclip_hint

static void _glewInfo_GL_SGIX_vertex_preclip_hint (void)
{
  glewPrintExt("GL_SGIX_vertex_preclip_hint", GLEW_SGIX_vertex_preclip_hint);
}

#endif /* GL_SGIX_vertex_preclip_hint */

/* ----------------------------- GL_SGIX_ycrcb ----------------------------- */

#ifdef GL_SGIX_ycrcb

static void _glewInfo_GL_SGIX_ycrcb (void)
{
  glewPrintExt("GL_SGIX_ycrcb", GLEW_SGIX_ycrcb);
}

#endif /* GL_SGIX_ycrcb */

/* -------------------------- GL_SGI_color_matrix -------------------------- */

#ifdef GL_SGI_color_matrix

static void _glewInfo_GL_SGI_color_matrix (void)
{
  glewPrintExt("GL_SGI_color_matrix", GLEW_SGI_color_matrix);
}

#endif /* GL_SGI_color_matrix */

/* --------------------------- GL_SGI_color_table -------------------------- */

#ifdef GL_SGI_color_table

static void _glewInfo_GL_SGI_color_table (void)
{
  glewPrintExt("GL_SGI_color_table", GLEW_SGI_color_table);

  glewInfoFunc("glColorTableParameterfvSGI", glewColorTableParameterfvSGI == NULL);
  glewInfoFunc("glColorTableParameterivSGI", glewColorTableParameterivSGI == NULL);
  glewInfoFunc("glColorTableSGI", glewColorTableSGI == NULL);
  glewInfoFunc("glCopyColorTableSGI", glewCopyColorTableSGI == NULL);
  glewInfoFunc("glGetColorTableParameterfvSGI", glewGetColorTableParameterfvSGI == NULL);
  glewInfoFunc("glGetColorTableParameterivSGI", glewGetColorTableParameterivSGI == NULL);
  glewInfoFunc("glGetColorTableSGI", glewGetColorTableSGI == NULL);
}

#endif /* GL_SGI_color_table */

/* ----------------------- GL_SGI_texture_color_table ---------------------- */

#ifdef GL_SGI_texture_color_table

static void _glewInfo_GL_SGI_texture_color_table (void)
{
  glewPrintExt("GL_SGI_texture_color_table", GLEW_SGI_texture_color_table);
}

#endif /* GL_SGI_texture_color_table */

/* ------------------------- GL_SUNX_constant_data ------------------------- */

#ifdef GL_SUNX_constant_data

static void _glewInfo_GL_SUNX_constant_data (void)
{
  glewPrintExt("GL_SUNX_constant_data", GLEW_SUNX_constant_data);

  glewInfoFunc("glFinishTextureSUNX", glewFinishTextureSUNX == NULL);
}

#endif /* GL_SUNX_constant_data */

/* -------------------- GL_SUN_convolution_border_modes -------------------- */

#ifdef GL_SUN_convolution_border_modes

static void _glewInfo_GL_SUN_convolution_border_modes (void)
{
  glewPrintExt("GL_SUN_convolution_border_modes", GLEW_SUN_convolution_border_modes);
}

#endif /* GL_SUN_convolution_border_modes */

/* -------------------------- GL_SUN_global_alpha -------------------------- */

#ifdef GL_SUN_global_alpha

static void _glewInfo_GL_SUN_global_alpha (void)
{
  glewPrintExt("GL_SUN_global_alpha", GLEW_SUN_global_alpha);

  glewInfoFunc("glGlobalAlphaFactorbSUN", glewGlobalAlphaFactorbSUN == NULL);
  glewInfoFunc("glGlobalAlphaFactordSUN", glewGlobalAlphaFactordSUN == NULL);
  glewInfoFunc("glGlobalAlphaFactorfSUN", glewGlobalAlphaFactorfSUN == NULL);
  glewInfoFunc("glGlobalAlphaFactoriSUN", glewGlobalAlphaFactoriSUN == NULL);
  glewInfoFunc("glGlobalAlphaFactorsSUN", glewGlobalAlphaFactorsSUN == NULL);
  glewInfoFunc("glGlobalAlphaFactorubSUN", glewGlobalAlphaFactorubSUN == NULL);
  glewInfoFunc("glGlobalAlphaFactoruiSUN", glewGlobalAlphaFactoruiSUN == NULL);
  glewInfoFunc("glGlobalAlphaFactorusSUN", glewGlobalAlphaFactorusSUN == NULL);
}

#endif /* GL_SUN_global_alpha */

/* --------------------------- GL_SUN_mesh_array --------------------------- */

#ifdef GL_SUN_mesh_array

static void _glewInfo_GL_SUN_mesh_array (void)
{
  glewPrintExt("GL_SUN_mesh_array", GLEW_SUN_mesh_array);
}

#endif /* GL_SUN_mesh_array */

/* --------------------------- GL_SUN_slice_accum -------------------------- */

#ifdef GL_SUN_slice_accum

static void _glewInfo_GL_SUN_slice_accum (void)
{
  glewPrintExt("GL_SUN_slice_accum", GLEW_SUN_slice_accum);
}

#endif /* GL_SUN_slice_accum */

/* -------------------------- GL_SUN_triangle_list ------------------------- */

#ifdef GL_SUN_triangle_list

static void _glewInfo_GL_SUN_triangle_list (void)
{
  glewPrintExt("GL_SUN_triangle_list", GLEW_SUN_triangle_list);

  glewInfoFunc("glReplacementCodePointerSUN", glewReplacementCodePointerSUN == NULL);
  glewInfoFunc("glReplacementCodeubSUN", glewReplacementCodeubSUN == NULL);
  glewInfoFunc("glReplacementCodeubvSUN", glewReplacementCodeubvSUN == NULL);
  glewInfoFunc("glReplacementCodeuiSUN", glewReplacementCodeuiSUN == NULL);
  glewInfoFunc("glReplacementCodeuivSUN", glewReplacementCodeuivSUN == NULL);
  glewInfoFunc("glReplacementCodeusSUN", glewReplacementCodeusSUN == NULL);
  glewInfoFunc("glReplacementCodeusvSUN", glewReplacementCodeusvSUN == NULL);
}

#endif /* GL_SUN_triangle_list */

/* ----------------------------- GL_SUN_vertex ----------------------------- */

#ifdef GL_SUN_vertex

static void _glewInfo_GL_SUN_vertex (void)
{
  glewPrintExt("GL_SUN_vertex", GLEW_SUN_vertex);

  glewInfoFunc("glColor3fVertex3fSUN", glewColor3fVertex3fSUN == NULL);
  glewInfoFunc("glColor3fVertex3fvSUN", glewColor3fVertex3fvSUN == NULL);
  glewInfoFunc("glColor4fNormal3fVertex3fSUN", glewColor4fNormal3fVertex3fSUN == NULL);
  glewInfoFunc("glColor4fNormal3fVertex3fvSUN", glewColor4fNormal3fVertex3fvSUN == NULL);
  glewInfoFunc("glColor4ubVertex2fSUN", glewColor4ubVertex2fSUN == NULL);
  glewInfoFunc("glColor4ubVertex2fvSUN", glewColor4ubVertex2fvSUN == NULL);
  glewInfoFunc("glColor4ubVertex3fSUN", glewColor4ubVertex3fSUN == NULL);
  glewInfoFunc("glColor4ubVertex3fvSUN", glewColor4ubVertex3fvSUN == NULL);
  glewInfoFunc("glNormal3fVertex3fSUN", glewNormal3fVertex3fSUN == NULL);
  glewInfoFunc("glNormal3fVertex3fvSUN", glewNormal3fVertex3fvSUN == NULL);
  glewInfoFunc("glReplacementCodeuiColor3fVertex3fSUN", glewReplacementCodeuiColor3fVertex3fSUN == NULL);
  glewInfoFunc("glReplacementCodeuiColor3fVertex3fvSUN", glewReplacementCodeuiColor3fVertex3fvSUN == NULL);
  glewInfoFunc("glReplacementCodeuiColor4fNormal3fVertex3fSUN", glewReplacementCodeuiColor4fNormal3fVertex3fSUN == NULL);
  glewInfoFunc("glReplacementCodeuiColor4fNormal3fVertex3fvSUN", glewReplacementCodeuiColor4fNormal3fVertex3fvSUN == NULL);
  glewInfoFunc("glReplacementCodeuiColor4ubVertex3fSUN", glewReplacementCodeuiColor4ubVertex3fSUN == NULL);
  glewInfoFunc("glReplacementCodeuiColor4ubVertex3fvSUN", glewReplacementCodeuiColor4ubVertex3fvSUN == NULL);
  glewInfoFunc("glReplacementCodeuiNormal3fVertex3fSUN", glewReplacementCodeuiNormal3fVertex3fSUN == NULL);
  glewInfoFunc("glReplacementCodeuiNormal3fVertex3fvSUN", glewReplacementCodeuiNormal3fVertex3fvSUN == NULL);
  glewInfoFunc("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN", glewReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN == NULL);
  glewInfoFunc("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN", glewReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN == NULL);
  glewInfoFunc("glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN", glewReplacementCodeuiTexCoord2fNormal3fVertex3fSUN == NULL);
  glewInfoFunc("glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN", glewReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN == NULL);
  glewInfoFunc("glReplacementCodeuiTexCoord2fVertex3fSUN", glewReplacementCodeuiTexCoord2fVertex3fSUN == NULL);
  glewInfoFunc("glReplacementCodeuiTexCoord2fVertex3fvSUN", glewReplacementCodeuiTexCoord2fVertex3fvSUN == NULL);
  glewInfoFunc("glReplacementCodeuiVertex3fSUN", glewReplacementCodeuiVertex3fSUN == NULL);
  glewInfoFunc("glReplacementCodeuiVertex3fvSUN", glewReplacementCodeuiVertex3fvSUN == NULL);
  glewInfoFunc("glTexCoord2fColor3fVertex3fSUN", glewTexCoord2fColor3fVertex3fSUN == NULL);
  glewInfoFunc("glTexCoord2fColor3fVertex3fvSUN", glewTexCoord2fColor3fVertex3fvSUN == NULL);
  glewInfoFunc("glTexCoord2fColor4fNormal3fVertex3fSUN", glewTexCoord2fColor4fNormal3fVertex3fSUN == NULL);
  glewInfoFunc("glTexCoord2fColor4fNormal3fVertex3fvSUN", glewTexCoord2fColor4fNormal3fVertex3fvSUN == NULL);
  glewInfoFunc("glTexCoord2fColor4ubVertex3fSUN", glewTexCoord2fColor4ubVertex3fSUN == NULL);
  glewInfoFunc("glTexCoord2fColor4ubVertex3fvSUN", glewTexCoord2fColor4ubVertex3fvSUN == NULL);
  glewInfoFunc("glTexCoord2fNormal3fVertex3fSUN", glewTexCoord2fNormal3fVertex3fSUN == NULL);
  glewInfoFunc("glTexCoord2fNormal3fVertex3fvSUN", glewTexCoord2fNormal3fVertex3fvSUN == NULL);
  glewInfoFunc("glTexCoord2fVertex3fSUN", glewTexCoord2fVertex3fSUN == NULL);
  glewInfoFunc("glTexCoord2fVertex3fvSUN", glewTexCoord2fVertex3fvSUN == NULL);
  glewInfoFunc("glTexCoord4fColor4fNormal3fVertex4fSUN", glewTexCoord4fColor4fNormal3fVertex4fSUN == NULL);
  glewInfoFunc("glTexCoord4fColor4fNormal3fVertex4fvSUN", glewTexCoord4fColor4fNormal3fVertex4fvSUN == NULL);
  glewInfoFunc("glTexCoord4fVertex4fSUN", glewTexCoord4fVertex4fSUN == NULL);
  glewInfoFunc("glTexCoord4fVertex4fvSUN", glewTexCoord4fVertex4fvSUN == NULL);
}

#endif /* GL_SUN_vertex */

/* -------------------------- GL_WIN_phong_shading ------------------------- */

#ifdef GL_WIN_phong_shading

static void _glewInfo_GL_WIN_phong_shading (void)
{
  glewPrintExt("GL_WIN_phong_shading", GLEW_WIN_phong_shading);
}

#endif /* GL_WIN_phong_shading */

/* -------------------------- GL_WIN_specular_fog -------------------------- */

#ifdef GL_WIN_specular_fog

static void _glewInfo_GL_WIN_specular_fog (void)
{
  glewPrintExt("GL_WIN_specular_fog", GLEW_WIN_specular_fog);
}

#endif /* GL_WIN_specular_fog */

/* ---------------------------- GL_WIN_swap_hint --------------------------- */

#ifdef GL_WIN_swap_hint

static void _glewInfo_GL_WIN_swap_hint (void)
{
  glewPrintExt("GL_WIN_swap_hint", GLEW_WIN_swap_hint);

  glewInfoFunc("glAddSwapHintRectWin", glewAddSwapHintRectWin == NULL);
}

#endif /* GL_WIN_swap_hint */

#ifdef _WIN32

/* -------------------------- WGL_3DFX_multisample ------------------------- */

#ifdef WGL_3DFX_multisample

static void _glewInfo_WGL_3DFX_multisample (void)
{
  glewPrintExt("WGL_3DFX_multisample", WGLEW_3DFX_multisample);
}

#endif /* WGL_3DFX_multisample */

/* ------------------------- WGL_ARB_buffer_region ------------------------- */

#ifdef WGL_ARB_buffer_region

static void _glewInfo_WGL_ARB_buffer_region (void)
{
  glewPrintExt("WGL_ARB_buffer_region", WGLEW_ARB_buffer_region);

  glewInfoFunc("wglCreateBufferRegionARB", wglewCreateBufferRegionARB == NULL);
  glewInfoFunc("wglDeleteBufferRegionARB", wglewDeleteBufferRegionARB == NULL);
  glewInfoFunc("wglRestoreBufferRegionARB", wglewRestoreBufferRegionARB == NULL);
  glewInfoFunc("wglSaveBufferRegionARB", wglewSaveBufferRegionARB == NULL);
}

#endif /* WGL_ARB_buffer_region */

/* ----------------------- WGL_ARB_extensions_string ----------------------- */

#ifdef WGL_ARB_extensions_string

static void _glewInfo_WGL_ARB_extensions_string (void)
{
  glewPrintExt("WGL_ARB_extensions_string", WGLEW_ARB_extensions_string);

  glewInfoFunc("wglGetExtensionsStringARB", wglewGetExtensionsStringARB == NULL);
}

#endif /* WGL_ARB_extensions_string */

/* ----------------------- WGL_ARB_make_current_read ----------------------- */

#ifdef WGL_ARB_make_current_read

static void _glewInfo_WGL_ARB_make_current_read (void)
{
  glewPrintExt("WGL_ARB_make_current_read", WGLEW_ARB_make_current_read);

  glewInfoFunc("wglGetCurrentReadDCARB", wglewGetCurrentReadDCARB == NULL);
  glewInfoFunc("wglMakeContextCurrentARB", wglewMakeContextCurrentARB == NULL);
}

#endif /* WGL_ARB_make_current_read */

/* -------------------------- WGL_ARB_multisample -------------------------- */

#ifdef WGL_ARB_multisample

static void _glewInfo_WGL_ARB_multisample (void)
{
  glewPrintExt("WGL_ARB_multisample", WGLEW_ARB_multisample);
}

#endif /* WGL_ARB_multisample */

/* ---------------------------- WGL_ARB_pbuffer ---------------------------- */

#ifdef WGL_ARB_pbuffer

static void _glewInfo_WGL_ARB_pbuffer (void)
{
  glewPrintExt("WGL_ARB_pbuffer", WGLEW_ARB_pbuffer);

  glewInfoFunc("wglCreatePbufferARB", wglewCreatePbufferARB == NULL);
  glewInfoFunc("wglDestroyPbufferARB", wglewDestroyPbufferARB == NULL);
  glewInfoFunc("wglGetPbufferDCARB", wglewGetPbufferDCARB == NULL);
  glewInfoFunc("wglQueryPbufferARB", wglewQueryPbufferARB == NULL);
  glewInfoFunc("wglReleasePbufferDCARB", wglewReleasePbufferDCARB == NULL);
}

#endif /* WGL_ARB_pbuffer */

/* -------------------------- WGL_ARB_pixel_format ------------------------- */

#ifdef WGL_ARB_pixel_format

static void _glewInfo_WGL_ARB_pixel_format (void)
{
  glewPrintExt("WGL_ARB_pixel_format", WGLEW_ARB_pixel_format);

  glewInfoFunc("wglChoosePixelFormatARB", wglewChoosePixelFormatARB == NULL);
  glewInfoFunc("wglGetPixelFormatAttribfvARB", wglewGetPixelFormatAttribfvARB == NULL);
  glewInfoFunc("wglGetPixelFormatAttribivARB", wglewGetPixelFormatAttribivARB == NULL);
}

#endif /* WGL_ARB_pixel_format */

/* ------------------------- WGL_ARB_render_texture ------------------------ */

#ifdef WGL_ARB_render_texture

static void _glewInfo_WGL_ARB_render_texture (void)
{
  glewPrintExt("WGL_ARB_render_texture", WGLEW_ARB_render_texture);

  glewInfoFunc("wglBindTexImageARB", wglewBindTexImageARB == NULL);
  glewInfoFunc("wglReleaseTexImageARB", wglewReleaseTexImageARB == NULL);
  glewInfoFunc("wglSetPbufferAttribARB", wglewSetPbufferAttribARB == NULL);
}

#endif /* WGL_ARB_render_texture */

/* ----------------------- WGL_ATI_pixel_format_float ---------------------- */

#ifdef WGL_ATI_pixel_format_float

static void _glewInfo_WGL_ATI_pixel_format_float (void)
{
  glewPrintExt("WGL_ATI_pixel_format_float", WGLEW_ATI_pixel_format_float);
}

#endif /* WGL_ATI_pixel_format_float */

/* -------------------------- WGL_EXT_depth_float -------------------------- */

#ifdef WGL_EXT_depth_float

static void _glewInfo_WGL_EXT_depth_float (void)
{
  glewPrintExt("WGL_EXT_depth_float", WGLEW_EXT_depth_float);
}

#endif /* WGL_EXT_depth_float */

/* ---------------------- WGL_EXT_display_color_table ---------------------- */

#ifdef WGL_EXT_display_color_table

static void _glewInfo_WGL_EXT_display_color_table (void)
{
  glewPrintExt("WGL_EXT_display_color_table", WGLEW_EXT_display_color_table);

  glewInfoFunc("wglBindDisplayColorTableEXT", wglewBindDisplayColorTableEXT == NULL);
  glewInfoFunc("wglCreateDisplayColorTableEXT", wglewCreateDisplayColorTableEXT == NULL);
  glewInfoFunc("wglDestroyDisplayColorTableEXT", wglewDestroyDisplayColorTableEXT == NULL);
  glewInfoFunc("wglLoadDisplayColorTableEXT", wglewLoadDisplayColorTableEXT == NULL);
}

#endif /* WGL_EXT_display_color_table */

/* ----------------------- WGL_EXT_extensions_string ----------------------- */

#ifdef WGL_EXT_extensions_string

static void _glewInfo_WGL_EXT_extensions_string (void)
{
  glewPrintExt("WGL_EXT_extensions_string", WGLEW_EXT_extensions_string);

  glewInfoFunc("wglGetExtensionsStringEXT", wglewGetExtensionsStringEXT == NULL);
}

#endif /* WGL_EXT_extensions_string */

/* ----------------------- WGL_EXT_make_current_read ----------------------- */

#ifdef WGL_EXT_make_current_read

static void _glewInfo_WGL_EXT_make_current_read (void)
{
  glewPrintExt("WGL_EXT_make_current_read", WGLEW_EXT_make_current_read);

  glewInfoFunc("wglGetCurrentReadDCEXT", wglewGetCurrentReadDCEXT == NULL);
  glewInfoFunc("wglMakeContextCurrentEXT", wglewMakeContextCurrentEXT == NULL);
}

#endif /* WGL_EXT_make_current_read */

/* -------------------------- WGL_EXT_multisample -------------------------- */

#ifdef WGL_EXT_multisample

static void _glewInfo_WGL_EXT_multisample (void)
{
  glewPrintExt("WGL_EXT_multisample", WGLEW_EXT_multisample);
}

#endif /* WGL_EXT_multisample */

/* ---------------------------- WGL_EXT_pbuffer ---------------------------- */

#ifdef WGL_EXT_pbuffer

static void _glewInfo_WGL_EXT_pbuffer (void)
{
  glewPrintExt("WGL_EXT_pbuffer", WGLEW_EXT_pbuffer);

  glewInfoFunc("wglCreatePbufferEXT", wglewCreatePbufferEXT == NULL);
  glewInfoFunc("wglDestroyPbufferEXT", wglewDestroyPbufferEXT == NULL);
  glewInfoFunc("wglGetPbufferDCEXT", wglewGetPbufferDCEXT == NULL);
  glewInfoFunc("wglQueryPbufferEXT", wglewQueryPbufferEXT == NULL);
  glewInfoFunc("wglReleasePbufferDCEXT", wglewReleasePbufferDCEXT == NULL);
}

#endif /* WGL_EXT_pbuffer */

/* -------------------------- WGL_EXT_pixel_format ------------------------- */

#ifdef WGL_EXT_pixel_format

static void _glewInfo_WGL_EXT_pixel_format (void)
{
  glewPrintExt("WGL_EXT_pixel_format", WGLEW_EXT_pixel_format);

  glewInfoFunc("wglChoosePixelFormatEXT", wglewChoosePixelFormatEXT == NULL);
  glewInfoFunc("wglGetPixelFormatAttribfvEXT", wglewGetPixelFormatAttribfvEXT == NULL);
  glewInfoFunc("wglGetPixelFormatAttribivEXT", wglewGetPixelFormatAttribivEXT == NULL);
}

#endif /* WGL_EXT_pixel_format */

/* -------------------------- WGL_EXT_swap_control ------------------------- */

#ifdef WGL_EXT_swap_control

static void _glewInfo_WGL_EXT_swap_control (void)
{
  glewPrintExt("WGL_EXT_swap_control", WGLEW_EXT_swap_control);

  glewInfoFunc("wglGetSwapIntervalEXT", wglewGetSwapIntervalEXT == NULL);
  glewInfoFunc("wglSwapIntervalEXT", wglewSwapIntervalEXT == NULL);
}

#endif /* WGL_EXT_swap_control */

/* --------------------- WGL_I3D_digital_video_control --------------------- */

#ifdef WGL_I3D_digital_video_control

static void _glewInfo_WGL_I3D_digital_video_control (void)
{
  glewPrintExt("WGL_I3D_digital_video_control", WGLEW_I3D_digital_video_control);

  glewInfoFunc("wglGetDigitalVideoParametersI3D", wglewGetDigitalVideoParametersI3D == NULL);
  glewInfoFunc("wglSetDigitalVideoParametersI3D", wglewSetDigitalVideoParametersI3D == NULL);
}

#endif /* WGL_I3D_digital_video_control */

/* ----------------------------- WGL_I3D_gamma ----------------------------- */

#ifdef WGL_I3D_gamma

static void _glewInfo_WGL_I3D_gamma (void)
{
  glewPrintExt("WGL_I3D_gamma", WGLEW_I3D_gamma);

  glewInfoFunc("wglGetGammaTableI3D", wglewGetGammaTableI3D == NULL);
  glewInfoFunc("wglGetGammaTableParametersI3D", wglewGetGammaTableParametersI3D == NULL);
  glewInfoFunc("wglSetGammaTableI3D", wglewSetGammaTableI3D == NULL);
  glewInfoFunc("wglSetGammaTableParametersI3D", wglewSetGammaTableParametersI3D == NULL);
}

#endif /* WGL_I3D_gamma */

/* ---------------------------- WGL_I3D_genlock ---------------------------- */

#ifdef WGL_I3D_genlock

static void _glewInfo_WGL_I3D_genlock (void)
{
  glewPrintExt("WGL_I3D_genlock", WGLEW_I3D_genlock);

  glewInfoFunc("wglDisableGenlockI3D", wglewDisableGenlockI3D == NULL);
  glewInfoFunc("wglEnableGenlockI3D", wglewEnableGenlockI3D == NULL);
  glewInfoFunc("wglGenlockSampleRateI3D", wglewGenlockSampleRateI3D == NULL);
  glewInfoFunc("wglGenlockSourceDelayI3D", wglewGenlockSourceDelayI3D == NULL);
  glewInfoFunc("wglGenlockSourceEdgeI3D", wglewGenlockSourceEdgeI3D == NULL);
  glewInfoFunc("wglGenlockSourceI3D", wglewGenlockSourceI3D == NULL);
  glewInfoFunc("wglGetGenlockSampleRateI3D", wglewGetGenlockSampleRateI3D == NULL);
  glewInfoFunc("wglGetGenlockSourceDelayI3D", wglewGetGenlockSourceDelayI3D == NULL);
  glewInfoFunc("wglGetGenlockSourceEdgeI3D", wglewGetGenlockSourceEdgeI3D == NULL);
  glewInfoFunc("wglGetGenlockSourceI3D", wglewGetGenlockSourceI3D == NULL);
  glewInfoFunc("wglIsEnabledGenlockI3D", wglewIsEnabledGenlockI3D == NULL);
  glewInfoFunc("wglQueryGenlockMaxSourceDelayI3D", wglewQueryGenlockMaxSourceDelayI3D == NULL);
}

#endif /* WGL_I3D_genlock */

/* -------------------------- WGL_I3D_image_buffer ------------------------- */

#ifdef WGL_I3D_image_buffer

static void _glewInfo_WGL_I3D_image_buffer (void)
{
  glewPrintExt("WGL_I3D_image_buffer", WGLEW_I3D_image_buffer);

  glewInfoFunc("wglAssociateImageBufferEventsI3D", wglewAssociateImageBufferEventsI3D == NULL);
  glewInfoFunc("wglCreateImageBufferI3D", wglewCreateImageBufferI3D == NULL);
  glewInfoFunc("wglDestroyImageBufferI3D", wglewDestroyImageBufferI3D == NULL);
  glewInfoFunc("wglReleaseImageBufferEventsI3D", wglewReleaseImageBufferEventsI3D == NULL);
}

#endif /* WGL_I3D_image_buffer */

/* ------------------------ WGL_I3D_swap_frame_lock ------------------------ */

#ifdef WGL_I3D_swap_frame_lock

static void _glewInfo_WGL_I3D_swap_frame_lock (void)
{
  glewPrintExt("WGL_I3D_swap_frame_lock", WGLEW_I3D_swap_frame_lock);

  glewInfoFunc("wglDisableFrameLockI3D", wglewDisableFrameLockI3D == NULL);
  glewInfoFunc("wglEnableFrameLockI3D", wglewEnableFrameLockI3D == NULL);
  glewInfoFunc("wglIsEnabledFrameLockI3D", wglewIsEnabledFrameLockI3D == NULL);
  glewInfoFunc("wglQueryFrameLockMasterI3D", wglewQueryFrameLockMasterI3D == NULL);
}

#endif /* WGL_I3D_swap_frame_lock */

/* ------------------------ WGL_I3D_swap_frame_usage ----------------------- */

#ifdef WGL_I3D_swap_frame_usage

static void _glewInfo_WGL_I3D_swap_frame_usage (void)
{
  glewPrintExt("WGL_I3D_swap_frame_usage", WGLEW_I3D_swap_frame_usage);

  glewInfoFunc("wglBeginFrameTrackingI3D", wglewBeginFrameTrackingI3D == NULL);
  glewInfoFunc("wglEndFrameTrackingI3D", wglewEndFrameTrackingI3D == NULL);
  glewInfoFunc("wglGetFrameUsageI3D", wglewGetFrameUsageI3D == NULL);
  glewInfoFunc("wglQueryFrameTrackingI3D", wglewQueryFrameTrackingI3D == NULL);
}

#endif /* WGL_I3D_swap_frame_usage */

/* -------------------------- WGL_NV_float_buffer -------------------------- */

#ifdef WGL_NV_float_buffer

static void _glewInfo_WGL_NV_float_buffer (void)
{
  glewPrintExt("WGL_NV_float_buffer", WGLEW_NV_float_buffer);
}

#endif /* WGL_NV_float_buffer */

/* ---------------------- WGL_NV_render_depth_texture ---------------------- */

#ifdef WGL_NV_render_depth_texture

static void _glewInfo_WGL_NV_render_depth_texture (void)
{
  glewPrintExt("WGL_NV_render_depth_texture", WGLEW_NV_render_depth_texture);
}

#endif /* WGL_NV_render_depth_texture */

/* -------------------- WGL_NV_render_texture_rectangle -------------------- */

#ifdef WGL_NV_render_texture_rectangle

static void _glewInfo_WGL_NV_render_texture_rectangle (void)
{
  glewPrintExt("WGL_NV_render_texture_rectangle", WGLEW_NV_render_texture_rectangle);
}

#endif /* WGL_NV_render_texture_rectangle */

/* ----------------------- WGL_NV_vertex_array_range ----------------------- */

#ifdef WGL_NV_vertex_array_range

static void _glewInfo_WGL_NV_vertex_array_range (void)
{
  glewPrintExt("WGL_NV_vertex_array_range", WGLEW_NV_vertex_array_range);

  glewInfoFunc("wglAllocateMemoryNV", wglewAllocateMemoryNV == NULL);
  glewInfoFunc("wglFreeMemoryNV", wglewFreeMemoryNV == NULL);
}

#endif /* WGL_NV_vertex_array_range */

/* -------------------------- WGL_OML_sync_control ------------------------- */

#ifdef WGL_OML_sync_control

static void _glewInfo_WGL_OML_sync_control (void)
{
  glewPrintExt("WGL_OML_sync_control", WGLEW_OML_sync_control);

  glewInfoFunc("wglGetMscRateOML", wglewGetMscRateOML == NULL);
  glewInfoFunc("wglGetSyncValuesOML", wglewGetSyncValuesOML == NULL);
  glewInfoFunc("wglSwapBuffersMscOML", wglewSwapBuffersMscOML == NULL);
  glewInfoFunc("wglSwapLayerBuffersMscOML", wglewSwapLayerBuffersMscOML == NULL);
  glewInfoFunc("wglWaitForMscOML", wglewWaitForMscOML == NULL);
  glewInfoFunc("wglWaitForSbcOML", wglewWaitForSbcOML == NULL);
}

#endif /* WGL_OML_sync_control */

#else /* _UNIX */

/* ---------------------------- GLX_VERSION_1_2 ---------------------------- */

#ifdef GLX_VERSION_1_2

static void _glewInfo_GLX_VERSION_1_2 (void)
{
  glewPrintExt("GLX_VERSION_1_2", GLXEW_VERSION_1_2);

  glewInfoFunc("glXGetCurrentDisplay", glewXGetCurrentDisplay == NULL);
}

#endif /* GLX_VERSION_1_2 */

/* ---------------------------- GLX_VERSION_1_3 ---------------------------- */

#ifdef GLX_VERSION_1_3

static void _glewInfo_GLX_VERSION_1_3 (void)
{
  glewPrintExt("GLX_VERSION_1_3", GLXEW_VERSION_1_3);

  glewInfoFunc("glXChooseFBConfig", glewXChooseFBConfig == NULL);
  glewInfoFunc("glXCreateNewContext", glewXCreateNewContext == NULL);
  glewInfoFunc("glXCreatePbuffer", glewXCreatePbuffer == NULL);
  glewInfoFunc("glXCreatePixmap", glewXCreatePixmap == NULL);
  glewInfoFunc("glXCreateWindow", glewXCreateWindow == NULL);
  glewInfoFunc("glXDestroyPbuffer", glewXDestroyPbuffer == NULL);
  glewInfoFunc("glXDestroyPixmap", glewXDestroyPixmap == NULL);
  glewInfoFunc("glXDestroyWindow", glewXDestroyWindow == NULL);
  glewInfoFunc("glXGetCurrentReadDrawable", glewXGetCurrentReadDrawable == NULL);
  glewInfoFunc("glXGetFBConfigAttrib", glewXGetFBConfigAttrib == NULL);
  glewInfoFunc("glXGetFBConfigs", glewXGetFBConfigs == NULL);
  glewInfoFunc("glXGetSelectedEvent", glewXGetSelectedEvent == NULL);
  glewInfoFunc("glXGetVisualFromFBConfig", glewXGetVisualFromFBConfig == NULL);
  glewInfoFunc("glXMakeContextCurrent", glewXMakeContextCurrent == NULL);
  glewInfoFunc("glXQueryContext", glewXQueryContext == NULL);
  glewInfoFunc("glXQueryDrawable", glewXQueryDrawable == NULL);
  glewInfoFunc("glXSelectEvent", glewXSelectEvent == NULL);
}

#endif /* GLX_VERSION_1_3 */

/* ---------------------------- GLX_VERSION_1_4 ---------------------------- */

#ifdef GLX_VERSION_1_4

static void _glewInfo_GLX_VERSION_1_4 (void)
{
  glewPrintExt("GLX_VERSION_1_4", GLXEW_VERSION_1_4);
}

#endif /* GLX_VERSION_1_4 */

/* -------------------------- GLX_3DFX_multisample ------------------------- */

#ifdef GLX_3DFX_multisample

static void _glewInfo_GLX_3DFX_multisample (void)
{
  glewPrintExt("GLX_3DFX_multisample", GLXEW_3DFX_multisample);
}

#endif /* GLX_3DFX_multisample */

/* ------------------------ GLX_ARB_get_proc_address ----------------------- */

#ifdef GLX_ARB_get_proc_address

static void _glewInfo_GLX_ARB_get_proc_address (void)
{
  glewPrintExt("GLX_ARB_get_proc_address", GLXEW_ARB_get_proc_address);
}

#endif /* GLX_ARB_get_proc_address */

/* -------------------------- GLX_ARB_multisample -------------------------- */

#ifdef GLX_ARB_multisample

static void _glewInfo_GLX_ARB_multisample (void)
{
  glewPrintExt("GLX_ARB_multisample", GLXEW_ARB_multisample);
}

#endif /* GLX_ARB_multisample */

/* ------------------------- GLX_EXT_import_context ------------------------ */

#ifdef GLX_EXT_import_context

static void _glewInfo_GLX_EXT_import_context (void)
{
  glewPrintExt("GLX_EXT_import_context", GLXEW_EXT_import_context);

  glewInfoFunc("glXFreeContextEXT", glewXFreeContextEXT == NULL);
  glewInfoFunc("glXGetContextIDEXT", glewXGetContextIDEXT == NULL);
  glewInfoFunc("glXImportContextEXT", glewXImportContextEXT == NULL);
  glewInfoFunc("glXQueryContextInfoEXT", glewXQueryContextInfoEXT == NULL);
}

#endif /* GLX_EXT_import_context */

/* -------------------------- GLX_EXT_scene_marker ------------------------- */

#ifdef GLX_EXT_scene_marker

static void _glewInfo_GLX_EXT_scene_marker (void)
{
  glewPrintExt("GLX_EXT_scene_marker", GLXEW_EXT_scene_marker);
}

#endif /* GLX_EXT_scene_marker */

/* -------------------------- GLX_EXT_visual_info -------------------------- */

#ifdef GLX_EXT_visual_info

static void _glewInfo_GLX_EXT_visual_info (void)
{
  glewPrintExt("GLX_EXT_visual_info", GLXEW_EXT_visual_info);
}

#endif /* GLX_EXT_visual_info */

/* ------------------------- GLX_EXT_visual_rating ------------------------- */

#ifdef GLX_EXT_visual_rating

static void _glewInfo_GLX_EXT_visual_rating (void)
{
  glewPrintExt("GLX_EXT_visual_rating", GLXEW_EXT_visual_rating);
}

#endif /* GLX_EXT_visual_rating */

/* ------------------------ GLX_MESA_copy_sub_buffer ----------------------- */

#ifdef GLX_MESA_copy_sub_buffer

static void _glewInfo_GLX_MESA_copy_sub_buffer (void)
{
  glewPrintExt("GLX_MESA_copy_sub_buffer", GLXEW_MESA_copy_sub_buffer);

  glewInfoFunc("glXCopySubBufferMESA", glewXCopySubBufferMESA == NULL);
}

#endif /* GLX_MESA_copy_sub_buffer */

/* ------------------------ GLX_MESA_pixmap_colormap ----------------------- */

#ifdef GLX_MESA_pixmap_colormap

static void _glewInfo_GLX_MESA_pixmap_colormap (void)
{
  glewPrintExt("GLX_MESA_pixmap_colormap", GLXEW_MESA_pixmap_colormap);

  glewInfoFunc("glXCreateGLXPixmapMESA", glewXCreateGLXPixmapMESA == NULL);
}

#endif /* GLX_MESA_pixmap_colormap */

/* ------------------------ GLX_MESA_release_buffers ----------------------- */

#ifdef GLX_MESA_release_buffers

static void _glewInfo_GLX_MESA_release_buffers (void)
{
  glewPrintExt("GLX_MESA_release_buffers", GLXEW_MESA_release_buffers);

  glewInfoFunc("glXReleaseBuffersMESA", glewXReleaseBuffersMESA == NULL);
}

#endif /* GLX_MESA_release_buffers */

/* ------------------------- GLX_MESA_set_3dfx_mode ------------------------ */

#ifdef GLX_MESA_set_3dfx_mode

static void _glewInfo_GLX_MESA_set_3dfx_mode (void)
{
  glewPrintExt("GLX_MESA_set_3dfx_mode", GLXEW_MESA_set_3dfx_mode);

  glewInfoFunc("glXSet3DfxModeMESA", glewXSet3DfxModeMESA == NULL);
}

#endif /* GLX_MESA_set_3dfx_mode */

/* -------------------------- GLX_NV_float_buffer -------------------------- */

#ifdef GLX_NV_float_buffer

static void _glewInfo_GLX_NV_float_buffer (void)
{
  glewPrintExt("GLX_NV_float_buffer", GLXEW_NV_float_buffer);
}

#endif /* GLX_NV_float_buffer */

/* ----------------------- GLX_NV_vertex_array_range ----------------------- */

#ifdef GLX_NV_vertex_array_range

static void _glewInfo_GLX_NV_vertex_array_range (void)
{
  glewPrintExt("GLX_NV_vertex_array_range", GLXEW_NV_vertex_array_range);

  glewInfoFunc("glXAllocateMemoryNV", glewXAllocateMemoryNV == NULL);
  glewInfoFunc("glXFreeMemoryNV", glewXFreeMemoryNV == NULL);
}

#endif /* GLX_NV_vertex_array_range */

/* -------------------------- GLX_OML_swap_method -------------------------- */

#ifdef GLX_OML_swap_method

static void _glewInfo_GLX_OML_swap_method (void)
{
  glewPrintExt("GLX_OML_swap_method", GLXEW_OML_swap_method);
}

#endif /* GLX_OML_swap_method */

/* -------------------------- GLX_OML_sync_control ------------------------- */

#if defined(GLX_OML_sync_control) && defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#include <inttypes.h>

static void _glewInfo_GLX_OML_sync_control (void)
{
  glewPrintExt("GLX_OML_sync_control", GLXEW_OML_sync_control);

  glewInfoFunc("glXGetMscRateOML", glewXGetMscRateOML == NULL);
  glewInfoFunc("glXGetSyncValuesOML", glewXGetSyncValuesOML == NULL);
  glewInfoFunc("glXSwapBuffersMscOML", glewXSwapBuffersMscOML == NULL);
  glewInfoFunc("glXWaitForMscOML", glewXWaitForMscOML == NULL);
  glewInfoFunc("glXWaitForSbcOML", glewXWaitForSbcOML == NULL);
}

#endif /* GLX_OML_sync_control */

/* ------------------------ GLX_SGIS_blended_overlay ----------------------- */

#ifdef GLX_SGIS_blended_overlay

static void _glewInfo_GLX_SGIS_blended_overlay (void)
{
  glewPrintExt("GLX_SGIS_blended_overlay", GLXEW_SGIS_blended_overlay);
}

#endif /* GLX_SGIS_blended_overlay */

/* -------------------------- GLX_SGIS_color_range ------------------------- */

#ifdef GLX_SGIS_color_range

static void _glewInfo_GLX_SGIS_color_range (void)
{
  glewPrintExt("GLX_SGIS_color_range", GLXEW_SGIS_color_range);
}

#endif /* GLX_SGIS_color_range */

/* -------------------------- GLX_SGIS_multisample ------------------------- */

#ifdef GLX_SGIS_multisample

static void _glewInfo_GLX_SGIS_multisample (void)
{
  glewPrintExt("GLX_SGIS_multisample", GLXEW_SGIS_multisample);
}

#endif /* GLX_SGIS_multisample */

/* ---------------------- GLX_SGIS_shared_multisample ---------------------- */

#ifdef GLX_SGIS_shared_multisample

static void _glewInfo_GLX_SGIS_shared_multisample (void)
{
  glewPrintExt("GLX_SGIS_shared_multisample", GLXEW_SGIS_shared_multisample);
}

#endif /* GLX_SGIS_shared_multisample */

/* --------------------------- GLX_SGIX_fbconfig --------------------------- */

#ifdef GLX_SGIX_fbconfig

static void _glewInfo_GLX_SGIX_fbconfig (void)
{
  glewPrintExt("GLX_SGIX_fbconfig", GLXEW_SGIX_fbconfig);

  glewInfoFunc("glXChooseFBConfigSGIX", glewXChooseFBConfigSGIX == NULL);
  glewInfoFunc("glXCreateContextWithConfigSGIX", glewXCreateContextWithConfigSGIX == NULL);
  glewInfoFunc("glXCreateGLXPixmapWithConfigSGIX", glewXCreateGLXPixmapWithConfigSGIX == NULL);
  glewInfoFunc("glXGetFBConfigAttribSGIX", glewXGetFBConfigAttribSGIX == NULL);
  glewInfoFunc("glXGetFBConfigFromVisualSGIX", glewXGetFBConfigFromVisualSGIX == NULL);
  glewInfoFunc("glXGetVisualFromFBConfigSGIX", glewXGetVisualFromFBConfigSGIX == NULL);
}

#endif /* GLX_SGIX_fbconfig */

/* ---------------------------- GLX_SGIX_pbuffer --------------------------- */

#ifdef GLX_SGIX_pbuffer

static void _glewInfo_GLX_SGIX_pbuffer (void)
{
  glewPrintExt("GLX_SGIX_pbuffer", GLXEW_SGIX_pbuffer);

  glewInfoFunc("glXCreateGLXPbufferSGIX", glewXCreateGLXPbufferSGIX == NULL);
  glewInfoFunc("glXDestroyGLXPbufferSGIX", glewXDestroyGLXPbufferSGIX == NULL);
  glewInfoFunc("glXGetSelectedEventSGIX", glewXGetSelectedEventSGIX == NULL);
  glewInfoFunc("glXQueryGLXPbufferSGIX", glewXQueryGLXPbufferSGIX == NULL);
  glewInfoFunc("glXSelectEventSGIX", glewXSelectEventSGIX == NULL);
}

#endif /* GLX_SGIX_pbuffer */

/* ------------------------- GLX_SGIX_swap_barrier ------------------------- */

#ifdef GLX_SGIX_swap_barrier

static void _glewInfo_GLX_SGIX_swap_barrier (void)
{
  glewPrintExt("GLX_SGIX_swap_barrier", GLXEW_SGIX_swap_barrier);

  glewInfoFunc("glXBindSwapBarrierSGIX", glewXBindSwapBarrierSGIX == NULL);
  glewInfoFunc("glXQueryMaxSwapBarriersSGIX", glewXQueryMaxSwapBarriersSGIX == NULL);
}

#endif /* GLX_SGIX_swap_barrier */

/* -------------------------- GLX_SGIX_swap_group -------------------------- */

#ifdef GLX_SGIX_swap_group

static void _glewInfo_GLX_SGIX_swap_group (void)
{
  glewPrintExt("GLX_SGIX_swap_group", GLXEW_SGIX_swap_group);

  glewInfoFunc("glXJoinSwapGroupSGIX", glewXJoinSwapGroupSGIX == NULL);
}

#endif /* GLX_SGIX_swap_group */

/* ------------------------- GLX_SGIX_video_resize ------------------------- */

#ifdef GLX_SGIX_video_resize

static void _glewInfo_GLX_SGIX_video_resize (void)
{
  glewPrintExt("GLX_SGIX_video_resize", GLXEW_SGIX_video_resize);

  glewInfoFunc("glXBindChannelToWindowSGIX", glewXBindChannelToWindowSGIX == NULL);
  glewInfoFunc("glXChannelRectSGIX", glewXChannelRectSGIX == NULL);
  glewInfoFunc("glXChannelRectSyncSGIX", glewXChannelRectSyncSGIX == NULL);
  glewInfoFunc("glXQueryChannelDeltasSGIX", glewXQueryChannelDeltasSGIX == NULL);
  glewInfoFunc("glXQueryChannelRectSGIX", glewXQueryChannelRectSGIX == NULL);
}

#endif /* GLX_SGIX_video_resize */

/* ---------------------- GLX_SGIX_visual_select_group --------------------- */

#ifdef GLX_SGIX_visual_select_group

static void _glewInfo_GLX_SGIX_visual_select_group (void)
{
  glewPrintExt("GLX_SGIX_visual_select_group", GLXEW_SGIX_visual_select_group);
}

#endif /* GLX_SGIX_visual_select_group */

/* ---------------------------- GLX_SGI_cushion ---------------------------- */

#ifdef GLX_SGI_cushion

static void _glewInfo_GLX_SGI_cushion (void)
{
  glewPrintExt("GLX_SGI_cushion", GLXEW_SGI_cushion);

  glewInfoFunc("glXCushionSGI", glewXCushionSGI == NULL);
}

#endif /* GLX_SGI_cushion */

/* ----------------------- GLX_SGI_make_current_read ----------------------- */

#ifdef GLX_SGI_make_current_read

static void _glewInfo_GLX_SGI_make_current_read (void)
{
  glewPrintExt("GLX_SGI_make_current_read", GLXEW_SGI_make_current_read);

  glewInfoFunc("glXGetCurrentReadDrawableSGI", glewXGetCurrentReadDrawableSGI == NULL);
  glewInfoFunc("glXMakeCurrentReadSGI", glewXMakeCurrentReadSGI == NULL);
}

#endif /* GLX_SGI_make_current_read */

/* -------------------------- GLX_SGI_swap_control ------------------------- */

#ifdef GLX_SGI_swap_control

static void _glewInfo_GLX_SGI_swap_control (void)
{
  glewPrintExt("GLX_SGI_swap_control", GLXEW_SGI_swap_control);

  glewInfoFunc("glXSwapIntervalSGI", glewXSwapIntervalSGI == NULL);
}

#endif /* GLX_SGI_swap_control */

/* --------------------------- GLX_SGI_video_sync -------------------------- */

#ifdef GLX_SGI_video_sync

static void _glewInfo_GLX_SGI_video_sync (void)
{
  glewPrintExt("GLX_SGI_video_sync", GLXEW_SGI_video_sync);

  glewInfoFunc("glXGetVideoSyncSGI", glewXGetVideoSyncSGI == NULL);
  glewInfoFunc("glXWaitVideoSyncSGI", glewXWaitVideoSyncSGI == NULL);
}

#endif /* GLX_SGI_video_sync */

/* --------------------- GLX_SUN_get_transparent_index --------------------- */

#ifdef GLX_SUN_get_transparent_index

static void _glewInfo_GLX_SUN_get_transparent_index (void)
{
  glewPrintExt("GLX_SUN_get_transparent_index", GLXEW_SUN_get_transparent_index);

  glewInfoFunc("glXGetTransparentIndexSUN", glewXGetTransparentIndexSUN == NULL);
}

#endif /* GLX_SUN_get_transparent_index */

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

static void glewInfo (void)
{
#ifdef GL_VERSION_1_1
  _glewInfo_GL_VERSION_1_1();
#endif /* GL_VERSION_1_1 */
#ifdef GL_VERSION_1_2
  _glewInfo_GL_VERSION_1_2();
#endif /* GL_VERSION_1_2 */
#ifdef GL_VERSION_1_3
  _glewInfo_GL_VERSION_1_3();
#endif /* GL_VERSION_1_3 */
#ifdef GL_VERSION_1_4
  _glewInfo_GL_VERSION_1_4();
#endif /* GL_VERSION_1_4 */
#ifdef GL_3DFX_multisample
  _glewInfo_GL_3DFX_multisample();
#endif /* GL_3DFX_multisample */
#ifdef GL_3DFX_tbuffer
  _glewInfo_GL_3DFX_tbuffer();
#endif /* GL_3DFX_tbuffer */
#ifdef GL_3DFX_texture_compression_FXT1
  _glewInfo_GL_3DFX_texture_compression_FXT1();
#endif /* GL_3DFX_texture_compression_FXT1 */
#ifdef GL_APPLE_client_storage
  _glewInfo_GL_APPLE_client_storage();
#endif /* GL_APPLE_client_storage */
#ifdef GL_APPLE_element_array
  _glewInfo_GL_APPLE_element_array();
#endif /* GL_APPLE_element_array */
#ifdef GL_APPLE_fence
  _glewInfo_GL_APPLE_fence();
#endif /* GL_APPLE_fence */
#ifdef GL_APPLE_specular_vector
  _glewInfo_GL_APPLE_specular_vector();
#endif /* GL_APPLE_specular_vector */
#ifdef GL_APPLE_transform_hint
  _glewInfo_GL_APPLE_transform_hint();
#endif /* GL_APPLE_transform_hint */
#ifdef GL_APPLE_vertex_array_object
  _glewInfo_GL_APPLE_vertex_array_object();
#endif /* GL_APPLE_vertex_array_object */
#ifdef GL_APPLE_vertex_array_range
  _glewInfo_GL_APPLE_vertex_array_range();
#endif /* GL_APPLE_vertex_array_range */
#ifdef GL_APPLE_ycbcr_422
  _glewInfo_GL_APPLE_ycbcr_422();
#endif /* GL_APPLE_ycbcr_422 */
#ifdef GL_ARB_depth_texture
  _glewInfo_GL_ARB_depth_texture();
#endif /* GL_ARB_depth_texture */
#ifdef GL_ARB_fragment_program
  _glewInfo_GL_ARB_fragment_program();
#endif /* GL_ARB_fragment_program */
#ifdef GL_ARB_imaging
  _glewInfo_GL_ARB_imaging();
#endif /* GL_ARB_imaging */
#ifdef GL_ARB_matrix_palette
  _glewInfo_GL_ARB_matrix_palette();
#endif /* GL_ARB_matrix_palette */
#ifdef GL_ARB_multisample
  _glewInfo_GL_ARB_multisample();
#endif /* GL_ARB_multisample */
#ifdef GL_ARB_multitexture
  _glewInfo_GL_ARB_multitexture();
#endif /* GL_ARB_multitexture */
#ifdef GL_ARB_occlusion_query
  _glewInfo_GL_ARB_occlusion_query();
#endif /* GL_ARB_occlusion_query */
#ifdef GL_ARB_point_parameters
  _glewInfo_GL_ARB_point_parameters();
#endif /* GL_ARB_point_parameters */
#ifdef GL_ARB_point_sprite
  _glewInfo_GL_ARB_point_sprite();
#endif /* GL_ARB_point_sprite */
#ifdef GL_ARB_shading_language_100
  _glewInfo_GL_ARB_shading_language_100();
#endif /* GL_ARB_shading_language_100 */
#ifdef GL_ARB_shadow
  _glewInfo_GL_ARB_shadow();
#endif /* GL_ARB_shadow */
#ifdef GL_ARB_shadow_ambient
  _glewInfo_GL_ARB_shadow_ambient();
#endif /* GL_ARB_shadow_ambient */
#ifdef GL_ARB_texture_border_clamp
  _glewInfo_GL_ARB_texture_border_clamp();
#endif /* GL_ARB_texture_border_clamp */
#ifdef GL_ARB_texture_compression
  _glewInfo_GL_ARB_texture_compression();
#endif /* GL_ARB_texture_compression */
#ifdef GL_ARB_texture_cube_map
  _glewInfo_GL_ARB_texture_cube_map();
#endif /* GL_ARB_texture_cube_map */
#ifdef GL_ARB_texture_env_add
  _glewInfo_GL_ARB_texture_env_add();
#endif /* GL_ARB_texture_env_add */
#ifdef GL_ARB_texture_env_combine
  _glewInfo_GL_ARB_texture_env_combine();
#endif /* GL_ARB_texture_env_combine */
#ifdef GL_ARB_texture_env_crossbar
  _glewInfo_GL_ARB_texture_env_crossbar();
#endif /* GL_ARB_texture_env_crossbar */
#ifdef GL_ARB_texture_env_dot3
  _glewInfo_GL_ARB_texture_env_dot3();
#endif /* GL_ARB_texture_env_dot3 */
#ifdef GL_ARB_texture_mirrored_repeat
  _glewInfo_GL_ARB_texture_mirrored_repeat();
#endif /* GL_ARB_texture_mirrored_repeat */
#ifdef GL_ARB_texture_non_power_of_two
  _glewInfo_GL_ARB_texture_non_power_of_two();
#endif /* GL_ARB_texture_non_power_of_two */
#ifdef GL_ARB_transpose_matrix
  _glewInfo_GL_ARB_transpose_matrix();
#endif /* GL_ARB_transpose_matrix */
#ifdef GL_ARB_vertex_blend
  _glewInfo_GL_ARB_vertex_blend();
#endif /* GL_ARB_vertex_blend */
#ifdef GL_ARB_vertex_buffer_object
  _glewInfo_GL_ARB_vertex_buffer_object();
#endif /* GL_ARB_vertex_buffer_object */
#ifdef GL_ARB_vertex_program
  _glewInfo_GL_ARB_vertex_program();
#endif /* GL_ARB_vertex_program */
#ifdef GL_ARB_window_pos
  _glewInfo_GL_ARB_window_pos();
#endif /* GL_ARB_window_pos */
#ifdef GL_ATIX_point_sprites
  _glewInfo_GL_ATIX_point_sprites();
#endif /* GL_ATIX_point_sprites */
#ifdef GL_ATIX_texture_env_combine3
  _glewInfo_GL_ATIX_texture_env_combine3();
#endif /* GL_ATIX_texture_env_combine3 */
#ifdef GL_ATIX_texture_env_route
  _glewInfo_GL_ATIX_texture_env_route();
#endif /* GL_ATIX_texture_env_route */
#ifdef GL_ATIX_vertex_shader_output_point_size
  _glewInfo_GL_ATIX_vertex_shader_output_point_size();
#endif /* GL_ATIX_vertex_shader_output_point_size */
#ifdef GL_ATI_draw_buffers
  _glewInfo_GL_ATI_draw_buffers();
#endif /* GL_ATI_draw_buffers */
#ifdef GL_ATI_element_array
  _glewInfo_GL_ATI_element_array();
#endif /* GL_ATI_element_array */
#ifdef GL_ATI_envmap_bumpmap
  _glewInfo_GL_ATI_envmap_bumpmap();
#endif /* GL_ATI_envmap_bumpmap */
#ifdef GL_ATI_fragment_shader
  _glewInfo_GL_ATI_fragment_shader();
#endif /* GL_ATI_fragment_shader */
#ifdef GL_ATI_map_object_buffer
  _glewInfo_GL_ATI_map_object_buffer();
#endif /* GL_ATI_map_object_buffer */
#ifdef GL_ATI_pn_triangles
  _glewInfo_GL_ATI_pn_triangles();
#endif /* GL_ATI_pn_triangles */
#ifdef GL_ATI_separate_stencil
  _glewInfo_GL_ATI_separate_stencil();
#endif /* GL_ATI_separate_stencil */
#ifdef GL_ATI_text_fragment_shader
  _glewInfo_GL_ATI_text_fragment_shader();
#endif /* GL_ATI_text_fragment_shader */
#ifdef GL_ATI_texture_env_combine3
  _glewInfo_GL_ATI_texture_env_combine3();
#endif /* GL_ATI_texture_env_combine3 */
#ifdef GL_ATI_texture_float
  _glewInfo_GL_ATI_texture_float();
#endif /* GL_ATI_texture_float */
#ifdef GL_ATI_texture_mirror_once
  _glewInfo_GL_ATI_texture_mirror_once();
#endif /* GL_ATI_texture_mirror_once */
#ifdef GL_ATI_vertex_array_object
  _glewInfo_GL_ATI_vertex_array_object();
#endif /* GL_ATI_vertex_array_object */
#ifdef GL_ATI_vertex_attrib_array_object
  _glewInfo_GL_ATI_vertex_attrib_array_object();
#endif /* GL_ATI_vertex_attrib_array_object */
#ifdef GL_ATI_vertex_streams
  _glewInfo_GL_ATI_vertex_streams();
#endif /* GL_ATI_vertex_streams */
#ifdef GL_EXT_422_pixels
  _glewInfo_GL_EXT_422_pixels();
#endif /* GL_EXT_422_pixels */
#ifdef GL_EXT_abgr
  _glewInfo_GL_EXT_abgr();
#endif /* GL_EXT_abgr */
#ifdef GL_EXT_bgra
  _glewInfo_GL_EXT_bgra();
#endif /* GL_EXT_bgra */
#ifdef GL_EXT_blend_color
  _glewInfo_GL_EXT_blend_color();
#endif /* GL_EXT_blend_color */
#ifdef GL_EXT_blend_func_separate
  _glewInfo_GL_EXT_blend_func_separate();
#endif /* GL_EXT_blend_func_separate */
#ifdef GL_EXT_blend_logic_op
  _glewInfo_GL_EXT_blend_logic_op();
#endif /* GL_EXT_blend_logic_op */
#ifdef GL_EXT_blend_minmax
  _glewInfo_GL_EXT_blend_minmax();
#endif /* GL_EXT_blend_minmax */
#ifdef GL_EXT_blend_subtract
  _glewInfo_GL_EXT_blend_subtract();
#endif /* GL_EXT_blend_subtract */
#ifdef GL_EXT_clip_volume_hint
  _glewInfo_GL_EXT_clip_volume_hint();
#endif /* GL_EXT_clip_volume_hint */
#ifdef GL_EXT_cmyka
  _glewInfo_GL_EXT_cmyka();
#endif /* GL_EXT_cmyka */
#ifdef GL_EXT_color_subtable
  _glewInfo_GL_EXT_color_subtable();
#endif /* GL_EXT_color_subtable */
#ifdef GL_EXT_compiled_vertex_array
  _glewInfo_GL_EXT_compiled_vertex_array();
#endif /* GL_EXT_compiled_vertex_array */
#ifdef GL_EXT_convolution
  _glewInfo_GL_EXT_convolution();
#endif /* GL_EXT_convolution */
#ifdef GL_EXT_coordinate_frame
  _glewInfo_GL_EXT_coordinate_frame();
#endif /* GL_EXT_coordinate_frame */
#ifdef GL_EXT_copy_texture
  _glewInfo_GL_EXT_copy_texture();
#endif /* GL_EXT_copy_texture */
#ifdef GL_EXT_cull_vertex
  _glewInfo_GL_EXT_cull_vertex();
#endif /* GL_EXT_cull_vertex */
#ifdef GL_EXT_depth_bounds_test
  _glewInfo_GL_EXT_depth_bounds_test();
#endif /* GL_EXT_depth_bounds_test */
#ifdef GL_EXT_draw_range_elements
  _glewInfo_GL_EXT_draw_range_elements();
#endif /* GL_EXT_draw_range_elements */
#ifdef GL_EXT_fog_coord
  _glewInfo_GL_EXT_fog_coord();
#endif /* GL_EXT_fog_coord */
#ifdef GL_EXT_fragment_lighting
  _glewInfo_GL_EXT_fragment_lighting();
#endif /* GL_EXT_fragment_lighting */
#ifdef GL_EXT_histogram
  _glewInfo_GL_EXT_histogram();
#endif /* GL_EXT_histogram */
#ifdef GL_EXT_index_array_formats
  _glewInfo_GL_EXT_index_array_formats();
#endif /* GL_EXT_index_array_formats */
#ifdef GL_EXT_index_func
  _glewInfo_GL_EXT_index_func();
#endif /* GL_EXT_index_func */
#ifdef GL_EXT_index_material
  _glewInfo_GL_EXT_index_material();
#endif /* GL_EXT_index_material */
#ifdef GL_EXT_index_texture
  _glewInfo_GL_EXT_index_texture();
#endif /* GL_EXT_index_texture */
#ifdef GL_EXT_light_texture
  _glewInfo_GL_EXT_light_texture();
#endif /* GL_EXT_light_texture */
#ifdef GL_EXT_misc_attribute
  _glewInfo_GL_EXT_misc_attribute();
#endif /* GL_EXT_misc_attribute */
#ifdef GL_EXT_multi_draw_arrays
  _glewInfo_GL_EXT_multi_draw_arrays();
#endif /* GL_EXT_multi_draw_arrays */
#ifdef GL_EXT_multisample
  _glewInfo_GL_EXT_multisample();
#endif /* GL_EXT_multisample */
#ifdef GL_EXT_packed_pixels
  _glewInfo_GL_EXT_packed_pixels();
#endif /* GL_EXT_packed_pixels */
#ifdef GL_EXT_paletted_texture
  _glewInfo_GL_EXT_paletted_texture();
#endif /* GL_EXT_paletted_texture */
#ifdef GL_EXT_pixel_transform
  _glewInfo_GL_EXT_pixel_transform();
#endif /* GL_EXT_pixel_transform */
#ifdef GL_EXT_pixel_transform_color_table
  _glewInfo_GL_EXT_pixel_transform_color_table();
#endif /* GL_EXT_pixel_transform_color_table */
#ifdef GL_EXT_point_parameters
  _glewInfo_GL_EXT_point_parameters();
#endif /* GL_EXT_point_parameters */
#ifdef GL_EXT_polygon_offset
  _glewInfo_GL_EXT_polygon_offset();
#endif /* GL_EXT_polygon_offset */
#ifdef GL_EXT_rescale_normal
  _glewInfo_GL_EXT_rescale_normal();
#endif /* GL_EXT_rescale_normal */
#ifdef GL_EXT_scene_marker
  _glewInfo_GL_EXT_scene_marker();
#endif /* GL_EXT_scene_marker */
#ifdef GL_EXT_secondary_color
  _glewInfo_GL_EXT_secondary_color();
#endif /* GL_EXT_secondary_color */
#ifdef GL_EXT_separate_specular_color
  _glewInfo_GL_EXT_separate_specular_color();
#endif /* GL_EXT_separate_specular_color */
#ifdef GL_EXT_shadow_funcs
  _glewInfo_GL_EXT_shadow_funcs();
#endif /* GL_EXT_shadow_funcs */
#ifdef GL_EXT_shared_texture_palette
  _glewInfo_GL_EXT_shared_texture_palette();
#endif /* GL_EXT_shared_texture_palette */
#ifdef GL_EXT_stencil_two_side
  _glewInfo_GL_EXT_stencil_two_side();
#endif /* GL_EXT_stencil_two_side */
#ifdef GL_EXT_stencil_wrap
  _glewInfo_GL_EXT_stencil_wrap();
#endif /* GL_EXT_stencil_wrap */
#ifdef GL_EXT_subtexture
  _glewInfo_GL_EXT_subtexture();
#endif /* GL_EXT_subtexture */
#ifdef GL_EXT_texture
  _glewInfo_GL_EXT_texture();
#endif /* GL_EXT_texture */
#ifdef GL_EXT_texture3D
  _glewInfo_GL_EXT_texture3D();
#endif /* GL_EXT_texture3D */
#ifdef GL_EXT_texture_compression_s3tc
  _glewInfo_GL_EXT_texture_compression_s3tc();
#endif /* GL_EXT_texture_compression_s3tc */
#ifdef GL_EXT_texture_env
  _glewInfo_GL_EXT_texture_env();
#endif /* GL_EXT_texture_env */
#ifdef GL_EXT_texture_env_add
  _glewInfo_GL_EXT_texture_env_add();
#endif /* GL_EXT_texture_env_add */
#ifdef GL_EXT_texture_env_combine
  _glewInfo_GL_EXT_texture_env_combine();
#endif /* GL_EXT_texture_env_combine */
#ifdef GL_EXT_texture_env_dot3
  _glewInfo_GL_EXT_texture_env_dot3();
#endif /* GL_EXT_texture_env_dot3 */
#ifdef GL_EXT_texture_filter_anisotropic
  _glewInfo_GL_EXT_texture_filter_anisotropic();
#endif /* GL_EXT_texture_filter_anisotropic */
#ifdef GL_EXT_texture_lod_bias
  _glewInfo_GL_EXT_texture_lod_bias();
#endif /* GL_EXT_texture_lod_bias */
#ifdef GL_EXT_texture_mirror_clamp
  _glewInfo_GL_EXT_texture_mirror_clamp();
#endif /* GL_EXT_texture_mirror_clamp */
#ifdef GL_EXT_texture_object
  _glewInfo_GL_EXT_texture_object();
#endif /* GL_EXT_texture_object */
#ifdef GL_EXT_texture_perturb_normal
  _glewInfo_GL_EXT_texture_perturb_normal();
#endif /* GL_EXT_texture_perturb_normal */
#ifdef GL_EXT_texture_rectangle
  _glewInfo_GL_EXT_texture_rectangle();
#endif /* GL_EXT_texture_rectangle */
#ifdef GL_EXT_vertex_array
  _glewInfo_GL_EXT_vertex_array();
#endif /* GL_EXT_vertex_array */
#ifdef GL_EXT_vertex_shader
  _glewInfo_GL_EXT_vertex_shader();
#endif /* GL_EXT_vertex_shader */
#ifdef GL_EXT_vertex_weighting
  _glewInfo_GL_EXT_vertex_weighting();
#endif /* GL_EXT_vertex_weighting */
#ifdef GL_HP_convolution_border_modes
  _glewInfo_GL_HP_convolution_border_modes();
#endif /* GL_HP_convolution_border_modes */
#ifdef GL_HP_image_transform
  _glewInfo_GL_HP_image_transform();
#endif /* GL_HP_image_transform */
#ifdef GL_HP_occlusion_test
  _glewInfo_GL_HP_occlusion_test();
#endif /* GL_HP_occlusion_test */
#ifdef GL_HP_texture_lighting
  _glewInfo_GL_HP_texture_lighting();
#endif /* GL_HP_texture_lighting */
#ifdef GL_IBM_cull_vertex
  _glewInfo_GL_IBM_cull_vertex();
#endif /* GL_IBM_cull_vertex */
#ifdef GL_IBM_multimode_draw_arrays
  _glewInfo_GL_IBM_multimode_draw_arrays();
#endif /* GL_IBM_multimode_draw_arrays */
#ifdef GL_IBM_rasterpos_clip
  _glewInfo_GL_IBM_rasterpos_clip();
#endif /* GL_IBM_rasterpos_clip */
#ifdef GL_IBM_static_data
  _glewInfo_GL_IBM_static_data();
#endif /* GL_IBM_static_data */
#ifdef GL_IBM_texture_mirrored_repeat
  _glewInfo_GL_IBM_texture_mirrored_repeat();
#endif /* GL_IBM_texture_mirrored_repeat */
#ifdef GL_IBM_vertex_array_lists
  _glewInfo_GL_IBM_vertex_array_lists();
#endif /* GL_IBM_vertex_array_lists */
#ifdef GL_INGR_color_clamp
  _glewInfo_GL_INGR_color_clamp();
#endif /* GL_INGR_color_clamp */
#ifdef GL_INGR_interlace_read
  _glewInfo_GL_INGR_interlace_read();
#endif /* GL_INGR_interlace_read */
#ifdef GL_INTEL_parallel_arrays
  _glewInfo_GL_INTEL_parallel_arrays();
#endif /* GL_INTEL_parallel_arrays */
#ifdef GL_INTEL_texture_scissor
  _glewInfo_GL_INTEL_texture_scissor();
#endif /* GL_INTEL_texture_scissor */
#ifdef GL_MESA_resize_buffers
  _glewInfo_GL_MESA_resize_buffers();
#endif /* GL_MESA_resize_buffers */
#ifdef GL_MESA_window_pos
  _glewInfo_GL_MESA_window_pos();
#endif /* GL_MESA_window_pos */
#ifdef GL_NV_blend_square
  _glewInfo_GL_NV_blend_square();
#endif /* GL_NV_blend_square */
#ifdef GL_NV_copy_depth_to_color
  _glewInfo_GL_NV_copy_depth_to_color();
#endif /* GL_NV_copy_depth_to_color */
#ifdef GL_NV_depth_clamp
  _glewInfo_GL_NV_depth_clamp();
#endif /* GL_NV_depth_clamp */
#ifdef GL_NV_element_array
  _glewInfo_GL_NV_element_array();
#endif /* GL_NV_element_array */
#ifdef GL_NV_evaluators
  _glewInfo_GL_NV_evaluators();
#endif /* GL_NV_evaluators */
#ifdef GL_NV_fence
  _glewInfo_GL_NV_fence();
#endif /* GL_NV_fence */
#ifdef GL_NV_float_buffer
  _glewInfo_GL_NV_float_buffer();
#endif /* GL_NV_float_buffer */
#ifdef GL_NV_fog_distance
  _glewInfo_GL_NV_fog_distance();
#endif /* GL_NV_fog_distance */
#ifdef GL_NV_fragment_program
  _glewInfo_GL_NV_fragment_program();
#endif /* GL_NV_fragment_program */
#ifdef GL_NV_half_float
  _glewInfo_GL_NV_half_float();
#endif /* GL_NV_half_float */
#ifdef GL_NV_light_max_exponent
  _glewInfo_GL_NV_light_max_exponent();
#endif /* GL_NV_light_max_exponent */
#ifdef GL_NV_multisample_filter_hint
  _glewInfo_GL_NV_multisample_filter_hint();
#endif /* GL_NV_multisample_filter_hint */
#ifdef GL_NV_occlusion_query
  _glewInfo_GL_NV_occlusion_query();
#endif /* GL_NV_occlusion_query */
#ifdef GL_NV_packed_depth_stencil
  _glewInfo_GL_NV_packed_depth_stencil();
#endif /* GL_NV_packed_depth_stencil */
#ifdef GL_NV_pixel_data_range
  _glewInfo_GL_NV_pixel_data_range();
#endif /* GL_NV_pixel_data_range */
#ifdef GL_NV_point_sprite
  _glewInfo_GL_NV_point_sprite();
#endif /* GL_NV_point_sprite */
#ifdef GL_NV_primitive_restart
  _glewInfo_GL_NV_primitive_restart();
#endif /* GL_NV_primitive_restart */
#ifdef GL_NV_register_combiners
  _glewInfo_GL_NV_register_combiners();
#endif /* GL_NV_register_combiners */
#ifdef GL_NV_register_combiners2
  _glewInfo_GL_NV_register_combiners2();
#endif /* GL_NV_register_combiners2 */
#ifdef GL_NV_texgen_emboss
  _glewInfo_GL_NV_texgen_emboss();
#endif /* GL_NV_texgen_emboss */
#ifdef GL_NV_texgen_reflection
  _glewInfo_GL_NV_texgen_reflection();
#endif /* GL_NV_texgen_reflection */
#ifdef GL_NV_texture_compression_vtc
  _glewInfo_GL_NV_texture_compression_vtc();
#endif /* GL_NV_texture_compression_vtc */
#ifdef GL_NV_texture_env_combine4
  _glewInfo_GL_NV_texture_env_combine4();
#endif /* GL_NV_texture_env_combine4 */
#ifdef GL_NV_texture_expand_normal
  _glewInfo_GL_NV_texture_expand_normal();
#endif /* GL_NV_texture_expand_normal */
#ifdef GL_NV_texture_rectangle
  _glewInfo_GL_NV_texture_rectangle();
#endif /* GL_NV_texture_rectangle */
#ifdef GL_NV_texture_shader
  _glewInfo_GL_NV_texture_shader();
#endif /* GL_NV_texture_shader */
#ifdef GL_NV_texture_shader2
  _glewInfo_GL_NV_texture_shader2();
#endif /* GL_NV_texture_shader2 */
#ifdef GL_NV_texture_shader3
  _glewInfo_GL_NV_texture_shader3();
#endif /* GL_NV_texture_shader3 */
#ifdef GL_NV_vertex_array_range
  _glewInfo_GL_NV_vertex_array_range();
#endif /* GL_NV_vertex_array_range */
#ifdef GL_NV_vertex_array_range2
  _glewInfo_GL_NV_vertex_array_range2();
#endif /* GL_NV_vertex_array_range2 */
#ifdef GL_NV_vertex_program
  _glewInfo_GL_NV_vertex_program();
#endif /* GL_NV_vertex_program */
#ifdef GL_NV_vertex_program1_1
  _glewInfo_GL_NV_vertex_program1_1();
#endif /* GL_NV_vertex_program1_1 */
#ifdef GL_NV_vertex_program2
  _glewInfo_GL_NV_vertex_program2();
#endif /* GL_NV_vertex_program2 */
#ifdef GL_OML_interlace
  _glewInfo_GL_OML_interlace();
#endif /* GL_OML_interlace */
#ifdef GL_OML_resample
  _glewInfo_GL_OML_resample();
#endif /* GL_OML_resample */
#ifdef GL_OML_subsample
  _glewInfo_GL_OML_subsample();
#endif /* GL_OML_subsample */
#ifdef GL_PGI_misc_hints
  _glewInfo_GL_PGI_misc_hints();
#endif /* GL_PGI_misc_hints */
#ifdef GL_PGI_vertex_hints
  _glewInfo_GL_PGI_vertex_hints();
#endif /* GL_PGI_vertex_hints */
#ifdef GL_REND_screen_coordinates
  _glewInfo_GL_REND_screen_coordinates();
#endif /* GL_REND_screen_coordinates */
#ifdef GL_S3_s3tc
  _glewInfo_GL_S3_s3tc();
#endif /* GL_S3_s3tc */
#ifdef GL_SGIS_color_range
  _glewInfo_GL_SGIS_color_range();
#endif /* GL_SGIS_color_range */
#ifdef GL_SGIS_detail_texture
  _glewInfo_GL_SGIS_detail_texture();
#endif /* GL_SGIS_detail_texture */
#ifdef GL_SGIS_fog_function
  _glewInfo_GL_SGIS_fog_function();
#endif /* GL_SGIS_fog_function */
#ifdef GL_SGIS_generate_mipmap
  _glewInfo_GL_SGIS_generate_mipmap();
#endif /* GL_SGIS_generate_mipmap */
#ifdef GL_SGIS_multisample
  _glewInfo_GL_SGIS_multisample();
#endif /* GL_SGIS_multisample */
#ifdef GL_SGIS_pixel_texture
  _glewInfo_GL_SGIS_pixel_texture();
#endif /* GL_SGIS_pixel_texture */
#ifdef GL_SGIS_sharpen_texture
  _glewInfo_GL_SGIS_sharpen_texture();
#endif /* GL_SGIS_sharpen_texture */
#ifdef GL_SGIS_texture4D
  _glewInfo_GL_SGIS_texture4D();
#endif /* GL_SGIS_texture4D */
#ifdef GL_SGIS_texture_border_clamp
  _glewInfo_GL_SGIS_texture_border_clamp();
#endif /* GL_SGIS_texture_border_clamp */
#ifdef GL_SGIS_texture_edge_clamp
  _glewInfo_GL_SGIS_texture_edge_clamp();
#endif /* GL_SGIS_texture_edge_clamp */
#ifdef GL_SGIS_texture_filter4
  _glewInfo_GL_SGIS_texture_filter4();
#endif /* GL_SGIS_texture_filter4 */
#ifdef GL_SGIS_texture_lod
  _glewInfo_GL_SGIS_texture_lod();
#endif /* GL_SGIS_texture_lod */
#ifdef GL_SGIS_texture_select
  _glewInfo_GL_SGIS_texture_select();
#endif /* GL_SGIS_texture_select */
#ifdef GL_SGIX_async
  _glewInfo_GL_SGIX_async();
#endif /* GL_SGIX_async */
#ifdef GL_SGIX_async_histogram
  _glewInfo_GL_SGIX_async_histogram();
#endif /* GL_SGIX_async_histogram */
#ifdef GL_SGIX_async_pixel
  _glewInfo_GL_SGIX_async_pixel();
#endif /* GL_SGIX_async_pixel */
#ifdef GL_SGIX_blend_alpha_minmax
  _glewInfo_GL_SGIX_blend_alpha_minmax();
#endif /* GL_SGIX_blend_alpha_minmax */
#ifdef GL_SGIX_clipmap
  _glewInfo_GL_SGIX_clipmap();
#endif /* GL_SGIX_clipmap */
#ifdef GL_SGIX_depth_texture
  _glewInfo_GL_SGIX_depth_texture();
#endif /* GL_SGIX_depth_texture */
#ifdef GL_SGIX_flush_raster
  _glewInfo_GL_SGIX_flush_raster();
#endif /* GL_SGIX_flush_raster */
#ifdef GL_SGIX_fog_offset
  _glewInfo_GL_SGIX_fog_offset();
#endif /* GL_SGIX_fog_offset */
#ifdef GL_SGIX_fog_texture
  _glewInfo_GL_SGIX_fog_texture();
#endif /* GL_SGIX_fog_texture */
#ifdef GL_SGIX_fragment_specular_lighting
  _glewInfo_GL_SGIX_fragment_specular_lighting();
#endif /* GL_SGIX_fragment_specular_lighting */
#ifdef GL_SGIX_framezoom
  _glewInfo_GL_SGIX_framezoom();
#endif /* GL_SGIX_framezoom */
#ifdef GL_SGIX_interlace
  _glewInfo_GL_SGIX_interlace();
#endif /* GL_SGIX_interlace */
#ifdef GL_SGIX_ir_instrument1
  _glewInfo_GL_SGIX_ir_instrument1();
#endif /* GL_SGIX_ir_instrument1 */
#ifdef GL_SGIX_list_priority
  _glewInfo_GL_SGIX_list_priority();
#endif /* GL_SGIX_list_priority */
#ifdef GL_SGIX_pixel_texture
  _glewInfo_GL_SGIX_pixel_texture();
#endif /* GL_SGIX_pixel_texture */
#ifdef GL_SGIX_pixel_texture_bits
  _glewInfo_GL_SGIX_pixel_texture_bits();
#endif /* GL_SGIX_pixel_texture_bits */
#ifdef GL_SGIX_reference_plane
  _glewInfo_GL_SGIX_reference_plane();
#endif /* GL_SGIX_reference_plane */
#ifdef GL_SGIX_resample
  _glewInfo_GL_SGIX_resample();
#endif /* GL_SGIX_resample */
#ifdef GL_SGIX_shadow
  _glewInfo_GL_SGIX_shadow();
#endif /* GL_SGIX_shadow */
#ifdef GL_SGIX_shadow_ambient
  _glewInfo_GL_SGIX_shadow_ambient();
#endif /* GL_SGIX_shadow_ambient */
#ifdef GL_SGIX_sprite
  _glewInfo_GL_SGIX_sprite();
#endif /* GL_SGIX_sprite */
#ifdef GL_SGIX_tag_sample_buffer
  _glewInfo_GL_SGIX_tag_sample_buffer();
#endif /* GL_SGIX_tag_sample_buffer */
#ifdef GL_SGIX_texture_add_env
  _glewInfo_GL_SGIX_texture_add_env();
#endif /* GL_SGIX_texture_add_env */
#ifdef GL_SGIX_texture_coordinate_clamp
  _glewInfo_GL_SGIX_texture_coordinate_clamp();
#endif /* GL_SGIX_texture_coordinate_clamp */
#ifdef GL_SGIX_texture_lod_bias
  _glewInfo_GL_SGIX_texture_lod_bias();
#endif /* GL_SGIX_texture_lod_bias */
#ifdef GL_SGIX_texture_multi_buffer
  _glewInfo_GL_SGIX_texture_multi_buffer();
#endif /* GL_SGIX_texture_multi_buffer */
#ifdef GL_SGIX_texture_range
  _glewInfo_GL_SGIX_texture_range();
#endif /* GL_SGIX_texture_range */
#ifdef GL_SGIX_texture_scale_bias
  _glewInfo_GL_SGIX_texture_scale_bias();
#endif /* GL_SGIX_texture_scale_bias */
#ifdef GL_SGIX_vertex_preclip
  _glewInfo_GL_SGIX_vertex_preclip();
#endif /* GL_SGIX_vertex_preclip */
#ifdef GL_SGIX_vertex_preclip_hint
  _glewInfo_GL_SGIX_vertex_preclip_hint();
#endif /* GL_SGIX_vertex_preclip_hint */
#ifdef GL_SGIX_ycrcb
  _glewInfo_GL_SGIX_ycrcb();
#endif /* GL_SGIX_ycrcb */
#ifdef GL_SGI_color_matrix
  _glewInfo_GL_SGI_color_matrix();
#endif /* GL_SGI_color_matrix */
#ifdef GL_SGI_color_table
  _glewInfo_GL_SGI_color_table();
#endif /* GL_SGI_color_table */
#ifdef GL_SGI_texture_color_table
  _glewInfo_GL_SGI_texture_color_table();
#endif /* GL_SGI_texture_color_table */
#ifdef GL_SUNX_constant_data
  _glewInfo_GL_SUNX_constant_data();
#endif /* GL_SUNX_constant_data */
#ifdef GL_SUN_convolution_border_modes
  _glewInfo_GL_SUN_convolution_border_modes();
#endif /* GL_SUN_convolution_border_modes */
#ifdef GL_SUN_global_alpha
  _glewInfo_GL_SUN_global_alpha();
#endif /* GL_SUN_global_alpha */
#ifdef GL_SUN_mesh_array
  _glewInfo_GL_SUN_mesh_array();
#endif /* GL_SUN_mesh_array */
#ifdef GL_SUN_slice_accum
  _glewInfo_GL_SUN_slice_accum();
#endif /* GL_SUN_slice_accum */
#ifdef GL_SUN_triangle_list
  _glewInfo_GL_SUN_triangle_list();
#endif /* GL_SUN_triangle_list */
#ifdef GL_SUN_vertex
  _glewInfo_GL_SUN_vertex();
#endif /* GL_SUN_vertex */
#ifdef GL_WIN_phong_shading
  _glewInfo_GL_WIN_phong_shading();
#endif /* GL_WIN_phong_shading */
#ifdef GL_WIN_specular_fog
  _glewInfo_GL_WIN_specular_fog();
#endif /* GL_WIN_specular_fog */
#ifdef GL_WIN_swap_hint
  _glewInfo_GL_WIN_swap_hint();
#endif /* GL_WIN_swap_hint */
}

/* ------------------------------------------------------------------------ */

#ifdef _WIN32

static void wglewInfo ()
{
#ifdef WGL_3DFX_multisample
  _glewInfo_WGL_3DFX_multisample();
#endif /* WGL_3DFX_multisample */
#ifdef WGL_ARB_buffer_region
  _glewInfo_WGL_ARB_buffer_region();
#endif /* WGL_ARB_buffer_region */
#ifdef WGL_ARB_extensions_string
  _glewInfo_WGL_ARB_extensions_string();
#endif /* WGL_ARB_extensions_string */
#ifdef WGL_ARB_make_current_read
  _glewInfo_WGL_ARB_make_current_read();
#endif /* WGL_ARB_make_current_read */
#ifdef WGL_ARB_multisample
  _glewInfo_WGL_ARB_multisample();
#endif /* WGL_ARB_multisample */
#ifdef WGL_ARB_pbuffer
  _glewInfo_WGL_ARB_pbuffer();
#endif /* WGL_ARB_pbuffer */
#ifdef WGL_ARB_pixel_format
  _glewInfo_WGL_ARB_pixel_format();
#endif /* WGL_ARB_pixel_format */
#ifdef WGL_ARB_render_texture
  _glewInfo_WGL_ARB_render_texture();
#endif /* WGL_ARB_render_texture */
#ifdef WGL_ATI_pixel_format_float
  _glewInfo_WGL_ATI_pixel_format_float();
#endif /* WGL_ATI_pixel_format_float */
#ifdef WGL_EXT_depth_float
  _glewInfo_WGL_EXT_depth_float();
#endif /* WGL_EXT_depth_float */
#ifdef WGL_EXT_display_color_table
  _glewInfo_WGL_EXT_display_color_table();
#endif /* WGL_EXT_display_color_table */
#ifdef WGL_EXT_extensions_string
  _glewInfo_WGL_EXT_extensions_string();
#endif /* WGL_EXT_extensions_string */
#ifdef WGL_EXT_make_current_read
  _glewInfo_WGL_EXT_make_current_read();
#endif /* WGL_EXT_make_current_read */
#ifdef WGL_EXT_multisample
  _glewInfo_WGL_EXT_multisample();
#endif /* WGL_EXT_multisample */
#ifdef WGL_EXT_pbuffer
  _glewInfo_WGL_EXT_pbuffer();
#endif /* WGL_EXT_pbuffer */
#ifdef WGL_EXT_pixel_format
  _glewInfo_WGL_EXT_pixel_format();
#endif /* WGL_EXT_pixel_format */
#ifdef WGL_EXT_swap_control
  _glewInfo_WGL_EXT_swap_control();
#endif /* WGL_EXT_swap_control */
#ifdef WGL_I3D_digital_video_control
  _glewInfo_WGL_I3D_digital_video_control();
#endif /* WGL_I3D_digital_video_control */
#ifdef WGL_I3D_gamma
  _glewInfo_WGL_I3D_gamma();
#endif /* WGL_I3D_gamma */
#ifdef WGL_I3D_genlock
  _glewInfo_WGL_I3D_genlock();
#endif /* WGL_I3D_genlock */
#ifdef WGL_I3D_image_buffer
  _glewInfo_WGL_I3D_image_buffer();
#endif /* WGL_I3D_image_buffer */
#ifdef WGL_I3D_swap_frame_lock
  _glewInfo_WGL_I3D_swap_frame_lock();
#endif /* WGL_I3D_swap_frame_lock */
#ifdef WGL_I3D_swap_frame_usage
  _glewInfo_WGL_I3D_swap_frame_usage();
#endif /* WGL_I3D_swap_frame_usage */
#ifdef WGL_NV_float_buffer
  _glewInfo_WGL_NV_float_buffer();
#endif /* WGL_NV_float_buffer */
#ifdef WGL_NV_render_depth_texture
  _glewInfo_WGL_NV_render_depth_texture();
#endif /* WGL_NV_render_depth_texture */
#ifdef WGL_NV_render_texture_rectangle
  _glewInfo_WGL_NV_render_texture_rectangle();
#endif /* WGL_NV_render_texture_rectangle */
#ifdef WGL_NV_vertex_array_range
  _glewInfo_WGL_NV_vertex_array_range();
#endif /* WGL_NV_vertex_array_range */
#ifdef WGL_OML_sync_control
  _glewInfo_WGL_OML_sync_control();
#endif /* WGL_OML_sync_control */
}

#else /* _UNIX */

static void glxewInfo ()
{
#ifdef GLX_VERSION_1_2
  _glewInfo_GLX_VERSION_1_2();
#endif /* GLX_VERSION_1_2 */
#ifdef GLX_VERSION_1_3
  _glewInfo_GLX_VERSION_1_3();
#endif /* GLX_VERSION_1_3 */
#ifdef GLX_VERSION_1_4
  _glewInfo_GLX_VERSION_1_4();
#endif /* GLX_VERSION_1_4 */
#ifdef GLX_3DFX_multisample
  _glewInfo_GLX_3DFX_multisample();
#endif /* GLX_3DFX_multisample */
#ifdef GLX_ARB_get_proc_address
  _glewInfo_GLX_ARB_get_proc_address();
#endif /* GLX_ARB_get_proc_address */
#ifdef GLX_ARB_multisample
  _glewInfo_GLX_ARB_multisample();
#endif /* GLX_ARB_multisample */
#ifdef GLX_EXT_import_context
  _glewInfo_GLX_EXT_import_context();
#endif /* GLX_EXT_import_context */
#ifdef GLX_EXT_scene_marker
  _glewInfo_GLX_EXT_scene_marker();
#endif /* GLX_EXT_scene_marker */
#ifdef GLX_EXT_visual_info
  _glewInfo_GLX_EXT_visual_info();
#endif /* GLX_EXT_visual_info */
#ifdef GLX_EXT_visual_rating
  _glewInfo_GLX_EXT_visual_rating();
#endif /* GLX_EXT_visual_rating */
#ifdef GLX_MESA_copy_sub_buffer
  _glewInfo_GLX_MESA_copy_sub_buffer();
#endif /* GLX_MESA_copy_sub_buffer */
#ifdef GLX_MESA_pixmap_colormap
  _glewInfo_GLX_MESA_pixmap_colormap();
#endif /* GLX_MESA_pixmap_colormap */
#ifdef GLX_MESA_release_buffers
  _glewInfo_GLX_MESA_release_buffers();
#endif /* GLX_MESA_release_buffers */
#ifdef GLX_MESA_set_3dfx_mode
  _glewInfo_GLX_MESA_set_3dfx_mode();
#endif /* GLX_MESA_set_3dfx_mode */
#ifdef GLX_NV_float_buffer
  _glewInfo_GLX_NV_float_buffer();
#endif /* GLX_NV_float_buffer */
#ifdef GLX_NV_vertex_array_range
  _glewInfo_GLX_NV_vertex_array_range();
#endif /* GLX_NV_vertex_array_range */
#ifdef GLX_OML_swap_method
  _glewInfo_GLX_OML_swap_method();
#endif /* GLX_OML_swap_method */
#if defined(GLX_OML_sync_control) && defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#include <inttypes.h>
  _glewInfo_GLX_OML_sync_control();
#endif /* GLX_OML_sync_control */
#ifdef GLX_SGIS_blended_overlay
  _glewInfo_GLX_SGIS_blended_overlay();
#endif /* GLX_SGIS_blended_overlay */
#ifdef GLX_SGIS_color_range
  _glewInfo_GLX_SGIS_color_range();
#endif /* GLX_SGIS_color_range */
#ifdef GLX_SGIS_multisample
  _glewInfo_GLX_SGIS_multisample();
#endif /* GLX_SGIS_multisample */
#ifdef GLX_SGIS_shared_multisample
  _glewInfo_GLX_SGIS_shared_multisample();
#endif /* GLX_SGIS_shared_multisample */
#ifdef GLX_SGIX_fbconfig
  _glewInfo_GLX_SGIX_fbconfig();
#endif /* GLX_SGIX_fbconfig */
#ifdef GLX_SGIX_pbuffer
  _glewInfo_GLX_SGIX_pbuffer();
#endif /* GLX_SGIX_pbuffer */
#ifdef GLX_SGIX_swap_barrier
  _glewInfo_GLX_SGIX_swap_barrier();
#endif /* GLX_SGIX_swap_barrier */
#ifdef GLX_SGIX_swap_group
  _glewInfo_GLX_SGIX_swap_group();
#endif /* GLX_SGIX_swap_group */
#ifdef GLX_SGIX_video_resize
  _glewInfo_GLX_SGIX_video_resize();
#endif /* GLX_SGIX_video_resize */
#ifdef GLX_SGIX_visual_select_group
  _glewInfo_GLX_SGIX_visual_select_group();
#endif /* GLX_SGIX_visual_select_group */
#ifdef GLX_SGI_cushion
  _glewInfo_GLX_SGI_cushion();
#endif /* GLX_SGI_cushion */
#ifdef GLX_SGI_make_current_read
  _glewInfo_GLX_SGI_make_current_read();
#endif /* GLX_SGI_make_current_read */
#ifdef GLX_SGI_swap_control
  _glewInfo_GLX_SGI_swap_control();
#endif /* GLX_SGI_swap_control */
#ifdef GLX_SGI_video_sync
  _glewInfo_GLX_SGI_video_sync();
#endif /* GLX_SGI_video_sync */
#ifdef GLX_SUN_get_transparent_index
  _glewInfo_GLX_SUN_get_transparent_index();
#endif /* GLX_SUN_get_transparent_index */
}

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

int main (int argc, char** argv)
{
  GLuint err;
  glutInit(&argc, argv);
  glutCreateWindow("GLEW Extension Info");
  glewExperimental = GL_TRUE;
  err = glewInit();
  if (GLEW_OK != err)
  {
    fprintf(stderr, "Error [main]: glewInit failed: %s\n", glewGetErrorString(err));
    return 1;
  }
#ifdef _WIN32
  f = fopen("glewinfo.txt", "w");
  if (f == NULL) f = stdout;
#else
  f = stdout;
#endif
  fprintf(f, "---------------------------\n");
  fprintf(f, "    GLEW Extension Info\n");
  fprintf(f, "---------------------------\n\n");
  fprintf(f, "Running on a %s from %s\n", 
	  glGetString(GL_RENDERER), glGetString(GL_VENDOR));
  fprintf(f, "OpenGL version %s is supported\n", glGetString(GL_VERSION));
  fprintf(f, "GLEW version %s is supported\n", glewGetString(GLEW_VERSION));
  glewInfo();
#ifdef _WIN32
  wglewInfo();
#else
  glxewInfo();
#endif
  if (f != stdout) fclose(f);
  return 0;
}
