
#include <iostream>
#include <cassert>

#include "maxdefense.hh"
#include "timer.hh"
using namespace std;

void check_greedy(const ArmorVector& armors){
	Timer timer;
	auto run = greedy_max_defense(armors, 5000);
	double elapsed = timer.elapsed();
	cout << "Greedy elapsed time in seconds: " << elapsed << endl;
	timer.reset();
}

void check_exhaustive(const ArmorVector& armors){
	Timer timer;
	auto run = exhaustive_max_defense(armors, 5000);
	double elapsed = timer.elapsed();
	cout << "Exhaustive elapsed time in seconds: " << elapsed << endl;
	timer.reset();
}

int main()
{
	int n;
	
	auto all_armors = load_armor_database("armor.csv");
	assert( all_armors );
	
	cout << "Enter a value of n: ";
	cin >> n;
	cout << endl;
	
	while(n > 0){
		auto filtered_armors = filter_armor_vector(*all_armors, 1, 2500, n);
		//print_armor_vector(*filtered_armors);    // displays the the entire list of armors in the filtered inventory.
	
		check_greedy(*filtered_armors);            //switch between greedy and exhaustive for tests.
		//check_exhaustive(*filtered_armors);
		
		cout << "Enter a value of n, 0 to end: ";
		cin >> n;
		cout << endl;
	}
	
	return 0;
}


