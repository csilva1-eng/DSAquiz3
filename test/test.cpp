#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "interquartile_range.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Example Test Name - Change me!", "[flag]"){
	// instantiate any class members that you need to test here
	int one = 1;

	// anything that evaluates to false in a REQUIRE block will result in a failing test 
	REQUIRE(one == 1); // fix me!

	// all REQUIRE blocks must evaluate to true for the whole test to pass
	REQUIRE(false); // also fix me!
}

TEST_CASE("Test 2", "[flag]"){
	// you can also use "sections" to share setup code between tests, for example:
	int one = 1;

	SECTION("num is 2") {
		int num = one + 1;
		REQUIRE(num == 2);
	};

	SECTION("num is 3") {
		int num = one + 2;
		REQUIRE(num == 3);
	};

	// each section runs the setup code independently to ensure that they don't affect each other
}


TEST_CASE("Function: IQR Negative w/ Positive 6 t3 list", "[made]") {
	std::vector<int> v = {-10, -8, 9, 100, 900, 1000};
	Node* head = nullptr;
	for (int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 908.00);

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

TEST_CASE("Function: IQR 30 terms of fibonacci t3 list", "[made]") {
	std::vector<int> v = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181,
6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229};
	Node* head = nullptr;
	for (int i: v)
		head = insertEnd(head, i);


	REQUIRE(interQuartile(head) == 17698.0);

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}


TEST_CASE("Function: IQR 100 terms from [-100,50] t1 list", "[made]") {
	std::vector<int> v = {-100, -99, -98, -97, -96, -95, -94, -93, -92, -91, -90, -89, -88, -87,
		-86, -85, -84, -83, -82, -81, -80, -79, -78, -77, -76, -75, -74, -73, -72, -71, -70, -69,
		-68, -67, -66, -65, -64, -63, -62, -61, -60, -59, -58, -57, -56, -55, -54, -53, -52, -51,
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
		25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
		48, 49, 50};
	Node* head = nullptr;
	for (int i: v)
		head = insertEnd(head, i);


	REQUIRE(interQuartile(head) == 101.0);

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

TEST_CASE("Function: IQR All Negative t2 list", "[made]") {
	std::vector<int> v = {-900, -879, -830, -820, -814, -730, -640, -637, -65, -64, -63, -62, -61, -60, -59, -58, 0};
	Node* head = nullptr;
	for (int i: v)
		head = insertEnd(head, i);


	REQUIRE(interQuartile(head) == 756.5);

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

TEST_CASE("Function: IQR Near max int t4 list", "[made]") {
	std::vector<int> v = {2147483500, 2147483524, 2147483547, 2147483587, 2147483598, 2147483600, 2147483612};
	Node* head = nullptr;
	for (int i: v)
		head = insertEnd(head, i);


	REQUIRE(interQuartile(head) == 76.00);

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
// you must write 5 unique, meaningful tests for credit on the testing portion of this quiz!

// the provided tests from edugator are below. Note that you must determine the correct output for the [output_hidden] tests yourself

TEST_CASE("Function: IQR 1", "[given]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 3.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 2", "[given]") {
	std::vector<int> v = {1, 2, 3, 4};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// uncomment these and put the correct values in the REQUIRE blocks

 TEST_CASE("Function: IQR 3", "[output_hidden]") {
	std::vector<int> v = {1, 8, 15, 43, 82, 101, 110, 2456, 55345, 137556};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2441.0);

    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

 TEST_CASE("Function: IQR 4", "[output_hidden]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8, 9, 10};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 4.5);

    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

 TEST_CASE("Function: IQR 5", "[output_hidden]") {
	std::vector<int> v = {1, 8, 15, 43, 82, 101, 110, 2456, 55345, 137556, 137576};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 55330);

    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
