#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void BucketSort(float collection[], int n)
{
    vector<float> bucket[n];
    for (int i = 0; i < n; ++i)
    {
        int bucketIndex = n * collection[i];
        bucket[bucketIndex].push_back(collection[i]);
    }

    for (int x = 0; x < n; ++x)
        sort(bucket[x].begin(), bucket[x].end());
        
    int index = 0;
    for (int a = 0; a < n; ++a)
    {
        for (int b = 0; b < bucket[a].size(); ++b)
        {
            collection[index++] = bucket[a][b];
        }
    }
}

int main()
{
    // Array to Sort
    float numbers[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434, 0.538, 0.1};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    BucketSort(numbers, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << numbers[i] << std::endl;
    }
    //std::cin.get();
    return 0;
}