//
// main.cpp for  in /home/aubert_n/rep/nibbler/openGLPourLesNuls
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Sat Apr  5 16:17:40 2014 Nathan AUBERT
// Last update Sun Apr  6 13:47:05 2014 Nathan AUBERT
//

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

GLfloat     Rotate; 

int width, height;

void draw_cube(GLuint Texture, float rotate, float x, float y, float z)
{
      // draw...
      glTranslatef(x, y, z);
      glRotatef(rotate, 1.f, 1.f, 1.f);
      glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, Texture);
      glColor4f(1.f, 1.f, 1.f, 1.f);

      glBegin(GL_QUADS);
      // Front Face
      glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
      glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
      glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
      glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
      // Back Face
      glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
      glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
      glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
      glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
      // Top Face
      glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
      glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
      glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
      glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
      // Bottom Face
      glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
      glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
      glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
      glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
      // Right face
      glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
      glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
      glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
      glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
      // Left Face
      glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
      glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
      glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
      glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
      glEnd();
}

void	clear_buffer()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // MatrixMode(GL_MODELVIEW);
  glLoadIdentity(); 
  gluLookAt(3,4,5, 0,0,0, 0,0,1);
  gluPerspective(45.0f, 800.0f / 600.0f, 1.0f, 500.0f);
}
   
using namespace std;
int main()
{
  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
  window.setVerticalSyncEnabled(true);
  width = 256;
  height = 256;
  glClearDepth(1.f);
  glClearColor(0.f, 0.f, 0.f, 0.f);
  glMatrixMode(GL_PROJECTION);

  /**/
  // glLoadIdentity();
  // glFrustum(-2.f, 1.f, -1.f, 1.f, 1.5f, 20.f);
  // glMatrixMode(GL_MODELVIEW);
  // glLoadIdentity();
  /**/


  glDepthMask(GL_TRUE);
  glEnable(GL_DEPTH_TEST);
  // load resources, initialize the OpenGL states, ...

  GLuint Texture = 0;
  {
    sf::Image Image;
    if (!Image.loadFromFile("GreenCube.bmp"))
      return EXIT_FAILURE;
    glGenTextures(1, &Texture);
    glBindTexture(GL_TEXTURE_2D, Texture);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, width, height, GL_RGBA, GL_UNSIGNED_BYTE, Image.getPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  }
  // run the main loop

  bool running = true;
  while (running)
    {
      // handle events
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    {
	      // end the program
	      running = false;
	    }
	  else if (event.type == sf::Event::Resized)
	    {
	      // adjust the viewport when the window is resized
	      glViewport(0, 0, event.size.width, event.size.height);
	    }
	}

      // end the current frame (internally swaps the front and back buffers)

      static float rotate = 0;

      clear_buffer();
      glPushMatrix();
      draw_cube(Texture, rotate, 0, 0, -7);
      glPopMatrix();

      // glPushMatrix();
      // draw_cube(Texture, -rotate, 1, -1, -7);
      // glPopMatrix();

      window.display(); 
      rotate += 1;
    }

  // release resources...

  return 0;
}

