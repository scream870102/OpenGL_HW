#include "MainScene.h"

MainScene::MainScene()
{
	pPlayer = new Player();
	//  產生 projection 矩陣，此處為產生正投影矩陣
	matProjection = Ortho(-225.0f, 225.0f, -400.0f, 400.0f, -2.0f, 2.0f);
	matModelView = mat4(1.0f);
	pPlayer->SetShader(matModelView, matProjection);
}

MainScene::~MainScene()
{
	delete pPlayer;
}

void MainScene::Update(float delta)
{	
	pPlayer->Update(delta);
}

void MainScene::OnWinKeyboard(unsigned char key, int x, int y)
{
	printf_s("%c %d %d \n", key, x, y);
	switch (key)
	{
	case W_KEY:
		break;
	default:
		break;
	}
}

void MainScene::OnWinSpecialKeyboard(int key, int x, int y)
{
	/*if (key == GLUT_KEY_LEFT)
		printf_s("Left arrow being pressed");*/
}

void MainScene::OnWinMouse(int button, int state, int x, int y)
{
	/*if (button == GLUT_LEFT_BUTTON)
		printf_s("Left button being pressed");*/
}

void MainScene::Draw()
{
	pPlayer->Draw();
}
