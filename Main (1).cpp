#include<iostream>
using namespace std;

int main() {
    const int secretNumber = 35; // 设置秘密数字
    int num;
    bool guessed = false; // 标记是否猜对
    
    cout << "猜猜我心里想的数字是几（范围在0-100之间）" << endl;
    
    while (!guessed) {
        cout << "请输入你的猜测: ";
        cin >> num;
        
        if (num == secretNumber) {
            cout << "恭喜你猜对了！" << endl;
            guessed = true;
        } else if (num > secretNumber) {
            cout << "你猜的数字有点大了，再试试" << endl;
        } else if (num >= 29) { // 29-34之间
            cout << "你猜的小了，不过很接近了" << endl;
        } else { // 小于29
            cout << "有点太小了" << endl;
        }
    }
    
    cout << "游戏结束！" << endl;
    return 0;
}
