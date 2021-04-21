#ifndef userUtil
#define userUtil

inline void Compute(int TotalResource, int noOfProcess, int N)
{
    TotalResource = (noOfProcess * (N - 1)) + 1;
    std::cout << "Min. No of resources of Avoid Deadlock in the System : " << TotalResource;
    std::cout << std::endl;
}

#endif