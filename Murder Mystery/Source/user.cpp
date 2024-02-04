#include"../header/define.h" 

/*------------------
 | ���[�U���N���X |
  ------------------*/
/*�����o�ϐ�������*/
UserClass::UserClass(){
	PageFlag			= PAGE::TITLE;
	SaveData.SceneCount = 0;
	SaveData.TextCount	= 0;

	//�R���t�B�O�f�[�^������

}

/*���݃y�[�W���Z�b�g*/
void UserClass::SetPage(int Page){
	PageFlag = Page;
}

/*���݃y�[�W���擾*/
int UserClass::GetPage(){
	return PageFlag;
}

/*�Z�[�u�f�[�^�Z�b�g*/
void UserClass::SetSaveData(SaveData_rec &SaveData){this->SaveData = SaveData;}
SaveData_rec UserClass::GetSaveData(){ return this->SaveData;}

/*�R���t�B�O��񃍁[�h*/
void UserClass::LoadConfigData(){
	//�萔
	enum{TEXTSPEED,AUTOSPEED,SKIP,ALLVOL,BGMVOL,SEVOL};

	FILE *fp;
	int  TmpData[6];

	//�R���t�B�O�f�[�^�ǂݍ���
	fp = fopen("./resource/data/conf.dat","rb+");
	fread(TmpData,6,sizeof(TmpData),fp);
	fclose(fp);

	//�ǂݍ��񂾃f�[�^�����[�U�[�N���X�ɃR�s�[
	ConfigData.TextSpeed = TmpData[TEXTSPEED];
	ConfigData.AutoSpeed = TmpData[AUTOSPEED];
	ConfigData.SkipFlag  = TmpData[SKIP];
	ConfigData.AllBolume = TmpData[ALLVOL];
	ConfigData.BGMBolume = TmpData[BGMVOL];
	ConfigData.SEBolume  = TmpData[SEVOL];

}

void UserClass::SaveConfigData(){
	//�萔
	enum{TEXTSPEED,AUTOSPEED,SKIP,ALLVOL,BGMVOL,SEVOL};

	FILE *fp;
	int  TmpData[6];

	//���[�U�[�N���X�̃R���t�B�O�����R�s�[
	TmpData[TEXTSPEED] = ConfigData.TextSpeed;
	TmpData[AUTOSPEED] = ConfigData.AutoSpeed;
	TmpData[SKIP]      = ConfigData.SkipFlag; 
	TmpData[ALLVOL]    = ConfigData.AllBolume;
	TmpData[BGMVOL]    = ConfigData.BGMBolume;
	TmpData[SEVOL]     = ConfigData.SEBolume;  

	//�R���t�B�O�f�[�^��������
	fp = fopen("./resource/data/conf.dat","wb+");
	fwrite(TmpData,6,sizeof(int),fp);
	fclose(fp);

}

/*�R���t�B�O�f�[�^�Z�b�g�E�擾*/
void UserClass::SetConfigData(ConfigData_rec &ConfigData){ this->ConfigData = ConfigData; }
ConfigData_rec UserClass::GetConfigData(){ return ConfigData; }


/*�R���t�B�O�f�[�^����擾*/
int UserClass::GetTextSpeed(){	
	int TextSpeed;

	if( ConfigData.TextSpeed == 0 ) TextSpeed = 5; 
	if( ConfigData.TextSpeed == 1 ) TextSpeed = 4; 
	if( ConfigData.TextSpeed == 2 ) TextSpeed = 3; 
	if( ConfigData.TextSpeed == 3 ) TextSpeed = 2; 
	if( ConfigData.TextSpeed == 4 ) TextSpeed = 1; 

	return TextSpeed; 
}

int UserClass::GetAutoTextSpeed(){
	int AutoSpeed;

	if( ConfigData.AutoSpeed == 0 ) AutoSpeed = 5; 
	if( ConfigData.AutoSpeed == 1 ) AutoSpeed = 4; 
	if( ConfigData.AutoSpeed == 2 ) AutoSpeed = 3; 
	if( ConfigData.AutoSpeed == 3 ) AutoSpeed = 2; 
	if( ConfigData.AutoSpeed == 4 ) AutoSpeed = 1; 


	return AutoSpeed; 
}

int UserClass::GetSkipFlag(){
	return ConfigData.SkipFlag;  
}

int UserClass::GetBGMVol(){
	int VolLevel;

	VolLevel = ConfigData.AllBolume + ConfigData.BGMBolume;
	
	if( VolLevel >= 6 && VolLevel <= 8 ) VolLevel = ( VolLevel - 3 ) * 50;
	if( VolLevel >= 2 && VolLevel <= 5 ) VolLevel = ( ( VolLevel - 1 ) * 25 ) + 25; 

	if( ConfigData.AllBolume == 0 || ConfigData.BGMBolume == 0 ) VolLevel = 0;

	return VolLevel;
}

int UserClass::GetSEVol(){
	int VolLevel;

	VolLevel = ConfigData.AllBolume + ConfigData.SEBolume;
	
	if( VolLevel >= 6 && VolLevel <= 8 ) VolLevel = ( VolLevel - 3 ) * 50;
	if( VolLevel >= 2 && VolLevel <= 5 ) VolLevel = ( ( VolLevel - 1 ) * 25 ) + 25; 

	if( ConfigData.AllBolume == 0 || ConfigData.SEBolume == 0 ) VolLevel = 0;


	//VolLevel = ConfigData.AllBolume + ConfigData.SEBolume - 6 + 2;
	//if( VolLevel <= 0 ) VolLevel = 0;
	return VolLevel;
}

/*���Ǌ֌W*/
void UserClass::ReadUpdate(){
	short int WriteData[2];
	FILE *fp;

	//�폜
	/*
	if( ConfigData.SkipFlag == 1 ){
		fp = fopen("./resource/data/read.dat","wb+");
		WriteData[0] = 0;
		WriteData[1] = 0;
		fwrite(WriteData,2,sizeof(short int),fp);
		fclose(fp);
	}

	//���߂�
	if( ConfigData.SkipFlag == 0 ){
		fp = fopen("./resource/data/read.dat","wb+");
		WriteData[0] = 999;
		WriteData[1] = 999;
		fwrite(WriteData,2,sizeof(short int),fp);
		fclose(fp);
	}*/
}

/*BGM�R�[�h�Z�b�g��Q�b�g*/
void UserClass::SetBGMCode(int Code){ this->BGMCode = Code; }
int  UserClass::GetBGMCode(){return BGMCode;}

/*�w�i�R�[�h�Z�b�g��Q�b�g*/
void UserClass::SetBackCode(int Code){ this->BackCode = Code; }
int  UserClass::GetBackCode(){return BackCode;}

/*�L�����N�^�R�[�h�Z�b�g��Q�b�g*/
void UserClass::SetCharacterCode(int Code){ this->CharCode = Code; }
int  UserClass::GetCharacterCode(){return CharCode;}

/*�V�[�N���b�g�t���O*/
void UserClass::SetSecretFlag(){
	//�ϐ��錾
	FILE *fp;
	int SecretFlag;

	//�萔��`
	const int Key = 831;

	//�t�@�C���I�[�v��
	fp = fopen("./resource/data/syslog.dat","rb+");
	
	//�t�@�C���ǂݍ���
	fread(&SecretFlag,1,sizeof(int),fp);

	//�t���O�`�F�b�N
	if( SecretFlag == Key ) this->SecretFlag = TRUE;
	else					this->SecretFlag = FALSE;

	//�t�@�C���N���[�Y
	fclose(fp);
}
bool UserClass::GetSecretFlag(){return SecretFlag;}