/*
 * @author:Mohamed Hosny Ahmed
 * @date: 10 / 7 / 2016
 * @purpose: BenchMarking an algorithm in c++ code between start and end macros
 */

#include <stdio.h>
#include <stdlib.h>
#include <chrono>

class BenchMarking
{
public:
    /**
     * @brief BenchMarking
     */
    BenchMarking();

    /**
     * @brief startTimer
     */
    void startTimer();

    /**
     * @brief endTimer
     */
    void endTimer();

    /**
     * @brief print time in milliseconds
     */
    void printMilliSeconds();

    /**
     * @brief return execution time of algorithm
     */
    auto getEllapsedTime();

    /**
     * @brief static variable to access and use algorithm execution time
     */
    static long int EllapsedTime;

private:
    /**
     * @brief start_ to store start point time
     */
    std::chrono::high_resolution_clock::time_point start_;

    /**
     * @brief end_ to store end point time
     */
    std::chrono::high_resolution_clock::time_point end_;
};

long int BenchMarking::EllapsedTime = 0;

BenchMarking::BenchMarking()
{

}

void BenchMarking::startTimer()
{
    start_ = std::chrono::high_resolution_clock::now();
}

void BenchMarking::endTimer()
{
    end_ = std::chrono::high_resolution_clock::now();
}

auto BenchMarking::getEllapsedTime()
{
    auto ellapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_).count();
    EllapsedTime = ellapsedTime;
    return ellapsedTime;
}

void BenchMarking::printMilliSeconds()
{
    printf("%s: %li %s\n", "Time", getEllapsedTime(), " ms" );
}

// macro to define class
#define BENCH_APP
	static BenchMarking* benchApp = new BenchMarking();\

// start BenchMarkinging
#define START(obj)\
    if( obj == "BenchMarking" )\
    {\
        printf("%s\n", "start BenchMarking!!!");\
        benchApp->startTimer();\
    }\
    else\
    {\
    	printf("%s\n", "to BenchMarking your algorithm you should enter BenchMarking" );\
    	exit(-1);\
    }\

// end bench marking
#define END(obj)\
    if( obj == "BenchMarking" )\
    {\
    	benchApp->endTimer();\
    	benchApp->getEllapsedTime();\
    	printf("%s\n", "end BenchMarking!!!");\
    }\
    else\
    {\
    	printf("%s\n", "to BenchMarking your algorithm you should enter BenchMarking" );\
    	exit(-1);\
    }\

// sum array of any numbering type
template <typename T>
T sumArray( T* array, size_t count )
{
	T result = 0;
	while( count != 0 )
	{
		result += array[ count-1 ];
		count--;
	}
	return result;
}

// test application
void unitTest( int argc, char** argv )
{

    size_t avgCount = 0;

    printf("%s", "Enter Number of Tests: ");
    scanf("%lui", &avgCount);

    long int* result = (long int*) malloc( sizeof(long int) * avgCount );

    for( int i = 0; i < avgCount; i++ )
    {
        START("BenchMarking");
                for ( int i = 0; i < 500000000; i++ );
    	END("BenchMarking");
        result[i] = BenchMarking::EllapsedTime;
    }
    printf("%s: %li %s\n", "EllapsedTime", sumArray( result, avgCount ) / avgCount, "ms");
}

int main( int argc, char** argv )
{
    // run test
    unitTest( argc, argv );
    return EXIT_SUCCESS;
}
