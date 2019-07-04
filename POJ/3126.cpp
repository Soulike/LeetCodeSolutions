#include <cmath>
#include <queue>
#include <set>
#include <cstdio>

using namespace std;

bool isPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int min(int a, int b)
{
    return a > b ? b : a;
}

vector<int> divide(int x)
{
    int thousand = x / 1000;
    int hundred = (x - thousand * 1000) / 100;
    int ten = (x - thousand * 1000 - hundred * 100) / 10;
    int one = (x - thousand * 1000 - hundred * 100 - ten * 10);
    vector<int> ret;
    ret.push_back(thousand);
    ret.push_back(hundred);
    ret.push_back(ten);
    ret.push_back(one);
    return ret;
}

int find(int x, int target)
{
    if (x == target)
    {
        return 0;
    }

    set<int> changedNums;
    queue<int> queue1, queue2;
    queue1.push(x);
    changedNums.insert(x);
    int step = 0;
    int currentX = 0;
    int changed = 0;
    while (!queue1.empty() || !queue2.empty())
    {
        if (step % 2 == 0) // 使用 queue1，推入 queue2
        {
            while (!queue1.empty())
            {
                currentX = queue1.front();
                queue1.pop();
                vector<int> digits = divide(currentX);
                for (int i = 0; i < 10; i++)
                {
                    // 改变第四位
                    if (i != 0 && i != digits[0])
                    {
                        changed = i * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
                        if (changed == target)
                        {
                            return step + 1;
                        }
                        if (changedNums.find(changed) == changedNums.end() && isPrime(changed))
                        {
                            queue2.push(changed);
                            changedNums.insert(changed);
                        }
                    }
                    // 改变第三位
                    if (i != digits[1])
                    {
                        changed = digits[0] * 1000 + i * 100 + digits[2] * 10 + digits[3];
                        if (changed == target)
                        {
                            return step + 1;
                        }
                        if (changedNums.find(changed) == changedNums.end() && isPrime(changed))
                        {
                            queue2.push(changed);
                            changedNums.insert(changed);
                        }
                    }
                    // 改变第二位
                    if (i != digits[2])
                    {
                        changed = digits[0] * 1000 + digits[1] * 100 + i * 10 + digits[3];
                        if (changed == target)
                        {
                            return step + 1;
                        }
                        if (changedNums.find(changed) == changedNums.end() && isPrime(changed))
                        {
                            queue2.push(changed);
                            changedNums.insert(changed);
                        }
                    }
                    // 改变第一位
                    if (i != digits[3])
                    {
                        changed = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + i;
                        if (changed == target)
                        {
                            return step + 1;
                        }
                        if (changedNums.find(changed) == changedNums.end() && isPrime(changed))
                        {
                            queue2.push(changed);
                            changedNums.insert(changed);
                        }
                    }
                }
            }
            step++;
        }
        else // 使用 queue2，推入 queue1
        {
            while (!queue2.empty())
            {
                currentX = queue2.front();
                queue2.pop();
                vector<int> digits = divide(currentX);
                for (int i = 0; i < 10; i++)
                {
                    // 改变第四位
                    if (i != 0 && i != digits[0])
                    {
                        changed = i * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
                        if (changed == target)
                        {
                            return step + 1;
                        }
                        if (changedNums.find(changed) == changedNums.end() && isPrime(changed))
                        {
                            queue1.push(changed);
                            changedNums.insert(changed);
                        }
                    }
                    // 改变第三位
                    if (i != digits[1])
                    {
                        changed = digits[0] * 1000 + i * 100 + digits[2] * 10 + digits[3];
                        if (changed == target)
                        {
                            return step + 1;
                        }
                        if (changedNums.find(changed) == changedNums.end() && isPrime(changed))
                        {
                            queue1.push(changed);
                            changedNums.insert(changed);
                        }
                    }
                    // 改变第二位
                    if (i != digits[2])
                    {
                        changed = digits[0] * 1000 + digits[1] * 100 + i * 10 + digits[3];
                        if (changed == target)
                        {
                            return step + 1;
                        }
                        if (changedNums.find(changed) == changedNums.end() && isPrime(changed))
                        {
                            queue1.push(changed);
                            changedNums.insert(changed);
                        }
                    }
                    // 改变第一位
                    if (i != digits[3])
                    {
                        changed = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + i;
                        if (changed == target)
                        {
                            return step + 1;
                        }
                        if (changedNums.find(changed) == changedNums.end() && isPrime(changed))
                        {
                            queue1.push(changed);
                            changedNums.insert(changed);
                        }
                    }
                }
            }
            step++;
        }
    }

    return -1;
}

int main()
{
    int T;
    scanf("%d", &T);

    int source, target, step;

    while (T > 0)
    {
        scanf("%d %d", &source, &target);
        step = find(source, target);
        if (step == -1)
        {
            printf("Impossible");
        }
        else
        {
            printf("%d\n", step);
        }
        T--;
    }
}