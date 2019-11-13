// Model-View matrix and Projection matrix
// Orthogonal or Orthographic projection
// Windows Events - Keyboard & Mouse
// Rotate Rectangle

#include "../Header/Angel.h"
#include "../191030_HW/Player.h"
#include "../Utils/Input.h"

//For move
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
//For rotation
#define Q_KEY 113
#define E_KEY 101
//For Scale
#define J_KEY 106
#define K_KEY 107
//Function Key
#define ESC_KEY 33
#define SPACE_KEY 32
#define R_KEY 72


// 必須在 glewInit(); 執行完後,在執行物件實體的取得
Player* pPlayer;	// 宣告 Quad 指標物件，結束時記得釋放
vec3 position;
vec3 rotation;
vec3 scale;
vec3 nPos;
vec3 nRot;
vec3 nScl;
//Input input = Input();
const float POS_VEL = 10000.0f;
const float ROT_VEL = 1500.0f;
const float SCL_VEL = 100.0f;

//For automatically scaling
const float SCL_RANGE = 3.0f;
const float SCL_SPEED = 500.0f;
float degree = 0.0f;
bool bScaling = false;

// For Model View and Projection Matrix
mat4 matModelView(1.0f);
mat4 matProjection;

bool bUpdateTRS = false;

//----------------------------------------------------------------------------
// 函式的原型宣告
void IdleProcess();

void init(void) {
	// 必須在 glewInit(); 執行完後,在執行物件實體的取得
	pPlayer = new Player();
	position = vec3();
	rotation = vec3();
	scale = vec3(1.0f);

	//  產生 projection 矩陣，此處為產生正投影矩陣
	matProjection = Ortho(-225.0f, 225.0f, -400.0f, 400.0f, -2.0f, 2.0f);
	pPlayer->SetShader(matModelView, matProjection);
	
	glClearColor(0.0, 0.0, 0.0, 1.0); // black background
}

//----------------------------------------------------------------------------

void UpdateTRS() {
	mat4 trsMat;
	trsMat = Translate(position);
	trsMat *= RotateZ(rotation.z);
	trsMat *= Scale(scale);
	pPlayer->SetTRSMatrix(trsMat);
}

void UpdateTransform(float delta) {
	position += nPos * delta;
	rotation += nRot * delta;
	scale += nScl * delta;
	bUpdateTRS = false;
	UpdateTRS();
}


void AutoScaling(float delta) {
	degree += SCL_SPEED *delta;
	if (degree >= 360.0f)degree = 0.0f;
	float range= abs(SCL_RANGE * cosf(degree * M_PI / 180.0));
	scale.x = 1 + range;
	scale.y = 1 + range;
	UpdateTRS();
}

//void Update(float delta) {
//	if (input.GetKey(KeyCode::w))position.y += POS_VEL * delta;
//	if (input.GetKey(KeyCode::s)) { printf_s("AAA"); position.y -= POS_VEL * delta; }
//	if (input.GetKey(KeyCode::a))position.x -= POS_VEL * delta;
//	if (input.GetKey(KeyCode::d))position.x += POS_VEL * delta;
//	if (input.GetKey(KeyCode::q))rotation.z += ROT_VEL * delta;
//	if (input.GetKey(KeyCode::e))rotation.z -= ROT_VEL * delta;
//	if (input.GetKey(KeyCode::j)) {
//		scale.x += SCL_VEL * delta;
//		scale.y += SCL_VEL * delta;
//	}
//	if (input.GetKey(KeyCode::k)) {
//		scale.x -= SCL_VEL * delta;
//		scale.y -= SCL_VEL * delta;
//	}
//	mat4 trsMat;
//	trsMat = Translate(position);
//	trsMat *= RotateZ(rotation.z);
//	trsMat *= Scale(scale);
//	pPlayer->SetTRSMatrix(trsMat);
//}

void GL_Display(void) {
	glClear(GL_COLOR_BUFFER_BIT); // clear the window
	pPlayer->Draw();
	glutSwapBuffers();	// 交換 Frame Buffer
}

void onFrameMove(float delta) {
	//Update(delta);
	if (bScaling)AutoScaling(delta);
	if (bUpdateTRS)UpdateTransform(delta);
	GL_Display();
}

//----------------------------------------------------------------------------
void reset() {
	bUpdateTRS = false;
	position = vec3();
	rotation = vec3();
	scale = vec3(1.0f);
}
//----------------------------------------------------------------------------

void Win_Keyboard(unsigned char key, int x, int y) {
	//printf_s("%d", key);
	//input.UpdateKey(key);
	nPos = vec3();
	nRot = vec3();
	nScl = vec3();
	switch (key) {
	case W_KEY:
		nPos.y += POS_VEL;
		bUpdateTRS = true;
		break;
	case S_KEY:
		nPos.y -= POS_VEL;
		bUpdateTRS = true;
		break;
	case A_KEY:
		nPos.x -= POS_VEL;
		bUpdateTRS = true;
		break;
	case D_KEY:
		nPos.x += POS_VEL;
		bUpdateTRS = true;
		break;
	case Q_KEY:
		nRot.z += ROT_VEL;
		bUpdateTRS = true;
		break;
	case E_KEY:
		nRot.z -= ROT_VEL;
		bUpdateTRS = true;
		break;
	case J_KEY:
		nScl.x += SCL_VEL;
		nScl.y += SCL_VEL;
		bUpdateTRS = true;
		break;
	case K_KEY:
		nScl.x -= SCL_VEL;
		nScl.y -= SCL_VEL;
		bUpdateTRS = true;
		break;
	case R_KEY:
		reset();
		break;
	case ESC_KEY:
		delete pPlayer;
		exit(EXIT_SUCCESS);
		break;
	case SPACE_KEY:
		bScaling = !bScaling;
		break;
	}
}
//----------------------------------------------------------------------------
void Win_Mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:   // 目前按下的是滑鼠左鍵
		break;
	case GLUT_MIDDLE_BUTTON:  // 目前按下的是滑鼠中鍵 ，換成 Y 軸
		break;
	case GLUT_RIGHT_BUTTON:   // 目前按下的是滑鼠右鍵
		break;
	default:
		break;
	}
}
//----------------------------------------------------------------------------
void Win_SpecialKeyboard(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:		// 目前按下的是向左方向鍵
		break;
	case GLUT_KEY_RIGHT:	// 目前按下的是向右方向鍵
		break;
	default:
		break;
	}
}
//----------------------------------------------------------------------------
void GL_Reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
}

//----------------------------------------------------------------------------

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(450, 800);

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
	glutKeyboardFunc(Win_Keyboard);	// 處理 ASCI 按鍵如 A、a、ESC 鍵...等等
	glutSpecialFunc(Win_SpecialKeyboard);	// 處理 NON-ASCI 按鍵如 F1、Home、方向鍵...等等
	glutDisplayFunc(GL_Display);
	glutReshapeFunc(GL_Reshape);
	glutIdleFunc(IdleProcess);

	glutMainLoop();
	return 0;
}
