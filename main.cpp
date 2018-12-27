#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

int main( ) {
    // create the vars
    std::vector< int > numbers { };
    auto amount_number = 0u;

    // ask for the users input
    std::cout << "how many numbers would you like to enter?\n";
    std::cin >> amount_number;

    std::cout << "please enter " << amount_number << " numbers please\n";
    for( auto i = 0u; i < amount_number; ++i ) {
        int input;
        std::cin >> input;
        // store into the vector we created before
        numbers.push_back( input );
    }

    std::make_heap( numbers.begin( ), numbers.end( ) );
    // now you may be asking yourself "why std::copy"
    // my reasoning is simple i prefer the look of it
    // did a quick look at the asm for other ways all did the exact same thing
    std::copy( numbers.begin( ), numbers.end( ), std::ostream_iterator< int >( std::cout, " " ) );
    std::cout << "\n";

    std::sort_heap( numbers.begin( ), numbers.end( ) );
    std::cout << "sorted numbers:\n";
    std::copy( numbers.begin( ), numbers.end( ), std::ostream_iterator< int >( std::cout, " " ) );
    std::cout << "\n";

    // go ahead and make a copy before we remove anything
    auto copy = numbers;

    std::cout << "lets go ahead and swap the last number with the first\n";
    std::pop_heap( numbers.begin( ), numbers.end( ) );

    std::cout << "now lets remove the last number in the vector\n";
    numbers.pop_back( );
    std::copy( numbers.begin( ), numbers.end( ), std::ostream_iterator< int >( std::cout, " " ) );
    std::cout << "\n";

    std::random_device rand_device;
    std::mt19937 gen( rand_device( ) );

    std::cout << "now shuffle the heap\n";
    std::shuffle( copy.begin( ), copy.end( ), gen );
    std::copy( copy.begin( ), copy.end( ), std::ostream_iterator< int >( std::cout, " " ) );


    return 1;
}