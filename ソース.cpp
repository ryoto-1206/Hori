#include<iostream> //�ȉ��̓��͂ɕK�v
#include<vector>
#include<random>
#include<string>
#include<chrono>
#include<fstream>
using namespace std; //std::cout��cout�݂̂œ��͂ł���悤�ɂ���
using namespace std::chrono; 

class Modeselect { //class���`���N���X����Modeselect�Ƃ���
public: //�ȉ��̃v���O�������O������A�N�Z�X�ł���悤�ɂ���
	int Wordcount() { //Wordcount�֐����`����
		string str1; ////str1�𕶎��Ƃ��Ē�`����
		cin >> str1; //�L�[�{�[�h�œ��͂��镶����str1�Ƃ���
		return size(str1); //���͂�������str1�̕�������߂�l�Ƃ��ĕԂ�
	}
};

void end()//�v���O�����𐳏�ɏI��������֐�end()���`����
{
	std::exit(0);//�v���O�����𐳏�ɏI��������
}

double Decidetime(int n, int m) { //����n,m�̓��͂ɂ���Ă����̊Ԃ̐�����C�ӂɌ��肷��֐�
	vector<int>v1; //v1��p�ӂ���
	random_device engine; //�������쐬����
	uniform_int_distribution<unsigned> dist1(n, m); //n����m�͈͓̔��ŔC�ӂ̐������쐬����
	for (int i = 0; i < 5; ++i) { //0����4�̗v�f(����)��p�ӂ���v1�Ɋi�[����
		v1.push_back(dist1(engine));
	}
	auto it = v1.begin(); //�擪�v�f���w���C�e���[�^���`����
	return *(it + 2); //��`����it����2�Ԗڂ̗v�f���w��������߂�l�Ƃ��ĕԂ�
}

double Measuretime() { //�L�[�{�[�h���͂ɂ�莞�Ԃ𑪒肷��֐�
	string str2; //str2�𕶎��Ƃ��Ē�`����
	cin >> str2; //�L�[�{�[�h�œ��͂��镶����str2�Ƃ���
	if (str2 == "s") { //���͂�������str2��s�ł������Ƃ�
		cout << "���Ԃ̑�����J�n�����!\n"; //���Ԃ̑�����J�n���邱�Ƃ��o�͂���
		auto t0 = high_resolution_clock::now(); //���̎����𑪒肷��
		cin >> str2; //�L�[�{�[�h�œ��͂��镶����str2�Ƃ���
		auto t1 = high_resolution_clock::now(); //���̎����𑪒肷��
		return duration_cast<milliseconds>(t1 - t0).count() / 1000.; //���肵������t0,t1�̍����Ƃ邱�ƂŃL�[�{�[�h��2����͂����Ԃ̎��Ԃ�߂�l�Ƃ��ĕԂ�
	}
	else {
		cout << "���͂��镶�����Ⴄ��!\n"; //���͂���������s�ł͂Ȃ������Ƃ����͂����������Ⴄ���Ƃ��o�͂���
		end(); //�v���O�����𐳏�ɏI��������
	}
}



int main(){//main�֐�
	ifstream infile("game explanation.txt"); //�t�@�C��game explanation.txt���J��
	string line; //line�𕶎��Ƃ��Ē�`����
	while (getline(infile, line)) { //�t�@�C���̏I���܂ŌJ��Ԃ�
		cout << line << endl; //�����Ƃ��Ē�`����line���o�͂���
	}
	infile.close(); //�t�@�C�������
	
	Modeselect mojisu; //�N���X�ł���Modeselect�̃I�u�W�F�N�g�Ƃ���mojisu���`����
	 int result =mojisu.Wordcount();  //�I�u�W�F�N�gmojisu��Wordcount�֐��̖߂�l(���͂��ꂽ������)�𐮐��Ƃ���result�ƒ�`����
	
	 if (result == 6) { //Wordcount�֐��̖߂�l�ł��镶������6�ł������Ƃ�
		 cout << "�L�[�{�[�h����s����͂���Enter�L�[�������Ă�.Enter�L�[�������Ǝ��Ԃ̑��肪�n�܂��.����,�w�肳�ꂽ�b�������O�ɍD���ȕ�������͂��Ď��Ԃ��������Ǝv������Enter�L�[�������Ă�"; //�ȏ�̂悤�ɏo�͂���
		 double time = Measuretime(); //Measuretime�֐��̖߂�l(���肳�ꂽ����)�������Ƃ���time�Ƃ��Ē�`����
		 cout << "���ʂ�" << time << "�b����" << endl; //time�̌��ʂ��o�͂���
		 double a = 10.000; //����a��10.000�Ƃ��Ē�`����
		 double b = a - time; //a��time�̍�������b�Ƃ��Ē�`����
		 //���肵�����ԂƎw�肵�����Ԃ̍����Ƃ邱�ƂŃ����N�𔻒肷��
		 if (-0.5 < b && b < 0.5) cout << "S�����N����@���΂炵���I�I�@�����ڎw���Ċ撣�낤�I\n"; //b�̐�Βl��0.5��菬������Έȏ�̂悤�ɏo�͂���
		 else if (-1.0 < b && b < 1.0) cout << "A�����N����@���Ə�����S�����N���I\n"; //b�̐�Βl��1.0��菬������Έȏ�̂悤�ɏo�͂���
		 else if (-2.0 < b && b < 2.0) cout << "B�����N����@�����������\n"; //b�̐�Βl��2.0��菬������Έȏ�̂悤�ɏo�͂���
		 else  cout << "C�����N����@���߂�ȁ` �H\n"; //����ȊO�Ȃ�Έȏ�̂悤�ɏo�͂���
	 }

	 else if (result == 5) {//Wordcount�֐��̖߂�l�ł��镶������5�ł������Ƃ�
		 double time1 = Decidetime(10, 20); //Decidetime�֐��̈�����10,20�Ƃ����Ƃ��̖߂�l��time1�ƒ�`����
		 cout << "�w�肳�ꂽ���Ԃ�" << time1 << "�b����" << endl; //�߂�l�̌��ʂ��ȏ�̂悤�ɏo�͂���
		 cout << "�L�[�{�[�h����s����͂���Enter�L�[��������.Enter�L�[�������Ǝ��Ԃ̑��肪�n�܂��.����,�w�肳�ꂽ�b�������O�ɍD���ȕ�������͂��Ď��Ԃ��������Ǝv������Enter�L�[�������Ă�";//�ȏ�̂悤�ɏo�͂���
		 double time2 = Measuretime(); //Measuretime�֐��̖߂�l��time2�ƒ�`����
		 cout << "���ʂ�" << time2 << "�b����" << endl; //�߂�l�̌��ʂ��ȉ��̂悤�ɏo�͂���
		 double c = time1 - time2; //time1��time2�̍�������c�Ƃ��Ē�`����
		 if (-0.5 < c && c < 0.5) //����c�̐�Βl��0.5�ȉ��̂Ƃ�
			 cout << "S�����N����@���΂炵���I�I �����ڎw���Ċ撣�낤�I\n"; //�ȏ�̂悤�ɏo�͂���
		 else if (-1.0 < c && c < 1.0)//����c�̐�Βl��1.0�ȉ��̂Ƃ�
			 cout << "A�����N����@������,���Ə�����S�����N���I\n";//�ȏ�̂悤�ɏo�͂���
		 else if (-2.0 < c && c < 2.0) //����c�̐�Βl��2.0�ȉ��̂Ƃ�
			 cout << "B�����N����@�t�@�C�g�\�I�I\n"; //�ȏ�̂悤�ɏo�͂���
		 else cout << "C�����N����@�撣�낤�I�@\n"; //����ȊO�̂Ƃ��ȏ�̂悤�ɏo�͂���
	 }

	 else if (result == 9) { //Wordcount�֐��̖߂�l�ł��镶������9�ł������Ƃ�
		 double time3 = Decidetime(20, 30); //Decidetime�֐��̈�����20,30�Ƃ����Ƃ��̖߂�l��time3�ƒ�`����
		 cout << "�w�肳�ꂽ���Ԃ�" << time3 << "�b����" << endl; //�߂�l�̌��ʂ��ȏ�̂悤�ɏo�͂���
		 cout << "�L�[�{�[�h����s����͂���Enter�L�[��������.Enter�L�[�������Ǝ��Ԃ̑��肪�n�܂��.����,�w�肳�ꂽ�b�������O�ɍD���ȕ�������͂��Ď��Ԃ��������Ǝv������Enter�L�[�������Ă�";//�ȏ�̂悤�ɏo�͂���
		 double time4 = Measuretime(); //Measuretime�֐��̖߂�l��time4�ƒ�`����
		 cout << "���ʂ�" << time4 << "�b����" << endl; //�߂�l�̌��ʂ��ȉ��̂悤�ɏo�͂���
		 double d = time3 - time4; //time3��time4�̍�������d�Ƃ��Ē�`����
		 if (-0.5 < d && d < 0.5) cout << "����Ȃ���S�����N����@���΂炵���I�I\n"; //����d�̐�Βl��0.5�ȉ��̂Ƃ��ȏ�̂悤�ɏo�͂���
		 else if (-1.0 < d && d < 1.0) cout << "����������A�����N����@���Ə�����S�����N���I\n"; //����d�̐�Βl��0.5�ȉ��̂Ƃ��ȏ�̂悤�ɏo�͂���
		 else if (-2.0 < d && d < 2.0) cout << "������B�����N����@�܂��܂�����\n"; //����d�̐�Βl��0.5�ȉ��̂Ƃ��ȏ�̂悤�ɏo�͂���
		 else cout << "�Œ�]����C�����N����@����` ���v���ȁH�H\n"; //����ȊO�̂Ƃ��ȏ�̂悤�ɏo�͂���
	 }
}



