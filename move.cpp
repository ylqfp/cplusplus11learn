#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using std::chrono::steady_clock;

void create_a_range(const int target_size, vector<int>& return_by_ref)
{
	return_by_ref.resize(target_size);
	for(int i=0; i<target_size; i++)
	{
		return_by_ref[i] = i;
	}
}

vector<int> create_a_range(const int target_size) {
	vector<int> res(target_size);
	for(int i=0; i < target_size; i++) {
		res[i] = i;
	}
	return res;
}

int main() {
	const int target_size = 1000;
	const int loops = 1000;
	int ref_cs = 0;
	int return_cs = 0;
	steady_clock::time_point b = steady_clock::now();
	for (int i=0; i < loops; i++) {
		vector<int> result;
		create_a_range(target_size, result);
		ref_cs += result[target_size/2];
	}
	steady_clock::time_point e = steady_clock::now();
	auto ref_seconds = std::chrono::duration<double>(e-b).count();
	// time used by move
	//
	b = steady_clock::now();
	for (int i=0; i < loops; i++) {
		vector<int> result = create_a_range(target_size);
		ref_cs += result[target_size/2];
	}
	e = steady_clock::now();
	auto move_seconds = std::chrono::duration<double>(e-b).count();
	///
	cout << "Return by ref:" << ref_seconds << endl;
	cout << "Return with move:" << move_seconds << endl;
	return 0;
}
