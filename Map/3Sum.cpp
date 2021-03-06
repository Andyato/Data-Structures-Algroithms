/* leetcode-15 */

#include<unordered_map>
#include<vector>

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        unordered_map<int,int> counter;
        for(int e : nums)
            ++counter[e];

        //去重
        sort(nums.begin(), nums.end());
        vector<int>::iterator iter = unique(nums.begin(), nums.end());//例如[123223311]，此时iter指向第四个元素，即2
        nums.erase(iter, nums.end());

        vector<vector<int>> res;
        if(counter[0] >= 3)
            res.push_back({0,0,0});

        for(int i = 0; i < nums.size(); ++i)
            for(int j = i+1; j < nums.size(); ++j)
            {
                if(nums[i]*2 + nums[j] == 0 && counter[nums[i]] >= 2)
                {
                    res.push_back({nums[i], nums[i], nums[j]});
                }

                if(nums[i] + nums[j]*2 == 0 && counter[nums[j]] >= 2)
                {
                    res.push_back({nums[i], nums[j], nums[j]});
                }

                int c = 0 - nums[i] - nums[j];
                if(counter[c] >= 1 && c > nums[j])
                {
                    res.push_back({nums[i], nums[j], c});
                }
            }

        return res;
    }
};

class Solution2
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        const int n = nums.size();
        for (int i = 0; i < n - 2; ++i)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                    while (l < r && nums[r] == nums[r + 1])
                        --r;
                }
                else if (nums[i] + nums[l] + nums[r] < 0)
                {
                    ++l;
                }
                else
                {
                    --r;
                }
            }
        }
        return ans;
    }
};