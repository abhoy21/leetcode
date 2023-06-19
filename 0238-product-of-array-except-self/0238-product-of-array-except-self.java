class Solution {
  public int[] productExceptSelf(int[] nums) {
    int s = nums.length;
    int[] a = new int[s];
    a[0] = 1;
    for (int i = 1; i < s; ++i)
      a[i] = a[i - 1] * nums[i - 1];
    int p = 1;
    for (int i = s - 1; i >= 0; --i) 
    {
      a[i] *= p;
      p *= nums[i];
    }
    return a;
  }
}