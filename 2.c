#include <stdio.h>
#include <string.h>

void DigiTran(int k, char res[]) {
    char temp[20]; // 暂存数字转成字符的过程
    int len = 0;   // res 的索引

    // 将整数 k 转换为字符数组 temp
    sprintf(temp, "%d", k);
    int i = 0;
    
    // 遍历 temp
    while (temp[i] != '\0') {
        // 尝试获取两位数字
        if (temp[i + 1] != '\0') {
            int two_digit = (temp[i] - '0') * 10 + (temp[i + 1] - '0');
            if (two_digit >= 0 && two_digit <= 25) {
                res[len++] = 'A' + two_digit; // 将两位数转换为字母
                i += 2; // 跳过两位
                continue;
            }
        }
        // 处理单个数字
        res[len++] = 'A' + (temp[i] - '0');
        i++;
    }
    
    // 结尾加上字符串结束符
    res[len] = '\0';
}

int main() {
    int k;
    char result[20]; // 存放转换后的字符串

    while (1) {
        scanf("%d", &k);
        if (k == -1) break; // 读到 -1 结束输入
        
        DigiTran(k, result); // 调用函数进行转换
        printf("%s ", result); // 输出转换结果
    }
    
    return 0;
}


