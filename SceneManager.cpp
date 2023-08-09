#include "SceneManager.h"


//�����o�ϐ��̒l��u��������̂��A�b�v�f�[�g�֐�
AbstractScene* SceneManager::Update()
{
	//���݂̃V�[���̃A�b�v�f�[�g�����s
	
	mScene->Update();
}

//�`�揈���݂̂��s���֐�
void SceneManager::Draw() const
{
	//���݂̃V�[���̕`��֐������s
	mScene->Draw();
}

//�V�[���̕ύX����
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