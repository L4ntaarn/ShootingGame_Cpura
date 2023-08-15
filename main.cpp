#include "DxLib.h"
#include "SceneManager.h"
#include "GameMainScene.h"
#include "Player.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	SetGraphMode(1280, 720, 32);

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��


	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	//�V�[���}�l�[�W���[�I�u�W�F�N�g�̍쐬
	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));

	Player player;

	int nextTime;

	// �Q�[�����[�v
	while (ProcessMessage() == 0)
	{
		sceneMng.Update();
		sceneMng.Draw();
		player.Draw();



		if (sceneMng.Change() == nullptr) //�V�[���̕ύX����
		{
			break;
		}
		//sceneManager.Draw();

		//CreateBall();		//�{�[���e�X�g
		//MoveBall();

		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f


		DxLib_End();	// DX���C�u�����g�p�̏I������
		return 0;	// �\�t�g�̏I��
	}
}
