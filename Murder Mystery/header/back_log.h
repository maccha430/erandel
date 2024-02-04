/*------------------
 | �o�b�N���O�N���X |
  ------------------*/
class BackLogClass{
	private:
		int  DrawLine;										//�`��s��
		int  DrawSize;										//�e�L�X�g�`��c�T�C�Y
		int  LineHeight;									//��s�̍���
		int  LogDrawX;										//�o�b�N���O�`����W
		int  LogDrawY;										//�o�b�N���O�`����W
		int  DrawTextX;										//�e�L�X�g�`��X
		int  DrawTextY;										//�e�L�X�g�`��Y
		int  DrawNameX;										//���O�`��X
		int  DrawNameY;										//���O�`��Y
		int  *LineNo;										//�s�����X�g
		int  SerifCount;									//���݂̃Z���t�J�E���g
		int  DrawTextCount;									//�e�L�X�g�̕`��J�E���g
		int  EventCodeSize;									//�C�x���g�R�[�h�̑傫��
		int  MoveScroll;									//�X�N���[���o�[�ړ���
		int  SelectNo;										//�I�����Ă�W�����v�{�^��
		bool EndFlag;										//�G���h�t���O
		bool DialogFlag;									//�_�C�A���O�t���O
		int  JumpLoopCount;									//�W�����v���[�v��
		int  ButtonX1;										//�{�^��X1���W
		int  ButtonX2;										//�{�^��X2���W
		vector<int> ButtonY1;								//�{�^��Y1���W
		vector<int> ButtonY2;								//�{�^��Y2���W
		vector<int> JumpTextCount;							//�e�L�X�g�J�E���g
		vector<int> JumpSerifCount;							//�Z���t�J�E���g
		int  UpButtonHandle;								//��{�^���摜�n���h��
		int  DownButtonHandle;								//���{�^���摜�n���h��

	public:
		BackLogClass();																//������
		void Update(int *ArgLineNo,int ArgSerifCount);								//�Z���t�J�E���g�X�V
		void GetDrawLine();															//�`��s���擾
		void GetDrawSize();															//�e�L�X�g�`��c�T�C�Y�擾
		void GetLogDrawPoint();														//�`����W�擾
		int  DrawLog(std::string Name[1024],std::string Text[1024]);				//�o�b�N���O�`��
		int  MouseScroll();															//�}�E�X�z�C�[���ړ���
		int  Jump(short int &TextCount,short int &SerifCount,UserClass &User);		//�O�̃Z���t�ɔ��
		ScrollBarClass ScrollBar;													//�X�N���[���o�[�C���X�^���X
};