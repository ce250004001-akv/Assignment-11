/*#include <iostream>
using namespace std;
struct Student{
    int age;
    string name, gender, branch;
};
int main(){
    Student *arr=new Student[100];
    cout<<"enter name , age , gender and branch for 2 student "<<endl;
    for(int i=0;i<2;i++){
        cin>>arr[i].name>>arr[i].age>>arr[i].gender>>arr[i].branch;
    }
    Student *temp=new Student[200];
    // cpy old data
    for (int i = 0; i < 100; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr=temp;
    for(int i=0;i<200;i++){
        cout<<arr[i].name<<" "<<arr[i].age<<" "<<arr[i].gender<<" "<<arr[i].branch<<endl;
    }
    delete[] arr;
}
*/
#include <iostream>
#include <string> // Required for using string

using namespace std;

// Student structure definition
struct Student {
    int age;
    string name, gender, branch;
};

int main() {
    // --- Initial Setup ---
    int current_capacity = 100; // Define initial capacity
    int actual_students = 0;    // Tracks the count of students already entered

    Student* arr = new Student[current_capacity];

    // --- First Data Input ---
    int n;
    cout << "Enter how many student data would you like to enter initially (Max " << current_capacity << "):" << endl;
    cin >> n;

    // Check if n exceeds initial capacity (optional)
    if (n > current_capacity) {
        cout << "Warning: Input count exceeds initial capacity. Entering up to " << current_capacity << " students." << endl;
        n = current_capacity;
    }

    cout << "Enter name, age, gender and branch for " << n << " student(s):" << endl;
    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i].name >> arr[i].age >> arr[i].gender >> arr[i].branch)) {
            cerr << "Input failed. Stopping data entry." << endl;
            break;
        }
        actual_students++; // Correctly counts the initial students
    }

    // --- Array Resizing ---
    int m;
    cout << "\nTell the resizing value (New capacity should be >= " << actual_students << "):" << endl;
    cin >> m;
    
    // Safety check: Ensure new capacity is at least as large as the current data size
    int new_capacity = (m > actual_students) ? m : actual_students;
    if (new_capacity != m) {
        cout << "New capacity adjusted to " << new_capacity << " to hold existing data." << endl;
    }

    Student* temp = new Student[new_capacity];

    // Copy old data: Iterate only up to the actual number of students
    for (int i = 0; i < actual_students; i++) {
        temp[i] = arr[i];
    }
    
    // Clean up old memory and update pointer/capacity
    delete[] arr;
    arr = temp;
    current_capacity = new_capacity;

    // --- Adding More Elements ---
    int o;
    // The new elements must start at the index where the old elements ended (actual_students)
    cout << "\nEnter how many more element would you like to add on (Max " << (current_capacity - actual_students) << " more): " << endl;
    cin >> o;
    
    // Check if new additions exceed available space
    if (actual_students + o > current_capacity) {
        cout << "Warning: Cannot add " << o << " elements. Only " << (current_capacity - actual_students) << " slots are available." << endl;
        o = current_capacity - actual_students;
    }

    // CRITICAL FIX: The loop must start from the *current* number of students (`actual_students`)
    // and run for 'o' times.
    for (int i = 0; i < o; i++) {
        int index_to_fill = actual_students + i; // The correct index in the array
        
        cout << "Enter data for new student #" << (i + 1) << ": ";
        if (!(cin >> arr[index_to_fill].name >> arr[index_to_fill].age >> arr[index_to_fill].gender >> arr[index_to_fill].branch)) {
            cerr << "Input failed. Stopping data entry." << endl;
            break;
        }
        actual_students++; // Increment the total count of students for each successful entry
    }

    // --- Data Output ---
    cout << "\n--- Final Student Data (" << actual_students << " records) ---\n";
    
    // Loop only up to the final actual_students count
    if (actual_students == 0) {
        cout << "No student data to display." << endl;
    } else {
        for (int i = 0; i < actual_students; i++) {
            cout << arr[i].name << " " << arr[i].age << " " << arr[i].gender << " " << arr[i].branch << endl;
        }
    }
    cout << "------------------------------------------" << endl;

    // --- Cleanup ---
    delete[] arr;
    return 0;
}
