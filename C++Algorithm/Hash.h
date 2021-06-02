#pragma once
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>


using std::string;
using std::cout;
using std::endl;
class Hash
{
public:
    /**
        给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
        示例 1:
        输入: s = "anagram", t = "nagaram"
        输出: true
        示例 2:
        输入: s = "rat", t = "car"
        输出: false
        说明:
        你可以假设字符串只包含小写字母。
    */
    bool isAnagram(string s, string t) {
        char arr[26] = { 0 };
        for (auto itor : s) {
            arr[itor - 'a'] += 1;
        }
        for (auto itor : t) {
            arr[itor - 'a'] -= 1;
        }

        int sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += abs(arr[i]);
        }
        

        return !sum;

        /*
        for(int i = 0; i < 26; i++){
            if(arr[i] != 0) return false;

        return true;
        */
    }


    /**
        给定两个数组，编写一个函数来计算它们的交集。
        示例 1：
        输入：nums1 = [1,2,2,1], nums2 = [2,2]
        输出：[2]
        示例 2：
        输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
        输出：[9,4]
    */
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::map<int, int> hashmap;
        for (int itor : nums1) {
            hashmap[itor] = 1;
        }
        for (int itor : nums2) {
            if (hashmap.find(itor) != hashmap.end()) {
                hashmap[itor] += 1;
            }
        }
        std::vector<int> result;
        for (auto itor : hashmap) {
            if (itor.second != 1) {
                result.push_back(itor.first);
            }
        }
        return result;
    }

    /**
        编写一个算法来判断一个数 n 是不是快乐数。
        「快乐数」定义为：
        对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
        然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
        如果 可以变为  1，那么这个数就是快乐数。
        如果 n 是快乐数就返回 true ；不是，则返回 false 。
        示例 ：
        输入：19
        输出：true
        解释：
        12 + 92 = 82
        82 + 22 = 68
        62 + 82 = 100
        12 + 02 + 02 = 1
    */
    
    int getNum(int num) {
        int s = num;
        int sum = 0;
        do {
            int t = s % 10;
            sum += t * t;
            s = s / 10;
        } while (s > 0);
        return sum;
    }
    bool isHappy(int num) {
        int temp = num;
        std::unordered_set<int> result;
        auto f = [](int num)->int {
            int s = num;
            int sum = 0;
            do {
                int t = s % 10;
                sum += t * t;
                s = s / 10;
            } while (s > 0);
            return sum;
        };
        while (true) {
            temp = f(temp);
            if (temp == 1)return true;
            else if (result.count(temp) != 0) {
                return false;
            }else {
                result.insert(temp);
            }
        }

    }

    /**
        给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 
        的那 两个 整数，并返回它们的数组下标。
        你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
        你可以按任意顺序返回答案。
        输入：nums = [2,7,11,15], target = 9
        输出：[0,1]
        解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
    */
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            if (map.find(temp) != map.end()) {
                return std::vector<int>{i, map.find(temp)->second};
            }
            else {
                map.insert(std::pair<int, int>(nums[i], i));
            }
       }
        return {};
    }

    /**
        给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) 
        ，使得 A[i] + B[j] + C[k] + D[l] = 0。
        为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 
        。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
        例如:

        输入:
        A = [ 1, 2]
        B = [-2,-1]
        C = [-1, 2]
        D = [ 0, 2
    */
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
       /*
        思路：
        首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
        遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
        定义int变量count，用来统计a+b+c+d = 0 出现的次数。
        在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
        最后返回统计值 count 就可以了
       */
        std::unordered_map<int, int> map;
        for (auto it : nums1) {
            for (auto it1 : nums2) {
                map[it1 + it] ++;
            }
        }

        int count = 0;
        for (auto it : nums3) {
            for (auto it1 : nums4) {
                auto itor = map.find((0 - it - it1));
                if (itor != map.end()) {
                    count += itor->second;
                }
            }
        }
        return count;
    }

    //赎金信
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> map;
        for (int i = 0; i < magazine.size(); i++) {
            map[magazine[i]] += 1;
        }
        for (auto itor : ransomNote) {
            map[itor] -= 1;
            if (map[itor] < 0) {
                return false;
            }
        }

        //for (auto itor : map) {
        //    if (itor.second < 0) {
        //        return false;
        //    }
        //}
        return true;
    }
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        for (auto i = 0; i < nums.size(); i++) {
            for (auto j = i + 1; j < nums.size(); j++) {
                for (auto z = j + 1; z < nums.size(); z++) {

                }
            }
        }
    }

};

class HashTest {
public:
    void canConstructTest() {
        Hash hash;
        cout << hash.canConstruct("aa","acb");
    }
    void fourSumCountTest() {
        Hash hash;
        std::vector<int> nums1{ 1, 2 };
        std::vector<int> nums2{ -2,-1};
        std::vector<int> nums3{ -1,2 };
        std::vector<int> nums4{ 0,2 };
        cout<< hash.fourSumCount(nums1, nums2, nums3, nums4);

    }
    void twoSumTest() {
        Hash hash;
        std::vector<int> nums{ 2,7,11,15 };
        auto result = hash.twoSum(nums, 2);
        for (auto itor : result) {
            cout << itor << " ";
        }
        cout << endl;
    }
    void isHappyTest() {
        Hash hash;
        cout << "arg0: [19]" << endl;
        cout << "expect = 1" << endl;
        cout << "actually " << hash.isHappy(3) << endl;
    }
    void isAnagramTest() {
        Hash hash;
        cout << "arg0 = \"anagram\", arg1 = \"naagram\" , expect = 1, actually = " << hash.isAnagram("anagram", "naagram") << endl;
        cout << "arg0 = \"rat\", arg1 = \"crt\" , expect = 0, actually = " << hash.isAnagram("rat", "crt") << endl;

    }
    void intersectionTest() {
        Hash hash;
        std::vector<int> nums1{ 1,2,2,1 };
        std::vector<int> nums2{ 2,2 };
        std::cout << "arg0 : { 1, 2, 2, 1 }  arg1 : { 2, 2 }" << endl;
        std::cout << "expect: { 2 }" << std::endl;

        auto result = hash.intersection(nums1, nums2);
        std::cout << "actually : { ";
        for (auto i : result) {
            std::cout << i<<" " ;
        }
        std::cout << "}"<<std::endl;


        std::vector<int> nums3{ 4, 9, 5 };
        std::vector<int> nums4{ 9, 4, 9, 8, 4 };
        std::cout << "arg0 : { 4, 9, 5 }  arg1 : { 9, 4, 9, 8, 4 }" << endl;
        std::cout << "expect: { 4, 9 }" << std::endl;

        auto result1 = hash.intersection(nums3, nums4);
        std::cout << "actually : { ";
        for (auto i : result1) {
            std::cout << i << " ";
        }
        std::cout << "}" << std::endl;
    }
    void run() {
        //isAnagramTest();
        //intersectionTest();
       // isHappyTest();
        //twoSumTest();
        //fourSumCountTest();
        canConstructTest();
    }
};