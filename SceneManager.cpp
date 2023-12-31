#include "SceneManager.h"


//メンバ変数の値を置き換えるのがアップデート関数
AbstractScene* SceneManager::Update()
{
	//現在のシーンのアップデートを実行
	
	mScene->Update();

	return mScene;
}

//描画処理のみを行う関数
void SceneManager::Draw() const
{
	//現在のシーンの描画関数を実行
	mScene->Draw();
}

//シーンの変更処理
AbstractScene* SceneManager::Change()
{
	AbstractScene* nextScene = mScene->Change();

	if (nextScene != mScene)
	{
		delete mScene;
		mScene = nextScene;
	}
	return nextScene;
}