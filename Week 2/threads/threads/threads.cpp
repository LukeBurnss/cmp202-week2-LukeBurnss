// Simple threading example
// Adam Sampson <a.sampson@abertay.ac.uk>

#include <chrono>
#include <iostream>
#include <thread>

// Import things we need from the standard library
using std::chrono::milliseconds;
using std::cout;
using std::endl;
using std::ofstream;
using std::this_thread::sleep_for;
using std::thread;

struct ThreadArgs {
	int foo, bar;
};

void myThreadFunc(int id, int delay)
{
	
	//cout << "I am myThreadFunc\n";
	//cout << args->foo << endl;
	//cout << args->bar << endl;
	//args->foo = 10;

	for (int i = 0; i < 10; i++)
	{
		id = i;
		sleep_for(milliseconds(delay));
		cout << "ID:" << id << endl;
	}
	

}

int main(int argc, char *argv[])
{
	// At the moment our program is only running one thread (the initial one the operating system gave us).

	ThreadArgs args = { 7,9 };

	int delay = 500;
	int id = 5;

	//std::thread* IDs;
	const int num_threads = 5;
	thread* threads[num_threads];

	for (int i = 0; i < num_threads; i++)
	{
		int delay = 500 + i * 100; // Calculates delay from 500 to 900
		threads[i] = new thread(myThreadFunc, i, delay);
	}
		

	// Now our program is running two threads in parallel (the initial one, and myThread).
	
	cout << "I am main\n";

	// Wait for myThread to finish.
	for (int i = 0; i < num_threads; i++)
	{
		threads[i]->join();
		delete threads[i]; // Clean up
	}

	// Now we just have the initial thread. So it's safe to exit.

	cout << "All done\n\n";
	sleep_for(milliseconds(3));

	cout << args.foo << endl;
	cout << args.bar << endl;


	return 0;
}
