/*----------------
 | �e�L�X�g�N���X |
  ----------------*/
class TextClass{
	private:
		//�萔
		enum{SceneMax=8,RowMax=1024};						//�V�[���ő吔�A�s���ő�
		enum{NORMAL,EYECATCH,BACKLOG,NOTWINDOW,CHANGE,END,TITLE}; //�`�惂�[�h�萔

		int  Select;										//�I�����j���[
		int  MenuEnterFlag;									//���j���[����t���O 
		int  WriteMode;									    //�`�惂�[�h�i�[

		short int  TextCount;								//�e�L�X�g�J�E���^
		short int  SceneCount;								//�V�[���J�E���^
		short int  SerifCount;								//�Z���t�J�E���^

		int  SelectFlag;									//�I�����o���t���O
		int  SkipPermitFlag;								//�X�L�b�v���t���O
		int  AutoFlag;										//�I�[�g�t���O�@
		int  TextGraphEndFlag;								//�e�L�X�g�S���`�抮���t���O

		int LineNo[64][1024];								//�e�Z���t�̍s�����擾
		int LineMax[100];									//1�V�[�����Ƃ̃e�L�X�g�̑��s��
		std::string Name[64][1024];							//�L�����l�[���ϐ�
		std::string Text[64][1024];							//�Z���t�e�L�X�g�ϐ�

		//�e�L�X�g���\�b�h
		void InitGameCount(UserClass &User);				//�Q�[���J�E���g�̏�����

		//�Z�[�u�f�[�^
		struct SaveData_rec SaveData;	

	public:
		//��������`�F�b�N
		TextClass();										//������
		void InitVar();										//�ϐ�������
		void LoadStory();									//�X�g�[���[���[�h
		int  CutSpace(std::string &TmpText);				//�e�L�X�g����S�p�󔒂���菜��
		void CheckText(UserClass &User);					//�e�L�X�g�`�F�b�N
		std::vector<std::string> StringSplit(const std::string &Str,char Sep);		 //�����񕪊�

		//���C���֐�
		void Main(UserClass &User);													//���C���֐�
		void ModeChange(int &ModeFlag,int &ChangeFlag,UserClass &User);				//���[�h�`�F���W

		//�ʏ�`��֘A
		void NormalWrite(UserClass &User);					//�e�L�X�g�ʏ�`��
		void WriteText(UserClass &User);					//�e�L�X�g�`��
		void WriteName();									//���O�`��
		void WriteSkip();									//�X�L�b�v�@�\
		
		//���̍s�֐i�߂�
		void PutNextLine(UserClass &User);					//���̍s�֐i�߂�		
		
		//�`�惂�[�h�擾
		int  GetWriteMode();								//�Z���N�g�t���O�擾

		//�A�C�L���b�`�֘A
		void EyeCatching(UserClass &User);					//�A�C�L���b�`����

		//�X�L�b�v�E�I�[�g
		void SkipFunction(UserClass &User);					//�X�L�b�v����
		void CheckRead();									//���ǃ`�F�b�N
		void ControlRead();									//�f�o�b�O�p���Ǒ���
		void AutoFunction(UserClass &User);					//�I�[�g����

		//�o�b�N���O�`��
		void BackLogMain(UserClass &User);					//�o�b�N���O�`��

		//�E�B���h�E��\��
		void NotWindow();									//�E�B���h�E��\��

		//�R���t�B�O�̖��ǃX�L�b�v���ݒ�
		void ReadUpdate(UserClass &User);					//���̂܂�

		//���Ԃ��o�߂����悤�Ɍ�����
		void OverTime(UserClass &User);						//���Ԃ��o�����悤�Ɍ�����

		//�Q�[���I��
		void GameEnd(UserClass &User);						//�I��

		//���݂̃f�[�^���Z�b�g
		void SetGameData(UserClass &User);

		//����R�[�h�`�F�b�N
		void CheckCotrolCode(UserClass &User);	
		void BackCheckControlCode(UserClass &User);


		//�Q�[���O���t�B�b�N
		TextGraphClass		Graph;
				
};