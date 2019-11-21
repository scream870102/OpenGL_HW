// Model-View matrix and Projection matrix
// Orthogonal or Orthographic projection
// Windows Events - Keyboard & Mouse
// Rotate Rectangle

#include "../Header/Angel.h"
#include "MainScene.h"

#define ESC_KEY 27

MainScene* mainScene;
//----------------------------------------------------------------------------
// ㄧΑ
void IdleProcess();

void init(void) {
	mainScene = new MainScene();
	glClearColor(0.0, 0.0, 0.0, 1.0); // black background
}

void GL_Display(void) {
	glClear(GL_COLOR_BUFFER_BIT); // clear the window
	mainScene->Draw();
	glutSwapBuffers();	// ユ传 Frame Buffer
}

void onFrameMove(float delta) {
	mainScene->Update(delta);
	GL_Display();
}


void Win_Keyboard(unsigned char key, int x, int y) {
	if ((int)key == ESC_KEY) {
		delete mainScene;
		exit(EXIT_SUCCESS);
	}
	mainScene->OnWinKeyboard(key, x, y);


}
//----------------------------------------------------------------------------
void Win_Mouse(int button, int state, int x, int y) {
	mainScene->OnWinMouse(button, state, x, y);
}
//----------------------------------------------------------------------------
void Win_Motion_Mouse(int x, int y) {
	mainScene->OnWinPassiveMouse(x, y);
}
void Win_SpecialKeyboard(int key, int x, int y) {

	mainScene->OnWinSpecialKeyboard(key, x, y);
}
//----------------------------------------------------------------------------
void GL_Reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
}

//----------------------------------------------------------------------------

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);

	// If you use freeglut the two lines of code can be added to your application 
	glutInitContextVersion(3, 2);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutCreateWindow("Momoko Momoko Momoko");

	// The glewExperimental global switch can be turned on by setting it to GL_TRUE before calling glewInit(), 
	// which ensures that all extensions with valid entry points will be exposed.
	glewExperimental = GL_TRUE;
	glewInit();

	init();

	glutMouseFunc(Win_Mouse);
	glutPassiveMotionFunc(Win_Motion_Mouse);
	glutMotionFunc(Win_Motion_Mouse);
	glutKeyboardFunc(Win_Keyboard);	// 矪瞶 ASCI 龄 AaESC 龄...单单
	glutSpecialFunc(Win_SpecialKeyboard);	// 矪瞶 NON-ASCI 龄 F1Homeよ龄...单单
	glutDisplayFunc(GL_Display);
	glutReshapeFunc(GL_Reshape);
	glutIdleFunc(IdleProcess);

	glutMainLoop();
	return 0;
}