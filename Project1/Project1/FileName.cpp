#include <iostream>
#include <cmath>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction operator+(Fraction right) {
		return Fraction(numerator_ * right.denominator_ + right.numerator_ * denominator_, denominator_ * right.denominator_);
	}

	Fraction operator-(Fraction right) {
		return Fraction(numerator_ * right.denominator_ - right.numerator_ * denominator_, denominator_ * right.denominator_);
	}

	Fraction operator*(Fraction right) {
		return Fraction(numerator_ * right.numerator_, denominator_ * right.denominator_);
	}

	Fraction operator/(Fraction right) {
		return Fraction(numerator_ * right.denominator_, denominator_ * right.numerator_);
	}

	Fraction operator-() {
		return Fraction(-numerator_, -denominator_);
	}

	Fraction& operator++() {
		numerator_=numerator_ + denominator_;
		return *this;
	}

	Fraction operator++(int) {
		Fraction temp = *this;
		++(*this);
		return temp;
	}

	Fraction& operator--() {
		numerator_ = numerator_ - denominator_;
		return *this;
	}

	Fraction operator--(int) {
		Fraction temp = *this;
		--(*this);
		return temp;
	}

	friend std::ostream& operator<<(std::ostream& cout, Fraction fraction);
};

std::ostream& operator<<(std::ostream& cout, Fraction fraction) {
	int mod = (abs(fraction.numerator_) < abs(fraction.denominator_)) ? fraction.numerator_ : fraction.denominator_;
	int i = 2;
	while (i <= mod) {
		while (fraction.numerator_ % i == 0 && fraction.denominator_ % i == 0) {
			fraction.numerator_ = fraction.numerator_ / i;
			fraction.denominator_ = fraction.denominator_ / i;
		}
		++i;
	}
	return cout << fraction.numerator_ << "/" << fraction.denominator_;
}

int main()
{
	int a1, b1, a2, b2;

	std::cout << "Enter the numerator of the fraction 1:";
	std::cin >> a1;
	std::cout << "Enter the denominator of the fraction 1:";
	std::cin >> b1;
	std::cout << "Enter the numerator of the fraction 2:";
	std::cin >> a2;
	std::cout << "Enter the denominator of the fraction 2:";
	std::cin >> b2;

	Fraction f1(a1, b1);
	Fraction f2(a2, b2);

	
	std::cout << f1++ * f2 << std::endl;
	std::cout << ++f1 * f2 << std::endl;
	std::cout << f1 * f2-- << std::endl;
	std::cout << f1*--f2 << std::endl;


	return 0;
}