//
// Created by wenwen on 2022/4/18.
//

#include "al_arr.h"
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <climits>

vector<int> twoSum(const vector<int>& nums, int target){
    unordered_map<int, int> mValIdx;
    for(int i = 0; i < nums.size(); ++i){
        int diff = target - nums[i];
        if(mValIdx.count(diff))return {mValIdx[diff], i};

        mValIdx[nums[i]] = i;
    }

    return {};
}


#ifdef USE_3SUM_V1

void threeSumHelper(const vector<int>& nums, int startIdx, int target, vector<vector<int>>& vecVec){
    int beg = startIdx, end = int(nums.size()) - 1;

    while(beg < end){
        int tmp = nums[beg] + nums[end];
        if(tmp < target){
            ++beg;
        }else if(tmp > target){
            --end;
        }else{
            vecVec.push_back({nums[beg++], nums[end--]});
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums){
    std::set<vector<int>> setVec;

    std::stable_sort(nums.begin(), nums.end());
    int len = static_cast<int>(nums.size());

    for(int i = 0; i < len - 2; ++i){
        if(i > 0 and nums[i] == nums[i - 1])continue;

        vector<vector<int>> vecVec;
        int target = -nums[i];
        threeSumHelper(nums, i + 1, target, vecVec);

        for(auto& vec : vecVec){
            vec.insert(vec.begin(), nums[i]);
            setVec.insert(vec);
        }
    }

    vector<vector<int>> vecRes(setVec.begin(), setVec.end());
    return vecRes;
}
#endif

void threeSumHelper(const vector<int>& nums, int startIdx, int target, vector<vector<int>>& vecVec){
    int beg = startIdx, end = int(nums.size()) - 1;

    while(beg < end){
        int tmp = nums[beg] + nums[end];
        if(tmp < target){
            ++beg;
        }else if(tmp > target){
            --end;
        }else{
            vecVec.push_back({nums[beg++], nums[end--]});
            while(nums[beg] == nums[beg - 1] and beg < end)++beg;
            while(nums[end] == nums[end + 1] and beg < end)--end;
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> vecVec;
    std::stable_sort(nums.begin(), nums.end());
    if(nums.empty() or nums[0] > 0)return vecVec;

    int len = static_cast<int>(nums.size());
    for(int i = 0; i < len - 2; ++i){
        if(nums[i] > 0) break;
        if(i > 0 and nums[i] == nums[i - 1])continue;
        int target = -nums[i];

        vector<vector<int>> vecTmp;
        threeSumHelper(nums, i + 1, target, vecTmp);

        for(const auto& vec : vecTmp){
            vecVec.push_back({nums[i], vec[0], vec[1]});
        }
    }

    return vecVec;
}

void mergeSortArr(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int pos = m + n - 1;
    int i = m - 1, j = n - 1;
    while(i >= 0 and j >= 0){
        if(nums1[i] >= nums2[j]){
            nums1[pos--] = nums1[i--];
        }else{
            nums1[pos--] = nums2[j--];
        }
    }

    while(j >= 0) nums1[pos--] = nums2[j--];
}

vector<int> sortedSquares(vector<int>& nums) {
    int len = static_cast<int>(nums.size());
    int i = 0, j = len - 1, pos = len - 1;
    vector<int> res(nums.size(), 0);

    while(i <= j){
        int v = nums[i];
        if(std::abs(nums[i]) < std::abs(nums[j])){
            v = nums[j--];
        }else{
            ++i;
        }

        res[pos--] = v * v;
    }

    return res;
}

string reverseOnlyLetters(string s){
    int l = 0, r = static_cast<int>(s.size()) - 1;
    while(l < r){
        bool lFlag = std::isalpha(s[l]), rFlag = std::isalpha(s[r]);
        if(lFlag and rFlag){
            std::swap(s[l++], s[r--]);
        }

        if(not lFlag) ++l;
        if(not rFlag) --r;
    }

    return s;
}

string compressString(string str){
    int len = static_cast<int>(str.size());
    int i = 0;
    string res;

    while(i < len){
        int j = i + 1;
        for(; j < len and str[j] == str[j - 1]; ++j);
        res.push_back(str[i]);
        if(j - i < 10)res.push_back(j - i + '0');
        else res.append(std::to_string(j - i));
        i = j;
    }

    return res.size() < str.size() ? res : str;
}

template<typename Size>
int getNumericSize(Size size){
    int cnt = 0;
    while(size){++cnt; size /= 10;}
    return cnt;
}

int compress(vector<char>& chars){
    int len = chars.size();
    int i = 0, k = 0, cnt = 0;
    while(i < len){
        int j = i + 1;
        for(; j < len and chars[j] == chars[j - 1]; ++j);

        cnt += 1;
        chars[k++] = chars[i];
        int diff = j - i;
        if(diff > 1){
            cnt += getNumericSize(diff);
            string tmp = std::to_string(diff);
            for(auto ch : tmp)chars[k++] = ch;
        }

        i = j;
    }
    return std::min(cnt, len);
}

void adjustHeap(vector<int>& arr, int beg, int end){
    while(2 * beg + 1 < end){
        int i = 2 * beg + 1;
        if(i + 1 < end and arr[i + 1] > arr[i]) i += 1;

        if(arr[beg] >= arr[i])break;
        std::swap(arr[beg], arr[i]);
        beg = i;
    }
}

void heapSort(vector<int>& arr){
    if(arr.size() < 2) return;
    int len = static_cast<int>(arr.size());
    for(int i = (len - 2) / 2; i >= 0; --i){
        adjustHeap(arr, i, len);
    }

    for(int i = len - 1; i > 0; --i){
        std::swap(arr[0], arr[i]);
        adjustHeap(arr, 0, i);
    }
}

vector<int> spiralOrder2(vector<vector<int>>& matrix){
    int row = int(matrix.size());
    int col = int(matrix[0].size());
    int cnt = (std::min(row, col) + 1) / 2;
    vector<int> res;
    for(int i = 0; i < cnt; ++i){
        int r = i, c = i;
        for(; c < col - i; ++c){
            res.push_back(matrix[r][c]);
        }

        r = i + 1;
        c = col - 1 - i;
        for(; r < row - 1 - i; ++r){
            res.push_back(matrix[r][c]);
        }

        r = row - 1 - i;
        c = col - 1 - i;
        for(; r > i and c >= i; --c){  // r > i 上下没有重合
            res.push_back(matrix[r][c]);
        }

        c = i;
        r = row - 1 - i - 1;
        for(; (c < col - 1 - i) and r > i; --r){ // 左右没有重合
            res.push_back(matrix[r][c]);
        }
    }

    return res;
}

vector<int> spiralOrder(vector<vector<int>>& matrix){
    int upper = 0, down = int(matrix.size());
    int left = 0, right = int(matrix[0].size());

    vector<int> res;
    while(true){
        for(int c = left; c < right;++c){
            res.push_back(matrix[upper][c]);
        }
        if(++upper >= down)break;

        for(int r = upper; r < down; ++r){
            res.push_back(matrix[r][right - 1]);
        }
        if(--right <= left)break;

        for(int c = right - 1; c >= left; --c){
            res.push_back(matrix[down - 1][c]);
        }
        if(--down <= upper)break;

        for(int r = down - 1; r >= upper; --r){
            res.push_back(matrix[r][left]);
        }
        if(++left >= right)break;
    }

    return res;
}

vector<vector<int>> generateMatrix(int n){
    int num = 1, threshold = n * n;
    int upper = 0, down = n - 1;
    int left = 0, right = n - 1;
    vector<vector<int>> res(n, vector<int>(n, 0));
    while(num <= threshold){
        for(int c = left; c <= right; ++c){
            res[upper][c] = num++;
        }
        if(++upper > down)break;

        for(int r = upper; r <= down; ++r){
            res[r][right] = num++;
        }
        if(--right < left)break;

        for(int c = right; c >= left; --c){
            res[down][c] = num++;
        }
        if(--down < upper)break;

        for(int r = down; r >= upper; --r){
            res[r][left] = num++;
        }
        if(++left > right)break;
    }

    return res;
}

static const char CH_FILL = '*';
inline bool isFill(char c){return CH_FILL == c;}
string convert6(string s, int row){
    int len = int(s.size());
    if(row <= 1 or len <= 2) return s;

    int periodNum = (2 * row - 2);
    int period = (len - 1) / periodNum + 1;
    vector<vector<char>>  matrix(row, vector<char>(period * 2, CH_FILL));
    int idx = 0;
    for(int p =0; p < period and idx < len; ++p){
        for(int i = 0; i < periodNum and idx < len; ++i){
            int r = (i < row) ? i : (periodNum - i);
            int c = 2 * p + (i < row ? 0 : 1);
            matrix[r][c] = s[idx++];
        }
    }

    string res;res.reserve(len);
    for(int r = 0; r < row; ++r){
        for(int c = 0; c < matrix[0].size(); ++c){
            char ch = matrix[r][c];
            if(isFill(ch)) continue;
            res.push_back(ch);
        }
    }

    return res;
}

vector<int> exchange(vector<int>& nums){
    int len = nums.size();
    int i = 0, j = len -1;
    while(i < j){
        while(i < j and nums[i] % 2)++i;
        while(i < j and (0 == nums[j] % 2))--j;
        if(i >= j) break;
        std::swap(nums[i++], nums[j--]);
    }
    return nums;
}

vector<int> exchange2(vector<int>& nums) {
    std::stable_sort(nums.begin(), nums.end(), [](int a, int b){
        if(a % 2) return true;
        return false;
    });
    return nums;
}

vector<int> sortArrayByParity(vector<int>& nums){
    int len = nums.size();
    int i = 0, j = len  - 1;
    while(i < j){
        while(i < j and 0 == nums[i] % 2)++i;
        while(i < j and 1 == nums[j] % 2)--j;
        if(i >= j)break;
        std::swap(nums[i++], nums[j--]);
    }
    return nums;
}

int removeDuplicates(vector<int>& nums){
    int len = int(nums.size());
    int i = 0, j = 1;
    while(j < len){
        if(nums[i] != nums[j]){
            nums[++i] = nums[j];
        }
        ++j;
    }
    return i + 1;
}

int removeDuplicates2(vector<int>& nums){
    int len = nums.size();
    if(len <= 2) return len;
    int i = 2, j = 2;
    while(j < len){
        if(nums[j] != nums[i - 2]){
            nums[i++] = nums[j];
        }
        ++j;
    }
    return i;
}

int removeElement(vector<int>& nums, int val){
    int len = int(nums.size());
    int i = 0, j = 0;
    while(j < len){
        if(nums[j] != val){
            nums[i++] = nums[j];
        }
        ++j;
    }

    return i;
}

void moveZeroes(vector<int>& nums){
    int len = nums.size();
    int idx = 0;
    for(int i = 0; i < len; ++i){
        if(0 != nums[i]){
            nums[idx++] = nums[i];
        }
    }

    for( ; idx < len; ++idx){
        nums[idx] = 0;
    }
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i = m - 1, j = n - 1;
    int idx = m + n - 1;

    while(i >=0 and j >= 0){
        if(nums1[i] > nums2[j]){
            nums1[idx--] = nums1[i--];
        }else{
            nums1[idx--] = nums2[j--];
        }
    }

    while(j >= 0)nums1[idx--] = nums2[j--];
}

vector<int> sortedSquares2(vector<int>& nums){
    int len = nums.size();
    int i = 0, j = len - 1, idx = len - 1;
    vector<int> res(nums.size(), 0);
    while(i <= j){
        int n1 = std::abs(nums[i]);
        int n2 = std::abs(nums[j]);
        if(n1 > n2){
            res[idx--] = n1 * n1;
            ++i;
        }else{
            res[idx--] = n2 * n2;
            --j;
        }
    }
    return res;
}

int maxArea(vector<int>& height){
    int len = height.size();
    int i = 0, j = len - 1;
    int res = 0;
    while(i < j){
        int area = std::min(height[i], height[j]) * (j - i);
        res = std::max(res, area);
        if(height[i] < height[j]){
            ++i;
        }else{
            --j;
        }
    }
    return res;
}

int trap(vector<int>& height){
    int len = height.size();
    if(len < 3){return 0;}
    std::vector<std::pair<int, int>> vMaxLeftRight(len, {0, 0});

    for(int i = 1; i < len; ++i){
        vMaxLeftRight[i].first = std::max(vMaxLeftRight[i - 1].first, height[i - 1]);
    }

    for(int j = len - 2; j >= 0; --j){
        vMaxLeftRight[j].second = std::max(vMaxLeftRight[j + 1].second, height[j + 1]);
    }

    int res = 0;
    for(int i = 1; i < len - 1; ++i){
        if(vMaxLeftRight[i].first <= height[i] or vMaxLeftRight[i].second <= height[i])
            continue;
        int h = std::min(vMaxLeftRight[i].first, vMaxLeftRight[i].second) - height[i];
        res += h;
    }
    return res;
}

int largestRectangleArea(vector<int>& heights){
    int len = heights.size();
    int res = 0;
    for(int i = 0; i < len; ++i){
        if(0 == heights[i]) continue;
        int iMinHeight = heights[i];
        res = std::max(res, iMinHeight);
        for(int j = i + 1; j < len; ++j){
            if(0 == heights[j]) break;
            iMinHeight = std::min(heights[j], iMinHeight);
            res = std::max(res, iMinHeight * (j - i + 1));
        }
    }
    return res;
}

int largestRectangleArea1(vector<int>& heights){
    std::unordered_map<int, int> mHeightArea;
    int len = heights.size();
    int res = 0;
    for(int i = 0; i < len; ++i){
        if(mHeightArea.count(heights[i]))continue;
        int cnt = 1;
        for(int j = i - 1; j >=0 and heights[j] >= heights[i]; --j)++cnt;
        for(int j = i + 1; j < len and heights[j] >= heights[i]; ++j)++cnt;

        int area = heights[i] * cnt;
        res = std::max(res, area);
        mHeightArea[heights[i]] = area;
    }

    return res;
}

int largestRectangleArea3(vector<int>& heights){
    int len = heights.size();
    int res = 0;
    for(int i = 0; i < len; ++i){
        if(0 == heights[i]) continue;
        if(i > 0 and heights[i] == heights[i - 1]) continue;

        int cnt = 1;
        for(int j = i - 1; j >= 0 and heights[j] >= heights[i]; --j)++cnt;
        for(int j = i + 1; j < len and heights[j] >= heights[i]; ++j)++cnt;

        int area = heights[i] * cnt;
        res = std::max(res, area);
    }

    return res;
}

int searchInsert(vector<int>& nums, int target){
    int len = nums.size();
    int l = 0, r = len - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    if(r < 0) return 0;
    if(l >= len) return len;
    return r + 1;
}

int helper34_1(const vector<int>& nums, int target, int left, int right){
    while(left <= right){
        int mid = (left + right) / 2 ;
        if(nums[mid] > target){
            right = mid - 1;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else{
            if(mid > 0 and nums[mid - 1] == target){
                right = mid - 1;
            }else{
                return mid;
            }
        }
    }
    return -1;
}

int helper34_2(const vector<int>& nums, int target, int left, int right){
    while(left <= right){
        int mid = (left + right) / 2 ;
        if(nums[mid] > target){
            right = mid - 1;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else{
            if(mid < right and nums[mid + 1] == target){
                left = mid + 1;
            }else{
                return mid;
            }
        }
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target){
    int len = nums.size();
    int left = helper34_1(nums, target, 0, len - 1);
    if(left < 0) return {-1, -1};
    int right = helper34_2(nums, target, left, len - 1);
    return {left, right};
}


int search33(vector<int>& nums, int target){
    int len = nums.size();
    int left = 0, right = len - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(target == nums[mid]){
            return mid;
        }else if(target > nums[mid]){
            if(nums[left] < nums[mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }else{
//            if(nums[] >= nums[mid]){
//                right = mid - 1;
//            }else{
//                left = mid + 1;
//            }
        }
    }

    return -1;
}


vector<int> twoSum(vector<int>& nums, int target){
	std::multimap<int, int> mValIdx;
	for(int i = 0; i < nums.size(); ++i){
          mValIdx.insert({nums[i], i});
	}

    auto it1 = mValIdx.begin();
	auto it2 = --mValIdx.end();
	while(it1 != it2){
		int n = it1->first + it2->first;
		if(n == target){
			return {it1->second, it2->second};
		}else if(n > target){
			--it2;
		}else{
			++it1;
		}
	}

	return {-1, -1};
}

vector<int> twoSum2(vector<int>& nums, int target){
    std::unordered_map<int, int> mValIdx;
    for(int i = 0; i < nums.size(); ++i){
        int n = target - nums[i];
        auto it = mValIdx.find(n);
        if(it != mValIdx.end()){
            return {i, it->second};
        }
        mValIdx[nums[i]] = i;
    }

    return {-1, -1};
}

void helper15(const vector<int>& nums, int idx, vector<vector<int>>& res){
    int len = nums.size();
    int left = idx + 1, right = len - 1, target = -nums[idx];
    while(left < right){
        int n = nums[left] + nums[right];
        if(n > target){
            --right;
        }else if(n < target){
            ++left;
        }else{
            res.push_back({nums[left++], nums[right--]});
        }
    }
}

vector<vector<int>> threeSumV2(vector<int>& nums){
    std::stable_sort(nums.begin(), nums.end());
    int len = nums.size();
    std::set<vector<int>> setVec;
    for(int i = 0; i < len; ++i){
        if(nums[i] > 0)break;
        if(i > 0 and nums[i] == nums[i - 1])continue;

        vector<vector<int>> vecVec;
        helper15(nums, i, vecVec);
        for(auto& vec : vecVec){
            vec.insert(vec.begin(), nums[i]);
            setVec.insert(vec);
        }
    }

    vector<vector<int>> res(setVec.begin(), setVec.end());
    return res;
}

int helper16(const vector<int>& nums, int idx, int target){
    int left = idx, right = int(nums.size()) - 1;
    int ret = nums[idx - 1] + nums[left] + nums[right];
    while(left < right){
        int num = nums[left] + nums[right] + nums[idx - 1];
        if(std::abs(ret - target) > std::abs(num - target)){
            ret = num;
        }
        if(num == target){
            break;
        }else if(num < target){
            ++left;
        }else{
            --right;
        }
    }

    return ret;
}

int threeSumClosest(vector<int>& nums, int target) {
    int len = nums.size();
    std::stable_sort(nums.begin(), nums.end());

    int ret = nums[0] + nums[1] + nums[2];
    for(int i = 0; i < len - 2; ++i){
        int tmp = helper16(nums, i + 1, target);
        if(std::abs(ret - target) >= std::abs(tmp - target)){
            ret = tmp;
            if(target == ret)break;
        }
    }

    return ret;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> mValCnt;
    vector<int> vUniq;
    for(auto n : nums){
        ++mValCnt[n];
        if(1 == mValCnt[n]) vUniq.push_back(n);
    }

    std::stable_sort(vUniq.begin(), vUniq.end(), [&](int v1, int v2){
        return mValCnt[v1]  > mValCnt[v2];
    });

    vector<int> res(vUniq.begin(), vUniq.begin() + k);
    return res;
}
