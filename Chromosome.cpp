#include"Chromosome.h"

//막대 상태 넣어줌
void Chromosome::set_peg(const vector<vector<int>>& peg) {
	this->peg = peg;
}

//막대 임의로 선택
int Chromosome::rand_peg() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> ran(0, 2);
	int r = ran(gen);
	return r;
}

//방법을 만드는 함수
void Chromosome::run() {
	count = 0;
	state.push_back(peg);
	
	for (int i = 1; i <= disk_num; i++) {
		suc_peg.push_back(i);
	}
	while (is_success() == false) {

		moving();

		count++;

		state.push_back(peg);
	}
}

//고리 개수를 넣어줌
void Chromosome::set_disk(const int& disk_num) {
	this->disk_num = disk_num;
}

//고리를 뺄 막대 찾기
int Chromosome::peg_disk() {
	while (true) {
		int r = rand_peg();
		if (peg[r].size() != 0)
			return r;
	}
}

//고리를 옮기는 함수
void Chromosome::moving() {
	while (true) {
		int i = peg_disk();
		int r = rand_peg();
		vector<int> v;
		v.push_back(i); v.push_back(r);
		if (count >= 1) {
			vector<int> post_way(way[count - 1]);
			if (post_way[0] == r && post_way[1] == i)
				continue;
		}
		if (r != i) {
			if (peg[r].size() == 0 || peg[r][peg.at(r).size() - 1] < peg[i][peg.at(i).size() - 1]) {
				peg[r].push_back(peg[i][peg.at(i).size() - 1]);
				peg[i].pop_back();
				way.push_back(v);
				break;
			}
		}

	}
}

//성공 여부를 확인하는 함수
bool Chromosome::is_success() {
	for (int i = 1; i <= 2; i++)
		if (peg[i] == suc_peg) 
			return true;

	return false;
}

//way값을 내보낸다.
vector<vector<int>> Chromosome::get_way() const{
	return way;
}

//count값을 내보낸다.
int Chromosome::get_count() const{
	return count;
}

//state값을 내보낸다.
vector<vector<vector<int>>> Chromosome::get_state() const {
	return state;
}

//물려줌
void Chromosome::heritage(const vector<vector<vector<int>>>& state,const vector<vector<int>>& way, const int& count) {
	this->state = state; 
	this->way = way;
	this->count = count;
	this->disk_num = disk_num;
}

//변이
//void Chromosome::mutate(int r) {
//	set_peg(state[r]);
//	way.erase(way.begin() + r+1, way.end());
//	state.erase(state.begin() + r+1, state.end());
//	count = r;
//
//	while (is_success() == false) {
//
//		moving();
//
//		count++;
//
//		state.push_back(peg);
//	}
//	cout << "suc" << endl;
//}
