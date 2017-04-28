// pc1.cpp : Programming challege 3, sequence sum.
// Adam Flammino, 3/26
// Prints first (user inputed int) odd numbers and squares, finds sums


#include "stdafx.h"
#include <iostream>

// Abstract class
class AbstractSeq {
public:
	virtual int fun(int k) = 0;
	void printSeq(int k, int m);
	int sumSeq(int k, int m);
};

// Prints sequence
void AbstractSeq::printSeq(int k, int m) {
	for (int i = k; i <= m; i++) {
		std::cout << fun(i) << " ";
	}
}

// Sums sequence
int AbstractSeq::sumSeq(int k, int m) {
	int sum = 0;
	for (int i = k; i <= m; i++) {
		sum += fun(i);
	}
	return sum;
}

// Returns sequence of odd numbers
class OddSeq : public AbstractSeq {
	int fun(int k) {
		int odd = 2 * k + 1;
		return odd;
	}
};

// Returns sequence of squares
class SquareSeq : public AbstractSeq {
	int fun(int k) {
		int square = k * k;
		return square;
	}
};


int main()
{
	int input;
	int cap;
	OddSeq odd;
	SquareSeq square;
	std::cout << "Enter how many numbers you would like in your sequence:\t";
	std::cin >> input;
	cap = input - 1;
	std::cout << std::endl << "The first " << input << " odd numbers are:\n";
	odd.printSeq(0, cap);
	std::cout << "\nThe sum of the first " << input << " odd numbers is:\t " <<
		odd.sumSeq(0, cap) << std::endl;
	std::cout << "\nThe first " << input << " squares are:\n";
	square.printSeq(0, cap);
	std::cout << "\nThe sum of the first " << input << " squares is:\t" <<
		square.sumSeq(0, cap) << std::endl << std::endl;

    return 0;
}

