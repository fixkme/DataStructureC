#ifndef SEARCH_H
#define SEARCH_H

#define EQ(a, b) ((a) == (b))
#define LQ(a, b) ((a) <= (b))
#define LT(a, b) ((a) <  (b))

#include <vector>

/// 判断 key 在 arr 是否存在，并找到位置
/// 要求：物理存储是有序的，元素也是有序的，不管元素是否重复
int SearchBin(std::vector<int> arr, int key)
{
    int low = 0, high = arr.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] > key)
            high = mid - 1;
        else if (arr[mid] < key)
            low = mid + 1;
        if (arr[mid] == key)
            return mid;
    }
    return -1;
}

#endif
