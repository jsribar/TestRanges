#include <range/v3/all.hpp>

#include <algorithm>
#include <iostream>
#include <vector>


template <typename T>
auto duplicates_of_even(const std::vector<T>& input)
{
	return input | ranges::view::filter([](int n) { return n % 2 == 0; }) | ranges::view::transform([](int n) { return n * 2; });
}

auto sum_of_first_N_squared(int N)
{
	return ranges::accumulate(ranges::view::ints(1) | ranges::view::transform([](int i) { return i * i; }) | ranges::view::take(N), 0);
}

int main()
{
	std::vector<int> numbers = { 1, 2, 3, 4, 5 };
	
	auto results = duplicates_of_even(numbers);

	for (int n : results)
	{
		std::cout << n << std::endl;
	}

	std::cout << sum_of_first_N_squared(10) << std::endl;

	return 0;
}

