#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

// ---------- yardimcilar ----------

// Diziyi const referansla alir: size() ve operator[] const nesnede calismali.
template <typename T>
void printArray(std::string const& name, Array<T> const& arr)
{
	std::cout << name << " (size " << arr.size() << "): ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << "[" << arr[i] << "]";
	std::cout << std::endl;
}

// Sinir disi bir indekse yazmayi dener: exception atilmali.
template <typename T>
void tryAccess(std::string const& label, Array<T>& arr, int idx)
{
	try
	{
		arr[idx] = T();
		std::cout << "  BASARISIZ: " << label << " exception atmadi!" << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << "  OK: " << label << " -> " << e.what() << std::endl;
	}
}

static void title(std::string const& t)
{
	std::cout << std::endl << "=== " << t << " ===" << std::endl;
}

// ---------- testler ----------

int main(void)
{
	title("1. Default constructor: bos dizi");
	{
		Array<int> empty;
		std::cout << "size: " << empty.size() << "  (beklenen: 0)" << std::endl;
		tryAccess("empty[0]", empty, 0);
	}

	title("2. Array(n): n eleman, default deger");
	{
		Array<int> nums(5);
		printArray("nums", nums);
		std::cout << "beklenen: 5 tane [0]" << std::endl;

		Array<std::string> strs(3);
		printArray("strs", strs);
		std::cout << "beklenen: 3 tane bos []" << std::endl;

		Array<int> zero(0);
		std::cout << "zero size: " << zero.size() << "  (beklenen: 0)" << std::endl;
	}

	title("3. operator[] ile yazma ve okuma");
	{
		Array<int> nums(5);
		for (unsigned int i = 0; i < nums.size(); i++)
			nums[i] = i * 10;
		printArray("nums", nums);
		std::cout << "beklenen: [0][10][20][30][40]" << std::endl;
	}

	title("4. Copy constructor: derin kopya");
	{
		Array<int> original(3);
		original[0] = 1;
		original[1] = 2;
		original[2] = 3;

		Array<int> copy(original);
		copy[0] = 99;
		original[2] = 77;

		printArray("original", original);
		printArray("copy    ", copy);
		std::cout << "beklenen: original [1][2][77], copy [99][2][3]" << std::endl;
	}

	title("5. Assignment operator: derin kopya + boyut degisimi");
	{
		Array<int> small(2);
		Array<int> big(5);
		for (unsigned int i = 0; i < big.size(); i++)
			big[i] = i + 1;

		small = big;
		small[0] = 42;
		printArray("big  ", big);
		printArray("small", small);
		std::cout << "beklenen: big [1][2][3][4][5], small [42][2][3][4][5]" << std::endl;

		Array<int> tiny(1);
		tiny[0] = 8;
		big = tiny;
		printArray("big  ", big);
		std::cout << "beklenen: big (size 1) [8]" << std::endl;

		Array<int> empty;
		big = empty;
		printArray("big  ", big);
		std::cout << "beklenen: big (size 0)" << std::endl;
	}

	title("6. Self-assignment: a = a");
	{
		Array<int> a(3);
		a[0] = 5;
		a[1] = 6;
		a[2] = 7;

		Array<int>& sameA = a;
		a = sameA;
		printArray("a", a);
		std::cout << "beklenen: [5][6][7]" << std::endl;
	}

	title("7. Sinir disi erisim: exception");
	{
		Array<int> nums(3);
		tryAccess("nums[3]   (size'a esit)", nums, 3);
		tryAccess("nums[100]", nums, 100);
		tryAccess("nums[-1] ", nums, -1);
		std::cout << "beklenen: hepsi OK" << std::endl;
	}

	title("8. const Array: sadece okuma");
	{
		Array<int> nums(3);
		nums[0] = 4;
		nums[1] = 2;
		nums[2] = 0;

		Array<int> const& constRef = nums;
		std::cout << "constRef[1]     = " << constRef[1] << "  (beklenen: 2)" << std::endl;
		std::cout << "constRef.size() = " << constRef.size() << "  (beklenen: 3)" << std::endl;
		try
		{
			std::cout << constRef[5] << std::endl;
			std::cout << "  BASARISIZ: constRef[5] exception atmadi!" << std::endl;
		}
		catch (std::exception const& e)
		{
			std::cout << "  OK: constRef[5] -> " << e.what() << std::endl;
		}
		// Asagidaki satir DERLENMEMELI: const diziye yazmaya calisiyor.
		// Yorumu kaldirip dene, derleyici reddetmeli.
		// constRef[0] = 1;
	}

	title("9. std::string ile");
	{
		Array<std::string> words(3);
		words[0] = "merhaba";
		words[1] = "42";
		words[2] = "istanbul";

		Array<std::string> copy = words;
		copy[1] = "kopya";
		printArray("words", words);
		printArray("copy ", copy);
		std::cout << "beklenen: words [merhaba][42][istanbul], copy [merhaba][kopya][istanbul]" << std::endl;
	}

	title("10. Ic ice: Array<Array<int> >");
	{
		Array<Array<int> > grid(2);
		grid[0] = Array<int>(2);
		grid[1] = Array<int>(3);
		grid[1][2] = 9;

		std::cout << "grid.size()    = " << grid.size() << "  (beklenen: 2)" << std::endl;
		std::cout << "grid[0].size() = " << grid[0].size() << "  (beklenen: 2)" << std::endl;
		std::cout << "grid[1].size() = " << grid[1].size() << "  (beklenen: 3)" << std::endl;
		std::cout << "grid[1][2]     = " << grid[1][2] << "  (beklenen: 9)" << std::endl;
	}

	title("11. Subject testi: 750 rastgele sayi");
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		bool same = true;
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
				same = false;
		}
		std::cout << (same ? "OK: degerler korundu" : "BASARISIZ: degerler bozuldu") << std::endl;
		delete[] mirror;
	}

	std::cout << std::endl;
	return 0;
}
