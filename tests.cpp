// =================================================================
//
// File: tests.cpp
// Author: Pedro Perez
// Description: This file implements various tests on the
//				implemented code.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include "heap.h"
#include "heapsort.h"
#include "priority_queue.h"

TEST_CASE( "Testing heap implementation", "[Heap]" ) {
	Priority_queue<int> heap(3);

	SECTION( "1: Testing if the heap is empty." ) {
		REQUIRE(heap.empty() == true);
	}

	SECTION( "2: Checking size of heap." ) {
		heap.add(10); heap.push(1);

		REQUIRE(heap.size() == 2);
	}

	SECTION( "3: Putting an element in the heap." ) {
		heap.push(10);
		REQUIRE(strcmp(heap.toString().c_str(), "[10]") == 0);
		heap.push(1);
		REQUIRE(strcmp(heap.toString().c_str(), "[1 10]") == 0);
		heap.push(5);
		REQUIRE(strcmp(heap.toString().c_str(), "[1 10 5]") == 0);
		REQUIRE_THROWS_AS(heap.push(11), Overflow);
	}

	SECTION( "4: Removing an element in the heap." ) {
		int x;

		heap.push(10); heap.push(1); heap.push(5);
		CHECK(strcmp(heap.toString().c_str(), "[1 10 5]") == 0);
		heap.clear();
		REQUIRE(strcmp(heap.toString().c_str(), "[]") == 0);
	}

	SECTION( "5: Removing an element in the heap." ) {
		int x;

		heap.push(10); heap.push(1); heap.push(5);

		x = heap.pop();
		REQUIRE(strcmp(heap.toString().c_str(), "[5 10]") == 0);
		x = heap.pop();
		REQUIRE(strcmp(heap.toString().c_str(), "[10]") == 0);
		x = heap.pop();
		REQUIRE(strcmp(heap.toString().c_str(), "[]") == 0);
		REQUIRE_THROWS_AS(heap.pop(), NoSuchElement);
	}
}

TEST_CASE( "Testing heap sort", "[heapSort]" ) {
	int output[] = {1, 2, 16, 24, 29, 30, 42, 45, 49, 56, 63, 76, 77, 82, 89, 92, 93, 93, 94, 94};

	SECTION( "1: Worst scenario." ) {
		int input[] = {94, 94, 93, 93, 92, 89, 82, 77, 76, 63, 56, 49, 45, 42, 30, 29, 24, 16, 2, 1};

		heapSort(input, 20);
		REQUIRE(strcmp(arr2str(input, 20).c_str(), arr2str(output, 20).c_str()) == 0);
	}

	SECTION( "2: Average scenario." ) {
		int input[] = {92, 1, 76, 89, 94, 30, 16, 24, 77, 93, 45, 56, 94, 93, 63, 29, 42, 82, 49, 2};

		heapSort(input, 20);
		REQUIRE(strcmp(arr2str(input, 20).c_str(), arr2str(output, 20).c_str()) == 0);
	}

	SECTION( "3: Best scenario." ) {
		int input[] = {1, 2, 16, 24, 29, 30, 42, 45, 49, 56, 63, 76, 77, 82, 89, 92, 93, 93, 94, 94};

		heapSort(input, 20);
		REQUIRE(strcmp(arr2str(input, 20).c_str(), arr2str(output, 20).c_str()) == 0);
	}
}
