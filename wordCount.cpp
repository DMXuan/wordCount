#include <stdio.h> // 用于标准输入输出函数  
  
// 函数原型声明  
int count_characters(FILE *file);  
int count_words(FILE *file);  
  
int main(int argc, char *argv[]) {  
    FILE *file;  
    char mode;  
  
    // 检查参数数量  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    // 获取参数 '-c' 或 '-w' 的第二个字符  
    mode = argv[1][1];  
  
    // 打开文件  
    file = fopen(argv[2], "r");  
    if (!file) {  
        perror("Error opening file");  
        return 1;  
    }  
  
    // 统计字符数或单词数  
    switch (mode) {  
        case 'c':     
            printf("字符数：%d\n", count_characters(file));  
            break;  
        case 'w':   
            printf("单词数：%d\n", count_words(file));  
            break;  
        default:  
            fprintf(stderr, "Invalid mode: %c\n", mode);  
            break;  
    }  
  
    // 关闭文件  
    fclose(file);  
    return 0;  
}  
  
// 统计字符数  
int count_characters(FILE *file) {  
    int count = 0;  
    int ch;  
    // 逐字符读取并计数  
    while ((ch = fgetc(file)) != EOF) {  
        count++;  
    }  

    return count;  
}  
  
// 统计单词数 
int count_words(FILE *file) {  
    int count = 0;  
    int in_word = 0; // 表示当前是否在单词内  
    int ch;  
    // 逐字符读取并根据空格、逗号等分隔符判断单词  
    while ((ch = fgetc(file)) != EOF) {  
        if (ch==' ' || ch=='\n'||ch == ',') { // 如果遇到空格、换行符或逗号，则认为单词结束  
            in_word = 0;  
        } else if (!in_word) { // 如果之前不在单词内，现在遇到了字母或数字，则认为单词开始  
            in_word = 1;  
            count++;  
        }  
    }  
    return count;  
}
