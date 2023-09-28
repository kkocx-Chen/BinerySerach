//
// Created by 陳政揚 on 2023/9/28.
//
#include <iostream>
#include <fstream>
void SelectionSort (int *a,const int n){
    for (int i=0;i<n;i++){
        int j=i;
        for (int k=i+1;k<n;k++)
            if (a[k]<a[j]) j=k;
        std::swap(a[i],a[j]);
    }
}

void InputFile(const char* filename, int*& numbers, int& n){
    std::ifstream input(filename);
    if(!input){ //偵錯
        std::cerr << "無法打開 input 文件 " << filename << std::endl;
        return;
    }
    n = 0;  // 初始化 n 為 0

    while (input >> temp) {
        n++;  // 每讀取一個數字，增加 n 的計數
    }

    // 重置檔案指標到開頭
    input.clear();
    input.seekg(0L, std::ios::beg); // 註 此為fstream 用法 seekg 從第一行開始ios::beg 從頭開始

    numbers = new int[n];

    for(int i = 0; i < n; i++) {
        input >> numbers[i];
    }

    input.close();

}
void OutputFile(const char* filename, int*& numbers, int& n){
    std::ofstream output(filename);
    if(!output){    //偵錯
        std::cerr << "無法打開 output 文件 " << filename << std::endl;
        return;
    }
    for(int i=0;i<n;i++){
        output<<numbers[i]<<" "; //<< 由右至左
    }
    output.close();
}
int main(){
    int *numbers;
    int n;
    int select;
    std::cout << "請選擇模式 1-2: ";
    std::cin >> select;
    switch (select){
        case 1:
            InputFile("/Users/chenzhengyang/NFU-C/DataHW02/integers.txt",numbers,n);
            SelectionSort(numbers,n);
            OutputFile("/Users/chenzhengyang/NFU-C/DataHW02/sortedIntegers.txt",numbers,n);
            delete[] numbers;
            std::cout << "排序完成，結果已保存到 sortedIntegers.txt" << std::endl;
            break;
        case 2:

            break;


    }


    return 0;
}