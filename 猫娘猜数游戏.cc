#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <random>

using namespace std;

// 随机数生成器
mt19937 rng(static_cast<unsigned>(time(0)));

// 猫娘角色类
class NekoCharacter {
public:
    string name;
    vector<string> winArt;
    vector<string> closeArt;
    vector<string> farArt;
    vector<string> veryFarArt;
    vector<string> hintArt;
    vector<string> thinkArt;
    vector<string> happyArt;
    vector<string> shyArt;
    vector<string> feedArt;
    vector<string> teaseArt;
    
    // 角色特有语气
    string getWinMessage(int attempts) {
        vector<string> messages = {
            "主人好厉害喵！只用了" + to_string(attempts) + "次就猜中啦！",
            "喵呜~主人这么快就猜对了，人家好开心！",
            "主人真是太聪明了！" + to_string(attempts) + "次就猜中了喵~",
            "主人猜对啦！作为奖励，可以摸摸人家的头哦~",
            "喵~主人这么快就猜对了，是不是偷偷看人家心里想的数字了？"
        };
        uniform_int_distribution<int> dist(0, messages.size() - 1);
        return messages[dist(rng)];
    }
    
    string getCloseMessage() {
        vector<string> messages = {
            "主人离答案好近喵~就差一点点啦！",
            "喵呜~主人快要猜中啦！",
            "就差那么一点点喵~主人加油！",
            "好接近喵~主人再试一次就能猜中啦！",
            "喵~主人离答案只有一步之遥呢！"
        };
        uniform_int_distribution<int> dist(0, messages.size() - 1);
        return messages[dist(rng)];
    }
    
    string getFarMessage() {
        vector<string> messages = {
            "喵呜~主人好像有点走偏了呢",
            "主人还需要再靠近一点喵~",
            "方向不太对喵~主人再想想看",
            "喵~主人离答案还有点距离呢",
            "这个方向不太对喵~换个思路试试"
        };
        uniform_int_distribution<int> dist(0, messages.size() - 1);
        return messages[dist(rng)];
    }
    
    string getVeryFarMessage() {
        vector<string> messages = {
            "喵...主人完全猜错了喵~",
            "这个方向完全不对喵~",
            "喵呜~主人离目标好远呢",
            "完全不对喵~主人再想想看",
            "这个数字差得好远喵~"
        };
        uniform_int_distribution<int> dist(0, messages.size() - 1);
        return messages[dist(rng)];
    }
};

// 猫娘角色集合
map<string, NekoCharacter> nekoCharacters;

// 初始化角色
void initializeCharacters() {
    // 巧克力（活泼开朗）
    NekoCharacter choco;
    choco.name = "巧克力";
    choco.winArt = {
        "  /\\_/\\  ",
        " (^◕ᴥ◕^) ",
        "  > ^ <   ",
        " /     \\ ",
        "(       )",
        " \\_____/ "
    };
    choco.closeArt = {
        "  /\\_/\\  ",
        " ( o.o ) ",
        " > ^ <   "
    };
    choco.farArt = {
        "  /\\_/\\  ",
        " ( -.- ) ",
        " o_(\")(\")"
    };
    choco.veryFarArt = {
        "  /\\_/\\  ",
        " (⊙﹏⊙) ",
        "  (,,>﹏<,,)"
    };
    choco.hintArt = {
        "  /\\_/\\  ",
        " (｡◕‿◕｡)",
        "  / >ω< \\"
    };
    choco.thinkArt = {
        "  /\\_/\\  ",
        " ( -.-)  ",
        "  ~(˘▾˘~)"
    };
    choco.happyArt = {
        "  /\\_/\\  ",
        " (=^･ω･^=)",
        "  (^._.^)ﾉ"
    };
    choco.shyArt = {
        "  /\\_/\\  ",
        " (⁄ ⁄•⁄ω⁄•⁄ ⁄)",
        "  ~(˘///˘~)"
    };
    choco.feedArt = {
        "  /\\_/\\  ",
        " (^◕ᴥ◕^) ",
        "  > ^ <   ",
        " 小鱼干好好吃喵~"
    };
    choco.teaseArt = {
        "  /\\_/\\  ",
        " (=^･ω･^=)",
        " 主人好坏喵~"
    };
    nekoCharacters["choco"] = choco;
    
    // 香草（文静温柔）
    NekoCharacter vanilla;
    vanilla.name = "香草";
    vanilla.winArt = {
        "    /\\_/\\    ",
        "   ( •.• )   ",
        "   > ^ < ฅ   ",
        "  /       \\ ",
        " (         ) ",
        "  \\_______/ "
    };
    vanilla.closeArt = {
        "  /\\_/\\  ",
        " (´･ω･`)",
        "  > ^ <   "
    };
    vanilla.farArt = {
        "  /\\_/\\  ",
        " (´-ω-`)",
        " o_(\")(\")"
    };
    vanilla.veryFarArt = {
        "  /\\_/\\  ",
        " (╥﹏╥) ",
        "  (,,>﹏<,,)"
    };
    vanilla.hintArt = {
        "  /\\_/\\  ",
        " (｡◕‿◕｡)",
        "  / >ω< \\"
    };
    vanilla.thinkArt = {
        "  /\\_/\\  ",
        " ( -.-)  ",
        "  ~(˘▾˘~)"
    };
    vanilla.happyArt = {
        "  /\\_/\\  ",
        " (^◕ᴥ◕^) ",
        " 主人最棒了~"
    };
    vanilla.shyArt = {
        "  /\\_/\\  ",
        " (⁄ ⁄>⁄ω⁄<⁄ ⁄)",
        " 主人不要这样..."
    };
    vanilla.feedArt = {
        "  /\\_/\\  ",
        " (´･ω･`)",
        " 谢谢主人的小鱼干~"
    };
    vanilla.teaseArt = {
        "  /\\_/\\  ",
        " (⁄ ⁄>⁄ω⁄<⁄ ⁄)",
        " 主人请不要这样..."
    };
    nekoCharacters["vanilla"] = vanilla;
    
    // 红豆（傲娇）
    NekoCharacter azuki;
    azuki.name = "红豆";
    azuki.winArt = {
        "    /\\_/\\    ",
        "   (｀Д´)    ",
        "   > ^ < ฅ   ",
        "  /       \\ ",
        " (         ) ",
        "  \\_______/ "
    };
    azuki.closeArt = {
        "  /\\_/\\  ",
        " (｀ε´) ",
        "  > ^ <   "
    };
    azuki.farArt = {
        "  /\\_/\\  ",
        " (¬_¬) ",
        " o_(\")(\")"
    };
    azuki.veryFarArt = {
        "  /\\_/\\  ",
        " (╬ Ò﹏Ó) ",
        "  (,,>﹏<,,)"
    };
    azuki.hintArt = {
        "  /\\_/\\  ",
        " (｀ε´) ",
        " 才不是想帮你呢！"
    };
    azuki.thinkArt = {
        "  /\\_/\\  ",
        " ( -.-)  ",
        " 别打扰我思考！"
    };
    azuki.happyArt = {
        "  /\\_/\\  ",
        " (｀ω´) ",
        " 哼，算你厉害"
    };
    azuki.shyArt = {
        "  /\\_/\\  ",
        " (⁄ ⁄•⁄ω⁄•⁄ ⁄)",
        " 笨蛋主人..."
    };
    azuki.feedArt = {
        "  /\\_/\\  ",
        " (｀ε´) ",
        " 我才不是想吃小鱼干呢！"
    };
    azuki.teaseArt = {
        "  /\\_/\\  ",
        " (╬ Ò﹏Ó) ",
        " 别碰我！"
    };
    nekoCharacters["azuki"] = azuki;
}

// 显示ASCII艺术
void displayArt(const vector<string>& art) {
    for (const auto& line : art) {
        cout << line << endl;
    }
    cout << endl;
}

// 计算最小尝试次数
int calculateMinAttempts(int minRange, int maxRange) {
    int range = maxRange - minRange + 1;
    return max(1, static_cast<int>(ceil(log2(range))));
}

// 显示游戏帮助
void showHelp() {
    cout << "\n===== 游戏帮助喵~ =====" << endl;
    cout << "1. 游戏会随机生成一个范围内的数字" << endl;
    cout << "2. 主人需要猜出这个数字是多少" << endl;
    cout << "3. 根据主人的猜测，猫娘会给出提示" << endl;
    cout << "4. 提示类型：" << endl;
    cout << "   - 非常接近：差距在范围5%以内" << endl;
    cout << "   - 有点远：差距在范围20%以内" << endl;
    cout << "   - 完全不对：差距超过范围20%" << endl;
    cout << "5. 主人有有限次数的尝试机会" << endl;
    cout << "6. 小鱼干系统：" << endl;
    cout << "   - 初始有三条小鱼干" << endl;
    cout << "   - 猜对后奖励一条小鱼干" << endl;
    cout << "   - 可以投喂小鱼干换取提示" << endl;
    cout << "7. 逗猫系统：" << endl;
    cout << "   - 有10%的机会获得暗示" << endl;
    cout << "   - 三次逗猫必定获得一次暗示" << endl;
    cout << "8. 输入 'hint' 可以获得提示（消耗一条小鱼干）" << endl;
    cout << "9. 输入 'feed' 可以投喂小鱼干" << endl;
    cout << "10. 输入 'tease' 可以逗猫" << endl;
    cout << "11. 输入 'quit' 可以随时退出游戏" << endl;
    cout << "12. 游戏结束后可以选择重新开始或退出" << endl;
    cout << "======================\n" << endl;
}

// 胜利后的特殊反馈
void victoryFeedback(NekoCharacter& character, int attempts, int minAttempts) {
    vector<string> messages = {
        "既然主人已经猜对了，那么接下来就该干羞羞的事情啦~",
        "主人这么快就猜对了，是不是偷偷看人家心里想的数字了？",
        "喵呜~作为奖励，可以摸摸人家的头哦~",
        "主人这么快就猜对了，人家还没有玩够呢~",
        "主人真是太聪明了！要不要和人家玩点别的游戏？"
    };
    
    vector<string> specialMessages = {
        "主人居然在理论最小次数内就猜对了！太厉害了！",
        "主人打破了人家的记录！作为奖励，可以亲人家一下哦~",
        "喵呜~主人简直是天才！这么快就猜对了，人家好开心！"
    };
    
    uniform_int_distribution<int> dist(0, messages.size() - 1);
    string message = messages[dist(rng)];
    
    if (attempts <= minAttempts) {
        uniform_int_distribution<int> specialDist(0, specialMessages.size() - 1);
        message = specialMessages[specialDist(rng)];
    }
    
    displayArt(character.shyArt);
    cout << message << endl;
}

// 主游戏函数
void playGame(int minRange, int maxRange, NekoCharacter& character) {
    int range = maxRange - minRange + 1;
    uniform_int_distribution<int> numDist(minRange, maxRange);
    int secretNumber = numDist(rng);
    
    // 计算尝试次数：范围除以10向上取整，但至少为3次
    int maxAttempts = max(3, static_cast<int>(ceil(range / 10.0)));
    int minAttempts = calculateMinAttempts(minRange, maxRange);
    
    int closeThreshold = max(1, static_cast<int>(range * 0.05));
    int farThreshold = max(1, static_cast<int>(range * 0.2));
    
    // 小鱼干系统
    int fishTreats = 3;
    // 逗猫系统
    int teaseCount = 0;
    bool teaseHintAvailable = false;
    
    displayArt(character.thinkArt);
    cout << character.name << ": 喵~人家已经想好了一个" << minRange << "到" << maxRange 
         << "之间的数字喵~" << endl;
    cout << "主人有 " << maxAttempts << " 次机会喵~" << endl;
    cout << "理论最小尝试次数: " << minAttempts << " 次" << endl;
    cout << "初始小鱼干: " << fishTreats << " 条" << endl;
    cout << "输入 'help' 可以查看游戏帮助喵~" << endl;
    cout << "输入 'quit' 可以随时退出游戏喵~" << endl;
    cout << "输入 'hint' 可以获得提示喵~ (消耗1条小鱼干)" << endl;
    cout << "输入 'feed' 可以投喂小鱼干喵~" << endl;
    cout << "输入 'tease' 可以逗猫喵~ (有10%几率获得提示)" << endl;
    
    int attempts = 0;
    bool guessed = false;
    vector<int> guesses;
    vector<string> feedbacks;
    
    while (attempts < maxAttempts && !guessed) {
        cout << "\n[" << character.name << "] 请输入主人的猜测 (" 
             << (attempts + 1) << "/" << maxAttempts << "): ";
        
        string input;
        cin >> input;
        
        // 处理特殊命令
        if (input == "quit") {
            cout << character.name << ": 主人要退出游戏喵？人家会想你的..." << endl;
            return;
        }
        
        if (input == "help") {
            showHelp();
            continue;
        }
        
        if (input == "hint") {
            if (fishTreats > 0) {
                fishTreats--;
                // 提示：告诉玩家一个范围（比如在中间三分之一范围内）
                int lowerBound = max(minRange, secretNumber - range/6);
                int upperBound = min(maxRange, secretNumber + range/6);
                displayArt(character.hintArt);
                cout << character.name << ": 提示喵：数字在" 
                     << lowerBound << " 到 " << upperBound << " 之间喵~" << endl;
                cout << "剩余小鱼干: " << fishTreats << " 条" << endl;
                feedbacks.push_back("使用了提示");
                continue;
            } else {
                cout << character.name << ": 喵~没有小鱼干了，不能使用提示啦！" << endl;
                continue;
            }
        }
        
        if (input == "feed") {
            if (fishTreats > 0) {
                fishTreats--;
                displayArt(character.feedArt);
                cout << character.name << ": 谢谢主人的小鱼干喵~好开心！" << endl;
                cout << "剩余小鱼干: " << fishTreats << " 条" << endl;
                feedbacks.push_back("投喂了小鱼干");
                continue;
            } else {
                cout << character.name << ": 喵~没有小鱼干了，不能投喂啦！" << endl;
                continue;
            }
        }
        
        if (input == "tease") {
            teaseCount++;
            displayArt(character.teaseArt);
            
            // 10%几率获得提示，或者每三次必定获得提示
            uniform_int_distribution<int> teaseDist(1, 100);
            if (teaseDist(rng) <= 10 || teaseCount % 3 == 0) {
                teaseHintAvailable = true;
                cout << character.name << ": 喵呜~主人好坏！不过人家可以给你一点提示哦~" << endl;
            } else {
                cout << character.name << ": 喵！不要逗人家啦！" << endl;
            }
            feedbacks.push_back("逗猫");
            continue;
        }
        
        // 尝试转换为数字
        try {
            int guess = stoi(input);
            
            // 检查是否在范围内
            if (guess < minRange || guess > maxRange) {
                cout << character.name << ": 喵~数字要在 " << minRange << " 和 " << maxRange << " 之间啦！" << endl;
                continue;
            }
            
            int difference = abs(guess - secretNumber);
            attempts++;
            guesses.push_back(guess);
            
            if (guess == secretNumber) {
                guessed = true;
                displayArt(character.winArt);
                cout << character.name << ": " << character.getWinMessage(attempts) << endl;
                feedbacks.push_back("猜对了！");
                
                // 胜利奖励：一条小鱼干
                fishTreats++;
                cout << character.name << ": 作为奖励，主人获得一条小鱼干喵~" << endl;
                cout << "现在有 " << fishTreats << " 条小鱼干" << endl;
                
                // 胜利后的特殊反馈
                victoryFeedback(character, attempts, minAttempts);
            } else if (difference <= closeThreshold) {
                displayArt(character.closeArt);
                cout << character.name << ": " << character.getCloseMessage() << endl;
                feedbacks.push_back("非常接近");
            } else if (difference <= farThreshold) {
                displayArt(character.farArt);
                cout << character.name << ": " << character.getFarMessage() << endl;
                feedbacks.push_back("有点远");
            } else {
                displayArt(character.veryFarArt);
                cout << character.name << ": " << character.getVeryFarMessage() << endl;
                feedbacks.push_back("完全不对");
            }
            
            // 提供提示
            if (!guessed && attempts < maxAttempts) {
                if (teaseHintAvailable) {
                    if (guess < secretNumber) {
                        cout << character.name << ": 提示喵：人家想的数字比这个大哦~" << endl;
                    } else {
                        cout << character.name << ": 提示喵：人家想的数字比这个小呢~" << endl;
                    }
                    teaseHintAvailable = false;
                }
            }
        } catch (const invalid_argument&) {
            cout << character.name << ": 喵~要输入数字啦主人！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    if (!guessed) {
        displayArt(character.veryFarArt);
        cout << character.name << ": 喵...机会用完啦~正确答案是: " << secretNumber << endl;
    }
    
    // 显示猜测历史
    if (!guesses.empty()) {
        cout << "\n===== 主人的猜测历史喵~ =====" << endl;
        for (int i = 0; i < guesses.size(); i++) {
            cout << "第" << i+1 << "次: " << guesses[i] << " - " << feedbacks[i];
            if (guesses[i] < secretNumber) {
                cout << " (小了)";
            } else if (guesses[i] > secretNumber) {
                cout << " (大了)";
            }
            cout << endl;
        }
        cout << "=============================" << endl;
    }
}

int main() {
    initializeCharacters();
    bool playAgain = true;
    int minRange = 1, maxRange = 100;
    string currentCharacter = "choco";
    
    cout << "欢迎来到猫娘猜数字游戏喵~\n" << endl;
    displayArt(nekoCharacters["choco"].happyArt);
    
    // 角色选择
    cout << "===== 请选择今天要陪哪只猫娘玩猜数游戏喵~ =====" << endl;
    cout << "1. 巧克力 (活泼开朗) (^◕ᴥ◕^)" << endl;
    cout << "2. 香草 (文静温柔) (´･ω･`)" << endl;
    cout << "3. 红豆 (傲娇) (｀ε´)" << endl;
    cout << "===========================================" << endl;
    cout << "请选择喵~ (1-3): ";
    
    int charChoice;
    cin >> charChoice;
    
    if (charChoice == 1) {
        currentCharacter = "choco";
        cout << "\n巧克力: 喵哈~主人选我啦！今天要好好陪人家玩哦！" << endl;
    } else if (charChoice == 2) {
        currentCharacter = "vanilla";
        cout << "\n香草: 喵...主人选择了我吗？我会努力的..." << endl;
    } else if (charChoice == 3) {
        currentCharacter = "azuki";
        cout << "\n红豆: 哼！既然主人选了我，那就勉为其难陪你玩吧！" << endl;
    } else {
        cout << "喵~无效的选择，默认选择巧克力喵~" << endl;
        currentCharacter = "choco";
    }
    
    while (playAgain) {
        cout << "\n===== 主菜单喵~ =====" << endl;
        cout << "1. 开始新游戏" << endl;
        cout << "2. 设置游戏参数" << endl;
        cout << "3. 查看游戏帮助" << endl;
        cout << "4. 重新选择猫娘" << endl;
        cout << "5. 退出游戏" << endl;
        cout << "=====================" << endl;
        cout << "请选择喵~: ";
        
        int choice;
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "喵~要输入数字啦主人！" << endl;
            continue;
        }
        
        switch (choice) {
            case 1: // 开始游戏
                playGame(minRange, maxRange, nekoCharacters[currentCharacter]);
                break;
                
            case 2: // 设置参数
                cout << "请输入最小数字喵~: ";
                cin >> minRange;
                cout << "请输入最大数字喵~: ";
                cin >> maxRange;
                
                // 确保范围有效
                if (minRange >= maxRange) {
                    cout << "喵~范围无效啦！人家自动帮主人调整喵~" << endl;
                    swap(minRange, maxRange);
                }
                cout << "范围已设置为: " << minRange << " ~ " << maxRange << endl;
                displayArt(nekoCharacters[currentCharacter].thinkArt);
                cout << nekoCharacters[currentCharacter].name << ": 喵~参数设置完成啦！" << endl;
                continue;
                
            case 3: // 游戏帮助
                showHelp();
                continue;
                
            case 4: // 重新选择猫娘
                cout << "===== 请选择今天要陪哪只猫娘玩猜数游戏喵~ =====" << endl;
                cout << "1. 巧克力 (活泼开朗) (^◕ᴥ◕^)" << endl;
                cout << "2. 香草 (文静温柔) (´･ω･`)" << endl;
                cout << "3. 红豆 (傲娇) (｀ε´)" << endl;
                cout << "===========================================" << endl;
                cout << "请选择喵~ (1-3): ";
                
                cin >> charChoice;
                
                if (charChoice == 1) {
                    currentCharacter = "choco";
                    cout << "\n巧克力: 喵哈~主人又选我啦！今天也要好好玩哦！" << endl;
                } else if (charChoice == 2) {
                    currentCharacter = "vanilla";
                    cout << "\n香草: 喵...主人又选择了我吗？我会继续努力的..." << endl;
                } else if (charChoice == 3) {
                    currentCharacter = "azuki";
                    cout << "\n红豆: 哼！既然主人又选了我，那就再陪你玩一次吧！" << endl;
                } else {
                    cout << "喵~无效的选择，保持当前猫娘喵~" << endl;
                }
                continue;
                
            case 5: // 退出游戏
                playAgain = false;
                displayArt(nekoCharacters[currentCharacter].happyArt);
                cout << nekoCharacters[currentCharacter].name << ": 谢谢主人陪人家玩喵~再见啦！" << endl;
                break;
                
            default:
                cout << "喵~无效的选择啦！请重新选择喵~" << endl;
                continue;
        }
        
        if (choice != 5 && playAgain) {
            cout << "\n主人想做什么喵？" << endl;
            cout << "1. 再玩一次 (相同范围)" << endl;
            cout << "2. 重新设置范围" << endl;
            cout << "3. 返回主菜单" << endl;
            cout << "4. 退出游戏" << endl;
            cout << "请选择喵~: ";
            
            int option;
            cin >> option;
            
            if (option == 4) {
                playAgain = false;
                displayArt(nekoCharacters[currentCharacter].happyArt);
                cout << nekoCharacters[currentCharacter].name << ": 谢谢主人陪人家玩喵~再见啦！" << endl;
            } else if (option == 2) {
                cout << "请输入新的最小数字喵~: ";
                cin >> minRange;
                cout << "请输入新的最大数字喵~: ";
                cin >> maxRange;
            } else if (option == 1) {
                // 直接使用相同范围重新开始
                continue;
            }
        }
    }
    
    return 0;
}
