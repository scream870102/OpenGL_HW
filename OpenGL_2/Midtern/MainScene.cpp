#include "MainScene.h"

MainScene::MainScene()
{
	pPlayer = new Player();
	//  產生 projection 矩陣，此處為產生正投影矩陣
	matProjection = Ortho(-225.0f, 225.0f, -400.0f, 400.0f, -2.0f, 2.0f);
	matModelView = mat4(1.0f);
	pPlayer->SetShader(matModelView, matProjection);
	printf_s("x:%f sx:%f px:%f \n",pPlayer->Transform.position.x, pPlayer->Transform.scale.x,pPlayer->Transform.colors[0].x);
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
	printf_s("%c being pressed \n", key);
	switch (key)
	{
	case 119:
		printf_s("before %f\n",pPlayer->Transform.position.x);
		pPlayer->Transform.position.x += 10;
		printf_s("w being pressed %f\n", pPlayer->Transform.position.x);
		break;
	default:
		break;
	}
}

void MainScene::Draw()
{
	pPlayer->Draw();
}
