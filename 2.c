#include <stdio.h>
#include <string.h>

void DigiTran(int k, char res[]) {
    char temp[20]; // �ݴ�����ת���ַ��Ĺ���
    int len = 0;   // res ������

    // ������ k ת��Ϊ�ַ����� temp
    sprintf(temp, "%d", k);
    int i = 0;
    
    // ���� temp
    while (temp[i] != '\0') {
        // ���Ի�ȡ��λ����
        if (temp[i + 1] != '\0') {
            int two_digit = (temp[i] - '0') * 10 + (temp[i + 1] - '0');
            if (two_digit >= 0 && two_digit <= 25) {
                res[len++] = 'A' + two_digit; // ����λ��ת��Ϊ��ĸ
                i += 2; // ������λ
                continue;
            }
        }
        // ����������
        res[len++] = 'A' + (temp[i] - '0');
        i++;
    }
    
    // ��β�����ַ���������
    res[len] = '\0';
}

int main() {
    int k;
    char result[20]; // ���ת������ַ���

    while (1) {
        scanf("%d", &k);
        if (k == -1) break; // ���� -1 ��������
        
        DigiTran(k, result); // ���ú�������ת��
        printf("%s ", result); // ���ת�����
    }
    
    return 0;
}


