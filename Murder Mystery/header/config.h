/*------------------
 | �R���t�B�O�N���X |
  ------------------*/
class ConfigClass{
	private:
		int Select;														//�I��ԍ��󂯎��
		int FadeFlag;													//�t�F�[�h�t���O

		struct ConfigData_rec ConfigData;								//�R���t�B�O�R�s�[���
		struct ConfigData_rec BackConfigData;							//�R���t�B�O�f�[�^�o�b�N�A�b�v
		struct MenuArg_rec  MenuArg;									//���j���[�p�����[�^

	public:
		ConfigClass();													//������
		void Main(UserClass& User,int &ChangeFlag);						//���C��
		void ModeChange(int &ModeFlag,int &ChangeFlag,UserClass &User);	//���[�h�`�F���W
		ConfigGraphClass Graph;											//�O���t�B�b�N

};
