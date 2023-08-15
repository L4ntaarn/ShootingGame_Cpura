#include "DxLib.h"
#include "SceneManager.h"
#include "GameMainScene.h"
#include "Player.h"

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	SetGraphMode(1280, 720, 32);

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動


	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	//シーンマネージャーオブジェクトの作成
	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));

	Player player;

	int nextTime;

	// ゲームループ
	while (ProcessMessage() == 0)
	{
		sceneMng.Update();
		sceneMng.Draw();
		player.Draw();



		if (sceneMng.Change() == nullptr) //シーンの変更処理
		{
			break;
		}
		//sceneManager.Draw();

		//CreateBall();		//ボールテスト
		//MoveBall();

		ScreenFlip();			// 裏画面の内容を表画面に反映


		DxLib_End();	// DXライブラリ使用の終了処理
		return 0;	// ソフトの終了
	}
}
