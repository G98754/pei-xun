#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 插入排序函数
// 功能：将数组按升序排序，采用插入排序算法
// 原理：从第二个元素开始，将其插入到前面已经排好序的部分中
void InsertSort(int arr[], int n) {
    int i, j, key;
    // 从第二个元素开始遍历数组
    for (i = 1; i < n; i++) {
        // 取出当前元素
        key = arr[i];
        // 从当前元素的前一个元素开始向前比较
        j = i - 1;
        // 当前面的元素比当前元素大时，将前面的元素后移
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // 将当前元素插入到合适的位置
        arr[j + 1] = key;
    }
}

// 合并两个子数组的函数
// 功能：将两个有序的子数组合并成一个有序的数组
// 原理：分别从两个子数组的开头开始比较，将较小的元素依次放入新数组中
void merge(int arr[], int l, int m, int r) {
    // 计算左右子数组的长度
    int n1 = m - l + 1;
    int n2 = r - m;
    // 创建左右子数组
    int L[n1], R[n2];
    int i, j, k;

    // 将原数组的元素复制到左右子数组中
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // 初始化左右子数组的索引和原数组的索引
    i = 0;
    j = 0;
    k = l;
    // 比较左右子数组的元素，将较小的元素放入原数组中
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // 将左子数组中剩余的元素放入原数组中
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // 将右子数组中剩余的元素放入原数组中
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序函数
// 功能：将数组按升序排序，采用归并排序算法
// 原理：将数组不断分成两半，分别对左右子数组进行排序，然后合并
void MergeSort(int arr[], int l, int r) {
    if (l < r) {
        // 计算中间位置
        int m = l + (r - l) / 2;
        // 对左子数组进行排序
        MergeSort(arr, l, m);
        // 对右子数组进行排序
        MergeSort(arr, m + 1, r);
        // 合并左右子数组
        merge(arr, l, m, r);
    }
}

// 快速排序的分区函数
// 功能：选择一个基准元素，将数组分为两部分，左边部分小于基准元素，右边部分大于基准元素
// 原理：从数组的左边开始，找到第一个大于基准元素的元素，从数组的右边开始，找到第一个小于基准元素的元素，然后交换它们
int partition(int arr[], int low, int high) {
    // 选择最后一个元素作为基准元素
    int pivot = arr[high];
    // 初始化小于基准元素的元素的索引
    int i = (low - 1);
    int j;
    // 遍历数组
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // 交换元素
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // 将基准元素放到正确的位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    // 返回基准元素的位置
    return (i + 1);
}

// 快速排序（递归版）函数
// 功能：将数组按升序排序，采用快速排序算法
// 原理：选择一个基准元素，将数组分为两部分，分别对左右子数组进行排序
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        // 进行分区操作，得到基准元素的位置
        int pi = partition(arr, low, high);
        // 对左子数组进行排序
        QuickSort(arr, low, pi - 1);
        // 对右子数组进行排序
        QuickSort(arr, pi + 1, high);
    }
}

// 计数排序函数
// 功能：将数组按升序排序，采用计数排序算法
// 原理：统计每个元素出现的次数，然后根据统计结果将元素放回原数组中
void CountSort(int arr[], int n) {
    // 找到数组中的最大值
    int max_value = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    // 分配内存用于统计每个元素出现的次数
    int *count = (int *)calloc(max_value + 1, sizeof(int));
    if (count == NULL) {
        fprintf(stderr, "Memory allocation failed for CountSort\n");
        return;
    }
    // 统计每个元素出现的次数
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    // 根据统计结果将元素放回原数组中
    for (i = 0; i <= max_value; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
    // 释放内存
    free(count);
}

// 获取数字的第 d 位数字的函数
// 功能：返回一个整数的第 d 位数字
// 原理：通过除法和取模运算得到指定位置的数字
int getDigit(int num, int d) {
    int divisor = 1;
    // 计算除数
    while (d > 0) {
        divisor *= 10;
        d--;
    }
    // 返回第 d 位数字
    return (num / divisor) % 10;
}

// 基数计数排序函数
// 功能：将数组按升序排序，采用基数计数排序算法
// 原理：从最低位开始，依次对每一位进行计数排序
void RadixCountSort(int arr[], int n) {
    // 找到数组中的最大值
    int max_value = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    int exp = 1;
    // 分配内存用于临时存储排序结果
    int *temp = (int *)malloc(n * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed for RadixCountSort\n");
        return;
    }
    // 从最低位开始，依次对每一位进行计数排序
    while (max_value / exp > 0) {
        int bucket[10] = {0};
        // 统计每个数字出现的次数
        for (i = 0; i < n; i++) {
            bucket[getDigit(arr[i], exp - 1)]++;
        }
        // 计算每个数字的最终位置
        for (i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }
        // 将元素按顺序放入临时数组中
        for (i = n - 1; i >= 0; i--) {
            temp[--bucket[getDigit(arr[i], exp - 1)]] = arr[i];
        }
        // 将临时数组中的元素复制回原数组
        for (i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
        // 处理下一位
        exp *= 10;
    }
    // 释放内存
    free(temp);
}

// 测试函数，计算排序函数运行时间
// 功能：计算指定排序函数对数组进行排序所需的时间
// 原理：记录排序前后的时钟时间，计算差值并转换为秒
double test_sort(void (*sort_func)(int[], int), int arr[], int n) {
    clock_t start, end;
    double cpu_time_used;
    // 记录排序开始的时钟时间
    start = clock();
    // 调用排序函数
    sort_func(arr, n);
    // 记录排序结束的时钟时间
    end = clock();
    // 计算排序所需的时间
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

// 专门为 MergeSort 和 QuickSort 设计的测试函数
// 功能：计算 MergeSort 和 QuickSort 对数组进行排序所需的时间
// 原理：与 test_sort 函数类似，但处理的排序函数参数不同
double test_sort_with_range(void (*sort_func)(int[], int, int), int arr[], int n) {
    clock_t start, end;
    double cpu_time_used;
    // 记录排序开始的时钟时间
    start = clock();
    // 调用排序函数
    sort_func(arr, 0, n - 1);
    // 记录排序结束的时钟时间
    end = clock();
    // 计算排序所需的时间
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

// 测试不同大小的数据
// 功能：对指定大小的数组进行排序测试，并输出每种排序算法的运行时间
// 原理：生成随机数组，调用不同的排序函数进行排序，并记录时间
void test_different_sizes(int data_size) {
    // 分配内存用于存储随机数组
    int *arr = (int *)malloc(data_size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed for data size %d\n", data_size);
        return;
    }
    // 生成随机数组
    for (int j = 0; j < data_size; j++) {
        arr[j] = rand() % 100000;
    }
    // 输出数据大小
    printf("Data size: %d\n", data_size);
    // 测试插入排序并输出时间
    printf("InsertSort time: %f seconds\n", test_sort(InsertSort, arr, data_size));
    // 测试归并排序并输出时间
    printf("MergeSort time: %f seconds\n", test_sort_with_range(MergeSort, arr, data_size));
    // 测试快速排序并输出时间
    printf("QuickSort time: %f seconds\n", test_sort_with_range(QuickSort, arr, data_size));
    // 测试计数排序并输出时间
    printf("CountSort time: %f seconds\n", test_sort(CountSort, arr, data_size));
    // 测试基数计数排序并输出时间
    printf("RadixCountSort time: %f seconds\n", test_sort(RadixCountSort, arr, data_size));
    // 释放内存
    free(arr);
}

// 测试小数据多次排序
// 功能：对大小为 100 的数组进行多次排序测试，并输出每种排序算法的总运行时间
// 原理：多次生成随机数组，调用不同的排序函数进行排序，并累加时间
void test_small_data(int num_sorts) {
    int arr[100];
    int i, j;
    double insert_time = 0, merge_time = 0, quick_time = 0, count_time = 0, radix_time = 0;

    // 多次进行排序测试
    for (i = 0; i < num_sorts; i++) {
        // 生成随机数组
        for (j = 0; j < 100; j++) {
            arr[j] = rand() % 100;
        }
        // 累加插入排序的时间
        insert_time += test_sort(InsertSort, arr, 100);
        // 累加归并排序的时间
        merge_time += test_sort_with_range(MergeSort, arr, 100);
        // 累加快速排序的时间
        quick_time += test_sort_with_range(QuickSort, arr, 100);
        // 累加计数排序的时间
        count_time += test_sort(CountSort, arr, 100);
        // 累加基数计数排序的时间
        radix_time += test_sort(RadixCountSort, arr, 100);
    }

    // 输出测试信息
    printf("Testing with 100 data sorted %d times\n", num_sorts);
    // 输出插入排序的总时间
    printf("InsertSort time: %f seconds\n", insert_time);
    // 输出归并排序的总时间
    printf("MergeSort time: %f seconds\n", merge_time);
    // 输出快速排序的总时间
    printf("QuickSort time: %f seconds\n", quick_time);
    // 输出计数排序的总时间
    printf("CountSort time: %f seconds\n", count_time);
    // 输出基数计数排序的总时间
    printf("RadixCountSort time: %f seconds\n", radix_time);
}

// 生成测试数据并保存到文件
// 功能：生成指定大小的随机数组，并将其保存到指定文件中
// 原理：生成随机数并写入文件
void generate_and_save_data(int data_size, const char *file_path) {
    // 打开文件以写入数据
    FILE *fp = fopen(file_path, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }
    int i;
    // 生成随机数并写入文件
    for (i = 0; i < data_size; i++) {
        fprintf(fp, "%d\n", rand() % 100000);
    }
    // 关闭文件
    fclose(fp);
}

// 从文件读取数据并排序
// 功能：从指定文件中读取数据，对其进行排序，并输出排序结果
// 原理：读取文件内容，将其存储到数组中，调用排序函数进行排序，然后输出结果
void read_and_sort(const char *file_path, void (*sort_func)(int[], int)) {
    // 打开文件以读取数据
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    int *arr = NULL;
    int capacity = 0;
    int size = 0;
    int num;
    // 读取文件内容并存储到数组中
    while (fscanf(fp, "%d", &num) == 1) {
        if (size >= capacity) {
            capacity = capacity == 0? 1 : capacity * 2;
            int *new_arr = (int *)realloc(arr, capacity * sizeof(int));
            if (new_arr == NULL) {
                fprintf(stderr, "Memory allocation failed while reading file\n");
                fclose(fp);
                free(arr);
                return;
            }
            arr = new_arr;
        }
        arr[size++] = num;
    }
    // 关闭文件
    fclose(fp);
    // 调用排序函数进行排序
    sort_func(arr, size);
    // 输出排序结果
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // 释放内存
    free(arr);
}

// 假设的排序应用函数（这里就是简单调用排序算法）
// 功能：对数组进行插入排序
// 原理：调用 InsertSort 函数
void sort_application(int arr[], int n) {
    InsertSort(arr, n);
}

int main() {
    // 初始化随机数种子
    srand(time(NULL));
    int choice;
    int num_sorts = 100000;
    const char *file_path = "test_data.txt";

    while (1) {
        // 输出主菜单
        printf("\nSorting Algorithm Tester\n");
        printf("1. Test different data sizes\n");
        printf("2. Test small data multiple times\n");
        printf("3. Generate and sort data from file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        // 读取用户输入
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // 清除输入缓冲区
            continue;
        }

        switch (choice) {
            case 1: {
                int data_size;
                while (1) {
                    // 提示用户选择数据大小
                    printf("Choose data size (1: 50000, 2: 10000, 3: 200000, other: back to main menu): ");
                    if (scanf("%d", &choice) != 1) {
                        printf("Invalid input. Please enter a valid number.\n");
                        while (getchar() != '\n'); // 清除输入缓冲区
                        continue;
                    }
                    switch (choice) {
                        case 1:
                            data_size = 50000;
                            break;
                        case 2:
                            data_size = 10000;
                            break;
                        case 3:
                            data_size = 200000;
                            break;
                        default:
                            // 跳出内层循环，返回主菜单
                            break;
                    }
                    if (choice >= 1 && choice <= 3) {
                        // 进行排序测试
                        test_different_sizes(data_size);
                    } else {
                        break;
                    }
                }
                break;
            }
            case 2:
                // 进行小数据多次排序测试
                test_small_data(num_sorts);
                break;
            case 3: {
                int file_choice;
                // 提示用户选择生成数据还是读取数据
                printf("1. Generate data\n");
                printf("2. Read data from file\n");
                printf("Enter your choice: ");
                if (scanf("%d", &file_choice) != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n'); // 清除输入缓冲区
                    continue;
                }
                if (file_choice == 1) {
                    int data_size;
                    // 提示用户输入生成数据的大小
                    printf("Enter the size of data to generate: ");
                    if (scanf("%d", &data_size) != 1) {
                        printf("Invalid input. Please enter a valid number.\n");
                        while (getchar() != '\n'); // 清除输入缓冲区
                        continue;
                    }
                    // 生成数据并保存到文件
                    generate_and_save_data(data_size, file_path);
                    // 提示用户数据已保存，并告知排序开始
                    printf("Generated data saved to %s. Now sorting...\n", file_path);
                    // 从文件读取数据并排序
                    read_and_sort(file_path, InsertSort);
                } else if (file_choice == 2) {
                    char input_file_path[1024];
                    // 提示用户输入文件的绝对路径
                    printf("Enter the absolute path of the file: ");
                    scanf("%s", input_file_path);
                    // 从文件读取数据并排序
                    read_and_sort(input_file_path, InsertSort);
                } else {
                    printf("Invalid choice. Please try again.\n");
                }
                break;
            }
            case 4:
                // 退出程序
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}    
