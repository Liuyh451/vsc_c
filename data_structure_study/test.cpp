#include <iostream>
#include <vector>

int calculateDifference(std::vector<int>& a) {
    int left = 0;
    int right = a.size() - 1;
    int result = 0;
    bool add = true;  // 控制正负号

    while (left <= right) {
        if (add) {
            result += a[left];
            result -= a[right];
        } else {
            result -= a[left];
            result += a[right];
        }
        left++;
        right--;
        add = !add;  // 每轮改变正负号
    }

    return result;
}

int main() {
    std::vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);

    int result = calculateDifference(a);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
