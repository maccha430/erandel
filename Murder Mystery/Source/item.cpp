#include"../header/define.h"
/*----------------
 | �A�C�e���N���X |
  ----------------*/
/*������*/
ItemClass::ItemClass()
{
	Select = -1;
	//�A�C�e���A�C�R��
	ItemHandle.push_back(LoadGraph("./resource/graph/item_play.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_eye.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_drop.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_jail.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_memo.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_flute.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_sheet.png"));
	ItemHandle.push_back(LoadGraph("./resource/graph/item_ID.png"));
}
/*���C���֐�*/
void ItemClass::Main(UserClass& User, int& ChangeFlag)
{
	//�萔�錾
	const int Speed = 60;	//�t�F�[�h�C�����x

	//���[�h�`�F���W�����Ƃ��A������
	if (ChangeFlag == TRUE) {
		for (int i = 0; i < MAX_FLAG; ++i)//���[�U�[�N���X�̃t���O�����R�s�[
		{
			flags[i] = User.CheckFlag(i);
		}
		SetMenuParam();
		ChangeFlag = FALSE;					//���[�h�`�F���W�t���O��܂�
		FadeFlag = FALSE;					//�t�F�[�h�����t���O��܂�
		Graph.Anime.Reset();				//�A�j���[�V�������Z�b�g
	}

	//�t�F�[�h�C��
	FadeFlag = Graph.Anime.FadeIn(Speed);
	Draw();
}


void ItemClass::ModeChange(int& ModeFlag, int& ChangeFlag, UserClass& User)
{
	//�C���X�^���X��
	MouseClass* Mouse = MouseClass::GetInstance();
	static DialogClass Dialog;

	//�萔��`
	enum { BACK = 8};

	//�_�C�A���O�`��t���O���擾
	MenuDialogFlag = Dialog.GetDrawFlag();

	//���N���b�N����āA�t�F�[�h���I����Ă�
	if (Mouse->GetState(MOUSE::LEFT) == TRUE && FadeFlag == TRUE && MenuDialogFlag == FALSE) {
		switch (Select) {
			//�O�ɖ߂�
		case BACK:
			ModeFlag = MODE::MAIN;
			ChangeFlag = TRUE;
			break;

			//�^�C�g���ɖ߂�
		//case TITLEBACK:
		//	Dialog.SetSelectNo(Select, "�^�C�g���ɖ߂�܂����H");
		//	break;
		}
	}

	if (MenuDialogFlag == TRUE) {
		//�_�C�A���O�`��
		Dialog.Draw(User);

		//Yes�Ȃ珈��
		if (Dialog.GetSelectFlag() == DIALOG::YES) {

			//�I��ԍ��󂯎��
			Select = Dialog.GetSelectNo();

			//�^�C�g���Ȃ��
			//if (Select == TITLEBACK) {
			//	ModeFlag = MODE::OTHER;
			//	User.SetPage(PAGE::TITLE);
			//	Dialog.Clear();
			//}
		}

		//No�Ȃ�_�C�A���O�폜
		if (Dialog.GetSelectFlag() == DIALOG::NO) 	Dialog.Clear();
	}
}
void ItemClass::SetMenuParam()
{
	UpperItemParam.DrawX = 60;
	UpperItemParam.DrawY = 80;
	UpperItemParam.Interval = 150;
	UpperItemParam.Width = 150;
	UpperItemParam.Height = 150;
	UpperItemParam.ListMin = 0;
	UpperItemParam.ListMax = 4;
	UpperItemParam.AtherNo = -1;
	UpperItemParam.AlphaNo = 100;
	UpperItemParam.DrawFlag = MENU::IMAGE;
	UpperItemParam.DirectionFlag = MENU::ROW;

	UnderItemParam.DrawX = 60;
	UnderItemParam.DrawY = 370;
	UnderItemParam.Interval = 150;
	UnderItemParam.Width = 150;
	UnderItemParam.Height = 150;
	UnderItemParam.ListMin = 4;
	UnderItemParam.ListMax = 8;
	UnderItemParam.AtherNo = -1;
	UnderItemParam.AlphaNo = 100;
	UnderItemParam.DrawFlag = MENU::IMAGE;
	UnderItemParam.DirectionFlag = MENU::ROW;
	ItemLoad(flags);
	//�E�����j���[
	ItemNaviParam.DrawX =windowX-300;
	ItemNaviParam.DrawY =windowY-60;
	ItemNaviParam.Interval =0;
	ItemNaviParam.Width = 320;
	ItemNaviParam.Height = 56;
	ItemNaviParam.ListMin = 8;
	ItemNaviParam.ListMax =	9;
	ItemNaviParam.AtherNo = -1;
	ItemNaviParam.AlphaNo = 200;
	ItemNaviParam.DrawFlag = MENU::IMAGE;
	ItemNaviParam.DirectionFlag = MENU::ROW;
	ItemNaviParam.DrawHandle[0] = LoadGraph("./resource/graph/BackGo.png");
}

void ItemClass::ItemLoad(bool flags[32])
{
	for (int i = 0; i < MAX_ITEM/2; ++i)
	{
		if (flags[i] == true)
		{
			UpperItemParam.DrawHandle[i]=ItemHandle[i];
		}
		else { UpperItemParam.DrawHandle[i] = (LoadGraph("./resource/graph/item_question.png")); }
	}
	int j = 0;
	for (int i = MAX_ITEM / 2; i <MAX_ITEM ; ++i)
	{
		
		if (flags[i] == true)
		{
			UnderItemParam.DrawHandle[j] = ItemHandle[i];
		}
		else { UnderItemParam.DrawHandle[j] = (LoadGraph("./resource/graph/item_question.png")); }
		++j;
	}
}

void ItemClass::Draw()
{
	const int AtherSelect = -1;
	//�e�탁�j���[�錾
	ItemMenuClass UpperItemMenu(UpperItemParam);
	ItemMenuClass UnderItemMenu(UnderItemParam);
	MenuClass NaviMenu(ItemNaviParam);

	 if (MenuDialogFlag == FALSE && ItemDialogFlag == FALSE) {
		 UpperItemMenu.Select();
		 UnderItemMenu.Select();
		 NaviMenu.Select();
	 }
	 /*�w�i�`��*/
	 Graph.Draw();

	 /*���j���[�`��*/
	 UpperItemMenu.Draw();
	 UnderItemMenu.Draw();
	 NaviMenu.Draw();
	 Select = NaviMenu.GetSelectNo();
	 if (Select == AtherSelect) Select = UpperItemMenu.GetSelectNo();
	 if (Select == AtherSelect) Select = UnderItemMenu.GetSelectNo();
}



