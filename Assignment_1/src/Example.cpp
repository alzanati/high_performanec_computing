#include <Example.h>

Example::Example()
{

}

void Example::helloWorld()
{
    int thread_num_now = 0;
    int np = 0;
    int max = 0;

    /* start using omp */
#if defined ( _OPENMP )

    max = omp_get_max_threads(); // max number of threads
    omp_set_num_threads(4); // number of threads will be used = 2

    /* parallel region */
#pragma omp parallel private( thread_num_now)
    {
        thread_num_now = omp_get_thread_num();
        printf("hello multicore user! thread %i\n", thread_num_now);
        ++np;
    }

#endif

    /* print total number of threads */
    printf("number of threads has been used %i\n", np);
    printf("max number of threads %i\n", max);
}

void Example::forloop()
{

}
