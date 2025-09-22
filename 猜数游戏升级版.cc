#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

// 猫娘ASCII艺术
const string CLOSE_CAT = R"(
(≧◡≦) 喵~主人好接近呢！就差一点点啦！
 /)__)
( •ω•) 
)";
const string FAR_CAT = R"(
(´･ω･`) 主人好像有点走偏了呢~
 /)__)
( •ω•) 
)";
const string VERY_FAR_CAT = R"(
(,,>﹏<,,) 主人完全猜错了喵~要加油哦！
 /)__)
( •ω•) 
)";
const string WIN_CAT = R"(
(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ 主人好厉害喵！猜对啦！
 /)__)
( •ω•) 
)";

int main() {
    srand(static_cast<unsigned>(time(0)));
    bool playAgain = true;
    int minRange = 1, maxRange = 100;

    while (playAgain) {
        cout << "喵~主人想设定数字范围吗？(y/n) ";
        char choice;
        cin >> choice;
        
        if (choice == 'y' || choice == 'Y') {
            cout << "请输入最小数字喵~: ";
            cin >> minRange;
            cout << "请输入最大数字喵~: ";
            cin >> maxRange;
        }

        int range = maxRange - minRange + 1;
        int secretNumber = rand() % range + minRange;
        int maxAttempts = ceil(range / 10.0);
        int closeThreshold = range * 0.05;
        int farThreshold = range * 0.2;

        cout << "\n喵~人家已经想好了一个" << minRange << "到" << maxRange 
             << "之间的数字喵~ (｡◕‿◕｡)" << endl;
        cout << "主人有" << maxAttempts << "次机会猜中喵~加油哦！" << endl;

        int attempts = 0;
        bool guessed = false;

        while (attempts < maxAttempts && !guessed) {
            cout << "\n请输入主人的猜测喵~ (" << (attempts + 1) << "/" 
                 << maxAttempts << "): ";
            int guess;
            cin >> guess;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "喵~要输入数字啦主人！(>_<)" << endl;
                continue;
            }

            int difference = abs(guess - secretNumber);
            attempts++;

            if (guess == secretNumber) {
                guessed = true;
                cout << WIN_CAT << endl;
                cout << "主人好棒喵~只用了" << attempts << "次就猜中啦！(≧∇≦)ﾉ" << endl;
            } else if (difference <= closeThreshold) {
                cout << CLOSE_CAT << endl;
                cout << "喵~主人离答案很接近呢！(｡♥‿♥｡)" << endl;
            } else if (difference <= farThreshold) {
                cout << FAR_CAT << endl;
                cout << "喵呜~主人还需要再靠近一点喵~ (。-`ω´-)" << endl;
            } else {
                cout << VERY_FAR_CAT << endl;
                cout << "喵...主人离目标还有点远呢 (´･_･`)" << endl;
            }

            if (!guessed && attempts < maxAttempts) {
                if (guess < secretNumber) {
                    cout << "提示喵：人家想的数字比这个大哦~ (=^ェ^=)" << endl;
                } else {
                    cout << "提示喵：人家想的数字比这个小呢~ (^・ω・^ )" << endl;
                }
            }
        }

        if (!guessed) {
            cout << "\n喵...机会用完啦~正确答案是: " << secretNumber 
                 << " (｡•́︿•̀｡)" << endl;
        }

        cout << "\n主人想再玩一次喵？" << endl;
        cout << "1. 用相同范围再玩一次 (=^･ｪ･^=)" << endl;
        cout << "2. 重新设置范围 (^._.^)ﾉ" << endl;
        cout << "3. 退出游戏 (╥﹏╥)" << endl;
        cout << "请选择喵~: ";
        
        int option;
        cin >> option;
        
        if (option == 3) {
            playAgain = false;
            cout << "\n谢谢主人陪人家玩喵~再见啦！(≧◡≦)ノ彡☆" << endl;
        } else if (option == 2) {
            cout << "请输入新的最小数字喵~: ";
            cin >> minRange;
            cout << "请输入新的最大数字喵~: ";
            cin >> maxRange;
        }
    }

    return 0;
}
