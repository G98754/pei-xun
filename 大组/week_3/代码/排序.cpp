#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ����������
// ���ܣ������鰴�������򣬲��ò��������㷨
// ԭ���ӵڶ���Ԫ�ؿ�ʼ��������뵽ǰ���Ѿ��ź���Ĳ�����
void InsertSort(int arr[], int n) {
    int i, j, key;
    // �ӵڶ���Ԫ�ؿ�ʼ��������
    for (i = 1; i < n; i++) {
        // ȡ����ǰԪ��
        key = arr[i];
        // �ӵ�ǰԪ�ص�ǰһ��Ԫ�ؿ�ʼ��ǰ�Ƚ�
        j = i - 1;
        // ��ǰ���Ԫ�رȵ�ǰԪ�ش�ʱ����ǰ���Ԫ�غ���
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // ����ǰԪ�ز��뵽���ʵ�λ��
        arr[j + 1] = key;
    }
}

// �ϲ�����������ĺ���
// ���ܣ������������������ϲ���һ�����������
// ԭ���ֱ������������Ŀ�ͷ��ʼ�Ƚϣ�����С��Ԫ�����η�����������
void merge(int arr[], int l, int m, int r) {
    // ��������������ĳ���
    int n1 = m - l + 1;
    int n2 = r - m;
    // ��������������
    int L[n1], R[n2];
    int i, j, k;

    // ��ԭ�����Ԫ�ظ��Ƶ�������������
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // ��ʼ�������������������ԭ���������
    i = 0;
    j = 0;
    k = l;
    // �Ƚ������������Ԫ�أ�����С��Ԫ�ط���ԭ������
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
    // ������������ʣ���Ԫ�ط���ԭ������
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // ������������ʣ���Ԫ�ط���ԭ������
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// �鲢������
// ���ܣ������鰴�������򣬲��ù鲢�����㷨
// ԭ�������鲻�Ϸֳ����룬�ֱ�������������������Ȼ��ϲ�
void MergeSort(int arr[], int l, int r) {
    if (l < r) {
        // �����м�λ��
        int m = l + (r - l) / 2;
        // �����������������
        MergeSort(arr, l, m);
        // �����������������
        MergeSort(arr, m + 1, r);
        // �ϲ�����������
        merge(arr, l, m, r);
    }
}

// ��������ķ�������
// ���ܣ�ѡ��һ����׼Ԫ�أ��������Ϊ�����֣���߲���С�ڻ�׼Ԫ�أ��ұ߲��ִ��ڻ�׼Ԫ��
// ԭ�����������߿�ʼ���ҵ���һ�����ڻ�׼Ԫ�ص�Ԫ�أ���������ұ߿�ʼ���ҵ���һ��С�ڻ�׼Ԫ�ص�Ԫ�أ�Ȼ�󽻻�����
int partition(int arr[], int low, int high) {
    // ѡ�����һ��Ԫ����Ϊ��׼Ԫ��
    int pivot = arr[high];
    // ��ʼ��С�ڻ�׼Ԫ�ص�Ԫ�ص�����
    int i = (low - 1);
    int j;
    // ��������
    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // ����Ԫ��
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // ����׼Ԫ�طŵ���ȷ��λ��
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    // ���ػ�׼Ԫ�ص�λ��
    return (i + 1);
}

// �������򣨵ݹ�棩����
// ���ܣ������鰴�������򣬲��ÿ��������㷨
// ԭ��ѡ��һ����׼Ԫ�أ��������Ϊ�����֣��ֱ�������������������
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        // ���з����������õ���׼Ԫ�ص�λ��
        int pi = partition(arr, low, high);
        // �����������������
        QuickSort(arr, low, pi - 1);
        // �����������������
        QuickSort(arr, pi + 1, high);
    }
}

// ����������
// ���ܣ������鰴�������򣬲��ü��������㷨
// ԭ��ͳ��ÿ��Ԫ�س��ֵĴ�����Ȼ�����ͳ�ƽ����Ԫ�طŻ�ԭ������
void CountSort(int arr[], int n) {
    // �ҵ������е����ֵ
    int max_value = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    // �����ڴ�����ͳ��ÿ��Ԫ�س��ֵĴ���
    int *count = (int *)calloc(max_value + 1, sizeof(int));
    if (count == NULL) {
        fprintf(stderr, "Memory allocation failed for CountSort\n");
        return;
    }
    // ͳ��ÿ��Ԫ�س��ֵĴ���
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    // ����ͳ�ƽ����Ԫ�طŻ�ԭ������
    for (i = 0; i <= max_value; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
    // �ͷ��ڴ�
    free(count);
}

// ��ȡ���ֵĵ� d λ���ֵĺ���
// ���ܣ�����һ�������ĵ� d λ����
// ԭ��ͨ��������ȡģ����õ�ָ��λ�õ�����
int getDigit(int num, int d) {
    int divisor = 1;
    // �������
    while (d > 0) {
        divisor *= 10;
        d--;
    }
    // ���ص� d λ����
    return (num / divisor) % 10;
}

// ��������������
// ���ܣ������鰴�������򣬲��û������������㷨
// ԭ�������λ��ʼ�����ζ�ÿһλ���м�������
void RadixCountSort(int arr[], int n) {
    // �ҵ������е����ֵ
    int max_value = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    int exp = 1;
    // �����ڴ�������ʱ�洢������
    int *temp = (int *)malloc(n * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed for RadixCountSort\n");
        return;
    }
    // �����λ��ʼ�����ζ�ÿһλ���м�������
    while (max_value / exp > 0) {
        int bucket[10] = {0};
        // ͳ��ÿ�����ֳ��ֵĴ���
        for (i = 0; i < n; i++) {
            bucket[getDigit(arr[i], exp - 1)]++;
        }
        // ����ÿ�����ֵ�����λ��
        for (i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }
        // ��Ԫ�ذ�˳�������ʱ������
        for (i = n - 1; i >= 0; i--) {
            temp[--bucket[getDigit(arr[i], exp - 1)]] = arr[i];
        }
        // ����ʱ�����е�Ԫ�ظ��ƻ�ԭ����
        for (i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
        // ������һλ
        exp *= 10;
    }
    // �ͷ��ڴ�
    free(temp);
}

// ���Ժ�������������������ʱ��
// ���ܣ�����ָ��������������������������ʱ��
// ԭ����¼����ǰ���ʱ��ʱ�䣬�����ֵ��ת��Ϊ��
double test_sort(void (*sort_func)(int[], int), int arr[], int n) {
    clock_t start, end;
    double cpu_time_used;
    // ��¼����ʼ��ʱ��ʱ��
    start = clock();
    // ����������
    sort_func(arr, n);
    // ��¼���������ʱ��ʱ��
    end = clock();
    // �������������ʱ��
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

// ר��Ϊ MergeSort �� QuickSort ��ƵĲ��Ժ���
// ���ܣ����� MergeSort �� QuickSort ������������������ʱ��
// ԭ���� test_sort �������ƣ��������������������ͬ
double test_sort_with_range(void (*sort_func)(int[], int, int), int arr[], int n) {
    clock_t start, end;
    double cpu_time_used;
    // ��¼����ʼ��ʱ��ʱ��
    start = clock();
    // ����������
    sort_func(arr, 0, n - 1);
    // ��¼���������ʱ��ʱ��
    end = clock();
    // �������������ʱ��
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

// ���Բ�ͬ��С������
// ���ܣ���ָ����С���������������ԣ������ÿ�������㷨������ʱ��
// ԭ������������飬���ò�ͬ���������������򣬲���¼ʱ��
void test_different_sizes(int data_size) {
    // �����ڴ����ڴ洢�������
    int *arr = (int *)malloc(data_size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed for data size %d\n", data_size);
        return;
    }
    // �����������
    for (int j = 0; j < data_size; j++) {
        arr[j] = rand() % 100000;
    }
    // ������ݴ�С
    printf("Data size: %d\n", data_size);
    // ���Բ����������ʱ��
    printf("InsertSort time: %f seconds\n", test_sort(InsertSort, arr, data_size));
    // ���Թ鲢�������ʱ��
    printf("MergeSort time: %f seconds\n", test_sort_with_range(MergeSort, arr, data_size));
    // ���Կ����������ʱ��
    printf("QuickSort time: %f seconds\n", test_sort_with_range(QuickSort, arr, data_size));
    // ���Լ����������ʱ��
    printf("CountSort time: %f seconds\n", test_sort(CountSort, arr, data_size));
    // ���Ի��������������ʱ��
    printf("RadixCountSort time: %f seconds\n", test_sort(RadixCountSort, arr, data_size));
    // �ͷ��ڴ�
    free(arr);
}

// ����С���ݶ������
// ���ܣ��Դ�СΪ 100 ��������ж��������ԣ������ÿ�������㷨��������ʱ��
// ԭ���������������飬���ò�ͬ���������������򣬲��ۼ�ʱ��
void test_small_data(int num_sorts) {
    int arr[100];
    int i, j;
    double insert_time = 0, merge_time = 0, quick_time = 0, count_time = 0, radix_time = 0;

    // ��ν����������
    for (i = 0; i < num_sorts; i++) {
        // �����������
        for (j = 0; j < 100; j++) {
            arr[j] = rand() % 100;
        }
        // �ۼӲ��������ʱ��
        insert_time += test_sort(InsertSort, arr, 100);
        // �ۼӹ鲢�����ʱ��
        merge_time += test_sort_with_range(MergeSort, arr, 100);
        // �ۼӿ��������ʱ��
        quick_time += test_sort_with_range(QuickSort, arr, 100);
        // �ۼӼ��������ʱ��
        count_time += test_sort(CountSort, arr, 100);
        // �ۼӻ������������ʱ��
        radix_time += test_sort(RadixCountSort, arr, 100);
    }

    // ���������Ϣ
    printf("Testing with 100 data sorted %d times\n", num_sorts);
    // ��������������ʱ��
    printf("InsertSort time: %f seconds\n", insert_time);
    // ����鲢�������ʱ��
    printf("MergeSort time: %f seconds\n", merge_time);
    // ��������������ʱ��
    printf("QuickSort time: %f seconds\n", quick_time);
    // ��������������ʱ��
    printf("CountSort time: %f seconds\n", count_time);
    // ������������������ʱ��
    printf("RadixCountSort time: %f seconds\n", radix_time);
}

// ���ɲ������ݲ����浽�ļ�
// ���ܣ�����ָ����С��������飬�����䱣�浽ָ���ļ���
// ԭ�������������д���ļ�
void generate_and_save_data(int data_size, const char *file_path) {
    // ���ļ���д������
    FILE *fp = fopen(file_path, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }
    int i;
    // �����������д���ļ�
    for (i = 0; i < data_size; i++) {
        fprintf(fp, "%d\n", rand() % 100000);
    }
    // �ر��ļ�
    fclose(fp);
}

// ���ļ���ȡ���ݲ�����
// ���ܣ���ָ���ļ��ж�ȡ���ݣ�����������򣬲����������
// ԭ����ȡ�ļ����ݣ�����洢�������У�������������������Ȼ��������
void read_and_sort(const char *file_path, void (*sort_func)(int[], int)) {
    // ���ļ��Զ�ȡ����
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    int *arr = NULL;
    int capacity = 0;
    int size = 0;
    int num;
    // ��ȡ�ļ����ݲ��洢��������
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
    // �ر��ļ�
    fclose(fp);
    // ������������������
    sort_func(arr, size);
    // ���������
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // �ͷ��ڴ�
    free(arr);
}

// ���������Ӧ�ú�����������Ǽ򵥵��������㷨��
// ���ܣ���������в�������
// ԭ������ InsertSort ����
void sort_application(int arr[], int n) {
    InsertSort(arr, n);
}

int main() {
    // ��ʼ�����������
    srand(time(NULL));
    int choice;
    int num_sorts = 100000;
    const char *file_path = "test_data.txt";

    while (1) {
        // ������˵�
        printf("\nSorting Algorithm Tester\n");
        printf("1. Test different data sizes\n");
        printf("2. Test small data multiple times\n");
        printf("3. Generate and sort data from file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        // ��ȡ�û�����
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // ������뻺����
            continue;
        }

        switch (choice) {
            case 1: {
                int data_size;
                while (1) {
                    // ��ʾ�û�ѡ�����ݴ�С
                    printf("Choose data size (1: 50000, 2: 10000, 3: 200000, other: back to main menu): ");
                    if (scanf("%d", &choice) != 1) {
                        printf("Invalid input. Please enter a valid number.\n");
                        while (getchar() != '\n'); // ������뻺����
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
                            // �����ڲ�ѭ�����������˵�
                            break;
                    }
                    if (choice >= 1 && choice <= 3) {
                        // �����������
                        test_different_sizes(data_size);
                    } else {
                        break;
                    }
                }
                break;
            }
            case 2:
                // ����С���ݶ���������
                test_small_data(num_sorts);
                break;
            case 3: {
                int file_choice;
                // ��ʾ�û�ѡ���������ݻ��Ƕ�ȡ����
                printf("1. Generate data\n");
                printf("2. Read data from file\n");
                printf("Enter your choice: ");
                if (scanf("%d", &file_choice) != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n'); // ������뻺����
                    continue;
                }
                if (file_choice == 1) {
                    int data_size;
                    // ��ʾ�û������������ݵĴ�С
                    printf("Enter the size of data to generate: ");
                    if (scanf("%d", &data_size) != 1) {
                        printf("Invalid input. Please enter a valid number.\n");
                        while (getchar() != '\n'); // ������뻺����
                        continue;
                    }
                    // �������ݲ����浽�ļ�
                    generate_and_save_data(data_size, file_path);
                    // ��ʾ�û������ѱ��棬����֪����ʼ
                    printf("Generated data saved to %s. Now sorting...\n", file_path);
                    // ���ļ���ȡ���ݲ�����
                    read_and_sort(file_path, InsertSort);
                } else if (file_choice == 2) {
                    char input_file_path[1024];
                    // ��ʾ�û������ļ��ľ���·��
                    printf("Enter the absolute path of the file: ");
                    scanf("%s", input_file_path);
                    // ���ļ���ȡ���ݲ�����
                    read_and_sort(input_file_path, InsertSort);
                } else {
                    printf("Invalid choice. Please try again.\n");
                }
                break;
            }
            case 4:
                // �˳�����
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}    
