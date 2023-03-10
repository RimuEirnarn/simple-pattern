#pragma once
#define not !
#define or ||
#define and &&
#define true 1
#define false 0

// use this if you want
#define start int main(int argc, char **argv)
#define _start(...) int main(int argc, char **argv, ##__VA_ARGS__)
// else if
#define elif else if
// use this too if you use start. Equalivent to end(0)
#define endmain return 0;
// end a function
#define end(value) return value;
// class -> typedef struct
#define class typedef struct
// is value true?
#define iftrue(value) if (value == true)
// generic for loop. Use i to mark as current turn, no start.
#define frange(end) for (int i=0; i <= (end-1); i++)
// generic for loop. Use current to mark as current turn.
#define for_range(end) for (int current=0; current <= (end-1); current++)
// generic for loop. Use i to mark it as current turn.
#define fsrange(start, end) for (int i=start; i <= (end-1); i++)
// generic for loop. Use current to mark it as current turn
/**
 * @brief Generic for-loop range. Verbose version
 * @param start starter, must less than end
 * @param end end? must bigger than start
 */
#define for_srange(start, end) for (int current=start; current <= (end-1); current++)
/**
 * @brief Geneirc for-loop range with step. Use i as current turn.
 * @param start starter, must less than end
 * @param end end, must bigger than start.
 * @param step step, must be a positive integer or it'll be forever loop.
 */
#define fssrange(start, end, step) for (int i=start; i <= (end-1); i+=step)
/**
 * @brief Geneirc for-loop range with step. Verbose version. Use current as current turn
 * @param start starter, must less than end
 * @param end end, must bigger than start.
 * @param step step, must be a positive integer or it'll be forever loop.
 */
#define for_stepsrange(start, end, step) for (int current=start; current <= (end-1); current+=step)
// for loop, end, step.
#define fstrange(end, step) for (int i=0; i <= (end-1); i+=step)
// for loop, end, step.
#define for_steprange(end, step) for (int current=0; current <= (end-1); current+=step)
#define forloop(var, end) for int ((int) ##var=0; ##var <= (end-1); ##var++)

// isn't it a str?
#define str char*
#define str_array char**
// Simple while (true)
#define forever() while (true)
// repeat of (turn) because, why not?
#define repeat(turn) for (int _i___iaefasda = 0; _i___iaefasda <= (turn-1); _i___iaefasda++)