#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Array
{
public:
    /*
        Description :给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索
        nums 中的 target，如果目标值存在返回下标，否则返回 -1。
        Solution : 二分查找法
    */
    int search(std::vector<int>& nums, int target) {
        if (nums.size() <= 0) return -1;
        //if ((target < nums.at(0)) || (target > nums.at(nums.size() - 1))) return -1;

        int low = 0;//1
        int high = nums.size() - 1;//2

        while (low <= high) {
            //int mid = (low + high) / 2;//需要做防溢出处理
            int mid = low + ((high - low) / 2);
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }
    void search_run() {
        std::vector<int> m_nums{ -1,0,3,5,9,12 };
        std::cout << search(m_nums, 9) << std::endl;
        std::cout << search(m_nums, -56) << std::endl;

    }
    //苏州月亮湾营业部。推荐人21310014
    /*
    给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
    solution:使用双指针法，快慢指针法
    */
    int removeElement(std::vector<int>& nums, int val) {

        int low = 0;
        int fast = 0;
        for (fast = 0; fast < nums.size(); fast++) {
            if (nums.at(fast) != val) {
                nums[low++] = nums[fast];
            }
        }
        return low;
    }
    void removeElement_run() {
        std::vector<int> m_nums{1};
        int count = removeElement(m_nums, 2);
        for (auto itor : m_nums) {
            std::cout << itor << " ";
        }
        std::cout << std::endl << "count" << count<<std::endl;
    }

    /*给定一个含有 n 个正整数的数组和一个正整数 target 。
    找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
    并返回其长度。如果不存在符合条件的子数组，返回 0 。
        solution:两种方法，暴力法和滑动窗口法
    */
    //暴力法
    int minSubArrayForce(int s, std::vector<int>& nums) {
        int size = INT_MAX;
        int sum = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            while (sum >= s) {
                int length = (i - j + 1);
                size = size > length ? length : size;
                sum -= nums[j++];
            }
        }
        return size == INT_MAX ? 0 : size;
    }
    void minSubArrayForce_run() {
        std::vector<int> m_nums{ 13};
        int count = minSubArrayForce(12,m_nums);
        std::cout << std::endl << "count" << count << std::endl;
    }

    /*
        给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
    */
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> nums(n, std::vector<int>(n, 0));
        int loop = n / 2;
        int start = 0;
        int offset = 1;
        int x, y ,temp;
        int count = 1;
        while (loop--) {
            x = y = start;
            temp = n - (start + offset);
            for (int i = 0; i < temp; i++) {
                nums[x][y++] = count++;
            }
            for (int i = 0; i < temp; i++) {
                nums[x++][y] = count++;
            }
            for (int i = 0; i < temp; i++) {
                nums[x][y--] = count++; 
            }
            for (int i = 0; i < temp; i++) {
                nums[x--][y] = count++;
            }
            start++;
            offset++;
        }
        if (n % 2 != 0) {
            nums[n / 2][n / 2] = count;
        }
        return nums;
    }
    void generateMatrix_run() {
        auto result = generateMatrix(5);
        for (auto itor : result) {
            for (auto i : itor) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    }

};

class ArrayTest {
public:
    ArrayTest() {}
    ~ArrayTest(){}





};