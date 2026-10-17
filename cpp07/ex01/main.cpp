#include "iter.hpp"
#include <iostream>
#include <string>

// ---------- iter'a verilecek fonksiyonlar ----------

// Function template: iter'a print<int> gibi instantiate edilerek verilir.
// Elemani const referansla alir, sadece okur.
template <typename T>
void print(T const& x)
{
	std::cout << x << " ";
}

// Function template: elemani non-const referansla alir ve degistirir.
template <typename T>
void doubleIt(T& x)
{
	x = x + x;
}

// Normal (template olmayan) fonksiyon: elemani degistirir.
void addOne(int& x)
{
	x += 1;
}

// Normal fonksiyon: const elemani sadece okur.
void printChar(char const& c)
{
	std::cout << "[" << c << "]";
}

// ---------- testler ----------

int main(void)
{
	int			nums[] = {1, 2, 3, 4, 5};
	const int	constNums[] = {10, 20, 30};
	std::string	words[] = {"ab", "cd", "ef"};
	char		letters[] = {'4', '2'};

	std::cout << "=== 1. int dizi, const ref ile okuma (print<int>) ===" << std::endl;
	iter(nums, 5, print<int>);
	std::cout << std::endl << "beklenen: 1 2 3 4 5" << std::endl << std::endl;

	std::cout << "=== 2. int dizi, non-const ref ile degistirme (addOne) ===" << std::endl;
	iter(nums, 5, addOne);
	iter(nums, 5, print<int>);
	std::cout << std::endl << "beklenen: 2 3 4 5 6" << std::endl << std::endl;

	std::cout << "=== 3. int dizi, template ile degistirme (doubleIt<int>) ===" << std::endl;
	iter(nums, 5, doubleIt<int>);
	iter(nums, 5, print<int>);
	std::cout << std::endl << "beklenen: 4 6 8 10 12" << std::endl << std::endl;

	std::cout << "=== 4. const int dizi, okuma (print<int>) ===" << std::endl;
	iter(constNums, 3, print<int>);
	std::cout << std::endl << "beklenen: 10 20 30" << std::endl << std::endl;
	// Asagidaki satir DERLENMEMELI: const elemani degistirmeye calisiyor.
	// Yorumu kaldirip dene, derleyici reddetmeli.
	// iter(constNums, 3, addOne);

	std::cout << "=== 5. non-const dizi, print<const int> ===" << std::endl;
	iter(nums, 5, print<const int>);
	std::cout << std::endl << "beklenen: 4 6 8 10 12" << std::endl << std::endl;

	std::cout << "=== 6. std::string dizi, degistir + oku ===" << std::endl;
	iter(words, 3, doubleIt<std::string>);
	iter(words, 3, print<std::string>);
	std::cout << std::endl << "beklenen: abab cdcd efef" << std::endl << std::endl;

	std::cout << "=== 7. char dizi, normal fonksiyon (printChar) ===" << std::endl;
	iter(letters, 2, printChar);
	std::cout << std::endl << "beklenen: [4][2]" << std::endl << std::endl;

	std::cout << "=== 8. uzunluk 0 ===" << std::endl;
	iter(nums, 0, print<int>);
	std::cout << std::endl << "beklenen: (ustteki satir bos)" << std::endl;

	return 0;
}
