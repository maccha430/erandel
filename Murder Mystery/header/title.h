
/*------------------------
 | �^�C�g����ʐ���N���X |
  ------------------------*/
class TitleClass{
	protected:
		int Select;
		int FadeFlag;

	public:
		void Main(int &ChangeFlag,UserClass &User);						//���C���֐�
		void ModeChange(int &ModeFlag,int &ChangFlag,UserClass &User);	//���[�h�`�F���W
		void InitSaveData(UserClass &User);								//���[�U�[�̃f�[�^������
		TitleGraphClass Graph;											//�^�C�g���O���t�B�b�N����
};	

