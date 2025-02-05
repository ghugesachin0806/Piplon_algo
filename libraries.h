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


// Annexure - 1
#define NO_BATTERS (18)
// Annexure - 2
#define NO_BOWLERS (18)
// Annexure - 3
#define COMPOSITION_VARIANT (20)
// Annexure - 4
#define ROTATION_OF_FIELDERS_VARIANT (6)
// Annexure - 5
#define OVERS_PER_PLAYER (6)

// Annexure - 3
typedef struct Composition_fielsers_on_grd
{
    uint32_t variant;
    uint32_t f_batting;
    uint32_t f_bowling;
    uint32_t wicketkeeper;
    bool wkt_bat_org;
    uint32_t total;

} compstn_fldrs_on_grd;

// Annexure - 4
typedef struct Rotation_of_fielder
{
    uint32_t variant;
    uint32_t batters_after_over;
    uint32_t bowlers_after_over;
} rotation_of_fielder;

// Annexure - 5
typedef struct Over_per_player
{
    uint32_t variant;
    uint32_t bowler_bowling;
    uint32_t batsmen_rest;
    uint32_t batsmen_batting;
} over_per_player;

// Annexure - 1
uint8_t no_batters[NO_BATTERS] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

// Annexure - 2
uint8_t no_bowlers[NO_BATTERS] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

// Annexure - 3
compstn_fldrs_on_grd compositions[COMPOSITION_VARIANT] =
    {
        {1, 2, 3, 0, 0, 5},
        {2, 3, 3, 0, 0, 6},
        {3, 3, 4, 0, 0, 7},
        {4, 4, 4, 0, 0, 8},
        {5, 4, 5, 0, 0, 9},
        {6, 5, 5, 0, 0, 10},
        {7, 5, 6, 0, 0, 11},
        {8, 6, 5, 0, 0, 11},
        {9, 7, 4, 0, 0, 11},
        {10, 8, 3, 0, 0, 11},
        {11, 9, 2, 0, 0, 11},
        {12, 10, 1, 0, 0, 11},
        {13, 6, 4, 1, 0, 11},
        {14, 7, 3, 1, 0, 11},
        {15, 8, 2, 1, 0, 11},
        {16, 9, 1, 1, 0, 11},
        {17, 8, 4, 0, 0, 12},
        {18, 9, 3, 0, 0, 12},
        {19, 10, 2, 0, 0, 12},
        {20, 11, 1, 0, 0, 12}};

// Annexure - 4
rotation_of_fielder rotaions[ROTATION_OF_FIELDERS_VARIANT] = {
    {1, 1, 1},
    {2, 2, 1},
    {3, 2, 2},
    {4, 3, 1},
    {5, 3, 3},
    {6, 4, 4}};

// Annexure - 5
over_per_player over_per_players[OVERS_PER_PLAYER] = {
    {1, 1, 1, 1},
    {2, 2, 2, 2},
    {3, 3, 3, 3},
    {4, 4, 4, 4},
    {5, 5, 5, 5},
    {6, 6, 6, 6}};
