#include<iostream> //以下の入力に必要
#include<vector>
#include<random>
#include<string>
#include<chrono>
#include<fstream>
using namespace std; //std::coutをcoutのみで入力できるようにした
using namespace std::chrono; 

class Modeselect { //classを定義しクラス名をModeselectとする
public: //以下のプログラムを外部からアクセスできるようにした
	int Wordcount() { //Wordcount関数を定義する
		string str1; ////str1を文字として定義する
		cin >> str1; //キーボードで入力する文字をstr1とする
		return size(str1); //入力した文字str1の文字数を戻り値として返す
	}
};

void end()//プログラムを正常に終了させる関数end()を定義する
{
	std::exit(0);//プログラムを正常に終了させる
}

double Decidetime(int n, int m) { //引数n,mの入力によってそれらの間の数字を任意に決定する関数
	vector<int>v1; //v1を用意する
	random_device engine; //乱数を作成する
	uniform_int_distribution<unsigned> dist1(n, m); //nからmの範囲内で任意の数字を作成する
	for (int i = 0; i < 5; ++i) { //0から4の要素(乱数)を用意したv1に格納する
		v1.push_back(dist1(engine));
	}
	auto it = v1.begin(); //先頭要素を指すイテレータを定義する
	return *(it + 2); //定義したitから2番目の要素が指す乱数を戻り値として返す
}

double Measuretime() { //キーボード入力により時間を測定する関数
	string str2; //str2を文字として定義する
	cin >> str2; //キーボードで入力する文字をstr2とする
	if (str2 == "s") { //入力した文字str2がsであったとき
		cout << "時間の測定を開始するよ!\n"; //時間の測定を開始することを出力する
		auto t0 = high_resolution_clock::now(); //この時刻を測定する
		cin >> str2; //キーボードで入力する文字をstr2とする
		auto t1 = high_resolution_clock::now(); //この時刻を測定する
		return duration_cast<milliseconds>(t1 - t0).count() / 1000.; //測定した時刻t0,t1の差をとることでキーボードで2回入力した間の時間を戻り値として返す
	}
	else {
		cout << "入力する文字が違うよ!\n"; //入力した文字がsではなかったとき入力した文字が違うことを出力する
		end(); //プログラムを正常に終了させる
	}
}



int main(){//main関数
	ifstream infile("game explanation.txt"); //ファイルgame explanation.txtを開く
	string line; //lineを文字として定義する
	while (getline(infile, line)) { //ファイルの終わりまで繰り返す
		cout << line << endl; //文字として定義したlineを出力する
	}
	infile.close(); //ファイルを閉じる
	
	Modeselect mojisu; //クラスであるModeselectのオブジェクトとしてmojisuを定義する
	 int result =mojisu.Wordcount();  //オブジェクトmojisuのWordcount関数の戻り値(入力された文字数)を整数としてresultと定義する
	
	 if (result == 6) { //Wordcount関数の戻り値である文字数が6であったとき
		 cout << "キーボードからsを入力してEnterキーを押してね.Enterキーを押すと時間の測定が始まるよ.次に,指定された秒数がたつ前に好きな文字を入力して時間がたったと思ったらEnterキーを押してね"; //以上のように出力する
		 double time = Measuretime(); //Measuretime関数の戻り値(測定された時間)を少数としてtimeとして定義する
		 cout << "結果は" << time << "秒だよ" << endl; //timeの結果を出力する
		 double a = 10.000; //少数aを10.000として定義する
		 double b = a - time; //aとtimeの差を少数bとして定義する
		 //測定した時間と指定した時間の差をとることでランクを判定する
		 if (-0.5 < b && b < 0.5) cout << "Sランクだよ　すばらしい！！　次も目指して頑張ろう！\n"; //bの絶対値が0.5より小さければ以上のように出力する
		 else if (-1.0 < b && b < 1.0) cout << "Aランクだよ　あと少しでSランクだ！\n"; //bの絶対値が1.0より小さければ以上のように出力する
		 else if (-2.0 < b && b < 2.0) cout << "Bランクだよ　もうちょっと\n"; //bの絶対値が2.0より小さければ以上のように出力する
		 else  cout << "Cランクだよ　諦めるな～ ？\n"; //それ以外ならば以上のように出力する
	 }

	 else if (result == 5) {//Wordcount関数の戻り値である文字数が5であったとき
		 double time1 = Decidetime(10, 20); //Decidetime関数の引数を10,20としたときの戻り値をtime1と定義する
		 cout << "指定された時間は" << time1 << "秒だよ" << endl; //戻り値の結果を以上のように出力する
		 cout << "キーボードからsを入力してEnterキーを押しね.Enterキーを押すと時間の測定が始まるよ.次に,指定された秒数がたつ前に好きな文字を入力して時間がたったと思ったらEnterキーを押してね";//以上のように出力する
		 double time2 = Measuretime(); //Measuretime関数の戻り値をtime2と定義する
		 cout << "結果は" << time2 << "秒だよ" << endl; //戻り値の結果を以下のように出力する
		 double c = time1 - time2; //time1とtime2の差を少数cとして定義する
		 if (-0.5 < c && c < 0.5) //少数cの絶対値が0.5以下のとき
			 cout << "Sランクだよ　すばらしい！！ 次も目指して頑張ろう！\n"; //以上のように出力する
		 else if (-1.0 < c && c < 1.0)//少数cの絶対値が1.0以下のとき
			 cout << "Aランクだよ　おしい,あと少しでSランクだ！\n";//以上のように出力する
		 else if (-2.0 < c && c < 2.0) //少数cの絶対値が2.0以下のとき
			 cout << "Bランクだよ　ファイト―！！\n"; //以上のように出力する
		 else cout << "Cランクだよ　頑張ろう！　\n"; //それ以外のとき以上のように出力する
	 }

	 else if (result == 9) { //Wordcount関数の戻り値である文字数が9であったとき
		 double time3 = Decidetime(20, 30); //Decidetime関数の引数を20,30としたときの戻り値をtime3と定義する
		 cout << "指定された時間は" << time3 << "秒だよ" << endl; //戻り値の結果を以上のように出力する
		 cout << "キーボードからsを入力してEnterキーを押しね.Enterキーを押すと時間の測定が始まるよ.次に,指定された秒数がたつ前に好きな文字を入力して時間がたったと思ったらEnterキーを押してね";//以上のように出力する
		 double time4 = Measuretime(); //Measuretime関数の戻り値をtime4と定義する
		 cout << "結果は" << time4 << "秒だよ" << endl; //戻り値の結果を以下のように出力する
		 double d = time3 - time4; //time3とtime4の差を少数dとして定義する
		 if (-0.5 < d && d < 0.5) cout << "文句なしのSランクだよ　すばらしい！！\n"; //少数dの絶対値が0.5以下のとき以上のように出力する
		 else if (-1.0 < d && d < 1.0) cout << "おしいけどAランクだよ　あと少しでSランクだ！\n"; //少数dの絶対値が0.5以下のとき以上のように出力する
		 else if (-2.0 < d && d < 2.0) cout << "微妙なBランクだよ　まだまだだね\n"; //少数dの絶対値が0.5以下のとき以上のように出力する
		 else cout << "最低評価のCランクだよ　あれ～ 大丈夫かな？？\n"; //それ以外のとき以上のように出力する
	 }
}



