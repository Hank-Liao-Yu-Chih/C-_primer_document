#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<vector<int>> ivec;	// ok
	//vector<string> svec = ivec; // error,  error: conversion from ‘vector<std::vector<int>>’ to non-scalar type ‘vector<std::__cxx11::basic_string<char>>’ requested
	vector<string> svec(10, "null"); //ok

	return 0;
}