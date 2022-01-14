#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        vector<int> result = {-1, -1};

        if (nums.empty())
        {
            return result;
        }

        result[0] = leftMostELement(nums, target);
        result[1] = rightMostELement(nums, target);

        return result;
    }

    int leftMostELement(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int midpoint;
        int index = -1;

        while (left <= right)
        {
            midpoint = left + (right - left) / 2;

            if (nums[midpoint] >= target)
            {
                right = midpoint - 1;
            }
            else
            {
                left = midpoint + 1;
            }

            if (nums[midpoint] == target)
            {
                index = midpoint;
            }
        }

        return index;
    }

    int rightMostELement(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int midpoint;
        int index = -1;

        while (left <= right)
        {
            midpoint = left + (right - left) / 2;

            if (nums[midpoint] <= target)
            {
                left = midpoint + 1;
            }
            else
            {
                right = midpoint - 1;
            }

            if (nums[midpoint] == target)
            {
                index = midpoint;
            }
        }

        return index;
    }
};

int FindLastIndex(vector<int> &vec, const int &ele)
{
    int result = -1;
    int high = vec.size() - 1;
    int low = 0;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        cout << "mid=" << mid << "high=" << high << "low=" << low << endl;
        if ((vec[mid] == ele) && ((mid == 0) || (vec[mid] != vec[mid + 1])))
        {
            return mid;
        }

        if (vec[mid] >= ele)
        {
            high = mid + 1;
        }
        else
        {
            low = mid - 1;
        }
    }
    return result;
}
int main()
{
    vector<int> test = {1, 2, 2, 4, 5, 6};
    cout << FindLastIndex(test, 2) << endl;
}