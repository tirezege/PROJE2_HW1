#include <iostream>
#include <GL/glut.h>
#include <SOIL/SOIL.h>

GLdouble angle = 0;
GLint texture[6];
GLint skybox[6];
GLfloat LightDiffuse[]=		{ 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[]=	{ -28.0f, 0.0f, 0.0f, 1.0f };
GLfloat material_shininess[] = { 20 };
//GLfloat amb_light[] =		{ 0.1, 0.1, 0.1, 1.0 };


int LoadGLTextures()
{
	texture[0] = SOIL_load_OGL_texture
		(
		"Data/star.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
		);

	texture[1] = SOIL_load_OGL_texture
		(
		"Data/planet1.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
		);

	texture[2] = SOIL_load_OGL_texture
		(
		"Data/planet1moon1.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y |SOIL_FLAG_TEXTURE_REPEATS
		);

	texture[3] = SOIL_load_OGL_texture
		(
		"Data/planet2.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
		);

	texture[4] = SOIL_load_OGL_texture
		(
		"Data/planet2moon1.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
		);

	texture[5] = SOIL_load_OGL_texture
		(
		"Data/planet2moon2.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
		);

	skybox[0] = SOIL_load_OGL_texture
		(
		"Data/skybox0.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
		);

	skybox[1] = SOIL_load_OGL_texture
		(
		"Data/skybox1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
		);

	skybox[2] = SOIL_load_OGL_texture
		(
		"Data/skybox2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
		);

	skybox[3] = SOIL_load_OGL_texture
		(
		"Data/skybox3.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
		);

	skybox[4] = SOIL_load_OGL_texture
		(
		"Data/skybox4.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
		);

	skybox[5] = SOIL_load_OGL_texture
		(
		"Data/skybox5.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
		);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	
	return true;
}

static void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

	//Draw SKYBOX
	glPushMatrix();
	glLoadIdentity();
	gluLookAt(
		0,0,0,
		0,0,-80,
        0,1,0);

	glPushAttrib(GL_ENABLE_BIT);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);

	// Render the front quad
	glBindTexture(GL_TEXTURE_2D, skybox[0]);
	glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
        glTexCoord2f(0, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
    glEnd();
 
    // Render the left quad
    glBindTexture(GL_TEXTURE_2D, skybox[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(  0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
        glTexCoord2f(0, 1); glVertex3f(  0.5f,  0.5f,  0.5f );
    glEnd();
 
    // Render the back quad
    glBindTexture(GL_TEXTURE_2D, skybox[2]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f,  0.5f );
        glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f,  0.5f );
 
    glEnd();
 
    // Render the right quad
    glBindTexture(GL_TEXTURE_2D, skybox[3]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 0); glVertex3f( -0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 1); glVertex3f( -0.5f,  0.5f,  0.5f );
        glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
    glEnd();
 
    // Render the top quad
    glBindTexture(GL_TEXTURE_2D, skybox[4]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
        glTexCoord2f(0, 0); glVertex3f( -0.5f,  0.5f,  0.5f );
        glTexCoord2f(1, 0); glVertex3f(  0.5f,  0.5f,  0.5f );
        glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
    glEnd();
 
    // Render the bottom quad
    glBindTexture(GL_TEXTURE_2D, skybox[5]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
        glTexCoord2f(0, 1); glVertex3f( -0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 1); glVertex3f(  0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
    glEnd();

	glPopAttrib();
    glPopMatrix();

	glEnable( GL_LIGHT0 );
    glTranslatef(0.f, 0.0f, -50.f);
	//gluLookAt(0, 5, 0, 0, 0, 0, 0, 0, 1);
  
	//Star

	glRotated(angle/2, 0, 1, 0);
	
	glBindTexture(GL_TEXTURE_2D, texture[0]); 

	GLfloat sun_emission[] = { 1.0, 1.0, 0.0, 1 };
	glMaterialfv( GL_FRONT, GL_EMISSION, sun_emission );
    GLUquadric* quadric1 = gluNewQuadric();
    gluQuadricNormals(quadric1, GLU_SMOOTH);
	gluQuadricTexture(quadric1, GL_TRUE);
	gluSphere( quadric1, 4 , 50 , 50 );

	glPushMatrix();
		//Planet1
		glRotated(angle/2, 0, 1, 0);
		glTranslatef(10.0f, 0.0f, 0.0f);
		glRotated(angle, 0, 1, 0);
	
		glBindTexture(GL_TEXTURE_2D, texture[1]); 
		
		GLfloat planet_emission[] = { 0.0, 0.0, 0.0, 1.0 };
		glMaterialfv( GL_FRONT, GL_EMISSION, planet_emission );
		GLUquadric* quadric2 = gluNewQuadric();
		gluQuadricNormals(quadric2, GLU_SMOOTH);
		gluQuadricTexture(quadric2, GL_TRUE);
		gluSphere( quadric2 , 1 , 50 , 50 );

		//Planet1 Moon1
		glRotated(angle, 0, 1, 0);
		glTranslatef(2.0f, 0.0f, 0.0f);

		glBindTexture(GL_TEXTURE_2D, texture[2]); 

		GLUquadric* quadric3 = gluNewQuadric();
		gluQuadricNormals(quadric3, GLU_SMOOTH);
		gluQuadricTexture(quadric3, GL_TRUE);
		gluSphere( quadric3 , 0.5 , 50 , 50 );
	glPopMatrix();
	
	//Planet2		

		glTranslatef(20.0f, 0.0f, 0.0f);
		glRotated(angle, 0, 1, 0);

		glBindTexture(GL_TEXTURE_2D, texture[3]); 

		GLUquadric* quadric4 = gluNewQuadric();
		gluQuadricNormals(quadric4, GLU_SMOOTH);
		gluQuadricTexture(quadric4, GL_TRUE);
		gluSphere( quadric4 , 2, 50 , 50 );

	glPushMatrix();
		//Planet2 Moon1
		glRotated(angle, 0, 1, 0);
		glTranslatef(4.0f, 0.0f, 0.0f);
		glRotated(angle/2, 0, 1, 0);

		glBindTexture(GL_TEXTURE_2D, texture[4]); 

		GLUquadric* quadric5 = gluNewQuadric();
		gluQuadricNormals(quadric5, GLU_SMOOTH);
		gluQuadricTexture(quadric5, GL_TRUE);
		gluSphere( quadric5 , 1 , 50 , 50 );
	glPopMatrix();

	//Planet2 Moon2
		
		glRotated(angle/2, 0, 1, 0);
		glTranslatef(8.0f, 0.0f, 0.0f);
		glRotated(angle/2, 0, 1, 0);

		glBindTexture(GL_TEXTURE_2D, texture[5]); 

		GLUquadric* quadric6 = gluNewQuadric();
		gluQuadricNormals(quadric6, GLU_SMOOTH);
		gluQuadricTexture(quadric6, GL_TRUE);
		gluSphere( quadric6 , 1 , 50 , 50 );    
    glutSwapBuffers();


    
}

static void timerCallback (int value)
{	
    angle ++;


	glLightfv(GL_LIGHT0, GL_POSITION,LightPosition);
    glMaterialfv(GL_FRONT,GL_SHININESS, material_shininess);

    glutTimerFunc(10, timerCallback, 0);
    glutPostRedisplay();
}

int main (int argc, char ** argv)
{


    GLenum type;
    
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	type = GLUT_RGB;
	type |= GLUT_DOUBLE;
	type |= GLUT_DEPTH;
    type |= GLUT_MULTISAMPLE;
	glutInitDisplayMode(type);
	glutCreateWindow("Ege Sarioglu 040070240 PROJE I");
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
       
    glMatrixMode(GL_PROJECTION);
    gluPerspective(55, 800/600, 0.1, 100);
    
    glMatrixMode(GL_MODELVIEW);
    
    timerCallback(0);

	LoadGLTextures();

	//Setup Light
	glEnable( GL_LIGHTING );	
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);		
	glEnable( GL_COLOR_MATERIAL );
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glMaterialfv(GL_FRONT,GL_SHININESS, material_shininess);
	glShadeModel(GL_SMOOTH);
	//glLightModelfv( GL_LIGHT_MODEL_AMBIENT, amb_light );

	glEnable(GL_TEXTURE_2D);

    glutDisplayFunc(Draw);
    glutMainLoop();
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
