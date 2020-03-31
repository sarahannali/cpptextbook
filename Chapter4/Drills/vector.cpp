#include "../../std_lib_facilities.h.txt"

int main()
{
    double num;
    string unit;
    cout << "Enter some values with their units (cm, in, ft, m), followed by a '|': ";

    double sum;

    vector<double> nums;
    while (cin >> num >> unit)
    {

        double converted_num;

        if (unit == "m")
        {
            converted_num = num;
        }

        else if (unit == "ft")
        {
            converted_num = num * 12 * 2.54/100;
        }

        else if (unit == "in")
        {
            converted_num = num * 2.54/100;
        }

        else if (unit == "cm")
        {
            converted_num = num/100;
        }

        else
        {
            cout << "The unit " << unit << " is not allowed; " << num << unit << " value rejected.\n";
        }

        sum += converted_num;
        nums.push_back(converted_num);
        sort(nums);

        // For step 6:
        // 
        // if (num == nums[0])
        // {
        //     cout << num << unit << " is the smallest value so far.\n";
        // }

        // if (num == nums[nums.size() - 1])
        // {
        //     cout << num << unit << " is the largest value so far\n";
        // }
    }
    
    // For steps 2-5:
    //
    // if (nums[0] == nums[1])
    // {
    //     cout << "The values are equal.";
    // }
    // else
    // {
    //     cout << "The smaller value is: " << nums[0];
    //     cout << "\nThe smaller value is: " << nums[1];
    //     if (nums[1] - nums[0] <= 1.0/100){
    //         cout << "\nThe numbers are almost equal.";
    //     }
    // }

    cout << "All values entered, converted to m: ";

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "m, ";
    }

    cout << "\n\nThe total size was: " << sum << "m";
    cout << "\nThe smallest size was: " << nums[0] << "m";
    cout << "\nThe largest size was: " << nums[nums.size()-1] << "m";

    return 0;
}