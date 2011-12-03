TEMPLATE	= app
TARGET		= opencsgexample

CONFIG	 	+= opengl warn_on release
INCLUDEPATH     += ../include
LIBS            += -L../lib -lopencsg -lGLEW
macx {
  INCLUDEPATH   += /opt/local/include
  LIBS          += -framework GLUT -L/opt/local/lib
}
else {
  INCLUDEPATH   += ../glew/include
  LIBS          += -lglut -L../glew/lib
}

HEADERS		= displaylistPrimitive.h
SOURCES		= displaylistPrimitive.cpp main.cpp
