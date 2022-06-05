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

