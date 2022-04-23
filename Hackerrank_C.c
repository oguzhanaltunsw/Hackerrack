#define _CRT_SECURE_NO_WARNINGS

/**
* Playing With Characters
**/

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//
//#define MAX_LEN     100
//
//int main()
//{
//    char ch;
//    char s[MAX_LEN];
//    char sen[MAX_LEN];
//    scanf("%c", &ch);
//    scanf("%s", s);
//    scanf("\n");
//    scanf("%[^\n]%*c", sen);
//
//    printf("%c\n", ch);
//    printf("%s\n", s);
//    printf("%s\n", sen);
//
//
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    return 0;
//}

/**
* Sum and Difference of Two Numbers
**/

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//
//int main()
//{
//    int i1, i2;
//    float f1, f2;
//
//    scanf("%d %d", &i1, &i2);
//    scanf("%f %f", &f1, &f2);
//
//    printf("%d %d\n", i1 + i2, i1 - i2);
//    printf("%.1f %.1f\n", f1 + f2, f1 - f2);
//
//    return 0;
//}

/**
* Functions in C
**/

//#include <stdio.h>
//
//int max_of_four(int a, int b, int c, int d)
//{
//    int max = a;
//
//    if (b > max)
//        max = b;
//
//    if (c > max)
//        max = c;
//
//    if (d > max)
//        max = d;
//
//    return max;
//}
//
//int main() {
//    int a, b, c, d;
//    scanf("%d %d %d %d", &a, &b, &c, &d);
//    int ans = max_of_four(a, b, c, d);
//    printf("%d", ans);
//
//    return 0;
//}

/**
* Pointers in C
**/

//#include <stdio.h>
//
//void update(int* a, int* b) {
//    int temp = *a;
//    *a = *a + *b;
//    *b = temp > * b ? temp - *b : *b - temp;
//}
//
//int main() {
//    int a, b;
//    int* pa = &a, * pb = &b;
//
//    scanf("%d %d", &a, &b);
//    update(pa, pb);
//    printf("%d\n%d", a, b);
//
//    return 0;
//
//}

/**
* Post Transition
**/

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_STRING_LENGTH 6
//
//struct package
//{
//	char* id;
//	int weight;
//};
//
//typedef struct package package;
//
//struct post_office
//{
//	int min_weight;
//	int max_weight;
//	package* packages;
//	int packages_count;
//};
//
//typedef struct post_office post_office;
//
//struct town
//{
//	char* name;
//	post_office* offices;
//	int offices_count;
//};
//
//typedef struct town town;
//
//
//
//void print_all_packages(town t) {
//	printf("%s:\n", t.name);
//
//	for (int i = 0; i < t.offices_count; i++)
//	{
//		printf("\t%d:\n", i);
//		post_office* actPostOffice = t.offices + i;
//		for (int j = 0; j < actPostOffice->packages_count; j++)
//			printf("\t\t%s\n", actPostOffice->packages[j].id);
//	}
//
//}
//
//void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
//
//	post_office* source_office = source->offices + source_office_index;
//	post_office* target_office = target->offices + target_office_index;
//
//	int count = 0;
//
//	for (int i = 0; i < source_office->packages_count; i++)
//	{
//		if (source_office->packages[i].weight >= target_office->min_weight &&
//			source_office->packages[i].weight <= target_office->max_weight)
//		{
//			count++;
//		}
//	}
//
//	target_office->packages = (package*)realloc(target_office->packages, sizeof(package) * (target_office->packages_count + count));
//
//	if (target_office->packages == NULL)
//	{
//		printf("Memory Error\n");
//		exit(EXIT_FAILURE);
//	}
//	
//	count = 0;
//	for (int i = 0; i < source_office->packages_count; i++)
//	{
//		if (source_office->packages[i].weight >= target_office->min_weight &&
//			source_office->packages[i].weight <= target_office->max_weight)
//		{
//			target_office->packages[target_office->packages_count++] = source_office->packages[i];
//		}
//		else {
//			source_office->packages[count++] = source_office->packages[i];
//		}
//	}
//	source_office->packages_count = count;
//	source_office->packages = (package*)realloc(source_office->packages, sizeof(package) * (target_office->packages_count - count));
//
//	if (source_office->packages == NULL)
//	{
//		printf("Memory Error\n");
//		exit(EXIT_FAILURE);
//	}
//}
//
//town town_with_most_packages(town* towns, int towns_count) {
//	int max = -1;
//	town* result = towns;
//	for (int i = 0; i < towns_count; i++)
//	{
//		int temp = 0;
//
//		for (int j = 0; j < towns[i].offices_count; j++)
//			temp += towns[i].offices[j].packages_count;
//
//		if (temp > max)
//		{
//			max = temp;
//			result = &towns[i];
//		}
//	}
//
//	return *result;
//}
//
//town* find_town(town* towns, int towns_count, char* name) {
//	for (int i = 0; i < towns_count; i++)
//		if (!strcmp(towns[i].name, name))
//			return &towns[i];
//	return NULL;
//}
//
//int main()
//{
//	int towns_count;
//	scanf("%d", &towns_count);
//	town* towns = malloc(sizeof(town) * towns_count);
//	for (int i = 0; i < towns_count; i++) {
//		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
//		scanf("%s", towns[i].name);
//		scanf("%d", &towns[i].offices_count);
//		towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);
//		for (int j = 0; j < towns[i].offices_count; j++) {
//			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
//			towns[i].offices[j].packages = malloc(sizeof(package) * towns[i].offices[j].packages_count);
//			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
//				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
//				scanf("%s", towns[i].offices[j].packages[k].id);
//				scanf("%d", &towns[i].offices[j].packages[k].weight);
//			}
//		}
//	}
//	int queries;
//	scanf("%d", &queries);
//	char town_name[MAX_STRING_LENGTH];
//	while (queries--) {
//		int type;
//		scanf("%d", &type);
//		switch (type) {
//		case 1:
//			scanf("%s", town_name);
//			town* t = find_town(towns, towns_count, town_name);
//			print_all_packages(*t);
//			break;
//		case 2:
//			scanf("%s", town_name);
//			town* source = find_town(towns, towns_count, town_name);
//			int source_index;
//			scanf("%d", &source_index);
//			scanf("%s", town_name);
//			town* target = find_town(towns, towns_count, town_name);
//			int target_index;
//			scanf("%d", &target_index);
//			send_all_acceptable_packages(source, source_index, target, target_index);
//			break;
//		case 3:
//			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
//			break;
//		}
//	}
//	return 0;
//}

/**
* Conditional Statements in C
**/

//#include <assert.h>
//#include <limits.h>
//#include <math.h>
//#include <stdbool.h>
//#include <stddef.h>
//#include <stdint.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//char* readline();
//
//
//
//int main()
//{
//    char* n_endptr;
//    char* n_str = readline();
//    int n = strtol(n_str, &n_endptr, 10);
//
//    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }
//
//    if (n == 1)
//        printf("one\n");
//    else if (n == 2)
//        printf("two\n");
//    else if (n == 3)
//        printf("three\n");
//    else if (n == 4)
//        printf("four\n");
//    else if (n == 5)
//        printf("five\n");
//    else if (n == 6)
//        printf("six\n");
//    else if (n == 7)
//        printf("seven\n");
//    else if (n == 8)
//        printf("eight\n");
//    else if (n == 9)
//        printf("nine\n");
//    else
//        printf("Greater than 9\n");
//
//    return 0;
//}
//
//char* readline() {
//    size_t alloc_length = 1024;
//    size_t data_length = 0;
//    char* data = malloc(alloc_length);
//
//    while (true) {
//        char* cursor = data + data_length;
//        char* line = fgets(cursor, alloc_length - data_length, stdin);
//
//        if (!line) { break; }
//
//        data_length += strlen(cursor);
//
//        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }
//
//        size_t new_length = alloc_length << 1;
//        data = realloc(data, new_length);
//
//        if (!data) { break; }
//
//        alloc_length = new_length;
//    }
//
//    if (data[data_length - 1] == '\n') {
//        data[data_length - 1] = '\0';
//    }
//
//    data = realloc(data, data_length);
//
//    return data;
//}

/**
* Conditional Statements in C
**/


//#include <assert.h>
//#include <limits.h>
//#include <math.h>
//#include <stdbool.h>
//#include <stddef.h>
//#include <stdint.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//char* readline();
//
//
//
//int main()
//{
//    char* n_endptr;
//    char* n_str = readline();
//    int n = strtol(n_str, &n_endptr, 10);
//
//    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }
//
//    if(n == 1)
//        printf("one\n");
//    else if(n == 2)
//        printf("two\n");
//    else if(n == 3)
//        printf("three\n");
//    else if(n == 4)
//        printf("four\n");
//    else if(n == 5)
//        printf("five\n");
//    else if(n == 6)
//        printf("six\n");
//    else if(n == 7)
//        printf("seven\n");
//    else if(n == 8)
//        printf("eight\n");
//    else if(n == 9)
//        printf("nine\n");
//    else 
//        printf("Greater than 9\n");
//
//    return 0;
//}
//
//char* readline() {
//    size_t alloc_length = 1024;
//    size_t data_length = 0;
//    char* data = malloc(alloc_length);
//
//    while (true) {
//        char* cursor = data + data_length;
//        char* line = fgets(cursor, alloc_length - data_length, stdin);
//
//        if (!line) { break; }
//
//        data_length += strlen(cursor);
//
//        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }
//
//        size_t new_length = alloc_length << 1;
//        data = realloc(data, new_length);
//
//        if (!data) { break; }
//
//        alloc_length = new_length;
//    }
//
//    if (data[data_length - 1] == '\n') {
//        data[data_length - 1] = '\0';
//    }
//
//    data = realloc(data, data_length);
//
//    return data;
//}


/**
* For Loop in C
**/

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//
//void number_to_out(int n)
//{
//    if (n == 1)
//        printf("one\n");
//    else if (n == 2)
//        printf("two\n");
//    else if (n == 3)
//        printf("three\n");
//    else if (n == 4)
//        printf("four\n");
//    else if (n == 5)
//        printf("five\n");
//    else if (n == 6)
//        printf("six\n");
//    else if (n == 7)
//        printf("seven\n");
//    else if (n == 8)
//        printf("eight\n");
//    else if (n == 9)
//        printf("nine\n");
//    else if (n % 2 == 0)
//        printf("even\n");
//    else
//        printf("odd\n");
//}
//
//int main()
//{
//    int a, b;
//    scanf("%d\n%d", &a, &b);
//
//    for (; a <= b; a++)
//        number_to_out(a);
//
//    return 0;
//}


/**
* Sum of Digits of a Five Digit Number
**/

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//
//int main() {
//
//    int n;
//    scanf("%d", &n);
//
//    int sum = 0;
//
//    while (n)
//    {
//        sum += n % 10;
//        n /= 10;
//    }
//
//    printf("%d\n", sum);
//
//    return 0;
//}

/**
* Bitwise Operators
**/

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
////Complete the following function.
//
//
//void calculate_the_maximum(int n, int k) {
//    int temp, max_and = 0, max_or = 0, max_xor = 0;
//    for (int i = 1; i < n; i++)
//    {
//        for (int j = i + 1; j < n + 1; j++)
//        {
//            temp = i & j;
//
//            if (temp < k && temp > max_and)
//                max_and = temp;
//
//            temp = i | j;
//
//            if (temp < k && temp > max_or)
//                max_or = temp;
//
//            temp = i ^ j;
//
//            if (temp < k && temp > max_xor)
//                max_xor = temp;
//        }
//    }
//
//    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
//}
//
//int main() {
//    int n, k;
//
//    scanf("%d %d", &n, &k);
//    calculate_the_maximum(n, k);
//
//    return 0;
//}

/**
* Printing Pattern Using Loops
**/

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//
//int main()
//{
//
//    int n;
//    scanf("%d", &n);
//
//    int edge = 2 * n - 1;
//
//    for (int i = 1; i <= edge; i++)
//    {
//        int x = abs(n - i) + 1;
//        for (int j = 1; j <= edge; j++)
//        {
//            int y = abs(n - j) + 1;
//
//            if (y > x)
//                printf("%d ", y);
//            else
//                printf("%d ", x);
//        }
//        printf("\n");
//    }
//    return 0;
//}


/**
* 1D Arrays in C
**/

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//
//int main() {
//
//    int n, sum = 0;
//    scanf("%d", &n);
//
//    // Cheat :)
//    int temp;
//
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &temp);
//        sum += temp;
//    }
//    printf("%d", sum);
//    return 0;
//
//    // Must be :)
//    int* arr = (int*)malloc(sizeof(int) * n);
//
//    for (int i = 0; i < n; i++)
//        scanf("%d", &arr[i]);
//
//    for (int i = 0; i < n; i++)
//        sum += arr[i];
//
//    printf("%d", sum);
//    return 0;
//}

/**
* Array Reversal
**/

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int num, * arr, i, temp;
//    scanf("%d", &num);
//    arr = (int*)malloc(num * sizeof(int));
//    for (i = 0; i < num; i++) {
//        scanf("%d", arr + i);
//    }
//
//    int half_num = num / 2;
//
//    for (int i = 0; i < half_num; i++)
//    {
//        temp = arr[i];
//        arr[i] = arr[num - i - 1];
//        arr[num - i - 1] = temp;
//    }
//
//    for (i = 0; i < num; i++)
//        printf("%d ", *(arr + i));
//    return 0;
//}

/**
* Printing Tokens
**/

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//
//int main() {
//
//    char* s;
//    s = malloc(1024 * sizeof(char));
//    scanf("%[^\n]", s);
//    s = realloc(s, strlen(s) + 1);
//
//    // 1
//    for (char* c = s; *c != '\0'; c++)
//        if (*c == ' ') *c = '\n';
//    printf("%s", s);
//
//    return 0;
//
//    // 2
//    for (int i = 0; i < strlen(s); i++)
//    {
//        if (s[i] == ' ') printf("\n");
//        else printf("%c", s[i]);
//    }
//    return 0;
//}

/**
* Digit Frequency
**/

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//
//int main() {
//    char s[1001];
//    int arrFreq[10] = { 0 };
//    scanf("%s", s);
//
//    for (char* c = s; *c != '\0'; c++)
//        if (isdigit(*c)) arrFreq[*c - '0']++;
//
//    for (int i = 0; i < 10; i++)
//        printf("%d ", arrFreq[i]);
//    return 0;
//}

/**
* Dynamic Array in C
**/

//#include <stdio.h>
//#include <stdlib.h>
//
///*
// * This stores the total number of books in each shelf.
// */
//int* total_number_of_books;
//
///*
// * This stores the total number of pages in each book of each shelf.
// * The rows represent the shelves and the columns represent the books.
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//
// /*
//  * This stores the total number of books in each shelf.
//  */
//int* total_number_of_books;
//
///*
// * This stores the total number of pages in each book of each shelf.
// * The rows represent the shelves and the columns represent the books.
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//
// /*
//  * This stores the total number of books in each shelf.
//  */
//int* total_number_of_books;
//
///*
// * This stores the total number of pages in each book of each shelf.
// * The rows represent the shelves and the columns represent the books.
// */
//int** total_number_of_pages;
//
//int main()
//{
//    int total_number_of_shelves;
//    scanf("%d", &total_number_of_shelves);
//
//    int total_number_of_queries;
//    scanf("%d", &total_number_of_queries);
//
//    while (total_number_of_queries--) {
//        int type_of_query;
//        scanf("%d", &type_of_query);
//
//        if (type_of_query == 1) {
//            /*
//             * Process the query of first type here.
//             */
//            int x, y;
//            scanf("%d %d", &x, &y);
//            if (total_number_of_books == NULL)
//                total_number_of_books = calloc(total_number_of_shelves, sizeof(int));
//
//            if (total_number_of_pages == NULL)
//                total_number_of_pages = calloc(total_number_of_shelves, sizeof(int*));
//
//            total_number_of_books[x]++;
//
//            if (total_number_of_pages[x])
//            {
//                int* temp = malloc(sizeof(int) * total_number_of_books[x]);
//                for (int i = 0; i < total_number_of_books[x] - 1; i++)
//                    temp[i] = total_number_of_pages[x][i];
//                free(total_number_of_pages[x]);
//                total_number_of_pages[x] = temp;
//                total_number_of_pages[x][total_number_of_books[x] - 1] = y;
//            }
//            else {
//                total_number_of_pages[x] = calloc(1, sizeof(int));
//                total_number_of_pages[x][0] = y;
//            }
//
//        }
//        else if (type_of_query == 2) {
//            int x, y;
//            scanf("%d %d", &x, &y);
//            printf("%d\n", *(*(total_number_of_pages + x) + y));
//        }
//        else {
//            int x;
//            scanf("%d", &x);
//            printf("%d\n", *(total_number_of_books + x));
//        }
//    }
//
//    if (total_number_of_books) {
//        free(total_number_of_books);
//    }
//
//    for (int i = 0; i < total_number_of_shelves; i++) {
//        if (*(total_number_of_pages + i)) {
//            free(*(total_number_of_pages + i));
//        }
//    }
//
//    if (total_number_of_pages) {
//        free(total_number_of_pages);
//    }
//
//    return 0;
//}

/**
* Calculate the Nth term
**/

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
////Complete the following function.
//
//int find_nth_term(int n, int a, int b, int c) {
//    if (n == 1) return a;
//    else if (n == 2) return b;
//    else if (n == 3) return c;
//
//    return find_nth_term(n - 1, a, b, c) + find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c);
//}
//
//int main() {
//    int n, a, b, c;
//
//    scanf("%d %d %d %d", &n, &a, &b, &c);
//    int ans = find_nth_term(n, a, b, c);
//
//    printf("%d", ans);
//    return 0;
//}


/**
* Students Marks Sum
**/

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//
////Complete the following function.
//
//int marks_summation(int* marks, int number_of_students, char gender) {
//    int sum = 0;
//
//    for (int i = gender == 'b' ? 0 : 1; i < number_of_students; i += 2)
//        sum += marks[i];
//
//    return sum;
//}
//
//int main() {
//    int number_of_students;
//    char gender;
//    int sum;
//
//    scanf("%d", &number_of_students);
//    int* marks = (int*)malloc(number_of_students * sizeof(int));
//
//    for (int student = 0; student < number_of_students; student++) {
//        scanf("%d", (marks + student));
//    }
//
//    scanf(" %c", &gender);
//    sum = marks_summation(marks, number_of_students, gender);
//    printf("%d", sum);
//    free(marks);
//
//    return 0;
//}

/**
* Sorting Array of Strings
**/

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int lexicographic_sort(const char* a, const char* b) {
//    return strcmp(a, b) > 0;
//}
//
//int lexicographic_sort_reverse(const char* a, const char* b) {
//    return strcmp(b, a) > 0;
//}
//
//int sort_by_number_of_distinct_characters(const char* a, const char* b) {
//    int number_of_distinct_characters_1 = 0, number_of_distinct_characters_2 = 0;
//
//    char* c = calloc(sizeof(char), strlen(a) + 1);
//    for (char* c1 = a; *c1 != '\0'; c1++)
//    {
//        char *c2 = c;
//        for (; *c2 != '\0'; c2++)
//        {
//            if (c1 != c2 && *c1 == *c2)
//                break;
//        }
//        if (*c2 == '\0')
//        {
//            c[number_of_distinct_characters_1++] = *c1;
//        }
//    }
//
//    free(c);
//    c = calloc(sizeof(char), strlen(b) + 1);
//
//    for (char* c1 = b; *c1 != '\0'; c1++)
//    {
//        char* c2 = c;
//        for (; *c2 != '\0'; c2++)
//        {
//            if (c1 != c2 && *c1 == *c2)
//                break;
//        }
//        if (*c2 == '\0')
//        {
//            c[number_of_distinct_characters_2++] = *c1;
//        }
//    }
//
//    free(c);
//
//    if (number_of_distinct_characters_1 == number_of_distinct_characters_2)
//        return lexicographic_sort(a, b);
//    return number_of_distinct_characters_1 > number_of_distinct_characters_2;
//}
//
//int sort_by_length(const char* a, const char* b) {
//    if (strlen(a) == strlen(b))
//        return lexicographic_sort(a, b);
//    return strlen(a) > strlen(b);
//}
//
//void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
//    for (int i = 0; i < len - 1; i++)
//    {
//        for (int j = 0; j < len - i - 1; j++)
//        {
//            if (cmp_func(arr[j], arr[j + 1]))
//            {
//                char* temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//
//    char** arr;
//    arr = (char**)malloc(n * sizeof(char*));
//
//    for (int i = 0; i < n; i++) {
//        *(arr + i) = malloc(1024 * sizeof(char));
//        scanf("%s", *(arr + i));
//        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
//    }
//
//    string_sort(arr, n, lexicographic_sort);
//    for (int i = 0; i < n; i++)
//        printf("%s\n", arr[i]);
//    printf("\n");
//
//    string_sort(arr, n, lexicographic_sort_reverse);
//    for (int i = 0; i < n; i++)
//        printf("%s\n", arr[i]);
//    printf("\n");
//
//    string_sort(arr, n, sort_by_length);
//    for (int i = 0; i < n; i++)
//        printf("%s\n", arr[i]);
//    printf("\n");
//
//    string_sort(arr, n, sort_by_number_of_distinct_characters);
//    for (int i = 0; i < n; i++)
//        printf("%s\n", arr[i]);
//    printf("\n");
//}

/**
* Permutations of Strings
**/

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int next_permutation(int n, char** s)
//{
//    int i = n - 1;
//
//    for (; i > 0; i--)
//    {
//        char** priorty = &s[i];
//        if (strcmp(s[i], s[i - 1]) > 0)
//        {
//            for (int j = i; j < n; j++)
//            {
//                if (strcmp(*priorty, s[j]) > 0 && strcmp(s[j], s[i - 1]) > 0)
//                {
//                    priorty = &s[j];
//                }
//            }
//            char* temp = *priorty;
//            *priorty = s[i - 1];
//            s[i - 1] = temp;
//            break;
//        }
//    }
//    if (i == 0)
//        return 0;
//
//    for (int j = 0; j < n - i; j++)
//    {
//        for (int k = i; k < n - j - 1; k++)
//        {
//            if (strcmp(s[k], s[k + 1]) > 0)
//            {
//                char* temp = s[k];
//                s[k] = s[k + 1];
//                s[k + 1] = temp;
//            }
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    char** s;
//    int n;
//    scanf("%d", &n);
//    s = calloc(n, sizeof(char*));
//    for (int i = 0; i < n; i++)
//    {
//        s[i] = calloc(11, sizeof(char));
//        scanf("%s", s[i]);
//    }
//    do
//    {
//        for (int i = 0; i < n; i++)
//            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
//    } while (next_permutation(n, s));
//    for (int i = 0; i < n; i++)
//        free(s[i]);
//    free(s);
//    return 0;
//}


/**
* Variadic functions in C
**/

//#include <stdarg.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define MIN_ELEMENT 1
//#define MAX_ELEMENT 1000000
//int  sum(int count, ...) {
//    int result = 0;
//
//    va_list ptr;
//    va_start(ptr, count);
//
//    for (int i = 0; i < count; i++)
//        result += va_arg(ptr, int);
//
//    va_end(ptr);
//
//    return result;
//}
//
//int min(int count, ...) {
//    int result, temp;
//
//    if (!count)
//        return 0;
//    va_list ptr;
//    va_start(ptr, count);
//
//    result = va_arg(ptr, int);
//
//    for (int i = 0; i < count - 1; i++)
//    {
//        temp = va_arg(ptr, int);
//        if (temp < result)
//            result = temp;
//    }
//    va_end(ptr);
//
//    return result;
//}
//
//int max(int count, ...) {
//    int result, temp;
//
//    if (!count)
//        return 0;
//    va_list ptr;
//    va_start(ptr, count);
//
//    result = va_arg(ptr, int);
//
//    for (int i = 0; i < count - 1; i++)
//    {
//        temp = va_arg(ptr, int);
//        if (temp > result)
//            result = temp;
//    }
//    va_end(ptr);
//
//    return result;
//}
//
//int test_implementations_by_sending_three_elements() {
//    srand(time(NULL));
//
//    int elements[3];
//
//    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//
//    fprintf(stderr, "Sending following three elements:\n");
//    for (int i = 0; i < 3; i++) {
//        fprintf(stderr, "%d\n", elements[i]);
//    }
//
//    int elements_sum = sum(3, elements[0], elements[1], elements[2]);
//    int minimum_element = min(3, elements[0], elements[1], elements[2]);
//    int maximum_element = max(3, elements[0], elements[1], elements[2]);
//
//    fprintf(stderr, "Your output is:\n");
//    fprintf(stderr, "Elements sum is %d\n", elements_sum);
//    fprintf(stderr, "Minimum element is %d\n", minimum_element);
//    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
//
//    int expected_elements_sum = 0;
//    for (int i = 0; i < 3; i++) {
//        if (elements[i] < minimum_element) {
//            return 0;
//        }
//
//        if (elements[i] > maximum_element) {
//            return 0;
//        }
//
//        expected_elements_sum += elements[i];
//    }
//
//    return elements_sum == expected_elements_sum;
//}
//
//int test_implementations_by_sending_five_elements() {
//    srand(time(NULL));
//
//    int elements[5];
//
//    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//
//    fprintf(stderr, "Sending following five elements:\n");
//    for (int i = 0; i < 5; i++) {
//        fprintf(stderr, "%d\n", elements[i]);
//    }
//
//    int elements_sum = sum(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
//    int minimum_element = min(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
//    int maximum_element = max(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
//
//    fprintf(stderr, "Your output is:\n");
//    fprintf(stderr, "Elements sum is %d\n", elements_sum);
//    fprintf(stderr, "Minimum element is %d\n", minimum_element);
//    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
//
//    int expected_elements_sum = 0;
//    for (int i = 0; i < 5; i++) {
//        if (elements[i] < minimum_element) {
//            return 0;
//        }
//
//        if (elements[i] > maximum_element) {
//            return 0;
//        }
//
//        expected_elements_sum += elements[i];
//    }
//
//    return elements_sum == expected_elements_sum;
//}
//
//int test_implementations_by_sending_ten_elements() {
//    srand(time(NULL));
//
//    int elements[10];
//
//    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[5] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[6] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[7] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[8] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//    elements[9] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
//
//    fprintf(stderr, "Sending following ten elements:\n");
//    for (int i = 0; i < 10; i++) {
//        fprintf(stderr, "%d\n", elements[i]);
//    }
//
//    int elements_sum = sum(10, elements[0], elements[1], elements[2], elements[3], elements[4],
//        elements[5], elements[6], elements[7], elements[8], elements[9]);
//    int minimum_element = min(10, elements[0], elements[1], elements[2], elements[3], elements[4],
//        elements[5], elements[6], elements[7], elements[8], elements[9]);
//    int maximum_element = max(10, elements[0], elements[1], elements[2], elements[3], elements[4],
//        elements[5], elements[6], elements[7], elements[8], elements[9]);
//
//    fprintf(stderr, "Your output is:\n");
//    fprintf(stderr, "Elements sum is %d\n", elements_sum);
//    fprintf(stderr, "Minimum element is %d\n", minimum_element);
//    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
//
//    int expected_elements_sum = 0;
//    for (int i = 0; i < 10; i++) {
//        if (elements[i] < minimum_element) {
//            return 0;
//        }
//
//        if (elements[i] > maximum_element) {
//            return 0;
//        }
//
//        expected_elements_sum += elements[i];
//    }
//
//    return elements_sum == expected_elements_sum;
//}
//
//int main()
//{
//    int number_of_test_cases;
//    scanf("%d", &number_of_test_cases);
//
//    while (number_of_test_cases--) {
//        if (test_implementations_by_sending_three_elements()) {
//            printf("Correct Answer\n");
//        }
//        else {
//            printf("Wrong Answer\n");
//        }
//
//        if (test_implementations_by_sending_five_elements()) {
//            printf("Correct Answer\n");
//        }
//        else {
//            printf("Wrong Answer\n");
//        }
//
//        if (test_implementations_by_sending_ten_elements()) {
//            printf("Correct Answer\n");
//        }
//        else {
//            printf("Wrong Answer\n");
//        }
//    }
//
//    return 0;
//}


/**
* Boxes through a Tunnel
**/

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_HEIGHT 41
//
//struct box
//{
//	int length, width, height;
//};
//
//typedef struct box box;
//
//int get_volume(box b) {
//	return b.length * b.width * b.height;
//}
//
//int is_lower_than_max_height(box b) {
//	return b.height < MAX_HEIGHT;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	box* boxes = malloc(n * sizeof(box));
//	for (int i = 0; i < n; i++) {
//		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
//	}
//	for (int i = 0; i < n; i++) {
//		if (is_lower_than_max_height(boxes[i])) {
//			printf("%d\n", get_volume(boxes[i]));
//		}
//	}
//	return 0;
//}

/**
* Small Triangles, Large Triangles
**/

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//struct triangle
//{
//    int a;
//    int b;
//    int c;
//};
//
//typedef struct triangle triangle;
//
//double calculate_triangle_area(triangle* tr)
//{
//    double p = (tr->a + tr->b + tr->c) / 2.0;
//
//    return sqrt(p * (p - tr->a) * (p - tr->b) * (p - tr->c));
//}
//void sort_by_area(triangle* tr, int n) {
//    for (int i = 0; i < n - 1; i++)
//    {
//        for (int j = 0; j < n - i - 1; j++)
//        {
//            if (calculate_triangle_area(tr + j) > calculate_triangle_area(tr + j + 1))
//            {
//                triangle temp = tr[j];
//                tr[j] = tr[j + 1];
//                tr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    triangle* tr = malloc(n * sizeof(triangle));
//    for (int i = 0; i < n; i++) {
//        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
//    }
//    sort_by_area(tr, n);
//    for (int i = 0; i < n; i++) {
//        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
//    }
//    return 0;
//}

