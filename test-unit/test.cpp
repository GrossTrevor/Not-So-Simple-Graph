#include "../src/not_so_simple_graph.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
	To check output (At the not_so_simple_graph directory):
		g++ -std=c++14 -Werror -Wuninitialized -o test test-unit/test.cpp && ./test
*/

TEST_CASE("Function: sumEdge", "[unit]") 
{
	Graph g;

	g.insertEdge(0, 0, 10);
	g.insertEdge(0, 1, 20);
	g.insertEdge(0, 2, 30);

	std::vector<int> expected_weight = {20};
	std::vector<int> expected_adjacent = {0, 1, 2};

	REQUIRE(g.isEdge(0, 0) == 1);
	REQUIRE(g.sumEdge(0, 2) == 30);
	REQUIRE(g.getWeight(0, 1) == expected_weight);
	REQUIRE(g.getAdjacent(0) == expected_adjacent);
}

TEST_CASE("Function: single", "[unit]")
{
	Graph g;

	g.insertEdge(0, 0, 10);

	std::vector<int> expected_weight = { 10 };
	std::vector<int> expected_adjacent = { 0 };

	REQUIRE(g.isEdge(0, 0) == 1);
	REQUIRE(g.sumEdge(0, 0) == 10);
	REQUIRE(g.getWeight(0, 0) == expected_weight);
	REQUIRE(g.getAdjacent(0) == expected_adjacent);
}

TEST_CASE("Function: dupe", "[unit]")
{
	Graph g;

	g.insertEdge(0, 0, 10);
	g.insertEdge(0, 0, 10);

	std::vector<int> expected_weight = { 10, 10 };
	std::vector<int> expected_adjacent = { 0 };

	REQUIRE(g.isEdge(0, 0) == 1);
	REQUIRE(g.sumEdge(0, 0) == 20);
	REQUIRE(g.getWeight(0, 0) == expected_weight);
	REQUIRE(g.getAdjacent(0) == expected_adjacent);
}

TEST_CASE("Function: 69", "[unit]")
{
	Graph g;

	g.insertEdge(0, 0, 96);
	g.insertEdge(0, 1, 574);
	g.insertEdge(9, 0, 20);
	g.insertEdge(0, 9, 21);
	g.insertEdge(6, 9, 69);
	g.insertEdge(4, 2, 0);

	std::vector<int> expected_weight = { 69 };
	std::vector<int> expected_adjacent = { 0, 1, 9 };

	REQUIRE(g.isEdge(2, 4) == 0);
	REQUIRE(g.sumEdge(0, 9) == 21);
	REQUIRE(g.getWeight(6, 9) == expected_weight);
	REQUIRE(g.getAdjacent(0) == expected_adjacent);
}