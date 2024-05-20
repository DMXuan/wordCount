#include <stdio.h> // ���ڱ�׼�����������  
  
// ����ԭ������  
int count_characters(FILE *file);  
int count_words(FILE *file);  
  
int main(int argc, char *argv[]) {  
    FILE *file;  
    char mode;  
  
    // ����������  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    // ��ȡ���� '-c' �� '-w' �ĵڶ����ַ�  
    mode = argv[1][1];  
  
    // ���ļ�  
    file = fopen(argv[2], "r");  
    if (!file) {  
        perror("Error opening file");  
        return 1;  
    }  
  
    // ͳ���ַ����򵥴���  
    switch (mode) {  
        case 'c':     
            printf("�ַ�����%d\n", count_characters(file));  
            break;  
        case 'w':   
            printf("��������%d\n", count_words(file));  
            break;  
        default:  
            fprintf(stderr, "Invalid mode: %c\n", mode);  
            break;  
    }  
  
    // �ر��ļ�  
    fclose(file);  
    return 0;  
}  
  
// ͳ���ַ���  
int count_characters(FILE *file) {  
    int count = 0;  
    int ch;  
    // ���ַ���ȡ������  
    while ((ch = fgetc(file)) != EOF) {  
        count++;  
    }  

    return count;  
}  
  
// ͳ�Ƶ����� 
int count_words(FILE *file) {  
    int count = 0;  
    int in_word = 0; // ��ʾ��ǰ�Ƿ��ڵ�����  
    int ch;  
    // ���ַ���ȡ�����ݿո񡢶��ŵȷָ����жϵ���  
    while ((ch = fgetc(file)) != EOF) {  
        if (ch==' ' || ch=='\n'||ch == ',') { // ��������ո񡢻��з��򶺺ţ�����Ϊ���ʽ���  
            in_word = 0;  
        } else if (!in_word) { // ���֮ǰ���ڵ����ڣ�������������ĸ�����֣�����Ϊ���ʿ�ʼ  
            in_word = 1;  
            count++;  
        }  
    }  
    return count;  
}
