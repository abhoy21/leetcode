/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let value = init;
    for(let i = 0; i < nums.length; i++){
        value = fn(value, nums[i]);
    }

    return value;
};