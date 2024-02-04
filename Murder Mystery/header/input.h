/*--------------------------
 | �L�[�N���X(�V���O���g��) |
  --------------------------*/
class KeyClass{
	private:
		int KeyState[256];
		KeyClass(){}

	public:
		static KeyClass* GetInstance();
		void SetHitKey();
		int  GetState(int KeyCode);
};


/*---------------------------
 | �}�E�X�N���X(�V���O���g��)|
  ---------------------------*/
class MouseClass{
	
	enum{LeftClick,RightClick};

	private:
		int MouseX,MouseY;					  //�N���b�N���ꂽ���W���i�[
		int MouseState[2];					  //�N���b�N�����L�[���i�[
		int MouseWheel;						  //�}�E�X�z�C�[���̉�]�ʂ��i�[
		MouseClass(){}

	public:
		static MouseClass* GetInstance();
		void SetHitMouse();					//�N���b�N�������W���擾(�E�N���b�N�����N���b�N����)
		void GetPoint(int *x,int *y);		//�N���b�N�������W��Ԃ�
		void GetPointX(int &x);				//x���W��Ԃ�
		void GetPointY(int &y);				//y���W��Ԃ�
		int  GetWheel();					//�}�E�X�z�C�[���̉�]�ʂ��擾
		int  GetState(int MouseCode);		//�}�E�X�̏�Ԃ�Ԃ�
};
