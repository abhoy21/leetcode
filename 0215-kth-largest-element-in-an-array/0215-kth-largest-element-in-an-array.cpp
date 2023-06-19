class Solution
{
public:
    void swap_val(int &x, int &y)
        {
            int temp = x;
            x = y;
            y = temp;
        }

    int partition_arr(vector<int> & nums, int left, int right)
        {

            int i = left;
            int pivotElement = nums[right];

            for (int j = left; j < right; j++)
            {
                if (nums[j] < pivotElement)
                {
                    swap_val(nums[i], nums[j]);
                    i++;
                }
            }
            swap_val(nums[i], nums[right]);

            return i;
        }

    int kthLargest(vector<int> &nums, int k)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (true)
        {
            int pivotindx = partition_arr(nums, left, right);
            if (pivotindx == (nums.size() - k))
                return nums[pivotindx];
            else if (pivotindx < (nums.size() - k))
                left = pivotindx + 1;
            else
                right = pivotindx - 1;
        }
    }
    int findKthLargest(vector<int> &nums, int k)
    {

        return kthLargest(nums,k);
        
    }
};