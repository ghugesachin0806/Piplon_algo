// Standard I/O & Utilities
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

// Data Structures & Containers
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// Algorithms & Functions
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>

// String Manipulation
#include <string>
#include <cstring>

// Math & Random
#include <cmath>
#include <random>

// Concurrency & Multithreading
#include <thread>
#include <mutex>
#include <future>

// Other Libraries
#include <bitset>
#include <limits>
#include <climits>
#include <cassert>

// Annexure - 0
#define MAX_OVERS_ALLOWED (50)

// Annexure - I
#define MIN_BATSMEN (3)
#define MAX_BATSMEN (20)

// Annexure - II
#define MIN_BOWLERS (3)
#define MAX_BOWLERS (20)

// Annexure - III

// custom lcm function
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
