#include <stdio.h> 
void insertElement(int arr[], int *n, int element, int pos) 
{ 
if (*n >= pos) 
{ 
for (int i = *n; i >= pos; i--) 
{ 
arr[i] = arr[i - 1]; 
} 
arr[pos - 1] = element; 
(*n)++; 
printf("Element inserted\n"); 
} 
else 
{ 
printf("Invalid position for insertion!\n"); 
} 
} 
void deleteElement(int arr[], int *n, int pos) 
{ 
if (pos >= 1 && pos <= *n) 
{ 
for (int i = pos - 1; i < *n - 1; i++) 
{ 
arr[i] = arr[i + 1]; 
} 
(*n)--; 
printf("Element deleted\n"); 
} 
else 
{ 
printf("Invalid position for deletion\n"); 
} 
} 
int linearSearch(int arr[], int n, int element) 
{ 
for (int i = 0; i < n; i++) 
{ 
if (arr[i] == element) 
{ 
return i; 
} 
} 
return -1; 
} 
void traverse(int arr[], int n) 
{ 
printf("Array Elements: "); 
for (int i = 0; i < n; i++) 
{ 
printf("%d ", arr[i]); 
} 
printf("\n"); 
} 
int main() 
{ 
int n; 
printf("Enter size n: "); 
scanf("%d", &n); 
int arr[100]; 
printf("Enter Array elements: "); 
for (int i = 0; i < n; i++) 
{ 
scanf("%d", &arr[i]); 
} 
int option, element, position; 
do { 
printf("**MENU**\n"); 
printf("1. Insert\n"); 
printf("2. Delete\n"); 
printf("3. Linear Search\n"); 
printf("4. Traverse\n"); 
printf("5. Exit\n"); 
printf("Enter option: "); 
scanf("%d", &option); 
switch (option) 
{ 
case 1: 
printf("Element to insert: "); 
scanf("%d", &element); 
printf("Enter Position: "); 
scanf("%d", &position); 
insertElement(arr, &n, element, position); 
break; 
case 2: 
printf("Enter Position to delete: "); 
scanf("%d", &position); 
deleteElement(arr, &n, position); 
break; 
case 3: 
printf("Element to search: "); 
scanf("%d", &element); 
position = linearSearch(arr, n, element); 
if (position != -1) 
{ 
printf("Element found at position %d\n", position + 1); 
} 
else 
{ 
printf("Element not found\n"); 
} 
break; 
case 4: 
traverse(arr, n); 
break; 
case 5: 
printf("Exiting program\n"); 
break; 
default: 
printf("Invalid option\n"); 
break; 
} 
} while (option != 5); 
return 0; 
}
