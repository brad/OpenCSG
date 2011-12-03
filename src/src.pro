TEMPLATE	= lib
TARGET		= opencsg
VERSION     = 1.3.2

CONFIG		+= opengl warn_on release
INCLUDEPATH += ../include ../

# Optionally specify deployment location using the 
# MACOSX_DEPLOY_DIR env. variable
DEPLOYDIR = $$(MACOSX_DEPLOY_DIR)

!isEmpty(DEPLOYDIR) {
  message("Deploy")
  INSTALLDIR     = $$(MACOSX_DEPLOY_DIR)
  INCLUDEPATH += $$(MACOSX_DEPLOY_DIR)/include
  LIBS += -L$$(MACOSX_DEPLOY_DIR)/lib -lGLEW
  CONFIG += absolute_library_soname
  headers.files = ../include/opencsg.h
  headers.path = $$INSTALLDIR/include
  INSTALLS += target headers
  target.path = $$INSTALLDIR/lib
}
else {
  DESTDIR = ../lib
  INCLUDEPATH += ../glew/include
  INSTALLS += target
  target.path = $$DESTDIR
}

HEADERS		= ../include/opencsg.h \
		  opencsgConfig.h \
		  area.h \
		  batch.h \
		  context.h \
		  channelManager.h \
		  frameBufferObject.h \
		  frameBufferObjectExt.h \
		  occlusionQuery.h \
		  offscreenBuffer.h \
		  opencsgRender.h \
		  openglHelper.h \
		  pBufferTexture.h \
		  primitiveHelper.h \
		  scissorMemo.h \
		  settings.h \
		  stencilManager.h \
		  ../RenderTexture/RenderTexture.h
SOURCES		= area.cpp \
		  batch.cpp \
		  context.cpp \
		  channelManager.cpp \
		  frameBufferObject.cpp	\
		  frameBufferObjectExt.cpp \
		  occlusionQuery.cpp \
		  offscreenBuffer.cpp \
		  opencsgRender.cpp \
		  openglHelper.cpp \
		  pBufferTexture.cpp \
		  primitive.cpp \
		  primitiveHelper.cpp \
		  renderGoldfeather.cpp \
		  renderSCS.cpp \
		  scissorMemo.cpp \
		  settings.cpp \
		  stencilManager.cpp \
		  ../RenderTexture/RenderTexture.cpp
