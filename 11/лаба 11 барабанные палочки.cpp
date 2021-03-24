#include <iostream>
#include <cmath>
using namespace std;


class Polynome 
{
protected:

	int size;
	float *A = new float[size];

public:
	Polynome() : size(3) {}
	Polynome(int len) : size(len) {}
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
};

	ostream& operator<< (ostream &out, const Polynome &p)
	{
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
		try
		{
			if (!(in >> p.A[i - 1]))
			{
				in.clear();
				fflush(stdin);
				throw 0;
			}
		}
		catch (int er)
		{
			cout << "set to null" << endl;
			p.A[i - 1] = 0;
			in.get();
		}

	}
	return in;
}

int main(int argc, char const *argv[]) {
	Polynome p1;
	int size;
	cout << "Enter the first polynome:\n";
	cin >> p1;
	cout << p1 << endl;
	p1--;
	cout << p1 << endl;
	cout << "Enter the second polynome size:\n";
	cin >> size;
	Polynome p2(size);
	cout << "Enter the second polynome:\n";
	cin >> p2;
	cout << p2 << endl;
	p2 = p1 + p2;
	cout << p2 << endl;
	return 0;
}