#include<iostream>
#include<vector>
#include<random>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

class Chromosome {
public:
	void run();									//실행하는 함수
	void set_peg(const vector<vector<int>>& peg);
	void set_disk(const int& disk_num);			//고리 개수를 받는 함수
	int peg_disk();								//고리가 있는 막대를 찾는 함수
	void moving();								//고리를 옮겨주는 함수
	bool is_success();							//성공 여부를 확인하는 함수
	int rand_peg();								//랜덤으로 0~2사이의 숫자를 반환하는 함수

	vector<vector<vector<int>>> get_state() const;		//상태를 반환하는 함수
	vector<vector<int>> get_way() const;		//방법을 반환하는 함수
	int get_count() const;						//옮긴 수를 반환하는 함수

	void heritage(const vector<vector<vector<int>>>& s, const vector<vector<int>>& w, const int& count);		//새로운 유전자에 상속해주는 함수
	//void mutate(int r);							//변이시키는 함수
private:
	int count;									//옮긴 수				
	int disk_num;								//고리 수				
	vector<vector<vector<int>>> state;			//상태 3차원 벡터		
	vector<vector<int>>way;						//방법 2차원 벡터		
	vector< vector<int> > peg;					//막대 2차원 벡터
	vector< int > suc_peg;						//이상적인 막대 벡터
};

#pragma once
