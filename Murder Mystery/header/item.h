/*----------------
 | �A�C�e���N���X |
  ----------------*/

class ItemClass {
protected:
	int Select;														//�I��ԍ��󂯎��
	int FadeFlag;													//�t�F�[�h�t���O
	bool flags[32];													//�t���O�󂯎��
	struct MenuArg_rec  UpperItemParam;								//�チ�j���[�p�����[�^
	struct MenuArg_rec  UnderItemParam;								//�チ�j���[�p�����[�^
	struct MenuArg_rec	ItemNaviParam;								//�A�C�e���i�r
	vector<int> ItemHandle;											//�A�C�e���摜

	bool ItemDialogFlag;
	bool MenuDialogFlag;

public:
	ItemClass();														//������
	void Main(UserClass& User, int& ChangeFlag);						//���C��
	void ModeChange(int& ModeFlag, int& ChangeFlag, UserClass& User);	//���[�h�`�F���W
	void SetMenuParam();												//���j���[�p�����[�^�Z�b�g
	void ItemLoad(bool flags[32]);										//�A�C�e���摜�����j���[�ɃZ�b�g
	void Draw();														//�`��
	ItemGraphClass Graph;												//�O���t�B�b�N

};