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