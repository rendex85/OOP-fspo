#include <iostream>
#include <cmath>
using namespace std;


class Polynome 
{
protected:

	int size;
	float *A;
public:
	Polynome() : size(3) { A = new float[size]; }
	Polynome(int len) : size(len) { A = new float[size]; }
	~Polynome() {}

	friend ostream& operator<< (ostream &out, const Polynome &p);
	friend istream& operator>> (istream &in,  Polynome &p);
	Polynome operator++(int) 
	{
		for (int i = 0; i < size; i++) {
			A[i]++;
		}
		return 0;
	}
	Polynome operator--(int) {
		for (int i = 0; i < size; i++) {
			A[i]--;
		}
		return 0;
	}

	Polynome operator+(Polynome p2) {
		int temp_size = size;
		if (temp_size == p2.size) {
			for (int i = 0; i < temp_size; i++) {
				p2.A[i] += A[i];
			}
		}
			temp_size = p2.size;
			return p2;
	}
	void delmas()
	{
		delete[] A;
	}
};

	ostream& operator<< (ostream &out, const Polynome &p)
	{
		out.width(30);
	for (int i = p.size; i > 0; i--) {
		
		out << p.A[i-1] << "X^" << i;
		if (i > 1) {
			out << " + ";
		}
	}
	return out;
}

istream& operator>> (istream &in,  Polynome &p) {
	
	for (int i = p.size; i > 0; i--) {
		
		in >> p.A[i-1];
		cout.width(40);
		cout << " ";
	}
	return in;
}

int main(int argc, char const *argv[]) {
	Polynome p1;
	int size;
	cout.width(40);
	cout << "Enter the first polynome: ";
	cin >> p1;
	cout << "\n";
	cout << p1 << endl;
	cout << "\n";
	p1--;
	cout << p1 << endl;
	cout << "\n";
	cout.width(40);
	cout << "Enter the second polynome size: ";
	cin >> size;
	Polynome p2(size);
	cout << "\n";
	cout.width(40);
	cout << "Enter the second polynome: ";
	cin >> p2;
	cout << "\n";
	cout << p2 << endl;
	cout << "\n";
	p2 = p1 + p2;
	cout << p2 << endl;
	p1.delmas();
	p2.delmas();
	return 0;
}