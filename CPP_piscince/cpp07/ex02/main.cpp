#include "includes.hpp"
#include "types.hpp"
#include "templates.tpp"



int main()
{
	TArray<int> A(5);
	TArray<char> B;
	TArray<char> C(10);

	std::cout << "after creation:" << std::endl;
	std::cout << "A: " << A << " " << A.size() << std::endl;
	std::cout << "B: " << B << " " << B.size() << std::endl;
	std::cout << "C: " << C << " " << C.size() << std::endl;

	std::cout << "After modification ([1]):" << std::endl;
	A[1] = 1;
	C[1] = 'a';
	C[2] = 'z';
	C[9] = '!';
	std::cout << A << " " << A.size() << std::endl;
	std::cout << B << " " << B.size() << std::endl;
	std::cout << C << " " << C.size() << std::endl;

	std::cout << "Copy constructing D from A, modifying A and printing both (A, D):" << std::endl;
	TArray<int> D(A);
	A[1] = 2;
	std::cout << A << " " << A.size() << std::endl;
	std::cout << D << " " << D.size() << std::endl;
	std::cout << "Trying to access the empty initialized B in position B[1] should result in an error:" << std::endl;
	try { B[1] = 'a';}
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	std::cout << "Exiting program safely" << std::endl;
	return(0);
}
