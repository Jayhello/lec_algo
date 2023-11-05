//
// Created by wenwen on 2022/5/22.
//

#include <climits>
#include "al_other.h"

bool isUgly(int n){
    if(n <= 0) return false;

    while(0 == n % 2) n /= 2;
    while(0 == n % 3) n /= 3;
    while(0 == n % 5) n /= 5;

    return 1 == n;
}

int nthUglyNumber(int n){
    set<int> nums;

    for(long a = 1; a < INT_MAX; a *= 2){
        for(long b = 1; b < INT_MAX; b *= 3){
            for(long c = 1; c < INT_MAX; c *= 5){
                long tmp = a * b * c;
                if(tmp > INT_MAX) break;
                nums.insert(tmp);
            }
        }
    }

    auto it = nums.begin();
    std::advance(it, n - 1);
    return *it;
}

bool isPrime(int n){
    if(n <= 1) return false;

    for(int i = 2; i * i <= n; ++i){
        if(0 == n % i)return false;
    }

    return true;
}

#ifdef countPrimes_v1
int countPrimes(int n){
    int count = 0;
    for(int i = 2; i <= n; ++i){
        if(isPrime(i))++count;
    }

    return count;
}
#endif

int countPrimes(int n){
    int count = 0;
    vector<bool> vFlag(n, true);

    for(int i = 2; i < n; ++i){
        if(vFlag[i] and isPrime(i)){
            ++count;
            vFlag[i] = false;

            for(int j = 2 * i; j < n; j += i){
                vFlag[j] = false;
            }
        }
    }

    return count;
}

bool isIsomorphic(string s, string t) {
    int len = s.size(), i = 0;;
    unordered_map<char, char> mkv1, mkv2;
    for(; i < len; ++i){
        char c1 = s[i];
        char c2 = t[i];

        auto it1 = mkv1.find(c1);
        if(it1 != mkv1.end() and it1->second != c2){
            break;
        }

        auto it2 = mkv2.find(c2);
        if(it2 != mkv2.end() and it2->second != c1){
            break;
        }

        mkv1[c1] = c2;
        mkv2[c2] = c1;
    }

    return i == len;
}

bool wordPattern(string pattern, string s) {
    int len_p = pattern.size(), len_s = s.size();
    int i = 0, j = 0;
    unordered_map<char, string> mkv1;
    unordered_map<string, char> mkv2;

    for(; i < len_p; ++i){
        char c1 = pattern[i];

        while(j < len_s and  ' ' == s[j]) ++j;
        if(j == len_s) break;

        int idx = j;
        while(j < len_s and  ' ' != s[j]) ++j;

        string word = s.substr(idx, j - idx);
        auto it = mkv1.find(c1);
        if(it != mkv1.end() and it->second != word){
            break;
        }

        auto it2 = mkv2.find(word);
        if(it2 != mkv2.end() and it2->second != c1){
            break;
        }

        mkv1[c1] = word;
        mkv2[word] = c1;
    }

    while(j < len_s and  ' ' == s[j]) ++j;

    return i == len_p and j == len_s;
}
