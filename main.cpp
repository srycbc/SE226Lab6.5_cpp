#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> commonFind(vector<int> list1, vector<int> list2) {
    vector<int> result;
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    set_intersection(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(result));
    return result;
}

bool createPalindrome(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> filterPalindromes(vector<string> list) {
    vector<string> result;
    for (string str : list) {
        if (createPalindrome(str)) {
            result.push_back(str);
        }
    }
    return result;
}

vector<int> findPrime(vector<int> nums) {
    vector<int> primes;
    int n = nums.size();
    vector<bool> arr(n+1, true);
    for (int p=2; p*p<=n; p++) {
        if (arr[p] == true) {
            for (int i=p*p; i<=n; i += p)
                arr[i] = false;
        }
    }
    for (int i=2; i<=n; i++) {
        if (arr[i] && find(nums.begin(), nums.end(), i) != nums.end())
            primes.push_back(i);
    }
    return primes;}


vector<string> anagrams(string word, vector<string> word_list) {
    vector<string> result;
    string sorted_word = word;
    sort(sorted_word.begin(), sorted_word.end());
    for (string w : word_list) {
        string sorted_w = w;
        sort(sorted_w.begin(), sorted_w.end());
        if (sorted_w == sorted_word) {
            result.push_back(w);
        }
    }
    return result;
}


int main() {
    cout<<"***QUESTION 1***"<<endl;
    vector<int> list1 = {3,8,9,2,1,6};
    vector<int> list2 = {7,6,9,1,2,3};
    vector<int> commonElements = commonFind(list1, list2);

    cout << "Common elements: ";
    for (int element : commonElements) {
        cout << element << " ";
    }
    cout << endl;

    cout<<" "<<endl;
    cout<< "***QUESTION 2***"<<endl;
    vector<string> list = {"level", "bob", "seray", "ses", "course"};
    vector<string> palindromes = filterPalindromes(list);

    cout << "palindromes: ";
    for (string str : palindromes) {
        cout << str << " ";
    }
    cout << endl;

    cout<<" "<<endl;
    cout<<"***QUESTION 3***"<<endl;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> primes = findPrime(nums);
    cout << "prime numbers: "<<endl;
    for (int prime : primes)
        cout << prime << " "<<endl;

    cout<<" "<<endl;
    cout<<"***QUESTION 4***" <<endl;

    string word = "below";
    vector<string> word_list = {"eblow", "woble", "seray", "eblew"};
    vector<string> result = anagrams(word, word_list);
    for (string s : result) {
        cout << s << endl;
    }


    return 0;
}