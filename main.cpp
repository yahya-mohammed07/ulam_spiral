#include <iostream>
#include <Kraken/all.hpp> /// @link https://github.com/yahya-mohammed07/Kraken

using namespace kraken;

enum directions {
  right,  // 0
  up,     // 1
  left,   // 2
  down    // 3
};

auto main() -> int
{
  matrix_<char, 213, 213> arr{};
  auto x        {arr.row() / 2};
  auto y        {arr.col() / 2};
  //
  auto step     { 1U };
  auto num_steps{ 1U };
  auto turn     { 1U };
  auto state    { 0U }; // state of direction
  //
  for ( [[maybe_unused]] const auto &i : arr ) {
    arr.at( x,y ) = cal::is_prime(step) ? '*' : ' ';
    //
    switch ( state ) {
      case directions::right: {
        ++y; break;
      }
      case directions::up: {
        --x; break;
      }
      case directions::left: {
        --y; break;
      }
      case directions::down: {
        ++x; break;
      }
    }
    if ( !(step % num_steps) ) { // state % num_steps == 0
      state = ( state + 1 ) % 4; // set it to `0` if state is `4`
      ++turn; // turn each two steps
      if ( !(turn & 1) ) { // need to increase arrows `1-> 2 -> 3 ->4->5`
        ++num_steps;
      }
    }
    ++step;
  }
  std::cout << arr;
}